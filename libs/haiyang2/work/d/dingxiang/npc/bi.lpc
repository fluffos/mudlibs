
//Edit By Subzero

inherit NPC;
#include <ansi.h>

string do_quest();
string move_room();
int do_action1();

void create()
{
   int i;
   object *ob;
   set_name("毕玄",({ "bi xuan","bi" }) );
   set("gender", "男性" );		
   set("age", 42);
   set("long", "他就是武尊毕玄，域内外三大宗师之一\n");
       
   set("combat_exp",8000000);
   set("str", 35);
   set("per", 22);
   set_skill("unarmed",400);
   set_skill("dodge",400);
   set_skill("parry",400);
   set_skill("force",500);
   set_skill("blade",400);
   set_skill("literate",400);
   set_skill("cuff",500);
   set_skill("club",400);

   
   set("gin",6000);
   set("max_jing",6000);
   set("kee",6000);
   set("max_qi",6000);
   set("sen",6000);
   set("max_sen",6000);
   set("neili",15000);
   set("max_neili",15000);
   set("jiali",150);
   create_family("突厥",2,"武尊");

   set("apply_points",2000);

   setup();
   carry_object(__DIR__"obj/cloth")->wear();

   carry_object(__DIR__"obj/yinlong-spear")->wield(); 
}

