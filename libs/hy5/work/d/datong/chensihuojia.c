// Room: /open/dt/chensihuojia.c

inherit ROOM;

void create()
{
	set("short", "陈思霍家");
	set("long", @LONG
幕府师爷陈思霍是位绍兴人，素来信奉“公门之中好修行”
这句名言。那是说那是说官府手操百姓生杀大权，师爷拟稿之际
几字略重，便能令百姓家破人亡，稍加开脱，即可使之死里逃生，
因之在公门中救人，比之在寺庙中修行效力更大。因此，这位陈
师爷虽然有点儿贪财，但为人尚称公正。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"hongchanglu6",
]));

	setup();
	replace_program(ROOM);
}
