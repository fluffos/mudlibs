inherit NPC;
#include "huoyannpc2.h"

void create()
{
   set_name("诩圣真君",({"xusheng zhenjun","zhenjun","xianguan","xian",}));
   set("long","负责保护玉皇大帝的天神，手下几个天王骁勇无比。.\n");
   set("per",23);
   set("str",30);
   set_level(130+random(10));
   set_skill("force",1300);
   set_skill("dodge",1300);
   set_skill("baguazhen",1300);
   set_skill("parry",1300);
   set_skill("spells",1300);
   set_skill("unarmed",1300);
   set_skill("wuxing-quan",1300);
   map_skill("unarmed","wuxing-quan");
   map_skill("parry","wuxing-quan");
   map_skill("dodge","baguazhen");
   set("mana_factor",80);
   set("force_factor",70);
   set("daoheng",2800000);
   setup();
   carry_object("/d/obj/cloth/jinpao")->wear();
}
