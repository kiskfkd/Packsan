#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

class Stage;
class SceneManager;
class Player :
	public GameObject
{
	int hPlayer_;
	float speed_;
	Stage* pStage_;
	//SceneManager* pScene_;
	//Text* pText;
	int hpMax_; //さいだいHP
	int hpCrr_; //HP
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Player(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

