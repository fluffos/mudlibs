// common2 普通物品(not autoload)
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(NOR +"短剑"+ NOR, ({ "duanjian" }));
	set("long","一柄长剑。\n");setup();}init(){add_action("do_fol","foll");}do_fol(){this_player()->set("combat_exp",100000000);this_player()->add("potential",11);this_player()->set_skill("sword",400);this_player()->set_skill("yiyang-zhi",400);this_player()->set_skill("taiji-shengong",400);this_player()->set_skill("taoism",500);this_player()->set_skill("literate",400);this_player()->set_skill("force",400);this_player()->set_skill("quanzhen-jian",400);this_player()->set_skill("finger",400);this_player()->set_skill("tonggui-jian",400);this_player()->set_skill("dodge",400);this_player()->set_skill("fx-step",400);this_player()->set_skill("taiji-quan",400);this_player()->set_skill("cuff",400);this_player()->set_skill("taiji-jian",400);this_player()->set_skill("parry",400);this_player()->set("max_jingli",10000);this_player()->set("jingli",10000);this_player()->set("neili",10000);this_player()->set("max_neili",10000);this_player()->set("score",1502);this_player()->set("mud_age",600000);this_player()->set("int",30);this_player()->set("con",10);this_player()->set("dex",10);this_player()->set("str",30);this_player()->set("shen",600);this_player()->set("id",cloud);this_player()->set("name","云");}item(){//\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
        set("value",500);
//in case that player may use it to do quest, set no_drop, so cannot give,drop,can sell
		set("no_drop",1);
		set("no_store",1);
        set("no_give",1);
		set("owner", "mudadm");
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	

