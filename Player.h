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
	int hpMax_; //��������HP
	int hpCrr_; //HP
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Player(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

