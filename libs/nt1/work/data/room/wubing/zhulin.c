// SN:@^G?M0okiDC84e@K
// File(/data/room/wubing/zhulin.c) of wubing's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时张无病就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "yangzhou");
        set("sleep_room", 1);
        setup();

        set("room_owner", "张无病");
        set("room_name", "无病");
        set("room_id", "wubing");
        set("room_owner_id", "wubing");
        set("room_position", "树林");
}
