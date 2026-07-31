
//shulin.c树林
//diabio(青云)2001.3.30

#include <ansi.h>
#include <room.h>
#include <command.h>
inherit ROOM;
int consider_lv(object ob,int a);

void create ()
{
        set ("short", "树林");
        set ("long", @LONG
这是一片树林，林子很密，只有这一条小路穿林而过，一些阳光透
过密林射在地上，到了晚上这里基本是伸手不见五指的。在前面隐约
可以看见一个小房间。
LONG);
        set("exits", ([
             "east"  : __DIR__"pubu",
             "west"  : __DIR__"shulin"+(1+random(4)),
             "south" : __DIR__"shulin"+(1+random(4)),
             "north" : __DIR__"shulin"+(1+random(4)),               
        ]));


        set("outdoors", "feitian");
        setup();
}



void init()
{
	object me, ob;
	int level;
	mapping myfam;

	me = this_player();
	myfam = me->query("family");
if (!myfam) return;
	if ( myfam = me->query("family") && (myfam["family_name"] == "飞天御剑流") && random(100) < 25 
	&& !me->query_temp("shirenok"))
	{
		message_vision(HIW"突然树上传来一阵狞笑，伴一阵风势，一个蒙面人犹如一道利刃向你刺来.......\n"NOR, me);
		message_vision(HIW"蒙面人大喝一声：御剑流的通通的死，今天落到我手里算你倒霉，纳命来吧！！！\n"NOR, me);

		ob = new(__DIR__"npc/shiren");
              ob->set("combat_exp",me->query("combat_exp") * 9 / 10);
		ob->set("max_qi",me->query("max_qi"));
		ob->set("eff_qi",me->query("max_qi"));
		ob->set("qi",me->query("max_qi"));
/*
		ob->set("max_jingli",me->query("max_jingli"));
		ob->set("eff_jingli",me->query("max_jingli"));
		ob->set("jingli",me->query("max_jingli"));
		ob->set("max_neili",me->query("max_neili"));
		ob->set("neili",me->query("max_neili"));
*/
	level = (int)me->query_skill("force",1) * 5 / 6;
  if (level <=50) level=50;
  if (!level) level=50;
		ob->set_skill("force", level);
		ob->set_skill("unarmed", level);
		ob->set_skill("xuanhualiu-quanfa",level);
		ob->set_skill("dodge", level); 
                ob->set_skill("blade", level); 
		ob->set_skill("aikido", level); 
		ob->set_skill("wuxing-dun", level); 
		ob->set_skill("shayi-xinfa", level);
		ob->set_skill("parry", level); 
		ob->set_skill("literate", level); 
		ob->set_skill("feitian-yujianliu", level); 
                        ob->map_skill("parry", "aikido");
                        ob->map_skill("unarmed", "aikido");
                        ob->map_skill("dodge", "wuxing-dun");
                        ob->map_skill("force", "shayi-xinfa");
                        ob->map_skill("blade", "feitian-yujianliu");
		ob->move(environment(me));
		ob->kill_ob(me);
		me->kill_ob(ob);
		me->start_busy(1);
		me->set_temp("shiren",1);
me->set_temp("shirenok",1);
	}
	return;
}

int consider_lv(object ob,int a)
{
	int level; 
	float exper;

	exper = to_float(ob->query("combat_exp"));
	level = ceil( pow( exper*10.0, 0.333333) );

	level = level * a / 10;
if (level <=30) level=30;
if (!level) level=30;
	return level;
}

int valid_leave(object me, string dir)
{

	if (  ((dir == "south")||(dir == "north")||(dir == "west")||(dir == "east"))
	   && me->query_temp("shiren") == 1
	   && objectp(present("bang zhong", environment(me))) )
	{
		message_vision("蒙面人一闪身将你拦了下来：想走？没那么容易！！！", me);
		return notify_fail("\n");
	}
	me->delete_temp("shiren");
	return ::valid_leave(me, dir);
}
