// SN:@E?2=;H0j<WcBOSg
// File(/data/room/peiyu/zhulin.c) of peiyu's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时俞佩玉就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "xiakedao");
        set("sleep_room", 1);
        setup();

        set("room_owner", "俞佩玉");
        set("room_name", "杀人山庄");
        set("room_id", "peiyu");
        set("room_owner_id", "peiyu");
        set("room_position", "南海之滨");
}
