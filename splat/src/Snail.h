//
//  Snail.h
//  SDLPlatformer
//
//  Created by shaun mitchell on 13/04/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#ifndef SDLPlatformer_Snail_h
#define SDLPlatformer_Snail_h

#include "Enemy.h"
#include "GameObjectFactory.h"
#include "Camera.h"
#include "TileLayer.h"
#include <iostream>

//snail Death: m_bDeath = true;
//trybitmask on player
class Snail : public Enemy
{
public:
    
    Snail() : Enemy()
    {
        moveLeft = true;
//        m_health = 100;
    }
    
    //test
   virtual void collision()
{
    if(!m_bDying)
    {
//        m_currentFrame = 0;
  //      m_currentRow = 4;
    //    m_numFrames = 9;
       // m_width = 50;
        m_bDying = true;
//        moveRight = true;
         
    }
}

virtual void Death(){
//m_bDead = true;
  std::cout << "hi";
}


   //test
    virtual void update()
    {
//    m_health = 11;
collided = true;
if(collided == true){
  //m_bDead = true;
  moveRight= true;
}
  
//test m_position.m_y + m_height >= 399
if(m_position.m_y + m_height <= 470)//snail collision 399 470
        {
         // m_bDead = true; 
         // collision();
         //collided == true;
   // m_bDying = true;    
        }


    //test
if(m_bDying)
 {
//  m_bDead = true;
//TheSoundManager::Instance()->load("Hurt.wav","Hurt",SOUND_SFX);
  //      TheSoundManager::Instance()->playSound("Hurt", 0);
std::cout << "coll" << std::endl;;
}
  if(!m_bDying){

   /* if(m_position.m_y + m_height >= 470)//snail collision 399
        {
         // m_bDead = true; 
          collision();
         // collided == true;
   // m_bDying = true;    
        }*/
//m_health = 1;
/*if(collided == true){
 m_bDead = true;

}*/

     //test
        if(moveLeft)
        {
           //test
          if(collided == true){
       //  m_bDead = true;

}
          
           //test
            m_velocity.m_x = -2;
//            m_bDead = true;
        }
        else if(moveRight)
        {
            m_velocity.m_x = 2;
        }
        else
        {
            m_velocity.m_x = 0;
        }
        
        m_velocity.m_y = 5;
        
        handleMovement(m_velocity);
        handleAnimation();
   
   }//m_bDying
  }
    
    virtual void load(std::unique_ptr<LoaderParams> const &pParams)
    {
        PlatformerObject::load(std::move(pParams));
    }
    
    virtual void draw()
    {
      //TextureManager::Instance()->load("snail.png",m_textureID,TheGame::Instance()->getRenderer());
    //TextureManager::Instance()->draw(m_textureID, x,y, 30, 25,TheGame::Instance()->getRenderer());
      
      
      // if(collided == true){ 
       if(m_flipped)
        {
            TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX() -  TheCamera::Instance()->getPosition().m_x, (Uint32)m_position.getY() -  TheCamera::Instance()->getPosition().m_y,
                                                  m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer(), m_angle, m_alpha, SDL_FLIP_HORIZONTAL);
        }
        else
        {
            TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX() -  TheCamera::Instance()->getPosition().m_x, (Uint32)m_position.getY() -  TheCamera::Instance()->getPosition().m_y,
                                                  m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer(), m_angle, m_alpha);
        }

     // }//test
    }
    
private:
    
    void handleMovement(Vector2D velocity)
    {
        Vector2D newPos = m_position;
        newPos.m_x  = m_position.m_x + velocity.m_x;
        
        if(!checkCollideTile(newPos))
        {
            m_position.m_x = newPos.m_x;
        }
        else
        {
  //           m_velocity.m_x = 0;// stop

            if(moveLeft)
            {
//              m_bDead = true; //collides with wall  
              moveLeft = false;
                moveRight = true;
            }
            else if(moveRight)
            {
                moveLeft = true;
                moveRight = false;
            }
        }
        
        newPos = m_position;
        newPos.m_y += velocity.m_y;
        
        if(!checkCollideTile(newPos))
        {
            if(m_velocity.m_y == 0)
            {
                if(moveLeft)
                {
//                    m_bDead = true;
                    moveLeft = false;
                    moveRight = true;
                }
                else if(moveRight)
                {
                 // m_bDead = true;
                    moveLeft = true;
                    moveRight = false;
                }
            }
            
            m_position.m_y = newPos.m_y;
        }
        else
        {
//          m_bDead = true;  
          m_velocity.m_y = 0;
        }
    }
    
    void handleAnimation()
    {
        
        if(m_velocity.getX() < 0)
        {
            m_flipped = true;
        }
        else if(m_velocity.getX() > 0)
        {
            m_flipped = false;
        }
        else
        {
            m_currentRow = 0;
            m_numFrames = 1;
        }
        
        m_currentFrame = int(((SDL_GetTicks() / (100)) % m_numFrames));
    }
    
    bool moveLeft;
    bool moveRight;
    bool m_flipped;
    
    
};

//typedef Snail snail;;

class SnailCreator : public BaseCreator
{
    GameObject* createGameObject() const
    {
        return new Snail();
    }
};


#endif
