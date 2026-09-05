// taohuadao/taolin2 桃林
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "桃林");
        set("long", @LONG
这是桃花岛的桃林，四周都是桃花，似乎是一个桃花阵。
LONG);
        set("exits", ([ /*sizeof() == 3*/
        "south" : __DIR__"taolin1",
        "northup" : __DIR__"shanlu1",
//        "northwest" : __DIR__"mudi",
        "northwest" : __DIR__"taolin3",
       ]));
        set("outdoors","taohuadao");
	setup();
}
void init()
{
	object me = this_player();
	if(me->query_temp("zyhb/bhcs"))
	tell_object(me, HIC"西北面的桃林隐约传来一阵箫声，你经过仔细聆听，听出其音以“商”音为主。\n"NOR);
}