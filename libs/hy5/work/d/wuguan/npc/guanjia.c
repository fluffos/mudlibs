
inherit NPC;

void create()
{
       set_name("柴房管事", ({ "chaifang guanshi", "guanshi" }) );
       set("gender", "男性" );
       set("age", 50);
       set("long",
               "他是襄阳武馆的一个小管家，专管柴房！\n");
       set("combat_exp", 2500);
       set("attitude", "friendly");
              set("inquiry", ([
             "劈柴" : "你就在这老老实实劈柴，我不满意，你就别想回去覆命！",
	       
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
         
       if(!(ob->query_temp("job_name"))) return; 

       if (!( present("chaidao", this_player())))
       {
        command("hmm "+ob->query("id"));
        command("say 你还没领工具吧，去东物品房找老李要。 \n");
        return;
        }

        if(!(ob->query_temp("job_name")!="劈柴"))   
       {
        command("nod "+ob->query("id"));
       command("say " + RANK_D->query_respect(ob)
				+ "，你就在这劈柴（pi 柴）吧。\n");
            }
}