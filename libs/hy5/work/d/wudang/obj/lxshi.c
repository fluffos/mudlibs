// lianxinshi.c练心石

#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
        set_name(HIW"练心石"NOR,({"lianxin shi", "lianxin", "shi"}) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "座");
                set("value", 1);
                set("material", "stone");
                set("unique",1);
                set("treasure", 1);
                set("long", "这是一座巨大的白玉色大岩石。一面平滑，上面写着一些之字\n"+


        HIW" 练 心 石 "NOR+"~~~~~~~~~~~~~~~~~~~~~~~~
        此石乃老道修心之物，也借其作闭气练功之用。后修为日深，故立于练功处以待有缘人
                                                                 张三丰\n");
                set("wield_msg", "$N双手托起一座$n，几乎连眼睛都挡住了。\n");
                set("unequip_msg", "$N放下手中的$n，手臂都麻了。\n");
        }
        init_hammer(20);
        setup();
}                                                   
void init()
{
        if( this_player() == environment() )
        add_action("do_mianbi", "mianbi");
}

int do_mianbi()
{
        int damage;
        object me;
        me = this_player();
        if ( (int)me->query_skill("taoism", 1) < 101 )
           return notify_fail("你静心修炼,一会就打起了瞌睡。\n");
        if ( (int)me->query_skill("taoism", 1) >120 )
        return notify_fail("你静心修炼,但似乎已到了瓶颈。\n");
        me->receive_damage("jing", 30 + random(20));
        me->improve_skill("taoism", me->query("int"));
        message_vision("$N闭目端坐,想是在领悟什么。\n", me);
        return 1;
}
