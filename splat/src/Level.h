//
//  Map.h
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 09/03/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#ifndef __SDL_Game_Programming_Book__Map__
#define __SDL_Game_Programming_Book__Map__

#include <iostream>
#include <vector>
#include "Layer.h"
#include "LevelParser.h"
#include "Player.h"
#include "Weapon.h"
#include "LifeBar.h"
#include "CollisionManager.h"

class TileLayer;

struct Tileset
{
    int firstGridID;
    int tileWidth;
    int tileHeight;
    int spacing;
    int margin;
    int width;
    int height;
    int numColumns;
    std::string name;
};

class Level
{
public:
    
    ~Level();
    
    void update();
    void render();
    
    std::vector<Tileset>* getTilesets() { return &m_tilesets; }
    std::vector<Layer*>* getLayers() { return &m_layers; }    
    std::vector<TileLayer*>* getCollisionLayers() { return &m_collisionLayers; }
    
    const std::vector<TileLayer*>& getCollidableLayers() { return m_collisionLayers; }
    
    Player* getPlayer() { return m_pPlayer; }
    void setPlayer(Player* pPlayer) { m_pPlayer = pPlayer; }
    
    LifeBar* getLifeBar() { return m_pLifeBar; }
    void setPlayer(LifeBar* pLifeBar) { m_pLifeBar = pLifeBar; }
    
    //test
    Weapon* getWeapon() { return m_pWeapon; }
    void setWeapon(Weapon* pWeapon) { m_pWeapon = pWeapon; }
    
    //test
    
private:
    
    friend class LevelParser;
    
    Level();
    
    Player* m_pPlayer;
    LifeBar* m_pLifeBar;
    Weapon* m_pWeapon;
    
    std::vector<Layer*> m_layers;
    std::vector<Tileset> m_tilesets;
    std::vector<TileLayer*> m_collisionLayers;
};

#endif /* defined(__SDL_Game_Programming_Book__Map__) */
