//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "乌蒙村落");
	set("long", @LONG
这里是山的缓坡，乌夷人搬石去土，把这里修成一层层阶梯状的
平台，民居分别建在各处平台上，互不连接，各自有石砌围墙，村中
道路也由石头铺成。
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov85",
		"south" : __DIR__"minov86",
		"west" : __DIR__"minov81",
		"east" : __DIR__"minov87",
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
