// SN:GF3BE25CSbeH<SF^
// File(/data/room/ouyd/zhulin.c) of ouyd's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时欧阳毒就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "playertown");
        set("sleep_room", 1);
        setup();

        set("room_owner", "欧阳毒");
        set("room_name", "白驼山庄");
        set("room_id", "ouyd");
        set("room_owner_id", "ouyd");
        set("room_position", "碎石小道");
}
