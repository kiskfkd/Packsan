#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

class Text;
class GameOverScene
	:public GameObject
{
	Text* pText;
	int hOver_;
public:
	//�R���X�g���N�^
//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	GameOverScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};


