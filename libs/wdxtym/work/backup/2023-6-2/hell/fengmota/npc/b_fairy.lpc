//【蜀山剑派】dhxy-evil 2000.7.5
// modified by vikee
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("陈平安", ({ "baifa laotou","fairy","laotou" }));
        set("title", "好象很猛的");
		set("title", HIY "剑客" NOR);
        set("age", 300);
        set("attitude", "peaceful");
	set("str", 500);
	set("int", 500);
	set("con", 500);
	set("dex", 500);
	set("chat_chance", 1);
    set("quest2/kuihua/pass", 1);

	set("qi", 25000000);
	set("max_qi", 25000000);
	set("jing", 25000000);
	set("max_jing", 25000000);
	set("neili", 25000000);
	set("max_neili", 25000000);
	set("jiali", 5000);
	set("combat_exp", 25000000);
	set("score", 3500);
    set_skill("force", 15000+random(100));
    set_skill("unarmed", 15000+random(100));
    set_skill("dodge", 10000+random(100));
    set_skill("parry", 10000+random(100));
    set_skill("sword", 15000+random(100));
    set_skill("hand", 15000+random(100));
    set_skill("cuff", 15000+random(100));
    set_skill("strike", 15000+random(100));
    set_skill("finger", 15000+random(100));
    set_skill("claw", 15000+random(100));
    set_skill("blade", 15000+random(100));
    set_skill("staff", 15000+random(100));
    set_skill("hammer", 15000+random(100));
    set_skill("club", 15000+random(100));
    set_skill("whip", 15000+random(100));
    set_skill("shanggu-mijings", 15000+random(100));	
	map_skill("force", "shanggu-mijings");
    map_skill("sword", "shanggu-mijings");
    map_skill("parry", "shanggu-mijings");
    map_skill("unarmed", "shanggu-mijings");
    map_skill("dodge", "shanggu-mijings");
	map_skill("hand", "shanggu-mijings");
    map_skill("cuff", "shanggu-mijings");
    map_skill("strike", "shanggu-mijings");
    map_skill("finger", "shanggu-mijings");
    map_skill("claw", "shanggu-mijings");
	map_skill("blade", "shanggu-mijings");
    map_skill("staff", "shanggu-mijings");
    map_skill("hammer", "shanggu-mijings");
    map_skill("club", "shanggu-mijings");
    map_skill("whip", "shanggu-mijings");
    set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
       (: perform_action, "force.shanggub1" :),
	   (: perform_action, "force.shanggub2" :),
		(: perform_action, "force.shanggub3" :),
		(: perform_action, "force.shanggub4" :),
		(: exert_function, "force.shanggua1" :),
		(: exert_function, "force.shanggua2" :),
		(: exert_function, "force.shanggua3" :),
		(: exert_function, "force.shanggua4" :),
	}));
	set_temp("apply/attack", 50000);
	set_temp("apply/defense", 30000);
	set_temp("apply/unarmed_damage", 65000);
	set_temp("apply/armor", 30000);
	
	if (clonep(this_object()))
	{
	set("chat_chance", 100);
	set("chat_msg", ({ (: random_move :) }));
	set("born_time", time());
	keep_heart_beat();
	}
	setup();
}

void init()
{
        add_action("do_answer", "answer");
}

int do_answer(string arg)
{
        object who = this_player();
        object me = this_object();
        object ob;
        if (!arg || (arg != "丧尽天良的良" && arg != "善良的良"))
                return notify_fail("你要回答什么？\n");

        message_vision(CYN"陈平安说：“下次我看见韩老魔那小子肯定揍他一顿，我回去咯，但我会每时每刻在你身边帮助$N的！”\n", this_player());
        command("haha"+ me->query("id"));
        command("great"+ me->query("id"));
        who->add_temp("shushan/answer_book_fairy",1);
        write(CYN"说罢，陈平安消失得无影无踪！\n"NOR);
        message_vision("$N发现身上多了一本书。\n",this_player());
        ob = new("/data/hell/fengmota/obj/fbook");
        ob->move(who);
        destruct(me);
        return 1;
}
