// SN:Va8_mEg:VK0\\Jn[
// File(/data/room/lingyue/zhulin.c) of lingyue's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时灵月就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "playertown");
        set("sleep_room", 1);
        setup();

        set("room_owner", "灵月");
        set("room_name", "雪月楼");
        set("room_id", "xueyue");
        set("room_owner_id", "lingyue");
        set("room_position", "青砖路");
}
