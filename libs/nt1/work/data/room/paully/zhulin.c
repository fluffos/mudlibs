// SN:f4H4EHWLeBKClKn>
// File(/data/room/paully/zhulin.c) of paully's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时双剑就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "playertown");
        set("sleep_room", 1);
        setup();

        set("room_owner", "双剑");
        set("room_name", "双府");
        set("room_id", "shurangfu");
        set("room_owner_id", "paully");
        set("room_position", "碎石小道");
}
