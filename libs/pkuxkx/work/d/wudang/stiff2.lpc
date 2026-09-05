// stiff.c 悬崖
// by Xiang

inherit ROOM;

void create()
{
	set("short", "悬崖");
	set("long", 
"只见左右上下都是陡峭的岩石，滑滑的难以着手。脚下就\n"
"是万丈悬崖，吓得人不敢下望。山风罡烈，直要把你吹了下去。\n"
	);
        set("outdoors", "wudang");
	set("hsz_no_task",1);
	set("no_task",1);
	set("no_dbr_stage",1);
        set("exits", ([
                "down" : __DIR__"feng",
        ]));
	setup();
	replace_program(ROOM);
}

