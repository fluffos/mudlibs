// Room: /d/emei/chunyangdian.c
// Modify by Lklv add 恶婆娘丁敏君

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIR "纯阳殿" NOR);
	set("long", @LONG
纯阳殿海拔一千余米，四面古木苍翠，幽静宜人。殿前有一石，叫普贤石，
据说普贤菩萨登山时曾坐在这里休息过。在此可纵观峨嵋诸峰，仰望金顶，悬
崖峭壁，离天咫尺。这里西上至神水庵，东下是归云阁。
LONG
	);
	set("outdoors", "峨眉山");
	set("exits", ([
		"eastdown" : __DIR__"guiyunge",
		"westup" : __DIR__"shenshuian",
	]));
        set("objects",([
		CLASS_D("emei") + "/ding-minjun" : 1,
		"/d/emei/npc/dizi" : 1,
	]));
	setup();
}
