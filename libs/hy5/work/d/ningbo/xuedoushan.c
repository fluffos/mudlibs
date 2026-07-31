// /u/beyond/ningbo/xuedoushan.c 雪窦山
inherit ROOM;
void create()
{
	set("short","雪窦山");
	set("long", @LONG
你走上雪窦山，看到山上松樟翠竹蔽日，山岩奇突多姿，峰峦突兀雄奇，
银瀑飞撒如雪，景色绮丽如画。东西两涧的水在锦镜池汇聚，经过崖口顿然
凌空怒泻，形成溅喷如雪的巨瀑。登台远眺，无数秀美风景宛如绢画般动人。
LONG
     );
	set("exits",([ 
	//"south" : __DIR__"***",
	"north" : __DIR__"dongqianhu",
	]));
	//creat_door("
	setup();
	replace_program(ROOM);
}
