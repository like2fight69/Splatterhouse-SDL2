//
//  Player.h
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 12/01/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#ifndef __SDL_Game_Programming_Book__Weapon__
#define __SDL_Game_Programming_Book__Weapon__

#include <iostream>
#include <vector>
#include "PlatformerObject.h"
#include "GameObjectFactory.h"
#include "TextureManager.h"
#include "Camera.h"
#include "Game.h"

class Weapon : public PlatformerObject
{
public:
    
    //Weapon();
  //SDL_Rect heroRect;
  virtual void draw();//virtual void draw(int x, int y);
  //void handleInput();
  
   Weapon();
    virtual ~Weapon() {}
     //test
     virtual void load(std::unique_ptr<LoaderParams> const &pParams)
    {
        PlatformerObject::load(std::move(pParams));
       
    }
     //virtual std::string type() { return "Weapon"; }
    
    //virtual void load(std::unique_ptr<LoaderParams> const &pParams);
    /* void draw()
    {
    
    
    
    if(m_bFlipped)
        {
            TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX() -  TheCamera::Instance()->getPosition().m_x, (Uint32)m_position.getY() -  TheCamera::Instance()->getPosition().m_y,
                                                  m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer(), m_angle, m_alpha, SDL_FLIP_HORIZONTAL);
              
        }
        else
        {
            TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX() -  TheCamera::Instance()->getPosition().m_x, (Uint32)m_position.getY() -  TheCamera::Instance()->getPosition().m_y,
                                                  m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer(), m_angle, m_alpha);
        }
    }*/
    
    
    
    /*virtual void draw(){

   }
    virtual void update();
    virtual void clean();
    
    virtual void collision();*/
    virtual void update();
    virtual std::string type() { return "Weapon"; }
    
private:
    
    void attack();

    // bring the player back if there are lives left
    void ressurect();
    
    // handle any input from the keyboard, mouse, or joystick
    void handleInput();
    
    // handle any animation for the player
    void handleAnimation();
    
    void handleMovement(Vector2D velocity);
    //virtual void draw();

    SDL_Rect mCollider;

    // player can be invulnerable for a time
    int m_bInvulnerable;
    int m_invulnerableTime;
    int m_invulnerableCounter;
    int m_damage;
    int m_speed;
    
    bool m_bfacingRight;
    bool m_bfacingLeft;
    bool m_bPressedJump;
    bool m_bAttack;
};

// for the factory
class WeaponCreator : public BaseCreator
{
    GameObject* createGameObject() const
    {
        
       return new Weapon();
    }
};


#endif /* defined(__SDL_Game_Programming_Book__Player__) */
