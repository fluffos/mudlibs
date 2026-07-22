// shandong.c
// By River 98/09 
inherit ROOM;

#include <ansi.h>

string mu(object);
string zi(object);
string tai(object);

void create()
{
        set("short", HIB"大山洞"NOR);
        set("long", @LONG
这洞其实甚浅，行不到三丈，已抵尽头，洞中除了一张石桌、一张石凳之
外更无别物。洞角有一堆乱石高起，极似一个坟墓，洞壁上似乎写得有字，只
是尘封苔蔽，黑暗中瞧不清楚。
LONG
        );

        set("item_desc", ([        
           "deng" : "一张普通的石凳，看来很久没人坐过了，上面满是灰尘。\n",
           "mu" : (: mu :),
           "qingtai" : (: tai :),
           "tai" : (: tai:),
           "zi" : (: zi :)
        ]));

        set("exits", ([ 
            "out"  : __DIR__"dongkou",
        ]));
    
        setup();
}

string tai(object me)
{
      if(!me->query_temp("xuantie/light"))
          return "洞里面黑黝黝的，你什么也看不清楚。\n";
      if((int)me->query_skill("force", 1) < 100)
          return  "壁上满是青苔和灰尘。\n";
          me->set_temp("xuantie/qingtai", 1);
          me->delete_temp("xuantie/light");
          return  "壁上满是青苔和灰尘，青苔下面似乎刻着一些小字。\n";
}

string zi(object me)
{ 
      if(!me->query_temp("xuantie/qingtai"))
         return "你要看什么？\n";
      if(!me->query_temp("xuantie/mo"))
         return "壁上满是青苔和灰尘，你无法看清这些小字。\n";
         me->delete_temp("xuantie");
         me->set_temp("xuantie/zi", 1);
         return HIY"\n\t纵横江湖三十馀载，杀尽仇寇，败尽英雄，天下更无抗手。\n"+
                "\t无可柰何，惟隐居深谷，以雕为友。\n"+
                "\t呜呼，生平求一敌手而不可得，诚寂寥难堪也。\n\n"+ 
                "\t\t\t\t\t\t剑魔独孤求败\n"NOR;
}

string mu(object me)
{
     if( !me->query_temp("xuantie/zi"))
        return  "你终究看不出来这是谁的坟墓。\n";
     else {
        me->set_temp("xuantie/mu", 1);
        me->delete_temp("xuantie/zi");
        return "那个石堆的坟墓上也无其他标记，料是这位独孤求拜死後，是神雕衔石堆在他尸身之上。\n";
        }
}

void init()
{ 
      add_action("do_zuan","zuan");
      add_action("do_use", "dian");
      add_action("do_mo", ({"mo", "clean"}));
      add_action("do_kneel",({"kneel", "guibai"}));
}

int do_use(string arg)
{
      object me=this_player(), ob;
      if(me->is_busy() || me->is_fighting())
         return notify_fail("你正忙着哪！\n");
      if(!(ob=present("xiao shuzhi", me)) )
         return notify_fail("你没有引火之物！\n");
      if(! present("fire", me ))
         return notify_fail("你拿什么点火？\n");
      if( arg == "shuzhi"){
      message_vision(HIR"$N点燃了小树枝，周围马上亮了起来！\n"NOR, me);
      me->set_temp("xuantie/light", 1);
      me->start_busy(1);
      destruct(ob);
      return 1;
      }
      return notify_fail("你要点燃什么？\n");
}

int do_mo(string arg)
{
      object me=this_player();
      if(me->is_busy() || me->is_fighting())
         return notify_fail("你正忙着哪！\n");
      if( !arg || arg !="qingtai") return 0;
      if(!me->query_temp("xuantie/qingtai"))
         return notify_fail("你伸手在青苔上抹了几下，不小心弄胀了手。\n");
       tell_room(environment(me), me->name() + "附下身躯，伸手抹去洞壁上的青苔。\n"NOR, ({ me }));
       me->set_temp("xuantie/mo", 1);
       me->start_busy(1);
       write("你抹去青苔，现出三行字来，字迹笔划甚细，入石却是极深，显是用极锋利的兵刃划成。\n");
       return 1;
}

int do_kneel(string arg)
{
      object me = this_player();      
      if(me->is_busy() || me->is_fighting())
         return notify_fail("你正忙着哪！\n");
      if((!arg) || (arg != "mu")) return 0;
      if(!(int)me->query_temp("xuantie/mu"))
         return notify_fail("不要随便下跪嘛！\n");
       tell_room(environment(me), me->name() + "在石墓之前跪拜，拜了四拜。\n"NOR, ({ me }));
       write("你出了一会神，不自禁的在石墓之前跪拜，拜了四拜。\n");
       write(HIW"\n跪拜之际忽然发现山洞北面似乎有个出口，透过来一丝光亮。\n"NOR);
       me->delete_temp("xuantie");
       me->set_temp("xuantie/mu1", 1);
       me->start_busy(1);
       return 1;
}

int do_zuan(string arg)
{
       object me=this_player(),*ob;
       int i;
       if (!me->query_temp("xuantie/mu1")) return 0;
       if (me->is_busy() || me->is_fighting())
         return notify_fail("你正忙着哪！\n");
       if ( !arg || arg != "dong")
         return notify_fail("你往哪里钻啊？\n");
       ob = deep_inventory(me);
       i = sizeof(ob);
       while (i--)
       if (ob[i]->is_character())
          return notify_fail("洞口并不甚大，你只觉背负一人实在难以通过。\n");
       tell_room(environment(me), me->name() + "往洞后的"YEL"深谷"NOR"钻了出去。\n"NOR, ({ me }));
       me->move(__DIR__"shanlu7");
       me->delete_temp("xuantie");
       me->start_busy(1);
       write(HIW"\n你一矮身穿过小洞来到洞後，只见树木苍翠，山气清佳。\n"NOR);
       tell_room(environment(me), me->name() + "从"HIB"大山洞"NOR"里钻了出来。\n"NOR, ({ me }));
       return 1;
}
