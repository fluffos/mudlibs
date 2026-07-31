// SN:Y0dJLOi[BVliSdXk
// File(/data/room/newer/zhulin.c) of newer's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时段了就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "playertown");
        set("sleep_room", 1);
        setup();

        set("room_owner", "段了");
        set("room_name", "段了");
        set("room_id", "newer");
        set("room_owner_id", "newer");
        set("room_position", "碎石小道");
}
