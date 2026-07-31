//Room: hcaxiuxishi.c 华藏庵休息室
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","华藏庵休息室");
      set("long",@LONG
这里是峨嵋华藏庵的休息室。窗帘拉下来，房里整整齐齐放了很多木床。
有几个夜晚守庵的小师太正在睡觉。
　　休息室外就是禅房。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "north" : __DIR__"hcachanfang", 
      ]));
      set("sleep_room", 1);
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
void init()
{
//      add_action("do_jingzuo", "jingzuo");
}

int do_jingzuo()
{
      mapping myfam;
      object me;
      int jing_cost,qi_cost,skillslvl;

      me = this_player();
      myfam = (mapping)me->query("family");
      skillslvl = (int) me->query_skill("mahayana",1);

      if (me->is_busy()) return 0;
      if ((skillslvl<10) || !myfam || (myfam["family_name"] != "峨嵋派"))
         return 0;
      jing_cost = 600 / (int)me->query("int");
      qi_cost = 500 / (int)me->query("int");

      me->receive_damage("jing", jing_cost );
      me->receive_damage("qi", qi_cost );
      if (random((int)100/skillslvl)==0)
      {
           me->add("potential",1);
           me->add("combat_exp",1);
      }
      write("静坐完，你觉得特疲劳。休息一下吧！\n");
      me->start_busy(3);
      return 1;
}
