// laojundian.c 老君殿
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "老君殿");
        set("long", @LONG
这里是供奉太上老君的大殿。殿的正中塑着老君的塑像，老君骑
在青牛上，正临云而去。两旁塑着两个童子，都栩栩如生。殿中的地
都是以青砖一块块的铺成，打扫得一尘不染。
LONG
        );
        set("exits", ([
                "east" : __DIR__"houtang1",
                "south" : __DIR__"tongtiandian",
                "north" : __DIR__"yuanshidian",
                "west" : __DIR__"datang3",
        ]));
        
set("roomif","$botten#护教任务|采药任务|上交药材:ask qiu about job|ask qiu about yaojob|give <物品> to qiu$#");
        
        set("objects", ([
                "quest/menpaijob/quanzhen/qiu" : 1,
                __DIR__"npc/daotong" : 2,
                __DIR__"npc/daotong1" : 2,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        mapping fam;

        if (dir == "east" )
        {
                if(!(fam = me->query("family")) || fam["family_name"] != "全真教") {
                        if(present("dao tong", environment(me)) && living(present("dao tong", environment(me))))
                        {
                                return notify_fail(
"道童说道：后面是本教重地，这位" + RANK_D->query_respect(me) + "请止步。\n");
                        }
                        else
                                return ::valid_leave(me, dir);
                }
                else
                        return ::valid_leave(me, dir);
        }
        else
                return ::valid_leave(me, dir);

}
