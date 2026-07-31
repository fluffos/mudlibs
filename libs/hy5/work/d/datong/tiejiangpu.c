// Room: /open/dt/tiejiangpu.c

inherit ROOM;

void create()
{
	set("short", "铁匠铺");
	set("long", @LONG
一进门，一阵“叮叮当当”的打铁声便不绝于耳。铺子里大
约有十来个伙计，有的在拉风箱，有的把烧得通红的铁块放在铁
占上不停的敲打，你正看得入神，忽听“嗤”的一声，你转头一
看，只见三名老师傅正用铁钳合力把一块剑形黑铁从水池里夹出
来又放到火炉里，瞧着他们吃力的样子，好像那个东西很沉重。
门口挂着一块铁牌子(pai)。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"hongchanglu5",
]));

        set("item_desc", ([ /* sizeof() == 2 */
	"pai" :  "
收购兵器盔甲
修理(fix)兵器
配钥匙(pei key)\n
",
]));

	set("objects",([
	__DIR__"npc/smith" : 1,
]));

	setup();
	replace_program(ROOM);
}
