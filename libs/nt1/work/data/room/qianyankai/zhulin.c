// SN:;]8[BDF[J>d\cFQP
// File(/data/room/qianyankai/zhulin.c) of qianyankai's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时钱眼开就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "yangzhou");
        set("sleep_room", 1);
        setup();

        set("room_owner", "钱眼开");
        set("room_name", "扬州钱庄");
        set("room_id", "qianyankai");
        set("room_owner_id", "qianyankai");
        set("room_position", "树林");
}
