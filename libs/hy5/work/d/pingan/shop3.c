
inherit ROOM;

void create()
{
        set("short", "神针世家药店");
        set("long", @LONG
这里是神针世家所开的药店,一股浓浓的药味让你几欲窒息，
那是从药柜上的几百个小 抽屉里散发出来的。这里只有一个小
伙计站在柜台后招呼着顾客。
LONG
        );
        set("exits", ([
		"south" : __DIR__"west2",
        ]));
        set("objects", ([
                __DIR__"npc/huoji": 1,
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

