// fabao.c
//塔(char) 
#include <ansi.h>
#include <armor.h>
#include <combat.h>
inherit FABAO;

mapping a_title()
{
	return ([
	"邓婵玉" : ({"ad_unarmed","personality",}),
	"甄洛"   : ({"personality","intelligence","spells_succ","spells_dodge",}),
	"妲己"   : ({"personality","intelligence","fofce_refresh","receive_heal_kee",}),
	"湘君"   : ({"personality","intelligence","receive_heal_kee","receive_heal_sen",}),
	"娥皇"   : ({"personality","intelligence","receive_heal_sen","receive_curing_kee",}),
	"女英"   : ({"personality","intelligence","receive_curing_kee","receive_curing_sen",}),
	"何仙姑" : ({"sword","ad_sword","personality"}),
	"凝眸仙子":({"personality","ad_zongheng-sword","ad_siji-zhang"}),
	]);
}

void create()
{
	set_name("百花灯", ({ "baihua deng", "fabao", "deng" }) );
	set("family_name","百花谷");
	set("long","此乃%s炼制的飞行类法宝。此外，此法宝还具备存储(reserve)内法的功能。\n");
	set("armor_type","Fabao");
	set("fabao_type",({"other"}));
	set("my_type","char");
	set("fabao/max_force",15000);
	set("fabao/max_mana",15000);
	set("unit","朵");
	set("飞行",1);
	set("fabao/dest_msg",HIG"\n"HIG"只见$n"HIG"在半空几个翻滚，顿时隐入云际，沓然无踪。\n"NOR);
	set("fabao/back_msg",HIG"\n"HIG"只见$n"HIG"在半空几个翻滚，又跌回$N"HIG"手中。\n"NOR);
	set("fabao/ji_msg",HIG"\n"HIG"$N"HIG"喃喃念了几句咒语，手中$n"HIG"「呼」地一下飞到$P的头顶，滴溜溜转了几转停止不动，一道道青木之气从上而降，笼罩住了$N"HIG"全身。\n"NOR);
	set("fabao/fly_msg",HIG"\n$n"HIG"在$N"HIG"头顶绽放道道霞光，化作花雨包裹住$N"HIG"径直冲天而去！\n\n"NOR);
	set("fabao/fly_msg2",HIG"\n一阵花雨随风而来，瞬间化作了一朵$n"HIG"，$N顿时显出了身形。\n\n"NOR);
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

int init_fabao(object who)
{
	if( ::init_fabao(who) )
	{
		if( !query("fabao_title") )
			set("long",sprintf(query("long"),"蓬莱山百花谷凝眸仙子"));
		else	set("long",sprintf(query("long"),query("fabao_title")));
		return 1;
	}
	else	return 0;
}