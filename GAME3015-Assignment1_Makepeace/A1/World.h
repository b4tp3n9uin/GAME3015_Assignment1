#pragma once
#include "SceneNode.h"
#include "Player.h"
#include "Enemy.h"
#include "Background.h"
#include <map>

enum class RenderLayer : int
{
	Opaque = 0,
	Transparent,
	AlphaTested,
	Count
};

// class Player;

class World
{
public:
    /// Constructor.
    /// 
    /// @param no parameters
    World();

    /// Destructor.
    /// 
    /// @param no parameters
    ~World();

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

    /**
    * @brief (AllRenderItems) Vector for all the rendered items in the game world.
    */
	std::vector<std::unique_ptr<RenderItem>> AllRenderItems;

    /**
    * @brief (mGeometries) Mesh Geometry reference.
    */
	map<std::string, std::unique_ptr<MeshGeometry>> mGeometries;
	
    /**
    * @brief (mMaterials) Mesh Material reference.
    */
    map<std::string, std::unique_ptr<Material>> mMaterials;

    /**
    * @brief (mRitemLayer) Rendered Item Reference.
    */
	vector<RenderItem*> mRitemLayer[(int)RenderLayer::Count];

    // scene objects

    /**
    * @brief (player1) Player class instance.
    */
    Player* player1 = new Player();

    /**
    * @brief (enemy) Enemy class instance
    */
    Enemy* enemy;

    /**
    * @brief (bg1) Background class instance.
    */
    Background* bg1 = new Background();



};

