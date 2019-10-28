//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"

//########## �}�N����` ##########
#define GAME_WIDTH	800		//��ʂ̉��̑傫��
#define GAME_HEIGHT	600		//��ʂ̏c�̑傫��
#define GAME_COLOR	32		//��ʂ̃J���[�r�b�g

#define GAME_WINDOW_NAME	"GAME TITLE"		//�E�B���h�E�̃^�C�g��
#define GAME_WINDOW_MODECHANGE	TRUE			//TRUE�F�E�B���h�E���[�h / FALSE�F�t���X�N���[��

#define SET_WINDOW_ST_MODE_DEFAULT			0	//�f�t�H���g
#define SET_WINDOW_ST_MODE_TITLE_NONE		1	//�^�C�g���o�[�Ȃ�
#define SET_WINDOW_ST_MODE_TITLE_FLAME_NONE	2	//�^�C�g���o�[�ƃt���[���Ȃ�
#define SET_WINDOW_ST_MODE_FLAME_NONE		3	//�t���[���Ȃ�

#define GAME_FPS_SPEED					   60


//########## �񋓌^ ##########
enum GAME_SCENE {
	GAME_SCENE_TITLE,	//�^�C�g�����
	GAME_SCENE_PLAY,	//�v���C���
	GAME_SCENE_END		//�G���h���
};

//�E�B���h�E�֌W
WNDPROC WndProc;						//�E�B���h�E�v���V�[�W���̃A�h���X
BOOL IsWM_CREATE = FALSE;				//WM_CREATE������ɓ��삵�������f����

//FPS�֘A
int StartTimeFps;						//����J�n����
int CountFps;							//�J�E���^
float CalcFps;							//�v�Z����
int SampleNumFps = GAME_FPS_SPEED;		//���ς����T���v����

//�L�[�{�[�h�֘A
char AllKeyState[256];			//���ׂẴL�[�̏�Ԃ�����

//�V�[���֘A
int GameSceneNow = (int)GAME_SCENE_TITLE;	//�ŏ��̃Q�[����ʂ��^�C�g���ɐݒ�

//########## �\���� ##########
struct STRUCT_GAZOU {
	int Handle;				//�摜�̃n���h��
	char FilePath[128];		//�t�@�C���̃p�X
	int X;					//���̈ʒu
	int Y;					//�c�̈ʒu
	int Width;				//���̃T�C�Y
	int Height;				//�c�̃T�C�Y
	int C_Width;			//���̒��S�ʒu
	int C_Height;			//�c�̒��S�ʒu

	int MoveSpeed;			//�ړ����x

	
};



//########## ���O�̍Ē�` ##########
typedef STRUCT_GAZOU GAZOU;

//########## �O���[�o���ϐ� ##########

GAZOU BackImage;

//########## �v���g�^�C�v�錾 ##########
LRESULT CALLBACK MY_WNDPROC(HWND, UINT, WPARAM, LPARAM);	//����E�B���h�E�v���V�[�W��

VOID MY_FPS_UPDATE(VOID);			//FPS�l���v���A�X�V����֐�
//VOID MY_FPS_DRAW(VOID);				//FPS�l��`�悷��֐�
VOID MY_FPS_WAIT(VOID);				//FPS�l���v�����A�҂֐�

VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//�L�[�̓��͏�Ԃ��X�V����֐�

VOID MY_GAME_TITLE(VOID);			//�^�C�g����ʂ̊֐�
VOID MY_GAME_PLAY(VOID);			//�v���C��ʂ̊֐�
VOID MY_GAME_END(VOID);				//�G���h��ʂ̊֐�



//########## �v���O�����ōŏ��Ɏ��s�����֐� ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(GAME_WINDOW_MODECHANGE);					//�E�B���h�E���[�h�ɐݒ�
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//�w��̐��l�ŉ�ʂ�\������

	SetWindowStyleMode(SET_WINDOW_ST_MODE_TITLE_NONE);			//�^�C�g���o�[�Ȃ�

	SetMainWindowText(TEXT(GAME_WINDOW_NAME));					//�^�C�g���̕���

	//�t�b�N��WM_CLOSE�Ȃǂ̃��b�Z�[�W�������|���Ď擾����
	SetHookWinProc(MY_WNDPROC);	//�E�B���h�E�v���V�[�W���̐ݒ�

	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) { return -1; }	
	
	// �`���𗠉�ʂɎw��
	if (SetDrawScreen(DX_SCREEN_BACK) != 0) return 0; // ���s�����狭���I��

	

	//�c�w���C�u��������������

	SetDrawScreen(DX_SCREEN_BACK);								//Draw�n�֐��͗���ʂɕ`��

	//MY_GAZOU_LOAD(&BackImage, 0, 0, GAME_BACKIMAGE);

	//�������[�v
	while (TRUE)
	{
		// �v���C���[�̉摜��ǂݍ���
		int imgChara = LoadGraph("media/player_01.png");

		int playerSpeed = 2; // ��������
		int playerX = 0; // X���W
		int playerY = 256; // Y���W

		
		if (ProcessMessage() != 0) { break; }	//���b�Z�[�W�����̌��ʂ��G���[�̂Ƃ��A�����I��

		if (ClearDrawScreen() != 0) { break; }	//��ʂ������ł��Ȃ������Ƃ��A�����I��

		MY_ALL_KEYDOWN_UPDATE();				//�L�[�̏�Ԃ��擾

		

		//�V�[���I��
		switch (GameSceneNow)
		{
		case (int)GAME_SCENE_TITLE:	//�^�C�g����ʂ̏�����������

			MY_GAME_TITLE();	//�^�C�g����ʂ̏���

			break;	//�^�C�g����ʂ̏��������܂�

		case (int)GAME_SCENE_PLAY:	//�v���C��ʂ̏�����������

			MY_GAME_PLAY();		//�v���C��ʂ̏���

			break;	//�v���C��ʂ̏��������܂�

		case (int)GAME_SCENE_END:	//�G���h��ʂ̏�����������

			MY_GAME_END();		//�G���h��ʂ̏���

			break;	//�G���h��ʂ̏��������܂�

		default:

			break;

		}

		MY_FPS_UPDATE();						//FPS�̏���[�X�V]
		//DrawGraph(BackImage.X, BackImage.Y, BackImage.Handle, TRUE);
		// �w�i�̉摜��`��
		

		//MY_FPS_DRAW();		//FPS�̏���[�`��]

		ScreenFlip();		//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��

		MY_FPS_WAIT();		//FPS�̏���[�҂�]
	}
	DeleteGraph(BackImage.Handle);
	//WaitKey();

	DxLib_End();		//�c�w���C�u�����g�p�̏I������

	return 0;
}

//########## FPS�l���v���A�X�V����֐� ##########
VOID MY_FPS_UPDATE(VOID)
{
	if (CountFps == 0) //1�t���[���ڂȂ玞�����L��
	{
		StartTimeFps = GetNowCount();
	}

	if (CountFps == SampleNumFps) //60�t���[���ڂȂ畽�ς��v�Z
	{
		int now = GetNowCount();
		CalcFps = 1000.f / ((now - StartTimeFps) / (float)SampleNumFps);
		CountFps = 0;
		StartTimeFps = now;
	}
	CountFps++;
	return;
}

////########## FPS�l��`�悷��֐� ##########
//VOID MY_FPS_DRAW(VOID)
//{
//	//�������`��
//	DrawFormatString(0, GAME_HEIGHT - 20, GetColor(255, 255, 255), "FPS:%.1f", CalcFps);
//	return;
//}

//########## FPS�l���v�����A�҂֐� ##########
VOID MY_FPS_WAIT(VOID)
{
	int resultTime = GetNowCount() - StartTimeFps;					//������������
	int waitTime = CountFps * 1000 / GAME_FPS_SPEED - resultTime;	//�҂ׂ�����

	if (waitTime > 0)		//�w���FPS�l���������ꍇ
	{
		Sleep(waitTime);	//�҂�
	}
	return;
}

//########## �L�[�̓��͏�Ԃ��X�V����֐� ##########
VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{
	char TempKey[256];			//�ꎞ�I�ɁA���݂̃L�[�̓��͏�Ԃ��i�[����

	GetHitKeyStateAll(TempKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�

	for (int i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)	//������Ă���L�[�̃L�[�R�[�h�������Ă���Ƃ�
		{
			AllKeyState[i]++;	//������Ă���
		}
		else
		{
			AllKeyState[i] = 0;	//������Ă��Ȃ�
		}
	}
	return;
}

//########## �^�C�g����ʂ̊֐� ##########
VOID MY_GAME_TITLE(VOID)
{
	if (AllKeyState[KEY_INPUT_RETURN] != 0)	//�G���^�[�L�[��������Ă�����
	{
		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
	}

	//MY_GAZOU_LOAD(&BackGround, 0, 0, GAME_BACKGOUND);

	// �w�i�̉摜��ǂݍ���
	int imgBack = LoadGraph("image/utyu.jpg");

	DrawGraph(0, 0, imgBack, false);

	

	DrawString(310, 270, "�f�l�c", GetColor(255, 255, 255), SetFontSize(60));
	DrawString(190, 330, "�G���^�[�L�[�������Ă�������", GetColor(255, 255, 255),SetFontSize(30));

   

	return;
}

//########## �v���C��ʂ̊֐� ##########
VOID MY_GAME_PLAY(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�X�y�[�X�L�[��������Ă�����
	{
		GameSceneNow = (int)GAME_SCENE_END;	//�V�[�����G���h��ʂɂ���
	}

	int imgBack = LoadGraph("image/utyu2.jpg");

	DrawGraph(0, 0, imgBack, false);


	DrawString(0, 0, "�v���C���(�X�y�[�X�L�[�������Ă�������)", GetColor(255, 255, 255));

	return;
}

//########## �G���h��ʂ̊֐� ##########
VOID MY_GAME_END(VOID)
{
	if (AllKeyState[KEY_INPUT_BACK] != 0)	//�o�b�N�X�y�[�X�[�L�[��������Ă�����
	{
		GameSceneNow = (int)GAME_SCENE_TITLE;	//�V�[�����^�C�g����ʂɂ���
	}

	int imgBack = LoadGraph("image/utyu3.jpg");

	DrawGraph(0, 0, imgBack, false);


	DrawString(0, 0, "�G���h���(�o�b�N�X�y�[�X�L�[�������Ă�������)", GetColor(255, 255, 255));

	return;
}

//########## �E�B���h�E�v���V�[�W���֐� ##########
LRESULT CALLBACK MY_WNDPROC(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{

	case WM_CREATE:	//�E�B���h�E�̐�����������


		IsWM_CREATE = TRUE;	//WM_CREATE����I��
		return 0;

	case WM_CLOSE:		//����{�^�����������Ƃ�

		MessageBox(hwnd, TEXT("�Q�[�����I�����܂�"), TEXT("�I�����b�Z�[�W"), MB_OK);
		break;

	case WM_RBUTTONDOWN:	//�}�E�X�̉E�{�^�����������Ƃ�

		SendMessage(hwnd, WM_CLOSE, 0, 0);		//WM_CLOSE���b�Z�[�W���L���[�ɒǉ�
		break;

	case WM_LBUTTONDOWN:	//�}�E�X�̍��{�^�����������Ƃ�

		//WM_NCLBUTTONDOWN(�^�C�g���o�[�Ń}�E�X�̍��{�^����������)���b�Z�[�W�������ɔ��s
		PostMessage(hwnd, WM_NCLBUTTONDOWN, (WPARAM)HTCAPTION, lp);
		break;

	case WM_DESTROY:	//�E�B���h�E���j�����ꂽ(�Ȃ��Ȃ���)�Ƃ�

		PostQuitMessage(0);		//���b�Z�[�W�L���[�� WM_QUIT �𑗂�
		return 0;
	}

	//�f�t�H���g�̃E�B���h�E�v���V�[�W���֐����Ăяo��
	return DefWindowProc(hwnd, msg, wp, lp);
}

//########## �摜��ǂݍ��ސݒ������֐� ##########
//���@���Fconst char *�F�ǂݍ��މ摜�̃t�@�C���p�X
//���@���Fint�@�F�摜�̉��̈ʒu
//���@���Fint�@�F�摜�̏c�̈ʒu
//���@���F�摜�\���́@�F�ݒ肷��摜�\���̂̕ϐ�
//�߂�l�F�Ȃ�
VOID MY_GAZOU_LOAD(GAZOU *g, int x, int y, const char *path)
{
	wsprintf(g->FilePath, path);						//�t�@�C���p�X���R�s�[
	g->Handle = LoadGraph(g->FilePath);					//�摜���������ɓǂݍ��݁A�n���h�����擾
	GetGraphSize(g->Handle, &g->Width, &g->Height);		//�摜�T�C�Y���擾
	g->X = x;
	g->Y = y;
	g->C_Width = g->Width / 2;							//�摜�̉��T�C�Y�̒��S���擾
	g->C_Height = g->Height / 2;						//�摜�̏c�T�C�Y�̒��S���擾

	g->MoveSpeed = 10;									//�ړ����x

	
	return;
}