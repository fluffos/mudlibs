#include <ansi.h>
inherit NPC;  
void create()
{
        set_name(HIY"替补"NOR,({"guardian"}));
        set("attitude", "aggressive");
        set("combat_exp", 6500000);
        set("dungeon_npc","eren2");
        
        set("max_atman", 3000);
        set("atman", 3000);
        set("max_mana", 3000);
        set("mana", 3000);
        set("max_neili",4000);
        set("neili",4000);
        set("force_factor",60);
        
        set("resistance/gin",60);
        set("resistance/kee",60);
        set("resistance/sen",60);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                
        }) );
        

        set_name(HIB"魏麻衣"NOR,({"wei mayi"}));
        set("long", "枯瘦颀长，宛如竹竿，脸上碧油油的像是戴了层面具，令人一见就要
起鸡皮疙瘩，一见就要怍呕。\n");
        
        setup();
        carry_object(__DIR__"obj/j_cloth")->wear();
}    
