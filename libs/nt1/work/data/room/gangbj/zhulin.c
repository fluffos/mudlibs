// SN:1`9UBHXMN^<bl?P[
// File(/data/room/gangbj/zhulin.c) of gangbj's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时唐三藏就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "gumu");
        set("sleep_room", 1);
        setup();

        set("room_owner", "唐三藏");
        set("room_name", "三藏的庙");
        set("room_id", "gangbj");
        set("room_owner_id", "gangbj");
        set("room_position", "寒水潭");
}
