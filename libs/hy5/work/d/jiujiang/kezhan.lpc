
inherit ROOM;


void create ()
{
  set ("short","九江浔阳楼");
  set ("long", @LONG
浔阳楼因《水浒传》中的义军头领宋江曾在此题反诗而名声大噪
，历来为文人墨客游览九江必到之处。其联曰：大闹江州，人言此事
桩桩有，百代流传，无非天下英雄借题抒壮志；细观水浒，我觉其文
句句真，千秋炳焕，信是世间才子因史撰奇书。

LONG);

  set("exits", ([ 

 "north":__DIR__"dongdajie2",
 "enter":__DIR__"wofang",

         ]));
 set("objects",([
	 __DIR__"npc/xiaoer2":1,
	 ]));
 set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(!me->query_temp("gived_money")&&dir=="enter")
		if(objectp(present("xiao",environment(me))))
			return notify_fail("店小二拦住了你：客官，您还没给钱呢!\n");
		else return notify_fail("掌柜从里面喊道：客官，给钱再住店啊!\n");
		return ::valid_leave(me,dir);
		return 1;
}
