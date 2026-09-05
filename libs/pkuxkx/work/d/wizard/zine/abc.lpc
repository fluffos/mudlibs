// Room: /d/wizard/zine/abc.c

inherit ROOM;

void create()
{
	set("short", "空房间");
	set("long", @LONG
"好地方"LONG
	);
	set("main_dir", "/d/wizard/");
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"abcd",
]));
	set("no_clean_up", 0);
	set("realmap", "                                               
                                    
                           [1;32m空房间[2;37;0m              
                             ｜     
                           空房间              
");

	setup();
	replace_program(ROOM);
}
