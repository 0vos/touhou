/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "RecF.h"
#include <random>

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	void ConLife();
	void ConEnemylife();
	//Draw
	void DrawFace(int x, int y);
	void DrawBullet(int x, int y);
	void DrawEnemy(int x, int y);
	void DrawSpellyinyangyu(int x, int y);
	void DrawMylife(int x,int y);
	void DrawRestart1(int x, int y);
	void DrawContinue1(int x, int y);
	void DrawExit1(int x, int y);
	void DrawRestart2(int x, int y);
	void DrawContinue2(int x, int y);
	void DrawExit2(int x, int y);
	void DrawRevive1(int x, int y);
	void DrawRevive2(int x, int y); 
	void DrawMeaningless(int x, int y);
	void DrawEnemylife(int x, int y);
	void DrawWin(int x, int y);
	void DrawBorder1(int x, int y);
	void DrawBorder2(int x, int y);
	void DrawBlock(int x, int y);//画方块Spring
	void DrawBlockGreen(int x, int y);//Summer
	void DrawBlockBlue(int x, int y);//Winter
	void DrawBlockOrange(int x, int y);//Autumn
	//draw numbers
	void Draw1(int x, int y);
	void Draw2(int x, int y);
	void Draw3(int x, int y);
	void Draw4(int x, int y);
	void Draw5(int x, int y);
	void Draw6(int x, int y);
	void Draw7(int x, int y);
	void Draw8(int x, int y);
	void Draw9(int x, int y);
	void Draw0(int x, int y);
	//seasons
	void DrawSummer(int x, int y);
	void DrawAutumn(int x, int y);
	void DrawWinter(int x, int y);
	void DrawSpring(int x, int y);

	//functions
	void Shoot();//子弹射击函数
	void BlockMove(int x, int y, int speed, int reclife, RecF& arec);//单个方块下落
	void BlockMoveSummer(int x, int y, int speed, int reclife, RecF& arec);//单个方块下落
	void BlockMoveWinter(int x, int y, int speed, int reclife, RecF& arec);//单个方块下落
	void BlockMoveAutumn(int x, int y, int speed, int reclife, RecF& arec);//单个方块下落
	int SomeRand(int x[], int y[]);//生成随机数
	void Blocks(int x[], int y[], int reclife, int speed);//许多随机方块下落综合函数Spring
	void BlocksSummer(int x[], int y[], int reclife, int speed);//许多随机方块下落综合函数Summer
	void BlocksWinter(int x[], int y[], int reclife, int speed);//许多随机方块下落综合函数Winter
	void BlocksAutumn(int x[], int y[], int reclife, int speed);//许多随机方块下落综合函数Autumn
	void BlocksAutumnRemain();//还在屏幕上的就继续保留，没有停下的直接删除
	void BlocksSummerRemain();
	void BlocksWinterRemain();
	bool Bingo(RecF& arec) const;//子弹射到了方块
	void limitchara();//如果方块下落，砸到角色，角色一起下落
	bool CharaBlockLeft();//角色碰到了方块的左边
	bool CharaBlockRight();
	bool CharaBlockTop();
	bool CharaBlockBottom();
	bool CharaMoveable();//如果角色上下左右都碰到了方块，说明不能移动（被压死了
	bool Charadie();//角色死亡
	void CharaREalive();//角色复活到方块上面
	bool limitbullet();//限制子弹（不穿越过方块 未完成
	void EnemyHurtAndDie();//敌人受伤、死亡判定
	//time count
	void TimeCount();
	//score
	void scores(int score);
	void showScores(int x, int y);
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	int GameWidth;
	int GameHeight;
	double x = 370;
	double y = 300;
	double vx = 0;
	double vy = 0;
	double bulletX = x;
	double bulletY = y;
	RecF enemyRec;//敌人的矩形
	RecF faceRec;//自机的矩形（玩家
	RecF bulletRec;//子弹的矩形
	double enemyX = 230;//敌人的X坐标
	double enemyY = 20;
	//spell capcom
	int bxL = 0;
	int bxR = 799;
	int byU = 0;
	int byD = 599;
	int charaX = 400;
	int charaY = 100;
	int bulletTimeSum = 5;
	int life = 5;//自机的生命
	int enemyilfe = 100;//敌人的生命
	int enemynum = 0;
	int timesum = 0;
	int selectedOperation = 0;
	bool CharaAlreadyDead = false;//检测玩家是否已经死了一条命（死了就不能反复死
	bool CharaDraw = true;//是否画玩家 被压死了就不画
	bool EnemyAlreadyDead = false;//检测敌人生命是否归零
	bool IsBulletPressed = false;//检测是否已经按过空格键了
	bool inhibit = false;//检测是否已经按过方向键了
	bool flagcapcom = false;
	bool isGamePaused = false;
	bool isShown = false;
	bool isRestartRequested = false; // 定义一个标记，表示是否请求重来
	bool isUpKeyPressed = false;
	bool isDownKeyPressed = false;
	//block part
	RecF recs[1000];//方块的类数组
	int countrecs = 0;//数在界面上生成了多少个方块
	int timedown60 = 120;//倒计时60*1/60=1秒，每隔1秒下落新的一组
	int CountBlockThisFrame;//每生成新的一组 记录生成前countrecs的数值
	int dropblcoks;//每生成一组 这一组的方块数
	int xBB[10], yBB[10];//每一组x 随机偏移, 每一组y 随机偏移
	//time part
	int timelife = 20;
	const int timeUplife = 20;
	int framecount = 0;
	int tenPositionX = 94;
	int digitPositionX = 126;
	int numberY = 100;
	bool onepartIsover = false;
	typedef void (Game::* numbers) (int x, int y);
	numbers numberTen[7] = { &Game:: Draw3,&Game:: Draw2,&Game:: Draw1,&Game:: Draw0 };
	numbers numberDigits[10] = { &Game::Draw9, &Game::Draw8, &Game::Draw7, &Game::Draw6, 
		&Game::Draw5,&Game::Draw4, &Game::Draw3, &Game::Draw2, &Game::Draw1, &Game::Draw0 };
	//seasons part;
	int seasonsTimecount = 60;//显示60帧
	bool seasonOpenDone = false;
	enum seasons{Summer, Autumn, Winter, Spring};
	int seasonSpell = Summer;
	//score part
	int scoreChara = 0;
	//int digitPositionX = 300;
	int bigPositionX[7] = { 380 };
	//numbers* scorep[7] = { numberDigits, numberDigits, numberDigits,
	//	numberDigits, numberDigits, numberDigits, numberDigits };
	/********************************/
	/*  User Variables              */
	/********************************/
};