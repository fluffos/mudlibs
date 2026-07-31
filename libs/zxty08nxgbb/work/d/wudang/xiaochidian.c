// Room: /d/wudang/xiaochidian.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "小吃店");
    set("long", @LONG
这个小吃店布置简易，简直就是一个四面透风的凉棚嘛，也能叫小吃店。
顾客多是匆匆的行人，买点包子、鸡腿、米酒就赶路去了。
LONG
    );
    set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoer3" : 1,
]));
    set("no_clean_up", 0);
    set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"shijie5",
  "east" : __DIR__"xiaolu4",
  "southdown" : __DIR__"xuanwumen",
]));
    setup();
    replace_program(ROOM);
}
