//
//  Enemy.h
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 19/01/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#ifndef __SDL_Game_Programming_Book__Enemy__
#define __SDL_Game_Programming_Book__Enemy__

#include <iostream>
#include "PlatformerObject.h"
#include "SoundManager.h"
//#include "Snail.h"
// Enemy base class
class Enemy : public PlatformerObject
{
public:
        
    virtual std::string type() { return "Enemy"; }
//  static int m_health;  
   void Death(){
      
       // m_bDead = true;
//        m_width = 50;
       // m_bDying = true;

      collided = true;
//        m_health = 0;
  /*      for(int i = 2; i<=0; i--){
          m_health = i;
        }*/
        TheSoundManager::Instance()->playSound("hit", 0);
        //snail dies animation and stop drawing
      
       std::cout << "collided with enemy" << std::endl;
}

  
protected:
    
    int m_health;
    bool collided;  
  
    Enemy() : PlatformerObject() {}
    virtual ~Enemy() {}
};

#endif /* defined(__SDL_Game_Programming_Book__Enemy__) */
