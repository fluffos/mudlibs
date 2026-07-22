inherit NPC;
#include <ansi.h>
void create()
{
        set_name("马芳玲", ({ "ma fangling" }) );
        set("gender", "女性" );
        set("age", 18);
        set("title", HIW "万马堂"NOR);
        set("str", 6);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27);
        
        set("intellgent",1);
        set("attitude", "peaceful");
        set("chat_chance", 50);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("fly_target",1);
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 500);
        set("force", 500);
        set("max_mana", 300);
        set("mana", 300); 
        set("long",     "马空群的宝贝女儿。\n");  
        set("combat_exp", 999999); 
        set_skill("unarmed", 120);
        set_skill("throwing", 100);
        set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("literate", 70); 
        set_skill("demon-force", 100);
        set_skill("tigerstrike", 80);
        set_skill("demon-steps", 10); 
        map_skill("unarmed", "tigerstrike");
        map_skill("dodge", "demon-steps");
   map_skill("force", "demon-force"); 
        
                
        setup(); 
        //carry_object(__DIR__"obj/stone")->wield();
        carry_object("/d/xinjiang/npc/obj/blackcloth")->wear();
} 
void die()
{
        int i;
        object killer,owner; 
        if(objectp(killer = query_temp("last_damage_from"))) {
             if(owner=killer->query("possessed")) killer = owner;
             killer->set_temp("wanma/杀马芳玲_ma", 1);
        }
        
        ::die(); 

}
