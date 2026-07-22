// /d/xingxiu/npc/woman.c
// Jay 3/17/96

inherit NPC;

void create()
{
        set_name("维吾尔族妇女", ({ "woman" }) );
        set("gender", "女性" );
        set("age", 40);
        set("long", "一个很胖的维吾尔族中年妇女。\n");
        set("shen", 1000);
        set("combat_exp", 150);
        set("env/wimpy", 60);
        set("str", 13);
        set("dex", 12);
        set("con", 14);
        set("int", 13);
        set("attitude", "friendly");
        setup();
        set("chat_chance", 2);
        set("chat_msg", ({
                "维吾尔族妇女看着你笑了起来。\n",
                "维吾尔族妇女说道：小波郎子呀克西。\n",
                "维吾尔族妇女向你努了努嘴，又指了指北边。\n",
        }) );
        carry_object(ARMOR_D("wncloth"))->wear();
        add_money("coin", 100);
}
