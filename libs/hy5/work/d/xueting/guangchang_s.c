// Room: /d/xueting/square_s.c
inherit ROOM;
void create()
{
        set("short", "广场南侧");
        set("long", @LONG
这里是雪亭镇广场的南边，往北可以望见一株高大的榕树，广
场以榕树为中心形成一个十多丈见方的大空地。街道往南通往镇外，
东边不远处有间打铁铺子。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"sstreet1",
  "north" : __DIR__"guangchang",
  "west"  : __DIR__"guangchang_sw",
  "east"  : __DIR__"smithy",
]));
        set("outdoors","xueting");

        setup();
        replace_program(ROOM);
}
