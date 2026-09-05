// shen_dan2.c 神丹

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIG"神丹"NOR, ({"exp dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long",
                "这是一颗"HIG"神丹"NOR"，据说吃了大有好处。\n");
                set("value", 50000);
          //      set("no_get", 1);
                set("no_drop", "这东西不能扔。\n");
                set("no_steal", 1);

        }
        setup();
}

int do_eat(string arg)
{
//        int exp_limit, add_exp, improve;

        object me = this_player();

  //      exp_limit = 500000;
    //    add_exp = me->query("combat_exp");


        if (!id(arg))
        return notify_fail("你要吃什么？\n");


      //  if ( add_exp > exp_limit  )
        //{
         //       return 0;
        //}
        //else if ( add_exp <= exp_limit  )
        {
/*              improve = force_limit - neili_limit;

                if ( improve < 100 ) {
                        add_skill = force_skill + (100 - improve)/5 + 1;
                        me->set_skill("force", add_skill );
                }
*/
                me->add("combat_exp", 500);
                me->add("potential",25);
                me->add("max_neili", 20);
                me->add("max_jingli", 20);
     // me->save();

                message_vision(HIY "$N吃下一颗仙丹，顿然间得精神了许多...\n" NOR, this_player());
  //              me->apply_condition("bonze_drug", 2000);
        }

    //    me->unconcious();
        destruct(this_object());
        return 1;
}
