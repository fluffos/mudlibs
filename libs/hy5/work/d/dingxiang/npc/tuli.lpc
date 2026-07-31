
inherit F_MASTER;
inherit NPC;

#include <ansi.h>


int do_action1();

void create()
{
   set_name("突利",({ "tu li","tu","li" }) );
   set("gender", "男性" );		
   set("age",48);
   set("nickname","龙卷风");
   set("long", "他就是“龙卷风”突利，乃颉利之侄，武功高强。\n");       
   set("combat_exp",2500000);
   set_skill("dodge",300);
   set_skill("parry",300);
   set_skill("force",300);
   set_skill("club",350);
   set_skill("literate",200);
  
   set("max_jing",6000);
   set("max_qi",6000);
   set("max_sen",6000);
   set("neili",8000);
   set("max_neili",8000);
   create_family("突厥",3,"可汗");
    set("perform_quest/fengsha",1);
    set("perform_quest/fengyu",1);
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/fuying-spear")->wield();
  
}
