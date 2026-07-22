// Room: /d/huashan/houtang.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "后堂");
        set("long", @LONG
   这是华山派的后堂，来往的人不是很多，只看见几个仆人来回忙碌着。
东西面分别是男女弟子休息的地方，南面是华山派掌门岳不群的寝室。
LONG
        );

        set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("objects",([
		__DIR__"npc/ludayou" : 1,
	]));
        set("exits",([
        	"north" : __DIR__"zhengqi",
        	"south" : __DIR__"qinshi",
        	"west" : __DIR__"celang3",
        	"east" : __DIR__"celang4",
	]));
	set("indoors", "华山" );
	set("coor/x",80);
  set("coor/y",-30);
   set("coor/z",80);
   setup();

}
/*
int valid_leave(object me, string dir)
{

	if ((dir == "south") && ( 其他条件 )
	{
		return notify_fail("那是掌门的卧室，普通弟子不能进去!\n");
	}

	return ::valid_leave(me, dir);
}
*/