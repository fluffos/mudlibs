inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这是一条被人走出来的小山路，虽然不宽却是够一辆马车通行。小路
顺着山中较为平坦地带缓缓向东伸展。
LONG
        );
        set("exits", ([ 
		"eastup" : __DIR__"zijinshan2",
	       "east" : "/d/sandboy/to_zhongzhou",
]));
        set("outdoors", "xueshan");
set("objects",([
              "/d/hainan/npc/man1" : 2,
]));
        setup();
}
void init()
{
        add_action("do_go","go");

}

int do_go()
{
if(random(2)){
this_player()->move(this_object());
return 1;
}
}


