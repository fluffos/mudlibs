#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
         set("short","归元谷");
       set("long", @LONG
走出石室，只见在一深谷之内。前面一座高峰阻路，拔地而起,
直矗天半。四周峰峦都似向它躬揖，谷面内不过十亩方圆地面，怪
松奇石，株株不同。苍皮铁磷，虬干龙枝，似欲临风飞去。
LONG
     );
	set("exits", ([
                "southeast" : __DIR__"xclang",
              //"west"  : __DIR__"nxaju",
            //  "north" : __DIR__"dmtang",
            //  "northwest" : __DIR__"gygu",	
       ]));
        set("coor/x",40);
  set("coor/y",430);
   set("coor/z",130);
   setup();
}
  void init()
            {
              add_action("do_chop","kan");
             }
   int do_chop(string arg)
    {
       object me,weapon;
       me=this_player();
       weapon=me->query_temp("weapon");
       if (!arg) return 0;
       if (arg!="tree") return 0;
       if (!(me->query("pass_xin"))) return 0;
       if (!weapon || weapon->query("id")!="chai dao")
        return notify_fail("你要用柴刀劈树。\n");
    if (me->is_busy() || me->is_fighting()) return notify_fail("你正忙着呢。\n");
       if ((int)me->query("jingli",1)<50)
          return notify_fail("你的精力不够。\n");
       if ((int)me->query("neili",1)<100)
          return notify_fail("你的内力不够。\n"); 
if( me->query_skill("weituo-chu",1)>0 || me->query_skill("riyue-bian",1)>0)
return notify_fail("除非你有达摩老祖的修为，方能同时修习少林三绝技。\n");
      message_vision(RED"$N使开柴刀对准崖边怪松，一刀刀劈去，\n"
                         "松木坚韧，刀光笼罩之下，火星四溅，发出\n"
                         "辟扒燃烧之声。\n" NOR,me);
 me->receive_damage("jingli",30);
  me->receive_damage("neili",30);          
           me->improve_skill("ranmu-daofa", ((int)me->query_skill("blade",1))/4);
           me->improve_skill("blade",1);
           return 1;
      }
