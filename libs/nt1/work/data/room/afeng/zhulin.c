// SN:?oU9]G600C[`Z7XG
// File(/data/room/afeng/zhulin.c) of afeng's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时阿峰就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "playertown");
        set("sleep_room", 1);
        setup();

        set("room_owner", "阿峰");
        set("room_name", "狗洞");
        set("room_id", "afeng");
        set("room_owner_id", "afeng");
        set("room_position", "三岔口");
}
