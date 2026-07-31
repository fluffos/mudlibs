// Room: /d/jinghai/moon27.c

inherit ROOM;

void create()
{
	set("short", "烽火台敌楼");
	set("long", @LONG
这里是全水寨的最高了望点。副寨主经常亲临此地，督练水
卒兵勇的训练。了望北方是水寨的码头，南边是水寨大帐。从这
里俯视全寨，可以看见对对兵勇列队而行，整齐划一。可见两位
寨主功不可末。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"moon17",
]));
        set("outdoors","jinghai");
        set("objects",([
        __DIR__"npc/yong1" : 1,
        __DIR__"npc/master9" : 1,
]));


	setup();
	replace_program(ROOM);
}
