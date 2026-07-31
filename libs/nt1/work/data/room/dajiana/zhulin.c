// SN:VRMKTW<:7RW2H<3i
// File(/data/room/dajiana/zhulin.c) of dajiana's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时何济公就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "hangzhou");
        set("sleep_room", 1);
        setup();

        set("room_owner", "何济公");
        set("room_name", "盘龙山庄");
        set("room_id", "panglong");
        set("room_owner_id", "dajiana");
        set("room_position", "山路");
}
