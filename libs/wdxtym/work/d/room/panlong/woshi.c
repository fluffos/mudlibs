// SN:HE@Ca[S1UC^3XE^7
// File(/data/room/jun/woshi.c) of jun's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "卧室");
	set("long", "这是主人的卧室，收拾得井井有条。南窗下是一张大床，床边有
一个柜子。推开窗户可以看到下面的花园，还可嗅到阵阵花香，非常
惬意。远处是一大片竹林。
");


	set("exits", ([
		"down" : __DIR__"jusuo",
	]));

	set("sleep_room", 1);
	set("loving_room", 1);
	set("no_fight", 1);
	 set("no_clean_up",1);
	setup();
    
	set("room_owner", "康康儿");
	set("room_name", "天堂之家");
	set("room_id", "home");
	set("room_owner_id", "jun");
	set("room_position", "草地");
}
int clean_up()
{
	return 0;
}