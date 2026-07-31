// Room: /d/jinghai/moon9.c

inherit ROOM;

void create()
{
	set("short", "明月寨大帐");
	set("long", @LONG
这里是明月水寨的寨主大帐，正中间放着一把虎皮椅，椅子
上坐着明月寨的统领青龙堂堂主赵之玄。他若有所思的伏在一张
条案上。条案上整齐的码放着看似令鉴的东西。两侧分别各有一
队头带红巾的士卒和蓝巾的锦衣刀斧手，面无表情的站立着。让
人感觉有些拘谨，浑身不自在，连喘气都不敢大声。左边的木柱
上挂着一副[gaoshi]。
LONG
	);
        set("item_desc",([
        "gaoshi" : "
通喻：
一. 凡靖海弟子必须遵守水寨条例各章。
违反者予以重罚。
二. 凡靖海弟子领取武器及杂物须告之
师父，发给令牌者。 可
三. 凡靖海弟子调用一十六路水寨船只
须通晓寨主，发给令牌方可调动。

             明月统领 赵\n"
]));

	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"moon21",
  "north" : __DIR__"moon8",
  "southwest" : __DIR__"moon20",
]));


        set("objects",([
        __DIR__"npc/master8" : 1,
        __DIR__"npc/yong1" : 2,
        __DIR__"npc/yong2" : 2,
]));


	setup();
	replace_program(ROOM);
}
