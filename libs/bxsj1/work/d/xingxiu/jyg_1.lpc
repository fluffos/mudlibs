// Room: /d/xingxiu/kyg_1.c

inherit ROOM;

void create()
{
        set("short", "天阁斋分店");
        set("long", @LONG
这是老字号钱庄天阁斋位于嘉峪关的分店，开了大约有几十年了，天阁
斋在全国各地都有分店。它发行的银票信誉非常好，通行全国。墙上挂有一
个牌子(sign)。
LONG);
        set("no_fight", "1");
        set("exits", ([
                "north" : __DIR__"jyg",
        ]));

        set("item_desc", ([
                "sign" : "\n你可以在这里：
        查帐(check, chazhang, 查帐)
        存款(deposit, cun, 存)
        取款(withdraw, qu, 取)
        兑换(convert, duihuan, 兑换)

所有的金、银、铜钱、银票。\n",
        ]) );
        set("objects", ([
                __DIR__"npc/huang" : 1,          
        ]));

        set("coor/x",-210);
  set("coor/y",60);
   set("coor/z",-10);
   setup();
}
