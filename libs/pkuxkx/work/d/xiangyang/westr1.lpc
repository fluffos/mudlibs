// Modified by iszt@pkuxkx, 2007-04-03

inherit ROOM;

void create()
{
	set("short", "乡间土路");
	set("outdoors","xiangyang");
	set("occupied",1);
	set("long", @LONG
这里是襄阳城西的土路。开战以前，这里的老百姓本来过着平静的生活，大
军一到，人们死的死，亡的亡，路边残垣断壁，尸骨累累，残不忍睹。
LONG);

	set("exits", ([
		"east" : __DIR__"wgate",
		"west" : __DIR__"westr2",
	]));

	setup();
	replace_program(ROOM);
}