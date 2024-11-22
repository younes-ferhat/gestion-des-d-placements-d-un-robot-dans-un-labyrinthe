#ifndef POINT_H
#define POINT_H

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
};

#endif
