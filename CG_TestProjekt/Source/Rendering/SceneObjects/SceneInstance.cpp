#include "SceneInstance.h"

#include "DefaultAssets/Cube.h"

using namespace FancyMath;

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

void SceneInstance::SetLocation(Vector3f inNewLocation)
{
	transform.Elements[12] = inNewLocation.X;
	transform.Elements[13] = inNewLocation.Y;
	transform.Elements[14] = inNewLocation.Z;
}

void SceneInstance::SetRotation(Matrix4 inNewRotation)
{
	Matrix4 currentTransform = Translate(GetLocation());

	transform = currentTransform * inNewRotation;
}

Vector3f SceneInstance::GetLocation() const
{
	Vector4f transCollumn = transform.Collumns[3];

	Vector3f result = Vector3f(transCollumn.X, transCollumn.Y, transCollumn.Z);

	return result;
}

Matrix4 SceneInstance::GetRotation() const
{
	Matrix4 result = IdentityMatrix();



	return result;
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