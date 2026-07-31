// Room: /d/mr/hubian.c

inherit ROOM;

void create()
{
        set("short", "湖边");
        set("long", @LONG
俗话说 : 上有天堂, 下有苏杭。这里正是大大有名的太湖。 湖面绿波
上漂着一叶叶的小舟, 一阵阵悦耳的小曲儿随着湖上的轻风不时漂入你的耳
中。
LONG
        );
        set("outdoors", "mr");
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"hubian1",
//  "west" : "/d/mr/syj",
  "northeast" : "/d/suzhou/road5",
]));

        setup();
        replace_program(ROOM);
}

