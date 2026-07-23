 // garrison.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("邢锐", ({ "xing rui","rui" }) );
        set("long",
 "一个瘦小的老人，鹰勾鼻、三角眼满脸精明之色，双手上青筋盘蛇般
凸起，看来非但是个劳碌命，而且还练过鹰爪功一类的功夫。\n"); 
        set("attitude", "heroism");
        set("vendetta_mark", "authority");
    
        set("title", "济南府 总捕头");
        set("age",62); 
        set("str", 50);
        set("cor", 46);
        set("cps", 25);
        set("agi", 60); 
        set("max_qi", 3200);
        set("combat_exp", 5800000);
        set("max_force",10000);
        set("force_factor",100);
        set_skill("unarmed", 200);
        set_skill("claw", 100);
        set_skill("dodge", 300);
        set_skill("parry", 800);
  

        
        set("chat_chance", 1);
        set("chat_msg", ({
"邢总捕头用一双锐眼冷冷的看着你，似乎要将你看穿似的。\n",
        }) ); 
        setup();
    carry_object("/clone/misc/cloth")->wear(); 
}  
void greeting(object ob)
{
   if( !ob || environment(ob) != environment() ) return;
        if(ob->query("class")!="official" && random(2)==0)
        {
                message_vision("邢总镖头对$N说道：“衙门乃官府重地，岂容你来此放肆，左右与我打出！”\n",ob);
                message_vision("衙役将$N乱棒打出。\n",ob);
                ob->move("/d/jinan/street5");
        }
} 
void init()
{
        ::init();
        if( interactive(this_player()) ) {
                remove_call_out("greeting");
                call_out("greeting", 1, this_player());
        }        
}       
