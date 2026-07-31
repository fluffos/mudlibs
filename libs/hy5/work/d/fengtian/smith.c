// Room: /d/fengtian/smith.c

inherit ROOM;

void create()
{
	set("short", "铁匠铺");
	set("long", @LONG
铁匠铺的炉火升的很旺，你一走近就感觉一股热浪扑面而来
，刘铁匠正在这里挥汗如雨的打铁，这里虽然是北方您感觉还是
太热了。门口挂着一块小铁板(ban)。
LONG
	);

	set("item_desc",([
	"ban" : "高价收购兵器、护甲，代客配(pei)钥匙，修理(xiuli)兵器。\n",
]));

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wy6",
]));

	set("objects",([
	__DIR__"npc/smith" : 1,
]));

	setup();
	replace_program(ROOM);
}
