// 小道 /d/menpai/shennong/xiaodao4.c
// By lala, 1998-01-26

inherit ROOM;



void create()
{
    set("short",    "小道");
    set("long",@LONG
一条弯弯曲曲的小道。路两边是齐脚高的草地。要是不认真看，还真不容易
看出来。西边是无量山的主峰，是无量剑派的剑湖宫。远处稀疏的散着几片农田，
因为这里位处大理，所以还没有受到多年来战争的影响。
LONG
    );
    set("exits",    ([
        "east"      :   __DIR__"xiaodao3",
    	"southwest" :   "/d/dali/wuliang/lsdui",
    ]) );
    set("outdoors", "wuliang");
    setup();
}
