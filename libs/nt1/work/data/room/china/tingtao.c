// SN:gNh^fojF5F3;Q2af
// File(/data/room/china/tingtao.c) of china's room
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
    
        set("room_owner", "段盛");
        set("room_name", "长乐之家");
        set("room_id", "tomhome");
        set("room_owner_id", "china");
        set("room_position", "青石官道");
}
