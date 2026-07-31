// SN:4^^E2gQb22Pdm\\>
// File(/data/room/cbc/zhulin.c) of cbc's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时建设银行就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "playertown");
        set("sleep_room", 1);
        setup();

        set("room_owner", "建设银行");
        set("room_name", "建设银行金库");
        set("room_id", "cbc");
        set("room_owner_id", "cbc");
        set("room_position", "碎石小道");
}
