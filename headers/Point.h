#ifndef POINT_H
#define POINT_H

#include <iostream>
class Point {
private:
    int d_x, d_y;

public:
    // Constructeur par défaut et avec paramètres
    Point(int d_x = 0, int d_y = 0);

    // Getters
    int getX() const;
    int getY() const;

    // Setters
    void setX(int newX);
    void setY(int newY);

    // Méthode pour déplacer le Point
    void move(int x, int y);
    bool operator==(const Point& p)   const;
    /**
  Ouput of a point: (x,y)
  @param ost the stream on which the point is written
*/
  void print(std::ostream& ost) const;
/**
  Input of a point: (x,y)
  @param ist the stream from which the point is read
*/
  void read(std::istream& ist);
};
///operator<< for writing a point on a output stream
std::ostream& operator<<(std::ostream& , const Point& );
///operator>> for reading a point from a intput stream
std::istream& operator>>(std::istream& , Point& );
#endif