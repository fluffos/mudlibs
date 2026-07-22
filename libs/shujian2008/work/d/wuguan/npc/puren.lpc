//puren.c
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("仆人", ({ "pu ren", "puren","ren" }) );
        set("gender", "男性" );
        set("age", 20);
        set("long","这是个仆人打扮的年青人，两眼乱转，四处看个不停。\n");
        set("attitude", "peaceful");
        set("combat_exp",1000+random(500));
        
        set("inquiry", ([
                "做事" :  "你去找大师兄吧！\n",
                "工作" :  "你去找大师兄吧？\n",
                "好处" :  "我可不想告诉你.\n",
               ]) );

        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("silver", 1);
}
