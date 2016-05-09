#include "SceneInstance.h"

#include "DefaultAssets/Cube.h"

SceneInstance::SceneInstance(ShaderProgram* program, std::string assetName)
{
	transform = FancyMath::Matrix4(1);
	asset = nullptr;
	if (assetName == std::string("Cube"))
	{
		asset = new Cube(program);
	}
}

SceneInstance::~SceneInstance()
{
	if (asset)
	{
		delete asset;
	}
}

void SceneInstance::SetLocation(FancyMath::Vector3f inNewLocation)
{
	transform.Elements[12] = inNewLocation.X;
	transform.Elements[13] = inNewLocation.Y;
	transform.Elements[14] = inNewLocation.Z;
}


void SceneInstance::Draw()
{
	const ShaderProgram* shader = asset->GetShader();
	
	shader->SetUniformMatrix4("model_matrix", transform);
	if (&shader)
	{
		//shader->Enable();

		asset->Draw();

		//shader->Disable();
	}
}