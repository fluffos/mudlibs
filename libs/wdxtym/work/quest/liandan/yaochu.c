//yaochu.c 药锄
//海洋II（云起云落）
//星星lywin 2000/6/15

#include <ansi.h>
inherit ITEM;
#include "/clone/medicine/yc1.h"
string *she1=({"/d/shenlong/npc/dushe","/d/shenlong/npc/jinshe","/d/shenlong/npc/qingshe"});
string *she2=({"/d/shenlong/npc/fushe"});
string *yao1=({"/quest/liandan/yaocao1","quest/liandan/yaocao2"});

void init()
{
	add_action("do_wayao", "wayao");
}

void create()
{
	set_name("药锄", ({"yao chu", "chu"}));
        set_temp("workchu", 8);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		//set("no_drop","不要乱丢，这东西打到人痛！\n");
		//set("no_put",1);
		set("long", "这是一把破药锄，你可以用它来挖药（wayao）。\n");
		set("value", 0);
	}
	setup();
}

int do_wayao()
{
string file;
//string *roomlines;
string location;
string room;
object ob;
object ob1;
object me=this_player();
int filei;
	//quests = read_table("/quest/dynamic_quest");
//file = read_file("/clone/medicine/yc1");
//roomlines = explode(file,"\n");
//location = roomlines[random(sizeof(roomlines))];
//write location;
room=environment(me)->query("long");
filei=strsrch(room,"山中");
if (filei<=0) filei=strsrch(room,"高山");
if (filei<=0) filei=strsrch(room,"森林");
if (filei<=0) filei=strsrch(room,"溪水");
if (filei<=0) filei=strsrch(room,"草原");

	if (filei >0 && random(2)==0)
{
       environment(me)->set_temp("wayaono",1);
}

	if( file = environment(me)->query("no_fight"))
		return notify_fail("这里的药草早已被人挖光了。\n");

if( environment(me)->query("outdoors")=="migong")
return notify_fail("这里的药草早已被人挖光了。\n");

if( file = environment(me)->query_temp("wayaono"))
return notify_fail("这里的药草早已被人挖光了。\n");

//tell_object(me,location);
//if (filei <=0) tell_object(me,"无药");
//if (filei >0) tell_object(me,"有药");
//tell_object(me,filei);
//        ob1 = new(location);
//        ob1->move(me);


        if (me->is_busy())
        {
          tell_object(me,"等你忙完了，再挖吧，！\n");
          return 1;
        }
	if( me->is_fighting() )
        {
          tell_object(me,"等打完了，再挖吧，！\n");
          return 1;
        }

if (environment(me))
{
        if (present("dushe", environment(me))
        || present("qing she", environment(me))
        || present("jin she", environment(me))
        || present("fu she", environment(me)))
        {
          tell_object(me,"先把毒蛇干掉吧！\n");
          return 1;
        }
}
        if ((me->query("jing") < 20))
        {
          tell_object(me,"你的精力不能集中，不可以挖药！\n");
          return 1;
        }
        else
        if ((me->query("qi") < 30 ))
        {
          tell_object(me,"你的身体状态太差，不能挖药！\n");
          return 1;
        }
        else
        if ((int)me->query_condition("skill2_busy"))
            {
         tell_object(me,"你刚刚才干过活,要休息一会了！\n");
                      return 1;
            }
        else
	if (environment(me)->query_temp("wayao1") >= 1)
        {
        message_vision(HIC"$N挥动药锄开始在地上挖了起来。\n"NOR,me);
        me->add("jing",-10);
        me->add("qi",-20);
        me->start_busy(8);
       	call_out("wayao1",3,me);
       	me->stop_busy();
       	return 1;
      	}
      	else
	if (environment(me)->query_temp("wayao2") >= 1)
        {
        message_vision(HIC"$N挥动药锄开始在地上挖了起来。\n"NOR,me);
        me->add("jing",-20);
        me->add("qi",-30);
        me->start_busy(8);
       	call_out("wayao2",4,me);
       	me->stop_busy();
       	return 1;
      	}
      	else
	if (filei >0 )
        {
if( !file = environment(me)->query("outdoors"))
return notify_fail("只有户外才有可能有药才，请到室外找找吧。\n");

        message_vision(HIC"$N挥动药锄开始在地上挖了起来。\n"NOR,me);
        me->add("jing",-20);
        me->add("qi",-30);
        me->start_busy(8);
       	call_out("wayao3",4,me);
       	me->stop_busy();
       	return 1;
      	}
        return notify_fail("这里的药草早已被人挖光了。\n");
}

int wayao1(object me)
{
      object ob;
      object ob1;

      if(random(7)==2)
      {
        tell_room(environment(me),HIY"草丛中一阵晃动，突然钻出一条蛇。\n"NOR );
        ob=new(she1[random(3)]);
        ob->move(environment(me));
        ob->kill(me);
        ob->set_leader(me);
        me->start_busy(2);
      }
      else
      if (random(7)==3)
      {
          message_vision(CYN"一翻摸索后，草丛中似乎没有$N要找的东西，$N失望的叹了口气。\n"NOR,me);
		  message_vision(HIY"你对药理的知识增涨些许。\n"NOR,me);
			me->improve_skill("liandan", (int)me->query_skill("liandan", 1) + me->query_int());

      }
      else
      {
        message_vision(HIG"$N找了半天，终于发现其中一株草苗与其它的草略有不同，小心翼翼地掘了出来。\n"NOR,me);
		message_vision(HIY"你对药理的知识增涨许多。\n"NOR,me);
		me->improve_skill("liandan", (int)me->query_skill("liandan", 1) + me->query_int()*2);
        ob1 = new( __DIR__ "yaocao1");
        ob1->move(me);
        add_temp("workchu", -1);
        environment(me)->add_temp("wayao1",-1);
        environment(me)->set_temp("wayaob",1);
        me->apply_condition("skill2_busy",1+random(1));
                me->start_busy(1);
        if ( query_temp("workchu") < 1)
             {
    message_vision(HIG"药草倒是挖到了，可惜药锄却不小碰坏了。\n"NOR,me);
        destruct(this_object());
             }
      }
      return 1;
}

int wayao2(object me)
{
      object ob;
      object ob1;

      if(random(7)==2)
      {
        tell_room(environment(me),HIY"草丛中一阵晃动，突然钻出一条蛇。\n"NOR );
        ob=new(she2[random(1)]);
        ob->kill(me);
        ob->set_leader(me);
        ob->move(environment(me));
        me->start_busy(2);
      }
      else
      if (random(7)==3)
      {
          message_vision(CYN"一翻摸索后，草丛中似乎没有$N要找的东西，$N失望的叹了口气。\n"NOR,me);
		  message_vision(HIY"你对药理的知识增涨些许。\n"NOR,me);
			me->improve_skill("liandan", (int)me->query_skill("liandan", 1) + me->query_int());

      }
      else
      {
        message_vision(HIG"$N找了半天，终于发现其中一株草苗与其它的草略有不同，小心翼翼地掘了出来。\n"NOR,me);
		message_vision(HIY"你对药理的知识增涨许多。\n"NOR,me);
		me->improve_skill("liandan", (int)me->query_skill("liandan", 1) + me->query_int()*2);
        ob1 = new(yao1[random(2)]);
        ob1->move(me);
        environment(me)->add_temp("wayao2",-1);
        environment(me)->set_temp("wayaog",1);
        me->apply_condition("skill2_busy",1+random(1));
        add_temp("workchu", -1);
        me->start_busy(1);
        if ( query_temp("workchu") < 1)
             {
    message_vision(HIG"药草倒是挖到了，可惜药锄却不小碰坏了。\n"NOR,me);
        destruct(this_object());
             }
      }
      return 1;
}


int wayao3(object me)
{
      object ob;
      object ob1;
string file;
//string *roomlines;
string location;
string room;
me=this_player();
//file = read_file("/clone/medicine/yc1");
//roomlines = explode(file,"\n");
location = roomlines[random(sizeof(roomlines))];

      if(random(10) == 0 && !wizardp(me))
      {
        tell_room(environment(me),HIY"草丛中一阵晃动，突然钻出一条蛇。\n"NOR );
        ob=new(she2[random(1)]);
        ob->kill(me);
        ob->set_leader(me);
        ob->move(environment(me));
        me->start_busy(2);
      }
      else
      if (random(10) == 1 && !wizardp(me))
      {
          message_vision(CYN"一翻摸索后，草丛中似乎没有$N要找的东西，$N失望的叹了口气。\n"NOR,me);
		  message_vision(HIY"你对药理的知识增涨些许。\n"NOR,me);
			me->improve_skill("liandan", (int)me->query_skill("liandan", 1) + me->query_int());
      }
      else
      {
        message_vision(HIG"$N找了半天，终于发现在这周围有一样东西可以入药 ，小心翼翼地找了出来。\n"NOR,me);
		message_vision(HIY"你对药理的知识增涨许多。\n"NOR,me);
		me->improve_skill("liandan", (int)me->query_skill("liandan", 1) + me->query_int()*2);
        ob1 = new(location);
        ob1->move(me);
        message_vision(HIG"$N找到了"+ob1->query("name")+"。\n"NOR,me);
        environment(me)->set_temp("wayaono",1);
        me->apply_condition("skill2_busy",2+random(1));
        add_temp("workchu", -1);
        me->start_busy(1);
        if ( query_temp("workchu") < 1)
             {
    message_vision(HIG"药草倒是挖到了，可惜药锄却不小碰坏了。\n"NOR,me);
        destruct(this_object());
             }
      }
      return 1;
}