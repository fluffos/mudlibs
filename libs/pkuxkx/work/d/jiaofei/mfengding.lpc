//Create by whuan@pkuxkx
//铁掌帮
inherit ROOM;

void create()
{
	set("short", "拇指峰顶");
	set("long", @LONG
你累个半死，终于爬到拇指峰顶。这里有一个烽火台（tai），似乎用来传递信号只用。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		  "up" : __DIR__"mtai",
		  "southdown" : __DIR__"mshanlu10",
		]));
	set("no_clean_up", 0);
	set("realmap", "                           烽火台              
                             [1;36m〓[2;37;0m     
                          [1;32m拇指峰顶[2;37;0m             
                             ↑     
                            山路               
");
	set("outdoors", "tiezhang");
        setup();
        replace_program(ROOM);
}
