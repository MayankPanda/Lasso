#include <simplecpp>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace simplecpp;
double *minimum(double *d1,double *d2,double *d3)//function to find minimum
{
if ((*d1<*d2)&&(*d1<*d3))
return d1;
else if ((*d2<*d3)&&(*d2<*d1))
return d2;
else
return d3;}
void Controls()//function to display controls
{
Text t1(750,100,"THE CONTROLS ARE AS FOLLOWS");
Text t2 (200,200,"COMMANDS");
Text t3(800,200,"Tasks");
Text c1(200,300,"t");
Text c2(200,350,"l");
Text c3(200,400,"y");
Text c4(200,450,"q");
Text c5(200,500,"[");
Text c6(200,550,"]");
Text c7(200,600,"=");
Text c8(200,650,"-");
Text d1(800,300,"TO SET LASSO IN TRAJECTORY");
Text d2(800,350,"TO LOOP THE LASSO");
Text d3(800,400,"TO YANK THE LASSO");
Text d4(800,450,"TO QUIT THE GAME");
Text d5(800,500,"TO ROTATE LASSO ANTI CLOCKWISE*");
Text d6(800,550,"TO ROTATE LASSO CLOCKWISE*");
Text d7(800,600,"TO INCREASE LASSO SPEED**");
Text d8(800,650,"TO DECREASE LASSO SPEED**");
Text s1(750,700,"*: ONLY WHEN LASSO IS PAUSED");
Text s2(750,750,"**: SPEED CHANGE ALLOWED ONLY WHEN HALF OF THE TARGET SCORE IS ACHEIVED");
Text clix(750,750+textHeight(),"CLICK ANYWHERE");
t1.setColor(COLOR("blue"));
t2.setColor(COLOR("red"));
t3.setColor(COLOR("red"));
getClick();//waiting for user to click
}
void LoadingAnim()//loading dots display function
{
Rectangle r1(750+textWidth("DING.."),500,textWidth("..."),textHeight());
r1.setColor(COLOR("white"));

Text dot1(750+textWidth("DING."),500,".");
wait(1);
Text dot2(750+textWidth("DING.."),500,".");
wait(1);
Text dot3(750+textWidth("DING..."),500,".");
wait(1);
dot1.setColor(COLOR("white"));
dot2.setColor(COLOR("white"));
dot3.setColor(COLOR("white"));
r1.setFill(true);
Text dot4(750+textWidth("DING."),500,".");
wait(1);
Text dot5(750+textWidth("DING.."),500,".");
wait(1);
}

void Welcome()//welcome function
{
Text t1(750,200,"Welcome to Lasso Game");
t1.setColor(COLOR("blue"));
Rectangle r1(750,200,textWidth("Welcome to Lasso Game")+4,textHeight()+4);
Text t2(750,300,"THE BASIC PRINCIPLE IS TO COLLECT COINS USING LASSO IN A WAY TO MAXIMISE POINTS");
t2.setColor(COLOR("red"));
Rectangle r2(750,300,textWidth("THE BASIC PRINCIPLE IS TO COLLECT COINS USING LASSO IN A WAY TO MAXIMISE POINTS")+5,textHeight()+5);
Text t3(750,500,"LOADING");
Rectangle r3(750,500,textWidth("LOADING")+5,textHeight()+5);
LoadingAnim();
r1.setColor(COLOR("white"));
r1.setFill(true);
r2.setColor(COLOR("white"));
r2.setFill(true);
r3.setColor(COLOR("white"));
r3.setFill(true);
}
void Rules()//Rules of the Game
{
Text t1(750,300,"THE RULES ARE AS FOLLOWS:");
Circle Coin(400,400,10);
Coin.setColor(COLOR("yellow"));
Coin.setFill(true);
Circle Bomb(400,550,10);
Bomb.setColor(COLOR("black"));
Bomb.setFill(true);
Circle Special(400,700,10);

Special.setColor(COLOR("blue"));
Special.setFill(true);
Text CoinDesc(800,400,"This is a Coin which when collected increases the score by 1");
Text BombDesc(800,550,"This is a Bomb and when collected it decreases the score by 1");
Text SpecialDesc(800,700,"This is a Special Coin which when collected increases the score by 3");
Text Click(750,780,"Click Anywhere to proceed");
getClick();
Rectangle r1(750,400,1500,800);
r1.setColor(COLOR("white"));
r1.setFill(true);

Text Load(750,500,"LOADING");
LoadingAnim();//Loading dots Animation
wait(1);
Rectangle r2(750,400,1500,800);
r2.setColor(COLOR("white"));
r2.setFill(true);
}
int DifficultyLevel()
{
int level;
//Select Difficulty level with Easy Medium Hard and accordingly adjust target
Text t1(750,40,"SELECT DIFFICULTY LEVEL BY CLICKING");
Rectangle Easyr(700,150,300,100);
Easyr.setColor(COLOR("green"));
Easyr.setFill(true);
Text Easy(700,150,"EASY");
Rectangle Mediumr(700,300,300,100);
Mediumr.setColor(COLOR("yellow"));
Mediumr.setFill(true);
Text Medium(700,300,"MEDIUM");
Rectangle Difficultr(700,450,300,100);
Difficultr.setColor(COLOR("red"));
Difficultr.setFill(true);
Text Difficult(700,450,"DIFFICULT");
int w=getClick();//assigning diffculty level according to click
int ly=w%65536;
if ((ly>100)&&(ly<200))
level=1;
else if ((ly>250)&&(ly<350))
level=2;
else if ((ly>400)&&(ly<500))
level=3;
return level;
}



//movingObject.h
#ifndef _MOVINGOBJECT_INCLUDED_
#define _MOVINGOBJECT_INCLUDED_

#include <simplecpp>
#include <vector>
#include <composite.h>
#include <sprite.h>
using namespace simplecpp;

class MovingObject : public Sprite {
  vector<Sprite*> parts;
  double vx, vy;
  double ax, ay;
  bool paused;
  void initMO(double argvx, double argvy, double argax, double argay, bool argpaused=true) {
    vx=argvx; vy=argvy; ax=argax; ay=argay; paused=argpaused;
  }
 public:
 MovingObject(double argvx, double argvy, double argax, double argay, bool argpaused=true)
    : Sprite() {
    initMO(argvx, argvy, argax, argay, argpaused);
  }
 MovingObject(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : Sprite() {
   double angle_rad = angle_deg*PI/180.0;
   double argvx = speed*cos(angle_rad);
   double argvy = -speed*sin(angle_rad);
   initMO(argvx, argvy, argax, argay, argpaused);
  }
  void set_vx(double argvx) { vx = argvx; }
  void set_vy(double argvy) { vy = argvy; }
  void set_ax(double argax) { ax = argax; }
  void set_ay(double argay) { ay = argay; }
  double getXPos();
  double getYPos();
  void reset_all(double argx, double argy, double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta);

  void pause() { paused = true; }
  void unpause() { paused = false; }
  bool isPaused() { return paused; }

  void addPart(Sprite* p) {
    parts.push_back(p);
  }
  void nextStep(double t);
  void getAttachedTo(MovingObject *m);
};

#endif

//MovingObject.cpp

void MovingObject::nextStep(double t) {
  if(paused) { return; }
  //cerr << "x=" << getXPos() << ",y=" << getYPos() << endl;
  //cerr << "vx=" << vx << ",vy=" << vy << endl;
  //cerr << "ax=" << ax << ",ay=" << ay << endl;

  for(size_t i=0; i<parts.size(); i++){ //size_t gives size of i
    parts[i]->move(vx*t, vy*t);
  }
  vx += ax*t;
  vy += ay*t;
} // End MovingObject::nextStep()

double MovingObject::getXPos() {
  return (parts.size() > 0) ? parts[0]->getX() : -1;
}

double MovingObject::getYPos() {
  return (parts.size() > 0) ? parts[0]->getY() : -1;
}

void MovingObject::reset_all(double argx, double argy, double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) {
  for(size_t i=0; i<parts.size(); i++){
    parts[i]->moveTo(argx, argy);
  }
  double angle_rad = angle_deg*PI/180.0;
  double argvx = speed*cos(angle_rad);
  double argvy = -speed*sin(angle_rad);
  vx = argvx; vy = argvy; ax = argax; ay = argay; paused = argpaused;
} // End MovingObject::reset_all()

void MovingObject::getAttachedTo(MovingObject *m) {

  double xpos = m->getXPos();
  double ypos = m->getYPos();
  for(size_t i=0; i<parts.size(); i++){
    parts[i]->moveTo(xpos, ypos);
  }
  initMO(m->vx, m->vy, m->ax, m->ay, m->paused);
}

//coin.h
#ifndef __COIN_H__
#define __COIN_H__
class Bomb: public MovingObject//bomb object class
{
 double bomb_start_x;
  double bomb_start_y;

  double bomb_ax;
  double bomb_ay;

  // Moving parts
  Circle bomb;

 public:
 double release_speed;
  double release_angle_deg;
 Bomb(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    release_angle_deg = angle_deg;
    bomb_ax = argax;
    bomb_ay = argay;
    initbomb();
  }

  void initbomb();//BOMB INITIALISATION FUNCTION
  void resetbomb(double,double);//BOMB RESET FUNC
  };
//END CLASS BOMB
class Coin : public MovingObject {
  double coin_start_x;
  double coin_start_y;

  double coin_ax;
  double coin_ay;

  // Moving parts
  Circle coin_circle;

 public:
 double release_speed;
  double release_angle_deg;
 Coin(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    release_angle_deg = angle_deg;
    coin_ax = argax;
    coin_ay = argay;
    initCoin();
  }

  void initCoin();
  void resetCoin(double,double);
  void setcolor(char []);
  void changestartcoord(int x);

}; // End class Coin
class SpecialCoin: public MovingObject
{
 double scoin_start_x;
  double scoin_start_y;

  double scoin_ax;
  double scoin_ay;

  // Moving parts
  Circle Special;

 public:
 double release_speed;
  double release_angle_deg;
 SpecialCoin(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    release_angle_deg = angle_deg;
    scoin_ax = argax;
    scoin_ay = argay;
    initscoin();
  }

  void initscoin();
  void resetscoin(double,double);
  };
//END CLASS SPECIAL COIN
#endif

//lasso.h
#ifndef __LASSO_H__
#define __LASSO_H__

#define WINDOW_X 1500
#define WINDOW_Y 800

#define STEP_TIME 0.05

#define PLAY_X_START 200
#define PLAY_Y_START 0
#define PLAY_X_WIDTH (WINDOW_X-PLAY_X_START)
#define PLAY_Y_HEIGHT (WINDOW_Y-150)

#define LASSO_X_OFFSET 100
#define LASSO_Y_HEIGHT 100
#define LASSO_BAND_LENGTH LASSO_X_OFFSET
#define LASSO_THICKNESS 5

#define COIN_GAP 0.2

#define RELEASE_ANGLE_STEP_DEG 5
#define MIN_RELEASE_ANGLE_DEG 0
#define MAX_RELEASE_ANGLE_DEG (360-RELEASE_ANGLE_STEP_DEG)
#define INIT_RELEASE_ANGLE_DEG 45

#define RELEASE_SPEED_STEP 20
#define MIN_RELEASE_SPEED 0
#define MAX_RELEASE_SPEED 5000 //Change in MAx SPeed
#define INIT_RELEASE_SPEED 350

#define COIN_SPEED 400
#define COIN_ANGLE_DEG 127
//#define COIN_ANGLE_DEG3 150 //Change in angle


#define LASSO_G 30
#define COIN_G 30
//#define COIN_G2 30
//#define COIN_G3 30


#define LASSO_SIZE 10
#define LASSO_RADIUS 60
#define COIN_SIZE 5

class Lasso : public MovingObject {
public:
  double lasso_start_x;
  double lasso_start_y;
  double release_speed;
  double release_angle_deg;
  double lasso_ax;
  double lasso_ay;

  // Moving parts
  Circle lasso_circle;
  Circle lasso_loop;

  // Non-moving parts
  Line lasso_line;
  Line lasso_band;

  // State info
  bool lasso_looped;
  Coin *the_coin;
  Bomb *the_bomb;
  SpecialCoin *the_scoin;
  int num_coins;

  void initLasso();
 public:
 Lasso(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    release_angle_deg = angle_deg;
    lasso_ax = argax;
    lasso_ay = argay;
    initLasso();
  }

  void draw_lasso_band();
  void yank();
  void loopit();
  void addAngle(double angle_deg);
  void addSpeed(double speed);

  void nextStep(double t);
  bool check_for_coin(Coin *coin,Coin *trial,Coin *down);
  bool check_for_scoin(SpecialCoin *scoin);
  bool check_for_bomb(Bomb *bomb);
  int getNumCoins() { return num_coins; }

}; // End class Lasso

#endif

//coin.h
void Bomb::initbomb() {
  bomb_start_x = (PLAY_X_START+WINDOW_X)/2;
  bomb_start_y = PLAY_Y_HEIGHT;
  bomb.reset(bomb_start_x, bomb_start_y, COIN_SIZE);
  bomb.setColor(COLOR("black"));
  bomb.setFill(true);
  addPart(&bomb);

}

void Bomb::resetbomb(double speed,double degree) {
  double bomb_speed = speed;
  double bomb_angle_deg = degree;
  bomb_ax = 0;
  bomb_ay = COIN_G;
  bool paused = true, rtheta = true;
  reset_all(bomb_start_x,bomb_start_y, bomb_speed, bomb_angle_deg, bomb_ax, bomb_ay, paused, rtheta);
}

void Coin::initCoin() {
  coin_start_x = (PLAY_X_START+WINDOW_X)/2;
  coin_start_y = PLAY_Y_HEIGHT;
  coin_circle.reset(coin_start_x, coin_start_y, COIN_SIZE);
  addPart(&coin_circle);

}
void Coin::changestartcoord(int x)
{
coin_start_x=x;
}

void Coin::resetCoin(double speed,double degree) {
  double coin_speed = speed;
  double coin_angle_deg = degree;
  coin_ax = 0;
  coin_ay = COIN_G;
  bool paused = true, rtheta = true;
  reset_all(coin_start_x, coin_start_y, coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
}
void Coin::setcolor(char c[])
{
coin_circle.setColor(COLOR(c));
coin_circle.setFill(true);
}
//lasso.cpp

void Lasso::draw_lasso_band() {
  double len = (release_speed/MAX_RELEASE_SPEED)*LASSO_BAND_LENGTH;
  double arad = release_angle_deg*PI/180.0;
  double xlen = len*cos(arad);
  double ylen = len*sin(arad);
  lasso_band.reset(lasso_start_x, lasso_start_y, (lasso_start_x-xlen), (lasso_start_y+ylen));
  lasso_band.setThickness(LASSO_THICKNESS);
} // End Lasso::draw_lasso_band()

void Lasso::initLasso() {
  lasso_start_x = (PLAY_X_START+LASSO_X_OFFSET);
  lasso_start_y = (PLAY_Y_HEIGHT-LASSO_Y_HEIGHT);
  lasso_circle.reset(lasso_start_x, lasso_start_y, LASSO_SIZE);
  lasso_circle.setColor(COLOR("red"));
  lasso_circle.setFill(true);
  lasso_loop.reset(lasso_start_x, lasso_start_y, LASSO_SIZE/2);
  lasso_loop.setColor(COLOR("brown"));
  lasso_loop.setFill(true);
  addPart(&lasso_circle);
  addPart(&lasso_loop);
  lasso_looped = false;
  the_coin = NULL;
  the_bomb=NULL;
  the_scoin=NULL;
  num_coins = 0;

  lasso_line.reset(lasso_start_x, lasso_start_y, lasso_start_x, lasso_start_y);
  lasso_line.setColor(COLOR("black"));

  lasso_band.setColor(COLOR("blue"));
  draw_lasso_band();

} // End Lasso::initLasso()

void Lasso::yank() {
  bool paused = true, rtheta = true;
  reset_all(lasso_start_x, lasso_start_y, release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
  lasso_loop.reset(lasso_start_x, lasso_start_y, LASSO_SIZE/2);
  lasso_loop.setFill(true);
  lasso_looped = false;
  if (the_scoin!= NULL) {
    num_coins+=3;
    the_scoin->resetscoin(the_scoin->release_speed,the_scoin->release_angle_deg);
    the_scoin=NULL;
    return;
    }
  if(the_bomb != NULL) {
    num_coins--;
    the_bomb->resetbomb(the_bomb->release_speed,the_bomb->release_angle_deg);
    the_bomb=NULL;
    return;
    }
     if(the_coin != NULL) {
    num_coins++;
    the_coin->resetCoin(the_coin->release_speed,the_coin->release_angle_deg);
    the_coin=NULL;

  }
} // End Lasso::yank()

void Lasso::loopit() {
  if(lasso_looped) { return; } // Already looped
  lasso_loop.reset(getXPos(), getYPos(), LASSO_RADIUS);
  lasso_loop.setFill(false);
  lasso_looped = true;
} // End Lasso::loopit()

void Lasso::addAngle(double angle_deg) {
  release_angle_deg += angle_deg;
  if(release_angle_deg < MIN_RELEASE_ANGLE_DEG) { release_angle_deg = MIN_RELEASE_ANGLE_DEG; }
  if(release_angle_deg > MAX_RELEASE_ANGLE_DEG) { release_angle_deg = MAX_RELEASE_ANGLE_DEG; }
  bool paused = true, rtheta = true;
  reset_all(lasso_start_x, lasso_start_y, release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
} // End Lasso::addAngle()

void Lasso::addSpeed(double speed) {
  release_speed += speed;
  if(release_speed < MIN_RELEASE_SPEED) { release_speed = MIN_RELEASE_SPEED; }
  if(release_speed > MAX_RELEASE_SPEED) { release_speed = MAX_RELEASE_SPEED; }
  bool paused = true, rtheta = true;
  reset_all(lasso_start_x, lasso_start_y, release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
} // End Lasso::addSpeed()

void Lasso::nextStep(double stepTime) {
  draw_lasso_band();
  MovingObject::nextStep(stepTime);
  if(getYPos() > PLAY_Y_HEIGHT) { yank(); }
  lasso_line.reset(lasso_start_x, lasso_start_y, getXPos(), getYPos());
} // End Lasso::nextStep()

bool Lasso::check_for_coin(Coin *coinPtr1,Coin *coinPtr2,Coin *coinPtr3) {
  double lasso_x = getXPos();
  double lasso_y = getYPos();
  double coin_x1 = coinPtr1->getXPos();
  double coin_y1 = coinPtr1->getYPos();
  double xdiff1 = (lasso_x - coin_x1);
  double ydiff1 = (lasso_y - coin_y1);
  double distance1 = sqrt((xdiff1*xdiff1)+(ydiff1*ydiff1));
  double coin_x2 = coinPtr2->getXPos();
  double coin_y2 = coinPtr2->getYPos();
  double xdiff2 = (lasso_x - coin_x2);
  double ydiff2 = (lasso_y - coin_y2);
  double distance2 = sqrt((xdiff2*xdiff2)+(ydiff2*ydiff2));
  double coin_x3 = coinPtr3->getXPos();
  double coin_y3 = coinPtr3->getYPos();
  double xdiff3 = (lasso_x - coin_x3);
  double ydiff3 = (lasso_y - coin_y3);
  double distance3 = sqrt((xdiff3*xdiff3)+(ydiff3*ydiff3));
  double *d=minimum(&distance1,&distance2,&distance3);
  Coin *coinPtr;
  if (d==&distance1)
  coinPtr=coinPtr1;
  else if (d==&distance2)
  coinPtr=coinPtr2;
  else if (d==&distance3)
  coinPtr=coinPtr3;
  if(*d<= LASSO_RADIUS) {
    the_coin = coinPtr;
    the_coin->getAttachedTo(this);
    return true;
  }
  else
  return false;
} // End Lasso::check_for_coin()
//Returns Bool value if COIN IS COLLECTED
bool Lasso::check_for_bomb(Bomb *bptr) //Returns Bool value if BOMB IS COLLECTED
{
double lasso_x = getXPos();
  double lasso_y = getYPos();
  double bomb_x=bptr->getXPos();
  double bomb_y=bptr->getYPos();

  double xdiff=(lasso_x-bomb_x);
  double ydiff=(lasso_y-bomb_y);
  double distance=sqrt((xdiff*xdiff)+(ydiff*ydiff));
  if (distance<=LASSO_RADIUS)
  {
  the_bomb=bptr;
  the_bomb->getAttachedTo(this);
  return true;
}
else
return false;
}
bool Lasso::check_for_scoin(SpecialCoin *scoin) //Returns Bool value if SPECIAL COIN IS COLLECTED
{
double lasso_x = getXPos();
  double lasso_y = getYPos();
  double special_x=scoin->getXPos();
  double special_y=scoin->getYPos();
  double xdiff=(lasso_x-special_x);
  double ydiff=(lasso_y-special_y);
  double distance=sqrt((xdiff*xdiff)+(ydiff*ydiff));
  if (distance<=LASSO_RADIUS)
  {
  the_scoin=scoin;
  the_scoin->getAttachedTo(this);
  return true;
}
else
return false;
}

void SpecialCoin::initscoin() {
  scoin_start_x = (PLAY_X_START+WINDOW_X)/2;
  scoin_start_y = PLAY_Y_HEIGHT;
  Special.reset(scoin_start_x, scoin_start_y, COIN_SIZE);
  Special.setColor(COLOR("blue"));
  Special.setFill(true);
  addPart(&Special);

}

void SpecialCoin::resetscoin(double speed,double degree) {
  double scoin_speed = speed;
  double scoin_angle_deg = degree;
  scoin_ax = 0;
  scoin_ay = COIN_G;
  bool paused = true, rtheta = true;
  reset_all(scoin_start_x, scoin_start_y, scoin_speed, scoin_angle_deg, scoin_ax, scoin_ay, paused, rtheta);
}

main_program {

  initCanvas("Lasso", WINDOW_X, WINDOW_Y);
bool bombcaught=false;
bool scoincaught=false;
bool coincaught=false;
int level,target;
char WinningMessage[]={"Congratulations!!!You WIN"};
char LosingMessage[]={"Better Luck Next Time :("};
  Welcome();
  Rules();
  Controls();
  level=DifficultyLevel();
  int stepCount = 0;
  float stepTime = STEP_TIME;
  float runTime = 10; // sec; -ve means infinite //Value edited from -1
  float currTime = 0;
  if (level==1)
  target=5;
  else if (level==2)
  target=8;
  else if (level==3)
  target=10;
//Set target according to difficulty level
  // Draw lasso at start position
  double release_speed = INIT_RELEASE_SPEED; // m/s
  double release_angle_deg = INIT_RELEASE_ANGLE_DEG; // degrees
  double lasso_ax = 0;
  double lasso_ay = LASSO_G;
  bool paused = true;
  bool rtheta = true;
  //Insert Welcome and RUle DIsplay Functions
  Lasso lasso(release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
  Line b1(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
  b1.setColor(COLOR("blue"));
  Line b2(PLAY_X_START, 0, PLAY_X_START, WINDOW_Y);
  b2.setColor(COLOR("blue"));

  string msg("Cmd: _");
  Text charPressed(PLAY_X_START+50, PLAY_Y_HEIGHT+20, msg);
  char coinScoreStr[256];
  sprintf(coinScoreStr, "Coins: %d", lasso.getNumCoins());
  Text coinScore(PLAY_X_START+50, PLAY_Y_HEIGHT+50, coinScoreStr);


  paused = true; rtheta = true;
  double coin_speed = COIN_SPEED;
  double coin_angle_deg = COIN_ANGLE_DEG;
  double coin_ax = 0;
  double coin_ay = COIN_G;
  Coin coin(coin_speed+170,135, coin_ax, coin_ay, paused, rtheta);
  Coin trial(coin_speed,90,coin_ax,coin_ay,paused,rtheta);
  Coin down(coin_speed+50,70,coin_ax,coin_ay,paused,rtheta);
  SpecialCoin magnet(coin_speed+100, 105, coin_ax, coin_ay, paused, rtheta);
  char coinclr[]="yellow";
coin.setcolor(coinclr);
trial.setcolor(coinclr);
down.setcolor(coinclr);
trial.changestartcoord(PLAY_X_START-100);
down.changestartcoord(PLAY_X_START-159);
Bomb b(coin_speed-30,140, coin_ax+3, coin_ay, paused, rtheta);
 //Initialisation of Coins Bomb and Special Coin
 char Target[50];
  sprintf(Target,"Target:%d",target);
  Text targetdisplay(PLAY_X_START+100, PLAY_Y_HEIGHT+100, Target);
  // After every COIN_GAP sec, make the coin jump
  double last_coin_jump_end1 = 0;
double last_coin_jump_end2 = 0;
double last_coin_jump_end3 = 0;
double last_bomb_jump_end=0;
double last_scoin_jump_end=0;
  // When t is pressed, throw lasso
  // If lasso within range, make coin stick
  // When y is pressed, yank lasso
  // When l is pressed, loop lasso
  // When q is pressed, quit
  for(;;) {
    char CurrentTime[50];
    int curr=currTime;
  sprintf(CurrentTime,"Time:%d",curr);
  Text currentTime(PLAY_X_START+50, PLAY_Y_HEIGHT+70, CurrentTime);
char RunTime[50];
int run=runTime;
sprintf(RunTime,"Total Time:%d",run);
Text runTimedisplay(PLAY_X_START+50, PLAY_Y_HEIGHT+85, RunTime);
if (lasso.getNumCoins()>=target/2)
{
Text speedcvalid(900,700,"YOU CAN NOW CHANGE SPEED");
}
    if((runTime > 0) && (currTime > runTime))
     {

    wait(2);
    break; }
    XEvent e;
    bool pendingEv = checkEvent(e);
    if(pendingEv) {
      char c = charFromEvent(e);
      msg[msg.length()-1] = c;
      charPressed.setMessage(msg);
      switch(c) {
      case 't':
	lasso.unpause();
	break;
      case 'y':


	lasso.yank();
	break;
      case 'l':
	lasso.loopit();
	scoincaught=lasso.check_for_scoin(&magnet);
	if (scoincaught)
	{wait(STEP_TIME*5);
	break;
	}
	bombcaught=lasso.check_for_bomb(&b);
	if (bombcaught)
	{
	wait(STEP_TIME*5);
	break;
	}

	coincaught=lasso.check_for_coin(&coin,&trial,&down);
	wait(STEP_TIME*5);
	break;
      case '[':
	if(lasso.isPaused()) { lasso.addAngle(-RELEASE_ANGLE_STEP_DEG);	}
	break;
      case ']':
	if(lasso.isPaused()) { lasso.addAngle(+RELEASE_ANGLE_STEP_DEG); }
	break;
      case '-':
	if((lasso.isPaused())&&(lasso.getNumCoins()>=target/2)) { lasso.addSpeed(-RELEASE_SPEED_STEP); }
	break;
      case '=':
	if((lasso.isPaused())&&(lasso.getNumCoins()>=target/2)) { lasso.addSpeed(+RELEASE_SPEED_STEP); }
	break;
      case 'q':
	exit(0);
      default:
	break;
      }
    }

    lasso.nextStep(stepTime);
    coin.nextStep(stepTime);
b.nextStep(stepTime);
    trial.nextStep(stepTime);
    down.nextStep(stepTime);
    magnet.nextStep(stepTime);

    if(coin.isPaused()) {

      if((currTime-last_coin_jump_end1) >= COIN_GAP) {
	coin.unpause();
      }
    }
     if(trial.isPaused()) {

      if((currTime-last_coin_jump_end2) >= COIN_GAP) {
	trial.unpause();
      }
    }
    if(down.isPaused()) {

      if((currTime-last_coin_jump_end3) >= COIN_GAP) {
	down.unpause();
      }
    }
     if(b.isPaused()) {

      if((currTime-last_bomb_jump_end) >= COIN_GAP) {
	b.unpause();
      }
    }
 if(magnet.isPaused()) {

      if((currTime-last_scoin_jump_end) >= COIN_GAP) {
	magnet.unpause();
      }
    }

    if((coin.getYPos() > PLAY_Y_HEIGHT)||(coin.getXPos()<0)||(coin.getYPos()<0)) {
      coin.resetCoin(coin.release_speed,coin.release_angle_deg);
      last_coin_jump_end1 = currTime;
      }

       if((trial.getYPos() > PLAY_Y_HEIGHT)||(trial.getXPos()<0)||(trial.getYPos()<0)) {
      trial.resetCoin(trial.release_speed,trial.release_angle_deg);
      last_coin_jump_end2 = currTime;
    }
    if((down.getYPos() > PLAY_Y_HEIGHT)||(down.getXPos()<0)||(down.getYPos()<0)) {
      down.resetCoin(down.release_speed,down.release_angle_deg);

      last_coin_jump_end3 = currTime;
      }
       if((b.getYPos() > PLAY_Y_HEIGHT)||(b.getXPos()<0)||(b.getYPos()<0)) {
      b.resetbomb(b.release_speed,b.release_angle_deg);
      last_bomb_jump_end = currTime;
      }
if((magnet.getYPos() > PLAY_Y_HEIGHT)||(magnet.getXPos()<0)||(magnet.getYPos()<0)) {
      magnet.resetscoin(magnet.release_speed,magnet.release_angle_deg);
      last_scoin_jump_end = currTime;
      }

    sprintf(coinScoreStr, "Coins: %d", lasso.getNumCoins());
    coinScore.setMessage(coinScoreStr);

    stepCount++;
    currTime += stepTime;
    wait(stepTime);
    bombcaught=false;
    coincaught=false;
    scoincaught=false;
  } // End for(;;)
  //print Final result
  if (lasso.getNumCoins()>=target) //check if target is achieved
  {
  Text FinalMessage(500,400,WinningMessage);//print winning message
  wait(5);
  }
  else
  {
  Text FinalMessage(500,400,LosingMessage);//print losing message
  wait(5);
  }
} // End main_program

