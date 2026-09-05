// /d/dali/dlroad1.c

inherit ROOM;

void create()
{
	set("short", "羊肠小路");
	set("long", @LONG
这是一条小路, 西南方通向大理段氏, 东北方通向扬州城.
LONG
	);
	set("no_clean_up", 0);
	set("realmap", "                                     黄土路    
                                  ／
                          [1;32m羊肠小路[2;37;0m             
                        ／          
               羊肠小路                        
");
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
		  "northeast" : "/d/wudang/wdroad6",
		  "southwest" : __DIR__"dlroad2",
		]));
        setup();
        replace_program(ROOM);
}

