
// inn_2f.c

inherit ROOM;

void create()
{
    set("coor",({-20,4750,15}));
	set("short", "客栈二楼");
	set("long",
"你现在来到了客栈的二楼，这家客栈有个很奇怪的规矩，就是只留宿名头够大的客人，如果\n"
"你只是一个无名小卒，不论出再多银两都租不到一间空房，墙边有一道楼梯通往一楼的茶座\n"
"。\n"
);
	set("exits", ([
        "down" : __DIR__"inn" ]) );
	setup();
}
