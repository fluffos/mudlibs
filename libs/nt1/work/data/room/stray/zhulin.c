// SN:LQ30nj?HZG0;K`[A
// File(/data/room/stray/zhulin.c) of stray's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时我是米就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "playertown");
        set("sleep_room", 1);
        setup();

        set("room_owner", "我是米");
        set("room_name", "米米米米");
        set("room_id", "rice");
        set("room_owner_id", "stray");
        set("room_position", "青砖路");
}
