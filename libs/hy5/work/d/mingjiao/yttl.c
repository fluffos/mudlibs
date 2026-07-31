inherit ROOM;

#include <ansi.h>
void create()
{
  set("short",HIR"明教前殿"NOR);
  set("long",@LONG
你来到这里，放眼窗外望去，漫漫昆仑雪山，晶莹剔透，苍
天浩浩，白云悠悠。东方沃野千里，楚天辽阔；西面高山巍巍，
迤逦万里。这里就是叱咤武林八百年的明教总舵的前殿。

LONG);

     set("outdoors", "xiaoyao");
     set("exits",([
           "north" : __DIR__"dadian",
     ]));
 	set("objects", ([
		"/kungfu/class/mingjiao/sd1" : 1,
		"/kungfu/class/mingjiao/sd2" : 1,
		"/kungfu/class/mingjiao/sd3" : 1,
		"/kungfu/class/mingjiao/sd4" : 1,
		"/kungfu/class/mingjiao/sd5" : 1,
		"/kungfu/class/mingjiao/sd6" : 1,
	]));
     setup();
}
int valid_leave(object me, string dir)
{
object fang;
object who;
int i;
who=me;



	if ( objectp(present("kong zhi", environment(me))) )
		return notify_fail("少林派的人拦住了你的去路,这次一定要消灭魔教。\n");

	if ( objectp(present("miejue shitai", environment(me))) )
		return notify_fail("峨眉派的人拦住了你的去路,这次一定要消灭魔教。\n");

	if ( objectp(present("song yuanqiao", environment(me))) )
		return notify_fail("武当派的人拦住了你的去路,这次一定要消灭魔教。\n");

	if ( objectp(present("he taichong", environment(me))) )
		return notify_fail("昆仑派的人拦住了你的去路,这次一定要消灭魔教。\n");

	if ( objectp(present("tang wenliang", environment(me))) )
		return notify_fail("崆峒派的人拦住了你的去路,这次一定要消灭魔教。\n");

	if ( objectp(present("xian yutong", environment(me))) )
		return notify_fail("华山派的人拦住了你的去路,这次一定要消灭魔教。\n");


  if((int)who->query("jinyong/book12")==3)
{
		i = 1250+random(2000);
		who->set("jinyong/book12",4);
		who->add("combat_exp",i+14000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		tell_object (who,"你赢得了"+chinese_number(i+14000)+"点经验"+
		           chinese_number(i*18)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		who->save();
}

        return ::valid_leave(me, dir);
}

                                                                                                                                                                                                                                                                                                                                                                                                    