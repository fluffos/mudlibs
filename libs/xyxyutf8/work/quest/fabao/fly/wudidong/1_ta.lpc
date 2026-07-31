// fabao.c
//塔(char) 
#include <ansi.h>
#include <armor.h>
#include <combat.h>
inherit FABAO;

mapping a_title()
{
	return ([
	"邓九公" : ({"blade","ad_blade",}),
	"余化"   : ({"spells","ad_spells",}),
	"吕岳"   : ({"spells","ad_spells",}),
	"土行孙" : ({"dodge","ad_dodge",}),
	"姜子牙" : ({"spells_succ","spells_dodge",}),
	"申公豹" : ({"combat_succ","combat_dodge","combat_parry",}),
	"相柳"   : ({"spells_damage","combat_damage",}),
	"甄洛"   : ({"personality","intelligence","spells_succ","spells_dodge",}),
	"妲己"   : ({"personality","intelligence","fofce_refresh","receive_heal_kee",}),
	"湘君"   : ({"personality","intelligence","receive_heal_kee","receive_heal_sen",}),
	"娥皇"   : ({"personality","intelligence","receive_heal_sen","receive_curing_kee",}),
	"女英"   : ({"personality","intelligence","receive_curing_kee","receive_curing_sen",}),
	"玉鼠精" : ({"blade","ad_blade","ad_kugu-blade","ad_yinfeng-zhua","personality",}),
	"李靖"   : ({"sword","ad_sword","ad_qixiu-jian","courage",}),
	]);
}

void create()
{
	set_name("百妖塔", ({ "baiyao ta", "fabao", "ta" }) );
	set("family_name","陷空山无底洞");
	set("long","此乃%s炼制的飞行类法宝。此外，此法宝还具备存储(reserve)内法的功能。\n");
	set("armor_type","Fabao");
	set("fabao_type",({"other"}));
	set("my_type","char");
	set("fabao/max_force",8000);
	set("fabao/max_mana",10000);
	set("unit","座");
	set("飞行",1);
	set("fabao/dest_msg",HIR"\n"HIR"只见$n"HIR"在半空几个翻滚，顿时隐入云际，沓然无踪。\n"NOR);
	set("fabao/back_msg",HIR"\n"HIR"只见$n"HIR"在半空几个翻滚，又跌回$N"HIR"手中。\n"NOR);
	set("fabao/ji_msg",HIR"\n"HIR"$N"HIR"从怀中掏出$n"HIR"，喃喃念了几句咒语，$n"HIR"「呼」地一下飞到$P的头顶，滴溜溜转了几转停止不动，一道血气从上而降，笼罩住了$N"HIR"全身。\n"NOR);
	set("fabao/fly_msg",HIR"\n$n"HIR"在$N"HIR"头顶转了几转，腾住一团血光，包裹住$N"HIR"径直冲天而去！\n\n"NOR);
	set("fabao/fly_msg2",HIR"\n$n一团血光从天而降，$N"HIR"从中现出身影。\n\n"NOR);
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
			set("long",sprintf(query("long"),"陷空山无底洞玉鼠夫人"));
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
