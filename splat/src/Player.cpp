//
//  Player.cpp
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 12/01/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#include "Player.h"
#include "Game.h"
#include "InputHandler.h"
#include "TileLayer.h"
#include "SoundManager.h"
#include "Camera.h"
#include "TextureManager.h"
#include "CollisionManager.h"
#include "Weapon.h"
//#include "Snail.h"
#include "Collision.h"

using namespace std;
/*TODO
//lazyfoos collision detection
draw shuriken onto herorect:DONE
weapon follow player:DONE
collide with snail:DONE
draw enemy
player life bar:
*/
SDL_Rect heroRect;
SDL_Rect enemyRect;
//SDL_Rect* heroRect = new SDL_Rect();
//SDL_Rect* enemyRect = new SDL_Rect();


Player::Player() :  PlatformerObject(),
//m_bInvulnerable(fale),
m_invulnerableTime(200),
m_invulnerableCounter(0),
m_bPressedJump(false)
{
    m_jumpHeight = 80;
    mCollider.w = m_width;
    mCollider.h = m_height;
    heroRect.x = (Uint32)m_position.getX() -  TheCamera::Instance()->getPosition().m_x;//
    heroRect.y = (Uint32)m_position.getY() -  TheCamera::Instance()->getPosition().m_y;
        //enemyRect.x = (Uint32)m_position.getX() -  TheCamera::Instance()->getPosition().m_x;//
    //enemyRect.y = (Uint32)m_position.getY() -  TheCamera::Instance()->getPosition().m_y;
    

}
void Player::attack()
{
  m_bAttack = true;
  


}

void Player::collision()
{
    if(!m_bDying && !m_bInvulnerable)
    {
        //m_currentFrame = 0;
        //m_currentRow = 4;
      //  m_numFrames = 9;
       // m_width = 50;
       // m_bDying = true;
        
//test        
//       TheSoundManager::Instance()->load("Hurt.wav","Hurt",SOUND_SFX);
  //      TheSoundManager::Instance()->playSound("Hurt", 0);

//test
        std::cout << "col with snail";        
        std::cout << m_currentFrame;
    }
}

void Player::load(std::unique_ptr<LoaderParams> const &pParams)
{
    // inherited load function
    PlatformerObject::load(std::move(pParams));
    
    // can set up the players inherited values here
    
    // set up bullets
    m_bulletFiringSpeed = 13;
    m_moveSpeed = 3;
    
    // we want to be able to fire instantly
    m_bulletCounter = m_bulletFiringSpeed;
    
    // time it takes for death explosion
    m_dyingTime = 100;
    
    TheCamera::Instance()->setTarget(&m_position);
}
Weapon wp;
//Snail snail;

void Player::draw()
{
   //test
   //SDL_Rect heroRect;
    
  
    // Render hero
    //heroRect.x = (Uint32)m_position.getX() -  TheCamera::Instance()->getPosition().m_x;//
    //heroRect.y = (Uint32)m_position.getY() -  TheCamera::Instance()->getPosition().m_y;
    //heroRect.w = 20 ; 65ty77777777777777777777
   // heroRect.h = 20 ;
  SDL_Surface *bmpSurf = SDL_LoadBMP("dot.bmp");
	SDL_Texture *bmpTex = SDL_CreateTextureFromSurface(TheGame::Instance()->getRenderer(), bmpSurf);
    
   //SDL_RenderCopy(TheGame::Instance()->getRenderer(), bmpTex, NULL, &heroRect);
    //fillRect(&heroRect, 255, 0, 0 );
    
    
    //wp.draw(heroRect.x ,heroRect.y );
    //snail.draw(enemyRect.x, enemyRect.y);
    //wp.draw();
   //test
    if(m_bFlipped)
    {
        TheTextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX() -  TheCamera::Instance()->getPosition().m_x, (Uint32)m_position.getY() -  TheCamera::Instance()->getPosition().m_y,m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer(), m_angle, m_alpha, SDL_FLIP_HORIZONTAL);
        
    }
    else
    {
        TheTextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX() -  TheCamera::Instance()->getPosition().m_x, (Uint32)m_position.getY() -  TheCamera::Instance()->getPosition().m_y,
                                              m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer(), m_angle, m_alpha);
    }
}
//test
void Player::fillRect(SDL_Rect* rc, int r, int g, int b ) {
    SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), r, g, b, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(TheGame::Instance()->getRenderer(), rc);
}

//test

void Player::handleAnimation()
{
    // if the player is invulnerable we can flash its alpha to let people know
    if(m_bInvulnerable)
    {
        // invulnerability is finished, set values back
        if(m_invulnerableCounter == m_invulnerableTime)
        {
            m_bInvulnerable = false;
            m_invulnerableCounter = 0;
            m_alpha = 255;
        }
        else // otherwise, flash the alpha on and off
        {
            if(m_alpha == 255)
            {
                m_alpha = 0;
            }
            else
            {
                m_alpha = 255;
            }
        }
        
        // increment our counter
        m_invulnerableCounter++;
    }
    
    // if the player is not dead then we can change the angle with the velocity to give the impression of a moving helicopter
    if(!m_bDead && !m_bDying)
    {
        if(m_velocity.m_y < 0)
        {
            m_currentFrame = 2;
            m_currentRow = 2;
            m_numFrames = 2;
        }
        else if(m_velocity.m_y > 0)
        {
            m_currentRow = 3;
            m_numFrames = 1;
        }
        else
        {
            if(m_velocity.getX() < 0)
            {
                m_currentRow = 1;
                m_numFrames = 4;
                m_bFlipped = true;
            }
            else if(m_velocity.getX() > 0)
            {
                m_currentRow = 1;
                m_numFrames = 4;
                m_bFlipped = false;
            }
            else
            {
                m_currentRow = 0;
                m_numFrames = 1;
            }
        }
      //test
     unsigned int lastTime = 0, currentTime;
      currentTime = SDL_GetTicks();

      if(m_bAttack == true)
      {
//       m_bDead = true;
      
        m_currentFrame = 2;
            m_currentRow = 0;
            m_numFrames = 2;
           currentTime = SDL_GetTicks();
  if (currentTime > lastTime + 1000) {
   // printf("Report: %d\n", variable);
    lastTime = currentTime;
    m_bAttack = false;
  }


      }/* else{
         m_currentRow = 0;
                m_numFrames = 1;

      }*/

       //test 
        if(m_bRunning)
        {
            m_currentFrame = int(((SDL_GetTicks() / (100)) % m_numFrames));
        }
        else
        {
            m_currentFrame = int(((SDL_GetTicks() / (120)) % m_numFrames));
        }

    }
    else
    {
        m_currentFrame = m_dyingCounter / m_numFrames;//int(((SDL_GetTicks() / (200)) % m_numFrames));
    }
}

void Player::update()
{
   //heroRect.x = (Uint32)m_position.getX() -  TheCamera::Instance()->getPosition().m_x;//
    //heroRect.y = (Uint32)m_position.getY() -  TheCamera::Instance()->getPosition().m_y;
    //heroRect.w = 20 ;
    //heroRect.h = 20 ;
    
    
    
    

    if(m_bDying)
   {
    TheSoundManager::Instance()->load("Hurt.wav","Hurt",SOUND_SFX);
        TheSoundManager::Instance()->playSound("Hurt", 0);

   }

     if(!m_bDying)
    {
        
        if(m_position.m_y + m_height >= 470)//470
        {
            //snail collision
            collision();
//        Snail snail;
//          snail::Death();
     



        }
        
        handleInput();
        
        if(m_bMoveLeft)
        {
            if(m_bRunning)
            {
                m_velocity.m_x = -5;
            }
            else
            {
                m_velocity.m_x = -2;
            }
        }
        else if(m_bMoveRight)
        {
            if(m_bRunning)
            {
                m_velocity.m_x = 5;
            }
            else
            {
                m_velocity.m_x = 2;
            }
        }
        else
        {
            m_velocity.m_x = 0;
        }
        
        if(m_position.m_y < m_lastSafePos.m_y - m_jumpHeight)
        {
            m_bJumping = false;
        }
        
        if(!m_bJumping)
        {
            m_velocity.m_y = 5;
        }
        else
        {
            m_velocity.m_y = -5;
        }
        
         handleMovement(m_velocity);
    }
    else
    {
        m_velocity.m_x = 0;
        if(m_dyingCounter == m_dyingTime)
        {
            ressurect();
        }
        m_dyingCounter++;
        
        m_velocity.m_y = 5;
    }
    handleAnimation();
}

void Player::handleMovement(Vector2D velocity)
{
    // get the current position
    Vector2D newPos = m_position;
    
    // add velocity to the x position
    newPos.m_x  = m_position.m_x + velocity.m_x;
    
    // check if the new x position would collide with a tile
    if(!checkCollideTile(newPos))
    {
        // no collision, add to the actual x position
        m_position.m_x = newPos.m_x;
    }
    else
    {
        // collision, stop x movement
        m_velocity.m_x = 0;
    }
    
    // get the current position after x movement
    newPos = m_position;
    
    // add velocity to y position
    newPos.m_y += velocity.m_y;
    
    // check if new y position would collide with a tile
    if(!checkCollideTile(newPos))
    {
        // no collision, add to the actual x position
        m_position.m_y = newPos.m_y;
    }
    else
    {
        // collision, stop y movement
        m_velocity.m_y = 0;
        
        //  we collided with the map which means we are safe on the ground,
        //  make this the last safe position
        m_lastSafePos = m_position;
        
        // move the safe pos slightly back or forward so when resurrected we are safely on the ground after a fall
        if(velocity.m_x > 0)
        {
            m_lastSafePos.m_x -= 32;
        }
        else if(velocity.m_x < 0)
        {
            m_lastSafePos.m_x += 32;
            
        }
        
        // allow the player to jump again
        m_bCanJump = true;
        
        // jumping is now false
        m_bJumping = false;
    }
}

void Player::ressurect()
{
    TheGame::Instance()->setPlayerLives(TheGame::Instance()->getPlayerLives() - 1);
    
    m_position = m_lastSafePos;
    m_bDying = false;
    
    m_currentFrame = 0;
    m_currentRow = 0;
    m_width = 40;
    
    m_dyingCounter = 0;
    m_bInvulnerable = true;
}

void Player::clean()
{
    PlatformerObject::clean();
}

void Player::handleInput()
{
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT) && m_position.m_x < ((*m_pCollisionLayers->begin())->getMapWidth() * 32))
    {
        if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
        {
            m_bRunning = true;
        }
        else
        {
            m_bRunning = false;
        }
        
        m_bMoveRight = true;
        m_bMoveLeft = false;
    }
    else if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT) && m_position.m_x > 32)
    {
        if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
        {
            m_bRunning = true;
        }
        else
        {
            m_bRunning = false;
        }
        
        m_bMoveRight = false;
        m_bMoveLeft = true;
    }
    else
    {
        m_bMoveRight = false;
        m_bMoveLeft = false;
    }
   //test 
       if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_F))
    {
       m_bAttack = true;
//       Snail::m_bDead = true;
//       TheSndManager::Instance()->load("hit.wav","hit",SOUND_SFX);
       //draw shuriken
       //heroRect.x += 250;
       //wp.attack(heroRect.x,heroRect.y);
       //TextureManager::Instance()->draw("weapon", heroRect.x,heroRect.y, 30, 25,TheGame::Instance()->getRenderer());
        //TheSoundManager::Instance()->playSound("hit", 0);

    }


//load(std::string fileName, std::string id, sound_type type)

//test
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE) && m_bCanJump && !m_bPressedJump)
    {
        TheSoundManager::Instance()->playSound("jump", 0);
        if(!m_bPressedJump)
        {
            m_bJumping = true;
            m_bCanJump = false;
            m_lastSafePos = m_position;
            m_bPressedJump = true;
        }
    }
    
    if(!TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE) && m_bCanJump)
    {
        m_bPressedJump = false;
    }
}
