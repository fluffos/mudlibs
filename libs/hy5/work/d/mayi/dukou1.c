// rich 99/04/05
inherit ROOM;
void create()
{
	set("short", "黄河渡口");
	set("long", @LONG
这里是黄河的一个渡口，脚下就是滚滚而来的黄河水，这里主要是
供官府使用。
LONG
	);
set("outdoors", "mayi");
set("valid_startroom", 1);
set("exits", ([
                "northeast" : __DIR__"huangtu2",
"southeast" : "/d/huanghe/guchangcheng",	
	]));
       setup();
	replace_program(ROOM);
}
