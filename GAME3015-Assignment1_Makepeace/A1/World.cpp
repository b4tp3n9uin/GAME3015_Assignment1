#include "World.h"

World::World()
{
}

World::~World()
{
}




void World::Init()
{


    player1->setPosition(0.0f,0.1f,-10.0f);
	player1->setScale(0.1f, 1.0f, 0.1f);






	bg1->EntityRenderItem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&bg1->EntityRenderItem->World, XMMatrixScaling(2.5f, 1.0f, 2.5f) * XMMatrixTranslation(0.0f, 0.0f, 0.0f));
	bg1->EntityRenderItem->ObjCBIndex = 0;
	bg1->EntityRenderItem->Mat = mMaterials["BackgroundMat"].get();
	bg1->EntityRenderItem->Geo = mGeometries["shapeGeo"].get();
	//landRitem->World = MathHelper::Identity4x4();
	bg1->EntityRenderItem->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	bg1->EntityRenderItem->IndexCount = bg1->EntityRenderItem->Geo->DrawArgs["Quad"].IndexCount;
	bg1->EntityRenderItem->StartIndexLocation = bg1->EntityRenderItem->Geo->DrawArgs["Quad"].StartIndexLocation;
	bg1->EntityRenderItem->BaseVertexLocation = bg1->EntityRenderItem->Geo->DrawArgs["Quad"].BaseVertexLocation;
	mRitemLayer[(int)RenderLayer::Opaque].push_back(bg1->EntityRenderItem.get());
	AllRenderItems.push_back(std::move(bg1->EntityRenderItem));





	player1->EntityRenderItem = make_unique<RenderItem>();
	XMStoreFloat4x4(&player1->EntityRenderItem->World, XMMatrixScaling(0.1f, 1.0f, 0.1f) * XMMatrixTranslation(0.0f, 0.1f, -10.0f));
	player1->EntityRenderItem->ObjCBIndex = 1;
	player1->EntityRenderItem->Mat = mMaterials["PlaneMat"].get();
	player1->EntityRenderItem->Geo = mGeometries["shapeGeo"].get();
	player1->EntityRenderItem->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	player1->EntityRenderItem->IndexCount = player1->EntityRenderItem->Geo->DrawArgs["Quad"].IndexCount;
	player1->EntityRenderItem->StartIndexLocation = player1->EntityRenderItem->Geo->DrawArgs["Quad"].StartIndexLocation;
	player1->EntityRenderItem->BaseVertexLocation = player1->EntityRenderItem->Geo->DrawArgs["Quad"].BaseVertexLocation;
	mRitemLayer[(int)RenderLayer::Transparent].push_back(player1->EntityRenderItem.get());
	AllRenderItems.push_back(move(player1->EntityRenderItem));

}




void World::Update(const GameTimer& gt)
{
	player1->Update(gt);

	player1->EntityRenderItem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&player1->EntityRenderItem->World, XMMatrixScaling(player1->Scale.x, player1->Scale.y, player1->Scale.z) * XMMatrixTranslation(player1->Position.x, player1->Position.y, player1->Position.z));
	player1->EntityRenderItem->ObjCBIndex = 1;

	AllRenderItems.push_back(std::move(player1->EntityRenderItem));
}


void World::Draw()
{


}