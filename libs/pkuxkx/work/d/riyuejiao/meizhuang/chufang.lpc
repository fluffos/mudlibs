// chufang.c	厨房
// by bing

inherit ROOM;
string* names=({
	"/d/shaolin/obj/mala-doufu",
	"/d/shaolin/obj/bocai-fentiao",
	"/d/shaolin/obj/shanhu-baicai",
	"/d/shaolin/obj/liuli-qiezi",
        }); 

void create()
{
        set("short", "厨房");
        set("long", @LONG
这是梅庄的厨房。空气里充满了一种甜香，桌子上放着一些素菜，
客人可以在这里用膳。
LONG);
        set("exits", ([ 
"west" : __DIR__"tianjing",
]) );
	set("objects",([
		names[random(sizeof(names))]:1,
		names[random(sizeof(names))]:1,
		names[random(sizeof(names))]:1,
		names[random(sizeof(names))]:1,
		]));
	setup();
	replace_program(ROOM);
}
