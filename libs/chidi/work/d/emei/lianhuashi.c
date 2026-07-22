// Room: /d/emei/lianhuashi.c 峨嵋派 莲花石


inherit ROOM;


void create()
{
	set("short", "莲花石");
	set("long", @LONG
这是连接九老洞旁的一个支洞，在左边高处有一块形状酷似莲花
的大石(stone)，此石晶莹剔透，宛若碧玉。在阳光照射下，发出淡淡
光华。经常有人这里静坐，以求得道修得正果。
LONG
	);

	set("exits", ([
                "west":__DIR__"jiulaodong",
                "out": __DIR__"podao1",
	]));

	set("objects",([
	]));

	setup();
}
