// SN:HUfYelHOSHa[5L7Z
// File(/data/room/shadow/zhulin.c) of shadow's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时影子无敌就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "playertown");
        set("sleep_room", 1);
        setup();

        set("room_owner", "影子无敌");
        set("room_name", "神影之穴");
        set("room_id", "lightroom");
        set("room_owner_id", "shadow");
        set("room_position", "青砖路");
}
