// jingshenfeng.c 惊神峰

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
set("short","惊神峰"NOR);
	set("long",@long
折而向北，过了一岭，只见古柏三把百余章，皆挺直端秀，凌霄托根树
旁，作花柏顶，灿若云荼。走出十余丈，只听得琴声之中杂有无数鸟语，细
细听来，琴声竟似和鸟语互相应答，间间关关，宛转啼鸣。只见三株大松树
下一个白衣男子背向而坐，膝上放这一张焦尾琴，整自弹奏。他身周树木上
停满了鸟雀，黄莺，杜鹃，喜鹊，八哥，还有许多不知其名的，和琴声或一
问一答，或齐声和唱。
long);

set("roomif","$botten#练琴任务|开始练琴:ask he about lianqin|lianqin$#");   
set("objects",([
    "/kungfu/class/kunlun/hezudao.c" : 1,
    ])); 

set("exits", ([
"south" : __DIR__"sanshengao",
]));
	  set("outdoors", "kunlun");
	  setup();
replace_program(ROOM);
}
