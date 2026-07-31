// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "脱壳狱");
        set("long", @LONG
这里似乎和剥皮狱差不多，不过这里的犯人是皮肉和骨头分离，把活
人变为骷髅，然后再把皮肉贴上去，循环往复，其间痛苦实在难以抵
挡，许多囚犯经历这层以后变改邪归正，从此成为良善之徒。你看见
了不少似曾相识的面孔。再往下会是什么呢？
LONG
        );
        set("exits", ([
		"up" : __DIR__"hanbing",
		"down" : __DIR__"chouchang",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-210);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
