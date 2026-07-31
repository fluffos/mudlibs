// SN:_DKR]Mn6ic84E4QK
// File(/data/room/xiaojian/zhulin.c) of xiaojian's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时小剑就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "yangzhou");
        set("sleep_room", 1);
        setup();

        set("room_owner", "小剑");
        set("room_name", "剑府");
        set("room_id", "xiaojianfu");
        set("room_owner_id", "xiaojian");
        set("room_position", "树林");
}
