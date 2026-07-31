// SN:m5H>AD_QkT[[4WZO
// File(/data/room/longer/zhulin.c) of longer's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时药王就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "hangzhou");
        set("sleep_room", 1);
        setup();

        set("room_owner", "药王");
        set("room_name", "药王山庄");
        set("room_id", "longroom");
        set("room_owner_id", "longer");
        set("room_position", "山路");
}
