//pubu.c

inherit ROOM;

void create()
{
       set("short", "瀑布");
       set("long", @LONG
山路行到这里，忽听远处传来隐隐水声，转过一道山梁，只见一道白龙似
的大瀑布从对面双峰之间奔腾而下，空山寂寂，那水声在山谷中激荡回想，声
势甚是惊人。
LONG   );
       set("exits", ([ 
"northup" : __DIR__"xzfeng",
"eastdown" : __DIR__"sblu-1",
]));
       set("no_clean_up", 0);

       set("coor/x",-360);
  set("coor/y",-200);
   set("coor/z",60);
   setup();
}

void init()
{
       add_action("do_write",({"shuxie","write"}));
}

int do_write(string arg)
{
       object me=this_player();
       object weapon;
       int neili_lost;


       if (!living(me)) return 0;
       if (me->is_busy() || me->is_fighting()) 
                 return notify_fail("你正忙着呢。\n");
       if (!me->query_temp("weapon"))
                 return notify_fail("你空手怎么写字? \n");
       if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "brush") 
                 return notify_fail("你用的兵器不对。\n");   
       if (!me->query_skill("brush",1))
               return notify_fail("你不会这种技能。\n");
       if (me->query("jing") < 20) 
               return notify_fail("你没办法集中精神。\n");
       if (me->query("neili") <100)
               return notify_fail("你的内力不够了。\n");
       if (me->query_skill("brush",1) < 30) 
               return notify_fail("你的基本笔法太低了，无法领悟书法的意境。\n");
       if (me->query_skill("brush",1) > 100)
               return notify_fail("你瞑思苦想，对着空中不停地书写，想去领悟书法的意境，但是再也无法更进一步了。\n");
       neili_lost=(int)(me->query_skill("brush",1)/10);

       write("你苦思暝想，对着空中不停地书写，对书法的意境领悟又更深了一层。\n");
       me->receive_damage("jing",20);
       me->set("neili",(int)me->query("neili")-neili_lost);
       me->improve_skill("brush", me->query_int()/2);
       return 1;
}
