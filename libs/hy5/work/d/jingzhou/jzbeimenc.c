// Room: /d/jingzhou/jzbeimen
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short", "荆州北门" );
        set("long", @LONG
这里是荆州的北门，由于荆州历来都是军事要地，因此城墙坚实无比，城
楼高高耸立，由于北门以外，人烟稀少，来往的人不多，所以官兵的防卫也就
不十分严密。
LONG
        );
	set("objects", ([
		__DIR__"npc/bing" : 2,
]));
 
        set("exits", ([
  
	"northup" :"/d/wudang/wdroad2",
	"south" :__DIR__"beidajie2",
  
]));

        set("no_clean_up", 0);
        set("outdoors", "jingzhou");

        setup();
        replace_program(ROOM);
}

