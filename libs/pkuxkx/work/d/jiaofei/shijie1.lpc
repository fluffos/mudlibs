//Create by whuan@pkuxkx
//铁掌帮
inherit ROOM;

void create()
{
        set("short", "石阶");
        set("long", @LONG
一条石阶蜿蜒伸向山顶，两边皆是腰深的杂草，风过处似有强人隐没其中，你想
起这里常有强盗出没的传闻，不禁流出一身冷汗。
LONG    );
        set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shanjiao",
  "northup" : __DIR__"shijie2",
]));
        set("no_clean_up", 0);
        set("outdoors", "tiezhang");

        setup();
        replace_program(ROOM);
}