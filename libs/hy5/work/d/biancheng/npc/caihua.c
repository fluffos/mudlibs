#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";
 inherit NPC;
void create()
{ 
        set_name("采花蜂",({"caihua feng","caihua"}));
        set("title",WHT"江湖五毒"NOR);
        set("long", "这人的眼皮在跳，脸上却还是带着微笑——这笑容本就是刻在脸上的。。\n");
        set("age",39);
        set("gender","男性");
        set("combat_exp", 7000000);
         set("attitude", "aggressive");
        
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",2000);
        set("neili",2000);
        set("force_factor",100); 
        set("str",40);
          set("reward_npc", 1);
       set("difficulty", 20);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
         set_skill("unarmed", 220);
        set_skill("throwing", 100);
        set_skill("dodge", 200);
        set_skill("force", 230);
        set_skill("literate", 270); 
        set_skill("demon-force", 200);
        set_skill("demon-strike", 280);
        set_skill("demon-steps", 210); 
        map_skill("unarmed", "demon-strike");
        map_skill("dodge", "demon-steps");
   map_skill("force", "demon-force"); 

        set("no_fly",1);
        
        set("resistance/gin",30);
        set("resistance/kee",50);
        set("resistance/sen",40);
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
        set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
       set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                 (: perform_action, "unarmed.dimo" :),
                (: perform_action, "unarmed.renmo" :),
                (: perform_action, "unarmed.tianmo" :),
                (: exert_function, "mihun" :),

        }) );
         
/*        CHAR_D->setup_char(this_object());
        auto_npc_setup("liaoyin",250,200,1,"/obj/weapon/","fighter_w","tanzhi-shentong",1);
*/
        setup();
        carry_object("/clone/misc/cloth")->wear();
}  
int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
} 
void leave()
{
        object another;
        message("vision",name() + "诡异地一笑，又成了那个满脸堆笑的陈大倌。\n", 
                environment(),this_object() );
        another = new(__DIR__"bosschen");
        another->move(environment(this_object()));
        destruct(this_object());
}  
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        if(me->query("wanma/棺材之谜"))
                        me->set_temp("wanma/江湖五毒b",1);
        ::die();
}     
