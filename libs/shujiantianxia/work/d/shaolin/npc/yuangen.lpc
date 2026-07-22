inherit NPC;
#include <ansi.h>

void create()
{
       set_name("缘根和尚", ({ "yuangen", "heshang" }) );
       set("gender", "男性" );
       set("age", 50);
       set("long",
               "他是少林寺菜地管事，长的贼眉鼠眼！\n");
       set("combat_exp", 10000);
       set("attitude", "friendly");
              set("inquiry", ([
             "种菜" : "在这种菜都得听老子的，达摩院首座也是如此！\n",
              
       ]) );
       setup();

}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
       if( !ob || environment(ob) != environment() ) return;
         
       if(ob->query_temp("job_name")!="菜地种菜") return; 
        if(!(ob->query_temp("job_name")!="菜地种菜"))   
       {
        command("stare "+ob->query("id"));
       command("say " + RANK_D->query_respect(ob)
                               + "，你就在这浇粪"HIR"(jiao 粪)"NOR"吧。\n");
            }
}
