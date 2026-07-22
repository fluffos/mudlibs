// Room: /d/feitian/kefang.c
inherit ROOM;

void create()
{
  set ("short", "厢房");
  set ("long", @LONG
神古活心流的厢房，门下弟子练累了可以在这里休息一下。地下铺
了三个床已经有人在这里开始睡了，你忍不住打了个哈欠.还是赶
快找个位置睡觉吧！
LONG);

  set("no_clean_up", 1);
        set("sleep_room", "1");
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"chufang",
  "west" : __DIR__"daochang",
]));
  set("no_fight", 1);
  set("no_magic", 1);
  setup();
  replace_program(ROOM);
}
