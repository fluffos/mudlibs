// Room: /d/snow/fireplace.c
inherit ROOM;
void create()
{
        set("short", "大灶内");
        set("long", @LONG
你现在正蜷缩著挤在一个大灶之中, 头顶上方隐隐可看到烟囱
的出口, 不过显然没有办法从烟囱爬出去。这里的墙壁因为长年烧
火而变得乌黑, 地面上积了一层厚厚的柴灰。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "out" : __DIR__"inn_kitchen",
]));
        set("objects", ([
                __DIR__"obj/woodsword": 1
        ]));
        setup();
        replace_program(ROOM);
}
