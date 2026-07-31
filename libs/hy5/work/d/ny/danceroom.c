
// Room: /d/snow/tao.c

inherit ROOM;

void create()
{
        set("short", "晚月庄");
        set("long",
"这是一间歌舞院，这里有许多美貌的女孩子正在学习着歌艺和舞蹈。一位仙女般的女舞者正\n"
"在教她们跳各种美丽的舞蹈。在这里，你忍不住也想去和她们一起跳起来。\n"
);
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"crossroad",
]));

        set("valid_startroom", 1);
        setup();
        replace_program(ROOM);
}
