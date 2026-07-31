// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "冥府节司");
        set("long", @LONG
自古以来，男女大防，节字难守，多少女子，因种种诱惑，身
败名裂，受那地狱分尸之苦。节司两旁尽是贞节女子的画像，画像
中簇拥着一位女子端坐案上，正是节司的掌管--绿珠，当年虽身为
石崇侍妾，可宁死不随他人，终跳楼而死，节烈之气，名扬千古。
在其光芒之中，正受分尸之刑的男男女女，更为丑陋。
LONG
        );
        set("exits", ([
		"northeast" : __DIR__"naihe2",
        ]) );
        set("objects", ([
                __DIR__"npc/greengirl":1,
        ]) );
	set("coor/x",-1030);
	set("coor/y",-30);
	set("coor/z",-100);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
