#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/CsvReader.h"

namespace
{
}

bool Stage::IsWall(int _x, int _y)
{
	if (stageData_[_y][_x] == STAGE_OBJ::WALL)
		return true;
	else
		return false;
}

Stage::Stage(GameObject* parent)
	:GameObject(parent, "Stage")
{
	CsvReader csv;
	csv.Load("map.csv");


	stageWidth_ = csv.GetWidth();
	stageHeight_ = csv.GetHeight();

	for (int i = 0; i < stageHeight_; i++)
	{
		vector<int>sdata(stageWidth_, 0);
		stageData_.push_back(sdata);
	}

	for (int j = 0; j < stageHeight_; j++)
	{
		for (int i = 0; i < stageWidth_; i++)
		{
			stageData_[j][i] = csv.GetValue(i, j);
		}
	}
}

void Stage::Initialize()
{
	hFloor_ = Model::Load("Floor.fbx");
	assert(hFloor_ >= 0);
	hBlock_ = Model::Load("Wall.fbx");
	assert(hBlock_ >= 0);
	Camera::SetPosition({ 6.5,15,-3 });
	Camera::SetTarget({ 6.5, 0, 5.5 });
}

void Stage::Update()
{
}

void Stage::Draw()
{
	Transform floorTrans;
	for (int z = 0; z < 15; z++)
	{
		for (int x = 0; x < 15; x++)
		{
			floorTrans.position_ = { (float)x, 0 ,(float)(14 - z) };
#if 0
			if (x == 0 || z == 0 || x == 14 || z == 14)
			{
				Model::SetTransform(hBlock_, floorTrans);
				Model::Draw(hBlock_);
			}
			Model::SetTransform(hFloor_, floorTrans);
			Model::Draw(hFloor_);
#endif
			if (stageData_[z][x] == 1)
			{
				Model::SetTransform(hBlock_, floorTrans);
				Model::Draw(hBlock_);
			}
			else
			{
				Model::SetTransform(hFloor_, floorTrans);
				Model::Draw(hFloor_);
			}
		}
	}

}

void Stage::Release()
{
	//�z��̑|��
	for (int i = 0; i < stageHeight_; i++)
	{
		stageData_[i].clear();
	}
	stageData_.clear();
}
