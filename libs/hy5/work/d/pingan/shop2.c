
inherit ROOM;

void create()
{
        set("short", "平安兵器铺防具分店");
        set("long", @LONG
这里是平安城最大的防具店，这里有各种各样的防具.
LONG
        );
        set("exits", ([
		"south" : __DIR__"west1",
        ]));
        set("objects", ([
                __DIR__"npc/weaponer2": 1,
        ]) );
        set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
        set("coor/x",-10);
	set("coor/y",40);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

