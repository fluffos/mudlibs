// Write By Yanyang@SJ 2001.10.2
// Animal : /d/changan/npc/fenggou.c

inherit NPC;

void create()
{
        set_name("疯狗", ({ "feng gou", "dog", "gou" }) );
        set("race", "野兽");
        set("age", 4);
        set("unique", 2);
        set("long", "它浑身没有一处干净的地方，眼睛血红血红的。\n");
        set("attitude", "peace");
        set("shen_type", -1);

        set("limbs", ({ "狗头", "狗身", "前爪", "后爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 5000);

        set_temp("apply/attack", 10);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 30);

        setup();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player())
	&& random(ob->query_per()) < 10 
	&& random(10)) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}
