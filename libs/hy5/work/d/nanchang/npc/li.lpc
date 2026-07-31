#include <ansi.h>

inherit NPC;

void create()
{
   set_name("李财主",({ "li caizhu","li","caizhu" }) );
        set("gender", "男性" );
        set("age", 52);
   set("long", "这是南昌的大富李财主，近来他正在为女儿举办比武招亲。\n");
       
   set("combat_exp", 50000);
   set("str", 10);
   set("per", 22);
   set("attitude", "friendly");

   set("chat_chance",80);
   set("chat_msg",({
	   (:random_move:),
   }));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
  
}

