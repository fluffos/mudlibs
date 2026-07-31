//Edited by fandog, 02/15/2000

#include <ansi.h>
inherit ROOM;

void create()
{

	set("short", "汉阳码头");
	set("long", @LONG
面前是一条波涛翻滚的大江 (river)。浊流滚滚，千帆竞发。两岸
渡船来来往往，不少过江客都在这里等待渡船摆渡。
LONG );
	set("exits", ([
		"west" : __DIR__"hzjie2",
		"south" : __DIR__"matou2",
	]));
	set("item_desc", ([
		"river" : "近岸处有几只渡船，也许喊(yell)一声船家就能听见。\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "jiangling");
	set("coor/x", -1490);
	set("coor/y", -2110);
	set("coor/z", 0);
  set("yell_about", "船家");             // yell 船家
  set("river_type", "江");               // 江面上传来回响
  set("need_dodge",300);                 // 需要多少轻功


	setup();
}
