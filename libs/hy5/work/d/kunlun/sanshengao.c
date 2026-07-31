// 昆仑山三圣坳 sanshengao.c

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
set("short","昆仑山三圣坳");
	set("long",@long
但见遍地绿草如锦，到处果树香花。原来那三圣坳四周都是插天高山，挡住
了寒气。昆仑派历代掌门人曾花了极大力气整顿这个山坳，派遣弟子东至江南，
西至天竺，搬移奇花异树前来种植。忽听得山坳后隐隐传出一阵琴声，你好奇心
起，便循声寻去。
long);

set("exits", ([
"north" : __DIR__"jingshenfeng",
"down" :  __DIR__"fufengshan",
]));
	
	  set("outdoors", "kunlun");
	  setup();
	   replace_program(ROOM);
}
