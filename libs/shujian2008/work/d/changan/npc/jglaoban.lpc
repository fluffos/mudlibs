// Write By Yanyang@SJ 2001.10.2
// NPC: /d/changan/jglaoban.c

inherit NPC;

void create()
{
        set_name("酒馆老板", ({"jiuguan laoban", "laoban" }) );
        set("gender", "男性" );
        set("title","酒醉中的");
        set("age", 35);
        set("long", "他已经醉得不象样子，你根本没办法和他买东西。\n");

        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set("combat_exp", 2000);
        set("str", 25);
        set("dex", 20);
        set("con", 15);
        set("int", 15);
        apply_condition("drunk",1000);
        set("attitude","heroism");
        
        setup();

        set("chat_chance", 5);
        set("chat_msg", ({
                "酒馆老板打了个嗝，一嘴的酒气。\n",
                "酒馆老板强睁开泛着血丝的眼睛，望了你一下。\n",
        }) );
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("coin", 100);
}

void init()
{
	if ( file_name(environment(this_object())) == this_object()->query("startroom")) {
		add_action("do_list","list");
		add_action("do_buy","buy");
	}
}	

int do_list()
{
	write("酒馆老板喷着满嘴酒气对你说道：不……不要买了……，一起……起喝点……\n");
	return 1;
}

int do_buy()
{
	write("酒馆老板喷着满嘴酒气对你说道：不……不要买了……，一起……起喝点……\n");
	return 1;
}
