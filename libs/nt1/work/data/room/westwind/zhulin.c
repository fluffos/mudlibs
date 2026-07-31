// SN:2EQ4G@2P7oYkAQW:
// File(/data/room/westwind/zhulin.c) of westwind's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时西风就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "unknow");
        set("sleep_room", 1);
        setup();

        set("room_owner", "西风");
        set("room_name", "西风居");
        set("room_id", "wind");
        set("room_owner_id", "westwind");
        set("room_position", "名人堂");
}
