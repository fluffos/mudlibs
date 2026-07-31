#include <ansi.h>
inherit NPC;

void create()
{
	set_name("日本浪人", ({ "japanese" }) );
	set("gender", "男性" );
	set("age", 30);
        set("long","这是一个无恶不做的日本浪人, 腰中挎着日本刀四处寻找花姑娘。\n");
	set("chat_chance_combat",25);
	set("chat_msg_combat", ({
"日本浪人对你来了一个九十度的大鞠躬：哈依, 你的大大的厉害, 我的小小的干活。\n",
	}));
        set_skill("blade",10);
        set_skill("riblade",10);
        map_skill("blade","riblade");	
	setup();
	carry_object("/d/hua/obj/he_cloth")->wear();
	carry_object("/d/hua/obj/blade")->wield();
}

int do_killing(string arg)
{
	object me, victim, weapon;
	string skill_type;
	me = this_player();
	if (objectp(victim = present(arg, environment(this_object()))) && 
            living(victim)) {
		set("combat_exp", me->query("combat_exp"));
		set_skill("dodge", me->query_skill("dodge"));
                set_skill("renshu",me->query_skill("dodge"));
                map_skill("dodge","renshu");
		set_skill("parry", me->query_skill("parry"));
		if (objectp(weapon = me->query_temp("weapon")))
			skill_type = weapon->query("skill_type");
		else skill_type = "unarmed";
		set_skill("blade", me->query_skill(skill_type));
                set_skill("riblade",me->query_skill(skill_type));
                map_skill("blade","riblade");
		this_object()->kill_ob(me);
		return 0;
	}
	return 0;
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_killing", "kill");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
	if (ob->query("gender") == "女性")
		message_vision("日本浪人一见$N走进来两只眼睛泛着绿光, 说道：花姑娘的大大的好, 我的朋友的干活…\n"
"说话间口水流出老长…, 噢, 好恶心耶!!!\n", ob);
	else
		say("日本浪人一见有人过来, 眼睛笑成了一条缝：花姑娘的哪里的有? 说了大大的好, 不说死了死了的。\n");
}

int accept_fight(object me)
{
	set("combat_exp", me->query("combat_exp"));
	return 1;
}
