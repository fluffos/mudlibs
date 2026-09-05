// shijie15.c 石阶
// by Xiang

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", 
"你走在一条坚实的石阶上，不时地有进香客从你的身边走\n"
"过。一边是峭壁，一边是悬崖，抬头隐约可见笼罩在云雾中的\n"
"天柱峰，听着流水淙淙，令人心旷神怡。\n"
	);
        set("outdoors", "wudang");

	set("exits", ([
		"westdown" : __DIR__"haohan",
		"eastup" : __DIR__"xuanwu",
	]));
	setup();
	replace_program(ROOM);
}

