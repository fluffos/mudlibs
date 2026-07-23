// Room: /u/xdd/gumu/gmqinroom.c
// Modify By River 98/08/30
#include <ansi.h>;
inherit ROOM;
#include <room.h>
void create()
{
          set("short", HIC"琴室"NOR);
          set("long", @LONG
一张石桌(table)，一条石凳，桌上放着一把古琴(qin)，是小龙女休憩时
刻抚琴抒怀的地方。每每琴音袅袅，平淡清和，直引人心弛神往，与世无争。
LONG        );

          set("exits", ([
               "west" : __DIR__"houting", 
          ]));

          set("item_desc", ([
                "qin" : HIC"这是一把年代极远的古琴，琴风古朴，暗蕴玄机。
琴上刻着[ 至远 宁心 渡风 ] 六个字。\n"NOR,
                "table" : "桌上放着一把古琴。 \n",
                  ]));
//          create_door("east", "石门", "west", DOOR_CLOSED);
          setup();
}

void init()
{
          add_action("do_tan", "tan");
          add_action("do_nuo", "nuo");
          add_action("do_yanxi","yanxi");
}

int do_tan(string arg)
{
          mapping fam;
          object me = this_player();

          if (arg == "qin"){
          if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
           return notify_fail("你不是古墓传人，如何能领悟古墓武功？\n");
          if (me->query("qi") < 30 || me->query("jing") < 30)
           return notify_fail("你精神恍忽, 先去歇息一会再来弹琴吧。\n");
          write(HIC"你闭目调理一会气息, 心神宁静的抚琴而弹。\n"NOR);
          if (me->query_skill("force", 1) < 50 )
          return notify_fail("你弹了半天, 琴声仿若鸦鸣, 你还是弹棉花去吧。\n");
          if (me->query_skill("force", 1) > 100){
          message_vision(HIC"$N心随弦走，融入琴境，伴随琴声，高声吟道：\n"BLINK HIY"
\t沧海一声笑 滔滔两岸潮
\t浮沉随浪 只记今朝
\t苍天笑 纷纷世上潮
\t谁负谁胜出 天知晓
\t江山笑 烟雨遥
\t涛浪淘尽 红尘俗世几多娇
\t清风笑 竟惹寂寥
\t豪情还剩了一襟晚照
\t苍生笑 不再寂寥
\t豪情仍在 痴痴笑笑\n"NOR,me);
           return 1;
           }
//        return notify_fail("你内功精湛, 弹琴已无益于你修行内力. \n");
          write("你心随弦走, 融入琴境, 渐渐心气平和, 周身真气自然流动。\n");
          me->receive_damage("qi", 15+random(10), me);
          me->receive_damage("jing", 15+random(10), me);
          me->improve_skill("force", (int)(me->query_con()/4) +
                        (int)(me->query_skill("force", 1)/4) );
          return 1;
          }
          write("你要弹什么? 弹棉花? \n");
      return 1;
}

int do_nuo(string arg)
{
         object me = this_player();
         if (arg == "qin"){
         message_vision(YEL"$N轻轻地挪开了古琴。\n"NOR, me);
         write(HIC"琴下的桌面上居然刻着一篇文字。\n"NOR);
         me->set_temp("marks/qin", 1);
         return 1;
         }
         return notify_fail("你要挪什么? \n");
}

int do_yanxi(string arg)
{
         mapping fam;
         object me = this_player();
         if (arg == "table"){
         if (me->query_temp("marks/qin")){
         if (me->query("potential", 1) < 1)
             return notify_fail("你的潜能没了，不能再继续修习了\n");
         if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
          return notify_fail("你不是古墓传人，如何能领悟古墓武功？\n");
         if (me->query("qi") < 40 )
          return notify_fail("你的精神很差, 改先去休息一会. \n");           
         if (me->query_skill("force", 1) < 40)
          return notify_fail("你的基本内功太低，无法研习更高级的内功。\n");        
         if (me->query_skill("yunv-xinfa", 1) < 50)
          return notify_fail("你的玉女心经等级太低，无法领悟桌上的文字。\n");
         if (me->query_skill("yunv-xinfa", 1) > 100)
          return notify_fail("你的玉女心经精进一层，可以双人合修玉女神功了。\n");
         write("你开始研习桌上的玉女心经。\n");
         me->improve_skill("yunv-xinfa", (int)(me->query_int()/2) +
                           (int)(me->query_con()/2) );
         me->receive_damage("qi", 15 + random(20));
         me->add("potential", -1);
         return 1;
         }
        return notify_fail("你对着桌上的古琴研究了一番，发现它很值钱。\n");
     }
    return notify_fail("你要研习什么？\n");
}
