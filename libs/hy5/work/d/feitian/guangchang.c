// Room: /d/city/guangchang.c

inherit ROOM;

void create ()
{
  set ("short", "中央广场");
  set ("long", @LONG
京都的中心就是这里了,一个很宽阔的广场,一些地痞,武士在这里闲逛.
经常有其他国家的艺人在里表演.在广场中央有一棵樱花树(tree).每当
樱花盛开的时候不少人就在这里喝酒赏花,也是就樱花赏了,樱花上的树
叶(leaf)非常茂密,有几只小鸟在这里飞来飞去.大树旁边有一快新立的
牌子(sign).
LONG);

  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/dipi" : 1,
  __DIR__"npc/yiren" : 1,
  __DIR__"npc/wushi" : 1,
]));
  set("peach_count", 30);
  set("item_desc", ([ /* sizeof() == 3 */
  "sign" : "请爱护花草树木，攀爬损毁者重罚！    --京都告示
",
  "leaf" : "树叶松松地挂在树上，看上去很想把它摘下来。
",
  "tree" : "一棵大树，枝叶茂密，看不清上面的情况。枝头挂满了桃子，已经熟地要掉下来了。
",
]));
  set("stick_count", 5);
  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"ximen",
  "north" : __DIR__"beijie",
  "south" : __DIR__"haigang.c",
  "east" : __DIR__"jiedao1",
]));
  set("outdoors", "飞天御剑流");
  set("no_sleep_room", 1);

  setup();
  replace_program(ROOM);
}
