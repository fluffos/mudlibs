inherit ROOM;
void create()
{
        set("short", "寝室");
        set("long", @LONG
这里是太白居士的书房，四周陈设显得古典而雅致，左边是一个
古色古香的檀木书架，几个书童正在研墨待作。
LONG
        );
        set("no_clean_up", 0);
        set("no_fight", "1");
        set("sleep_room", "1");
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shuyuan",
]));
        setup();
        replace_program(ROOM);
}

