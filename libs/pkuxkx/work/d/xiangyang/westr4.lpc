// Modified by iszt@pkuxkx, 2007-04-03

inherit ROOM;

void create()
{
	set("short", "乡间土路");
	set("outdoors","xiangyang");
	set("occupied",1);
	set("long", @LONG
这里是襄阳城西的土路。这里离村庄比较远，路已渐渐没了。路边杂草丛生，
荆棘密布，不时有小兽出没。
LONG);

	set("exits", ([
		"east" : __DIR__"westr3",	
		"west" : __DIR__"westr5",
	]));

	setup();
	replace_program(ROOM);
}