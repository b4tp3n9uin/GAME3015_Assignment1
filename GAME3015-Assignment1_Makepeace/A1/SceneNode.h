#pragma once
#include "../../Common/d3dApp.h"
#include "../../Common/MathHelper.h"
#include "../../Common/UploadBuffer.h"
#include "../../Common/GeometryGenerator.h"
#include "../../Common/Camera.h"
#include "../../Common/FrameResource.h"


using Microsoft::WRL::ComPtr;
using namespace DirectX;
using namespace DirectX::PackedVector;
using namespace std;

#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")





// class A1;



// struct RenderItem
// {
//     RenderItem() = default;

// 	XMFLOAT4X4 World = MathHelper::Identity4x4();
// 	XMFLOAT4X4 TexTransform = MathHelper::Identity4x4();
// 	int NumFramesDirty = gNumFrameResources;
// 	UINT ObjCBIndex = -1;
// 	Material* Mat = nullptr;
// 	MeshGeometry* Geo = nullptr;
// 	D3D12_PRIMITIVE_TOPOLOGY PrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
// 	UINT IndexCount = 0;
// 	UINT StartIndexLocation = 0;
// 	int BaseVertexLocation = 0;
// };

class RenderItem
{
public:
	RenderItem() = default;
	XMFLOAT4X4 World = MathHelper::Identity4x4();
	XMFLOAT4X4 TexTransform = MathHelper::Identity4x4();
	int NumFramesDirty = gNumFrameResources;
	UINT ObjCBIndex = -1;
	Material* Mat = nullptr;
	MeshGeometry* Geo = nullptr;
	D3D12_PRIMITIVE_TOPOLOGY PrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	UINT IndexCount = 0;
	UINT StartIndexLocation = 0;
	int BaseVertexLocation = 0;
};


class SceneNode
{
public:
	/// Constructor.
	/// 
	/// @param no parameters
	SceneNode();
	
	/// Destructor.
	/// 
	/// @param no parameters
    ~SceneNode();

	// typedef std::unique_ptr<SceneNode> sNode_Ptr;
	
	/// Set the node Position.
	/// 
	/// @param (x) Set the Node's x position.
	/// @param (y) Set the Node's y position.
	/// @param (z) Set the Node's z position.
	/// @returns no return type.
	void setPosition(float x, float y, float z);

	/// Set the node Rotation.
	/// 
	/// @param (x) Set the Node's x rotation.
	/// @param (y) Set the Node's y rotation.
	/// @param (z) Set the Node's z rotation.
	/// @returns no return type.
	void setRotation(float x, float y, float z);

	/// Set the node Scale.
	/// 
	/// @param (x) Set the Node's x scale.
	/// @param (y) Set the Node's y scale.
	/// @param (z) Set the Node's z scale.
	/// @returns no return type.
	void setScale(float x, float y, float z);


	/// Set Nodes position.
	/// 
	/// @param no parameters
	/// @returns returns Entity's position as a XMFLOAT3 reference.
	XMFLOAT3 getPosition();

	/// Gets Nodes rotation.
	/// 
	/// @param no parameters
	/// @returns returns Entity's rotation as a XMFLOAT3 reference.
	XMFLOAT3 getRotation();

	/// Gets Nodes scale.
	/// 
	/// @param no parameters
	/// @returns returns Entity's scale as a XMFLOAT3 reference.
	XMFLOAT3 getscale();

	/// Gets Nodes Transformation (Position, Scale, and Rotaion).
	/// 
	/// @param no parameters
	/// @returns returns Entity's transformation as a XMFLOAT3 reference.
	XMFLOAT4X4 getTransform();


	// attach and detach child node from this node
	// void AttachChildNode(sNode_Ptr child);
	// sNode_Ptr DetachChildNode(SceneNode& child);


	// // node initialization
	// void Init();
	// void InitChildrenNode();
	// virtual void InitCurrentNode();


	// // node update
	// void Update(const GameTimer& gt);
	// void UpdateChildrenNode(const GameTimer& gt);
	// virtual void UpdateCurrentNode(const GameTimer& gt);


	// // node draw
	// void Draw();
	// void DrawChildrenNode();
	// virtual void DrawCurrentNode();







	/// Move Function.
	/// 
	/// @param (x) the x direction for the Node to move to.
	/// @param (y) the y direction for the Node to move to.
	/// @param (z) the z direction for the Node to move to.
	/// @returns no return type.
	void MoveTo(float x, float y, float z);

	// game reference
	// A1* GameRef;


	// // scene node parent pointer
	// SceneNode* ParentNode;

	// // scene node children
	// vector<sNode_Ptr> ChildrenList;

	/**
	* @brief (Position) Position of the Entity
	*/
	XMFLOAT3 Position;
	
	/**
	* @brief (Rotation) Rotation of the Entity
	*/
	XMFLOAT3 Rotation;
	
	/**
	* @brief (Scale) Scale of the Entity
	*/
	XMFLOAT3 Scale;



};

