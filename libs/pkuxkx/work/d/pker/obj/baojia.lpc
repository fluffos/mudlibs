
#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name("金丝甲", ({ "bao jia", "jia" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是平西王收藏多年，爱之如命的一件宝甲，相传是当年魏武帝曹操所用之物
价值连城\n");
                set("material", "gold");
                set("unit", "件");
                 set("value", 50000);
                set("wear_msg", BLU "$N披上了一件华美无比的宝甲。\n" NOR);

                set("remove_msg", YEL "$N将金丝甲脱了下来。\n" NOR);
                  set("armor_prop/armor", 50);
        }
        setup();
}



void init()
{
    add_action("do_sell","sell");
}



int do_sell(string arg)
{
   

   object me,ob,money;
   me=this_player();
   ob=this_object();
if(!(present("tang nan", environment(me)))) {
     write("什么?\n");
     return 1;
    }
 if(!arg||(arg!="bao jia"&&arg!="jia")) return 0;
   switch(random(3))
  {
    case 0:
            message("vision",HIY "老板正忙于算帐，也没怎么看，随手就给了你些钱\n" NOR,me);
            return 0;
            break;
    case 1:
            message("vision","老板细细地看了宝甲半天，嘿嘿一笑：又是走私来的\n水货吧?不要!\n",me);            
            return 1;
            break;
    case 2:
            message("vision","老板向着你微微的笑着，你感到有点不妙\n",me);
            message("vision",RED "两个身着警服的人走了进来，向着"+me->query("name")+"大喝：又是你！这回看你往哪里跑?\n" NOR,environment(me),me);
            message("vision",RED "两个身着警服的人走了进来，向着"+me->query("name")+"大喝：又是你！这回看你往哪里跑?\n" NOR,me);
            me->set("fanfa",1);
            me->move("/d/city/prison");
            me->save();
            return 1;
            break;
   }
 return 1;
}          
