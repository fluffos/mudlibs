#include <ansi.h>
inherit NPC; 
void create()
{
        int basic=400;
        int special=200;
                
        set_name("阿修罗王",({"xiuluo"}));
        set("title",YEL"魔教 八长老之"NOR);
        set("long", "这人好像笼罩在一团火中，全身闪闪火光，热焰扑人。\n");
        set("age",100+random(20));
//      set("attitude", "aggressive");
        set("combat_exp", 10000000);
        set("dungeon_npc","eren2");
        set("no_fly",1);
        set("boss",1);
                
        set("resistance/gin",50);
        set("resistance/kee",50);
        set("resistance/sen",50);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("max_atman", 2000);
        set("atman", 2000);
        set("max_mana", 2000);
        set("mana", 2000);
        set("max_neili",3000);
        set("neili",3000);
        set("force_factor",130);
        set("str",45);
        
   
        
        setup();
        carry_object(__DIR__"obj/g_armor")->wear();
}     
