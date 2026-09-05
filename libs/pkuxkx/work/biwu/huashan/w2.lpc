// Room: /clone/misc/w2.c
// Date: by jason(尔好啊) Tue Nov 17 15:44:29 2009
inherit "/biwu/biwuroom";

void create()
{
	set("short", "揽月台");
	set("long", @LONG
揽月台说是台，其实是一块巨大平整的花岗岩石。石上有一杆月旗，上绘广寒玉宫。
传说谁夺取了这面旗帜，谁就拥有了逐鹿天下的力量。
你可以用duo这个命令来夺旗。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
		  "south" : __DIR__"w3",
		  "east" : __DIR__"w5",
		  "north" : __DIR__"w1",
		  "out" : __DIR__"westgate",		  
		]));
	set("flag","月旗");
	set("default_flag_hp",5);
	set("flag_hp",5);		
    set("objects", ([
        "/biwu/jieshuo" : 1,
        ]));	
	setup();
}
