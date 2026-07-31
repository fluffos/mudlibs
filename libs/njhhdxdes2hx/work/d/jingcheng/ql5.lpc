#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIC"青龙大街"NOR);
	set("long", @LONG               
这里是青龙大街的中段。往南走几步是青龙大街和朱雀大街的十字
路口。这一片住的多是朝廷官员，或是有钱人家，深宅大院，垂柳
白杨，看起来十分的干净。东边有一家小店铺。
LONG
	);

	set("exits", ([
 "south"  :__DIR__"zhq3",
 "north"  :__DIR__"ql4", 
 "east"   :__DIR__"jxzhp",
 "west"   :__DIR__"ytgj",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

