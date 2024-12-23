#include "../headers/Point.h"

// Constructeur
Point::Point(int x, int y) : d_x(x), d_y(y) {}

// Getters
int Point::getX() const {
    return d_x;
}

int Point::getY() const {
    return d_y;
}

// Setters
void Point::setX(int newX) {
    d_x = newX;
}

void Point::setY(int newY) {
    d_y = newY;
}

// Méthode pour déplacer le Point
void Point::move(int x, int y) {
    d_x += x;
    d_y += y;
}
bool Point::operator==(const Point& p) const
    {
      return (d_x == p.d_x) && (d_y == p.d_y);
    }


void Point::print(std::ostream& ost) const
{
  ost<<'('<<d_x<<','<<d_y<<')';
}

void Point::read(std::istream& ist)
{
  char c;
  ist>>c;
  if (c == '(')
  {
    double x;
    ist>>x>>c;
    if (c == ',')
    {
      double y;
      ist>>y>>c;
      if (c == ')') { d_x = x; d_y = y; }
    }
  }
}

std::ostream& operator<<(std::ostream& ost, const Point& p)
{
  p.print(ost);
  return ost;
}

std::istream& operator>>(std::istream& ist, Point& p)
{
  p.read(ist);
  return ist;
}