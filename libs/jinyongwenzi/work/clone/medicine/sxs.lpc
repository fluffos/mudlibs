// 散
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIB "三笑逍遥散" NOR, ({ "sanxiao san", "san" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "包");
                set("long", "一包蓝色的散剂，一看就含有剧毒。\n");
                set("value", 1000);
                set("material", "paper");   
                set("no_sell", 1);             
        }
        setup();
}

int init()
{
        add_action("do_tan", "tan");
}

int do_tan(string arg)
{
       object me, ob;
       int i;
       string msg;
       mapping fam;
       me = this_player(); 
       fam = me->query("family");  

       if (!fam || fam["family_name"] != "星宿派")
               return notify_fail("你不是星宿弟子，所以不懂这个东西如何使用。\n");

       if( me->is_busy() || me->is_fighting())
               return notify_fail("你正忙着呢。\n");

       if (!arg) return notify_fail("你要对谁下手？\n");       

       ob = present(arg, environment(me));
       if (!ob) return notify_fail("找不到这个生物。\n");

       i = ob->query_skill("dodge", 1) + ob->query_skill("parry", 1);
       i = random(i/2) - 20;

       if( environment(me)->query("no_fight") )
                return notify_fail("你不能在这里动手。\n");

       if(me->is_busy())
                return notify_fail("你正忙着呢。\n");

       if(me->query("neili") < 500)
                return notify_fail("你的内力不够用来动手。\n");

       msg = BLU"\n$N轻轻挥了挥袖袍！\n"NOR;       
       me->start_busy(2);
       me->add("neili", -100);
       me->add("jingli", -20);
       if(me->query_skill("force", 1) > i 
        && random(ob->query_con()) < 20
        && me->query("max_neili") > (int)ob->query("neili")/2 ) {
              ob->apply_condition("sxs_poison", 5);
       }
       else {
          msg +=RED"$n凭着深厚的内力，将三笑散的威力硬生生顶了回去。\n"NOR;
          msg +=RED"$N感觉到三笑散的毒已经侵入了自己体内。"NOR;
          ob->add("jingli", -50);
          me->apply_condition("sxs_poison", 5);
       }              
       message_vision(msg, me, ob);
       destruct(this_object());
       return 1;
}
