// tanan.c
// By River
inherit ROOM;
#include <ansi.h>

void create()
{
         set("short", HIY"水潭岸边"NOR);
         set("long", @LONG
你站在一片山谷中的一处水潭(tan）岸边。游目四顾，只见繁花青草，便
如一个极大的花园。然而花影不动，幽谷无人，四下里十分安静。草地上一条
蜿蜒的小路铺满了鹅卵石(shi)，前方不远处一所茅屋。
LONG
        );
         set("item_desc", ([
            "tan":HIC"你举目向潭中望去，但见水潭里面水草晃动，几条不知名的白鱼游来游去。\n"NOR,
            "shi":"一块块大大小小的鹅卵石，你忍不住想捡(jian)起来看看。\n",
         ]));

         set("outdoors", "绝情谷");

         set("exits", ([
               "north" : __DIR__"xiaolu",
         ]));   

         setup();

}

void init()
{
      add_action("do_tiao", "tiao");
      add_action("do_jian", "jian");
      add_action("do_xiao", "xiao");
}

int do_tiao(string arg)
{
        object me;

        me=this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");
        if ( !arg || arg != "tan")
                return notify_fail("你要往哪跳？\n");
        message_vision(HIY"$N扑通一声，涌身跳入了水潭。\n"NOR, me);
        me->set("water", me->max_water_capacity()+ 100);
        me->move(__DIR__"tanmian");
        tell_room(environment(me), me->name() + "从岸边跳了下来。\n", ({ me }));
        return 1;
}

int do_jian(string arg)
{
        object me,ob;
        me=this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");
        if ( !arg || arg != "shi")
                return notify_fail("你要捡起什么？\n");
        if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 100) 
                return notify_fail("你的负荷过重了！\n");
        switch  (random(3)){
        case 0: ob = new(__DIR__"obj/shi1"); break;
        case 1: ob = new(__DIR__"obj/shi2"); break;
        case 2: ob = new(__DIR__"obj/shi3"); break;
        }
        ob->move(me);
        message_vision("$N弯下腰，从地上捡起了一块"+ob->name()+"。\n",me);
        return 1;
}

int get_object(object ob)
{
       return userp(ob);
}

int do_xiao(string arg,object *obj)
{
        object me=this_player();
        mapping fam;
        object *inv = deep_inventory(me);        
        fam = me->query("family");
        if (arg) return 0;
        if( ! fam || fam["family_name"] != "古墓派") return 0;

        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");
        obj = filter_array(inv,(:get_object:));
        if(sizeof(obj)){
          tell_object(me,HIR"你刚想偷偷背个人骑上白雕，结果负重太多，脚下一个绊拴，摔倒在地。\n"NOR);
          me->unconcious();
          return 1;
        }
        message_vision(HIW"\n$N当下作哨招雕，只见白雕双翅一振，高飞入云，盘旋数圈，猛地里从空中疾冲而下。\n"+
                          "$N骑上白雕后，那白雕厉声长鸣，穿破云雾，冲上山崖。\n\n"NOR,me);
        me->move(__DIR__"duanchang");
        tell_room(environment(me), me->name() + "从白雕身上跳了下来，白雕双翅一振，高飞入云。\n", ({ me }));
        return 1;
}
