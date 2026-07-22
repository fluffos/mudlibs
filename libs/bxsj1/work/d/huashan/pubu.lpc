// Room: /d/huashan/pubu.c
// Date: Look 99/03/25

inherit ROOM;

#include <ansi.h>
void create()
{
        set("short", "瀑布"NOR);
        set("long", @LONG
这里是一处峡谷，每年雨季山洪爆发时就形成了一处蔚为壮观的瀑布。传
说当年神雕侠杨过就是在这里练成绝世的玄铁剑法的。现在人去谷空，只剩下
空寥的山谷和飞流而下的瀑布(Pubu)，泉水从山上倾泻下来，形成一道水帘。
在地下冲出一个深潭(Tan)。东边是华山玉女峰。
LONG    );
        set("resource/water", 1);
        set("item_desc", ([
                "tan" : "那是一个非常深的潭，你隐隐约约看见下面的深潭旁边有条小路。\n",
		"pubu" : "这是一股飞流而下的瀑布，你隐隐发现水中依稀有个人形在舞剑。\n
但你定睛仔细一看，发现那只不过是水面反射的你的影子罢了。\n",
        ]) );
        set("exits", ([ 
        "east" : __DIR__"yunu",
        ]));
        set("objects",([
                __DIR__"npc/frog" : 1
        ]) );
        set("outdoors", "华山" );
        set("coor/x",60);
  set("coor/y",30);
   set("coor/z",60);
   setup();
}
 
void init()
{
        add_action("do_jump","tiao");
        add_action("do_fill","fill");
//        add_action("do_wujian", "wujian");
}

int do_jump(string arg)
{
        object me;
        int new_jing;
        me = this_player();
        new_jing = random( me->query("max_jing")*3 );
        if ( new_jing > me->query("jing") ) new_jing = me->query("jing") + 1;
        if( !arg || arg=="" ) return 0;

        if(me->query_temp("ride_horse"))
            return notify_fail("骑在马上你无法展开身法！\n");

        if( (me->query("dex") < 30) && ((int)me->query_skill("dodge")<100) )
                return notify_fail("你看了一眼深深的水潭，不由得倒退了一步！\n");
        if( arg == "down") {
        if(me->query_skill("dodge", 1) < 140){ 
        tell_object(me, HIR"你还没来的及选好位置跳，不小心脚一滑，只觉得一阵冰冷的山泉向你袭来，你被冲了下去。\n"NOR);
        message("vision", HIR"只见" + me->query("name") + "不小心脚一滑，掉进了瀑布，被山泉冲了下去。\n"NOR, environment(me), me);      
        me->add("jing", 0 - new_jing);        
        me->move(__DIR__"shentan");
        return 1;
        }
        else 
        message_vision(HIR"$N选好位置轻松一跳，在空中一个盘旋，落下了瀑布。\n"NOR,me);
        me->move(__DIR__"shentan");
        return 1;
	}
        if ( arg == "tan" ) {
        message_vision(HIY"$N一招狗急跳墙，四肢平展猛得朝水潭跳下。\n"NOR, me);
        me->move(__DIR__"shuitan");
        message_vision(RED"扑通一声，$N肚子首先入水，五脏六腑一阵翻滚。张嘴想要惊呼，咕噜咕噜，反而被灌了一肚子水。\n"NOR, me);
        me->receive_damage("jingli", 20);
        me->set("water", me->max_water_capacity()+200);
        me->start_busy(4);
        return 1;
	}
}


int do_fill(string arg)
{
        object me = this_player();
//        object ob = this_object();
        object tong;
        tong = present("shui tong", me);
        if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
        return notify_fail("你正忙着哪！\n");

        if(!arg || arg =="" || arg !="shuitong")
        return notify_fail("你要干什么？\n");
        
        if(arg =="shuitong" && present("shui tong", me)) {      
        if( tong->query("water") == 1) {
        write("桶里已经盛满了水。\n", me);
        return 1;}
        message_vision("你把水桶放到瀑布下，灌满了水。\n", me);
        tong->set("water", 1);
        tong->set("weight", 240000);
        tong->set("long", "水桶里盛满了泉水。\n");
        return 1;
        }
} 


int do_wujian()
{
        object me = this_player();
	object weapon;

        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你手中无剑，怎能舞剑？\n");
	if ( ((int)me->query_skill("sword",1) < 100) )
		return notify_fail("你身形跃起，拔剑对着瀑布刺去。却沮丧地发现根本碰不到瀑布。\n");
	if ( ((int)me->query_skill("sword",1) > 260) )
		return notify_fail("你身形跃起，拔剑对着瀑布刺去。飞泻的水流被剑光分开。\n");
        message_vision("$N身形跃起，拔剑对着瀑布刺去。剑光闪烁，水滴飞溅，$N对基本剑法有所领悟\n", me);
        me->receive_damage("jing", 15 + random((int)me->query_skill("sword" , 1) / 4));
        me->receive_damage("jingli", 15 + random((int)me->query_skill("sword" , 1) / 4));
        me->receive_damage("neili", 15 + random((int)me->query_skill("sword" , 1) / 4));
        me->improve_skill("sword", (int)me->query("int")*3);
        me->start_busy(random(2));
        return 1;
}


