#include <ansi.h>
inherit NPC;  
void create()
{
        set_name(HIY"替补"NOR,({"guardian"}));
        set("long", "这是一个专门打劫行商的马贼，不知为什么躲在这里。\n");
        set("age",30+random(20));
        set("attitude", "aggressive");
        set("combat_exp", 1000000);
        set("dungeon_npc","eren");
                
        set("max_mana", 800);
        set("mana", 800);
        set("max_neili",1000);
        set("neili",1000);
        set("force_factor",30);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        }) );

        set_name("马贼",({"bandit"}));
        set("force_factor",40);
        setup();
        carry_object(__DIR__"obj/oldcloth")->wear();
        carry_object(__DIR__"obj/niren");
        
}  
void init() {
   
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}  
void greeting(object ob) {
        
        if( !ob || environment(ob) != environment() ) return;
        message_vision(CYN"$N喝道：什么人！“\n"NOR,this_object());
}   
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        if (me)
        if(!me->query_temp("eren/bandit_2") 
                && me->query_temp("eren/bandit_1"))
        {
                me->set_temp("eren/bandit_2",1);
        }
        ::die();
}
            
