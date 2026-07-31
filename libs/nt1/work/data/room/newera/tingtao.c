// SN:eRa=\1N4Se`gTjD^
// File(/data/room/newera/tingtao.c) of newera's room
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
    
        set("room_owner", "天下");
        set("room_name", "随便吧");
        set("room_id", "newerb");
        set("room_owner_id", "newera");
        set("room_position", "碎石小道");
}
