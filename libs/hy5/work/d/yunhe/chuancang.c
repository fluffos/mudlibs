// Room: /d/yunhe/chuancang
// Date: netkill  98/08/18


inherit ROOM;

void create()
{
    set("short","船仓" );
    set("long",  @LONG
这是一间布置得十分雅致的船仓，一看就知道是大家闺秀在的
地方，中间的茶几上放着一张古琴，一位漂亮的小姐正在弹琴，一
个个音符有如行云流水一般，听的人心动神弛。墙上挂着一把剑，
一副字画。这里虽然光线不好，可是两盏大烛台将这里照得很明亮。
LONG 
    );
	set("exits", ([
		"out" :__DIR__"ship",
			]));
       set("objects", ([
		"quest/weiguo/japan/japan2.c" : 2,

	]));       
    set("outdoors", "yunhe");
    setup();
	replace_program(ROOM);
	
}


	
