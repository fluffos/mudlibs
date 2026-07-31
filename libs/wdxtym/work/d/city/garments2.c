// Room: /city/garments.c

inherit ROOM;
void create()
{
	set("short", "成衣店阁楼");
	set("long", @LONG
这里是成衣店的阁楼，这里卖的更加时尚，一直是2010年最热衷的装扮。左右招呼的是曾柔的好友兰兰，若论相貌，即使是曾柔也逊色三分。
旁边放满了裁剪好的衣物，时不时有女人们就为争强打闹开来，
墙上挂着一幅字(zi)，工整异常。想来出自兰兰手笔。
LONG );
	 set("no_fight", 1);
	set("exits", ([
		"down" : __DIR__"garments",
	]));
	set("objects", ([
		__DIR__"npc/lanlan": 1,
	]));
	setup();
}

