inherit ROOM;

void create ()
{
 //  reload("长安");
 set ("short", "暗室");
set ("long", @LONG

黑咕隆咚的，你看不见里面有什么。。。。。。
LONG);
  set("exits", ([
    "up" : "/d/xiyou/xueshan/xuelu",
]));
  set("no_clean_up", 1);
  set("outdoor", 1);
  setup();
}

int clean_up()
{
      return 0;
}

