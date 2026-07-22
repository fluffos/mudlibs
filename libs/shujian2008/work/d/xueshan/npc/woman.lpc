// woman.c

inherit NPC;

void create()
{
        set_name("妇女", ({"woman", "funv" ,"nv","fu"}) );
        set("gender", "女性" );
        set("age", 35);
        set("long", "一个中年妇女，满面愁容，看来正受到生活的压迫，鬓边已见几缕白发。\n");

        set_skill("unarmed", 15);
        set_skill("dodge", 15);
        set_skill("parry", 15);
        set("combat_exp", 300);
	set("shen_type", 0);
        set("str", 15);
        set("dex", 10);
        set("con", 15);
        set("int", 15);
        set("attitude","friendly");
	set("unique", 1);

        setup();
        set("chat_chance", 1);
        set("chat_msg", ({
		"妇女摇了摇怀里抱着的孩子，叹了口气。\n",
                "妇女揭开衣襟，把乳头塞进孩子的嘴里，孩子渐渐停止哭闹，吸吮起来。”\n",
		"妇女怀里的孩子伸拳踢腿，奶声奶气的哭了起来。\n",
        }) );
        carry_object(ARMOR_D("pipao"))->wear();
}
