
inherit F_MASTER;
inherit NPC;

#include <ansi.h>

int do_action1();

void create()
{
   int i;
   object *ob;
   
   set_name("可达志",({ "ke dazhi","ke" }) );
   set("gender", "男性" );		
   set("age", 30);
   set("combat_exp",6500000);

   set_skill("dodge",300);
   set_skill("parry",300);
   set_skill("force",300);
   set_skill("blade",350);
   set_skill("literate",200);


   set("max_jing",6000);
   set("max_qi",6000);
   set("max_sen",6000);
   set("neili",8000);
   set("max_neili",8000);
   
   set("inquiry",([
     "考验":(:do_action1:),
     ]));
   
   create_family("突厥",3,"武士");

    set("apply_points",200);
   
   setup();
  
   carry_object(__DIR__"obj/kuangsha-dao")->wield();  
}
