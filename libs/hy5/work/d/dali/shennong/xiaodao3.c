// 小道 /d/menpai/shennong/xiaodao3.c
// by lala, 1998-01-26

inherit ROOM;



void create()
{	
    set("short",    "小道");
	set("long",@LONG
一条弯弯曲曲的小道。路两边是齐脚高的草地。要是不认真看，还真不容易
看出来。西边是无量山的主峰，是无量剑派的剑湖宫。往东则是无量山东山之所
在。路越来越窄，好象好久没人来过了。
LONG    );
    set("exits",    ([
        "northeast" :   __DIR__"dongfeng_di",
	    "west"      :   __DIR__"xiaodao4"  
    ]) );
    set("outdoors", "wuliang");
    setup();
}
