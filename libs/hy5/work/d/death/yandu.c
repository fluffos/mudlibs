// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "酆都狱");
        set("long", @LONG
这里是“哭哭啼啼，凄凄惨惨，不忠不孝伤天理，佛口蛇心堕此门”，
这里关押的囚徒罪名比刚刚的又重了，酆都狱是用来关押的，此类
犯人实在太多，所以在此关押，受刑则送到下面的拔舌狱。
LONG
        );
        set("exits", ([
		"up" : __DIR__"huokeng",
		"down" : __DIR__"bashe",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-140);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
