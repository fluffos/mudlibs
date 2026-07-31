// Room: /d/emei/baota1.c 峨嵋派 宝塔1


#include <room.h>
inherit ROOM;
void create()
{
	set("short", "宝塔一层");
	set("long", @LONG
这里是大悲塔的底层，几缕阳光从墙上的小窗口中透射进来，在正对
青砖壁上留下几许光影，恍惚见可以看到墙壁(wall)上刻着大段的经文。往
上看去，长长的木楼梯盘绕而上，似乎永无尽头。墙角，梯级都相当洁净，
看来经常有人打扫。
LONG
         );

	set("exits", ([
		"out" : __DIR__"dabeita",
                "up" : __DIR__"baota2",
	]));
        set("item_desc", ([
           "wall" : @WALL
大乘佛经第一卷：
世尊成道已。作是思惟。离欲寂静。是最为胜。住大禅定。降诸魔道。
於鹿野苑中。转四谛法轮。求佛进止。世尊教敕。一一开悟。合掌敬诺。
而顺尊敕。....
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
    myfam = me->query("family");
    if ( !arg || (arg != "wall"))
       return notify_fail("你要阅读什么？\n");

    if (me->is_busy())
	return notify_fail("你现在正忙着呢。\n");

    if ( me->query("shen") < (me->query_skill("yugalism",1))* 10)
        return notify_fail("我佛慈悲，从善去恶！修习这门武功要有足够的善行。\n");

   if ( me->query("combat_exp") < (me->query_skill("yugalism",1))* 20)
        return notify_fail("你的经验不足！先多多磨练磨练吧。\n");

    message_vision("$N开始认真的阅读起墙壁上的经文。\n", me);

    if ( me->query_skill("yugalism",1) > 20 )
       return notify_fail("墙壁上的经文对你来说太浅了！\n");

   if ( me->query("jing") < 10)
       return notify_fail("你已经读的精疲力竭，需要休息一下了！\n");


   if ( myfam["family_name"] == "峨嵋派"  &&  (string)me->query("class")=="bonze" )
     {
          me->add("jing",-10); 
          me->improve_skill("yugalism", random(me->query_int()));
          return 1;
      }
   else {
        return notify_fail("你读了半天，毫无头绪，脑中一片混乱！\n");
        }
}

