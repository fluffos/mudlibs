// jingxiu.c 静修阁
// by llin

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "静修阁");
	set("long", 
"这里是武当道派清心静修的地方，凡是武当门下弟子在道\n"
"学上有什么疑难之处，除了向师傅请教外，还可在此处静修悟\n"
"道以提高道学上的修为。屋内一片宁静，四面白壁，唯有正东\n"
"面墙上贴着一条横幅“大道于心”，几名道士正盘腿打坐，闭\n"
"目冥想，似乎已游身世外。\n"
	);

	set("exits", ([
		"east" : __DIR__"xiaodao",
		"up" : __DIR__"jingxiu2"
	]));

  set("lingwu_family", "武当派");
  set("least_msg",1);
  set("no_sick_spread",1);
	setup();
}