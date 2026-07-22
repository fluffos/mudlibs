// little_monkey.c

inherit NPC;

void create()
{
	set_name("小猴",({ "xiao hou","xiao" }) );
        set("race", "野兽");

        set("age", 4);
        set("long", "这是一只调皮的小猴子，虽是畜牲，却喜欢模仿人样。\n");
        set("combat_exp", 1000+random(2000));
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
        set("attitude", "peaceful");

	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}) );
        setup();
}
