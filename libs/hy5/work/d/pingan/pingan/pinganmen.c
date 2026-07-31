// Room: /d/city/pinganmen
 inherit ROOM;
 
 void create ()
{
   set ("short", "平安门");
   set ("long", @LONG
这儿是天宫平安城的入口，有着无限的庄严。从此处北行，
就到平安城 了。一入平安城，永远将会平安，再无血腥风雨，
是一个避世的绝好去处。 如果向下行，你就进入江湖了。
LONG); 
        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
   set("outdoors", "pingan"); 
  set("exits", ([ /* sizeof() == 2 */  
 "east" : __DIR__"west3",   
 "up" : __DIR__"gate/wupgate",   
  "down" : "/d/city/guangchang", ]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
	]));
    setup();
} 
 int valid_leave(object me, string dir) 
{
       if (  me->query_temp("xunchen")< 1 && dir == "up" )
        return notify_fail("士兵说道：等一等,你和王大人说一下,才能巡城！\n");
 	if ( me->query("PKS") >= 3 && dir == "east" )
 	return notify_fail("你杀过太多的玩家！平安城不欢迎你！\n");
 	 	if ( me->query("age") >= 25 && dir == "east")
 	return notify_fail("你这么大岁数也还想进平安城？\n"); 
 	return ::valid_leave(me, dir);
}
