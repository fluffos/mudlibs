 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("喜娘", ({ "wedding lady" }) );
        set("gender", "女性" );
        set("age", 50 );
        set("long",
"一个身穿红色吉服的老喜娘，正忙碌个不停。\n");
        set("combat_exp", 300);
        set("attitude", "friendly");
        set("per",10);
        set("chat_chance", 2);
        set("chat_msg", ({
                "喜娘小心翼翼地给白飞飞精心打扮着。。\n",
        }) );
        set_skill("unarmed",20);
        set_skill("dodge",100);
        setup();
        carry_object(__DIR__"obj/jifu")->wear();
}  
