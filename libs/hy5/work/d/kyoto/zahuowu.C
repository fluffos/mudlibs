// Room: d/kyoto/zahuowu.c
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "杂货屋");
set("long", @LONG
这是一间历史悠久的杂货屋，老板吉田以买卖公道著称，所以来这里的
客人络绎不绝，而且一些穷困潦倒的剑士会把知名的宝剑抵押在这里，传说
曾经有人更在这里发现了失传已久的无我流心法要决，之后各地剑客都来这
里，希望能有朝一日买到一本至高无上的武籍。你可以看看牌子(paizi)，
看看现在有哪些东西出售。
LONG );
set("item_desc", ([
		"paizi": "请用 \"list\" 列出货物表，\"buy\" 向老板购物。\n",
	]));
set("exits",  ([
        "south"  : __DIR__"xijingting1",
      ]));
      set("objects", ([
		__DIR__"npc/jitian": 1,
	]));
        setup();
        replace_program(ROOM);
}