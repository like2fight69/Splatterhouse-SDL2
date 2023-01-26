
#ifndef SDLPlatformer_LifeBar_h
#define SDLPlatformer_LifeBar_h

#include <iostream>
#include <vector>
#include "PlatformerObject.h"
#include "GameObjectFactory.h"
#include "TextureManager.h"
#include "Camera.h"
#include "Game.h"


class LifeBar : public PlatformerObject
{
public:
    
   
   //LifeBar();
   // virtual ~LifeBar() {}
     LifeBar::LifeBar() : PlatformerObject()
    {
   moveLeft = true;
    }
    
    
    void fillRect(SDL_Rect* rc, int r, int g, int b ) {
    SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), r, g, b, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(TheGame::Instance()->getRenderer(), rc);
}

    
     //test
     virtual void load(std::unique_ptr<LoaderParams> const &pParams)
    {
        PlatformerObject::load(std::move(pParams));
       
    }
     
    virtual void update();
    virtual std::string type() { return "LifeBar"; }
    
private:
    
    

    // bring the player back if there are lives left
    void ressurect();
    void fillRect(SDL_Rect* rc, int r, int g, int b )
    // handle any input from the keyboard, mouse, or joystick
    
    
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


#endif /* defined(__SDL_Game_Programming_Book__Player__) */
