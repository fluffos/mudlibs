// Room: /d/putian/wgg.c 武功阁
// lklv 2001.9.12

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "武功阁");
        set("long", @LONG
这里是武功阁，里面地方很大，地面上铺着大块的清石方砖，四角各有一
个大柱子，两边放着兵器架，架上摆满了各种兵器。几个身材魁梧的壮年武僧
正在练武。
LONG
        );

        set("exits", ([
                "northdown" : __DIR__"dc-dian",
        ]));

        set("objects",([
                __DIR__"npc/wuseng" : 2,
                CLASS_D("putian") + "/yuanbei" : 1,
        ]));
        setup();
}
