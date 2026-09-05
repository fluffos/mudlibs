//吴起
//03-7-12

#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", "天阁斋分店"NOR);
	set("long", @LONG
这是老字号钱庄天阁斋位于凌霄城的分店，开了大约有几十年了，天阁
斋在全国各地都有分店。它发行的银票信誉非常好，通行全国。墙上挂有一
个牌子(sign)。
LONG);

	set("indoors", "凌霄城");
	set("item_desc", ([
		"sign" : "你可以在这里：
        查帐(check, chazhang, 查帐)
        存款(deposit, cun, 存)
        取款(withdraw, qu, 取)
        兑换(convert, duihuan, 兑换)

所有的金、银、铜钱、银票。\n",
	]));
	set("exits", ([
		"west" : __DIR__"bingjie2",
	]));
	set("objects", ([
		__DIR__"npc/dizi_free" : 1,
		__DIR__"npc/zhengwanjin" : 1,
	]));

	setup();
}

