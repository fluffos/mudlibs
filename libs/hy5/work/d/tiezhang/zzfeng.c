// Room: /u/zqb/tiezhang/zzfeng.c

inherit ROOM;

void create()
{
	set("short", "中指峰");
	set("long", @LONG
    这里就是铁掌山的最高峰--中指峰。由于山势太高，峰顶仍存有
大量的积雪，白雪皑皑，在阳光的照射下，泛起一片耀眼的银光。纵目远
眺，湘西几百里景色尽收眼底，泸溪，辰溪如两条玉带，从山下缓缓流过
。远处那条白色的亮线，就是湘西的大江--沅江。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"shanlu-9",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
