// /d/mingjiao/bishui.c
// Jay 4/3/97 -qingyun
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
         set("short",HIG"晦智圣座"NOR);
       set("long", @LONG
晦智禅师圣座内修真之处原是一间石洞，入得洞来只见青石铺地竟是颇
为宽敞，几处钟乳珠缨金络，晶壁玉障。不但合洞通明亮入白昼；玉床碧几，
不染纤尘。而且石室修整，门户井然，到处光华灿烂，目迷五色。想是禅师
有意于世俗富贵眩目之气内修真，更增禅心。四壁各雕了一座千手如来佛像
姿态各不相同，栩栩如生，凝望之下令人忘俗。
LONG
     );
    
	set("exits", ([
		"out" : __DIR__"fota2",				
	]));             
        setup();
}
void init()
{
	add_action("do_ningwang",({"gaze","ningwang"}));
}
int do_ningwang(string arg)
{
	object me;
	me=this_player();
	if (arg!="foxiang") return notify_fail("你要凝望什么？\n");
	if (!living(me)) return 0;
	if (!random(5))
        message("vision", me->name()+"正在对着墙壁凝神观看佛像的手法。\n",
        environment(me), ({me}) );
      if ((int)me->query_skill("hand",1)<30){
		write("你凝望佛像，但觉千手繁复，实无半点脉络可寻。\n");
 	return 1;
	}
	if ((int)me->query_skill("hand",1)>100){
		      write("佛像姿势虽繁但你已尽数领悟于心。\n");
	return 1;
	}
        me->receive_damage("jing", 30);
        me->improve_skill("hand", (me->query("int"))*3/2);
        write("你望着佛像千奇百怪之手法，心中对基本手法有所领悟。\n");
	return 1;
}
