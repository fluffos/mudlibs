// jianshi.c
// By River 98.10
inherit ROOM;
#include <ansi.h>

void create()
{
      set("short", HIC"剑室"NOR);
      set("long", @LONG
一间摆满兵器的石室，很多种剑都整齐地堆放在地上。周围的火把照的整
个石室灯火通明，几个古墓弟子正站在室中仔细挑选自己合手的兵刃。墙角放
着一个木制的护具架(jia)，上面挂着些古墓弟子平时防身用的护具。
LONG
      );

      set("exits", ([
	    "south" : __DIR__"gmqs",
      ]));

      set("item_desc", ([
           "jia" :"一个木头制成的架子，上面挂着铁甲(armor)等护具。\n\n"+
                  "命令格式: na armor from jia。\n",
      ]));

      set("objects", ([
              BINGQI_D("changjian") : 1,
              BINGQI_D("gangjian")  : 1,
              BINGQI_D("duanjian")  : 1,
              BINGQI_D("zhujian")   : 1,
              BINGQI_D("mujian")   : 1,
      ]));
      setup();
}

void init()
{
      add_action("do_get",({"get","na"}));
}

int do_get(string arg)
{
      object me,ob;
      string arg1,arg2;
      me=this_player();
      if(!arg || sscanf(arg, "%s from %s", arg1, arg2)!=2)
          return notify_fail("命令格式: na <护具名称> from jia。\n");
      if (arg2!="jia")
          return notify_fail("命令格式: na <护具名称> from jia。\n");
      if(me->query_temp("gumu/拿"))
          return notify_fail("你怎么这么贪心，拿过了还要拿？\n");
      if(me->query("combat_exp") > 120000)
          return notify_fail("你武艺已到一定程度，还是自食其力吧。\n");
      if (arg1 =="armor"){
          ob=new(ARMOR_D("armor")); 
          ob->move(me);
          message_vision("$N从护具架上拿出一件$n。\n",me, ob); 
          me->set_temp("gumu/拿",1);
          return 1;
      }     
      return notify_fail("护具架上没有你想要拿的东西。\n");
}

int valid_leave(object ob, string dir)
{
        string* jian = keys(query("objects"));
        object* sword = deep_inventory(ob);
        int i = sizeof(sword), count = 0;
        while (i--)
                if (member_array(base_name(sword[i]), jian) != -1) count++;
        if (count > 1) return notify_fail("你一下子拿这么多剑，别人不要用了吗？\n");
        return ::valid_leave(ob, dir);
}
