//jinling  nanjie1.c
inherit ROOM;

void create()
{
        set("short", "南街");
        set("long", @LONG
这里是金陵镇南边的主要街道，往北通往镇上最热闹的广场，往南
则通往南门，你的左边是一家花店，街道上人来人往，一派繁华的景象。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "north" : __DIR__"zhongxin",
           "south" : __DIR__"nanjie2",
           "west" : __DIR__"huadian",
           "east" : __DIR__"caifengdian",
   ]));
        set("objects", ([
              __DIR__"npc/girl" : 2,
              __DIR__"npc/bukuai" : 1,
			]) );

 set("outdoors", "jinling");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}