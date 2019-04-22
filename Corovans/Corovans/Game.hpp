//
//  Game.hpp
//  Corovans
//
//  Created by Yaroslav on 01/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//
#ifndef Game_hpp
#define Game_hpp


#include <stdio.h>
#include <list>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Object.hpp"
//#include "Storage.hpp"

//using SPRITE_TYPE;


const int CELL_SIZE = 1;


enum L_R_Dir
{
    R,
    L,
    N
};

enum Dir
{
    ST_BACK,
    ST_FORWARD,
    ST_LEFT,
    ST_RIGHT,
    BACK,
    FORWARD,
    LEFT,
    RIGHT,
    NO
};


const int X_SIZE = 6630;
const int Y_SIZE = 3770;


using Coord = std::pair <int, int>;


using CamelPainter = std::function<void(Coord, L_R_Dir)>;
using ObjectPainter = std::function<void(SPRITE_TYPE, Coord, int)>;
using MapPainter = std::function<void(sf::Sprite &, Coord)>;


class Map
{
public:
    Map();
    ~Map();
    
    int x_size, y_size;
    
    sf::Texture background;
    sf::Sprite sand;
    sf::Sprite stone;
    int size_in_cell;
};


class Camel
{
public:
    Camel(Coord c);
    Camel();
    ~Camel();
    sf::Texture texture;
    sf::Sprite sprite;
    std::list <Coord> body;
    L_R_Dir dir;
};

/*
class
public:
    Camel(Coord c);
    Camel();
    ~Camel();
    sf::Texture texture;
    sf::Sprite sprite;
    std::list <Coord> body;
    L_R_Dir dir;
};
*/

class Character
{
public:
    Character();
    ~Character();
    
    Character(const Character & c):
    dir(c.dir), texture(c.texture),
    sprite(c.sprite), step(c.step),
    x_size(c.x_size), y_size(c.y_size),
    z_size(c.z_size), position(c.position),
    speed(c.speed)
    {}
    
    Character & operator = (const Character & c){
        dir = c.dir;
        texture = c.texture;
        sprite = c.sprite;
        step = c.step;
        z_size = c.z_size;
        x_size = c.x_size;
        y_size = c.y_size;
        position = c.position;
        speed = c.speed;
        return * this;
    }
    
    void Move();
    void SetDirection(Dir d);
    char CheckPosition(Coord c);
    
    sf::Texture texture;
    sf::Sprite sprite;
    
    unsigned int x_size;
    unsigned int y_size;
    unsigned int z_size;
    
    //std::list <Coord> body;
    Coord position;
    Dir dir;
    int step;
    int speed;
};


class Game {
public:
    static Game * inst;
    
    Game();
    ~Game();
    
    static Game * Get();
    
    Character * character;
    Map * map;
    std::list <Object *> objects;
    
    void CamelPaint(CamelPainter p);
    void ObjectsPaint(ObjectPainter p);
    void MapPaint(MapPainter p, Coord c);
    
    void Move();
    
    void AddObject(Object * o);
};


Coord ChangePosition(Coord position, int x, int y);


#endif /* Game_hpp */
