// Room: /d/hainan/midao.c

inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
山腹中的一条密道,十分陡峭,一路上的碎石很容易划破衣服,但相隔
不多远,在洞壁上就有一颗明珠,照亮通道,所以并不显的黑暗.在有些山壁
上画着些花纹,不过实在看不清是些什么!
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 2 */
  "花纹" : "一中奇怪的花纹,互相缠绕,看久了使人发晕.
",
  "山壁" : "山壁上画有一些花纹.
",
]));
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"midao1",
  "westdown" : __DIR__"xuanya",
]));

	setup();
	replace_program(ROOM);
}
