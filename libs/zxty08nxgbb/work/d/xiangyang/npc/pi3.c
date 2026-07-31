// pi.c 裨将 朱雀内门
#include <ansi.h>
inherit NPC;


void create()
{
	set_name("裨将", ({ "pi jiang", "pi", "jiang" }));
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "这是一个大宋年轻将领，满脸征尘。\n");
	set("combat_exp", 45000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("sword", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);

	setup();
	carry_object("/d/city/obj/changjian")->wield();
	carry_object("/d/city/obj/tiejia")->wear();
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
//        if( !ob ) return;
        if( !ob || environment(ob) != environment() ) return;
    	if(ob->query_temp("start_job")==1)
	{
              say( "裨将皱了皱眉：这位" + RANK_D->query_respect(ob)
                                + "，你还是安心守城吧。\n");
	}	
        else if(ob->query_temp("mark/job_shadi")==3)                        
        {
        	say( "裨将拱手说道：这位" + RANK_D->query_respect(ob)
                                + "，你来得正是时候，蒙古靼子已经快攻上城了。\n");
               ob->apply_condition("jobshadi_limit", 5+random(5));
    		ob->set_temp("start_job",1);     
               ob->set_temp("where",environment(ob));
       		call_out("to_rob",10,ob);
    	}
    	if(ob->query_temp("job_over")==1)
	{
              say( "裨将拱手说道：这位" + RANK_D->query_respect(ob)
                                + "，你已经可以回去复命了。\n");
	      return;
	}                                


}

void to_rob()
{
        object *target,robber,room;
        mapping my_fam  = this_player()->query("family");                  
        int i;
        target=users();  
  	room = environment(this_player());
  	if(this_player()->query_temp("start_job")==0)
  	return;
  	if(this_player()->query_temp("start_job")==1)
        {
        	for(i=0;i<sizeof(target);i++)
		{
	        	if(target[i]->query("family/family_name") == my_fam["family_name"]&&target[i]->query("id")!=this_player()->query("id"))
	        	message("vission",HIR"一只浑身鲜血的鸽子飞到你面前传给你一张纸条：\n"HIW"╔══════════════════════════╗
║          蒙古靼子入侵中原，"+room->query("short")+"吃紧！          ║\n╚══════════════════════════╝ \n                              "+NOR+CYN+this_player()->query("family/family_name")+" "+this_player()->query("name")+"("+this_player()->query("id")+")\n" NOR,target[i]);  
		}
	}
if( environment(this_player())->query("short")=="朱雀内门")
{
		robber=new(__DIR__"robber1");
                robber->do_change(this_player());
  		robber->move(room);
  		message_vision(HIR"突然城下爬上来一个蒙古兵士。\n" NOR,this_player()); 
  		robber->kill_ob(this_player());
            this_player()->kill_ob(robber);
}
}
