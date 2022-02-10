#include "SceneNode.h"


SceneNode::SceneNode()
{

    Position = XMFLOAT3(0,0,0);
    Scale = XMFLOAT3(1,1,1);
    Rotation = XMFLOAT3(0,0,0);
}

SceneNode::~SceneNode()
{

}



// void SceneNode::AttachChildNode(sNode_Ptr child)
// {
//     // set new node's parent node
//     // child->ParentNode = this;
//     // ChildrenList.push_back(child);
// }


// unique_ptr<SceneNode> SceneNode::DetachChildNode(SceneNode& node)
// {
//     if(find(ChildrenList.begin(), ChildrenList.end(), node) != ChildrenList.end())
//     {
//         return node;
//     }

//     return node;
// }



// void SceneNode::Init()
// {
//     InitCurrentNode();
//     InitChildrenNode();
// }

// void SceneNode::InitCurrentNode()
// {

// }

// void SceneNode::InitChildrenNode()
// {
//     // for(const sNode_Ptr& c : ChildrenList)
//     // {
//     //     c->Init();
//     // }
// }





// void SceneNode::Update(const GameTimer& gt)
// {
//     UpdateCurrentNode(gt);
//     UpdateChildrenNode(gt);
// }

// void SceneNode::UpdateCurrentNode(const GameTimer& gt)
// {

// }

// void SceneNode::UpdateChildrenNode(const GameTimer& gt)
// {
//     // for (sNode_Ptr& c : ChildrenList)
// 	// {
// 	// 	c->Update(gt);
// 	// }
// }




// void SceneNode::Draw()
// {
//     DrawCurrentNode();
//     DrawChildrenNode();
// }

// void SceneNode::DrawCurrentNode()
// {

// }

// void SceneNode::DrawChildrenNode()
// {
// 	// for (const sNode_Ptr& c : ChildrenList)
// 	// {
// 	// 	c->Draw();
// 	// }
// }





void SceneNode::setPosition(float x, float y, float z)
{
    Position = XMFLOAT3(x,y,z);
}

void SceneNode::setRotation(float x, float y, float z)
{
    Rotation = XMFLOAT3(x,y,z);
}

void SceneNode::setScale(float x, float y, float z)
{
    Scale = XMFLOAT3(x,y,z);
}

XMFLOAT3 SceneNode::getPosition()
{
    return Position;
}

XMFLOAT3 SceneNode::getRotation()
{
    return Rotation;
}

XMFLOAT3 SceneNode::getscale()
{
    return Scale;
}

XMFLOAT4X4 SceneNode::getTransform()
{
    // temp matrix
    XMFLOAT4X4 transform;


    // store current transform in temp matrix
    FXMMATRIX CurrTransformMatrix = 
    XMMatrixScaling(Scale.x, Scale.y, Scale.z) *
    XMMatrixRotationX(Rotation.x) * 
    XMMatrixRotationY(Rotation.y) *
    XMMatrixRotationZ(Rotation.z) *
    XMMatrixTranslation(Position.x, Position.y, Position.z);


    XMStoreFloat4x4(&transform, CurrTransformMatrix);

    return transform;

}


void SceneNode::MoveTo(float x, float y, float z)
{
    Position.x = x;
    Position.y = y;
    Position.z = z;
}