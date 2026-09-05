// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
#include "baoxiao.h"
void create()
{
	set("short", "内厅");
	set("long", @LONG
这里是三司使的内厅，南面是盐铁司的衙门，北面是度支司的衙门，东面是
三司使长官的值房。
LONG
	);
       //set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"north" : __DIR__"sansi1",
		"out" : __DIR__"sansishi",
		"south" : __DIR__"sansi2",//吏部
		"east" : __DIR__"sansinei",//礼部
	]));
	set("yamen_id","三司使");
	setup();
}