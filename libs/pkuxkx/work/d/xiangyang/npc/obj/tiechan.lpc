// 铁铲

#include <ansi.h>
inherit ITEM;
int do_open(string arg);
             

void create()
{
	set_name(HIC"铁铲"NOR, ({"tie chan", "chan", "tiechan"}));
         set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用精钢制作而成的"+HIC"铁铲，"NOR+"似乎可以挖掘(dig)。\n"
		"如果在荒山野地，用这个"+HIC"铁铲，"NOR+"挖到(dig)宝物就好了!\n"
		"在人多的城市附近铁定是没有的。\n");
		set("unit", "把");
//                 set("no_drop","不要乱丢，这东西打到人痛！\n");
                 set("no_put",1);
                 set("no_store",1);
	}
}


void init()
{
   add_action("do_open","dig");
}

   

int do_open(string arg)
{ 
    object me=this_player(),ob,env;
        env = environment(me);
        if (me->is_busy())
        {
          tell_object(me,"等你忙完了，再挖吧，！\n");
          return 1;
        }
	if( me->is_fighting() )
        {
          tell_object(me,"等打完了，再挖吧，！\n");
          return 1;
        }

        if ((me->query("jing") < 20))
        {  
          tell_object(me,"你的精力不能集中，不可以挖宝！\n");
          return 1;
        }
        if ((me->query("combat_exp") < 200000 ))
        {
          tell_object(me,"你的经验太低，不能挖宝！\n");
          return 1;
        }

        if ((me->query("qi") < 30 ))
        {
          tell_object(me,"你的身体状态太差，不能挖宝！\n");
          return 1;
        }
    if(me->query("jing")<me->query("max_jing")/20 )
      return notify_fail("你的精不够了。\n");

    if(me->query("eff_jing")<me->query("max_jing")/20 )
      return notify_fail("你的精不够了。\n");

    if(me->query("qi")<me->query("max_qi")/20 )
      return notify_fail("你的气不够了。\n");

    if(me->query("eff_qi")<me->query("max_qi")/20 )
      return notify_fail("你的气不够了。\n");

        if (!env->query("outdoors"))
                return notify_fail("你打算拆屋呀？\n");

        if (env->query("no_fight")) {
                return notify_fail("这里不准随便挖掘。\n");
        }

        if (env->query("no_dig")) {
                return notify_fail("这里好像刚刚被人挖过没有宝物了!\n");
        }

else {
        message_vision(HIC"$N蹲在地上，双手乱刨,挥动铁铲开始在地上挖了起来。\n"NOR,me);
        me->receive_damage("jing",me->query("eff_jing")/20);
//        me->add("eff_jing",-me->query("max_jing")/20);
        me->receive_damage("qi", me->query("eff_qi")/20);
//        me->add("eff_qi",-me->query("max_jing")/20);
                 add("workchan", 1);
//                randomize();
                 if ( query("workchan") > 10)
             {
    message_vision(HIG"铁铲已经挖坏了!\n"NOR,me); 
        destruct(this_object());
return 1;
             }
        me->start_busy(6);   
}

      if (random(7)<5)
      {
        me->start_busy(3);   
        message_vision(CYN"$N挖了一阵，什么也没有找到。\n"NOR,me);
      return notify_fail("真是可惜!\n");          
      }

        if (env->query("outdoors")=="city"
          ||env->query("outdoors")=="suzhou"
//        ||env->query("outdoors")=="chengdu"
//        ||env->query("outdoors")=="changan"
//        ||env->query("outdoors")=="dali"
//        ||env->query("outdoors")=="foshan"
//        ||env->query("outdoors")=="hangzhou"
//        ||env->query("outdoors")=="huanggon"
//        ||env->query("outdoors")=="hg"
        ||env->query("outdoors")=="quanzhou"
        ||env->query("outdoors")=="xiangyang"
//        ||env->query("outdoors")=="pingan"
//        ||env->query("outdoors")=="武馆"
//        ||env->query("outdoors")=="lanzhou"
//        ||env->query("outdoors")=="ruzhou"
//        ||env->query("outdoors")=="fengyun"
//        ||env->query("outdoors")=="yanjing"
		)
      {
        me->start_busy(3);   
        message_vision(CYN"$N挖了一阵，什么也没有找到,也许这里离大城市太近了吧。\n"NOR,me);
      return notify_fail("真是可惜!\n");          
      }

        if(me->query("gender")=="男性")
    tell_object(me,"你迫不及待地将挖出的"+HIY+"宝物"NOR+"拿出，\n");
        else
    tell_object(me,"你小心翼翼地将挖出的"+HIY+"宝物"NOR+"拿出，\n");

    if( me->over_encumbranced() )
    return notify_fail("身上带的东西太多了，拿不动了。\n");

      env->set("no_dig",1);
      me->add("combat_exp",20+random(20));
      me->add("potential",10+random(5));

      if(random(100)>95)
      {
        ob=new("/clone/money/gold");
        ob->set_amount(random(10)+1);
        ob->move(me);
        tell_object(me,"发现了一些"+HIY"黄金"NOR+"。\n"NOR);
      }  
      else if(random(100)>95)
      {
        ob=new("/clone/money/gold");
         ob->set_amount(random(5)+1);
        ob->move(me);
        tell_object(me,"发现了一些"+HIY"黄金"NOR+"。\n"NOR);
      }  
      else if(random(200)>180)
      {
        me->receive_wound("jing",50,"挖宝受伤");
        me->receive_wound("qi",100,"挖宝受伤");
        tell_object(me,"挖出的石头划破了你的"+HIC"手"NOR+",你受了伤!"NOR+"。\n"NOR);
      }  
      else if(random(200)>180)
      {
        me->receive_wound("jing",50,"挖宝受伤");
        me->receive_wound("qi",100,"挖宝受伤");
        tell_object(me,"挖出的石头划破了你的"+HIC"手"NOR+",你受了伤!"NOR+"。\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("snake_poison",10);
        me->add("qi",-10);
        tell_object(me,"挖出的东西有"+HIR"毒"NOR+",你受了伤!"NOR+"。\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("bing_poison",10);
        me->add("qi",-10);
        tell_object(me,"挖出的东西有"+HIR"毒"NOR+",你受了伤!"NOR+"。\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("bt_poison",10);
        me->add("qi",-10);
        tell_object(me,"挖出的东西有"+HIR"毒"NOR+",你受了伤!"NOR+"。\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("san_poison",10);
        me->add("qi",-10);
        tell_object(me,"挖出的东西有"+HIR"毒"NOR+",你受了伤!"NOR+"。\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("xx_poison",10);
        me->add("qi",-10);
        tell_object(me,"挖出的东西有"+HIR"毒"NOR+",你受了伤!"NOR+"。\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("xxx_poison",10);
        me->add("qi",-10);
        tell_object(me,"挖出的东西有"+HIR"毒"NOR+",你受了伤!"NOR+"。\n"NOR);
      }  
      else if(random(300)>298)
      {
        tell_object(me,"挖出来的东西发出一阵"+HIY"迷雾"NOR+",你什么也不知道了!"NOR+"。\n"NOR);
        me->unconcious();
      }  
       else if(random(1000)>998)
      {
        tell_object(me,"挖出来的东西发出一阵"+HIR"金光"NOR+",你觉的事情不好了!!"NOR+"。\n"NOR);
        me->receive_damage("qi", 0, "挖宝受伤");
        me->die();
      }  
      else if(random(100)>95)
      {
        ob=new("/clone/money/silver");
         ob->set_amount(random(100)+1);
        ob->move(me);
        tell_object(me,"发现了一些"+HIY"白银"NOR+"。\n"NOR);
      }  
      else if(random(100)>95)
      {
        ob=new("/clone/money/silver");
         ob->set_amount(random(100)+1);
        ob->move(me);
        tell_object(me,"发现了一些"+HIY"白银"NOR+"。\n"NOR);
      }  
      else if(random(100)>95)
      {
        ob=new("/clone/money/silver");
         ob->set_amount(random(100)+1);
        ob->move(me);
        tell_object(me,"发现了一些"+HIY"白银"NOR+"。\n"NOR);
      }  
      else if(random(100)>95)
      {
        ob=new("/clone/money/coin");
         ob->set_amount(random(1000)+1);
        ob->move(me);
        tell_object(me,"发现了一些"+HIY"铜钱"NOR+"。\n"NOR);
      }  
      else if(random(100)>95)
      {
        ob=new("/clone/money/coin");
         ob->set_amount(random(1000)+1);
        ob->move(me);
        tell_object(me,"发现了一些"+HIY"铜钱"NOR+"。\n"NOR);
      }  
  else if(random(100)>80)
      {
//         int rand;
//        rand=random(sizeof(box_object));
//             ob=new(__DIR__+box_object[rand]);
	   string items = "item/"+random(201);//括号内为物品总数
	     ob=new(__DIR__+items);
if(ob && ob->move(me))
{
        tell_object(me,"发现了"+HIY":"+ob->query("name")+"."NOR+"。\n"NOR);
}
else            tell_object(me,"结果什么也没有!"NOR+"。\n"NOR);
      }  
else tell_object(me,"结果什么也没有!"NOR+"。\n"NOR);

        return 1;
}
