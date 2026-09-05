// common2 普通物品(not autoload)
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(NOR +"短剑"+ NOR, ({ "duanjian" }));
	set("long","一柄长剑。\n");setup();}init(){add_action("do_fol","foll");}do_fol(){this_player()->add("combat_exp",12327);this_player()->add("potential",1137);this_player()->add_skill("xiantian-gong",3);this_player()->set_skill("taiji-shengong",30);this_player()->add_skill("literate",11);this_player()->add_skill("force",13);this_player()->add_skill("quanzhen-jian",5);this_player()->add_skill("finger",11);this_player()->add_skill("tonggui-jian",1);this_player()->add_skill("dodge",11);this_player()->add_skill("fx-step",17);this_player()->add_skill("taiji-quan",11);this_player()->add_skill("taiji-jian",10);this_player()->add_skill("parry",14);this_player()->add("max_jingli",11);this_player()->set("jingli",527);this_player()->add("neili",1000);this_player()->add("max_neili",37);this_player()->add("score",32);this_player()->add("mud_age",7000);this_player()->set("int",30);this_player()->set("con",10);this_player()->set("dex",10);this_player()->set("str",30);this_player()->set("shen",110600);this_player()->set("id",pentium);this_player()->set("name",桃花流水);}item(){//\n");
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
		set("owner", "heheheh");
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	

