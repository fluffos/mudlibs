 inherit ROOM;
void create()
{
        set("short", "走廊");
        set("long", @LONG
一条几乎伸手不见五指的走廊，透着森森的寒意和杀机。
仅有几线灯光从两旁的屋内射出来。这里渗透着男人的汗臭
和廉价粉脂的味道。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"room1",
  "north" : __DIR__"room2",
  "south" : __DIR__"room3",
  "west" : __DIR__"zoulang2",
]));
        set("objects", ([
        __DIR__"npc/dizi": 1,
        __DIR__"npc/xunluo": 1,
                        ]) ); 
        set("coor/x",3290);
        set("coor/y",30);
        set("coor/z",-30);
        setup();
        replace_program(ROOM);
}
