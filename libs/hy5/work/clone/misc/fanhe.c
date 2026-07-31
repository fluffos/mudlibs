// more work needed to use this object to make poison
#include <ansi.h>
inherit ITEM;


void init()
{
        add_action("do_eat", "ci");
        add_action("do_eat", "he");
        add_action("do_sleep", "xiuxi");
          add_action ("do_fly","chen");
}

void create()
{
	set_name(YEL"新手背包"NOR, ({"newbie beg", "beg"}));
        set("unit", "只");
	set("long", "包里面看上去有永远吃不完的干粮。可以又吃又喝并休息(he,ci,xiuxi)。\n");
set("long", YEL"新手专用，包里面看上去有永远吃不完的干粮。\n
            你可以又吃又喝并休息和免费乘车(he,ci,xiuxi,chen)。，\n
           *@*@*@*@*@*@*@*@*@*可以带你乘(chen)到以下地方：*@*@*@*@*@*@*@*@*@*

              ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
              ＊＊ 北京(tam)        大理(dl)            泉州(qz)  ＊＊
              ＊＊ 少林(shl)        华山(hs)            灵鹫(lj)  ＊＊
              ＊＊ 武当(wd)         明教(mj)            扬州(gc)  ＊＊
              ＊＊ 星宿(xx)         雪山(xs)            峨眉(em)  ＊＊
              ＊＊ 全真(quz)        白驼山(bt)          古墓(gm)  ＊＊
              ＊＊ 苏州(sz)         归云庄(gyz)         襄阳(xy)  ＊＊
              ＊＊ 长安(ca)         成都(cd)            兰州(laz) ＊＊
              ＊＊ 荆州(jz)         盛京(yj)            武馆(wg)  ＊＊
              ＊＊ 昆明(km)         杭州(hz)            灵州(lz)  ＊＊
              ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n"NOR      
);
	set("no_get",1);
	set("no_drop",1);
		set("no_get", 1);
		set("no_put", 1);
		set("no_drop", 1);
             set("value", 0);
             set("material", "steel");
             set("no_drop", "这样东西不能离开你。\n");
        setup();
}

int do_eat(string arg)
{
object me = this_player();
	if (!id(arg))
                return notify_fail("你要吃什么？\n");
if (me->query("age") > 17)
return notify_fail("只有新手才能吃干粮!\n");
if (me->query("str") > 40)
return notify_fail("只有新手才能吃干粮!\n");
if (me->query("dex") > 40)
return notify_fail("只有新手才能吃干粮!\n");

if (me->is_busy())
return notify_fail("你要吃什么？\n");
if (me->is_fighting())
return notify_fail("你要吃什么？\n");
if ((int)me->query("combat_exp") > 600000 )
return notify_fail("只有新手才能吃干粮!\n");

if (me->query("food")*1.5 > me->max_food_capacity())
return notify_fail("你现在不饿啦!\n");
if (me->query("water")*1.5 > me->max_water_capacity())
return notify_fail("你现在不渴啦!\n");
message_vision(YEL "$N拿出干粮大吃大喝了一顿!!\n" NOR,me);
me->set("food",me->max_food_capacity());me->set("water",me->max_water_capacity());
me->start_busy(10);
}
int do_sleep(string arg)
{
object me = this_player();
	if (!id(arg))
                return notify_fail("你要用什么？\n");
if (me->query("age") > 17)
return notify_fail("只有新手才能用!\n");
if (me->query("str") > 40)
return notify_fail("只有新手才能用!\n");
if (me->query("dex") > 40)
return notify_fail("只有新手才能用!\n");

if (me->is_busy())
return notify_fail("你要用什么？\n");
if (me->is_fighting())
return notify_fail("你要用什么？\n");
if ((int)me->query("combat_exp") > 600000 )
return notify_fail("只有新手才能用!\n");

if (me->query("qi") > me->query("max_qi")
&& me->query("jing") > me->query("max_jing")
)
return notify_fail("你现在不累啦!\n");
message_vision(YEL "$N拿出新手背包铺在地上休息一会!!\n" NOR,me);
if (me->query("qi") < me->query("max_qi"))
me->add("qi",me->query("max_qi")/5);
if (me->query("jing") < me->query("max_jing"))
me->add("jing",me->query("max_jing")/5);
me->start_busy(12);
}

  int do_fly(string arg)
{

          string pla;
          object me = this_player();
if( me->query("jing") < 30 )
               return notify_fail("你精神不够旺盛，没力气做车马！\n");
if( me->query_temp("pending/team"))
               return notify_fail("你正和别人组队呢！\n");				

if( !environment(me)->query("no_fight") && me->query("combat_exp") > 500000)
{
  message_vision("只有在安全区域才能找到马车!!!\n"
                 ,me);
      	return 1;
}

if( !environment(me)->query("no_fight") && me->query("str") > 31)
{
  message_vision("只有在安全区域才能找到马车!!!\n"
                 ,me);
      	return 1;
}

if( !environment(me)->query("no_fight") && me->query("zhuanshen"))
{
  message_vision("只有在安全区域才能找到马车!!!\n"
                 ,me);
      	return 1;
}

if (me->query("age") > 17)
{
  message_vision("只有小于18岁，才能免费坐马车!!!\n"
                 ,me);
      	return 1;
}
    if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");
    if (me->is_busy()) 
        return notify_fail("你正热闹着呢!\n");

          if (!arg)
              return notify_fail("你想去哪里？\n");
          if( !wizardp(me) && me->is_fighting()  ) 
          return notify_fail("这么危险，那还有时间去坐马车?\n");

          if (me->query_temp("pigging_seat"))
                return notify_fail("先离开拱猪桌才能行动。\n");
          if( environment(me)->query("light_up"))
               return notify_fail("赌场里不能坐马车!!\n");


          else {
          message_vision(HIY
"$N叫了个马夫，并出示了手中的武林车马票，马夫牵来了马车。\n"+
"$N坐上马车，大喝一声“走喽”，只见马夫飞奔而去。。。\n\n"NOR, me);
}
          if(arg=="gc") pla = "/d/city/guangchang";
     else if(arg=="xx") pla = "/d/xingxiu/xxh1";
     else if(arg=="mj") pla = "/d/mingjiao/shanmen";
     else if(arg=="em") pla = "/d/emei/qingyinge";
     else if(arg=="shl") pla = "/d/shaolin/guangchang1";
     else if(arg=="lj") pla = "/d/lingjiu/damen";
     else if(arg=="dl") pla = "/d/dali/center";
     else if(arg=="xs") pla = "/d/xueshan/shanmen";
     else if(arg=="wd") pla = "/d/wudang/guangchang";
     else if(arg=="hs") pla = "/d/huashan/zhenyue";
     else if(arg=="tam") pla = "/d/city2/tian_anm";
     else if(arg=="quz") pla = "/d/quanzhen/damen";
     else if(arg=="bt") pla = "/d/baituo/dating";
     else if(arg=="qz") pla = "/d/quanzhou/zhongxin";
     else if(arg=="gm") pla = "/d/gumu/mumen";
     else if(arg=="sz") pla = "/d/suzhou/canlangting";
     else if(arg=="gyz") pla = "/d/guiyun/taihu";
     else if(arg=="xy") pla = "/d/xiangyang/guangchang";
     else if(arg=="ca") pla = "/d/changan/ca";
     else if(arg=="cd") pla = "/d/city3/guangchang";
     else if(arg=="laz") pla = "/d/lanzhou/guangchang";
     else if(arg=="jz") pla = "/d/jingzhou/guangchang";
     else if(arg=="km") pla = "/d/kunming/jinrilou";
     else if(arg=="yj") pla = "/d/yanjing/street";               
     else if(arg=="wg") pla = "/d/wuguan/guanmen";
     else if(arg=="hz") pla = "/d/hangzhou/kedian";
     else if(arg=="lz") pla = "/d/lingzhou/center";
               else {
               message_vision(HIR
"马车跑了半天，才发觉$N要去的地方根本没那个站。\n结果$N被马夫扔了下来，摔得鼻青脸肿！\n"NOR, me);
}
     if (me->move(pla)) {
       message_vision(HIC"\n到了！马车稳稳地停到地下，$N跳下了马车。对车夫挥了挥手。\n"NOR,me);
if( me->query("age") <= 16 )
           me->add("jing",-10);
 else   me->add("jing",-30);
}
     return 1;
}