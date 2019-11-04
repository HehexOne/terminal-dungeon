#include <iostream>
#include <vector>

using namespace std;

int screenSize[] = {75, 35};
enum material {empty=0 /* Space */, block=1 /* White wall */, character=2 /* Google Pixel 4 (RED) */};

struct Position {
    int posX;
    int posY;
    int zoneX;
    int zoneY;
};

class Map {
private:
    string filename;
    vector<vector<int>> map;
public:
    Map (string filename) : filename(move(filename)) {}
    vector<vector<int>> getZone(int x, int y) const {}
    vector<vector<int>> getZoneByPosition (Position const& pos) const {}
    int getCoord(int x, int y) const {return map[y][x];}
};

class Hero {
private:
    string name;
    Position pos = {0, 0, 0, 0};
public:
    Hero (string name) : name(move(name)){}
    Position getPosition() const {return this->pos;}
    string getName() const {return this->name;}
    void setPosition(Position const& nPos, Map const& map) {}
};

class Renderer {
private:
    vector<vector<int>> screen;
public:
    void render(vector<vector<int>> const& screen) const {}
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
