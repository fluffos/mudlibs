inherit ROOM;

void create()
{
        set("short", "紫金山");
        set("long", @LONG
紫金山亦名钟山，山势险峻，蜿蜒如龙，三国时诸葛亮谓之“钟山龙
蟠”。山周围名胜古迹众多，犹如珠围翠绕。钟山主峰海拔四百四十八米
，为金陵城外的一道屏障。
LONG
        );
        set("exits", ([ 
		"westup" : __DIR__"zhaimen",
	       "eastdown" : __DIR__"guanroad",
]));
        set("objects", ([
              __DIR__"npc/wulinren" : 2,
			]) );
        set("outdoors", "xueshan");
        setup();
}

int do_go()
{
if(random(2)){
this_player()->move(this_object());
return 1;
}
}


