// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 4/8/1997
// room: /d/westway/yunti.c

inherit ROOM;

void create ()
{
  set ("short", "云梯冈");
  set ("long", @LONG

云梯冈位于酒泉的北部，山冈不是很高。南边一条石头小路将山
下和山上连接起来，前面山壁上有一个山洞，洞口全是碎石头。
往北山路蜿转不定，遥遥可见山势清奇，不知通往何处。

LONG);

  set("exits", ([
        "enter"     : __DIR__"shandong",
        "southdown" : __DIR__"jiuquan",
        "north" : "/d/qujing/wuzhuang/shanlu1",
      ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object me, string dir)
{
  if (random(2)==0 && dir=="enter")
  {
    message_vision ("哗啦啦一阵碎石头响，$N从山壁上斜滑了下来！\n",me);
    me->move(__DIR__"jiuquan");
    message_vision ("$N滚到一个坡底才停下来！\n",me);
    call_out ("fall_back",2,me);
//    return notify_fail("");
    return 2; // mon 7/10/99 return 2 indicating fail but let go.c exit 1.
              // if return 0 here then possibly to have error since 
              // me is moved to another room in add_action.
  }
  return 1;
}

void fall_back (object me)
{
  tell_object (me,"你在地上呆坐了几秒钟，慢慢站起来。\n");
}


