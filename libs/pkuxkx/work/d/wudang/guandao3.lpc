// Room: /wudang/guandao3.c
// llin 11.25.1997 

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
一条行人走马的大道，路上不时有些赶路的旅人，官道到
这里几乎已是尽头。西北是一条黄土道，静悄悄的显得有些怕
人。
LONG
	);
	set("no_clean_up", 0);
	/*set("realmap", "                 黄土路                        
                        ＼          
                            [1;32m官道[2;37;0m-----官道      
                                    
                                               
");*/
	set("exits", ([ /* sizeof() == 2 */
		  "northwest" : __DIR__"wdroad6",
		  "east" : __DIR__"guandao2",
         // "southeast" : __DIR__"sample",
		]));
	set("outdoors", "wudang");
	setup();
}

