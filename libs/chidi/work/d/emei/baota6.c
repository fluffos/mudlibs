// Room: /d/emei/baota6.c 峨嵋派 宝塔6

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "宝塔六层");
	set("long", @LONG
这里是大悲塔的六层，脚下铺着厚厚的石板，八角形的墙身上则有四扇
木窗向四面敞开，向外望去可以看到生长茂密的楠树，偶尔几只飞燕掠过树
林飞上了碧蓝的天空。转身过去，可以看到墙壁(wall)上刻有大段的经文。
往上看去，圆行的顶盖，上挂了一口古钟。
LONG
         );

	set("exits", ([
		"down" : __DIR__"baota5",
	]));
        set("item_desc", ([
           "wall" : @WALL
大乘佛经第六卷：
佛言。吾视王侯之位。如过隙尘。视金玉之宝。如瓦砾。视纨素之服。如敝帛。
视大千界。如一诃子。视阿耨池水。如涂足油。视方便门。如化宝聚。视无上乘。
如梦金帛。视佛道。如眼前华。视禅定。如须弥柱。视涅盘。如昼夕寤。视倒正。
如六龙舞。视平等。如一真地。视兴化。如四时木。
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

   if ( me->query("shen") < (me->query_skill("yugalism",1))* 60)
        return notify_fail("我佛慈悲，从善去恶！修习这门武功要有足够的善行。\n");

   if ( me->query("combat_exp") < (me->query_skill("yugalism",1))* 120)
        return notify_fail("你的经验不足！先多多磨练磨练吧。\n");

    message_vision("$N开始认真的阅读起墙壁上的经文。\n", me);
 
    if ( me->query_skill("yugalism",1) < 100 )
    {
       return notify_fail("以你现在的修为，还无法看得懂墙壁上的经文！\n");
    }
    else if ( me->query_skill("yugalism",1) > 120 )
     {
          return notify_fail("墙壁上的经文对你来说太浅了！\n");
     }

    if ( me->query("jing") < 25)
       return notify_fail("你已经读的精疲力竭，需要休息一下了！\n");


    if (!(myfam = me->query("family")) || myfam["family_name"] == "峨嵋派"  &&  (string)me->query("class")=="bonze" )
     {
          me->add("jing",-24); 
          me->improve_skill("yugalism", random(me->query_int()));
          return 1;
      }
   else {
        return notify_fail("你读了半天，毫无头绪，脑中一片混乱！\n");
        }
}

