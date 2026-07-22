
inherit ROOM;

void create()
{
        set("short", "百花潭");
	set("long", @LONG
潭面平静得象一块明晃晃的镜子，倒映着红瓦绿树；潭面的几
片荷叶，又给潭水增添了几分姿色。往北就是浣花溪。
LONG
	);
        set("outdoors","chengdu");

	set("exits", ([
                "west" : __DIR__"caotang",
                "northeast" : __DIR__"cdcc",
                "north" : __DIR__"huanhuaxi1",
	]));
        set("objects" , ([
             __DIR__"npc/youke" : 2,
        ]));
	setup();
}


