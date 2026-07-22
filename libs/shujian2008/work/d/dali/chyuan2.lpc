// Room: /dali/chahuayuan2.c
// Modify By River 98/12
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"茶花园"NOR);
      	set("long", @LONG
你走在一个小山坡上，这里到处都是盛开的鲜花，你有点眼花缭乱了，你
漫步在这花园中，心情舒畅许多。 
LONG
       );
        set("exits", ([ 
              "northup" : __DIR__"chyuan3",
              "southdown" : __DIR__"chyuan",
	]));
        set("outdoors","大理");
        set("objects", ([
             __DIR__"obj/chahua2" : 1,
        ]));
	setup(); 
}

int valid_leave(object me, string dir)
{
	if ( dir == "southdown" )
        me->delete_temp("flower_paid");
	return ::valid_leave(me, dir);
}
