// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "地藏殿");
        set("long", @LONG
在这地府之中，居然有一处仙宫，实在难以置信，这是幽冥教主
地藏菩萨的寝宫，相传地藏原为朝鲜王子，修练得道于九华，因其公
正无私，故掌万物轮回，座下神兽谛听，善听人言辨真伪。但凡阎王
有难决之案，皆送至此处，由地藏菩萨处置，菩萨便以那无边慈航，
广渡众生。
LONG
        );
        set("exits", ([
		"southup" : __DIR__"beiyin",
        ]) );
       set("objects", ([
                __DIR__"npc/pusa" : 1,
        ]) );

	set("coor/x",-1020);
	set("coor/y",-40);
	set("coor/z",-100);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
