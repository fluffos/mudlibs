// /d/jinling/npc/xuezi.c

inherit NPC;

void create()
{
        set_name("学子", ({ "student" }) );
       set("str", 19);
        set("per", 26);
        set("age", 30);

        set("long",
                "一个普通的学子，可能在四处游玩。\n"
                "他不停的四出张望着。\n");

        set("chat_chance", 3);
        set("chat_msg", ({
                "学子说道：这里风景不错呀。\n",
                "学子走过来，走过去。\n",
                "学子说道：子曰........\n",
        }));
        setup();
        carry_object(__DIR__"obj/silk-cloth")->wear();
       add_money("silver", 80);
}
