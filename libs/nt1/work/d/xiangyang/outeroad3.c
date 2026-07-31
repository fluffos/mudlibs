// /d/xiangyang/outeroad3.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
你走在一条土路上，偶尔有马匹经过，搞得尘土飞扬。因为这里已是
湖北境内，所以可能会有山贼出没。往东就进入安徽境内了。西边通向襄
阳城。
LONG );
        set("outdoors", "襄阳");

	set("exits", ([
		"west" : __DIR__"outeroad2",
		"east" : __DIR__"anhuiroad",
	]));

	setup();
	replace_program(ROOM);
}

