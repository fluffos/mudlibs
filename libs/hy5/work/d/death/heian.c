// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "黑暗狱");
        set("long", @LONG
这里毫无光亮，无数的囚徒将在这里呆上数十年或者更长，没有一种
恐惧比黑暗更能让人丛内心感到绝望了，所以通常这里的犯人很少，
一旦进来，想出去可很难，不过也正是这里，可以给他们一个反省的
机会。往下便是刀山狱了。
LONG
        );
        set("exits", ([
		"up" : __DIR__"youguo",
		"down" : __DIR__"daoshan",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-240);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
