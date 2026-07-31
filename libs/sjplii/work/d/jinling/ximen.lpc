//jinling  ximen.c
inherit ROOM;

void create()
{
        set("short", "西门");
        set("long", @LONG
这里是金陵的西门，高高的城墙上面插着几个旗帜，城门口站着几个值
勤的官兵，你朝他们瞧了一眼，其中一个官兵冷冷地盯了你一眼，你不禁打
了个哆嗦，还是快点走吧。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
       "west" : __DIR__"guanroad2",
   "east" : __DIR__"xijie2",


]));
         set("objects", ([
           __DIR__"npc/bing" : 3,
			]) );
 set("outdoors", "jinling");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
