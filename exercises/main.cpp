#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Point {
    float x;
    float y;

    string to_string() const {
        return "[ " + std::to_string(x) + ", " + std::to_string(y) + "]";
    }
};

struct LineSegment {
    Point start;
    Point end;

    string to_string() const {
        return start.to_string() + " -- " + end.to_string();
    }
};

LineSegment readFile(string filePath);

int main() {
    cout << readFile("/home/alex/Computational-Geometry/exercises/s_1000_1.dat").to_string() << endl;
    return 0;
}

LineSegment readFile(string filePath) {
    ifstream file(filePath);
    string l;
    if(file.is_open()){

        for(string line; getline(file, line); ){
            istringstream in(line);
            string start_and_end_points;
            float x1, y1, x2, y2;
            in >> x1 >> y1 >> x2 >> y2;
            struct Point start;
            struct Point end;

            struct LineSegment currentLineSegment;

            start.x = x1;
            start.y = y1;

            end.x = x2;
            end.y = y2;

            currentLineSegment.start = start;
            currentLineSegment.end = end;
            return currentLineSegment;
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }

}
