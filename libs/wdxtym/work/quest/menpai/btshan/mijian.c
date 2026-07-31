#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"门派密件"NOR, ({ "mi jian"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("long",
                        "一封军机密件,记载着各个门派情况。\n");
                set("value", 0);
                set("material", "paper");
		 
         }
}
void init()
{    
	add_action("do_xiaohui", "xiaohui");
}

int do_xiaohui(string arg)
{
        int i,exp,pot,count,base_exp,add_exp;
        object ob,me,*team;
              
		me=this_player();
        ob=this_object();
		if(!arg||arg!="mi jian") return notify_fail("你要销毁什么？\n");
        if(ob->query_temp("host")!= me->query("id")
			||!me->query_condition("mjb_busy")||!me->query_temp("team_count"))
		return notify_fail("这件事好像和你没关系吧?\n");
		if (!present("mi jian",me) )
        return notify_fail("你身上没有密件。\n"); 
        //check ok
		message_vision("$N从怀中掏出一只火折点燃了密件。\n"+HIR"只听「轰」的一声，密件在火中慢慢化为灰烬 。\n"NOR, me);
        count=me->query_temp("team_count");
		if (count<2) count=2;	
        base_exp=3000/count;
		team=me->query_team();
		count=sizeof(team);
		//write("\n"+sprintf("%d",count));
		for(i=0;i<count;i++)
		{ if(team[i]!=0)
		{
			if (team[i]->query_condition("mjb_busy"))
			{if(!team[i]->query("mjb_job_count"))
		     team[i]->set("mjb_job_count",1);
             else
		     team[i]->add("mjb_job_count",1);  
			 add_exp=team[i]->query("mjb_job_count")/10;
		     exp=base_exp+random(600)+add_exp+500;
		     pot=exp*2/3+random(200);team[i]->delete_temp("team_count");
             if (environment(me)==environment(team[i])) team[i]->add("potential",pot);
             if (environment(me)==environment(team[i])) team[i]->add("combat_exp",exp);
 		       tell_object(team[i],HIW"你被奖励了：\n" + 
                       chinese_number(exp) + "点实战修为\n" +
                       chinese_number(pot) + "点潜能\n"+
                       NOR);
			 team[i]->delete_temp("team_count");
			}
			} 
		}
		  me->delete_temp("team_count");
         	  
		  destruct(this_object());
          return 1;
}

