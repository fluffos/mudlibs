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
//      set("no_drop", 1);
        set("no_get", 1);

        setup();
}

void init()
{
        add_action("do_sendto","sendto");
	remove_call_out("go");
	call_out("go",3);	
}

int do_sendto(string arg)
{
object ob=this_object(),me=this_player();
string targ;
int exp,pot;
        if (!arg||!ob=present(arg,environment(me)))
                return notify_fail("你要把信送给谁？\n");
        targ=ob->query("name");
if ( targ != me->query("quest/quest") ) return notify_fail("这是送给"+me->query("quest/quest")+"的信，你怎么能随便乱给呢？\n");
        if (userp(ob)) return notify_fail("你弄错人了吧？\n"); //玩家可能有相同于NPC的名字
        if ( (int) me->query("task_time") < time() )
        {
             return notify_fail(targ+"冷冷地说：“你来晚了,耽误了我的大事，你还有脸来见我！”\n");
        }
        tell_object(me,"你把信交给了"+targ+"。\n" NOR );
        exp=me->query("quest/exp_bonus");
        pot=me->query("quest/pot_bonus");
        tell_object(me,HIW""+targ+"大喜道：多谢您及时送信给我，你被奖励了：\n"
        +chinese_number(exp)+"点经验值。\n"
        +chinese_number(pot)+"点潜能。\n\n"NOR);
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->set_temp("tufei",0);
        me->set("quest",0);
        destruct(present("xin",me));
        return 1;
}

void go()
{	
  if (random(100)<15&& !environment(this_object())->query("no_fight") )
	{	
        if (this_object()->query_temp("tufei")<3)
	{
		to_rob();
		this_object()->add_temp("tufei",1);
		call_out("go",30);}
		return;
	}call_out("go",10);
}

void to_rob()
{
	int i;
	int maxexp;
	object robber;
	object me=this_player();
	maxexp=me->query("combat_exp");
	message_vision(HIR"忽然间跳出一群劫匪！\n"NOR,this_object());
	for (i=0;i<=random(2)+1;i++)
	{
		robber=new(__DIR__"tufei");
		robber->move(environment(this_player()));
		robber->set_leader(this_player());
                robber->set("combat_exp",maxexp);
		 if(objectp(present("biaoshi", environment(this_player()))))
		{	robber->kill_ob(present("biaoshi",environment(this_player())));
			present("biaoshi",environment(this_player()))->kill_ob(robber);}
		robber->kill_ob(this_player());
		this_player()->kill_ob(robber);
	}
	
}

void owner_is_killed() { destruct(this_object()); }
