// 秘密花园
// edit: by zine Sep 26 2010

inherit ROOM;

#include <ansi.h>


void create()
{
	set("short", "望江亭");
	set("long", @LONG
    这是长江岸边的一座小亭，虽然没有雕龙画凤，却是青山之畔，大江之滨的一处所在。
从这里望出去，只见滚滚长江东去，江面上白帆点点，一眼望不到边。你不禁胸中豪气
大生，只觉得这世间万事，都不过如此。
LONG
	);
	set("exits", ([ 
        "south":"/d/wizard/wizard_room_jason",
	]));
    set("objects", ([
        CLASS_D("wudang") + "/zhang" : 1 ]));
	setup();	
}

void test()
{
    write(HIY"张三丰悠悠吟道：\n悟得惺惺学到痴，到无为处无不为。\n两脚任踏尘里去，一心只有命相随。\n眼前世事只如此，耳畔风声总不知。\n"NOR);
    write(WHT"> baishi zhang sanfeng\n"NOR);
    write(GRN"你见到名满天下的张真人就在眼前，扑通一声跪倒，砰砰砰的磕了三个头，口中说道：小生何不去，恳请真人收录门墙！愿苦学武术，匡扶正义，光大武当！\n"NOR);
    write(GRN"张三丰微微一笑，伸出右手，向上轻轻虚托，你感到一股柔和但强大的力量将你托起，竟是跪不下去。\n"NOR);
    write(WHT"> ask zhang sanfeng about 武学\n"NOR);
    write(GRN"你向张三丰请教武学的事情。\n"NOR);
    write(GRN"张三丰并不答话，扬手在空中轻轻挥了三下，转身飘然离去。\n"NOR);
    write(WHT"> consier\n"NOR);
    write(GRN"你陷入了沉思。\n"NOR);
}
