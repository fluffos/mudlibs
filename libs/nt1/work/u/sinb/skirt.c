// skrit.c   by sinb for mhyj

#include <armor.h>
#include <ansi.h>
#include <mudlib.h>

inherit CLOTH;

void create()
{
        set_name(HIW "月影"HIG"长裙" NOR, ({ "moon skirt" }) ); 
        set_weight(600);

        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("long", HIW "漂亮的花裙子，上面有大象的图案。\n"
                                "是梦幻妖精寒假时去泰国买的。\n" NOR);

                set("unit", "件");
                set("value", 5000);
                set("material", "feather");
                set("armor_prop/personality", 10);
                set("armor_prop/armor", 10);
                set("armor_prop/attack", -2); 
                set("wear_msg", HIW"$N轻柔的展开一件洁白如雪的飘逸纱衣轻轻披在身上，映衬得\n"
                                     HIW"$N肌肤胜雪，眉目如画，让人意动魂摇。\n" NOR);
                set("remove_msg", HIY"$N企图诱惑安全中心，轻轻地把裙子掀起一半，\n"
                                  HIR"安全中心看得眼都直了！！！\n" NOR);
        }
        setup();
}

void init()
{
        if ( this_player()->query("id") == "mhyj" )
        add_action("do_home","home");
}
int do_home()
{
        object me = this_player();
       if( me->over_encumbranced() )
        return notify_fail("你的负荷过重，动弹不得。\n");
       if( me->is_busy() )
              return notify_fail("你的动作还没有完成，不能移动。\n");
       if (me->is_fighting()) return 0;
        me->move("/u/sinb/workroom");
        message_vision("$N在外面玩了一天，肚子饿了才回到家里。\n",me);
        return 1;
}


int query_autoload() { return 1; }
