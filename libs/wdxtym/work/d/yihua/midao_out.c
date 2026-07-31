#include <ansi.h>
inherit ROOM;
 
int do_pick(string arg) ;

void create()
{
        set("short", "密洞");
        set("long",@LONG
你正处在一个密洞中。这里光线很暗，只能隐隐约约看出地上有些其花异草。
花丛之中的一块石头上好象放着一个宝匣(xia)。 你突然闻到一股奇异的香味，你
真不知道你在什么地方了。
LONG);   
        set("item_desc", ([
        "xia" : "你仔细看了一下石匣，发现里面似乎放着两本书，似乎可以试着拿出来(pick book)。",
	"bi": "石壁上好像刻画着什么功法的图案，你盯着图案不禁领悟(lingwu)了起来。",
    ]) );
        set("exits", ([
				"out"  : __DIR__"midao",
				"west"   : __DIR__"xiaojing2",
]));
        set("objects", ([
        __DIR__"npc/huawuque" : 1,
    ]) );    

        setup();
}
void init()
{
	        add_action("do_think", "lingwu");
            add_action("do_pick","pick");
}
void reset()
{
        ::reset();
        set("get_available" , 2);
}

int do_pick(string arg)
{
       object me,obj;

       me = this_player();
       if( !arg || arg!="book" )
              return notify_fail("你要取什么?\n");
obj=present("hua wuque",environment(me));
if(obj && living(obj))
        
       {
        message_vision(YEL"花无缺说到：没有宫主的同意怎么能拿呢？"
                       "除非我死了！\n" NOR,me);
        return 1 ;
       }
       if ( query("get_available") )  {
       obj = new (__DIR__"obj/yihuapu");
       obj->move(me);
       obj = new (__DIR__"obj/yifengjianpu");
       obj->move(me);
       add("get_available", -2);
       message_vision("$N从宝匣中取出两本书。\n",me );
       }
       else
       return notify_fail("秘籍已经被别人捷足先登了。\n");
       return 1;
}


int do_think(string arg)
{
        object here, me = this_player();
        int add;
      int level;

       if (me->query("gender") != "女性")
                return notify_fail("你纯阴之气不足，难以领会高深的明玉功。\n");

        if (! living(me) || arg != "bi")
                return notify_fail("你要领悟什么？\n");

      if (me->query("sex/times"))
                return notify_fail("修炼明玉功必须是处子之身。\n");


        if (me->is_busy() || me->is_fighting())
                return notify_fail("你现在正忙着呢。\n");

        if ((int)me->query("int") < 25)
                return notify_fail("你若有所悟，然而总是有点不明白。\n");

        level = me->query_skill("mingyu-gong", 1);

   	if ((int)me->query_skill("mingyu-shengong", 1) < 100) 
                return notify_fail("是否先把冥雨神功练练再来。\n");

        if (me->query_skill("force", 1) < level)
                return notify_fail("你对基本内功的理解还不够，无法继续领会更"
                                   "高深的明玉功。\n");

        if (me->query_skill("unarmed", 1) < level)
                return notify_fail("你对基本拳脚的理解还不够，无法继续领会更"
                                   "高深的明玉功。\n");

        if ((int)me->query_skill("force", 1) < 200)
                return notify_fail("你的基本内功火候不够，无法领悟石壁"
                                   "上的武功。\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("你的内力修为不足，无法学习石壁上的武功。\n");

        if ((int)me->query("jing") < 85)
                return notify_fail("你现在精神不济，过于疲倦，还是休息"
                                   "一会吧。\n");

        if ((int)me->query_skill("martial-cognize", 1) < 100)
                return notify_fail("你觉得明玉功过于深奥，以自己的武学修养"
                                   "全然无法明白。\n");


        if ((int)me->query_skill("mingyu-gong", 1) >= 200)
                return notify_fail("你觉得石壁上记载的武功对你来说太浅了，结果你"
                                   "什么也没学到。\n");

        me->receive_damage("jing", 75);

        if (me->can_improve_skill("mingyu-gong"))
                me->improve_skill("mingyu-gong", add);

        me->start_busy(random(2));
        message_vision(HIY "\n$N" HIY "聚精会神的参详墙上所记载的神功，"
                       "似有所悟。\n" NOR, me);
        write(HIC "你对「明玉功」有了新的领悟。\n" NOR);
        return 1;
}