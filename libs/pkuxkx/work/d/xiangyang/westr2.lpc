// Modified by iszt@pkuxkx, 2007-04-03

inherit ROOM;

void create()
{
	set("short", "乡间土路");
	set("outdoors","xiangyang");
	set("occupied",1);
	set("long", @LONG
这里是襄阳城西的土路。开战以前，这里本来是个不小的村庄，大军一到，
人们死的死，亡的亡，路边残垣断壁，尸骨累累，残不忍睹。只剩下几家，还好
象有人居住的样子。
LONG);
	set("exits", ([
		"east" : __DIR__"westr1",
		"west" : __DIR__"westr3",
		"north" : __DIR__"wehouse",
	]));

	setup();
	replace_program(ROOM);
}