// Room: /city/kedian2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	string *order = ({"master1", "master2", "master3","master4","master5","master6","master7",
"master8","master9","master10","master11","master12","master13","master14","master15","master16"});
set("short", "客店二楼");
	set("long", @LONG
这里是客店的二楼几张大床一字排开，一些人正在上面睡的
呼噜震天响，门窗紧闭，官衔昏暗，你不由也想睡山个一觉。
LONG
	);
	set("sleep_room", "1");
	set("no_fight", "1");
        set("hotel",1);
	set("exits", ([
		"eastdown" : __DIR__"kedian",
		
	]));
	setup();
	
}
int valid_leave(object me, string dir)
{
	if ( dir == "out" ) me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}
