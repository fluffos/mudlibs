// forge.c
// by becool@pkuxkx

#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_GEMS;
void generate_newitem(object ob, int bonus, int channel);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
//	int index;
  object item, ob, *inv;
  int i, j, capacity, bonus;
  bonus = 0;
  if( !arg || arg == "")
  	return notify_fail("请指定一座熔炉。\n");
  if (!ob = present(arg, environment(me)) )
  	return notify_fail("你要用什么锻造？周围没有这东西啊？\n");
  if (ob->query("id") != "rong lu")
  	return notify_fail("只能在熔炉里锻造！\n");
  if( me->is_busy() )
    return notify_fail("你上一个动作还没有完成！\n");
    
  inv = all_inventory(ob); 
    for (i = 0; i < sizeof(inv); i++) 
		{
		  if (!inv[i]->query("newgem") && !inv[i]->query("forge"))
		  	return notify_fail("这炉子里都什么乱七八糟的东西啊？\n");
		  if (inv[i]->query("forge"))
			  {
				  if(objectp(item))
				  	{
				  		item->move(ob);
				  		return notify_fail("停！炉子里只能有一件装备！\n");
				  	}
			    else 
			    	{
			    	item = inv[i];
			      if (!item->move(me))
			      	return notify_fail("你身上东西太多了，怎么能施展得开手脚？\n");
		        }
		    }
		}
	if(me->query("forging")>250 && me->query("forgingjob/completed")<125)
  	{
  		me->set("forging",100);
  		me->set("forgingjob/completed",50);
  		return notify_fail("黑暗中虫子不知从哪儿冒了出来，对你说道：“不好意思，你这身锻造术来路不明，得废掉一部分了，嘿嘿。”\n");
  	}
  if(!objectp(item))
	 	return notify_fail("炉子里一件装备都没有，你到底想锻造什么？\n");
	inv = all_inventory(ob);
	item->move(ob);
	capacity = sizeof(inv);  
  if (capacity >2)
		return notify_fail("这个活儿需要专门的锻造工具，还是交给人家专业铁匠去做吧！\n");
  if (me->query("forging") < capacity * 100)
		return notify_fail("以你现在的锻造水平，没办法做这个活儿。\n");
  if (me->query("max_jingli") < 500 || me->query("jingli") < 500)
		return notify_fail("你现在精力不足，无法锻造！\n");
	if (me->query("max_neili") < 500 || me->query("neili") < 500)
		return notify_fail("你现在内力不足，无法锻造！\n");
  if (!capacity)
		return notify_fail("缺少用来和" + item->name() + "一起锻造的材料！\n");
	if (!item->query("forge/max"))
		return notify_fail(item->name() + "无法和其它材料融合！\n");
	if (item->query("forge/times") >= item->query("forge/times_max"))
		return notify_fail(item->name() + "实在经不起再次锻造了！\n");
	if (item->query("forge/max") < capacity)
		return notify_fail(item->name() + "无法和这么多材料融合！\n");		
	  
	  for (j = 0; j < sizeof(inv); j++) 
		{
		  if (!inv[j]->query("newgem"))
		  	return notify_fail("这炉子有问题了，通知becool吧。\n");
		  
		  if ( item->query("weapon_prop") &&
		  	   inv[j]->query("type") == "siling" )
		  	return notify_fail("目前四灵宝石还不能镶嵌到武器上。\n");
	    //改变item的公有属性
	    //1.设置锻造信息
      item->set(sprintf("forge/material%d", j+1), inv[j]->query("material"));
	    item->set(sprintf("forge/material%d_level", j+1), inv[j]->query("level"));
	    item->set(sprintf("forge/material%d_yinyang", j+1), inv[j]->query("yinyang"));
	    item->set(sprintf("forge/material%d_type", j+1), inv[j]->query("type"));
	    //2.改变物品重量
    	item->add("item/weight", inv[j]->query_weight());
    	//3.改变物品的价值
    	item->add("item/value", inv[j]->query("value") / 2);
    	destruct(inv[j]);
    }

  message_vision(HIY"$N往熔炉里大把大把的添着柴火，并仔细的观察着里面火焰的颜色，过了
一会儿，已经通红的" + item->name() + HIY"上隐隐的泛出几道暗色的光芒，似乎有一股神奇的
力量附在其中！$N从炉中取出" + item->name() + HIY"，拿着铁锤叮叮当当的一通乱砸，长吁了
一口气，擦了擦头上的汗水，仔细端详着自己的杰作，露出了得意地微笑。\n"NOR, me);
	me->add("max_jingli", - capacity);
	me->add("neili", - 1000);
	item->add("forge/times",1);
	item->set("forge/capacity",capacity);
	item->set("forge/bonus",bonus);
	if (!item->move(me))
		item->move(environment(me));
	item->set("is_forging",1);
	ob->delete("in_use");
	me->delete_temp("is_forging");
	me->start_busy(3);
	generate_newitem(item, bonus, 1);
	return 1;
}
	
int help(object me)
{
        write(@HELP
指令格式：forge <熔炉>

这个指令可以让你用熔炉锻造出更牛逼的装备。
锻造需要玩家具备锻造术，并且会消耗大量内力和少量最大精力。

HELP
    );
    return 1;
}


