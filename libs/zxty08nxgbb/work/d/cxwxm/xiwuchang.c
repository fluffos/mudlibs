// Room: /d/cxwxm/xiwuchang.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "后山习武场");
        set("long", @LONG
你一上山来，发现这里居然是痴心妄想门的习武场，在场中央摆放着
一排排的木人。难怪大门那边非常安静，原来弟子们全都在这里练武，他
们的喊打声，在这山谷中回荡着！

LONG
);
        set("exits", ([ /* sizeof() == 1 */
  "westdown" : __DIR__"cxwx2",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kuang" : 2,
]));
        set("outdoors", "cxwxm");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
