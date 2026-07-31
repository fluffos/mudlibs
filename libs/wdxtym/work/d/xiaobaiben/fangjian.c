// 地图源文件




inherit ROOM;

void create()
{
set("short", HIY"小怪聚集地"NOR);
	set("long", @LONG
这里是小怪聚集地
LONG);

set("exits", ([
 "north" : __DIR__"fangjian2",
	]));
	 set("no_sleep_room",1);
       set("no_clean_up", 0);
set("no_fuhuo", 1);
	set("objects", ([

//	__DIR__"npc/npcshuxing": 1,

	]));
	set("no_learn", 1);

   // set("no_fight", 1);
	setup();
	//replace_program(ROOM);

}

int valid_leave(object me, string dir)
{
        object ob;
if( userp(me) &&
dir=="north" && ob=present("xiaoguai", this_object()))
return notify_fail(
"你想硬闯？！\n");
return 1;
}

