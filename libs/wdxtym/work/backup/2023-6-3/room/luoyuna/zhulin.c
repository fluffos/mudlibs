// File(/data/room/luoyuna/zhulin.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set("long", "这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时大白就去听涛阁默听竹浪涛声，参悟武功。
");

	set("exits", ([
		"west" : __DIR__"huayuan",
		"east" : __DIR__"tingtao",
	]));

	set("outdoors", "hell");
	set("sleep_room", 1);
	setup();

        set("room_owner", "大白");
        set("room_name", "小白居");
        set("room_id", "xiaobai");
        set("room_owner_id", "luoyuna");
        set("room_position", "武林四街");
}
