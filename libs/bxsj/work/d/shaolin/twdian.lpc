// Room: /d/shaolin/twdian.c
// Date: YZC 96/01/19
// by zqb

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIR"天王殿"NOR);
	set("long", @LONG
这里是少林寺的中殿天王殿。殿内香烟燎绕，幔角叮咚。香火比前殿要
旺盛的多。正前方供着个大肚子，似乎永远都笑咪咪的弥勒佛。四大天王分
列两旁，分执“风调雨顺”。两侧香桌上摆满了四季果蔬，弥勒的身后站立
的是韦驮。只见他金盔金甲，年轻英俊，威风凛凛，双手合十，金刚杵横放
腕上。
LONG
	);

	set("exits", ([
//		"east" : __DIR__"twdian1",
//		"west" : __DIR__"twdian2",
		"south" : __DIR__"qdian",
		"north" : __DIR__"sblu-1",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/dao-guo" : 1,
		__DIR__"npc/xiang-ke" : 1,
	]));

	set("coor/x",50);
  set("coor/y",240);
   set("coor/z",110);
   setup();
}



