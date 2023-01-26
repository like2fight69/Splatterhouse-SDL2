//
//  CollisionManager.cpp
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 28/03/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#include "CollisionManager.h"
#include "Collision.h"
#include "Player.h"
#include "Enemy.h"
#include "TileLayer.h"
#include "stdio.h"
#include "Weapon.h"
#include "InputHandler.h"
#include "SoundManager.h"
#include "LifeBar.h"

//LifeBar pBar;

void CollisionManager::checkPlayerEnemyCollision(Player* pPlayer, const std::vector<GameObject*> &objects)
{
    SDL_Rect* pRect1 = new SDL_Rect();
    pRect1->x = pPlayer->getPosition().getX();
    pRect1->y = pPlayer->getPosition().getY();
    pRect1->w = pPlayer->getWidth();
    pRect1->h = pPlayer->getHeight();
//     Snail *snail;
       Enemy *enemy;

    //test
     for(int i = 0; i < objects.size(); i++)
    {
        if(objects[i]->type() != std::string("Enemy") || !objects[i]->updating())
        {
            
            continue;
        }
        //test
        LifeBar *pLifeBar;
        SDL_Rect* pRect3 = new SDL_Rect();
    pRect3->x = pLifeBar->getPosition().getX();
    pRect3->y = pLifeBar->getPosition().getY();
    pRect3->w = pLifeBar->getWidth();
    pRect3->h = pLifeBar->getHeight();
        
        

        //test
        SDL_Rect* pRect2 = new SDL_Rect();
        pRect2->x = objects[i]->getPosition().getX();
        pRect2->y = objects[i]->getPosition().getY();
        pRect2->w = objects[i]->getWidth();
        pRect2->h = objects[i]->getHeight();
        //test
      
       //test
       std::string en = "Enemy";
        if(RectRect(pRect1, pRect2))
        {
        
        if(objects[i]->type() == std::string("Enemy"))//std::string("Enemy")
        {
             //pPlayer->ressurect();
             //pLifeBar->playerHurt();
             //pBar.draw(152,45);
             //test
             if(pPlayer->width <= 10 ){//110 20
             pPlayer->ressurect();
             }else{
             pPlayer->width--;
            //pPlayer->height--;
             }
            //objects[i]->m_bDead = true;
         // PlatformerObject::doDyingAnimation();
       //   enemy->Death();
          //RectRect(pRect1,pRect2);
         //  delete pRect2;
            
        }


 
        //test
            if(!objects[i]->dead() && !objects[i]->dying())
            {
                pPlayer->collision();
//                delete pRect2;
//               printf("collision");

              //std::cout << "collision";
            }
        }
        
        delete pRect2;
    }
    
    delete pRect1;
}
//test
void CollisionManager::checkWeaponEnemyCollision(Weapon* pWeapon, const std::vector<GameObject*> &objects)
{
    SDL_Rect* pRect1 = new SDL_Rect();
    pRect1->x = pWeapon->getPosition().getX();
    pRect1->y = pWeapon->getPosition().getY();
    pRect1->w = pWeapon->getWidth();
    pRect1->h = pWeapon->getHeight();
//     Snail *snail;
       Enemy *enemy;

    //test
     for(int i = 0; i < objects.size(); i++)
    {
        if(objects[i]->type() != std::string("Enemy") || !objects[i]->updating())
        {
            
            continue;
        }
        

        
        SDL_Rect* pRect2 = new SDL_Rect();
        pRect2->x = objects[i]->getPosition().getX();
        pRect2->y = objects[i]->getPosition().getY();
        pRect2->w = objects[i]->getWidth();
        pRect2->h = objects[i]->getHeight();
        //test
      
       //test
       std::string en = "Enemy";
        if(RectRect(pRect1, pRect2))
        {
        
        if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_F))//isKeyDown
    {
        if(objects[i]->type() == std::string("Enemy"))//std::string("Enemy")
        {
//             pPlayer->collision();
            objects[i]->m_bDead = true;
            //TheSoundManager::Instance()->playSound("hit", 0);
         // PlatformerObject::doDyingAnimation();
       //   enemy->Death();
          //RectRect(pRect1,pRect2);
         //  delete pRect2;
            printf("weapo");
        }
       }//test


        //test
            if(!objects[i]->dead() && !objects[i]->dying())
            {
               // pWeapon->collision();
//                delete pRect2;
//               printf("collision");

              //std::cout << "collision";
            }
        }
        
        delete pRect2;
    }
    
    delete pRect1;
}





//test

