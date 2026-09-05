inherit ARMY;
#include <ansi.h>
void create()
{	
	string *names=({"山贼","土匪","强盗","马贼","悍匪","巨盗"});
	string *ids=({"shan zei","tu fei","qiang dao","ma zei","han fei","ju dao"});
	int *fights=({70+random(31),80+random(21),90+random(11),150+random(51),170+random(31),190+random(11)});
	int *trains=({40,40,40,50,50,50});
	int n=random(sizeof(names));
	set_name(names[n], ({ ids[n],"robbers"}));
	set_weight(5000000);
	set("long", "这是一支横行江浙一带的山贼。\n");
	set("material", "steal");
	set("unit", "支");
	set("value", 0);
    set("no_give",1);
    set("no_drop",1);
    set("no_put",1);
    set("no_get",1);
    set("shiqi",40+random(20));//士气
    set("junji",30+random(30));//军纪
    set("train_degree",trains[n]);//训练度
    set("fighters",fights[n]); 
	set("liang",1000);//默认100000粮，大约够吃30分钟
    set("xiang",1000);//默认100000军饷，大约够用30分钟
    set("side","robber");//边
	set("is_songrobber",1);
    set("weapon","刀");//武器
	setup();
    call_out("check",1);
    call_out("set_army",1);
}

int set_long(string name)
{
	if (!stringp(name))
	return 1;
	this_object()->set("long",replace_string(this_object()->query("long"),"江浙一带",name));
	return 1;
}
void init()
{
	set_long(environment()->query("short"));
	::init();
}

