// wangqing-jue, 1-60


inherit ITEM;
#include <ansi.h>
void init();
int do_read(string arg);

void create()
{
        set_name(HIC"《忘情天书》下册"NOR, ({"wangqing tianshu","wangqing","book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "册");
        set("long",
        "一本小册子，封面上《忘情天书》龙飞凤舞，气势不凡。\n
        需求：读书识字>300，最高读到500级，读时不耗费精神。\n");
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
        int gain;
        
        me=this_player();

        if( !this_object()->id(arg) ) return 0;
        if (me->query("mark/jinlong")!="wangqing2")
                        return notify_fail("你哪儿偷来的书？\n"); 
        if( me->is_busy() )
                        return notify_fail("你现在忙着呢，哪有可能静心研读...\n");
        if( me->is_fighting() )
                        return notify_fail("现在才想到精研忘情诀，太晚了吧？\n");
        if( (int)me->query_skill("literate", 1) < 300 ) 
                return notify_fail("你看了半天，里面不少字都是它认得你你不认得它。\n");
        if( (int)me->query_skill("wangqing-jue",1)>500 )
                return notify_fail("你在忘情诀方面已经很有造诣，这本书不会让你长进多少。\n");

        gain = (int)me->query_skill("literate", 1)/5+(int)me->query("int")/4+1;
        me->improve_skill("wangqing-jue", gain);

        message_vision("$N研读忘情天书，似乎有所领悟。\n", me);
                
        return 1;
}


