// SN:dKAd`@P?48Ai`T_>
// File(/data/room/thr/zhulin.c) of thr's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时阿二就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "suzhou");
        set("sleep_room", 1);
        setup();

        set("room_owner", "阿二");
        set("room_name", "二班");
        set("room_id", "erban");
        set("room_owner_id", "thr");
        set("room_position", "青石官道");
}
