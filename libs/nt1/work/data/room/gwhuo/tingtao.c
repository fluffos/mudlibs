// SN:>3B0RFZ4jKXk5:RO
// File(/data/room/gwhuo/tingtao.c) of gwhuo's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "听涛阁");
	set ("long", @LONG
这是竹林一角的听涛阁，在这里风吹竹叶的阵阵涛声听的非常真
切，真是让人心旷神怡。实在是一个参悟武功的好去处。 
LONG );

	set("exits", ([
                "west" : __DIR__"zhulin",
	]));

        set("sleep_room", 1);
        setup();

        set("research_improve", 15);  //15% improved
    
        set("room_owner", "鬼舞火");
        set("room_name", "小鬼之家");
        set("room_id", "gwhuo");
        set("room_owner_id", "gwhuo");
        set("room_position", "碎石小道");
}
