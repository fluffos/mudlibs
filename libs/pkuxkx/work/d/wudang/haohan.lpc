// shijie3.c 好汉坡
// by Xiang
// by arnzh 97/1/23

inherit ROOM;

void create()
{
	set("short", "好汉坡");
	set("long", 
"你走在一条坚实的石阶上，不时地有进香客从你的身边走\n"
"过。一边是峭壁，一边是悬崖，抬头隐约可见笼罩在云雾中的\n"
"天柱峰，听着流水淙淙，令人心旷神怡。北边是一座牌坊，西\n"
"边是一口井，过往的路人有些坐在井边休息有些在向酒袋里装水。\n"
	);
        set("outdoors", "wudang");

	set("exits", ([
	        "eastup": __DIR__"shijie15",       
		"southdown" : __DIR__"shijie14",
	]));
	setup();
	replace_program(ROOM);
}

