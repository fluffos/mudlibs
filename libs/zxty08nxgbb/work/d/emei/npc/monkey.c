// monkey.c 

inherit NPC;

void create()
{
	set_name("大马猴", ({ "ma hou","monkey"}) );
        set("race", "野兽");
	set("age", 8);
	set("long",
		"这只猴子在不停的跳上跳下，还不时津津有味地啃几口着蜜桃。\n");
     
        set("limbs", ({ "头部", "身体", "爪子", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 500);
        set("shen_type", -1);
	set("attitude", "peaceful");
	set("chat_chance", 20);
        set("chat_msg", ({
                        "大马猴不停的跳上跳下，还不时津津有味地啃几口着蜜桃。\n",
                        (: random_move :),
           }));setup();
}
