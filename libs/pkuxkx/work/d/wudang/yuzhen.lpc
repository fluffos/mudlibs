// yuzhenggong.c 遇真宫
// by Xiang

inherit ROOM;

void create()
{
	set("short", "遇真宫");
	set("long", 
"这里是武当的遇真宫，不时地有进香客从你的身边走过。\n"
"两边是几个菩萨，一条宽阔的石阶穿堂而过，直通笼罩在云雾\n"
"中的天柱峰，望着堂中烟云缭绕的香炉，和周围虔诚的许愿人，\n"
"令人肃然起敬。\n"
	);
        set("outdoors", "wudang");

	set("exits", ([
                "southdown" : __DIR__"shijie13",
		"west" : __DIR__"xiaodian",
	]));
        set("objects", ([
                __DIR__"npc/guest" : 1]));

	setup();
	replace_program(ROOM);
}

