#include <ansi.h>
inherit ITEM;
#include "/quest/menpai/givegift.c"
void create()
{
        set_name(HIR"门派密件"NOR, ({ "mi jian"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("long",
                        "一封军机密件,记载着各个门派情况。最好把他销毁了(xiaohui)。\n");
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
	string msg;
 object ob;
int exp,pot,base_exp,a;
	int i;
	object fang,who,where;
        int count,add_exp;
        object *team,boss,me;
object maxpot,obj;
ob = this_object();
me = this_player();
	who=me;
	where = environment(who);
              
		me=this_player();
        ob=this_object();
		if(!arg||arg!="mi jian") return notify_fail("你要销毁什么？\n");
        if(ob->query("okname")!= me->query("id")
			||me->query("mjb2job")!="阻击")
		return notify_fail("这件事好像和你没关系吧?\n");
		
		if (!present("mi jian",me) )
        return notify_fail("你身上没有密件。\n"); 
        //check ok

        fang = present("sha shou",where);
	if(fang)
	{
		who->start_busy(3);
         return notify_fail("你先解决现有的强敌吧！\n");
	}

        fang = present("boss killer",where);
	if(fang)
	{
		who->start_busy(3);
 return notify_fail("你先解决现有的强敌吧！\n");
	}

    if( me->is_busy() )
	return notify_fail("你的动作还没有完成。\n");
    if( me->is_fighting() )
        return notify_fail("你正打得热闹呢!。\n");



		message_vision("$N从怀中掏出一只火折点燃了密件。\n"+HIR"只听「轰」的一声，密件在火中慢慢化为灰烬 。\n"NOR, me);
       count=me->query_temp("team_count");
		if (count<2) count=2;	
               
		team=me->query_team();
		count=sizeof(team);
		//write("\n"+sprintf("%d",count));
if (!count)
{
		     exp=random(888)+888;
		     pot=exp*2/3+random(200);

me->clear_condition("mjb2_busy");		
me->clear_condition("mp2_kill");
me->delete("quest");
me->delete("task_time");
me->delete("mjb2job");
me->delete_temp("team_count");	
addnl(me,"exp",exp);
if (random(3)==0) addnl(me,"mpgx",1);
}	

		for(i=0;i<count;i++)
		{ if(team[i]!=0)
		{
			if (team[i]->query_condition("mjb2_busy"))
			{ 
			 add_exp=100;
		     exp=random(888)+888;
		     pot=exp*2/3+random(200);
		     team[i]->delete_temp("team_count");
             if (environment(me)==environment(team[i])) addnl(team[i],"exp",exp);

;
team[i]->clear_condition("mjb2_busy");		
team[i]->clear_condition("mp2_kill");
team[i]->delete("quest");
team[i]->delete("task_time");
team[i]->delete("mjb2job");
team[i]->delete_temp("team_count");
			}
			} 
		}



    me->start_busy(3);
       
		  me->delete_temp("team_count");
         	  
		  destruct(this_object());
          return 1;
}

