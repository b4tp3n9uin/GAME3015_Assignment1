#pragma once
#include "World.h"





class A1 : public D3DApp
{
public:
	/// Constructor.
	/// 
	/// @param (hInstance) Instance of class
	A1(HINSTANCE hInstance);

	/// Constructor.
	/// 
	/// @param (rhs) constant pointer of A1 class
	A1(const A1& rhs) = delete;

	
	A1& operator=(const A1& rhs) = delete;

	/// Destructor.
	/// 
	/// @param no parameters
	~A1();

	/// Initialize function.
	/// 
	/// @param no parameters
	/// @returns returns a boolean value.
	virtual bool Initialize()override;





	
    // getters for resources map ref
	std::vector<std::unique_ptr<RenderItem>>& getRenderItems() { return mAllRitems; }
	std::unordered_map<std::string, std::unique_ptr<Material>>& getMaterials() { return mMaterials; }
	std::unordered_map<std::string, std::unique_ptr<MeshGeometry>>& getGeometries() { return mGeometries; }
	std::unordered_map<std::string, std::unique_ptr<Texture>>& getTextures() { return mTextures; }


private:
	virtual void OnResize()override;

	/// Update function
	/// 
	/// @param (gt) passes GameTimer for the update function.
	/// @returns no return type.
	virtual void Update(const GameTimer& gt)override;

	/// Draw function
	/// 
	/// @param no parameters
	/// @returns no return type.
	virtual void Draw(const GameTimer& gt)override;



	/// On Mouse Down Function
	/// 
	/// @param (btnState) Mouse Button's current state.
	/// @param (x) Mouse Cursor x position.
	/// @param (y) Mouse Cursor y position.
	/// @returns no return type.
	virtual void OnMouseDown(WPARAM btnState, int x, int y)override;

	/// On Mouse Up Function
	/// 
	/// @param (btnState) Mouse Button's current state.
	/// @param (x) Mouse Cursor x position.
	/// @param (y) Mouse Cursor y position.
	/// @returns no return type.
	virtual void OnMouseUp(WPARAM btnState, int x, int y)override;

	/// On Mouse Move Function
	/// 
	/// @param (btnState) Mouse Button's current state.
	/// @param (x) Mouse Cursor x position.
	/// @param (y) Mouse Cursor y position.
	/// @returns no return type.
	virtual void OnMouseMove(WPARAM btnState, int x, int y)override;



	/// On Keyboard Input
	/// 
	/// @param (gt) passes GameTimer for the update function.
	/// @returns no return type.
	void OnKeyboardInput(const GameTimer& gt);

	/// Update Camera Function
	/// 
	/// @param (gt) passes GameTimer for the update function.
	/// @returns no return type.
	void UpdateCamera(const GameTimer& gt);


	void UpdateObjectCBs(const GameTimer& gt);
	void UpdateMaterialCBs(const GameTimer& gt);
	void UpdateMainPassCB(const GameTimer& gt);


	/// Load Texture
	/// 
	/// @param no params.
	/// @returns no return type.
	void LoadTextures();

	/// Build Root Signature
	/// 
	/// @param no params.
	/// @returns no return type.
	void BuildRootSignature();

	/// Build Descriptor Heaps
	/// 
	/// @param no params.
	/// @returns no return type.
	void BuildDescriptorHeaps();

	/// Build Shaders and Input Layout.
	/// 
	/// @param no params.
	/// @returns no return type.
	void BuildShadersAndInputLayout();

	void helpBuildSubMesh(GeometryGenerator::MeshData name,
		SubmeshGeometry& subName,
		UINT nameVertexOffset,
		UINT nameIndexOffset);

	void BuildShapeGeometry();
	void BuildShapeRenderItems();
	void BuildPSOs();
	void BuildFrameResources();
	void BuildMaterials();
	void DrawRenderItems(ID3D12GraphicsCommandList* cmdList, const std::vector<RenderItem*>& ritems);

	std::array<const CD3DX12_STATIC_SAMPLER_DESC, 6> GetStaticSamplers();





	// Entity
	/**
	* @brief (Plane) Plane Render Item.
	*/
	std::unique_ptr<RenderItem> Plane;

	/**
	* @brief (Background) Background Render Item.
	*/
	std::unique_ptr<RenderItem> Background;





private:
	/**
	* @brief (mFrameResources) Frame Resource Array
	*/
	std::vector<std::unique_ptr<FrameResource>> mFrameResources;
	FrameResource* mCurrFrameResource = nullptr;

	/**
	* @brief (mCurrFrameResourceIndex) Frame Resource Array Index
	*/
	int mCurrFrameResourceIndex = 0;

	UINT mCbvSrvDescriptorSize = 0;

	ComPtr<ID3D12RootSignature> mRootSignature = nullptr;

	ComPtr<ID3D12DescriptorHeap> mSrvDescriptorHeap = nullptr;

	// map for geometry
	std::unordered_map<std::string, std::unique_ptr<MeshGeometry>> mGeometries;

	// // map for material
	std::unordered_map<std::string, std::unique_ptr<Material>> mMaterials;

	// map for texture
	std::unordered_map<std::string, std::unique_ptr<Texture>> mTextures;

	// map for shaders
	std::unordered_map<std::string, ComPtr<ID3DBlob>> mShaders;

	// map for pipeline stage
	std::unordered_map<std::string, ComPtr<ID3D12PipelineState>> mPSOs;

	std::vector<D3D12_INPUT_ELEMENT_DESC> mInputLayout;

	// List of all the render items.
	std::vector<std::unique_ptr<RenderItem>> mAllRitems;

	// Render items divided by PSO.
	std::vector<RenderItem*> mRitemLayer[(int)RenderLayer::Count];

	PassConstants mMainPassCB;

	/**
	* @brief (mEyePos) Point that the camera is looking at.
	*/
	XMFLOAT3 mEyePos = { 0.0f, 0.0f, 0.0f };

	/**
	* @brief (mView) The view of the camera.
	*/
	XMFLOAT4X4 mView = MathHelper::Identity4x4();

	/**
	* @brief (mPorj) Projection of the camera.
	*/
	XMFLOAT4X4 mProj = MathHelper::Identity4x4();

	float mTheta = 1.5f * XM_PI; 
	float mPhi = XM_PIDIV2 - 0.1f;
	float mRadius = 50.0f;

	/**
	* @brief (mLastMousePos) Lattest position of the mouse.
	*/
	POINT mLastMousePos;

	/**
	* @brief (mWorld) the World class instance.
	*/
    World* mWorld= new World();
};