// shanmen.c 武当山门
// by Xiang

inherit ROOM;

void create()
{
	set("short", "武当山门");
	set("long", 
"你的面前是一座林木繁茂的高山，几座山峰在云雾中隐约\n"
"可见，一条石阶向山上延伸，走着几个进香客。石壁上写着\n"
"“武当山”三个大字，原来这就是天下闻名的武当山。\n"
	);
        set("outdoors", "wudang");

	set("exits", ([
		"east" : __DIR__"wdroad8",
		"westup" : __DIR__"shijie11",
		"south" :  __DIR__"machehang",
	]));
        set("objects", ([
                __DIR__"npc/guest" : 1]));
	setup();
	replace_program(ROOM);
}

