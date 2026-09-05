// /d/xingxiu/npc/woman.c
// Jay 3/17/96

inherit NPC;

void create()
{
        set_name("回族妇女", ({ "woman" }) );
        set("gender", "女性" );
        set("age", 40);
        set("long", "一个很胖的回族中年妇女。\n");
        set("shen", 1000);
        set("combat_exp", 150);
        set("env/wimpy", 60);
        set("chat_chance_combat", 50 );
        set("str", 13);
        set("dex", 12);
        set("con", 14);
        set("int", 13);
        set("attitude", "friendly");
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
                "回族妇女看着你笑了起来\n",
                "回族妇女向你努了努嘴，又指了指西北方向。\n",
        }) );
        carry_object(__DIR__"obj/wcloth")->wear();
        add_money("coin", 100);
}

