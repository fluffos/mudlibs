//created by vikee
//2000.10

#include <ansi.h>
inherit NPC;

void create()
{
   set_name("火鸦", ({ "huo ya","ya","huoya" }) );
   set("race", "野兽");
   set("age", 500);
   set("long", "太上老君的火部神兵之火鸦.\n");   
   set("attitude", "aggressive");
   set_skill("dodge",940);
   set_skill("dragonstep",940);
   set_skill("dragonfight",980);
   set_skill("parry",980);
   set_skill("unarmed",980);
   map_skill("unarmed","dragonfight");
   map_skill("parry","dragonfight");
   map_skill("dodge","dragonstep");
   set("limbs", ({ "头部", "身体", "脚爪", "尾巴","翅膀"}) );   
   set_level(100);
   set("daoxing",1500000);
   set_skill("pingtian-dafa",900);
   set_skill("force",900);
   set_skill("spells",900);
   map_skill("spells","pingtian-dafa");
   set("chat_chance_combat", 20);
   set("chat_msg_combat", ({
                (: cast_spell, "sanmei" :),
   }) );
   setup();
}


void die()
{
	if( environment() ) 
        	message("sound", ""HIY"火鸦消失在火光之中。"NOR"\n", environment());        
	destruct(this_object());
}