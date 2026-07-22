// waiter1.c
#include <ansi.h>
inherit NPC;
void greeting(object ob);
void create()
{
        set_name("迎宾小姐", ({ "xiao jie", "xiao", "jie" }));
        set("long", "她是星际大酒店迎宾小姐，正笑容可掬的迎接着络绎不绝的人流。\n");
set ("title", HIB"星际大酒店"NOR);
        set("gender", "女性");
        set("age", 23);
        set("attitude", "friendly");
        set("shen_type", 1);

        set("per", 30);
        set("str", 15);
        set("int", 14);
        set("con", 15);
        set("dex", 16);
        set("qi", 200);
        set("max_qi", 200);
        set("jing", 200);
        set("max_jing", 100);
        set("neili", 300);
        set("max_neili", 300);
        set("combat_exp", 20000);

        set_skill("dodge", 90);
        set_skill("unarmed", 90);
        set_skill("parry", 90);

        set("chat_chance", 1);
        set("chat_msg", ({
                "迎宾小姐说道：欢迎光临星际大酒店!\n",
                        "迎宾小姐说道：祝您用餐愉快!\n",
        }) );

        setup();
        carry_object("/d/city/obj/qun")->wear();
}
