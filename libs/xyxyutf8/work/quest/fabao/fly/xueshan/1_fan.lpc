// fabao.c
#include <ansi.h>
#include <armor.h>
#include <combat.h>
inherit FABAO;

mapping a_title()
{
	return ([
	"邓九公" : ({"blade","ad_blade",}),
	"邓婵玉" : ({"throwing","personality",}),
	"余化"   : ({"spells","ad_spells",}),
	"吕岳"   : ({"spells","ad_spells",}),
	"土行孙" : ({"dodge","ad_dodge",}),
	"申公豹" : ({"combat_succ","combat_dodge","combat_parry",}),
	"相柳"   : ({"spells_damage","combat_damage",}),
	"孔雀公主":({"personality","ad_bainiao-jian","ad_bingpo-blade","ad_cuixin-zhang",}),
]);
}

void create()
{
	set_name("招妖幡", ({ "zhaoyao fan", "fabao", "fan" }) );
	set("family_name","大雪山");
	set("long","此乃%s炼制的飞行类法宝。此外，此法宝还具备存储(reserve)内法的功能。\n");
	set("armor_type","Fabao");
	set("fabao_type",({"other"}));
	set("my_type","fan");
	set("fabao/max_force",15000);
	set("fabao/max_mana",8000);
	set("unit","面");
	set("飞行",1);
	set("fabao/dest_msg",HIW"\n"HIW"只见$n"HIW"在半空几个翻滚，顿时隐入云际，沓然无踪。\n"NOR);
	set("fabao/back_msg",HIW"\n"HIW"只见$n"HIW"在半空几个翻滚，又跌回$N"HIW"手中。\n"NOR);
	set("fabao/fly_msg",HIW"\n$n"HIW"雪光一闪，飞至$N"HIW"脚下，载着$P径直冲天而去！\n\n"NOR);
	set("fabao/fly_msg2",HIW"\n$n"HIW"雪光一闪$N"HIW"驾着$n"HIW"从天而降。\n\n"NOR);
	set("fabao/ji_msg",HIW"\n"HIW"$N"HIW"喃喃念了几句咒语，手中$n"HIW"「呼」地一下飞了出去，在半空滴溜溜转了几转又绕着$P周身游走。\n"NOR);
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
			set("long",sprintf(query("long"),"大雪山历代诸王"));
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
