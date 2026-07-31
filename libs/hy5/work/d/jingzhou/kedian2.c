// Room:kedian2.c
// congw 980830 

inherit ROOM;

void create()
{
string *order = ({"master1", "master2", "master3","master4","master5","master6","master7",
"master8","master9","master10","master11","master12","master13","master14","master15","master16"});
	set("short", "客店二楼");
	set("long", @LONG
你正走在客店二楼的走廊上，可以听到从客房里不时地呼呼的打酣声，一阵高过一
阵。不时有睡意朦胧的旅客进进出出，到楼下的掌柜处付了钱再上来睡觉。
LONG
	);

	set("exits", ([
		"down" : __DIR__"kedian",
		"enter" : __DIR__"kedian3",
	]));

	
	setup();
	replace_program(ROOM);
}

