// fabao.c
//塔(char) 
#include <ansi.h>
#include <armor.h>
#include <combat.h>
inherit FABAO;

mapping a_title()
{
	return ([
	"辛环"   : ({"hammer","ad_hammer",}),
	"余化"   : ({"spells","ad_spells",}),
	"吕岳"   : ({"spells","ad_spells",}),
	"土行孙" : ({"dodge","ad_dodge",}),
	"姜子牙" : ({"spells_succ","spells_dodge",}),
	"申公豹" : ({"combat_succ","combat_dodge","combat_parry",}),
	"相柳"   : ({"spells_damage","combat_damage",}),
	"龙女"   : ({"personality","intelligence","spells_succ","spells_dodge",}),
	"敖广"   : ({"unarmed","ad_unarmed","ad_dragonfight"}),
	"龟八斗" : ({"ad_hammer","hammer","ad_huntian-hammer",}),
	]);
}

void create()
{
	set_name("巡海飞叉", ({ "xunhai cha", "fabao", "cha" }) );
	set("family_name","东海龙宫");
	set("long","此乃%s炼制的飞行类法宝。此外，此法宝还具备存储(reserve)内法的功能。\n");
	set("armor_type","Fabao");
	set("fabao_type",({"other"}));
	set("my_type","weapon");
	set("fabao/max_force",10000);
	set("fabao/max_mana",10000);
	set("unit","柄");
	set("fabao/dest_msg",HIG"\n"HIG"只见$n"HIG"在半空几个翻滚，顿时隐入云际，沓然无踪。\n"NOR);
	set("fabao/back_msg",HIG"\n"HIC"只见$n"HIG"在半空几个翻滚，又跌回$N"HIG"手中。\n"NOR);
	set("fabao/ji_msg",HIG"\n"HIC"$N"HIG"喃喃念了几句咒语，手中$n"HIG"「呼」地一下飞了出去，在半空滴溜溜转了几转又绕着$P周身游走。\n"NOR);
	set("fabao/fly_msg",HIG"\n$n"HIG"闪了几闪，飞至$N"HIG"脚下，化作一片波涛载着$P径直冲天而去！\n\n"NOR);
	set("fabao/fly_msg2",HIG"\n"HIG"一道巨浪从天而降！随即化作一柄$n"HIG"，$N"HIG"显出了身形。\n\n"NOR);
	set("飞行",1);
	set("no_fabao",([
		"self_damage" : 1,
		"self_def" : 1,
		"combat_damage" : 1,
		"spells_damage" : 1,
		"combat_def" : 1,
		"spells_def" : 1,
		"hit_ob" : 1,
	]));
	setup();
}

void init()
{
	object me = this_player();
	if( environment() && me==environment() 
	 && !query("default_set") )
		this_object()->init_fabao(me);	 
	::init();
}

//战斗中法宝auto攻击
mixed hit_ob(object attacker,object target,int attack_type)
{
	return 0;
}

int init_fabao(object who)
{
	if( ::init_fabao(who) )
	{
		if( !query("fabao_title") )
			set("long",sprintf(query("long"),"东海龙王敖广"));
		else	set("long",sprintf(query("long"),query("fabao_title")));
		return 1;
	}
	else	return 0;
}

int self_damage(){return 0;}
int self_def(){return 0;}
int query_combat_damage(){return 0;}
int query_spells_damage(){return 0;}
int query_combat_def(){return 0;}
int query_spells_def(){return 0;}
