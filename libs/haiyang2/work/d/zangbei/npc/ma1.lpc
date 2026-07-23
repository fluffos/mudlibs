#include <ansi.h>
//inherit NPC;
inherit NPC;
void create()
{
        set_name("马小宝",({"ma xiaobao","xiaobao"}));
        set("long","
小宝和小贝是马方中的一双心肝宝贝，无论他们要什么几乎全都有求必应，
就算做错事，马方中也没有责备过他们一句。只要一空下来，就会陪他们到
处去玩。\n");
        
        set("gender","女性");
        set("group","ma");
        
        set("age",10);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
                
        
        set("combat_exp",50000);  
        set("attitude", "friendly");
        
        set("inquiry", ([
                "*":    "有事儿去问我爸我妈吧。\n",
        ]));
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(30) :),
        }) ); */
        set("chat_chance",1);
        set("chat_msg",({
                "马小宝跳跳蹦蹦地从里屋奔到外屋，又从外屋冲进里屋。\n",
        }) );                   
        
                
   setup();
        carry_object("/clone/misc/cloth")->wear();
 
}        
