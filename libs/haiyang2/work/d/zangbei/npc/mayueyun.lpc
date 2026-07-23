#include <ansi.h>
//inherit NPC;
inherit NPC;
int estate();
void create()
{
        set_name("马月云",({"ma yueyun","ma"}));
        set("title","温柔贤惠");
        set("long","
马方中的太太很贤慧、菜烧得很好，所以马方中一天比一天发福，到了中
年后，已是个不大不小的胖子。马太太无论说什么，马方中都千依百顾。
村子里的老太太，小媳妇们，都在羡慕马太太。一定是上辈子积了德，所
以才嫁到这样一位好丈夫。\n");
        
        set("gender","女性");
        set("group","ma");
        
        set("age",32);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",40);
        set("marry","马方中");
        set("marry_name","ma fangzhong");
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",500000);  
        set("attitude", "friendly");
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
                "*":    "我很少出门，你问的这些我都不知道呀。\n",
           ]));
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(30) :),
        }) );*/
        set("chat_chance",1);
        set("chat_msg",({
                "马月云看了看身边的一双儿女，心满意足地笑着。\n",
        }) );                   
        
                
        setup();
        carry_object("/clone/misc/cloth")->wear();
 
}      
