// poison.h 
// the headfile of poison
// write by xli
// begin in 1998.12.5

#ifndef POISON_H
#define POISON_H

#define TYPE_YIN 1
#define TYPE_YANG 2

#define PLACE_GIN 1
#define PLACE_KEE 2
#define PLACE_SEN 4
#define PLACE_FORCE 8

#endif

// 给出一些标准的使用动作
string std_useVerb=({"throw","spill","lay","smear","flip"});
string std_useDescribe=({"扔","洒","放","涂","弹"});

class Poison        // 毒药类
{
    string name;
    string verb;
    int damage_type;        // 是阴是阳，去掉中性一说
    int damage_place;       // 伤害的是精、气、神和内力中哪一个 
    int damage_start_wound; // 使用的瞬间伤害的点数(上限)
    int damage_start_hurt;  // 使用的瞬间伤害的点数(现有值)
    int damage_wound_point; // 从使用开始，每个心跳伤害的点数(上限)
    int damage_hurt_point;  // 从使用开始，每个心跳伤害的点数(现有值)
}



private class Poison poison=0;

void setup()
{
	seteuid( getuid() );
	this_object()->reset();
}

void SetType(string argType)
{
    if(argType=="yin")
        poison->damage_type=TYPE_YIN;
    if(argType=="yang")
        poison->damage_type=TYPE_YANG;
}

void SetPlace(string argPlace)
{
    if(argPlace="gin")
        poison->damage_place=PLACE_GIN;
    if(argPlace="kee")
        poison->damage_place=PLACE_KEE;
    if(argPlace="sen")
        poison->damage_place=PLACE_SEN;
}    

void SetDamage(int m_wound,int m_hurt,int m_woundp,int m_hurtp)
{
    damage_start_wound=m_wound;
    damage_start_hurt=m_hurt;
    damage_wound_point=m_woundp;
    damage_hurt_point=m_hurtp;
}

    