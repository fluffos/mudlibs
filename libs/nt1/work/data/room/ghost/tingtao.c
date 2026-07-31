// SN:00^S3DLTLdHE^4GN
// File(/data/room/ghost/tingtao.c) of ghost's room
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
    
        set("room_owner", "静香");
        set("room_name", "天空之城");
        set("room_id", "sky");
        set("room_owner_id", "ghost");
        set("room_position", "碎石小道");
}
