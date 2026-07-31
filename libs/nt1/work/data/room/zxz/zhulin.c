// SN:9V7]LTX:@>X3Vd=k
// File(/data/room/zxz/zhulin.c) of zxz's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时无盐就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "playertown");
        set("sleep_room", 1);
        setup();

        set("room_owner", "无盐");
        set("room_name", "明霖");
        set("room_id", "roomofzxz");
        set("room_owner_id", "zxz");
        set("room_position", "三岔口");
}
