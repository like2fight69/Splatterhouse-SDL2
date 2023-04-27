//
//  Player.h
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 12/01/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#ifndef __SDL_Game_Programming_Book__Player__
#define __SDL_Game_Programming_Book__Player__

#include <iostream>
#include <vector>
#include "PlatformerObject.h"
#include "GameObjectFactory.h"
#include "Weapon.h"
#include "LifeBar.h"

class Player : public PlatformerObject
{
public:
    
    Player();
    virtual ~Player() {}
    //LifeBar pBar;
    SDL_Rect lifeRect;
    virtual void load(std::unique_ptr<LoaderParams> const &pParams);
    
    virtual void draw();
    virtual void fillRect(SDL_Rect* rc, int r, int g, int b);
    virtual void update();
    virtual void clean();
    
    virtual void collision();
    void ressurect();
    int width = 152;
int height = 45;
    virtual std::string type() { return "Player"; }
    
private:
    
    void attack();

    // bring the player back if there are lives left
    //void ressurect();
    
    // handle any input from the keyboard, mouse, or joystick
    void handleInput();
    
    // handle any animation for the player
    void handleAnimation();
    
    void handleMovement(Vector2D velocity);

    SDL_Rect mCollider;

    // player can be invulnerable for a time
    int m_bInvulnerable;
    int m_invulnerableTime;
    int m_invulnerableCounter;
    
    bool m_bPressedJump;
    bool m_bAttack;
    bool m_bAttacking;
    bool m_bPressedAttack;
};

// for the factory
class PlayerCreator : public BaseCreator
{
    GameObject* createGameObject() const
    {
        return new Player();
    }
};


#endif /* defined(__SDL_Game_Programming_Book__Player__) */
