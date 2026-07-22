// Write By Yanyang@SJ 2001.9.27
// NPC: /d/changan/dashou.c

inherit NPC;

void create()
{
        set_name("打手", ({"da shou", "dashou" }) );
        set("gender", "男性" );
        set("age", 27);
        set("long", "这是长安万红楼雇用的打手，面无表情。\n");

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set("combat_exp", 10000);
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        setup();

        set("chat_chance", 2);
        set("chat_msg", ({
		"打手双手攥在一起，将骨节捏得“咯咯”直响。\n",
        }) );
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("coin",50);
}
