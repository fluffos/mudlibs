#include <ansi.h>
inherit NPC;
void create()
{ 
        set_name("恶人窟弟子", ({ "dizi"}) );
        set("long", "这是一位恶人窟专门担任巡护之责的弟子。\n");
        set("attitude", "friendly"); 
        set("max_atman", 100);
        set("atman", 100);
        set("max_mana", 100);
        set("mana", 100);
        
        set("cor", 30);
        set("cps", 25); 
        set("combat_exp", 5000000);
        set_skill("sword", 250);
        set_skill("parry", 250);
        set_skill("dodge", 250);
        set_skill("move", 250); 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
} 
/*
void init()
{
 if( interactive(this_player()) && !is_fighting() && !random(4)&& this_player()->query("class")!="bat") {
  message_vision("\n$N忽然对$n大喝一声：什么人竟敢在此乱闯！看剑！\n",this_object(),this_player());
  this_object()->kill_ob(this_player());
 }
}
*/    
