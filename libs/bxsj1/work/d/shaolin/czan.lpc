//czan.c
//by bren

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIY"初祖庵"NOR);
	set("long", @LONG
这里是初祖庵，乃是北宋末年少林寺中的僧人为了纪念达摩而修建的。
庵内山门，大殿及各式庭院齐全，正中的大殿内供奉着达摩初祖，二祖，三
祖，四祖及五祖的塑像。院内有几名老迈的僧人接待着前来敬香的香客。
LONG
	);

	set("exits", ([
		"north" : __DIR__"shanlu5",
                "south" : __DIR__"shanlu4",
       ]));
        set("objects",([
		__DIR__"npc/xiang-ke" : 1,
	]));

	set("coor/x",50);
  set("coor/y",480);
   set("coor/z",140);
   setup();
}


