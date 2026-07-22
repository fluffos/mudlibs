// Room: /d/yandang/shanlu7.c

inherit ROOM;

void create()
{
	set("short", "照胆潭");
	set("long", @LONG
果盒岩向下,就到了照胆潭,潭水碧绿阴森,一股寒气扑面而来,令人
心寒,水自潭中的腾波岩中流出,汇为深潭,绿如胆汁.当雨后初晴,水流
与阳光映照,在高处望去,可见彩虹横贯.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"shanlu5",
  "west" : __DIR__"shanlu8",
]));

	setup();
	replace_program(ROOM);
}
