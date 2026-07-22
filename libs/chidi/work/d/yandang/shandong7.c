// Room: /d/yandang/shandong7.c

inherit ROOM;

void create()
{
	set("short", "凉风洞");
	set("long", @LONG
进入洞中,只见洞壁上布满了大大小小的小石洞,天风刮过,响起阵
阵'呜.....呜....'的声音.洞的正中有一根石柱从洞顶垂下,从石壁中
刮进来的风在洞中形成一股旋风,绕着石柱旋转.强烈的风势刮得你衣抉
欲飞.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"dongwai.c",
  "southdown" : __DIR__"shandong6.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
