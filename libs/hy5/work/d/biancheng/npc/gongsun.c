#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";  
inherit NPC;
void create()
{
    set_name("公孙断",({"gongsun duan","gongsun"}));
    set("title","虬髯巨汉");
    set("long","这人满脸虬髯，一身白衣，腰里系着一尺宽的牛皮带，皮带上斜插着把银鞘乌柄的
奇形弯刀，手里还端着杯酒。酒杯在他手里，看来并不太大，但别的人用两只手也
未必能捧得住。\n");
        set("gender","男性");
        set("age",42);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",4000000);  
        set("attitude", "friendly");
        
        
        set("death_msg",CYN"\n$N满眼泪水地看了一眼屋子里的家具。。。。 \n"NOR);         
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );*/
        set("chat_chance",1);
        set("chat_msg",({
                "虬髯巨汉点点头，道：“我叫公孙断，我是个粗人，请进。”\n"
        }) );                   
           
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
    
}   
void die()
{
        int i;
        object killer,owner; 
        if(objectp(killer = query_temp("last_damage_from"))) {
             if(owner=killer->query("possessed")) killer = owner;
             killer->set_temp("wanma/杀公孙断_ma", 1);
        }
        
        ::die(); 

}
