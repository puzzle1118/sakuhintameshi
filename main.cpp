#define _CRT_SECURE_NO_WARNINGS

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include <dos.h>
#include<math.h>
#include<stdlib.h>

//########## マクロ定義 ##########
#define GAME_WIDTH	640		//画面の横の大きさ
#define GAME_HEIGHT	640		//画面の縦の大きさ
#define GAME_COLOR	32		//画面のカラービット

#define GAME_WINDOW_NAME	"Cliate Adventure"		//ウィンドウのタイトル
#define GAME_WINDOW_MODECHANGE	TRUE			//TRUE：ウィンドウモード / FALSE：フルスクリーン

#define SET_WINDOW_ST_MODE_DEFAULT			0	//デフォルト
#define SET_WINDOW_ST_MODE_TITLE_NONE		1	//タイトルバーなし
#define SET_WINDOW_ST_MODE_TITLE_FLAME_NONE	2	//タイトルバーとフレームなし
#define SET_WINDOW_ST_MODE_FLAME_NONE		3	//フレームなし

#define FPS_SPEED    60

#define BACKIMAGE_1 "BACKIMAGE\\haikei1.png"

#define BACKIMAGE_SOUSA "BACKIMAGE\\haikei_setumei.png"

#define BACKIMAGE_OVER "BACKIMAGE\\haikei_over_kakou.png"

#define BACKIMAGE_CLEAR "BACKIMAGE\\haikei_clear_kakou.png"

#define BACKGROUND_TITLE "BACKIMAGE\\logo_3.png"

#define MESSAGE_WINDOW_BATTLE1 "MessageWindow\\message_window_battle1.png"
#define MESSAGE_WINDOW_BATTLE2 "MessageWindow\\message_window_battle2.png"
#define MESSAGE_WINDOW_BATTLE3 "MessageWindow\\message_window_battle3.png"

#define MOJI_GAME_OVER "BACKIMAGE\\GAME_OVER.png"

#define MAP_1   "MAPIMAGE\\map_hashi_kakudai.png"

#define MAP_CSV_1    "MAPIMAGE\\map_54_64.csv"

#define PLAYER_IMAGE "CHARA\\syuzinkou.png"

#define SE_JUMP "MUSIC\\jump.mp3"

#define SE_GAME_OVER "MUSIC\\oti.mp3"

#define SE_GAME_CLEAR "MUSIC\\levelup_win02.mp3"

#define BGM_GAME_PLAY "MUSIC\\bgm11.mp3"

#define BGM_GAME_OP "MUSIC\\game_field11.mp3"

#define BGM_GAME_SOUSA "MUSIC\\sousa_harp.mp3"

#define SLIME_IMAGE "image\\Slime.png"
#define TREE_IMAGE "image\\Tree.png"
#define BEETLE_IMAGE "image\\Beetle.png"
#define LIZARD_IMAGE "image\\Lizard.png"
#define SCORPION_IMAGE "image\\Scorpion.png"
#define SPIDER_IMAGE "image\\Spider.png"
#define CAT_IMAGE "image\\Cat.png"
#define CHICKEN_IMAGE "image\\Chicken.png"
#define BONE_IMAGE "image\\Bone.png"
#define DRAGON_IMAGE "image\\Dragon.png"
#define KNIGHT_IMAGE "image\\Knight.png"
#define KERBEROS_IMAGE "image\\Kerberos.png"
#define BOSS_IMAGE "image\\Boss.png"

#define BATTLE_BACKIMAGE_SOUGEN "BACKIMAGE\\sougen_kakou.jpg"
#define BATTLE_BACKIMAGE_SUNABA "BACKIMAGE\\sunaba.png"
#define BATTLE_BACKIMAGE_NUMA "BACKIMAGE\\numa.png"
#define BATTLE_BACKIMAGE_LAST_STAGE "BACKIMAGE\\last_stage.png"
#define BATTLE_BACKIMAGE_BOSS "BACKIMAGE\\boss.png"

#define MAP_BUN_TATE_CNT    20
#define MAP_BUN_YOKO_CNT    8

#define MAP_YOKO  54
#define MAP_TATE  64

#define MAP_OneBlock_TATE_SIZE   32
#define MAP_OneBlock_YOKO_SIZE   32

#define CHARA_BUN_YOKO_CNT 3
#define CHARA_BUN_TATE_CNT 4

#define GAME_ENEMY_BUN_YOKO_CNT 12
#define GAME_ENEMY_BUN_TATE_CNT 8

#define CHARA_TATE_SIZE     32
#define CHARA_YOKO_SIZE     32

#define CHARA_MOTION_NUM    12

#define CHARA_KIND_YOKO    3
#define CHARA_KIND_TATE    4  

#define RANDOM_NUM  450

/* マップによる移動の制限数 */
#define MAP_NOTDOWN_KIND    16
#define MAP_OKDOWN_KIND     16
#define MAP_NOTUP_KIND      16
#define MAP_NOTLEFT_KIND    16
#define MAP_NOTRIGHT_KIND   16
#define OFF_HIT 1
#define ON_HIT  1
#define GAME_MAP_GOAL_KIND      3  //ゴールの種類

#define MAP_SOUGEN  1 //マップチップの草原(敵キャラの出現を分ける用)
#define MAP_SUNABA   1 //マップチップの砂場(敵キャラの出現を分ける用)
#define MAP_NUMA  1 //マップチップの沼(敵キャラの出現を分ける用)
#define MAP_LAST_STAGE  1 //マップチップの最後の島(敵キャラの出現を分ける用)
//#define BOSS_CASTLE　2　//ボスの城の当たり判定

#define BOSS_STAGE 2

#define GAME_CHARA_SPEED      2//キャラのスピード

#define GRAVITY    9.8067 //重力加速度
#define CHARA_WEIGHT    60//キャラの重さ

#define GAME_PLAYER_ZANKI_MAX  3

//########## 列挙型 ##########
enum GAME_SCENE {
	GAME_SCENE_TITLE,	//タイトル画面
	GAME_SCENE_SOUSA,
	GAME_SCENE_ENEMY_1,		//バトル画面
	GAME_SCENE_ENEMY_2,		//バトル画面
	GAME_SCENE_ENEMY_3,		//バトル画面
	GAME_SCENE_ENEMY_4,		//バトル画面
	GAME_SCENE_ENEMY_5,		//バトル画面
	GAME_SCENE_ENEMY_6,		//バトル画面
	GAME_SCENE_ENEMY_7,		//バトル画面
	GAME_SCENE_ENEMY_8,		//バトル画面
	GAME_SCENE_ENEMY_9,		//バトル画面
	GAME_SCENE_ENEMY_10,	//バトル画面
	GAME_SCENE_ENEMY_11,	//バトル画面
	GAME_SCENE_ENEMY_12,	//バトル画面
	GAME_SCENE_ENEMY_13,	//バトル画面
	GAME_SCENE_PLAY,	//プレイ画面
	GAME_SCENE_OVER,   //ゲームオーバー画面
	GAME_SCENE_END		//エンド画面
};

enum MAP_IMAGE {
	M_N = -1,
	M_B = 19,
	M_G_T = 6,
	M_BLO = 67,
	M_ON = 125,
	M_OFF = 126,
	M_AM = 95,
	M_END = 399
};

enum CHARA_IMAGE {
	CHARA_KIND_1 = 0,
	CHARA_KIND_END = 11
};

enum Block_No {
	first,
	second,
	third,
	fourth,
	not_use
};

enum GAME_END_KIND {
	END_KIND_CONTINUE,
	END_KIND_OVER,
	END_KIND_CLEAR
};

//############構造体##############
typedef struct STRUCT_GAZOU {
	int Handle;
	char FilePath[128];
	int X;
	int Y;
	int Width;
	int Height;
	int c_Width;
	int c_Height;
}GAZOU;

GAZOU BACKGROUND;
GAZOU BACK_TITLE;
GAZOU MESSAGE_WIN_BATTLE1;
GAZOU MESSAGE_WIN_BATTLE2;
GAZOU MESSAGE_WIN_BATTLE3;
GAZOU BACK_SOUSA;
GAZOU BACK_OVER;
GAZOU IMAGESLIME;
GAZOU IMAGETREE;
GAZOU IMAGEBEETLE;
GAZOU IMAGELIZARD;
GAZOU IMAGESCORPION;
GAZOU IMAGESPIDER;
GAZOU IMAGECAT;
GAZOU IMAGECHICKEN;
GAZOU IMAGEBONE;
GAZOU IMAGEDRAGON;
GAZOU IMAGEKNIGHT;
GAZOU IMAGEKERBEROS;
GAZOU IMAGEBOSS;
GAZOU BACK_SOUGEN;
GAZOU BACK_SUNABA;
GAZOU BACK_NUMA;
GAZOU BACK_LAST_STAGE;
GAZOU BACK_BOSS;
GAZOU BACK_CLEAR;
GAZOU BACK_GAME_OVER;

typedef struct STRUCT_MAP
{
	char FilePath[128];
	int Handle[MAP_BUN_TATE_CNT * MAP_BUN_YOKO_CNT];
	int X[MAP_BUN_TATE_CNT * MAP_BUN_YOKO_CNT];
	int Y[MAP_BUN_YOKO_CNT * MAP_BUN_TATE_CNT];
	int Width[MAP_BUN_YOKO_CNT * MAP_BUN_TATE_CNT];
	int Height[MAP_BUN_YOKO_CNT * MAP_BUN_TATE_CNT];
	int C_Width[MAP_BUN_YOKO_CNT * MAP_BUN_TATE_CNT];
	int C_Height[MAP_BUN_YOKO_CNT * MAP_BUN_TATE_CNT];

	BOOL charaStopFlag_x;
	BOOL charaStopFlag_y;

	BOOL GoalFlag;

	int EndKind;

	BOOL GoalEffect1;
}MAP;

typedef struct STRUCT_CHARACTOR
{
	char FilePath[128];
	int Handle[GAME_ENEMY_BUN_YOKO_CNT * GAME_ENEMY_BUN_TATE_CNT];
	int X[GAME_ENEMY_BUN_YOKO_CNT * GAME_ENEMY_BUN_TATE_CNT];
	int Y[GAME_ENEMY_BUN_YOKO_CNT * GAME_ENEMY_BUN_YOKO_CNT];
	int Width[GAME_ENEMY_BUN_YOKO_CNT * GAME_ENEMY_BUN_TATE_CNT];
	int Height[GAME_ENEMY_BUN_YOKO_CNT * GAME_ENEMY_BUN_TATE_CNT];
	int C_Width[GAME_ENEMY_BUN_YOKO_CNT * GAME_ENEMY_BUN_TATE_CNT];
	int C_Height[GAME_ENEMY_BUN_YOKO_CNT * GAME_ENEMY_BUN_TATE_CNT];
}CHARA;

typedef struct STRUCT_PLAYER
{
	int Handle[CHARA_MOTION_NUM];
	int X;
	int Y;
	int Width;
	int Height;
	int C_Width;
	int C_Height;
	int NowHandleNum;
	int NowHandleCnt;
	int NowHandleCntMAX;

	int Speed;
	int MoveDist_x;
	int MoveDist_y;

	int LvUp_KEIKENTI;
	int Total_Keikenti;

	int Mass;
	int Weight;

	int Lv;
	int Keikenti;
	int HP;
	int ATK;
	int DEF;

	BOOL CanMoveLeft;
	BOOL CanMoveRight;

	BOOL CanMoveUp;
	BOOL CanMoveDown;

	int atariX;
	int atariY;
	int atariWidth;
	int atariHeight;

	RECT atariRect;

}PLAYER;

typedef struct SLIME_ST
{
	int Get_Keikenti;
	int HP;
	int ATK;
	int DEF;

}SLIME;

typedef struct TREE_ST
{
	int Get_Keikenti;
	int HP;
	int ATK;
	int DEF;

}TREE;

typedef struct BEETLE_ST
{
	int Get_Keikenti;
	int HP;
	int ATK;
	int DEF;

}BEETLE;

typedef struct LIZARD_ST
{
	int Get_Keikenti;
	int HP;
	int ATK;
	int DEF;

}LIZARD;

typedef struct SCORPION_ST
{
	int Get_Keikenti;
	int HP;
	int ATK;
	int DEF;

}SCORPION;

typedef struct SPIDER_ST
{
	int Get_Keikenti;
	int HP;
	int ATK;
	int DEF;

}SPIDER;

typedef struct CAT_ST
{
	int Get_Keikenti;
	int HP;
	int ATK;
	int DEF;

}CAT;

typedef struct CHIKEN_ST
{
	int Get_Keikenti;
	int HP;
	int ATK;
	int DEF;

}CHIKEN;

typedef struct BONE_ST
{
	int Get_Keikenti;
	int HP;
	int ATK;
	int DEF;

}BONE;

typedef struct DRAGON_ST
{
	int Get_Keikenti;
	int HP;
	int ATK;
	int DEF;

}DRAGON;

typedef struct KERBEROS_ST
{
	int Get_Keikenti;
	int HP;
	int ATK;
	int DEF;

}KERBEROS;

typedef struct KNIGHT_ST
{
	int Get_Keikenti;
	int HP;
	int ATK;
	int DEF;

}KNIGHT;

typedef struct BOSS_ST
{
	int Get_Keikenti;
	int HP;
	int ATK;
	int DEF;

}BOSS_BATTLE;

typedef struct STRUCT_MUSIC
{
	int Handle;
	char FilePath[128];
	int Playtype;
}MUSIC;

//########## グローバル変数 ##########

//typedef STRUCT_GAZOU GAZOU;
//typedef STRUCT_CHARACTOR CHARA;
//typedef STRUCT_MAP MAP;
//typedef STRUCT_PLAYER PLAYER;

//ウィンドウ関係
WNDPROC WndProc;						//ウィンドウプロシージャのアドレス
BOOL IsWM_CREATE = FALSE;				//WM_CREATEが正常に動作したか判断する

//FPS関連
int StartTimeFps;						//測定開始時刻
int CountFps;							//カウンタ
float CalcFps;							//計算結果
int SampleNumFps = FPS_SPEED;		//平均を取るサンプル数

//キーボード関連
char AllKeyState[256];			//すべてのキーの状態が入る
int GameSceneNow = (int)GAME_SCENE_TITLE;

GAZOU BackImage[4];
int ScrollCntYoko;
int ScrollCntTate;

BOOL player_ATC_CHECK = FALSE;				//プレイヤーが攻撃したときのメッセージを出力するするかどうかを判断する
BOOL player_ATC_CHECK_DEF = FALSE;				//プレイヤーが攻撃したときのメッセージを出力するするかどうかを判断する(相手の防御力がプレイヤーの攻撃力を上回った場合)

BOOL ENEMY_ATC_CHECK = FALSE;				//敵が攻撃したときのメッセージを出力するするかどうかを判断する
BOOL ENEMY_ATC_CHECK_DEF = FALSE;				//敵が攻撃したときのメッセージを出力するするかどうかを判断する(プレイヤーの防御力が敵の攻撃力を上回った場合)

int ScrollDistPlusYoko = 1;

MAP MapImage;
int ScrollDistKeyPlusYoko = 2;

int G_Cnt = 0;

int charaCnt = 0;

int mapCnt = 0;

PLAYER p;

int blockCnt = 0;

int random;

MUSIC MUSIC_SE_JUMP;
MUSIC MUSIC_SE_GAME_OVER;
MUSIC MUSIC_BGM_PLAY;
MUSIC MUSIC_OP;
MUSIC MUSIC_SOUSA;
MUSIC MUSIC_SE_CLEAR;

int turn = 0;
int Totalturn = 0;

int i = 0;
int tate = 0;
int yoko = 0;
int sum = 0;
int rCnt = 0;
int NotD_Cnt = 0;
int cnt = 0;
int mot = 0;

int num = 0;

int switch1 = 33;

int switch2 = 90;

long a, b;

int battle_random;

int time_miri;
int time_miri_keisoku;

double Time = 0;
double Time1 = 0;
double Time2 = 0;

double Goal_Time = 0;

int message;

CHARA CharaImage;
PLAYER Myplayer;

SLIME sli;
TREE tre;
BEETLE bee;
LIZARD liz;
SCORPION sco;
SPIDER spi;
CAT cat;
CHIKEN chi;
BONE bon;
DRAGON dra;
KERBEROS ker;
KNIGHT kni;
BOSS_BATTLE bos;

int FONTHANDLE_TAMESHI = 0;

int on_x = 0;
int on_y = 0;

int blockX = 0;
int blockY = 0;

FILE* fp_map_csv;

int MapData[MAP_TATE][MAP_YOKO];//マップのデータ

int MapData_Init[MAP_TATE][MAP_YOKO];//マップのデータ初期化用

int ZankiDrawCount = 0;
int ZankiDrawCountMax = 60;

int UntilZankiDrawCount = 0;
int UntilZankiDrawCountMax = 60;

BOOL tyakuti = FALSE;

int PlayerImageNum[CHARA_MOTION_NUM] = {
	0,  1,  2,
	3,  4,  5,
	6,  7,  8,
	9, 10, 11
};

int MapNotDownKind[MAP_NOTDOWN_KIND] = { 8,9,10,11,12,14,20,90,102,103,109,110, 117,121,126,139 };
int MapNotUpKind[MAP_NOTUP_KIND] = { 8,9,10,11,12,14,20,90,102,103,109,110, 117,121,126,139 };

int MapOKDownKind[MAP_OKDOWN_KIND] = { -1 };

int MapNotLeftKind[MAP_NOTLEFT_KIND] = { 8,9,10,11,12,14,20,90,102,103,109,110, 117,121,126,139 };
int MapNotRightKind[MAP_NOTRIGHT_KIND] = { 8,9,10,11,12,14,20,90,102,103,109,110, 117,121,126,139 };

int OffHit[OFF_HIT] = { 126 };
int OnHit[ON_HIT] = { 125 };

int MapGoalKind[GAME_MAP_GOAL_KIND] = { 204,224 };

int Sougen[MAP_SOUGEN] = { 0 };
int Sunaba[MAP_SUNABA] = { 124 };
int Numa[MAP_NUMA] = { 120 };
int Last_Stage[MAP_LAST_STAGE] = { 123 };

int Castle[BOSS_STAGE] = { 148, 149 };

RECT rectMap_DownNG[MAP_TATE][MAP_YOKO];
RECT rectMap_DownNG_First[MAP_TATE][MAP_YOKO];

RECT rectMap_DownOK[MAP_TATE][MAP_YOKO];
RECT rectMap_DownOK_First[MAP_TATE][MAP_YOKO];

RECT rectMap_LeftNG[MAP_TATE][MAP_YOKO];
RECT rectMap_LeftNG_First[MAP_TATE][MAP_YOKO];

RECT rectMap_Sougen[MAP_TATE][MAP_YOKO];
RECT rectMap_Sougen_First[MAP_TATE][MAP_YOKO];

RECT rectMap_Sunaba[MAP_TATE][MAP_YOKO];
RECT rectMap_Sunaba_First[MAP_TATE][MAP_YOKO];

RECT rectMap_Numa[MAP_TATE][MAP_YOKO];
RECT rectMap_Numa_First[MAP_TATE][MAP_YOKO];

RECT rectMap_Last_Stage[MAP_TATE][MAP_YOKO];
RECT rectMap_Last_Stage_First[MAP_TATE][MAP_YOKO];

RECT rectMap_Boss[MAP_TATE][MAP_YOKO];
RECT rectMap_Boss_First[MAP_TATE][MAP_YOKO];

RECT rectMap_RightNG[MAP_TATE][MAP_YOKO];
RECT rectMap_RightNG_First[MAP_TATE][MAP_YOKO];

RECT rectMap_UpNG[MAP_TATE][MAP_YOKO];
RECT rectMap_UpNG_First[MAP_TATE][MAP_YOKO];

//########## プロトタイプ宣言 ##########
LRESULT CALLBACK MY_WNDPROC(HWND, UINT, WPARAM, LPARAM);	//自作ウィンドウプロシージャ

VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//キーの入力状態を更新する関数

VOID MY_FPS_UPDATE(VOID);			//FPS値を計測、更新する関数
VOID MY_FPS_DRAW(VOID);				//FPS値を描画する関数

VOID MY_GAME_TITLE(VOID);			//タイトル画面の関数
VOID MY_GAME_SOUSA(VOID);           //操作説明画面の関数
VOID MY_GAME_PLAY(VOID);			//プレイ画面の関数
VOID MY_GAME_END(VOID);				//エンド画面の関数
VOID MY_GAME_OVER(VOID);				//ゲームオーバー画面の関数

BOOL MY_GAZOU_LOAD(GAZOU*, int, int, const char*);

BOOL MY_PLAY_INIT(VOID);
VOID MY_PLAY_BACKIMAGE_DRAW(VOID);
VOID MY_PLAY_SCROLL(VOID);

BOOL MY_MAP_READ_CSV_NUM(FILE*, const char*);

BOOL MY_CHARA_LOAD_BUNKATSU(CHARA*, int, int, int, int, int, const char*);
BOOL MY_INIT_PLAYER(PLAYER*, CHARA, int*, int, int, int);

//VOID BLOCK_INDICATE(VOID);//	ブロックを表示する関数

VOID MY_FPS_WAIT(VOID);				//FPS値を計測し、待つ関数
VOID MY_PLAY_PLAYER_DRAW(VOID);
VOID MY_PLAYER_OPERATION(VOID);

VOID MY_PLAY_MAP_DRAW(VOID);//マップを描画する関数

VOID MY_PLAY_PLAYER_JUMP_PREV(VOID);//ジャンプの前処理を行う関数

BOOL MY_PLAY_CHECK_GAME_END(VOID);//ゲームエンドか判定する関数

VOID MY_DRAW_STRING_CENTER_CENTER(char[][128], int, char*, int);//画面中央に文字を描画する関数
VOID MY_DRAW_SET_DEFAULT_FONT(BOOL);//文字をデフォルトフォントに設定する関数

VOID MY_BG_IMAGE_INIT(VOID);

/* 当たり判定の関数 */
VOID MY_SET_PLAYER_ATARI(PLAYER*);
BOOL MY_CHECK_RECT_ATARI(RECT, RECT);
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP(RECT, RECT[MAP_TATE][MAP_YOKO]);
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(RECT, RECT map[MAP_TATE][MAP_YOKO], int*, int*);

VOID MY_TITLE_BACKGROUND_DRAW(VOID);

VOID MY_OVER_BACKGROUND_DRAW(VOID);

VOID MY_CLEAR_BACKGROUND_DRAW(VOID);

VOID MY_SOUSA_BACKGROUND_DRAW(VOID);

VOID MY_GAME_OVER_BACKGROUND_DRAW(VOID);

VOID MY_SOUGEN_BACKGROUND_DRAW(VOID);
VOID MY_SUNABA_BACKGROUND_DRAW(VOID);
VOID MY_NUMA_BACKGROUND_DRAW(VOID);
VOID MY_LAST_STAGE_BACKGROUND_DRAW(VOID);
VOID MY_BOSS_BACKGROUND_DRAW(VOID);

VOID MY_MESSAGE_BATTLE1(VOID);//バトル画面のメッセージウィンドウを表示する関数
VOID MY_MESSAGE_BATTLE2(VOID);//バトル画面のメッセージウィンドウを表示する関数
VOID MY_MESSAGE_BATTLE3(VOID);//バトル画面のメッセージウィンドウを表示する関数

VOID MY_SLIME_DRAW(VOID);
VOID MY_TREE_DRAW(VOID);
VOID MY_BEETLE_DRAW(VOID);
VOID MY_LIZARD_DRAW(VOID);
VOID MY_SCORPION_DRAW(VOID);
VOID MY_SPIDER_DRAW(VOID);
VOID MY_CAT_DRAW(VOID);
VOID MY_CHICKEN_DRAW(VOID);
VOID MY_BONE_DRAW(VOID);
VOID MY_DRAGON_DRAW(VOID);
VOID MY_KNIGHT_DRAW(VOID);
VOID MY_KERBEROS_DRAW(VOID);
VOID MY_BOSS_DRAW(VOID);

BOOL BACKGROUND_LOAD(GAZOU*, int, int, const char*);

VOID MY_GAME_ZANKI(VOID);

VOID MY_FPS_DRAW(VOID);

BOOL MAP_INIT(MAP*, int, int, int, int, int, const char*);

VOID MY_TIMER(VOID);

BOOL MY_MUSIC_LOAD(MUSIC*, const char*);

VOID BATTLE_SLIME(VOID);
VOID BATTLE_TREE(VOID);
VOID BATTLE_BEETLE(VOID);
VOID BATTLE_SPIDER(VOID);
VOID BATTLE_LIZARD(VOID);
VOID BATTLE_SCOPION(VOID);
VOID BATTLE_CHICKEN(VOID);
VOID BATTLE_CAT(VOID);
VOID BATTLE_BONE(VOID);
VOID BATTLE_DRAGON(VOID);
VOID BATTLE_KERBEROS(VOID);
VOID BATTLE_KNIGHT(VOID);
VOID BATTLE_KNIGHT(VOID);
VOID BATTLE_BOSS(VOID);

VOID SLIME_INIT(SLIME*);
VOID TREE_INIT(TREE*);
VOID BEETLE_INIT(BEETLE*);
VOID LIZARD_INIT(LIZARD*);
VOID SCORPION_INIT(SCORPION*);
VOID SPIDER_INIT(SPIDER*);
VOID CAT_INIT(CAT*);
VOID CHIKEN_INIT(CHIKEN*);
VOID BONE_INIT(BONE*);
VOID DRAGON_INIT(DRAGON*);
VOID KERBEROS_INIT(KERBEROS*);
VOID KNIGHT_INIT(KNIGHT*);
VOID BOSS_INIT(BOSS_BATTLE*);

VOID BATTLE_SLIME_FLOW(VOID);
VOID BATTLE_TREE_FLOW(VOID);
VOID BATTLE_BEETLE_FLOW(VOID);
VOID BATTLE_LIZARD_FLOW(VOID);
VOID BATTLE_SCORPION_FLOW(VOID);
VOID BATTLE_SPIDER_FLOW(VOID);
VOID BATTLE_CAT_FLOW(VOID);
VOID BATTLE_CHIKEN_FLOW(VOID);
VOID BATTLE_BONE_FLOW(VOID);
VOID BATTLE_DRAGON_FLOW(VOID);
VOID BATTLE_KERBEROS_FLOW(VOID);
VOID BATTLE_KNIGHT_FLOW(VOID);
VOID BATTLE_BOSS_FLOW(VOID);

//########## プログラムで最初に実行される関数 ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(GAME_WINDOW_MODECHANGE);					//ウィンドウモードに設定
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//指定の数値で画面を表示する
	SetWindowStyleMode(SET_WINDOW_ST_MODE_DEFAULT);			//タイトルバーなし
	SetMainWindowText(TEXT(GAME_WINDOW_NAME));					//タイトルの文字

	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) { return -1; }

	//ＤＸライブラリ初期化処理

	SetDrawScreen(DX_SCREEN_BACK);

	MY_MUSIC_LOAD(&MUSIC_SE_JUMP, SE_JUMP);
	MY_MUSIC_LOAD(&MUSIC_SE_GAME_OVER, SE_GAME_OVER);
	MY_MUSIC_LOAD(&MUSIC_BGM_PLAY, BGM_GAME_PLAY);
	MY_MUSIC_LOAD(&MUSIC_OP, BGM_GAME_OP);
	MY_MUSIC_LOAD(&MUSIC_SOUSA, BGM_GAME_SOUSA);
	MY_MUSIC_LOAD(&MUSIC_SE_CLEAR, SE_GAME_CLEAR);

	/*if (!BACKGROUND_LOAD(&BACKGROUND, 0, 0, BACKIMAGE_1))
	{
		return -1;
	}
*/
	if (!BACKGROUND_LOAD(&BACK_TITLE, 0, 0, BACKGROUND_TITLE))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&MESSAGE_WIN_BATTLE1, 0, 0, MESSAGE_WINDOW_BATTLE1))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&MESSAGE_WIN_BATTLE2, 0, 0, MESSAGE_WINDOW_BATTLE2))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&MESSAGE_WIN_BATTLE3, 0, 0, MESSAGE_WINDOW_BATTLE3))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&BACK_CLEAR, 0, 0, BACKIMAGE_CLEAR))
	{
		return -1;
	}
	if (!BACKGROUND_LOAD(&BACK_SOUSA, 0, 0, BACKIMAGE_SOUSA))
	{
		return -1;
	}
	if (!BACKGROUND_LOAD(&BACK_OVER, 0, 0, BACKIMAGE_OVER))
	{
		return -1;
	}
	if (!BACKGROUND_LOAD(&BACK_GAME_OVER, 0, -100, MOJI_GAME_OVER))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&BACK_SOUGEN, 0, 0, BATTLE_BACKIMAGE_SOUGEN))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&BACK_SUNABA, 0, 0, BATTLE_BACKIMAGE_SUNABA))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&BACK_NUMA, 0, 0, BATTLE_BACKIMAGE_NUMA))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&BACK_LAST_STAGE, 0, 0, BATTLE_BACKIMAGE_LAST_STAGE))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&BACK_BOSS, 0, 0, BATTLE_BACKIMAGE_BOSS))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&IMAGESLIME, 180, 80, SLIME_IMAGE))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&IMAGETREE, 180, 80, TREE_IMAGE))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&IMAGEBEETLE, 180, 80, BEETLE_IMAGE))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&IMAGELIZARD, 180, 80, LIZARD_IMAGE))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&IMAGESCORPION, 180, 80, SCORPION_IMAGE))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&IMAGESPIDER, 180, 80, SPIDER_IMAGE))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&IMAGECAT, 180, 80, CAT_IMAGE))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&IMAGECHICKEN, 180, 80, CHICKEN_IMAGE))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&IMAGEBONE, 180, 80, BONE_IMAGE))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&IMAGEDRAGON, 180, 80, DRAGON_IMAGE))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&IMAGEKNIGHT, 180, 80, KNIGHT_IMAGE))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&IMAGEKERBEROS, 180, 80, KERBEROS_IMAGE))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&IMAGEBOSS, 90, 80, BOSS_IMAGE))
	{
		return -1;

	}

	if (MAP_INIT(&MapImage, MAP_BUN_YOKO_CNT * MAP_BUN_TATE_CNT, MAP_BUN_YOKO_CNT, MAP_BUN_TATE_CNT, 32, 32, MAP_1) == FALSE) { MessageBox(NULL, MAP_1, "NotFound", MB_OK); return -1; }

	if (MY_MAP_READ_CSV_NUM(fp_map_csv, MAP_CSV_1) == FALSE) { MessageBox(NULL, MAP_CSV_1, "NotFound", MB_OK); return -1; }

	if (MAP_INIT(&MapImage, 160, 8, 20, 32, 32, MAP_1) == FALSE) { return -1; }

	if (MY_CHARA_LOAD_BUNKATSU(&CharaImage, CHARA_BUN_YOKO_CNT * CHARA_BUN_TATE_CNT, CHARA_BUN_YOKO_CNT, CHARA_BUN_TATE_CNT, CHARA_YOKO_SIZE, CHARA_TATE_SIZE, PLAYER_IMAGE) == FALSE) { MessageBox(NULL, PLAYER_IMAGE, "NotFound", MB_OK); return -1; }

	FONTHANDLE_TAMESHI = CreateFontToHandle(NULL, 40, 3);

	//無限ループ
	while (TRUE)
	{
		Time1 = GetNowCount();

		if (ProcessMessage() != 0) { break; }	//メッセージ処理の結果がエラーのとき、強制終了

		if (ClearDrawScreen() != 0) { break; }	//画面を消去できなかったとき、強制終了

		MY_ALL_KEYDOWN_UPDATE();				//キーの状態を取得

		//シーン選択
		switch (GameSceneNow)
		{
		case (int)GAME_SCENE_TITLE:	//タイトル画面の処理ここから

			MY_GAME_TITLE();	//タイトル画面の処理

			break;	//タイトル画面の処理ここまで


		case (int)GAME_SCENE_SOUSA:

			MY_GAME_SOUSA();

			break;

			//case (int)GAME_SCENE_ZANKI://残機表示画面の処理ここから

			//	MY_GAME_ZANKI();//残機表示画面の処理

			//	break;

		case (int)GAME_SCENE_ENEMY_1:

			BATTLE_SLIME();

			break;

		case (int)GAME_SCENE_ENEMY_2:

			BATTLE_TREE();

			break;

		case (int)GAME_SCENE_ENEMY_3:

			BATTLE_BEETLE();

			break;

		case (int)GAME_SCENE_ENEMY_4:

			BATTLE_SPIDER();

			break;

		case (int)GAME_SCENE_ENEMY_5:

			BATTLE_LIZARD();

			break;


		case (int)GAME_SCENE_ENEMY_6:

			BATTLE_SCOPION();

			break;

		case (int)GAME_SCENE_ENEMY_7:

			BATTLE_CHICKEN();

			break;

		case (int)GAME_SCENE_ENEMY_8:

			BATTLE_CAT();

			break;

		case (int)GAME_SCENE_ENEMY_9:

			BATTLE_BONE();

			break;

		case (int)GAME_SCENE_ENEMY_10:

			BATTLE_DRAGON();

			break;

		case (int)GAME_SCENE_ENEMY_11:

			BATTLE_KERBEROS();

			break;

		case (int)GAME_SCENE_ENEMY_12:

			BATTLE_KNIGHT();

			break;

		case (int)GAME_SCENE_ENEMY_13:

			BATTLE_BOSS();

			break;
		case (int)GAME_SCENE_PLAY:	//プレイ画面の処理ここから

			MY_GAME_PLAY();		//プレイ画面の処理

			break;	//プレイ画面の処理ここまで

		case (int)GAME_SCENE_OVER:	//ゲームオーバー画面の処理ここから

			MY_GAME_OVER();		//ゲームオーバー画面の処理

			break;	//ゲームオーバー画面の処理ここまで


		case (int)GAME_SCENE_END:	//エンド画面の処理ここから

			MY_GAME_END();		//エンド画面の処理

			break;	//エンド画面の処理ここまで

		default:

			break;
		}

		MY_FPS_UPDATE();						//FPSの処理[更新]

		ScreenFlip();
		//モニタのリフレッシュレートの速さで裏画面を再描画

		MY_FPS_WAIT();		//FPSの処理[待つ]
	}

	DeleteMusicMem(MUSIC_SE_JUMP.Handle);
	DeleteMusicMem(MUSIC_SE_GAME_OVER.Handle);
	DeleteMusicMem(MUSIC_BGM_PLAY.Handle);
	DeleteMusicMem(MUSIC_OP.Handle);
	DeleteMusicMem(MUSIC_SOUSA.Handle);
	DeleteMusicMem(MUSIC_SE_CLEAR.Handle);

	for (mapCnt = 0; mapCnt < MAP_YOKO * MAP_TATE; mapCnt++)
	{
		DeleteGraph(MapImage.Handle[mapCnt]);
	}

	for (charaCnt = 0; charaCnt < CHARA_BUN_YOKO_CNT * CHARA_BUN_TATE_CNT; charaCnt++)
	{
		DeleteGraph(CharaImage.Handle[charaCnt]);
	}

	DxLib_End();		//ＤＸライブラリ使用の終了処理

	return 0;
}

//########## FPS値を計測、更新する関数 ##########
VOID MY_FPS_UPDATE(VOID)
{
	if (CountFps == 0) //1フレーム目なら時刻を記憶
	{
		StartTimeFps = GetNowCount();
	}

	if (CountFps == SampleNumFps) //60フレーム目なら平均を計算
	{
		int now = GetNowCount();
		CalcFps = 1000.f / ((now - StartTimeFps) / (float)SampleNumFps);
		CountFps = 0;
		StartTimeFps = now;
	}
	CountFps++;
	return;
}

//########## FPS値を計測し、待つ関数 ##########
VOID MY_FPS_WAIT(VOID)
{
	int resultTime = GetNowCount() - StartTimeFps;					//かかった時間
	int waitTime = CountFps * 1000 / FPS_SPEED - resultTime;	//待つべき時間

	if (waitTime > 0)		//指定のFPS値よりも早い場合
	{
		Sleep(waitTime);	//待つ
	}
	return;
}

VOID MY_FPS_DRAW(VOID)
{
	DrawFormatString(0, GAME_HEIGHT - 30, GetColor(255, 255, 255), "FPS:%.1lf", CalcFps);

	return;
}

//########## キーの入力状態を更新する関数 ##########
VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{
	char TempKey[256];

	GetHitKeyStateAll(TempKey);   //ずべてのキー入力状態を取得する

	for (i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)
		{
			AllKeyState[i]++;    //押されている
		}
		else
		{
			AllKeyState[i] = 0;  //押されていない
		}
	}
	return;
}

//########## タイトル画面の関数 ##########
VOID MY_GAME_TITLE(VOID)
{/*
	if (CheckSoundMem(MUSIC_OP.Handle) < 1 && CheckSoundMem(MUSIC_BGM_PLAY.Handle) == 0)
	{
		ChangeVolumeSoundMem(255, MUSIC_OP.Handle);
		PlaySoundMem(MUSIC_OP.Handle, DX_PLAYTYPE_LOOP);
	}*/

	if (CheckSoundMem(MUSIC_OP.Handle) == 0)
	{
		ChangeVolumeSoundMem(100, MUSIC_OP.Handle);
		PlaySoundMem(MUSIC_OP.Handle, DX_PLAYTYPE_LOOP);
	}
	MY_TITLE_BACKGROUND_DRAW();

	if (AllKeyState[KEY_INPUT_RETURN] != 0)
	{
		if (MY_PLAY_INIT() == TRUE)		//プレイ画面初期化
		{
			for (tate = 0; tate < MAP_TATE; tate++)
			{
				for (yoko = 0; yoko < MAP_YOKO; yoko++)
				{
					MapData[tate][yoko] = MapData_Init[tate][yoko];
				}
			}
		}
	}

	if (AllKeyState[KEY_INPUT_RETURN] != 0)	//エンターキーが押されていた時
	{
		StopSoundMem(MUSIC_OP.Handle);
		GameSceneNow = (int)GAME_SCENE_SOUSA;	//シーンを操作説明画面にする
	}

	//DrawString(310, 270, "ＧＭＤ", GetColor(255, 255, 255), SetFontSize(60));
	DrawString(140, 450, "エンターキーを押してください", GetColor(255, 255, 0), SetFontSize(30));

	return;
}

//##########操作説明画面##########
VOID MY_GAME_SOUSA(VOID)
{
	if (CheckSoundMem(MUSIC_SOUSA.Handle) == 0)
	{
		MUSIC_OP.Handle = 0;
		ChangeVolumeSoundMem(255 * 80 / 100, MUSIC_SOUSA.Handle);
		PlaySoundMem(MUSIC_SOUSA.Handle, DX_PLAYTYPE_BACK);
	}
	DrawBox(0, 0, 800, 640, GetColor(255, 255, 255), TRUE);
	MY_SOUSA_BACKGROUND_DRAW();
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//エンターキーが押されていた時
	{
		StopSoundMem(MUSIC_SOUSA.Handle);
		GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
		Time2 = Time1;
	}

	/*DrawString(60, 100, "・プレイヤーは左右矢印キーで左右移動", GetColor(0, 0, 0), SetFontSize(30));
	DrawString(90, 130, "上矢印キーでジャンプします。", GetColor(0, 0, 0), SetFontSize(30));
	DrawString(60, 170, "・途中にあるOFFスイッチを押すとブロックが", GetColor(0, 0, 0), SetFontSize(30));
	DrawString(90, 200, "出てきて、Ａキーで左に、Ｄキーで右にＳキーで", GetColor(0, 0, 0), SetFontSize(30));
	DrawString(90, 230, "下に移動します。", GetColor(0, 0, 0), SetFontSize(30));
	DrawString(60, 270, "※ブロックは必ずマップのどこか置くかブロックの", GetColor(255, 0, 0), SetFontSize(30));
	DrawString(90, 300, "上に積み上げて使いましょう！", GetColor(255, 0, 0), SetFontSize(30));
	DrawString(60, 340, "※ブロックは４個まで出てきます。", GetColor(255, 0, 0), SetFontSize(30));*/

	DrawString(190, 600, "スペースキーを押すとスタート", GetColor(0, 0, 0), SetFontSize(30));
}

VOID BATTLE_SLIME(VOID)
{
	MY_SOUGEN_BACKGROUND_DRAW();

	MY_MESSAGE_BATTLE1();
	MY_MESSAGE_BATTLE2();
	MY_MESSAGE_BATTLE3();

	MY_SLIME_DRAW();

	BATTLE_SLIME_FLOW();
	if (player_ATC_CHECK == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "スライムに%dダメージ", Myplayer.ATK - sli.DEF + battle_random);
	}
	if (player_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "スライムに%dダメージ", battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", sli.ATK - Myplayer.DEF + battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", battle_random);
	}

	//if (AllKeyState[KEY_INPUT_SPACE] != 0)	//エンターキーが押されていた時
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//}
}

VOID BATTLE_TREE(VOID)
{
	MY_SOUGEN_BACKGROUND_DRAW();

	MY_TREE_DRAW();

	BATTLE_TREE_FLOW();

	if (player_ATC_CHECK == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "ツリーに%dダメージ", Myplayer.ATK - tre.DEF + battle_random);
	}
	if (player_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "ツリーに%dダメージ", battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", tre.ATK - Myplayer.DEF + battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", battle_random);
	}

	//if (tre.HP < 0 || Myplayer.HP < 0)
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//	Totalturn = 0;
	//	turn = 0;
	//}

	//if (AllKeyState[KEY_INPUT_SPACE] != 0)	//エンターキーが押されていた時
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//}
}

VOID BATTLE_BEETLE(VOID)
{
	MY_SOUGEN_BACKGROUND_DRAW();

	MY_BEETLE_DRAW();

	BATTLE_BEETLE_FLOW();

	if (player_ATC_CHECK == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "ビートルに%dダメージ", Myplayer.ATK - bee.DEF + battle_random);
	}
	if (player_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "ビートルに%dダメージ", battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", bee.ATK - Myplayer.DEF + battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", battle_random);
	}

	//if (bee.HP < 0 || Myplayer.HP < 0)
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//	Totalturn = 0;
	//	turn = 0;
	//}

	//if (AllKeyState[KEY_INPUT_SPACE] != 0)	//エンターキーが押されていた時
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//}
}

VOID BATTLE_SPIDER(VOID)
{
	MY_SUNABA_BACKGROUND_DRAW();

	MY_SPIDER_DRAW();

	BATTLE_LIZARD_FLOW();

	if (player_ATC_CHECK == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "スパイダーに%dダメージ", Myplayer.ATK - spi.DEF + battle_random);
	}
	if (player_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "スパイダーに%dダメージ", battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", spi.ATK - Myplayer.DEF + battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", battle_random);
	}

	//if (liz.HP < 0 || Myplayer.HP < 0)
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//	Totalturn = 0;
	//	turn = 0;
	//}

	//if (AllKeyState[KEY_INPUT_SPACE] != 0)	//エンターキーが押されていた時
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//}
}

VOID BATTLE_LIZARD(VOID)
{
	MY_SUNABA_BACKGROUND_DRAW();

	MY_LIZARD_DRAW();

	BATTLE_LIZARD_FLOW();

	if (player_ATC_CHECK == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "リザードに%dダメージ", Myplayer.ATK - liz.DEF + battle_random);
	}
	if (player_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "リザードに%dダメージ", battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", liz.ATK - Myplayer.DEF + battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", battle_random);
	}

	//if (liz.HP < 0 || Myplayer.HP < 0)
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//	Totalturn = 0;
	//	turn = 0;
	//}

	//if (AllKeyState[KEY_INPUT_SPACE] != 0)	//エンターキーが押されていた時
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//}
}

VOID BATTLE_SCOPION(VOID)
{
	MY_SUNABA_BACKGROUND_DRAW();

	MY_SCORPION_DRAW();

	BATTLE_SCORPION_FLOW();

	if (player_ATC_CHECK == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "スコーピオンに%dダメージ", Myplayer.ATK - sco.DEF + battle_random);
	}
	if (player_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "スコーピオンに%dダメージ", battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", sco.ATK - Myplayer.DEF + battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", battle_random);
	}

	//if (sco.HP < 0 || Myplayer.HP < 0)
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//	Totalturn = 0;
	//	turn = 0;
	//}

	//if (AllKeyState[KEY_INPUT_SPACE] != 0)	//エンターキーが押されていた時
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//}
}

VOID BATTLE_CHICKEN(VOID)
{
	MY_NUMA_BACKGROUND_DRAW();

	MY_CHICKEN_DRAW();

	BATTLE_CHIKEN_FLOW();

	if (player_ATC_CHECK == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "チキンに%dダメージ", Myplayer.ATK - chi.DEF + battle_random);
	}
	if (player_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "チキンに%dダメージ", battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", chi.ATK - Myplayer.DEF + battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", battle_random);
	}

	//if (chi.HP < 0 || Myplayer.HP < 0)
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//	Totalturn = 0;
	//	turn = 0;
	//}

	//if (AllKeyState[KEY_INPUT_SPACE] != 0)	//エンターキーが押されていた時
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//}
}

VOID BATTLE_CAT(VOID)
{
	MY_NUMA_BACKGROUND_DRAW();

	MY_CAT_DRAW();

	BATTLE_CAT_FLOW();

	if (player_ATC_CHECK == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "ケットシーに%dダメージ", Myplayer.ATK - cat.DEF + battle_random);
	}
	if (player_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "ケットシーに%dダメージ", battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", cat.ATK - Myplayer.DEF + battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", battle_random);
	}

	//if (cat.HP < 0 || Myplayer.HP < 0)
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//	Totalturn = 0;
	//	turn = 0;
	//}

	//if (AllKeyState[KEY_INPUT_SPACE] != 0)	//エンターキーが押されていた時
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//}
}

VOID BATTLE_BONE(VOID)
{
	MY_NUMA_BACKGROUND_DRAW();

	MY_BONE_DRAW();

	BATTLE_BONE_FLOW();

	if (player_ATC_CHECK == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "ボーンに%dダメージ", Myplayer.ATK - bon.DEF + battle_random);
	}
	if (player_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "ボーンに%dダメージ", battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", bon.ATK - Myplayer.DEF + battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", battle_random);
	}

	//if (bon.HP < 0 || Myplayer.HP < 0)
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//	Totalturn = 0;
	//	turn = 0;
	//}

	//if (AllKeyState[KEY_INPUT_SPACE] != 0)	//エンターキーが押されていた時
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//}
}

VOID BATTLE_DRAGON(VOID)
{

	MY_LAST_STAGE_BACKGROUND_DRAW();

	MY_DRAGON_DRAW();

	BATTLE_DRAGON_FLOW();

	if (player_ATC_CHECK == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "ドラゴンに%dダメージ", Myplayer.ATK - dra.DEF + battle_random);
	}
	if (player_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "ドラゴンに%dダメージ", battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", dra.ATK - Myplayer.DEF + battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", battle_random);
	}

	//if (dra.HP < 0 || Myplayer.HP < 0)
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//	Totalturn = 0;
	//	turn = 0;
	//}

	//if (AllKeyState[KEY_INPUT_SPACE] != 0)	//エンターキーが押されていた時
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//}
}

VOID BATTLE_KERBEROS(VOID)
{
	MY_LAST_STAGE_BACKGROUND_DRAW();

	MY_KERBEROS_DRAW();

	BATTLE_KERBEROS_FLOW();

	if (player_ATC_CHECK == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "ケルベロスに%dダメージ", Myplayer.ATK - ker.DEF + battle_random);
	}
	if (player_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "ケルベロスに%dダメージ", battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", ker.ATK - Myplayer.DEF + battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", battle_random);
	}

	//if (ker.HP < 0 || Myplayer.HP < 0)
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//	Totalturn = 0;
	//	turn = 0;
	//}

	//if (AllKeyState[KEY_INPUT_SPACE] != 0)	//エンターキーが押されていた時
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//}
}

VOID BATTLE_KNIGHT(VOID)
{
	MY_LAST_STAGE_BACKGROUND_DRAW();

	MY_KNIGHT_DRAW();

	BATTLE_KNIGHT_FLOW();

	if (player_ATC_CHECK == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "ナイトに%dダメージ", Myplayer.ATK - kni.DEF + battle_random);
	}
	if (player_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "ナイトに%dダメージ", battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", kni.ATK - Myplayer.DEF + battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", battle_random);
	}

	//if (kni.HP < 0 || Myplayer.HP < 0)
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//	Totalturn = 0;
	//	turn = 0;
	//}

	//if (AllKeyState[KEY_INPUT_SPACE] != 0)	//エンターキーが押されていた時
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//}
}

VOID BATTLE_BOSS(VOID)
{
	MY_BOSS_BACKGROUND_DRAW();//ボス戦の背景を描画

	MY_BOSS_DRAW();//ボスを描画

	BATTLE_BOSS_FLOW();

	if (player_ATC_CHECK == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "ボスに%dダメージ", Myplayer.ATK - bos.DEF + battle_random);
	}
	if (player_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "ボスに%dダメージ", battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", bos.ATK - Myplayer.DEF + battle_random);
	}

	if (ENEMY_ATC_CHECK_DEF == TRUE) {
		DrawFormatString(240, GAME_HEIGHT - 160, GetColor(255, 255, 255), "プレイヤーに%dダメージ", battle_random);
	}

	//if (bos.HP < 0 || Myplayer.HP < 0)
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//	Totalturn = 0;
	//	turn = 0;
	//}

	//if (AllKeyState[KEY_INPUT_SPACE] != 0)	//エンターキーが押されていた時
	//{
	//	GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	//	random = 0;
	//}
}

//########## プレイ画面の関数 ##########
VOID MY_GAME_PLAY(VOID)
{
	SLIME_INIT(&sli);
	TREE_INIT(&tre);
	BEETLE_INIT(&bee);
	LIZARD_INIT(&liz);
	SCORPION_INIT(&sco);
	SPIDER_INIT(&spi);
	CAT_INIT(&cat);
	CHIKEN_INIT(&chi);
	BONE_INIT(&bon);
	DRAGON_INIT(&dra);
	KERBEROS_INIT(&ker);
	KNIGHT_INIT(&kni);
	BOSS_INIT(&bos);

	if (CheckSoundMem(MUSIC_BGM_PLAY.Handle) == 0)
	{
		MUSIC_OP.Handle = 0;
		ChangeVolumeSoundMem(255 * 80 / 200, MUSIC_BGM_PLAY.Handle);
		PlaySoundMem(MUSIC_BGM_PLAY.Handle, DX_PLAYTYPE_BACK);
	}
	Time = (GetNowCount() - Time1) / 1000;

	//DrawFormatStringToHandle(300, 64, GetColor(255, 255, 255), FONTHANDLE_TAMESHI, "%d", Myplayer.Y);
	/*DrawFormatString(300, 0, GetColor(255, 255, 255), "クリアタイム%d秒", Time);*/

	/*time_miri_keisoku++;
	DrawFormatString(0, 0, GetColor(255, 255, 255), "クリアタイム%d秒", Time);*/

	//if (AllKeyState[KEY_INPUT_SPACE] != 0)
	//{
	//	//G ameSceneNow = (int)GAME_SCENE_END;
	//}
	if (AllKeyState[KEY_INPUT_RIGHT] == 0 && AllKeyState[KEY_INPUT_UP] == 0 && AllKeyState[KEY_INPUT_DOWN] == 0)
	{
		if (AllKeyState[KEY_INPUT_LEFT] != 0)
		{

			if (Myplayer.CanMoveLeft == TRUE)//プレイヤーが左に動けるとき
			{
				if (MapImage.charaStopFlag_x == TRUE)//プレイヤーを動かせないならば
				{
					if (ScrollCntYoko > 0)//マイナスのスクロールをしない
					{
						ScrollCntYoko -= Myplayer.Speed;//画面を左にスクロール
					}
				}
			}
		}
	}
	if (AllKeyState[KEY_INPUT_LEFT] == 0 && AllKeyState[KEY_INPUT_UP] == 0 && AllKeyState[KEY_INPUT_DOWN] == 0)
	{
		if (AllKeyState[KEY_INPUT_RIGHT] != 0)
		{
			if (Myplayer.CanMoveRight == TRUE)//プレイヤーが右に動けるとき
			{
				if (MapImage.charaStopFlag_x == TRUE)//プレイヤーを動かせないならば
				{
					if (ScrollCntYoko < MAP_OneBlock_YOKO_SIZE * MAP_YOKO)//画面外へスクロールをしない
					{
						ScrollCntYoko += Myplayer.Speed;//画面を右にスクロール
					}
				}
			}
		}
	}

	if (AllKeyState[KEY_INPUT_RIGHT] == 0 && AllKeyState[KEY_INPUT_LEFT] == 0 && AllKeyState[KEY_INPUT_DOWN] == 0)
	{
		if (AllKeyState[KEY_INPUT_UP] != 0)
		{
			if (Myplayer.CanMoveUp == TRUE)//プレイヤーが上に動けるとき
			{
				if (MapImage.charaStopFlag_y == TRUE)//プレイヤーを動かせないならば
				{
					if (ScrollCntTate > 0)//マイナスのスクロールをしない
					{
						ScrollCntTate -= Myplayer.Speed;//画面を左にスクロール
					}
				}
			}
		}
	}
	//if (AllKeyState[KEY_INPUT_UP] != 0)
	//{
	//		if (MapImage.charaStopFlag_y == TRUE)//プレイヤーを動かせないならば
	//		{
	//			if (Myplayer.Y == 0 || Myplayer.Y <= MAP_OneBlock_TATE_SIZE*10)
	//			{
	//					Myplayer.Y += Myplayer.Speed;
	//					ScrollCntTate -= Myplayer.Speed * 2;//画面を下にスクロール
	//			}
	//		}	
	//}
	if (AllKeyState[KEY_INPUT_RIGHT] == 0 && AllKeyState[KEY_INPUT_LEFT] == 0 && AllKeyState[KEY_INPUT_UP] == 0)
	{
		if (AllKeyState[KEY_INPUT_DOWN] != 0)
		{
			if (Myplayer.CanMoveDown == TRUE)//プレイヤーが下に動けるとき
			{
				if (MapImage.charaStopFlag_y == TRUE)//プレイヤーを動かせないならば
				{
					if (ScrollCntTate < MAP_OneBlock_TATE_SIZE * MAP_TATE)//画面外へスクロールをしない
					{
						ScrollCntTate += Myplayer.Speed;//画面を上にスクロール
					}
				}
			}
		}
	}

	//if (MY_PLAY_CHECK_GAME_END() == TRUE)
	//{
	//	/*getch();*/
	//	StopSoundMem(MUSIC_BGM_PLAY.Handle);
	//	GameSceneNow = (int)GAME_SCENE_END;
	//}
	/*else
	{*/
	MY_PLAYER_OPERATION();	//プレイヤーの操作
//}

	if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_Sougen) == TRUE)
	{
		if (random == 1)
		{
			GameSceneNow = (int)GAME_SCENE_ENEMY_1;
		}
	}

	if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_Sougen) == TRUE)
	{
		if (random == 151)
		{
			GameSceneNow = (int)GAME_SCENE_ENEMY_2;
		}
	}

	if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_Sougen) == TRUE)
	{
		if (random == 301)
		{
			GameSceneNow = (int)GAME_SCENE_ENEMY_3;
		}
	}

	if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_Sunaba) == TRUE)
	{
		if (random == 1)
		{
			GameSceneNow = (int)GAME_SCENE_ENEMY_4;
		}
	}

	if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_Sunaba) == TRUE)
	{
		if (random == 151)
		{
			GameSceneNow = (int)GAME_SCENE_ENEMY_5;
		}
	}

	if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_Sunaba) == TRUE)
	{
		if (random == 301)
		{
			GameSceneNow = (int)GAME_SCENE_ENEMY_6;
		}
	}

	if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_Numa) == TRUE)
	{
		if (random == 1)
		{
			GameSceneNow = (int)GAME_SCENE_ENEMY_7;
		}
	}

	if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_Numa) == TRUE)
	{
		if (random == 151)
		{
			GameSceneNow = (int)GAME_SCENE_ENEMY_8;
		}
	}

	if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_Numa) == TRUE)
	{
		if (random == 301)
		{
			GameSceneNow = (int)GAME_SCENE_ENEMY_9;
		}
	}

	if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_Last_Stage) == TRUE)
	{
		if (random == 1)
		{
			GameSceneNow = (int)GAME_SCENE_ENEMY_10;
		}
	}

	if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_Last_Stage) == TRUE)
	{
		if (random == 151)
		{
			GameSceneNow = (int)GAME_SCENE_ENEMY_11;
		}
	}

	if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_Last_Stage) == TRUE)
	{
		if (random == 301)
		{
			GameSceneNow = (int)GAME_SCENE_ENEMY_12;
		}
	}

	if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_Boss) == TRUE)
	{

		GameSceneNow = (int)GAME_SCENE_ENEMY_13;
	}

	//MY_PLAYER_OPERATION();

	MY_PLAY_BACKIMAGE_DRAW();//背景を描画

	MY_PLAY_MAP_DRAW();  //マップを描画

	//DrawFormatStringToHandle(300, 64, GetColor(255, 255, 255), FONTHANDLE_TAMESHI, "%d", Myplayer.Y);

	//DrawBox(Myplayer.atariRect.left, Myplayer.atariRect.top, Myplayer.atariRect.right, Myplayer.atariRect.bottom, GetColor(255, 0, 0), TRUE);

	DrawFormatStringToHandle(260, 0, GetColor(255, 255, 255), FONTHANDLE_TAMESHI, "経過時間%0.2lf秒", (Time1 - Time2) / 1000);

	MY_PLAY_PLAYER_DRAW();

	//DrawString(0, 0, "エンターキーを押すと移動", GetColor(255, 255, 255));
	//DrawFormatString(20, 20, GetColor(255, 255, 255), "%d", playerX);

	return;
}

//###########画面中央に文字を描画する関数############
VOID MY_DRAW_STRING_CENTER_CENTER(char str[][128], int row, char* fontname, int size)
{
	ChangeFont(fontname, DX_CHARSET_DEFAULT);//デフォルトのフォントを変更する
	SetFontSize(size);                       //デフォルトのフォントサイズを変える
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE);//フォントをきれいにみせる

	int StrHeightSum = 0;
	for (sum = 0; sum < row; sum++)//行全体の高さを集計
	{
		StrHeightSum += GetFontSize();//デフォルトのフォントの高さを取得
	}

	for (rCnt = 0; rCnt < row; rCnt++)//フォントを描画
	{
		int StrWidth = GetDrawFormatStringWidth(&str[rCnt][0]);//デフォルトのフォントの横幅を取得
		int StrHeight = GetFontSize();

		DrawFormatString(
			GAME_WIDTH / 2 - StrWidth / 2,
			GAME_HEIGHT / 2 - StrHeightSum + StrHeight * rCnt,//画面の中心　-　行全体の文字の高さ　+　１行の高さ
			GetColor(255, 255, 255), &str[rCnt][0]);//デフォルトのフォントで描画
	}

	MY_DRAW_SET_DEFAULT_FONT(TRUE);//デフォルトフォントに設定する
}

VOID MY_GAME_OVER(VOID)
{
	MUSIC_BGM_PLAY.Handle = 0;
	ChangeVolumeSoundMem(255 * 80 / 100, MUSIC_SE_GAME_OVER.Handle);
	PlaySoundMem(MUSIC_SE_GAME_OVER.Handle, DX_PLAYTYPE_BACK);

	if (AllKeyState[KEY_INPUT_BACK] != 0)
	{
		GameSceneNow = (int)GAME_SCENE_TITLE;	//シーンをタイトル画面にする
	}
}

//########## ゲームエンドか判定する関数 ##########
BOOL MY_PLAY_CHECK_GAME_END(VOID)
{
	//プレイヤーの位置は、プレイヤーの中心
	int PlayerToMapNumY = (Myplayer.MoveDist_y + Myplayer.C_Height) / MAP_OneBlock_TATE_SIZE;
	int PlayerToMapNumX = (Myplayer.MoveDist_x + Myplayer.C_Width) / MAP_OneBlock_TATE_SIZE;


	//プレイヤー画面外に落ちたとき
	if (Myplayer.HP <= 0)
	{
		ChangeVolumeSoundMem(255 * 80 / 100, MUSIC_SE_GAME_OVER.Handle);
		PlaySoundMem(MUSIC_SE_GAME_OVER.Handle, DX_PLAYTYPE_BACK);
		//MapImage.EndKind = (int)END_KIND_CONTINUE;

		MapImage.EndKind = (int)END_KIND_OVER;

		return TRUE;
	}

	if (PlayerToMapNumX<0 || PlayerToMapNumX>MAP_YOKO) { return FALSE; }
	if (PlayerToMapNumY<0 || PlayerToMapNumY>MAP_TATE) { return FALSE; }

	for (G_Cnt = 0; G_Cnt < GAME_MAP_GOAL_KIND; G_Cnt++)
	{
		//プレイヤーがゴールのものと接触したとき
		if (MapData[PlayerToMapNumY][PlayerToMapNumX] == MapGoalKind[G_Cnt])
		{

			Goal_Time = (Time1 - Time2) / 1000;
			/*if (Myplayer.GetRedCoinNum == 5)
			{*/
			ChangeVolumeSoundMem(255 * 80 / 100, MUSIC_SE_CLEAR.Handle);
			PlaySoundMem(MUSIC_SE_CLEAR.Handle, DX_PLAYTYPE_BACK);
			MapImage.EndKind = (int)END_KIND_CLEAR;
			return TRUE;
			break;
			//}
		}
	}
	return FALSE;//ゲーム続行
}

//########## エンド画面の関数 ##########
VOID MY_GAME_END(VOID)
{
	if (AllKeyState[KEY_INPUT_BACK] != 0)	//バックスペースーキーが押されていた時
	{
		GameSceneNow = (int)GAME_SCENE_TITLE;	//シーンをタイトル画面にする
	}

	MapData[16][17] = (int)M_N;

	MapData[17][53] = (int)M_N;

	MapData[16][108] = (int)M_N;
	MapData[14][109] = (int)M_N;
	MapData[12][110] = (int)M_N;
	MapData[10][111] = (int)M_N;
	/*for (int o = first; o <= fourth; o++)

		if (PlayerToMapNumY - 1 == 17 && PlayerToMapNumX == 53)
	{
		MapData[PlayerToMapNumY - 1][PlayerToMapNumX] = (int)M_BLO;
	}

	if (PlayerToMapNumY - 1 == 16 && PlayerToMapNumX == 108)
	{
		MapData[PlayerToMapNumY - 1][PlayerToMapNumX] = (int)M_BLO;
	}

	if (PlayerToMapNumY - 1 == 14 && PlayerToMapNumX == 109)
	{
		MapData[PlayerToMapNumY - 1][PlayerToMapNumX] = (int)M_BLO;
	}

	if (PlayerToMapNumY - 1 == 12 && PlayerToMapNumX == 110)
	{
		MapData[PlayerToMapNumY - 1][PlayerToMapNumX] = (int)M_BLO;
	}

	if (PlayerToMapNumY - 1 == 10 && PlayerToMapNumX == 111)
	{
		MapData[PlayerToMapNumY - 1][PlayerToMapNumX] = (int)M_BLO;
	{*/

	if (MapImage.EndKind == (int)END_KIND_OVER)	//ゲームオーバーのとき
	{
		MY_OVER_BACKGROUND_DRAW();
		char StrGameOver[2][128] = { "諦めるのはまだ早い","" };
		char StrFontOver[128] = { "MS ゴシック" };

		MY_DRAW_STRING_CENTER_CENTER(&StrGameOver[0], 2, StrFontOver, 40);

		MY_GAME_OVER_BACKGROUND_DRAW();
	}

	else if (MapImage.EndKind == (int)END_KIND_CLEAR)	//ゲームクリアのとき
	{
		MY_CLEAR_BACKGROUND_DRAW();

		DrawFormatStringToHandle(180, 0, GetColor(255, 255, 0), FONTHANDLE_TAMESHI, "あなたの記録は%0.2lf秒です", Goal_Time);
		char StrGameClear[2][128] = { "GAME CLEAR","簡単だったかな？" };
		DrawString(180, 400, "自己ベスト更新を目指そう！！", GetColor(0, 255, 0), SetFontSize(30));
		/*char StrGameClear_koushin[128] = { "自己ベスト更新を目指そう！！" };*/
		char StrFontClear[128] = { "MS ゴシック" };

		MY_DRAW_STRING_CENTER_CENTER(&StrGameClear[0], 2, StrFontClear, 40);
		/*MY_DRAW_STRING_CENTER_CENTER(&StrGameClear_koushin[0], 2, StrFontClear, 80);*/

	}
	else if (MapImage.EndKind == (int)END_KIND_CONTINUE)	//ゲーム続行のとき
	{
		if (UntilZankiDrawCount < UntilZankiDrawCountMax)
		{
			UntilZankiDrawCount++;
			//透明にする数値(0が透過なし、255が透過する)
			double ToukaPercent = UntilZankiDrawCount / (double)UntilZankiDrawCountMax;//透過％を求める

			DrawBox(0, 0, GAME_WIDTH, GAME_HEIGHT, GetColor(0, 0, 0), TRUE);//真っ暗な画面にする

			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
		else
		{
			if (MY_PLAY_INIT() == TRUE)	//プレイヤーの位置などの初期化処理
			{

			}
		}
	}

	DrawString(45, 490, "タイトルに戻るにはバックスペースキーを押してください", GetColor(255, 0, 0), SetFontSize(25));

	DrawString(130, 520, "終了したい場合は右クリックをしてください", GetColor(255, 0, 0), SetFontSize(25));

	return;
}

//文字をデフォルトフォントに設定する関数
VOID MY_DRAW_SET_DEFAULT_FONT(BOOL anti)
{
	ChangeFont("MS ゴシック", DX_CHARSET_DEFAULT);
	SetFontSize(16);

	if (anti)
	{
		ChangeFontType(DX_FONTTYPE_ANTIALIASING);
	}
	return;
}

//########## ウィンドウプロシージャ関数 ##########
LRESULT CALLBACK MY_WNDPROC(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	int closeMsgRet = 0;

	switch (msg)
	{
	case WM_CREATE:	//ウィンドウの生成＆初期化

		IsWM_CREATE = TRUE;	//WM_CREATE正常終了
		return 0;

	case WM_CLOSE:		//閉じるボタンを押したとき

		message = MessageBox(hwnd, TEXT("ゲームを終了します"), TEXT("終了メッセージ"), MB_OK/*YESNO*/);

		/*	if (message == IDYES)
			{
				return 0;
			}
			else
			{
				DefWindowProc(hwnd, msg, wp, lp);
			}*/

		break;

	case WM_RBUTTONDOWN:	//マウスの右ボタンを押したとき

		closeMsgRet = MessageBox(hwnd, TEXT("ゲームを終了しますか"), TEXT("終了メッセージ"), MB_YESNO);

		if (closeMsgRet == IDYES)
		{
			SendMessage(hwnd, WM_CLOSE, 0, 0);		//WM_CLOSEメッセージをキューに追加
		}
		else if (closeMsgRet == IDNO)
		{
			//break;
		}

		break;

	case WM_LBUTTONDOWN:	//マウスの左ボタンを押したとき

		//WM_NCLBUTTONDOWN(タイトルバーでマウスの左ボタンを押した)メッセージをすぐに発行
		//PostMessage(hwnd, WM_NCLBUTTONDOWN, (WPARAM)HTCAPTION, lp);
		break;

	case WM_DESTROY:	//ウィンドウが破棄された(なくなった)とき

		PostQuitMessage(0);		//メッセージキューに WM_QUIT を送る

		return 0;
	}
	//デフォルトのウィンドウプロシージャ関数を呼び出す
	return DefWindowProc(hwnd, msg, wp, lp);
}

//初期化の関数
BOOL MY_PLAY_INIT(VOID)
{
	if (MY_INIT_PLAYER(&Myplayer, CharaImage, &PlayerImageNum[0], MAP_OneBlock_YOKO_SIZE * 0, MAP_OneBlock_TATE_SIZE * 0, GAME_CHARA_SPEED) == FALSE) { MessageBox(NULL, "CHARA_INIT", "NotFound", MB_OK); return FALSE; }

	MapImage.GoalFlag = FALSE;//ゴール状態を初期化

	MapImage.EndKind = (int)END_KIND_CONTINUE;

	MapImage.GoalEffect1 = FALSE;

	//プレイヤーの初期化

	MY_DRAW_SET_DEFAULT_FONT(TRUE);	//デフォルトフォントに設定する

	MY_BG_IMAGE_INIT();//背景の位置を初期化

	ScrollCntYoko = 0;    //スクロール量を初期化
	ScrollCntTate = 1408;    //スクロール量を初期化

	ZankiDrawCount = 0;//残機表示カウンタ初期化
	UntilZankiDrawCount = 0;//残機表示までのカウンタ初期化

	return TRUE;
}

VOID MY_BG_IMAGE_INIT(VOID)
{
	//背景の位置
	BackImage[0].X = 0;

	return;
}

//プレイ画面の背景を描画する関数
VOID MY_PLAY_BACKIMAGE_DRAW(VOID)
{
	DrawGraph(BACKGROUND.X, BACKGROUND.Y, BACKGROUND.Handle, TRUE);
}
//タイトル画面の背景を描画する関数
VOID MY_TITLE_BACKGROUND_DRAW(VOID)
{
	DrawGraph(BACK_TITLE.X, BACK_TITLE.Y, BACK_TITLE.Handle, TRUE);
}

//バトル画面のメッセージウィンドウを描画する関数
VOID MY_MESSAGE_BATTLE1(VOID)
{
	DrawGraph(MESSAGE_WIN_BATTLE1.X, MESSAGE_WIN_BATTLE1.Y, MESSAGE_WIN_BATTLE1.Handle, TRUE);
}

//バトル画面のメッセージウィンドウを描画する関数
VOID MY_MESSAGE_BATTLE2(VOID)
{
	DrawGraph(MESSAGE_WIN_BATTLE2.X, MESSAGE_WIN_BATTLE2.Y, MESSAGE_WIN_BATTLE2.Handle, TRUE);
}

//バトル画面のメッセージウィンドウを描画する関数
VOID MY_MESSAGE_BATTLE3(VOID)
{
	DrawGraph(MESSAGE_WIN_BATTLE3.X, MESSAGE_WIN_BATTLE3.Y, MESSAGE_WIN_BATTLE3.Handle, TRUE);
}

//ゲームオーバー画面の背景を描画する関数
VOID MY_OVER_BACKGROUND_DRAW(VOID)
{
	DrawGraph(BACK_OVER.X, BACK_OVER.Y, BACK_OVER.Handle, TRUE);
}
//クリア画面の背景を描画する関数
VOID MY_CLEAR_BACKGROUND_DRAW(VOID)
{
	DrawGraph(BACK_CLEAR.X, BACK_CLEAR.Y, BACK_CLEAR.Handle, TRUE);
}

//草原でのバトル画面の背景を描画する関数
VOID MY_SOUGEN_BACKGROUND_DRAW(VOID)
{
	DrawGraph(BACK_SOUGEN.X, BACK_SOUGEN.Y, BACK_SOUGEN.Handle, TRUE);
}

VOID MY_SUNABA_BACKGROUND_DRAW(VOID)
{
	DrawGraph(BACK_SUNABA.X, BACK_SUNABA.Y, BACK_SUNABA.Handle, TRUE);
}

VOID MY_NUMA_BACKGROUND_DRAW(VOID)
{
	DrawGraph(BACK_NUMA.X, BACK_NUMA.Y, BACK_NUMA.Handle, TRUE);
}

VOID MY_LAST_STAGE_BACKGROUND_DRAW(VOID)
{
	DrawGraph(BACK_LAST_STAGE.X, BACK_LAST_STAGE.Y, BACK_LAST_STAGE.Handle, TRUE);
}

VOID MY_BOSS_BACKGROUND_DRAW(VOID)
{
	DrawGraph(BACK_BOSS.X, BACK_BOSS.Y, BACK_BOSS.Handle, TRUE);
}

//操作説明画面の背景を描画する関数
VOID MY_SOUSA_BACKGROUND_DRAW(VOID)
{
	DrawGraph(BACK_SOUSA.X, BACK_SOUSA.Y, BACK_SOUSA.Handle, TRUE);
}

VOID MY_GAME_OVER_BACKGROUND_DRAW(VOID)
{
	DrawGraph(BACK_GAME_OVER.X, BACK_GAME_OVER.Y, BACK_GAME_OVER.Handle, TRUE);
}

//スライムを描画する関数
VOID MY_SLIME_DRAW(VOID)
{
	DrawGraph(IMAGESLIME.X, IMAGESLIME.Y, IMAGESLIME.Handle, TRUE);
}

//木を描画する関数
VOID MY_TREE_DRAW(VOID)
{
	DrawGraph(IMAGETREE.X, IMAGETREE.Y, IMAGETREE.Handle, TRUE);
}
//ビートルを描画する関数
VOID MY_BEETLE_DRAW(VOID)
{
	DrawGraph(IMAGEBEETLE.X, IMAGEBEETLE.Y, IMAGEBEETLE.Handle, TRUE);
}
//リザードを描画する関数
VOID MY_LIZARD_DRAW(VOID)
{
	DrawGraph(IMAGELIZARD.X, IMAGELIZARD.Y, IMAGELIZARD.Handle, TRUE);
}
//サソリを描画する関数
VOID MY_SCORPION_DRAW(VOID)
{
	DrawGraph(IMAGESCORPION.X, IMAGESCORPION.Y, IMAGESCORPION.Handle, TRUE);
}
//クモを描画する関数
VOID MY_SPIDER_DRAW(VOID)
{
	DrawGraph(IMAGESPIDER.X, IMAGESPIDER.Y, IMAGESPIDER.Handle, TRUE);
}
//ネコを描画する関数
VOID MY_CAT_DRAW(VOID)
{
	DrawGraph(IMAGECAT.X, IMAGECAT.Y, IMAGECAT.Handle, TRUE);
}
//チキンを描画する関数
VOID MY_CHICKEN_DRAW(VOID)
{
	DrawGraph(IMAGECHICKEN.X, IMAGECHICKEN.Y, IMAGECHICKEN.Handle, TRUE);
}
//ボーンを描画する関数
VOID MY_BONE_DRAW(VOID)
{
	DrawGraph(IMAGEBONE.X, IMAGEBONE.Y, IMAGEBONE.Handle, TRUE);
}
//ドラゴンを描画する関数
VOID MY_DRAGON_DRAW(VOID)
{
	DrawGraph(IMAGEDRAGON.X, IMAGEDRAGON.Y, IMAGEDRAGON.Handle, TRUE);
}
//ナイトを描画する関数
VOID MY_KNIGHT_DRAW(VOID)
{
	DrawGraph(IMAGEKNIGHT.X, IMAGEKNIGHT.Y, IMAGEKNIGHT.Handle, TRUE);
}
//ケルベロスを描画する関数
VOID MY_KERBEROS_DRAW(VOID)
{
	DrawGraph(IMAGEKERBEROS.X, IMAGEKERBEROS.Y, IMAGEKERBEROS.Handle, TRUE);
}
//ボスを描画する関数
VOID MY_BOSS_DRAW(VOID)
{
	DrawGraph(IMAGEBOSS.X, IMAGEBOSS.Y, IMAGEBOSS.Handle, TRUE);
}

//画像を読み込む設定をする関数
BOOL MY_GAZOU_LOAD(GAZOU* g, int x, int y, const char* path)
{
	wsprintf(g->FilePath, path);
	g->Handle = LoadGraph(g->FilePath);

	if (g->Handle == -1) { return FALSE; }

	GetGraphSize(g->Handle, &g->Width, &g->Height);
	g->X = x;
	g->Y = y;
	g->c_Width = g->Width / 2;
	g->c_Height = g->Height / 2;

	return TRUE;
}

//マップを分割して読み込む設定をする関数
BOOL MAP_INIT(MAP* m, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char* path)
{
	int ret = 0;
	wsprintf(m->FilePath, path);

	ret = LoadDivGraph(m->FilePath, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, m->Handle);

	if (ret == -1)
	{
		return FALSE;
	}

	for (int count = 0; count < MAP_TATE * MAP_YOKO; count++)
	{
		GetGraphSize(
			m->Handle[cnt],
			&m->Width[cnt],
			&m->Height[cnt]
		);
		m->C_Width[cnt] = m->Width[cnt] / 2;
		m->C_Height[cnt] = m->Height[cnt] / 2;
	}

	m->charaStopFlag_x = FALSE;
	m->charaStopFlag_y = FALSE;

	return TRUE;
}

//##########キャラを分割して読み込む関数############
BOOL MY_CHARA_LOAD_BUNKATSU(CHARA* c, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char* path)
{
	int ret = 0;
	wsprintf(c->FilePath, path);

	ret = LoadDivGraph(c->FilePath, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, c->Handle);

	if (ret == -1) { return FALSE; }

	for (cnt = 0; cnt < MAP_BUN_YOKO_CNT * MAP_BUN_TATE_CNT; cnt++)
	{
		GetGraphSize(
			c->Handle[cnt],
			&c->Width[cnt],
			&c->Height[cnt]
		);

		c->C_Width[cnt] = c->Width[cnt] / 2;
		c->C_Height[cnt] = c->Height[cnt] / 2;
	}
	return TRUE;
}

//背景を読み込む関数
BOOL BACKGROUND_LOAD(GAZOU* g, int x, int y, const char* path)
{
	wsprintf(g->FilePath, path);
	g->Handle = LoadGraph(g->FilePath);
	if (g->Handle == -1)
	{
		return FALSE;
	}
	GetGraphSize(g->Handle, &g->Width, &g->Height);
	g->X = x;
	g->Y = y;

	return TRUE;
}

//プレイヤーを初期化する関数
BOOL MY_INIT_PLAYER(PLAYER* p, CHARA c, int* num, int x, int y, int speed)
{
	for (mot = 0; mot < CHARA_MOTION_NUM; mot++)
	{
		p->Handle[mot] = c.Handle[*(num + mot)];
	}

	p->X = 320;
	p->Y = 320;
	p->Width = c.Width[*(num + 0)];
	p->Height = c.Height[*(num + 0)];
	p->C_Width = c.C_Width[*(num + 0)];
	p->C_Height = c.C_Height[*(num + 0)];

	p->Width = MAP_OneBlock_YOKO_SIZE;
	p->Height = MAP_OneBlock_TATE_SIZE;
	p->C_Width = MAP_OneBlock_YOKO_SIZE / 2;
	p->C_Height = MAP_OneBlock_TATE_SIZE / 2;

	p->NowHandleNum = 6;
	p->NowHandleCnt = 0;
	p->NowHandleCntMAX = 4;

	p->Speed = speed;

	p->MoveDist_x = 320;
	p->MoveDist_y = 320;

	p->Lv = 1;
	p->Keikenti = 0;
	p->ATK = 5;
	p->DEF = 2;
	p->HP = 30;
	p->LvUp_KEIKENTI = 5;
	p->Total_Keikenti = 0;

	p->Mass = CHARA_WEIGHT;
	p->Weight = p->Mass * GRAVITY;

	p->CanMoveLeft = TRUE;
	p->CanMoveRight = TRUE;
	p->CanMoveUp = TRUE;
	p->CanMoveDown = TRUE;

	p->atariX = 4;
	p->atariY = 0;
	p->atariWidth = 25;
	p->atariHeight = 32;

	//MY_SET_PLAYER_ATARI(p);

	return TRUE;
}

VOID SLIME_INIT(SLIME* sl)
{
	sl->Get_Keikenti = 5;
	sl->ATK = 2;
	sl->DEF = 2;
	sl->HP = 30;

}
VOID TREE_INIT(TREE* tr)
{
	tr->Get_Keikenti = 6;
	tr->ATK = 2;
	tr->DEF = 3;
	tr->HP = 10;

}

VOID BEETLE_INIT(BEETLE* be)
{
	be->Get_Keikenti = 7;
	be->ATK = 5;
	be->DEF = 0;
	be->HP = 6;

}

VOID LIZARD_INIT(LIZARD* li)
{
	li->Get_Keikenti = 12;
	li->ATK = 8;
	li->DEF = 4;
	li->HP = 23;

}
VOID SCORPION_INIT(SCORPION* scor)
{
	scor->Get_Keikenti = 20;
	scor->ATK = 8;
	scor->DEF = 20;
	scor->HP = 4;

}

VOID SPIDER_INIT(SPIDER* spid)
{
	spid->Get_Keikenti = 18;
	spid->ATK = 10;
	spid->DEF = 2;
	spid->HP = 25;

}

VOID CAT_INIT(CAT* ca)
{
	ca->Get_Keikenti = 50;
	ca->ATK = 30;
	ca->DEF = 4;
	ca->HP = 42;

}
VOID CHIKEN_INIT(CHIKEN* ch)
{
	ch->Get_Keikenti = 55;
	ch->ATK = 32;
	ch->DEF = 0;
	ch->HP = 50;

}

VOID BONE_INIT(BONE* bo)
{
	bo->Get_Keikenti = 48;
	bo->ATK = 20;
	bo->DEF = 21;
	bo->HP = 30;

}

VOID DRAGON_INIT(DRAGON* drago)
{
	drago->Get_Keikenti = 250;
	drago->ATK = 50;
	drago->DEF = 32;
	drago->HP = 100;

}
VOID KERBEROS_INIT(KERBEROS* kerb)
{
	kerb->Get_Keikenti = 232;
	kerb->ATK = 44;
	kerb->DEF = 42;
	kerb->HP = 104;


}

VOID KNIGHT_INIT(KNIGHT* knig)
{
	knig->Get_Keikenti = 210;
	knig->ATK = 60;
	knig->DEF = 50;
	knig->HP = 140;


}

VOID BOSS_INIT(BOSS_BATTLE* boba)
{
	boba->Get_Keikenti = 2000;
	boba->ATK = 80;
	boba->DEF = 30;
	boba->HP = 800;


}

//プレイヤーを操作する関数
VOID MY_PLAYER_OPERATION(VOID)
{
	BOOL IsKeyDown = FALSE;

	BOOL CanMoveLeft = TRUE;//左に行けるか
	BOOL CanMoveRight = TRUE;//右に行けるか
	BOOL CanMoveUp = TRUE;//右に行けるか
	BOOL CanMoveDown = TRUE;//下に行けるか

	//プレイヤーの位置がマップ配列のどこにいるか変換
	int PlayerToMapNumY;
	//プレイヤーの【移動した位置】がマップ配列のどこにいるか変換	※プレイヤーの位置は、スクロール時、変わらないため
	//キャラの位置を、１マップの半分の位置にする
	int PlayerToMapNumX;

	if (AllKeyState[KEY_INPUT_RIGHT] == 0 && AllKeyState[KEY_INPUT_UP] == 0 && AllKeyState[KEY_INPUT_DOWN] == 0)
	{
		if (AllKeyState[KEY_INPUT_LEFT] != 0 /*|| (AllKeyState[KEY_INPUT_LEFT] != 0 && (AllKeyState[KEY_INPUT_RIGHT] != 0 || AllKeyState[KEY_INPUT_UP] != 0 || AllKeyState[KEY_INPUT_DOWN] != 0))*/)
		{
			IsKeyDown = TRUE;
			if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
			{
				Myplayer.NowHandleCnt++;
			}
			else
			{
				Myplayer.NowHandleCnt = 0;

				if (Myplayer.NowHandleNum >= 3 && Myplayer.NowHandleNum < 5)
				{
					Myplayer.NowHandleNum++;
				}
				else
				{
					Myplayer.NowHandleNum = 3;
				}
			}
			//左方向に、まだ動ける
			Myplayer.CanMoveLeft = TRUE;

			MY_SET_PLAYER_ATARI(&Myplayer);
			Myplayer.atariRect.left -= 4;

			if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_LeftNG) == TRUE)
			{
				Myplayer.CanMoveLeft = FALSE;
			}

			if (Myplayer.CanMoveLeft == TRUE)//左に移動できるとき
			{
				if (MapImage.charaStopFlag_x == FALSE)
				{
					if (Myplayer.X > 0)
					{
						Myplayer.X -= Myplayer.Speed;//プレイヤーを左に移動
					}
				}

				if (Myplayer.MoveDist_x > 0)
				{
					Myplayer.MoveDist_x -= Myplayer.Speed;//動いた距離を計算
				}
			}
			random = rand() % RANDOM_NUM;
		}
	}

	if (AllKeyState[KEY_INPUT_DOWN] == 0 && AllKeyState[KEY_INPUT_LEFT] == 0 && AllKeyState[KEY_INPUT_UP] == 0)
	{
		if (AllKeyState[KEY_INPUT_RIGHT] != 0)
		{

			IsKeyDown = TRUE;

			if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
			{
				Myplayer.NowHandleCnt++;
			}
			else
			{
				Myplayer.NowHandleCnt = 0;

				if (Myplayer.NowHandleNum >= 6 && Myplayer.NowHandleNum < 8)
				{
					Myplayer.NowHandleNum++;
				}
				else
				{
					Myplayer.NowHandleNum = 6;
				}
			}
			Myplayer.CanMoveRight = TRUE;

			MY_SET_PLAYER_ATARI(&Myplayer);
			Myplayer.atariRect.right += 4;

			if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_RightNG) == TRUE)
			{
				Myplayer.CanMoveRight = FALSE;
			}

			if (Myplayer.CanMoveRight == TRUE)//右に移動できるとき
			{
				if (MapImage.charaStopFlag_x == FALSE)
				{
					if (Myplayer.X + Myplayer.Width < GAME_WIDTH)
					{
						Myplayer.X += Myplayer.Speed;//プレイヤーを右に移動

					}
				}
				if (Myplayer.MoveDist_x < MAP_OneBlock_YOKO_SIZE * MAP_YOKO)
				{
					Myplayer.MoveDist_x += Myplayer.Speed;//動いた距離を計算
				}
			}
			random = rand() % RANDOM_NUM;
		}
	}

	if (AllKeyState[KEY_INPUT_RIGHT] == 0 && AllKeyState[KEY_INPUT_LEFT] == 0 && AllKeyState[KEY_INPUT_DOWN] == 0)
	{
		if (AllKeyState[KEY_INPUT_UP] != 0)
		{

			IsKeyDown = TRUE;

			if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
			{
				Myplayer.NowHandleCnt++;
			}
			else
			{
				Myplayer.NowHandleCnt = 0;

				if (Myplayer.NowHandleNum >= 9 && Myplayer.NowHandleNum < 11)
				{
					Myplayer.NowHandleNum++;
				}
				else
				{
					Myplayer.NowHandleNum = 9;
				}
			}
			Myplayer.CanMoveUp = TRUE;

			MY_SET_PLAYER_ATARI(&Myplayer);
			Myplayer.atariRect.top -= 4;

			if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_UpNG) == TRUE)
			{
				Myplayer.CanMoveUp = FALSE;
			}

			if (Myplayer.CanMoveUp == TRUE)//上に移動できるとき
			{
				if (MapImage.charaStopFlag_y == FALSE)
				{
					if (Myplayer.Y + Myplayer.Width < GAME_WIDTH)
					{
						Myplayer.Y -= Myplayer.Speed;//プレイヤーを上に移動


					}
				}
				Myplayer.MoveDist_y += Myplayer.Speed;//動いた距離を計算	
			}
			random = rand() % RANDOM_NUM;
		}
	}

	if (AllKeyState[KEY_INPUT_RIGHT] == 0 && AllKeyState[KEY_INPUT_LEFT] == 0 && AllKeyState[KEY_INPUT_UP] == 0)
	{
		if (AllKeyState[KEY_INPUT_DOWN] != 0)
		{
			IsKeyDown = TRUE;

			if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
			{
				Myplayer.NowHandleCnt++;
			}
			else
			{
				Myplayer.NowHandleCnt = 0;

				if (Myplayer.NowHandleNum >= 0 && Myplayer.NowHandleNum < 2)
				{
					Myplayer.NowHandleNum++;
				}
				else
				{
					Myplayer.NowHandleNum = 0;
				}
			}
			Myplayer.CanMoveDown = TRUE;

			MY_SET_PLAYER_ATARI(&Myplayer);
			Myplayer.atariRect.bottom += 4;

			if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_DownNG) == TRUE)
			{
				Myplayer.CanMoveDown = FALSE;
			}

			if (Myplayer.CanMoveDown == TRUE)//下に移動できるとき
			{
				if (MapImage.charaStopFlag_y == FALSE)
				{
					if (Myplayer.Y + Myplayer.Height < GAME_HEIGHT)
					{
						Myplayer.Y += Myplayer.Speed;//プレイヤーを下に移動
					}
				}
				Myplayer.MoveDist_y -= Myplayer.Speed;//動いた距離を計算	
			}
			random = rand() % RANDOM_NUM;
		}
	}
	//マップの左側にいるときは、プレイヤーを動かす
	if (Myplayer.MoveDist_x > 0 &&
		Myplayer.MoveDist_x <= MAP_OneBlock_YOKO_SIZE * 10)
	{
		MapImage.charaStopFlag_x = FALSE;
	}

	//マップの上側にいるときは、プレイヤーを動かす
	if (Myplayer.MoveDist_y > 0 &&
		Myplayer.MoveDist_y <= MAP_OneBlock_YOKO_SIZE * 10)
	{
		MapImage.charaStopFlag_y = FALSE;
	}

	//マップ真ん中らへんにいるときは、マップを動かす
	if (Myplayer.MoveDist_x > MAP_OneBlock_YOKO_SIZE * 10 &&
		Myplayer.MoveDist_x <= MAP_OneBlock_YOKO_SIZE * 53)
	{
		MapImage.charaStopFlag_x = TRUE;

	}
	//マップ真ん中らへんにいるときは、マップを動かす
	if (Myplayer.MoveDist_y > MAP_OneBlock_TATE_SIZE * 10 &&
		Myplayer.MoveDist_y <= MAP_OneBlock_TATE_SIZE * 63)
	{
		MapImage.charaStopFlag_y = TRUE;
	}

	//マップの下側にいるときは、プレイヤーを動かす
	if (Myplayer.MoveDist_y > MAP_OneBlock_TATE_SIZE * 63 &&
		Myplayer.MoveDist_y <= MAP_OneBlock_TATE_SIZE * MAP_TATE)
	{
		MapImage.charaStopFlag_y = FALSE;
	}

	//マップの右側にいるときは、プレイヤーを動かす
	if (Myplayer.MoveDist_x > MAP_OneBlock_YOKO_SIZE * 53 &&
		Myplayer.MoveDist_x <= MAP_OneBlock_YOKO_SIZE * MAP_YOKO)
	{
		MapImage.charaStopFlag_x = FALSE;
	}

	//キーが押されていないとき
	if (IsKeyDown == FALSE)
	{
		if (Myplayer.NowHandleNum >= 6 && Myplayer.NowHandleNum <= 8)
		{
			Myplayer.NowHandleNum = 6;
		}
		else if (Myplayer.NowHandleNum >= 3 && Myplayer.NowHandleNum <= 5)
		{
			Myplayer.NowHandleNum = 3;
		}
		Myplayer.NowHandleCnt = Myplayer.NowHandleCntMAX - 1;	//すぐ画像を変えられるようにする
	}

	//マップの当たり判定もスクロールさせる
	for (tate = 0; tate < MAP_TATE; tate++)
	{
		for (yoko = 0; yoko < MAP_YOKO; yoko++)
		{
			rectMap_DownNG[tate][yoko].left = rectMap_DownNG_First[tate][yoko].left - ScrollCntYoko;
			rectMap_DownNG[tate][yoko].right = rectMap_DownNG_First[tate][yoko].right - ScrollCntYoko;

			rectMap_DownOK[tate][yoko].left = rectMap_DownOK_First[tate][yoko].left - ScrollCntYoko;
			rectMap_DownOK[tate][yoko].right = rectMap_DownOK_First[tate][yoko].right - ScrollCntYoko;

			rectMap_LeftNG[tate][yoko].left = rectMap_LeftNG_First[tate][yoko].left - ScrollCntYoko;
			rectMap_LeftNG[tate][yoko].right = rectMap_LeftNG_First[tate][yoko].right - ScrollCntYoko;

			rectMap_RightNG[tate][yoko].left = rectMap_RightNG_First[tate][yoko].left - ScrollCntYoko;
			rectMap_RightNG[tate][yoko].right = rectMap_RightNG_First[tate][yoko].right - ScrollCntYoko;

			rectMap_UpNG[tate][yoko].left = rectMap_UpNG_First[tate][yoko].left - ScrollCntYoko;
			rectMap_UpNG[tate][yoko].right = rectMap_UpNG_First[tate][yoko].right - ScrollCntYoko;

			rectMap_DownNG[tate][yoko].top = rectMap_DownNG_First[tate][yoko].top - ScrollCntTate;
			rectMap_DownNG[tate][yoko].bottom = rectMap_DownNG_First[tate][yoko].bottom - ScrollCntTate;

			rectMap_DownOK[tate][yoko].top = rectMap_DownOK_First[tate][yoko].top - ScrollCntTate;
			rectMap_DownOK[tate][yoko].bottom = rectMap_DownOK_First[tate][yoko].bottom - ScrollCntTate;

			rectMap_LeftNG[tate][yoko].top = rectMap_LeftNG_First[tate][yoko].top - ScrollCntTate;
			rectMap_LeftNG[tate][yoko].bottom = rectMap_LeftNG_First[tate][yoko].bottom - ScrollCntTate;

			rectMap_RightNG[tate][yoko].top = rectMap_RightNG_First[tate][yoko].top - ScrollCntTate;
			rectMap_RightNG[tate][yoko].bottom = rectMap_RightNG_First[tate][yoko].bottom - ScrollCntTate;

			rectMap_UpNG[tate][yoko].top = rectMap_UpNG_First[tate][yoko].top - ScrollCntTate;
			rectMap_UpNG[tate][yoko].bottom = rectMap_UpNG_First[tate][yoko].bottom - ScrollCntTate;

			rectMap_Sougen[tate][yoko].left = rectMap_Sougen_First[tate][yoko].left - ScrollCntYoko;
			rectMap_Sougen[tate][yoko].right = rectMap_Sougen_First[tate][yoko].right - ScrollCntYoko;

			rectMap_Sougen[tate][yoko].top = rectMap_Sougen_First[tate][yoko].top - ScrollCntTate;
			rectMap_Sougen[tate][yoko].bottom = rectMap_Sougen_First[tate][yoko].bottom - ScrollCntTate;

			rectMap_Sunaba[tate][yoko].left = rectMap_Sunaba_First[tate][yoko].left - ScrollCntYoko;
			rectMap_Sunaba[tate][yoko].right = rectMap_Sunaba_First[tate][yoko].right - ScrollCntYoko;

			rectMap_Sunaba[tate][yoko].top = rectMap_Sunaba_First[tate][yoko].top - ScrollCntTate;
			rectMap_Sunaba[tate][yoko].bottom = rectMap_Sunaba_First[tate][yoko].bottom - ScrollCntTate;

			rectMap_Numa[tate][yoko].left = rectMap_Numa_First[tate][yoko].left - ScrollCntYoko;
			rectMap_Numa[tate][yoko].right = rectMap_Numa_First[tate][yoko].right - ScrollCntYoko;

			rectMap_Numa[tate][yoko].top = rectMap_Numa_First[tate][yoko].top - ScrollCntTate;
			rectMap_Numa[tate][yoko].bottom = rectMap_Numa_First[tate][yoko].bottom - ScrollCntTate;

			rectMap_Last_Stage[tate][yoko].left = rectMap_Last_Stage_First[tate][yoko].left - ScrollCntYoko;
			rectMap_Last_Stage[tate][yoko].right = rectMap_Last_Stage_First[tate][yoko].right - ScrollCntYoko;

			rectMap_Last_Stage[tate][yoko].top = rectMap_Last_Stage_First[tate][yoko].top - ScrollCntTate;
			rectMap_Last_Stage[tate][yoko].bottom = rectMap_Last_Stage_First[tate][yoko].bottom - ScrollCntTate;

			rectMap_Boss[tate][yoko].left = rectMap_Boss_First[tate][yoko].left - ScrollCntYoko;
			rectMap_Boss[tate][yoko].right = rectMap_Boss_First[tate][yoko].right - ScrollCntYoko;

			rectMap_Boss[tate][yoko].top = rectMap_Boss_First[tate][yoko].top - ScrollCntTate;
			rectMap_Boss[tate][yoko].bottom = rectMap_Boss_First[tate][yoko].bottom - ScrollCntTate;

		}
	}
	return;
	//}
}

//プレイヤーを表示する関数
VOID MY_PLAY_PLAYER_DRAW(VOID)
{
	DrawExtendGraph(
		Myplayer.X,
		Myplayer.Y,
		Myplayer.X + Myplayer.Width,
		Myplayer.Y + Myplayer.Height,
		Myplayer.Handle[Myplayer.NowHandleNum], TRUE);

	return;
}

//マップを表示する関数
VOID MY_PLAY_MAP_DRAW(VOID)
{
	for (tate = 0; tate < MAP_TATE; tate++)
	{
		for (yoko = 0; yoko < MAP_YOKO; yoko++)
		{
			if ((yoko + 1) * MAP_OneBlock_YOKO_SIZE - ScrollCntYoko >= 0 &&
				(yoko + 0) * MAP_OneBlock_YOKO_SIZE - ScrollCntYoko <= GAME_WIDTH)
			{
				DrawGraph(
					yoko * MAP_OneBlock_YOKO_SIZE - ScrollCntYoko,
					tate * MAP_OneBlock_TATE_SIZE - ScrollCntTate,
					MapImage.Handle[MapData[tate][yoko]], TRUE);
			}
		}
	}
}

//ゲーム画面のスクロールを行う関数
VOID MY_PLAY_SCROLL(VOID)
{
	ScrollCntYoko += ScrollDistPlusYoko;
	ScrollCntTate += ScrollDistPlusYoko;
	DrawFormatString(0, 20, GetColor(255, 255, 255), "スクロールした量(横):%06d", ScrollCntYoko);

	return;
}

//ゲームマップのCSVを読み込む関数
BOOL MY_MAP_READ_CSV_NUM(FILE* fp, const char* path)
{
	if ((fp = fopen(path, "r")) == NULL)
	{
		return FALSE;
	}

	int result = 0;
	int LoopCnt = 0;
	while (result != EOF)
	{
		result = fscanf(fp, "%d,", &MapData[LoopCnt / MAP_YOKO][LoopCnt % MAP_YOKO]);

		MapData_Init[LoopCnt / MAP_YOKO][LoopCnt % MAP_YOKO] = MapData[LoopCnt / MAP_YOKO][LoopCnt % MAP_YOKO];//値をコピー

		LoopCnt++;
	}

	fclose(fp);

	int cnt;

	for (tate = 0; tate < MAP_TATE; tate++)
	{
		for (yoko = 0; yoko < MAP_YOKO; yoko++)
		{
			for (cnt = 0; cnt < MAP_NOTDOWN_KIND; cnt++)
			{
				if (MapData[tate][yoko] == MapNotDownKind[cnt])
				{
					rectMap_DownNG[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_DownNG[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_DownNG[tate][yoko].right = (yoko + 1) * MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_DownNG[tate][yoko].bottom = (tate + 1) * MAP_OneBlock_TATE_SIZE - 1;

					rectMap_DownNG_First[tate][yoko] = rectMap_DownNG[tate][yoko];
				}
			}

			for (cnt = 0; cnt < MAP_OKDOWN_KIND; cnt++)
			{
				if (MapData[tate][yoko] == MapOKDownKind[cnt])
				{
					rectMap_DownOK[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_DownOK[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_DownOK[tate][yoko].right = (yoko + 1) * MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_DownOK[tate][yoko].bottom = (tate + 1) * MAP_OneBlock_TATE_SIZE - 1;

					rectMap_DownOK_First[tate][yoko] = rectMap_DownOK[tate][yoko];
				}
			}

			for (cnt = 0; cnt < MAP_NOTLEFT_KIND; cnt++)
			{
				if (MapData[tate][yoko] == MapNotLeftKind[cnt])
				{
					rectMap_LeftNG[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_LeftNG[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_LeftNG[tate][yoko].right = (yoko + 1) * MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_LeftNG[tate][yoko].bottom = (tate + 1) * MAP_OneBlock_TATE_SIZE - 1;

					rectMap_LeftNG_First[tate][yoko] = rectMap_LeftNG[tate][yoko];
				}
			}

			for (cnt = 0; cnt < MAP_SOUGEN; cnt++)
			{
				if (MapData[tate][yoko] == Sougen[cnt])
				{
					rectMap_Sougen[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_Sougen[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_Sougen[tate][yoko].right = (yoko + 1) * MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_Sougen[tate][yoko].bottom = (tate + 1) * MAP_OneBlock_TATE_SIZE - 1;

					rectMap_Sougen_First[tate][yoko] = rectMap_Sougen[tate][yoko];
				}
			}

			for (cnt = 0; cnt < MAP_SUNABA; cnt++)
			{
				if (MapData[tate][yoko] == Sunaba[cnt])
				{
					rectMap_Sunaba[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_Sunaba[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_Sunaba[tate][yoko].right = (yoko + 1) * MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_Sunaba[tate][yoko].bottom = (tate + 1) * MAP_OneBlock_TATE_SIZE - 1;

					rectMap_Sunaba_First[tate][yoko] = rectMap_Sunaba[tate][yoko];
				}
			}

			for (cnt = 0; cnt < MAP_NUMA; cnt++)
			{
				if (MapData[tate][yoko] == Numa[cnt])
				{
					rectMap_Numa[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_Numa[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_Numa[tate][yoko].right = (yoko + 1) * MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_Numa[tate][yoko].bottom = (tate + 1) * MAP_OneBlock_TATE_SIZE - 1;

					rectMap_Numa_First[tate][yoko] = rectMap_Numa[tate][yoko];
				}
			}

			for (cnt = 0; cnt < MAP_LAST_STAGE; cnt++)
			{
				if (MapData[tate][yoko] == Last_Stage[cnt])
				{
					rectMap_Last_Stage[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_Last_Stage[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_Last_Stage[tate][yoko].right = (yoko + 1) * MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_Last_Stage[tate][yoko].bottom = (tate + 1) * MAP_OneBlock_TATE_SIZE - 1;

					rectMap_Last_Stage_First[tate][yoko] = rectMap_Last_Stage[tate][yoko];
				}
			}

			for (cnt = 0; cnt < BOSS_STAGE; cnt++)
			{
				if (MapData[tate][yoko] == Castle[cnt])
				{
					rectMap_Boss[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_Boss[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_Boss[tate][yoko].right = (yoko + 1) * MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_Boss[tate][yoko].bottom = (tate + 1) * MAP_OneBlock_TATE_SIZE - 1;

					rectMap_Boss_First[tate][yoko] = rectMap_Boss[tate][yoko];
				}
			}

			for (cnt = 0; cnt < MAP_NOTRIGHT_KIND; cnt++)
			{
				if (MapData[tate][yoko] == MapNotRightKind[cnt])
				{
					rectMap_RightNG[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_RightNG[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_RightNG[tate][yoko].right = (yoko + 1) * MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_RightNG[tate][yoko].bottom = (tate + 1) * MAP_OneBlock_TATE_SIZE - 1;

					rectMap_RightNG_First[tate][yoko] = rectMap_RightNG[tate][yoko];
				}
			}
			for (cnt = 0; cnt < MAP_NOTUP_KIND; cnt++)
			{
				if (MapData[tate][yoko] == MapNotUpKind[cnt])
				{
					rectMap_RightNG[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_RightNG[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_RightNG[tate][yoko].right = (yoko + 1) * MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_RightNG[tate][yoko].bottom = (tate + 1) * MAP_OneBlock_TATE_SIZE - 1;

					rectMap_RightNG_First[tate][yoko] = rectMap_RightNG[tate][yoko];
				}
			}
			for (cnt = 0; cnt < MAP_NOTUP_KIND; cnt++)
			{
				if (MapData[tate][yoko] == MapNotUpKind[cnt])
				{
					rectMap_UpNG[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_UpNG[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_UpNG[tate][yoko].right = (yoko + 1) * MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_UpNG[tate][yoko].bottom = (tate + 1) * MAP_OneBlock_TATE_SIZE - 1;

					rectMap_UpNG_First[tate][yoko] = rectMap_UpNG[tate][yoko];
				}
			}
		}
	}
	return TRUE;
}
//プレイヤーの当たり判定の領域を設定する関数
VOID MY_SET_PLAYER_ATARI(PLAYER* p)
{
	p->atariRect.left = p->X + p->atariX + 1;
	p->atariRect.top = p->Y + p->atariY + 1;
	p->atariRect.right = p->X + p->atariX + p->atariWidth - 1;
	p->atariRect.bottom = p->Y + p->atariY + p->atariHeight - 1;

	return;
}

//##########両機のあたり判定をする関数##########
BOOL MY_CHECK_RECT_ATARI(RECT a, RECT b)
{
	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top)
	{
		return TRUE;
	}

	return FALSE;
}

VOID BATTLE_SLIME_FLOW(VOID)
{
	if (Myplayer.HP > 0 && sli.HP > 0)
	{
		turn = Totalturn % 2;
		if (turn == 0 && AllKeyState[KEY_INPUT_A] != 0)
		{
			battle_random = rand() % 3;
			if (Myplayer.ATK > sli.DEF)
			{
				ENEMY_ATC_CHECK = FALSE;
				ENEMY_ATC_CHECK_DEF = FALSE;
				player_ATC_CHECK = TRUE;
				sli.HP -= Myplayer.ATK - sli.DEF + battle_random;

			}
			else
			{
				ENEMY_ATC_CHECK = FALSE;
				ENEMY_ATC_CHECK_DEF = FALSE;
				player_ATC_CHECK_DEF = TRUE;
				sli.HP -= battle_random;
			}
			Totalturn++;
		}

		if (turn == 1 && AllKeyState[KEY_INPUT_RETURN] == 1)
		{
			battle_random = rand() % 3;
			if (sli.ATK > Myplayer.DEF)
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK = TRUE;
				Myplayer.HP -= sli.ATK - Myplayer.DEF + battle_random;
			}
			else
			{

				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK_DEF = TRUE;
				Myplayer.HP -= battle_random;
			}
			Totalturn++;
		}
	}
	else if (sli.HP <= 0)
	{
		Myplayer.Keikenti += sli.Get_Keikenti;
		Myplayer.Total_Keikenti += sli.Get_Keikenti;
		player_ATC_CHECK = FALSE;
		player_ATC_CHECK_DEF = FALSE;

		if (Myplayer.LvUp_KEIKENTI <= Myplayer.Keikenti)
		{
			Myplayer.Lv += 1;
			Myplayer.ATK += 2;
			Myplayer.DEF += 2;
			Myplayer.HP += 3;
			Myplayer.Keikenti = 0;
			Myplayer.LvUp_KEIKENTI = Myplayer.LvUp_KEIKENTI * 2;
		}

		GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
		random = 0;
		Totalturn = 0;
		turn = 0;
	}
	else if (Myplayer.HP <= 0)
	{
		ENEMY_ATC_CHECK = FALSE;
		ENEMY_ATC_CHECK_DEF = FALSE;
		random = 0;
		Totalturn = 0;
		turn = 0;
		GameSceneNow = (int)GAME_SCENE_OVER;
	}
}

VOID BATTLE_TREE_FLOW(VOID)
{
	if (Myplayer.HP > 0 && tre.HP > 0)
	{
		turn = Totalturn % 2;
		if (turn == 0 && AllKeyState[KEY_INPUT_A] == 1)
		{
			battle_random = rand() % 3;
			if (Myplayer.ATK > tre.DEF)
			{
				tre.HP -= Myplayer.ATK - tre.DEF + battle_random;
			}
			else
			{
				tre.HP -= battle_random;
			}
			Totalturn++;
		}

		if (turn == 1 && AllKeyState[KEY_INPUT_RETURN] == 1)
		{
			battle_random = rand() % 3;
			if (tre.ATK > Myplayer.DEF)
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK = TRUE;
				Myplayer.HP -= tre.ATK - Myplayer.DEF + battle_random;
			}
			else
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK_DEF = TRUE;
				Myplayer.HP -= battle_random;
			}
			Totalturn++;
		}
	}
	else if (tre.HP <= 0)
	{
		Myplayer.Keikenti += tre.Get_Keikenti;
		Myplayer.Total_Keikenti += tre.Get_Keikenti;
		player_ATC_CHECK = FALSE;
		player_ATC_CHECK_DEF = FALSE;

		if (Myplayer.LvUp_KEIKENTI <= Myplayer.Keikenti)
		{
			Myplayer.Lv += 1;
			Myplayer.ATK += 2;
			Myplayer.DEF += 2;
			Myplayer.HP += 3;
			Myplayer.Keikenti = 0;

			Myplayer.LvUp_KEIKENTI = Myplayer.LvUp_KEIKENTI * 2;
		}
		GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
		random = 0;
		Totalturn = 0;
		turn = 0;
	}
	else if (Myplayer.HP <= 0)
	{
		ENEMY_ATC_CHECK = FALSE;
		ENEMY_ATC_CHECK_DEF = FALSE;
		random = 0;
		Totalturn = 0;
		turn = 0;
		GameSceneNow = (int)GAME_SCENE_OVER;
	}
}

VOID BATTLE_BEETLE_FLOW(VOID)
{
	if (Myplayer.HP > 0 && bee.HP > 0)
	{
		turn = Totalturn % 2;
		if (turn == 0 && AllKeyState[KEY_INPUT_A] == 1)
		{
			battle_random = rand() % 3;
			if (Myplayer.ATK > bee.DEF)
			{
				bee.HP -= Myplayer.ATK - bee.DEF + battle_random;
			}
			else
			{
				bee.HP -= battle_random;
			}
			Totalturn++;
		}

		if (turn == 1 && AllKeyState[KEY_INPUT_RETURN] == 1)
		{
			battle_random = rand() % 3;
			if (bee.ATK > Myplayer.DEF)
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK = TRUE;
				Myplayer.HP -= bee.ATK - Myplayer.DEF + battle_random;
			}
			else
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK_DEF = TRUE;
				Myplayer.HP -= battle_random;
			}
			Totalturn++;
		}
	}
	else if (bee.HP <= 0)
	{
		player_ATC_CHECK = FALSE;
		player_ATC_CHECK_DEF = FALSE;

		Myplayer.Keikenti += bee.Get_Keikenti;
		Myplayer.Total_Keikenti += bee.Get_Keikenti;

		if (Myplayer.LvUp_KEIKENTI <= Myplayer.Keikenti)
		{
			Myplayer.Lv += 1;
			Myplayer.ATK += 2;
			Myplayer.DEF += 2;
			Myplayer.HP += 3;
			Myplayer.Keikenti = 0;

			Myplayer.LvUp_KEIKENTI = Myplayer.LvUp_KEIKENTI * 2;
		}
		GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
		random = 0;
		Totalturn = 0;
		turn = 0;
	}
	else if (Myplayer.HP <= 0)
	{
		ENEMY_ATC_CHECK = FALSE;
		ENEMY_ATC_CHECK_DEF = FALSE;
		random = 0;
		Totalturn = 0;
		turn = 0;
		GameSceneNow = (int)GAME_SCENE_OVER;
	}
}

VOID BATTLE_LIZARD_FLOW(VOID)
{
	if (Myplayer.HP > 0 && liz.HP > 0)
	{
		turn = Totalturn % 2;
		if (turn == 0 && AllKeyState[KEY_INPUT_A] == 1)
		{
			battle_random = rand() % 3;
			if (Myplayer.ATK > liz.DEF)
			{
				liz.HP -= Myplayer.ATK - liz.DEF + battle_random;
			}
			else
			{
				liz.HP -= battle_random;
			}
			Totalturn++;
		}

		if (turn == 1 && AllKeyState[KEY_INPUT_RETURN] == 1)
		{
			battle_random = rand() % 3;
			if (liz.ATK > Myplayer.DEF)
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK = TRUE;
				Myplayer.HP -= liz.ATK - Myplayer.DEF + battle_random;
			}
			else
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK_DEF = TRUE;
				Myplayer.HP -= battle_random;
			}
			Totalturn++;
		}
	}
	else if (liz.HP <= 0)
	{
		player_ATC_CHECK = FALSE;
		player_ATC_CHECK_DEF = FALSE;
		Myplayer.Keikenti += liz.Get_Keikenti;
		Myplayer.Total_Keikenti += liz.Get_Keikenti;

		if (Myplayer.LvUp_KEIKENTI <= Myplayer.Keikenti)
		{
			Myplayer.Lv += 1;
			Myplayer.ATK += 2;
			Myplayer.DEF += 2;
			Myplayer.HP += 3;
			Myplayer.Keikenti = 0;

			Myplayer.LvUp_KEIKENTI = Myplayer.LvUp_KEIKENTI * 2;
		}
		GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
		random = 0;
		Totalturn = 0;
		turn = 0;
	}
	else if (Myplayer.HP <= 0)
	{
		ENEMY_ATC_CHECK = FALSE;
		ENEMY_ATC_CHECK_DEF = FALSE;
		random = 0;
		Totalturn = 0;
		turn = 0;
		GameSceneNow = (int)GAME_SCENE_OVER;
	}
}

VOID BATTLE_SCORPION_FLOW(VOID)
{
	if (Myplayer.HP > 0 && sco.HP > 0)
	{
		turn = Totalturn % 2;
		if (turn == 0 && AllKeyState[KEY_INPUT_A] == 1)
		{
			battle_random = rand() % 3;
			if (Myplayer.ATK > sco.DEF)
			{
				sco.HP -= Myplayer.ATK - sco.DEF + battle_random;
			}
			else
			{
				sco.HP -= battle_random;
			}
			Totalturn++;
		}

		if (turn == 1 && AllKeyState[KEY_INPUT_RETURN] == 1)
		{
			battle_random = rand() % 3;
			if (sco.ATK > Myplayer.DEF)
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK = TRUE;
				Myplayer.HP -= sco.ATK - Myplayer.DEF + battle_random;
			}
			else
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK_DEF = TRUE;
				Myplayer.HP -= battle_random;
			}
			Totalturn++;
		}
	}
	else if (sco.HP <= 0)
	{
		player_ATC_CHECK = FALSE;
		player_ATC_CHECK_DEF = FALSE;
		Myplayer.Keikenti += sco.Get_Keikenti;
		Myplayer.Total_Keikenti += sco.Get_Keikenti;

		if (Myplayer.LvUp_KEIKENTI <= Myplayer.Keikenti)
		{
			Myplayer.Lv += 1;
			Myplayer.ATK += 2;
			Myplayer.DEF += 2;
			Myplayer.HP += 3;
			Myplayer.Keikenti = 0;

			Myplayer.LvUp_KEIKENTI = Myplayer.LvUp_KEIKENTI * 2;
		}
		GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
		random = 0;
		Totalturn = 0;
		turn = 0;
	}
	else if (Myplayer.HP <= 0)
	{
		ENEMY_ATC_CHECK = FALSE;
		ENEMY_ATC_CHECK_DEF = FALSE;
		random = 0;
		Totalturn = 0;
		turn = 0;
		GameSceneNow = (int)GAME_SCENE_OVER;
	}
}

VOID BATTLE_SPIDER_FLOW(VOID)
{
	if (Myplayer.HP > 0 && spi.HP > 0)
	{
		turn = Totalturn % 2;
		if (turn == 0 && AllKeyState[KEY_INPUT_A] == 1)
		{
			battle_random = rand() % 3;
			if (Myplayer.ATK > spi.DEF)
			{
				spi.HP -= Myplayer.ATK - spi.DEF + battle_random;
			}
			else
			{
				spi.HP -= battle_random;
			}
			Totalturn++;
		}

		if (turn == 1 && AllKeyState[KEY_INPUT_RETURN] == 1)
		{
			battle_random = rand() % 3;
			if (spi.ATK > Myplayer.DEF)
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK = TRUE;
				Myplayer.HP -= spi.ATK - Myplayer.DEF + battle_random;
			}
			else
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK_DEF = TRUE;
				Myplayer.HP -= battle_random;
			}
			Totalturn++;
		}
	}

	else if (spi.HP <= 0)
	{
		player_ATC_CHECK = FALSE;
		player_ATC_CHECK_DEF = FALSE;
		Myplayer.Keikenti += spi.Get_Keikenti;
		Myplayer.Total_Keikenti += spi.Get_Keikenti;

		if (Myplayer.LvUp_KEIKENTI <= Myplayer.Keikenti)
		{
			Myplayer.Lv += 1;
			Myplayer.ATK += 2;
			Myplayer.DEF += 2;
			Myplayer.HP += 3;
			Myplayer.Keikenti = 0;

			Myplayer.LvUp_KEIKENTI = Myplayer.LvUp_KEIKENTI * 2;
		}
		GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
		random = 0;
		Totalturn = 0;
		turn = 0;
	}
	else if (Myplayer.HP <= 0)
	{
		ENEMY_ATC_CHECK = FALSE;
		ENEMY_ATC_CHECK_DEF = FALSE;
		random = 0;
		Totalturn = 0;
		turn = 0;
		GameSceneNow = (int)GAME_SCENE_OVER;
	}
}

VOID BATTLE_CAT_FLOW(VOID)
{
	if (Myplayer.HP > 0 && cat.HP > 0)
	{
		turn = Totalturn % 2;
		if (turn == 0 && AllKeyState[KEY_INPUT_A] == 1)
		{
			battle_random = rand() % 3;
			if (Myplayer.ATK > cat.DEF)
			{
				cat.HP -= Myplayer.ATK - cat.DEF + battle_random;
			}
			else
			{
				cat.HP -= battle_random;
			}
			Totalturn++;
		}

		if (turn == 1 && AllKeyState[KEY_INPUT_RETURN] == 1)
		{
			battle_random = rand() % 3;
			if (cat.ATK > Myplayer.DEF)
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK_DEF = TRUE;
				Myplayer.HP -= cat.ATK - Myplayer.DEF + battle_random;
			}
			else
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK_DEF = TRUE;
				Myplayer.HP -= battle_random;
			}
			Totalturn++;
		}
	}
	else if (cat.HP <= 0)
	{
		player_ATC_CHECK = FALSE;
		player_ATC_CHECK_DEF = FALSE;
		Myplayer.Keikenti += cat.Get_Keikenti;
		Myplayer.Total_Keikenti += cat.Get_Keikenti;

		if (Myplayer.LvUp_KEIKENTI <= Myplayer.Keikenti)
		{
			Myplayer.Lv += 1;
			Myplayer.ATK += 2;
			Myplayer.DEF += 2;
			Myplayer.HP += 3;
			Myplayer.Keikenti = 0;

			Myplayer.LvUp_KEIKENTI = Myplayer.LvUp_KEIKENTI * 2;
		}
		GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
		random = 0;
		Totalturn = 0;
		turn = 0;
	}
	else if (Myplayer.HP <= 0)
	{
		ENEMY_ATC_CHECK = FALSE;
		ENEMY_ATC_CHECK_DEF = FALSE;
		random = 0;
		Totalturn = 0;
		turn = 0;
		GameSceneNow = (int)GAME_SCENE_OVER;
	}
}

VOID BATTLE_CHIKEN_FLOW(VOID)
{
	if (Myplayer.HP > 0 && chi.HP > 0)
	{
		turn = Totalturn % 2;
		if (turn == 0 && AllKeyState[KEY_INPUT_A] == 1)
		{
			battle_random = rand() % 3;
			if (Myplayer.ATK > chi.DEF)
			{
				chi.HP -= Myplayer.ATK - chi.DEF + battle_random;
			}
			else
			{
				chi.HP -= battle_random;
			}
			Totalturn++;
		}

		if (turn == 1 && AllKeyState[KEY_INPUT_RETURN] == 1)
		{
			battle_random = rand() % 3;
			if (chi.ATK > Myplayer.DEF)
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK = TRUE;
				Myplayer.HP -= chi.ATK - Myplayer.DEF + battle_random;
			}
			else
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK_DEF = TRUE;
				Myplayer.HP -= battle_random;
			}
			Totalturn++;
		}
	}
	else if (chi.HP <= 0)
	{
		player_ATC_CHECK = FALSE;
		player_ATC_CHECK_DEF = FALSE;
		Myplayer.Keikenti += chi.Get_Keikenti;
		Myplayer.Total_Keikenti += chi.Get_Keikenti;

		if (Myplayer.LvUp_KEIKENTI <= Myplayer.Keikenti)
		{
			Myplayer.Lv += 1;
			Myplayer.ATK += 2;
			Myplayer.DEF += 2;
			Myplayer.HP += 3;
			Myplayer.Keikenti = 0;

			Myplayer.LvUp_KEIKENTI = Myplayer.LvUp_KEIKENTI * 2;
		}
		GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
		random = 0;
		Totalturn = 0;
		turn = 0;
	}
	else if (Myplayer.HP <= 0)
	{
		ENEMY_ATC_CHECK = FALSE;
		ENEMY_ATC_CHECK_DEF = FALSE;
		random = 0;
		Totalturn = 0;
		turn = 0;
		GameSceneNow = (int)GAME_SCENE_OVER;
	}
}

VOID BATTLE_BONE_FLOW(VOID)
{
	if (Myplayer.HP > 0 && bon.HP > 0)
	{
		turn = Totalturn % 2;
		if (turn == 0 && AllKeyState[KEY_INPUT_A] == 1)
		{
			battle_random = rand() % 3;
			if (Myplayer.ATK > bon.DEF)
			{
				bon.HP -= Myplayer.ATK - bon.DEF + battle_random;
			}
			else
			{
				bon.HP -= battle_random;
			}
			Totalturn++;
		}

		if (turn == 1 && AllKeyState[KEY_INPUT_RETURN] == 1)
		{
			battle_random = rand() % 3;
			if (bon.ATK > Myplayer.DEF)
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK = TRUE;
				Myplayer.HP -= bon.ATK - Myplayer.DEF + battle_random;
			}
			else
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK_DEF = TRUE;
				Myplayer.HP -= battle_random;
			}
			Totalturn++;
		}
	}
	else if (bon.HP <= 0)
	{
		player_ATC_CHECK = FALSE;
		player_ATC_CHECK_DEF = FALSE;
		Myplayer.Keikenti += bon.Get_Keikenti;
		Myplayer.Total_Keikenti += bon.Get_Keikenti;

		if (Myplayer.LvUp_KEIKENTI <= Myplayer.Keikenti)
		{
			Myplayer.Lv += 1;
			Myplayer.ATK += 2;
			Myplayer.DEF += 2;
			Myplayer.HP += 3;
			Myplayer.Keikenti = 0;

			Myplayer.LvUp_KEIKENTI = Myplayer.LvUp_KEIKENTI * 2;
		}
		GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
		random = 0;
		Totalturn = 0;
		turn = 0;
	}
	else if (Myplayer.HP <= 0)
	{
		ENEMY_ATC_CHECK = FALSE;
		ENEMY_ATC_CHECK_DEF = FALSE;
		random = 0;
		Totalturn = 0;
		turn = 0;
		GameSceneNow = (int)GAME_SCENE_OVER;
	}
}

VOID BATTLE_DRAGON_FLOW(VOID)
{
	if (Myplayer.HP > 0 && dra.HP > 0)
	{
		turn = Totalturn % 2;
		if (turn == 0 && AllKeyState[KEY_INPUT_A] == 1)
		{
			battle_random = rand() % 3;
			if (Myplayer.ATK > dra.DEF)
			{
				dra.HP -= Myplayer.ATK - dra.DEF + battle_random;
			}
			else
			{
				dra.HP -= battle_random;
			}
			Totalturn++;
		}

		if (turn == 1 && AllKeyState[KEY_INPUT_RETURN] == 1)
		{
			battle_random = rand() % 3;
			if (dra.ATK > Myplayer.DEF)
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK = TRUE;
				Myplayer.HP -= dra.ATK - Myplayer.DEF + battle_random;
			}
			else
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK_DEF = TRUE;
				Myplayer.HP -= battle_random;
			}
			Totalturn++;
		}
	}
	else if (dra.HP <= 0)
	{
		player_ATC_CHECK = FALSE;
		player_ATC_CHECK_DEF = FALSE;
		Myplayer.Keikenti += dra.Get_Keikenti;
		Myplayer.Total_Keikenti += dra.Get_Keikenti;

		if (Myplayer.LvUp_KEIKENTI <= Myplayer.Keikenti)
		{
			Myplayer.Lv += 1;
			Myplayer.ATK += 2;
			Myplayer.DEF += 2;
			Myplayer.HP += 3;
			Myplayer.Keikenti = 0;

			Myplayer.LvUp_KEIKENTI = Myplayer.LvUp_KEIKENTI * 2;
		}
		GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
		random = 0;
		Totalturn = 0;
		turn = 0;
	}
	else if (Myplayer.HP <= 0)
	{
		ENEMY_ATC_CHECK = FALSE;
		ENEMY_ATC_CHECK_DEF = FALSE;
		random = 0;
		Totalturn = 0;
		turn = 0;
		GameSceneNow = (int)GAME_SCENE_OVER;
	}
}

VOID BATTLE_KERBEROS_FLOW(VOID)
{

	if (Myplayer.HP > 0 && ker.HP > 0)
	{
		turn = Totalturn % 2;
		if (turn == 0 && AllKeyState[KEY_INPUT_A] == 1)
		{
			battle_random = rand() % 3;
			if (Myplayer.ATK > ker.DEF)
			{
				ker.HP -= Myplayer.ATK - ker.DEF + battle_random;
			}
			else
			{
				ker.HP -= battle_random;
			}
			Totalturn++;
		}

		if (turn == 1 && AllKeyState[KEY_INPUT_RETURN] == 1)
		{
			battle_random = rand() % 3;
			if (ker.ATK > Myplayer.DEF)
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK = TRUE;
				Myplayer.HP -= ker.ATK - Myplayer.DEF + battle_random;
			}
			else
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK_DEF = TRUE;
				Myplayer.HP -= battle_random;
			}
			Totalturn++;
		}
	}
	else if (ker.HP <= 0)
	{
		player_ATC_CHECK = FALSE;
		player_ATC_CHECK_DEF = FALSE;
		Myplayer.Keikenti += ker.Get_Keikenti;
		Myplayer.Total_Keikenti += ker.Get_Keikenti;

		if (Myplayer.LvUp_KEIKENTI <= Myplayer.Keikenti)
		{
			Myplayer.Lv += 1;
			Myplayer.ATK += 2;
			Myplayer.DEF += 2;
			Myplayer.HP += 3;
			Myplayer.Keikenti = 0;

			Myplayer.LvUp_KEIKENTI = Myplayer.LvUp_KEIKENTI * 2;
		}
		GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
		random = 0;
		Totalturn = 0;
		turn = 0;
	}
	else if (Myplayer.HP <= 0)
	{
		ENEMY_ATC_CHECK = FALSE;
		ENEMY_ATC_CHECK_DEF = FALSE;
		random = 0;
		Totalturn = 0;
		turn = 0;
		GameSceneNow = (int)GAME_SCENE_OVER;
	}
}

VOID BATTLE_KNIGHT_FLOW(VOID)
{
	if (Myplayer.HP > 0 && kni.HP > 0)
	{
		turn = Totalturn % 2;
		if (turn == 0 && AllKeyState[KEY_INPUT_A] == 1)
		{
			battle_random = rand() % 3;
			if (Myplayer.ATK > kni.DEF)
			{
				kni.HP -= Myplayer.ATK - kni.DEF + battle_random;
			}
			else
			{
				kni.HP -= battle_random;
			}
			Totalturn++;
		}

		if (turn == 1 && AllKeyState[KEY_INPUT_RETURN] == 1)
		{
			battle_random = rand() % 3;
			if (kni.ATK > Myplayer.DEF)
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK = TRUE;
				Myplayer.HP -= kni.ATK - Myplayer.DEF + battle_random;
			}
			else
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK_DEF = TRUE;
				Myplayer.HP -= battle_random;
			}
			Totalturn++;
		}
	}
	else if (kni.HP <= 0)
	{
		player_ATC_CHECK = FALSE;
		player_ATC_CHECK_DEF = FALSE;
		Myplayer.Keikenti += kni.Get_Keikenti;
		Myplayer.Total_Keikenti += kni.Get_Keikenti;

		if (Myplayer.LvUp_KEIKENTI <= Myplayer.Keikenti)
		{
			Myplayer.Lv += 1;
			Myplayer.ATK += 2;
			Myplayer.DEF += 2;
			Myplayer.HP += 3;
			Myplayer.Keikenti = 0;

			Myplayer.LvUp_KEIKENTI = Myplayer.LvUp_KEIKENTI * 2;
		}
		GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
		random = 0;
		Totalturn = 0;
		turn = 0;
	}
	else if (Myplayer.HP <= 0)
	{
		ENEMY_ATC_CHECK = FALSE;
		ENEMY_ATC_CHECK_DEF = FALSE;
		random = 0;
		Totalturn = 0;
		turn = 0;
		GameSceneNow = (int)GAME_SCENE_OVER;
	}
}

VOID BATTLE_BOSS_FLOW(VOID)
{
	if (Myplayer.HP > 0 && bos.HP > 0)
	{
		turn = Totalturn % 2;
		if (turn == 0 && AllKeyState[KEY_INPUT_A] == 1)
		{
			battle_random = rand() % 3;
			if (Myplayer.ATK > bos.DEF)
			{
				bos.HP -= Myplayer.ATK - bos.DEF + battle_random;
			}
			else
			{
				bos.HP -= battle_random;
			}
			Totalturn++;
		}

		if (turn == 1 && AllKeyState[KEY_INPUT_RETURN] == 1)
		{
			battle_random = rand() % 3;
			if (bos.ATK > Myplayer.DEF)
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK = TRUE;
				Myplayer.HP -= bos.ATK - Myplayer.DEF + battle_random;
			}
			else
			{
				player_ATC_CHECK = FALSE;
				player_ATC_CHECK_DEF = FALSE;
				ENEMY_ATC_CHECK_DEF = TRUE;
				Myplayer.HP -= battle_random;
			}
			Totalturn++;
		}
	}
	else if (bos.HP <= 0)
	{
		player_ATC_CHECK = FALSE;
		player_ATC_CHECK_DEF = FALSE;
		Myplayer.Keikenti += bos.Get_Keikenti;
		Myplayer.Total_Keikenti += bon.Get_Keikenti;

		if (Myplayer.LvUp_KEIKENTI <= Myplayer.Keikenti)
		{
			Myplayer.Lv += 1;
			Myplayer.ATK += 2;
			Myplayer.DEF += 2;
			Myplayer.HP += 3;
			Myplayer.Keikenti = 0;

			Myplayer.LvUp_KEIKENTI = Myplayer.LvUp_KEIKENTI * 2;
		}
		GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
		random = 0;
		Totalturn = 0;
		turn = 0;
	}
	else if (Myplayer.HP <= 0)
	{
		ENEMY_ATC_CHECK = FALSE;
		ENEMY_ATC_CHECK_DEF = FALSE;
		random = 0;
		Totalturn = 0;
		turn = 0;
		GameSceneNow = (int)GAME_SCENE_OVER;
	}
}

//プレイヤーとマップの当たり判定をする関数
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP(RECT chara, RECT map[MAP_TATE][MAP_YOKO])
{
	for (tate = 0; tate < MAP_TATE; tate++)
	{
		for (yoko = 0; yoko < MAP_YOKO; yoko++)
		{
			if (MY_CHECK_RECT_ATARI(chara, map[tate][yoko]) == TRUE)
			{
				return TRUE;
			}
		}
	}
	return FALSE;
}

/*  */
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(RECT chara, RECT map[MAP_TATE][MAP_YOKO], int* atariX, int* atariY)
{
	for (tate = 0; tate < MAP_TATE; tate++)
	{
		for (yoko = 0; yoko < MAP_YOKO; yoko)
		{
			if (MY_CHECK_RECT_ATARI(chara, map[tate][yoko]) == TRUE)
			{
				*atariY = tate;
				*atariX = yoko;

				return TRUE;
			}
		}
	}
	return FALSE;
}

//########## 音を読み込む設定をする関数 ##########
//引　数：音構造体　	:設定する音構造体の変数
//引　数：const char *	:読み込む画像のファイルパス
//戻り値：BOOL			:TRUE:正常 / FALSE:異常
BOOL MY_MUSIC_LOAD(MUSIC* m, const char* path)
{
	//音を読み込む
	m->Handle = LoadSoundMem(path);

	if (m->Handle == -1)
	{
		return FALSE;
	}
	return TRUE;
}