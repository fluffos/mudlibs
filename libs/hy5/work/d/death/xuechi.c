// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "血池狱");
        set("long", @LONG
这里关押的都是“脱皮露骨，折臂断筋，也只为谋财害命，屠宰畜生堕
千年”的恶徒，手上都沾满了他人的血，故阎王以血还血，将这等人浸
泡于血池之中，每日受那血腥熏鼻之苦，日以继夜，痛苦难当。
LONG
        );
        set("exits", ([
		"up" : __DIR__"daoshan",
		"down" : __DIR__"abi",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-260);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
