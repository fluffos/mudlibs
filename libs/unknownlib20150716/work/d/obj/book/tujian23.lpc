// tujian 《神兵图鉴》中册 sword, 50-400
// tujian1.c
// Cracked by 凌惊雪 1-6-2004 

inherit ITEM;
#include <ansi.h>
void init();
int do_read(string arg);

void create()
{
        set_name(HIC"《神兵图鉴》"NOR"中册"NOR, ({"shenbing tujian","shenbing","tujian","book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "册");
        set("long",
        "一本小册子，封面上写着《神兵图鉴》几个苍劲古朴的篆字，气势不凡。
这本古书记录了关于舞棍技巧的精华。\n");
        set("material", "paper");
        set("no_put",1);
        set("no_give",1);
        set("no_drop", 1);                
        set("no_get",1);
        set("value", 0);
        }
}

void init()
{
        add_action("do_read", "read");
        add_action("do_read", "study");
}
int do_read(string arg)
{
        object me;
        int sen_cost, gain;
        
        me=this_player();

        if( !this_object()->id(arg) ) return 0;
        if (environment(this_object()) != me)
                        return notify_fail("书不在你身上怎么读呢？\n"); 
        if( me->is_busy() )
                        return notify_fail("你现在忙着呢，哪有可能静心研读...\n");
        if( me->is_fighting() )
                        return notify_fail("现在才想到精研神兵图鉴，太晚了吧？\n");
        if( (int)me->query_skill("literate", 1) < 200 ) 
                return notify_fail("你看了半天，里面的小篆都是它认得你你不认得它。\n");
        if( (int)me->query_skill("stick", 1) < 50 ) 
                return notify_fail("你在棍法方面的造诣太低，实在无法看懂。\n");
        if( (int)me->query_skill("stick",1)>400 )
                return notify_fail("你在棍法方面已经很有造诣，这本书不会让你长进多少。\n");

        sen_cost = 25 + random((30-(int)me->query("int")));
        if( sen_cost < 10 ) sen_cost = 10;
        if( (int)me->query("sen")<sen_cost )
                return notify_fail("你现在头晕脑胀，该休息休息了。\n"); 
        me->receive_damage("sen", sen_cost);

        gain = (int)me->query_skill("literate", 1)/5+(int)me->query("int")/4+1;
        me->improve_skill("stick", gain);

        message_vision("$N仔细研读神兵图鉴，似乎对舞棍的技巧有所领悟。\n", me);
                
        return 1;
}

