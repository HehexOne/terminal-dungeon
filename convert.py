from PIL import Image
import sys
import os.path


class NoFileException(Exception):

    def __init__(self):
        super().__init__("\n\tFile, that you provided, doesn't exist.")


class NoFileProvidedException(Exception):

    def __init__(self):
        super().__init__("\n\tEnter filename after script name.\n\tExample: python3 convert.py filename.jpg")


if len(sys.argv) == 1:
    raise NoFileProvidedException()
if not os.path.isfile(sys.argv[1]):
    raise NoFileException()
try:
    img = Image.open(sys.argv[1])
    result_file = open(sys.argv[1].split(".")[0], "w")
    img_pixels = img.load()

    for y in range(0, img.size[1], 2):
        for x in range(img.size[0]):
            if all(i > 128 for i in img_pixels[x, y]):
                result_file.write(" ")
            else:
                result_file.write("X")
        result_file.write("\n")

    img.close()
    result_file.close()
except Exception as e:
    print(e, "Error while processing image.", file=sys.stderr, sep="\n\t")
