// shantang.c
// shilling 97.2

inherit ROOM;

void create()
{
	set("short", "膳堂");
	set("long", @LONG
这里是逍遥派弟子平时吃饭的地方，地方虽然不大，但是也有不少逍遥派
的弟子光顾这里。你终于找到香味的来源了。
LONG );
	set("exits",([
		"north" : __DIR__"xiaodao2",
	]));

 	set("objects", ([
		__DIR__"npc/puren": 1,
	]));


	set("no_clean_up", 0);
	setup();
}
int valid_leave(object me,string dir)
{
	me=this_player();
if (me)
{
        if(dir=="north" && (present("bowl",this_player()) || present("rice",this_player()))) 
             return notify_fail("仆人说道：怎么，吃饱了还要带走？\n");
}
        return ::valid_leave(me,dir);
}