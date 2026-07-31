// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "冥府义司");
        set("long", @LONG
司内陈设与关庙毫无不同，掌印之人是关二爷，抚须沉思，正
与人对弈，当年千里送嫂，过五关斩六将，虽上马金，下马银，不
能改其义，反观那不义之徒，有何面目苟全于天地。堂下铡刀数口，
专铡不义之人。想起了你以前做过的事，你不由得一身冷汗。
LONG
        );
        set("exits", ([
		"northwest" : __DIR__"naihe2",
        ]) );
        set("objects", ([
                __DIR__"npc/guan":1,
        ]) );
	set("coor/x",-1010);
	set("coor/y",-30);
	set("coor/z",-100);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
