//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "东大街");
        set("long", @LONG
再往西就要到西内城门了，远远望去，可以看见守城的官兵正在检查
排队出城的路人。因为这里是街口，所以非常热闹。小商小贩们在向
行人吆喝着，兜售他们的商品。南一条安静的胡同，许多洛阳城的
老百姓住在里面，北边是一条幽静的碎石小路。
LONG
        );

        set("exits", ([
               "east" : __DIR__"dongmen",
               "west" : __DIR__"dongdajie1",
               "north" : __DIR__"suishilu1",
               "south" : __DIR__"hutong1",               
        ]));
/*        set("objects", ([
                "/d/city/npc/wujiang1"+random(2) : 1,
                "/d/city/npc/bing" : 2,
        ]));
*/
        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}

