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
        set_name(HIG"仙丹"NOR, ({"exp dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long",
                "这是一颗"HIG"仙丹"NOR"，据说有长生不老的功效。\n");
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
                me->add("str", random(2));
		     me->add("con", random(2));
		     me->add("int", random(2));
	   	     me->add("dex", random(2));
		me->add("mud_age", -36100);
		      // me->save();

  //              me->apply_condition("bonze_drug", 2000);
        }
message_vision(HIY "$N吃下一颗仙丹，大叫一声，我是超人....\n" NOR, this_player());


    //    me->unconcious();
        destruct(this_object());
        return 1;
}
