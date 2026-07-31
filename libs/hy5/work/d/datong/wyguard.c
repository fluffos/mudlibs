// Room: /open/dt/wyguard.c

inherit ROOM;

void create()
{
	set("short", "威远镖局");
	set("long", @LONG
威远镖局规模并不是很大，总镖头周全泰是个老江湖了，他
吃这行饭有十多年了，虽然没有保过什么很贵重的镖，但所幸也
没有失过手，所以名声还不错。大同城里的客商们要是想送些红
货到内地去一般都送到威远镖局来。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"tanhuanglu3",
]));

	setup();
	replace_program(ROOM);
}
