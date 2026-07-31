// fabao.c
//塔(char) 
#include <ansi.h>
#include <armor.h>
#include <combat.h>
inherit FABAO;

mapping a_title()
{
	return ([
	"余化"   : ({"spells","ad_spells",}),
	"吕岳"   : ({"spells","ad_spells",}),
	"土行孙" : ({"dodge","ad_dodge",}),
	"姜子牙" : ({"spells_succ","spells_dodge",}),
	"申公豹" : ({"combat_succ","combat_dodge","combat_parry",}),
	"相柳"   : ({"spells_damage","combat_damage",}),
	//
	"甄洛"   : ({"personality","intelligence","spells_succ","spells_dodge",}),
	"妲己"   : ({"personality","intelligence","fofce_refresh","receive_heal_kee",}),
	"湘君"   : ({"personality","intelligence","receive_heal_kee","receive_heal_sen",}),
	"娥皇"   : ({"personality","intelligence","receive_heal_sen","receive_curing_kee",}),
	"女英"   : ({"personality","intelligence","receive_curing_kee","receive_curing_sen",}),
	//
	"太清真人":({"ad_yujianshu","ad_tianshi-fufa","ad_sword","re_spells_damage",}),
]);
}

void create()
{
	set_name("蜀山御剑", ({ "shushan yujian", "fabao", "jian" }) );
	set("family_name","蜀山派");
	set("long","此乃%s炼制的攻击类法宝。\n");
	set("armor_type","Fabao");
	set("fabao_type",({"attack"}));
	set("my_type","weapon");
	set("unit","柄");
	set("fabao/dest_msg",HIC"\n"HIC"只见$n"HIC"在半空几个翻滚，顿时隐入云际，沓然无踪。\n"NOR);
	set("fabao/back_msg",HIC"\n"HIC"只见$n"HIC"在半空几个翻滚，又跌回$N"HIC"手中。\n"NOR);
	set("fabao/attack_msg",HIC"霎那间天色一变，风声大作！蜀山御剑带出一道低啸飞向$n"HIC"，凌空朝$n"HIC"$l刺去！\n"NOR);
	set("no_fabao",([
		"self_damage" : 1,
		"self_def" : 1,
		"combat_def" : 1,
		"spells_def" : 1,
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
			set("long",sprintf(query("long"),"蜀山七宫长老"));
		else	set("long",sprintf(query("long"),query("fabao_title")));
		return 1;
	}
	else	return 0;
}