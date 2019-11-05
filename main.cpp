#include <iostream>
#include <vector>
#include <fstream>


#ifndef __linux

#include <conio.h>

#else

#include <unistd.h>
#include <termios.h>


int getch()

{

    int ch;

    struct termios oldt, newt;

    tcgetattr( STDIN_FILENO, &oldt );

    newt = oldt;

    newt.c_lflag &= ~( ICANON | ECHO );

    tcsetattr( STDIN_FILENO, TCSANOW, &newt );

    ch = getchar();

    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );

    return ch;

}

#endif


#define vvi vector<vector<int>>
#define vi vector<int>

using namespace std;

int screenSize[] = {75, 35};
enum material {
    blank = 0 /* Space */, block = 1 /* White wall */, character = 2 /* Character material */};
char materials[] = {' ', '.', 'O'};

struct Position {
    int x;
    int y;
};

class Map {
private:
    string filename;
    vvi map;
public:

    Map(string filename) : filename(move(filename)) {
        ifstream file(this->filename);
        if (!file.is_open()) {
            cout << "Can't open map file!" << endl;
            exit(1);
        }
        vi tmp;
        while (!file.eof()) {
            char chr;
            file.get(chr);
            if (chr == '\n') {
                map.push_back(tmp);
                tmp.clear();
            } else {
                tmp.push_back(chr == 'X' ? block : blank);
            }
        }
        map.pop_back();
    }

    vvi getZone(int x, int y) {
        vvi zone(screenSize[1]);
        for (int i = 0; i < screenSize[1]; i++) {
            vi lineX(screenSize[0]);
            for (int j = 0; j < screenSize[0]; j++) {
                if (screenSize[0] * x + j >= map[0].size() || screenSize[1] * y + i >= map.size()
                    || screenSize[1] * y + i < 0 || screenSize[0] * x + j < 0) {
                    lineX[j] = block;
                } else {
                    lineX[j] = map[(screenSize[1] * y) + i][(screenSize[0] * x) + j];
                }
            }
            zone[i] = lineX;
        }
        return zone;
    }

    int getBlock(int x, int y) const {
        if (x >= map[0].size() || y >= map.size() || x < 0 || y < 0 ){
            return block;
        } else {
            return map[y][x];
        }
    }
};

class Hero {
private:
    string name;
    Position pos = {0, 0};
    Position zone = {0, 0};
public:
    Hero(string name) : name(move(name)) {}

    Hero(string name, Position pos, Position zone) : name(move(name)), pos(pos), zone(zone) {}

    Position getPosition() const { return this->pos; }

    Position getZone() const { return this->zone; }

    string getName() const { return this->name; }

    void updatePosition(Position const &nPos, Map const& map) {
        int nX = zone.x * screenSize[0] + pos.x + nPos.x;
        int nY = zone.y * screenSize[1] + pos.y + nPos.y;
        if (map.getBlock(nX, nY) != block) {
            pos.x += nPos.x;
            pos.y += nPos.y;
            if (pos.x >= screenSize[0]) {
                zone.x += 1;
                pos.x = nX - zone.x * screenSize[0];
            } else if (pos.x < 0) {
                zone.x -= 1;
                pos.x = nX - zone.x * screenSize[0];
            } else if (pos.y >= screenSize[1]) {
                zone.y += 1;
                pos.y = nY - zone.y * screenSize[1];
            } else if (pos.y < 0) {
                zone.y -= 1;
                pos.y = nY - zone.y * screenSize[1];
            }
        }
    }

    vvi getSprite() const { return {{character}}; }
};

class Renderer {
private:
    vvi screen;
public:

    Renderer() {
        // Empty screen generation
        vi tmp(screenSize[0], blank); // Variable for temp X row
        for (int i; i < screenSize[1]; i++) screen.push_back(tmp); // Create Y row with X rows
    }

    void draw(vvi const &object, Position pos) {
        for (int y = 0; y < object.size(); y++) {
            for (int x = 0; x < object[0].size(); x++) {
                screen[pos.y + y][pos.x + x] = object[y][x];
            }
        }
    }

    void update() {
        for (int y = 0; y < screenSize[1]; y++) {
            for (int x = 0; x < screenSize[0]; x++) {
                cout << materials[screen[y][x]];
            }
            cout << "\n";
        }
    }

};

int main() {
    Map map("/run/media/hehexone/HehexDrive/Projects/terminal-game/map_test");
    Renderer renderer;
    Hero hero("custom_name");
    Position pos{0, 0};
    while (true) {
        renderer.draw(map.getZone(hero.getZone().x, hero.getZone().y), {0, 0});
        renderer.draw(hero.getSprite(), hero.getPosition());
        renderer.update();
        char c = (char) getch();
        if (c == 'w') {
            hero.updatePosition({0, -1}, map);
        } else if (c == 's') {
            hero.updatePosition({0, 1}, map);
        } else if (c == 'a') {
            hero.updatePosition({-1, 0}, map);
        } else if (c == 'd') {
            hero.updatePosition({1, 0}, map);
        } else if (c == 'x') {
            break;
        }
    }
    return 0;
}
