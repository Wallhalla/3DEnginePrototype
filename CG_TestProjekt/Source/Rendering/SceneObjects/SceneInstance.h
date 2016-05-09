#pragma once

#include "FancyLib/FancyMath.h"
#include "Asset.h"

#include <string>

class SceneInstance
{
private:
	FancyMath::Matrix4 transform;
	ModelAsset* asset;

public:
	SceneInstance(ShaderProgram* program, std::string assetName);
	~SceneInstance();

	void SetLocation(FancyMath::Vector3f inNewLocation);
	void SetRotation(FancyMath::Matrix4 inNewRotation);

	FancyMath::Vector3f GetLocation() const;
	FancyMath::Matrix4 GetRotation() const;


	void Draw();
	
};