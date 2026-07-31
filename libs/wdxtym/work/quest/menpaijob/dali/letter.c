#include <ansi.h>
inherit ITEM;
void to_rob();
void create()
{
        set_name(HIR"军机信件"NOR, ({"xin", "letter"}));
        set("long",
               "这是大理段家托付你的重要信件。\n");
        set("unit", "封");
        set("weight", 5);
        set("no_drop", 1);
        set("no_get", 1);

        setup();
}

void init()
{
        add_action("do_sendto","sendto");
	remove_call_out("go");
	call_out("go",0);	
}

int do_sendto(string arg)
{
object ob=this_object(),me=this_player();
string targ;
int exp,pot;
int i;
        if (!arg||!ob=present(arg,environment(me)))
                return notify_fail("你要把信送给谁？\n");
        targ=ob->query("name");
if ( targ != me->query("quest/quest") ) return notify_fail("这是送给"+me->query("quest/quest")+"的信，你怎么能随便乱给呢？\n");
        if (userp(ob)) return notify_fail("你弄错人了吧？\n"); //玩家可能有相同于NPC的名字
    if(me->is_busy())
        return notify_fail("你现在正忙。\n");
     if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");

  if (random(100)<30&& !environment(this_player())->query("no_fight") )
	{	
        if (this_object()->query_temp("tufei")<1 && !environment(this_player())->query("no_fight")
         && !this_player()->is_fighting())
	{
		to_rob();
		this_object()->add_temp("tufei",1);
                this_player()->start_busy(1);
	}
		return 1;
	}

        if ( (int) me->query("task_time") < time() )
        {
             return notify_fail(targ+"冷冷地说：“你来晚了,耽误了我的大事，你还有脸来见我！”\n");
        }
        tell_object(me,"你把信交给了"+targ+"。\n" NOR );
        exp=me->query("quest/exp_bonus");
        pot=me->query("quest/pot_bonus");
i=this_object()->query_temp("tufei");
if (i>0)
{
        exp=me->query("quest/exp_bonus")+60+i*60;
        pot=me->query("quest/pot_bonus")+40+i*40;
}
if (exp > 600) exp=600;
if (pot > 400) pot=400;
        tell_object(me,HIW""+targ+"大喜道：多谢您及时送信给我，你被奖励了：\n"
        +chinese_number(exp)+"点修为值。\n"
        +chinese_number(pot)+"点潜能。\n\n"NOR);
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->set_temp("tufei",0);
        me->set("quest",0);
//        destruct(present("xin",me));
        destruct(this_object());
        return 1;
}

void go()
{	
if (this_player())
{
	this_player()->start_busy(1);
  if (random(100)<8&& !environment(this_player())->query("no_fight") )
	{	
        if (this_object()->query_temp("tufei")<2 && !environment(this_player())->query("no_fight")
         && !this_player()->is_fighting())
	{
		to_rob();
		this_object()->add_temp("tufei",1);
                this_player()->start_busy(1);
		call_out("go",30);}
		return;
	}
}
call_out("go",10);

}

void to_rob()
{
	int i;
	int maxskill;
	int maxexp;
	object robber;
	object me=this_player();
	maxskill=(int)me->query_skill("force");
if (!maxskill) maxskill=10;
	maxexp=me->query("combat_exp");
	message_vision(HIR"忽然间跳出一群劫匪！\n"NOR,this_object());
	for (i=0;i<=1;i++)
	{

		robber=new(__DIR__"tufei");
		robber->move(environment(this_player()));
		robber->set_leader(this_player());
                robber->set("combat_exp",maxexp);
                robber->set_skill("kuang-jian",maxskill*1/2);
                robber->set_skill("sword",maxskill*1/2);
                robber->set_skill("parry",maxskill*1/2);        
                robber->set_skill("dodge",maxskill*1/2);        
  	        robber->set("title",HIR"江南大盗"NOR);
if (random(10)>7 || this_player()->query("combat_exp")>1000000)
{
                robber->set_skill("kuang-jian",maxskill*2/3);
                robber->set_skill("sword",maxskill*2/3);
                robber->set_skill("parry",maxskill*2/3);        
                robber->set_skill("dodge",maxskill*2/3);        
  	        robber->set("title",HIC"江洋大盗"NOR);
}
		 if(objectp(present("biaoshi", environment(this_player()))))
		{	robber->kill_ob(present("biaoshi",environment(this_player())));
			present("biaoshi",environment(this_player()))->kill_ob(robber);}
		robber->kill_ob(this_player());
		robber->set_leader(this_player());
		this_player()->kill_ob(robber);
		this_player()->start_busy(2);
	}
	
}

void owner_is_killed() { destruct(this_object()); }
