// hen.c
inherit NPC;
void create()
{
        set_name("老母鸡", ({ "hen" }) );
        set("race", "野兽");
        set("age", 1);
        set("long", "一只正在地上找食吃的老母鸡。\n");
        set("max_gin", 50);
        set("max_kee", 50);
        set("max_sen", 50);
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 1);
        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
	"老母鸡“咕咕...咯咯...”的叫了几声.\n"
	}));
}
void die()
{
        object ob;
        message_vision("\n$N凄惨的嚎了几声，死了。\n", this_object());
        ob = new(__DIR__"dead_ji");
        ob->move(environment(this_object()));
        destruct(this_object());
}