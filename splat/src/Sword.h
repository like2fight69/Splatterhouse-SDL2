//
//  Sword.h
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 12/01/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#ifndef __SDL_Game_Programming_Book__Sword__
#define __SDL_Game_Programming_Book__Sword__

#include <iostream>
#include <vector>
#include "PlatformerObject.h"
#include "GameObjectFactory.h"

class Sword : public PlatformerObject
{
public:
    
    Sword();
    virtual ~Sword() {}
    
    virtual void load(std::unique_ptr<LoaderParams> const &pParams);
    
    virtual void draw();
    virtual void update();
    virtual void clean();
    
    virtual void collision();
    
    virtual std::string type() { return "Sword"; }
    
private:
    
    void attack();

    // bring the player back if there are lives left
    void ressurect();
    
    // handle any input from the keyboard, mouse, or joystick
    void handleInput();
    
    // handle any animation for the player
    void handleAnimation();
    
    void handleMovement(Vector2D velocity);

    // player can be invulnerable for a time
    int m_bInvulnerable;
    int m_invulnerableTime;
    int m_invulnerableCounter;
    
    bool m_bPressedJump;
    bool m_bAttack;
};

// for the factory
class SwordCreator : public BaseCreator
{
    GameObject* createGameObject() const
    {
        return new Sword();
    }
};


#endif /* defined(__SDL_Game_Programming_Book__Player__) */

