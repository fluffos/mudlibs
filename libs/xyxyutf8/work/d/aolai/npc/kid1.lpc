
inherit NPC;

void create()
{
       set_name("小男孩", ({"kid"}));
       set("gender", "男性");
        set_level(1);
       set("age", 8);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("chat_chance", 10);
        set("chat_msg", ({
            "小男孩对你嘻嘻地傻笑了几声。\n",
            (: random_move :)
        }) );
        setup();
	add_money("coin", 10+random(50));
}

