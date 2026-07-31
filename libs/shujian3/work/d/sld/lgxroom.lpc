// lgxroom.c
// 陆高轩家
inherit ROOM;
void create()
{
	set("short","陆府正厅");
	set("long",@long
这里是神龙教散人陆高轩的家，屋内四壁上挂了不少书画，其中不乏价值
连城之作，可想而知，主人对此是花费了大量心血，才得以收集到如此多的名
贵之作。
long);
	set("exits",([
	    "north" : __DIR__"lgxws",
           "east" : __DIR__"lgxys",
                   "out" : __DIR__"kongdi",
]));
       set("objects",([
		__DIR__"npc/lgx" : 1,
]));
	set("coor/x",490);
  set("coor/y",410);
   set("coor/z",10);
   setup();
}
	    	
int valid_leave(object me, string dir)
{
	if (dir == "out")
	{
		me->delete_temp("yaozhong");
		me->delete_temp("makeyao");
	}
	return ::valid_leave(me, dir);
} 
