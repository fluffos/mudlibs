// SN:dZ;2MfkEMdSNRkWN
// File(/data/room/yourdead/zhulin.c) of yourdead's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时渡会就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "playertown");
        set("sleep_room", 1);
        setup();

        set("room_owner", "渡会");
        set("room_name", "龙潭");
        set("room_id", "yourdead");
        set("room_owner_id", "yourdead");
        set("room_position", "碎石小道");
}
