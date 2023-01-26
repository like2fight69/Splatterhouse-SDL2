
#ifndef SDLPlatformer_LifeBar_h
#define SDLPlatformer_LifeBar_h

#include "TextureManager.h"
#include "Enemy.h"
#include "GameObjectFactory.h"
#include "Camera.h"
#include "TileLayer.h"
#include <iostream>

//snail Death: m_bDeath = true;
//trybitmask on player
class LifeBar : public PlatformerObject
{
public:
    
    LifeBar() : PlatformerObject()
    {
        //moveLeft = true;
//        m_health = 100;
    }
    virtual std::string type() { return "LifeBar"; }
 
    
    virtual void load(std::unique_ptr<LoaderParams> const &pParams)
    {
        PlatformerObject::load(std::move(pParams));
    }
    //int width
    virtual void draw(int width,int height)
    {
        TextureManager::Instance()->load("lifebar.png", m_textureID, TheGame::Instance()->getRenderer());
        TextureManager::Instance()->draw(m_textureID, 50,50, width, height,TheGame::Instance()->getRenderer());//152,45 = full hearts
        //TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX() -  TheCamera::Instance()->getPosition().m_x, (Uint32)m_position.getY() -  TheCamera::Instance()->getPosition().m_y,m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer(), m_angle, m_alpha);
           //playerHurt();
        
        
        
        
    }
   void playerHurt(){
       m_currentRow = 0;
            m_numFrames = 2;
       m_currentFrame = 2;
    
      
      
      
   }
private:
    
    void handleMovement(Vector2D velocity)
    {
       
    }
    
    void handleAnimation()
    {
        
      }
    
};

//typedef Snail snail;;

class LifeBarCreator : public BaseCreator
{
    GameObject* createGameObject() const
    {
        return new LifeBar();
    }
};


#endif
