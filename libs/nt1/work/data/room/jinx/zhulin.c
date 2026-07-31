// SN:]HcOoPO8EaN]cV<B
// File(/data/room/jinx/zhulin.c) of jinx's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时蕴龙心境就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "playertown");
        set("sleep_room", 1);
        setup();

        set("room_owner", "蕴龙心境");
        set("room_name", "金鳞阁");
        set("room_id", "jinlin");
        set("room_owner_id", "jinx");
        set("room_position", "碎石小道");
}
