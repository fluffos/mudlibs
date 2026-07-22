// Room: /d/wudie/jm.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "景门");
        set("long", @LONG
这里去碟舞山庄的必经之路，群山尽收眼底，白云在你的脚下缭
绕。只有一条铺着鹅卵石的小径向前伸延，小路两旁是一排茂密的松
林。走在小路上，给人一种心旷神怡的感觉。
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shanlu40",
  "north" : __DIR__"qjm",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
