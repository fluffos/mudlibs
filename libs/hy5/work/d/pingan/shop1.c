
inherit ROOM;

void create()
{
        set("short", "平安兵器铺");
        set("long", @LONG
这里是平安城最大的武器店，十八般外门兵器，这里应有尽有,大家行走
江湖都要在这里买几件趁手的武器,所以这里生意很不错.
LONG
        );
        set("exits", ([
		"north" : __DIR__"west1",
        ]));
        set("objects", ([
                __DIR__"npc/weaponer": 1,
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

