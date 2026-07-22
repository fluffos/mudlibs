//created by vikee
//2000.10
//huobing.c

#include <ansi.h>
inherit NPC;


void create()
{
   set_name("火部神兵", ({ "huo bing","bing"}) );
   set("race", "人类");
   set("age", 30);
   set("long", "太上老君的火部神兵.\n");
   set_level(120);
   set("daoxing",1500000);
   set_skill("pingtian-dafa",900);
   set_skill("force",900);
   set_skill("spells",900);
   map_skill("spells","pingtian-dafa");
   set("chat_chance_combat", 20);
   set("chat_msg_combat", ({
                (: cast_spell, "sanmei" :),
   }) );
   set("attitude", "aggressive");
   set_skill("dodge",940);
   set_skill("dragonstep",940);
   set_skill("huoyun-qiang",980);
   set_skill("spear",980);
   map_skill("spear","huoyun-qiang");
   map_skill("parry","huoyun-qiang");
   map_skill("dodge","dragonstep");
   set("env/test",({"HIB","HIR",})[random(2)]);
   set_temp("armor_level",90);
   set_temp("weapon_level",90);
   setup();
   carry_object(0,"armor",1)->wear();
   carry_object(0,"spear",1)->wield();
}

void die()
{
            if( environment() ) 
        message("sound", ""HIY"火部神兵消失在火海之中。"NOR"\n", environment());        
                destruct(this_object());
}


