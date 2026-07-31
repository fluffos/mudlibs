// SN:TBia>PZ0?DVKiY5M
// File(/data/room/xunxun/zhulin.c) of xunxun's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时枪下蛋就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "suzhou");
        set("sleep_room", 1);
        setup();

        set("room_owner", "枪下蛋");
        set("room_name", "寻寻");
        set("room_id", "xunxun");
        set("room_owner_id", "xunxun");
        set("room_position", "青石官道");
}
