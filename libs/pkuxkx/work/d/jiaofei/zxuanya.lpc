//Create by whuan@pkuxkx
//铁掌帮
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "玄崖");
	set("long", @LONG
这里是通往中指峰第二节的山路。你抬头望去似乎路已到了尽头。当下足底
加快，再不依循峰上小径，径自笔直的往上爬去。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		  "southdown" : __DIR__"zhouyuan",
		  "northup" : __DIR__"zshanding",
		]));
 	  set("outdoors", "tiezhang");
    setup();
    replace_program(ROOM);
}
