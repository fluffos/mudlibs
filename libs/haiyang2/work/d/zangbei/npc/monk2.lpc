#include <ansi.h>
//inherit NPC;
inherit NPC;

void create()
{ 
        set("long", "塔公寺的老喇嘛，衣着比起附近寺庙里的喇嘛差多了，愁眉苦脸地望着塔林出神。\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 2000000);
        set("dungeon_npc","eren");
                
        set("max_mana", 800);
        set("mana", 800);
        set("max_neili",1000);
        set("neili",1000);
        set("force_factor",30);
        set("class", "lama");
        
        set_skill("iron-cloth", 100);
        set_skill("staff", 100);

        set_skill("unarmed", 160);
        set_skill("lamaism", 100);
        set_skill("bloodystrike", 160);
        set_skill("force", 100);

        set_skill("spells",100);
        set_skill("parry",100);


        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"说：施主，布施点香火钱吧。\n",  
        }) );
        set("chat_chance_combat", 50);
    	set("chat_msg_combat", ({
            (: perform_action, "fefawubian" :),
            }) ); 
/*        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) ); */
         
//        auto_npc_setup();("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
       set_name("塔公寺的喇嘛",({"tagong lama","lama"}));
        set("force_factor",40+random(50));
        setup();
        carry_object(__DIR__"obj/lamacloth")->wear();
        
}  
int accept_object(object who, object ob){
        
        if (ob->query("value")<100000) {
                message_vision(CYN"老喇嘛脸上露出一丝失望，“嗯，多谢施主。”\n"NOR,this_object());
        } else if (ob->query("value")<500000) {
                message_vision(CYN"老喇嘛双掌合十，低头垂目：“嗯，多谢施主。”\n"NOR,this_object());
        } else {
                message_vision(CYN"老喇嘛的眼里忽然放出光来，话音也有些颤抖：“佛祖一定会保佑施主的。
老衲这就去让人重修佛塔，再塑金身。”\n"NOR,this_object());
                tell_object(who,WHT"听了老喇嘛的话你才注意到，原来这里的塔林久经风雨，已经十分破旧了。\n"NOR);
                who->set("zangbei/塔公寺施舍",1);
        }
        return 1;
}  
