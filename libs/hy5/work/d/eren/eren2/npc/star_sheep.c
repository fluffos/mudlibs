#include <ansi.h>
inherit NPC;  
void create()
{
        set_name(HIY"替补"NOR,({"guardian"}));
        set("age",30+random(20));
//      set("attitude", "aggressive");
        set("combat_exp", 5000000);
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

        set_name("叱石神君",({"chishi"}));
           set("title","十二星象");
        set("long", "“十二星相“从来不轻易出手，出手后从不空回。这一伙打家劫舍的强
盗，竟然都聚集在这里。此人这人一身白衣，弯着腰，驼着背，一张脸就像是倒悬的葫
芦，再加上一嘴山羊胡子，两只细眉小眼，就算将他放到山羊窝里去，也不会有人瞧出他是
人来。\n");
        
        setup();
        carry_object(__DIR__"obj/g_armor")->wear();
}    
