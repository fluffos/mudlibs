//ROM diabio

inherit ROOM;

void create()
{
	set("short","神古活心流大门");
        set("long",
         "这就是闻名方原百里的『神古活心流』的大门。大门上刻着日本的战神\n"
         "四周的墙壁均用各色木头建成，由于风吹日晒已经有点退色了。但还是\n"
         "能看出昔日的辉煌\n"
        );
        set("outdoors", "feitian");
        set("exits", ([
		"north" : __DIR__"qianting",
                "southdown" : __DIR__"jiedao",
        ]));
        set("objects",([
                __DIR__"npc/dizi" : 2,
	]));
	setup();
}
