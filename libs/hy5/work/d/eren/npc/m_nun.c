#include <ansi.h>
#include <command.h>
#include <condition.h> 
inherit NPC;
//inherit NPC;   
void create()
{ 
        set_name("扫地的中年女尼",({"middle aged nun","nun"}));
        set("long", "一个三四十岁的女尼，正在门前打扫落叶，清秀的脸上隐隐露出愁苦之色。\n");
        set("age",39);
        set("gender", "女性");
        set("combat_exp", 3500000);
         set("attitude", "friendly");
        
        set("max_atman", 700);
        set("atman", 700);
        set("max_mana", 1250);
        set("mana", 1250);
        set("max_neili",1200);
        set("neili",1200);
        set("force_factor",90); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
            set_skill("unarmed", 150);
  
    set_skill("sword", 200);

    set_skill("parry", 160);
    set_skill("dodge", 200);
  
        set("no_fly",1);
        
        set("resistance/gin",15);
        set("resistance/kee",25);
        set("resistance/sen",20);
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
//      set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
 

        setup();
        carry_object("/clone/misc/cloth")->wear();
}      
