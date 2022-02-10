#pragma once
#include "SceneNode.h"



// 2D Entity
class Entity : public SceneNode
{
public:
	/// Constructor.
	/// 
	/// @param no parameters
	Entity();

	/// Destructor.
	/// 
	/// @param no parameters
	~Entity();


	/// Gets Entity velocity.
	/// 
	/// @param no parameters
	/// @returns returns the velocity of the Entity, as a XMFLOAT2 reference.
	XMFLOAT2 getVelocity();

	/// Set Entity velocity.
	/// 
	/// @param (x) Set the entity's x direction.
	/// @param (y) Set the entity's y direction.
	/// @returns no return type
	void setVelocity(float x, float y);

	/// Applies updated velocity to the Entity
	/// 
	/// @param (gt) passes in the game timer to update the Entity.
	/// @returns no return type
	void updateVelocity(const GameTimer& gt);

	/**
	* @brief (EntityRenderItem) Renders item.
	*/
	unique_ptr<RenderItem> EntityRenderItem;


	/**
	* @brief (Velocity) Current Velocity of the Entity passed as XMFLOAT2
	*/
	XMFLOAT2 Velocity;

};


