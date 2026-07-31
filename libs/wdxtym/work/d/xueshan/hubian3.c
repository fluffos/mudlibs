//      hubian3.c 湖边小路
inherit ROOM;

void create()
{
	set("short", "湖边小路");
	set("long", @LONG
这是圣湖边的小路。天兰兰的，白白的云朵在湖里漂
移，波光潋滟。湖边生长着一些绿绿青青的不知名的矮树。
LONG );
	set("outdoors", "xueshan");
	set("exits", ([
		"north" : __DIR__"hubian4",
		"southwest" : __DIR__"hubian2",
	]));
	setup();
}
