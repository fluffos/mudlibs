//huayuan.c 花园
// By River 99/05/20
inherit ROOM;
#include <ansi.h>
void create()
{
          set("short",HIM"花园"NOR);
          set("long",@LONG
这里是花园，种满了情花树(flower)，西北方是一个小池塘，眼下正值六
月，池塘内荷花都绽开了花朵，几只青蛙趴在荷叶上“呱呱”地叫个不停。西
南方一座假山（hill），南面是一条长廊。
LONG
    );
          set("item_desc",([
                "flower": "树枝叶上生满小刺，情花花瓣的颜色娇艳无比，诱得你忍不住去摘下来。\n",
                "hill": "这是一座假山，一块巨石挡在山前，看上去这块巨石似乎有些奇怪，\n"+
                        "巨石后面似乎有些不同寻常，二名绿衣弟子守在假山前。\n",
          ]));

          set("outdoors","绝情谷");
	  set("exits",([
              "south": __DIR__"lang1",
          ]));  

          set("objects",([
                 __DIR__"npc/dizi1" : 2,
          ]));
          setup();
}

void init()
{
          add_action("do_zhai","zhai");
}

int do_zhai(string arg)
{    
          object me = this_player();
          if (!arg || (arg != "flower"))
              return notify_fail("你要摘什么啊？\n");
          if (me->is_busy() || me->is_fighting())
	      return notify_fail("你正忙着哪！\n");
          if (present("flower", this_player()))
	      return notify_fail("你身上不是有么，还想要，太贪心了。\n");
          if(me->query_condition("medicine"))
              return notify_fail("你刚摘过，这么快就还想要？\n");
          message_vision(HIY"$N避开枝上尖刺，伸手去摘"HIM"情花"HIY"，落手甚是小心。\n"NOR, this_player());
          new(__DIR__"obj/flower")->move(me);
          me->start_busy(2);
          if ( random(me->query("per")) < 10 ){
          message_vision(HIY"岂知花朵背後隐藏著小刺，将$N的手指给刺破了。\n"NOR, this_player());
          me->apply_condition("qinghua_poison", me->query("per") + random(me->query("per"))); 
          return 1;
          }
          else {
          message_vision(HIY"$N绕开花朵背后的小刺，伸手将"HIM"情花"HIY"摘了下来。\n"NOR, this_player());
          return 1;
          }
}
