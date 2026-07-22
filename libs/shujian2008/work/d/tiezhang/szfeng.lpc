// Room: /u/zqb/tiezhang/szfeng.c

inherit ROOM;

void create()
{
	set("short", "食指峰");
	set("long", @LONG
你终于爬上了峰顶，已经累得气喘吁吁了。这里只有丈许方圆的地方，却
长着些茂盛的树木(tree)，站在崖边，一阵狂风呼啸而过，吹得你一个趔趄，
差点摔倒，看来还是赶快离开这里的好。
LONG
	);

        set("item_desc",([
"tree": "这是些长了几十年的苍天松柏。\n"
]));

	set("no_clean_up", 0);
        set("outdoors", "tiezhang");
	setup();
}

void init()
{
        add_action("do_climb","climb");
        add_action("do_kan","kan");
}

int do_climb(string arg)
{
        object me;
        me=this_player();

        if (!arg || arg !="down")
         return notify_fail("你要往哪里爬? \n"); 
            write("你攀缘着石壁，缓缓向下爬去。\n");
            message("vision",me->name() + "向下爬去。\n", environment(me), ({me}) );
            me->move(__DIR__"juebi-5");
            message("vision",me->name() + "爬了下来。\n", environment(me), ({me}) );
         return 1;
}
int do_kan(string arg)
{
       object me = this_player();
       object weapon;
       string weapon_name;
       
       if (me->is_busy() || me->is_fighting())
             return notify_fail("你正忙着呢！\n");
       if (!arg || arg !="tree")
             return notify_fail("你要砍什么？\n");
       if (!me->query_temp("weapon"))
               return notify_fail("你空手怎么砍树? \n");
       if (!objectp(weapon = me->query_temp("weapon"))
         || (string)weapon->query("skill_type") != "axe") 
               return notify_fail("你用的兵器不对。\n");   
       if (!me->query_skill("axe",1))
               return notify_fail("你不会这种技能。\n");
       if (me->query("neili") <100)
               return notify_fail("你的内力不够了。\n");
       if (me->query_skill("axe",1) < 30) 
               return notify_fail("你的基本斧法太低了，无法使用斧子砍树。\n");
       weapon_name = weapon->query("name");
       if (me->query_skill("axe",1) > 100)
               return notify_fail("你挥起手中"+ weapon_name +",很轻松地把一棵大树砍倒了。\n");
       if (me->query("jing") < 5 || me->query("neili") < 10 ){
               message_vision("正好一棵大树倒在$N身上，$N一下子被砸晕了过去。\n", me);
               me->unconcious();
               return 1;
        }
//        message("vision", me->name() + "挥起手中"+ weapon_name +"，朝大树上一下下地砍去。\n",environment(me), ({me}));
        write("你挥起手中"+ weapon_name +",朝大树上一下下砍去。\n");
        me->receive_damage("jing",10);
        me->set("neili",(int)me->query("neili")-5);

        if ((int)me->query_skill("axe", 1) >= 30 && (int)me->query_skill("axe", 1) <= 100 )
        {
        me->improve_skill("axe", me->query("int"));
        tell_object(me, "隐约之中，你似乎觉得基本斧法有些进步了。\n");
        }
        return 1;
}
