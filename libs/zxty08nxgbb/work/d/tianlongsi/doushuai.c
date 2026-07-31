// Room: /d/tianlongsi/doushuai.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "兜率大士院");
    set("long", @LONG
这是一般参拜者所能到的最远的地方，再往南就是天龙寺历代高僧静
修之处——牟尼堂。那是常人不可轻易打搅的地方，你最好不要擅自闯入
。除非你确信能给高僧们带去好消息。
LONG
    );
    set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/xianglu" : 1,
]));
    set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"sanwugong",
  "northeast" : __DIR__"doumugong",
  "north" : __DIR__"qingxinge",
]));
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
