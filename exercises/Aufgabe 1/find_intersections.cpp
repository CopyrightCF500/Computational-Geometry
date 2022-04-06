#include <iostream>
#include <fstream>
#include <sstream>

#include <list>

using namespace std;

// Representation of a Point
struct Point {
    float x;
    float y;

    string to_string() const {
        return "[ " + std::to_string(x) + ", " + std::to_string(y) + "]";
    }
};

// Representation of a LineSegment
struct LineSegment {
    Point start;
    Point end;

    string to_string() const {
        return start.to_string() + " -- " + end.to_string();
    }
};

list<LineSegment> readFile(string filePath);

int main() {

    // List of all Line Segments
    list<LineSegment> allLineSegments = readFile("/home/alex/Computational-Geometry/exercises/data/s_1000_1.dat");


    // print every Line Segment
    int count = 1;
    for (auto lS : allLineSegments){
        cout << count << ". " << lS.to_string() << endl;
        ++count;
    }

    return 0;
}

/**
 * This function receives a file path to read the content of the file and create
 * a list of structs
 *
 * @param filePath - path of the file to read
 * @return list<LineSegment> - the content of the file in Line Segemnt structs
 */
list<LineSegment> readFile(string filePath) {
    list<LineSegment> allLineSegments;

    ifstream file(filePath);
    if(file.is_open()){

        // Iterate through file and safe every Line Segment in specific struct
        for(string line; getline(file, line); ){
            istringstream in(line);
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

            allLineSegments.push_back(currentLineSegment);
        }
        file.close();

        return allLineSegments;
    } else {
        cout << "Unable to open file" << endl;
    }

}
