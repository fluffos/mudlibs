//jinling  xijie2.c
inherit ROOM;

void create()
{
        set("short", "西街");
        set("long", @LONG
这里是金陵镇西边的主要街道，往东通往镇上最热闹的广场，往西
则通往西门，街道上人来人往，一派繁华的景象。北面好象有一家绸缎
铺，南面是一家中药铺。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "west" : __DIR__"ximen",
           "east" : __DIR__"xijie1",
           "north" : __DIR__"duanchoupu",
           "south" : __DIR__"zhongyaopu",
]));
        set("objects", ([
              __DIR__"npc/yiren" : 1,
              __DIR__"npc/pizi" : 1,
			]) );

 set("outdoors", "jinling");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}