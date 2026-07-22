// /d/taiyuan/guobingguan.c
// Room in 太原
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "国宾馆");
	set("long", @LONG
这是李渊起兵后，建立的国宾馆，招待各国使者，但从李渊迁都长
安后，这里也就对普通百姓开放，成了一家大客栈。
LONG
	);
set("exits", ([
                "north" : __DIR__"dongdajie1", 
                "south" : __DIR__"shuifang",    
	]));
	set("objects",([
	__DIR__"npc/xiaoer3":1,
	]));
       setup();
	
}	
int valid_leave(object ob,string dir)
{
   if(!ob->query_temp("gived_money")&&dir=="south")
   return notify_fail("怎么，想白住啊？\n");
   return ::valid_leave(ob,dir);
}
