// road0.c
inherit ROOM;
void create()
{
        set("short", "山中小路");
        set("long", @LONG
这里山色甚是凄凉，道路更本来已是苔藓土滑，崎岖难行到后来更是乱山峥
嵘，荒草没径。
LONG
        );
        set("exits", ([ 
  "eastup" : __DIR__"road1",
  "westdown" : __DIR__"road",
]));
        set("outdoors", "tieflag");
        setup();
}
void init()
{
	add_action("do_go","go");

}

int do_go()
{
if(random(3)){
this_player()->move(this_object());
return 1;
}
}
