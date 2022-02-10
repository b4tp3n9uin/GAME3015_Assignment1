#pragma once
#include "Entity.h"
#include "../../Common/d3dUtil.h"
#include "../../Common/GameTimer.h"



class Player : public Entity
{
public:
    /// Constructor.
    /// 
    /// @param no parameters
    Player();

    /// Destructor.
    /// 
    /// @param no parameters
    ~Player();

    /// Init function.
    /// 
    /// @param no parameters
    /// @returns no return type
    void Init();

    /// Update function
    /// 
    /// @param (gt) passes GameTimer for the update function.
    /// @returns no return type.
    void Update(const GameTimer& gt);

    /// Draw function
    /// 
    /// @param no parameters
    /// @returns no return type.
    void Draw();

private:
    /// Function to move the Player through Keyboard Input.
    /// 
    /// @param (gt) passes in the game timer for update.
    /// @returns no return type.
    void OnKeyboardInput(const GameTimer& gt);

    /**
    * @brief (m_PlayerSpeed) Player movement speed.
    */
    float m_PlayerSpeed;
};

