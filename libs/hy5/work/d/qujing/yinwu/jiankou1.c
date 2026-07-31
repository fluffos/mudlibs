// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "涧口");
  set ("long", @LONG

山石高耸之处，有斜坡自两岸缓缓而下，底下是潺潺流水之声
不断，涧水冲击着流水中的大小石块，发出一阵阵震耳欲聋的
轰鸣浪声，近处有几条暗沟。

LONG);

  set("exits", ([
        "northup"    : __DIR__"xuanya7",
      ]));
  set("outdoors", "xy32");
  setup();
}

void init ()
{
  add_action ("do_dive","dive");
}

int do_dive (string arg)
{
  object who = this_player ();

  message_vision ("$N往水里一扎潜了下去……\n",who);

    who->move(__DIR__"tianjing");
  return 1;
}
