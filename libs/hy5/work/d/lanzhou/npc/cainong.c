// cainong.c

inherit NPC;

void create()
{
        set_name("菜农", ({ "cainong", "nong" }) );
        set("gender", "男性" );
        set("age", 33);
        set("long", "一个散发着汗臭的菜农，一张脸由于经常被太阳暴晒而发红。\n");
        set("attitude", "friendly");
        set("combat_exp", 250);
//	set("shen", 50);
	set("shen_type", 1);
        set("str", 20);
        set("dex", 18);
        set("con", 17);
        set("int", 13);
        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
"菜农兴奋的说，今天我的菜卖的好极了。\n",
"菜农一边收拾自己的担子，一边道；妹妹你在家头啊！哥哥在城头，恩恩爱爱白头到老。 \n",
//                (: random_move :)
        }) );
        carry_object(__DIR__"obj/cloth")->wear();
}

