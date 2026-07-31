#include <ansi.h>
inherit NPC;  
void create()
{
        set_name("打水的妇人",({"woman"}));
        set("long", "一个衣衫不整的妇人，正在费劲地往羊皮酒袋里装水。\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 500000);
        set("gender","女性");
                
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",1000);
        set("neili",1000);
        set("force_factor",30);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "妇人说：你也多带点水吧，出了关就靠它了。\n"
        }) );
                
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/guanwai/npc/obj/wineskin");
        carry_object(__DIR__"obj/bucket");
        
}    
