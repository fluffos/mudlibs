#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("杜青莲",({"du qinglian","du"}));
        set("title",HIC"潇洒公子"NOR);
        set("long","
他脸色苍白，彷佛带著病容，但却笑容温和、举止优雅，服饰也极华贵。他的
身子虽然弱，虽然有病，可是人生中所有美好的事，他都能领略欣赏。他好像
对什么事都很有兴趣，所以他活得也很有趣。
\n");
        
        set("gender","男性");
        
        set("age",32);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",40);
        set("per",40);
        set("difficulty",10);
        set("reward_npc",1);
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",7500000);  
        set("attitude", "friendly");
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        
        set("death_msg",CYN"\n$N说：“善者不来，来者不善啊。”\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );      
        set("chat_chance",1);
        set("chat_msg",({
                name()+"曼声长吟：雪霁天晴朗，腊梅处处香。骑驴坝桥过，铃声响叮当。\n",
        }) );                   
        
        
        setup();
        carry_object(__DIR__"obj/qiucloth")->wear();
        carry_object(__DIR__"obj/dustick")->wield();    
    
}  
