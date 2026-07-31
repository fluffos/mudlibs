inherit ROOM;

#include <ansi.h>
void create()
{
  set("short",HIG"武当广场"NOR);
  set("long",@LONG
这是一个由大石板铺成的广场，是武当弟子学习武功和互相切磋的地点。
周围种满了梧桐树，一到秋天就是满地的落叶。一个年纪轻轻的道童正在打扫。
南边是灵霄宫三清殿。

LONG);

     set("outdoors", "xiaoyao");
     set("exits",([
           "south" : __DIR__"sanqingdian",
     ]));
 	set("objects", ([
		"/kungfu/class/mingjiao/sd1" : 1,
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
		return notify_fail("少林派的人拦住了你的去路,让你说出谢逊的下落，。\n");

	if ( objectp(present("miejue shitai", environment(me))) )
		return notify_fail("峨眉派的人拦住了你的去路,让你说出谢逊的下落，。\n");

	if ( objectp(present("he taichong", environment(me))) )
		return notify_fail("昆仑派的人拦住了你的去路,让你说出谢逊的下落，。\n");

	if ( objectp(present("tang wenliang", environment(me))) )
		return notify_fail("崆峒派的人拦住了你的去路,让你说出谢逊的下落，。\n");

	if ( objectp(present("xian yutong", environment(me))) )
		return notify_fail("华山派的人拦住了你的去路,让你说出谢逊的下落，。\n");


   if(who->query("jinyong/book12")==1)
{
		i = 950+random(2000);
		who->set("jinyong/book12",2);
		who->add("combat_exp",i+12000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		tell_object (who,"你赢得了"+chinese_number(i+12000)+"点经验"+
		           chinese_number(i*18)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		who->save();
}

        return ::valid_leave(me, dir);
}

                                                                                                                                                                                                                                                                                                                                                                                                    