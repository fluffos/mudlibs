// little_monkey.c

inherit NPC;

void create()
{
	set_name("小猴",({ "little monkey", "monkey"}) );
        set("race", "野兽");
        set("age", 7);
        set("long", "这是一只调皮的小猴子，虽是畜牲，却喜欢模仿人样。\n");
        set("limbs", ({ "头部", "身体", "爪子", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 50);
	set("shen_type", -1);
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
        set("attitude", "peaceful");
        set("chat_chance", 20);
        set("chat_msg", ({
                        "小猴吱吱的叫着，不时的东张西望。\n",
                        (: random_move :),
                        }));
        setup();
}
