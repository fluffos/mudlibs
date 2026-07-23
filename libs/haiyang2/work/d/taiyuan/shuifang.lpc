// /d/taiyuan/shuifang.c
// Room in 太原
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "睡房");
	set("long", @LONG
这是一间十分普通的睡房，房里布置的非常简单，只有一张床，一
张方桌，几个圆凳，但却十分幽静，你已经很累了，躺在床上，昏昏睡
去。
LONG
	);
set("exits", ([
                "north" : __DIR__"guobingguan", 
	]));
	set("sleep_room",1);
       setup();
	
}	

int valid_leave(object ob,string dir)
{
  if(dir=="north")
  ob->delete_temp("gived_money");
  return ::valid_leave(ob,dir);
}