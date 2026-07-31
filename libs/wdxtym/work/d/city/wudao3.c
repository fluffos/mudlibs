// Room: /city/wudao3.c

#include <ansi.h>

inherit __DIR__"underlt";

void create()
{
	set("short", "武道场");
	set("long", @LONG
这里是三面环山，只有北面有条出口的一坪山间平地。山坡山阵阵松涛哗
哗作响，山脚下的平地绿草如茵，中间架起了个擂台，四周一溜过去搭着凉棚，
棚中桌椅杯盆俱全。
LONG );
	set("outdoors", "city");
	set("exits", ([
		"leitai"      : __DIR__"leitai",
		"northeast"   : __DIR__"wudao1",
		"northwest"   : __DIR__"wudao2",
	]));
	set("no_fight", 1);
	setup();
	init_here();
	replace_program(__DIR__"underlt");
}
