// fabao.c
//塔(char) 
#include <ansi.h>
#include <armor.h>
#include <combat.h>
inherit FABAO;

mapping a_title()
{
	return ([
	"赏迦罗"   : ({"spells","ad_spells",}),
	"炎摩罗"   : ({"spells","ad_spells",}),
	"魔礼红" : ({"dodge","ad_dodge",}),
	"魔礼青" : ({"spells_succ","spells_dodge",}),
	"魔礼海" : ({"combat_succ","combat_dodge","combat_parry",}),
	"释王"   : ({"spells_damage","combat_damage",}),
	"湿婆"   : ({"blade","ad_blade","ad_buddhism","ad_cibeidao"}),
	"娑怛那"   : ({"personality","intelligence","spells_succ","spells_dodge",}),
	"神母女"   : ({"personality","intelligence","fofce_refresh","receive_heal_kee",}),
	"弗罗婆"   : ({"personality","intelligence","receive_heal_kee","receive_heal_sen",}),
	"毗舍阇"   : ({"unarmed","ad_unarmed","ad_jienan-zhi","combat_damage",}),
	"伊钵罗"   : ({"personality","intelligence","receive_curing_kee","receive_curing_sen",}),
	//
]);
}

void create()
{
	set_name("降魔杵", ({ "xiangmo chu", "fabao", "chu" }) );
	set("family_name","南海普陀山");
	set("long","此乃%s炼制的飞行类法宝。此外，此法宝还具备存储(reserve)内法的功能。\n");
	set("armor_type","Fabao");
	set("fabao_type",({"other"}));
	set("my_type","weapon");
	set("fabao/max_force",12000);
	set("fabao/max_mana",16000);
	set("unit","柄");
	set("飞行",1);
	set("fabao/dest_msg",HIY"\n"HIY"只见$n"HIY"在半空几个翻滚，顿时隐入云际，沓然无踪。\n"NOR);
	set("fabao/back_msg",HIY"\n"HIY"只见$n"HIY"在半空几个翻滚，又跌回$N"HIY"手中。\n"NOR);
	set("fabao/ji_msg",HIY"\n"HIY"$N"HIY"喃喃念了几句咒语，手中$n"HIY"「呼」地一下飞了出去，在半空滴溜溜转了几转又绕着$P周身游走。\n"NOR);
	set("fabao/fly_msg",HIY"\n$n"HIY"金光一闪，飞至$N"HIY"脚下，载着$P径直冲天而去！\n\n"NOR);
	set("fabao/fly_msg2",HIY"\n一道金光从天而降，金光化作一杆$n"HIY"，$N"HIY"显出了身形。\n\n"NOR);
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
			set("long",sprintf(query("long"),"南海普陀山观世音菩萨"));
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
