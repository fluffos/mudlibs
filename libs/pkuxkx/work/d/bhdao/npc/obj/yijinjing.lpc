inherit ITEM;
#include <ansi.h>
int to_read(string);
void create()
{
        set_name(HIR"易筋经推脉图"NOR, ({ "yijin jing", "jing" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "
《易筋经推脉图》乃中国历代智者集黄帝《内经》、《上古天真》、
华佗《内昭图》等中国古代对人体及生命潜能研究之大成，
作者非只一人，而在元朝末年时，当时武林第一大教的教主不但身负
中原和西域两方的顶尖奇功，并深明医道，该名高人在卸除原教主
职务后因机缘得到《易筋经推脉图》草本，再精心汇整而成
《易筋经推脉图》全书，其后该教也因演变成为了日月神教的前身。”\n");
                set("value", 10);
                set("material", "paper");
        }
}
void init()
{

 add_action("to_read","read");
} 
int to_read(string arg)
{       object me;
        string book;
        int times,realtimes,max_level;

        me = this_player();
        if(!arg || (sscanf(arg, "%s %d",book,times) < 1 ) || book != "jing")
             return notify_fail("指令格式：read jing [次数]\n");
             
        if (times<1) return notify_fail("你至少要读一次！\n");

        if ( (int)me->query_skill("literate", 1) < 1)
                return notify_fail("你是个文盲，先学点文化(literate)吧。\n");
        if ( (int)me->query_skill("force", 1) < 450)
                return notify_fail("你的基本内功修为不够450级，不能学易筋神功。\n");
        if (me->is_busy()) return notify_fail("你正忙着呢！\n");
        if ( (int)me->query_skill("medical-skill", 1) < 450)
                return notify_fail("你的医术修为不够450级，不能学易筋神功。\n");
        if ( (int)me->query("bh/yj") < 1)
                return notify_fail("你没资格学习易筋神功！\n");
        if ((int)me->query("jing")< 300)
                return 1;
        realtimes = times;
        if ((me->query("jing")-300)/70 < times)
                realtimes = (me->query("jing")-300)/70;
        me->add("jing",-70*realtimes);
        message_vision("$N正专心研读易筋经推脉图。\n", me);
                max_level = (me->query("kar") + me->query("int") + me->query_spi() )*10 / 2;
        max_level += 150;
        if ( (int)me->query_skill("yijin-jing", 1) < max_level )
        {
                me->improve_skill("yijin-jing", me->query("int")*realtimes/2 ); //原来代码中为random(2)，这里/2代替
                write("你仔细观察图中经脉走向，对易筋神功有了更深一层的了解。\n");
        }
        else    write("《推脉图》的内容过于艰涩难解，你一时不能理解其中深意。\n");
        if (realtimes < times)
        return 1;
}     
