// SN:_<1fgXiIfd?kGlV=
// File(/data/room/lenovo/zhulin.c) of lenovo's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时联想就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "huashan");
        set("sleep_room", 1);
        setup();

        set("room_owner", "联想");
        set("room_name", "叹息谷");
        set("room_id", "sighh");
        set("room_owner_id", "lenovo");
        set("room_position", "山洪瀑布");
}
