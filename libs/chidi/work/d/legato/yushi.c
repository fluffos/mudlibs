// Room: bathroom.c

#include <ansi.h>
inherit ROOM;

void init();
int do_tuo(string arg);
int do_chuan(string arg);
int do_push(string arg);
int valid_leave(object me, string dir);

void create()
{
      set("short", "浴室");
      set("long", @LONG
这里是主人的小浴室，劳累了一天在这里冲个澡可是放松的好办法
对面墙上有一个小按钮(button)，顶上垂下一个精巧的莲蓬头。
LONG
      );

      set("no_fight", "1");
      set("no_steal", "1");

      set("item_desc", ([
            "button" : "一个洗澡的小按钮，一按就出水再按就关闭。\n",
      ]));

      set("exits", ([
            "west"   : __DIR__"workroom",
      ]));

      setup();
}

void init()
{
        add_action("do_push","push");
        add_action("do_tuo", "tuo");
        add_action("do_chuan", "chuan");
}

int do_tuo(string arg)
{
      object me;
      object ob;
      string str;
      if (!arg)
            return notify_fail("你想脱啥？\n");
      if (arg=="all")
            return notify_fail("一件一件脱嘛着啥急？\n");
      me = this_player();
      if (me->query_temp("mark/bathing")>=1)
            return notify_fail("你已经是赤条条的还脱？\n");
      if( !objectp(ob = present(arg, me)) )
            return notify_fail("你身上没有这样东西。\n");
      if( (string)ob->query("equipped")!="worn" )
            return notify_fail("你并没有装备这样东西。\n");

      if( ob->unequip() )
      {
            if( !stringp(str = ob->query("unequip_msg")) )
            {
                  switch(ob->query("armor_type"))
                  {
                        case "cloth":
                        case "armor":
                        case "surcoat":
                        case "boots":
                              str ="$N将$n脱了下来。\n";
                              break;
                        case "bandage":
                              str ="$N将$n从伤口处拆了下来。\n";
                              break;
                        default:
                              str = "$N卸除$n的装备。\n";
                  }
            }
            message_vision(str, me, ob);
            me->set_temp("mark/bathing",1);
            return 1;
      }
      else
            return 0;
}

int do_chuan(string arg)
{
      object me;
      object ob;
      string str;
      me = this_player();
      if (me->is_busy())
            return notify_fail("你还没有洗完呢。\n");
      if (!arg)
            return notify_fail("你想穿啥？\n");
      if (arg=="all")
            return notify_fail("一件一件穿嘛着啥急？\n");
      if( !objectp(ob = present(arg, me)) )
            return notify_fail("你身上没有这样东西。\n");

      if( ob->query("equipped") )
            return notify_fail("你已经装备着了。\n");
      if (me->query_temp("mark/bathing")==2)
            return notify_fail("你还没关水就想穿衣服？\n");
      if( (ob->query("female_only") && (string)me->query("gender") =="男性") )
            return notify_fail("这是女人的衣衫，你一个大男人也想穿，羞也不羞？\n");

      if( ob->wear() )
      {
            if( !stringp(str = ob->query("wear_msg")) )
                  switch( ob->query("armor_type") )
                  {
                        case "cloth":
                        case "armor":
                        case "boots":
                              str = "$N穿上一" + ob->query("unit") + "$n。\n";
                              break;
                        case "head":
                        case "neck":
                        case "wrists":
                        case "finger":
                        case "hands":
                              str = "$N戴上一" + ob->query("unit") + "$n。\n";
                              break;
                        case "waist":
                              str = "$N将一" + ob->query("unit") + "绑在腰间。\n";
                              break;
                        default:
                              str = "$N装备$n。\n";
                  }
            message_vision(str, me, ob);
            me->delete_temp("mark/bathing");
            return 1;
      }
      else
            return 0;

}

int do_push(string arg)
{

      object me;

      if (!arg || arg != "button")
      {
            return notify_fail("你要按什么？\n");
      }

      me = this_player();
      if (me->query_temp("mark/bathing")==2)
      {
            if (me->is_busy())
                  return notify_fail("你还没有洗完呢。\n");
            me->set_temp("mark/bathing",3);
            tell_object(me,"你再按了一下按钮，头上的热水消失了，你觉得全身舒服极了\n",me);
            me->set("qi",me->query("eff_qi"));
            me->set("jing",me->query("eff_jing"));
      }
      else
      {
            if (me->query_temp("mark/bathing")>=1)
            {
                  me->set_temp("mark/bathing",2);
                  tell_object(me,"你按了一下按钮，一股热水又急又密喷了下来，你急忙拿起毛巾,香皂,沙宣洗发水  .............洗的真舒服，你觉得身上的疲惫一扫而光,好爽呀\n",me);
                  me->start_busy(5);
                  me->set_temp("washing", 1);
                  call_out( "compelete_wash", 10, me);
            }
            else
            {
                  tell_object(me,"你按了一下按钮，从头上滴下两滴水灌到你的脖子里你不禁打了个寒噤\n",me);
                  me->set_temp("mark/guang",1);
            }
      }
      return 1;
}

int valid_leave(object me, string dir)
{
      if (me->is_busy())
            return notify_fail("你还没有洗完呢。\n");
      if (me->query_temp("mark/bathing"))
      {
            return notify_fail("你一看自己还没有穿衣服,赶忙溜了回去。”\n");
      }
      else
            return ::valid_leave(me, dir);
}



private void compelete_wash(object me)
{
      me->delete_temp("washing");

      tell_object(me, "你洗好了。\n");
      return;
}

