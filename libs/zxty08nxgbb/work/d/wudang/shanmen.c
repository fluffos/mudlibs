// Room: /d/wudang/shanmen.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "武当山门");
    set("long", @LONG
你的面前是一座林木繁茂的高山，几座山峰在云雾中隐约可见，一条石
阶向山上延伸，走着几个进香客。石壁上写着“武当山”三个大字，原来这
就是天下闻名的武当山。
LONG
    );
    set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guest" : 1,
]));
    set("outdoors", "wudang");
    set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"wdroad8",
  "westup" : __DIR__"shijie11",
]));
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
