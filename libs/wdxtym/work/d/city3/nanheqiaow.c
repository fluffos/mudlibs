
// Room: nanheqiaow.c
inherit ROOM;
void create()
{
	set("short","南河桥");
	set("long",@LONG
这里是成都西门外南河桥。府河和南河夹城流过，呵护着这个天
府之国的首府之地。河水清新碧透。东面是西城门，往西就是浣花溪
了。
LONG);
	set("outdoors", "chengdu");
	set("exits",([ /* sizeof() == 1 */
	    "west"  : __DIR__"path1",
	    "east"  : __DIR__"westgate",
	]));
	set("no_clean_up", 0);
	setup();
}

