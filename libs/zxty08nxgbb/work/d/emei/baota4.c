// Room: /d/emei/baota4.c 峨嵋派 宝塔4

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "宝塔四层");
	set("long", @LONG
这里是大悲塔的四层，脚下铺着厚厚的石板，八角形的墙身上则有四扇
木窗紧紧的关闭着，在左右两侧各挂了一盏小莲花灯，照着在正对墙壁乎明
乎暗。恍惚间又可看到墙壁(wall)上刻有大段的经文。往上看去，长长的木
楼梯盘绕而上，似乎永无尽头。
LONG
         );

	set("exits", ([
		"down" : __DIR__"baota3",
                "up" : __DIR__"baota5",
	]));
        set("item_desc", ([
           "wall" : @WALL
大乘佛经第四卷：
佛言。夫为道者。犹木在水。寻流而行。不触两岸。不为人取。不为鬼神所遮。
不为洄流所住。亦不腐败。吾保此木。决定入海。学道之人。不为情欲所惑。
不为众邪所娆。精进无为。吾保此人。必得道矣。....
WALL
             ])) ;

        setup();
}
void init()
{
        add_action("do_yuedu", "yuedu");
}

int do_yuedu(string arg)
{

    mapping myfam;
    object me = this_player();
    if ( !arg || (arg != "wall"))
       return notify_fail("你要阅读什么？\n");

    if (me->is_busy())
	return notify_fail("你现在正忙着呢。\n");

   if ( me->query("shen") < (me->query_skill("yugalism",1))* 40)
        return notify_fail("我佛慈悲，从善去恶！修习这门武功要有足够的善行。\n");

   if ( me->query("combat_exp") < (me->query_skill("yugalism",1))* 80)
        return notify_fail("你的经验不足！先多多磨练磨练吧。\n");

    message_vision("$N开始认真的阅读起墙壁上的经文。\n", me);
 
    if ( me->query_skill("yugalism",1) < 60 )
    {
       return notify_fail("以你现在的修为，还无法看得懂墙壁上的经文！\n");
    }
    else if ( me->query_skill("yugalism",1) > 80 )
     {
          return notify_fail("墙壁上的经文对你来说太浅了！\n");
     }

    if ( me->query("jing") < 20)
       return notify_fail("你已经读的精疲力竭，需要休息一下了！\n");


    if (!(myfam = me->query("family")) || myfam["family_name"] == "峨嵋派"  &&  (string)me->query("class")=="bonze" )
     {
          me->add("jing",-19); 
          me->improve_skill("yugalism", random(me->query_int()));
          return 1;
      }
   else {
        return notify_fail("你读了半天，毫无头绪，脑中一片混乱！\n");
        }
}

