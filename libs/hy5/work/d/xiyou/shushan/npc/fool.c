//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("笨鬼", ({ "fool" }));
        set("title", "思考几百年");
        set("age", 50);
        set("attitude", "peaceful");
        set("int", 1);
        set("per", 10);
        
        set("max_qi", 2000);
        set("max_jing", 2000);
        set("chat_chance", 20);
        set("chat_msg", ({
                "笨鬼喃喃道：“我想了几百年，到底我该先踏出右脚还是先踏出左脚呢？你能回答(answer)我吗？”\n",
        }));
   add_temp("apply/damage", 20);
   add_temp("apply/armor", 20);
        setup();
}

