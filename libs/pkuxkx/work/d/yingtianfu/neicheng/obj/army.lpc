inherit ARMY;
#include <ansi.h>

void create()
{	
	set_name("大明军队", ({ "daming jundui","jun dui","dui"}));
	set_weight(5000000);
	set("long", "这里是大明的军队。\n");
	set("material", "steal");
	set("unit", "只");
	set("value", 0);
    set("no_give",1);
    set("no_drop",1);
    set("no_put",1);
    set("no_get",1);
    set("shiqi",50);//士气
    set("junji",50);//军纪
    set("train_degree",50);//训练度
    set("fighters",1000); //默认1000人队伍
    set("liang",100000);//默认100000粮，大约够吃30分钟
    set("xiang",100000);//默认100000军饷，大约够用30分钟
    set("side","ming");//边
    set("weapon","刀");//武器
    slogans=({HIW"选锋营"NOR,HIR"神机营"NOR,HIC"三千营"NOR,HIB"盘蛇营"NOR,HIM"巨熊营"NOR,HIY"飞虎营"NOR,YEL"飞豹营"NOR,MAG"飞熊营"NOR});//番号，大明和其他部队最好不同
    slogan_ids=({"xuanfeng ying","shenji ying","sanqian ying","panshe ying","juxiong ying","feihu ying","feibao ying","feixiong ying"});
	setup();
    call_out("check",1);
    call_out("set_army",1);
}