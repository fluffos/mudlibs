// /d/dalicheng/dlroad4.c

inherit ROOM;

void create()
{
	set("short", "大道");
	set("long", @LONG
你来到了大理国边境，西南方向是天龙寺，东北面则通向成都。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 4 */
		  "northeast" : __DIR__"dlroad2",
                  "south" : "/d/dalicheng/guandao6",
               "southwest" : __DIR__"foothill",
	//	  "north" : "/d/pingxiwangfu/pxroad1",   //平西王府按实际地理位置调整到昆明  Nov 25 2010 by Zine
		]));
        
        setup();
        
}
