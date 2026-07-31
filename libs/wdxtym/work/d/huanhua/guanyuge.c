// guanyuge.c 观鱼阁
// by chenww

inherit ROOM;

void create()
{
        set("short", "观鱼阁");
        set("long", @LONG
浣花溪流到这里汇集成潭，水不深，萧家在这里顺便养了些小鱼儿。依栏
望去，几条红鱼在清清的溪水中缓缓地游动。
LONG
        );
        set("exits", ([
             "south" : __DIR__"huayuan",
          "west" : __DIR__"dating",
             "north" : __DIR__"tingyulou" ,
        ]));
        set("objects", ([
                __DIR__"npc/dizi" : 2,
               __DIR__"npc/xiaoxueyu" : 1,
                       ]));
        set("outdoors", "huanhua" );
        
        set("coor/x",70);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-70);
	set("coor/z",0);
	setup();

        replace_program(ROOM);
}
