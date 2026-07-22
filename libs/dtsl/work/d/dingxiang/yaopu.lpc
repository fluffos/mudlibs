// /d/yazhang/yaopu.c
// Room in 牙帐
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "药铺");
	set("long", @LONG
这是定襄城最大的药店，这里所配的药都出自当朝御医之手，用料
考究，当然价格也不低了，所以光顾这里的大多是有钱人与江湖中人。
这里平日看来冷冷清清的，只有几个药房小活计正在打磕睡。
LONG
	);
set("exits", ([
                 "east" : __DIR__"beidajie1",  
	]));
      
      set("objects",([
         __DIR__"npc/zhoulaoban":1,
         ]));
      
       setup();
	replace_program(ROOM);
}	
