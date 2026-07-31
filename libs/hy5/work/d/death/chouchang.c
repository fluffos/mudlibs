// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "抽肠狱");
        set("long", @LONG
这里似乎与别处又是不同，没有大刑具，所有的东西就是几把钩子和
几把解牛刀，鬼卒熟练的用刀剖开肚子，钩子一钩，便是一声惨叫，
听着这声音，头皮发麻的你发誓以后绝不做坏事了，遍地的肠子让人
只做呕，但是心中又多了一分向善之心。这里往下便又是一种了。
LONG
        );
        set("exits", ([
		"up" : __DIR__"tuoke",
		"down" : __DIR__"youguo",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-220);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
