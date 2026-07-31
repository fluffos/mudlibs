 inherit ROOM;
void create()
{
        set("short", "东云路");
        set("long", @LONG
风云城中最杂最乱的地方。虽然如此，这里还是人来人往。只要你想得出来的，
这里就有，不管是吃的还是玩的。南面是一个破旧的小亭子，里面寄居这一个老道
士。北面则是风云城里老字号的布铺。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"ecloud3",
  "west" : __DIR__"ecloud1",
  "north": __DIR__"bupu",
  "south": __DIR__"jijian",
]));
        set("objects", ([
        __DIR__"npc/fatman" : 1,
        ]) ); 
        set("outdoors", "fengyun");
        set("coor/x",20);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
