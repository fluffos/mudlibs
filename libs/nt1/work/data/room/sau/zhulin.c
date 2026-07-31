// SN:Oki^iIIC0L8;lml@
// File(/data/room/sau/zhulin.c) of sau's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时白云就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "playertown");
        set("sleep_room", 1);
        setup();

        set("room_owner", "白云");
        set("room_name", "浪云吧");
        set("room_id", "sau");
        set("room_owner_id", "sau");
        set("room_position", "碎石小道");
}
