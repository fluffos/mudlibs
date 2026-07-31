#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("ÓÄÔ¹¸¾ÈË", ({ "sad woman","woman" }) );
        set("gender", "Å®ÐÔ" );
        set("long",
                "Ò»¸ö³îÃ¼¿àÁ³£¬ÓôÓô¹Ñ»¶µÄ¸¾ÈË¡£\n"
                );
        set("title", WHT"ÌìÑÄ¹ÂÂÃ"NOR);
        set("attitude", "peaceful");
        set("age", 25);
        set("agi", 20);
        set("per", 20);
        set("combat_exp", 1200000);
        
        set("max_neili", 500);
        set("neili", 500);
        set("force_factor", 30);
        set_temp("apply/damage", 50); 
        set("chat_chance", 1);
        set("chat_msg", ({
                "ÓÄÔ¹¸¾ÈËà«à«Ò÷µÀ£ºÖª·ñ,Öª·ñ,Ó¦ÊÇÂÌ·ÊºìÊÝ!\n",
                }) ); 
        set_skill("unarmed", 180);
        set_skill("parry", 150);
        set_skill("dodge", 200);
        set_skill("doomforce", 210);
        set_skill("doomstrike", 150);
        set_skill("doomsteps", 150);
        map_skill("unarmed", "doomstrike");
        map_skill("dodge", "doomsteps");
        
        setup();
        carry_object("/d/tieflag/qianfo/npc/obj/lady_dress")->wear();
}      
