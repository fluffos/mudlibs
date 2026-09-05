//yudao.c
//made by hacky
#include <ansi.h>
inherit NPC;

void create()
{
   set_name("浴堂道童",({"daotong","dao"}));
   set("title",HIB"全真派"NOR+YEL"道童"NOR);
   set("long",
"他是全真教的小道童.\n"
      );

   set("age",18);
   set("gender","男性");
   set("combat_exp",3000);
   set("attitude","friendly");
   set("shen_type",1);set("score",200);setup();
  }
 
void init()
{
   object ob;
   ::init();
   if(interactive(ob=this_player())&&!is_fighting() ) {
     remove_call_out("greeting");
        call_out("greeting",1,ob);
  }
}

void greeting(object ob)
 {
  if(!ob||environment(ob)!=environment() ) return;
    command("say"+RANK_D->query_respect(ob)+"进来洗个澡吧");
  }

int accept_object(object who,object ob)
{
   if(ob->query("money_id")&&ob->value()>=1000) {
   tell_object(who,"浴堂道童说道:请进!");
   who->set_temp("have_paid",1);
    return 1;
 }
    return 0;
 }

