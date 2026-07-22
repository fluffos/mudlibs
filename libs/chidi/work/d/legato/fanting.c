#include <ansi.h>
inherit ROOM;

void init();
int do_tap(string arg);
int do_sit(string arg);
int do_jing(string arg);
int do_stand(string arg);
void delete_served(object me);
int valid_leave(object me, string dir);

void create()
{
      set("short", "饭厅");
      set("long", @LONG
这里是主人的小厨房，中间有几张餐桌(table)和几张餐
椅(chair)，几个侍童在那里打扫着，见你走进来，赶忙
与你打招呼！
LONG
      );

       set("objects", ([
               "/u/legato/npc/xiao shitong": 1,
      ]));


      set("no_fight", "1");
      set("no_steal", "1");

      set("item_desc", ([
            "table" : "一张典雅的桃木小桌，上面放着水果盘和饮茶器具。\n",
            "chair" : "一只青竹打制的靠椅，躺上去摇摇晃晃，好舒服耶！\n",
        ]));

      set("exits", ([
            "east"   : __DIR__"keting",
      ]));

      setup();
}

void init()
{
        add_action("do_tap",  "knock");
        add_action("do_sit",  "sit");
        add_action("do_stand","standup");
        add_action("do_jing", "jing");
}

int do_jing(string arg)
{
      object me;
      object heshang;

      if (!arg || arg != "xiao shitong")
      {
            return notify_fail("你要敲什么？\n");
      }

      me = this_player();
            return notify_fail("你要敬侍童可惜他很忙。\n");
      if (me->query("chanxin/save")==4)
      {
            message_vision("$N恭恭敬敬地敬了侍童一碗酒。\n", me);
            me->set("chanxin/save",5);
            return 1;
      }
      message_vision("侍童对$N做了一揖说：我家公子不许我们喝酒。\n", me);
      return 1;
}

int do_tap(string arg)
{

      object me;
      object heshang;

      if (!arg || arg != "table")
      {
            return notify_fail("你要敲什么？\n");
      }

      me = this_player();
            return notify_fail("你敲了敲桌子，却只响起回音。\n");

      if( !me->query_temp("marks/sit") )
            return notify_fail("你敲了敲桌子，却没想到有只小狗从桌底下钻出来，跑出去了。");

      if( me->query_temp("marks/served") )
      {
            message_vision("侍童不耐烦地对$N说道：刚给你上过茶你接着就要，"+
                                "我还来不及做出来啊！\n", me);
            return notify_fail("");
      }

      message_vision("$N端坐在桌前，轻轻扣了下桌面，侍童一笑，过来招呼。\n", me);


      me->set_temp("marks/served", 1);
//    remove_call_out("delete_served");
      call_out("delete_served", 10, me);

      return 1;
}

void delete_served(object me)
{
        if ( objectp(me) )
              me->delete_temp("marks/served");
}

int do_sit(string arg)
{
      if ( !arg || (arg != "chair") )
            return notify_fail("你要坐什么上面？\n");

      if (this_player()->query_temp("marks/sit"))
            return notify_fail("你已经有了个座位了。\n");

      this_player()->set_temp("marks/sit", 1);
      return notify_fail("你找了个空位座下，等着上茶。\n");
}

int do_stand(string arg)
{
      if (this_player()->query_temp("marks/sit"))
      {
            this_player()->delete_temp("marks/sit");
            return notify_fail("你离开座位站了起来。\n");
      }

      return notify_fail("你还在站着呐，还想飞呀？\n");
}

int valid_leave(object me, string dir)
{
      int i;
      if (this_player()->query_temp("marks/sit"))
      {
            return notify_fail("你还在坐着呐，就想走呀？\n");
      }
      return ::valid_leave(me, dir);
}

