// huoji. 药铺伙计
#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

int ask_yjw();
void create()
{
        set_name("药铺伙计", ({ "yaopu huoji", "huoji" }));
        set("str", 20);
        set("gender", "男性");
        set("age", 18);
        set("long", "一个碌忙的小伙计。\n");
        set("combat_exp", 250);
        set("attitude", "friendly");
        set("vendor_goods", ({
        (["name":MEDICINE_D("jinchuang"),"number":25]),
        (["name":"/clone/medicine/m-book1","number":5]),
        (["name":"/clone/medicine/jingmai/jingmai-book1","number":1]),
        (["name":MEDICINE_D("yangjing"),"number": 20]),
        (["name":MEDICINE_D("jys"),"number": 100]),
        }));
        
	set("inquiry", ([
		"玉肌丸" : (: ask_yjw :),
		"yuji wan" : (: ask_yjw :),
		])); 
        setup();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

int ask_yjw()
{
	object ob, me = this_player();
	
	if (present("yuji wan", me))
        {	
        	command("say 你不是已经有了么？");
                return 1; 
	}
	
	if (me->query("max_neili")<100 || me->query("eff_jingli")<200)
	{
		ob = new(MEDICINE_D("neili/yujiwan"));
		ob->set("owner", me->query("id"));
		ob->move(me);
		command("say 小心点,不要再掉了!");
		message_vision("$N递给$n一颗"+HIW+"玉肌丸"+NOR+"。\n", this_object(), me); 
		return 1;
	}
	else
	{
		command("say 胡乱吃药会生病的!");
		return 1;
	}
}

