#include <ansi.h>
// inherit F_GEMS;
void generate_newitem(object ob, int bonus, int channel);
void forge(string arg);
void add_equip(string arg);
int rate_gold(int gold);
int ask_business();
int ask_here();
int ask_buy();

int *add_base = ({20,10,7,5,4,4,3,3,2,2});
int *add_count =({18,10,7,6,5,4,4,4,4,4});
int *add_rdm = ({5,5,4,4,4,3,3,2,2,1});
//每次强化加点数：9,10级别额外优待一些，总体上数值控制在20-36.
//level1-10: 20-40,10-20,7-13,5-10,4-8,4-7,3-6,3-5,2-5,2-5
int check()
{
	object env = environment(this_object());
	if (this_object()->query("boss_id")!=env->query("owner_id"))
		{
			message_vision("$N看了看四周突然慌乱起来：“这是哪里？我家老板"+this_object()->query("boss_name")+"呢？”\n",this_object(),);
			return 2;
		}
	else
		return 1;
}

int ask_here()
{
	object env = environment(this_object());
	message_vision("$N回答$n：“我只是个小小铁匠，没有名字，至于我家老板嘛，就是大名鼎鼎的"+this_object()->query("boss_name")+"("+this_object()->query("boss_id")+")了！”\n",this_object(),this_player());
	return 1;
}

int ask_buy()
{
	object env = environment(this_object());
	object me = this_player(), ob = this_object();
	message_vision("$N对$n说道：“你想盘下这间铁铺？真有眼光！实话告诉你，这间铺子是只赚不赔！\n“不过嘛，我看你的锻造术也忒低了点儿，还是练好了手艺再来吧！”\n",ob,me);
	return 1;
}

int ask_forge()
{
	object env = environment(this_object());
	if (check()==2)
		return 1;
	if (this_player()->query("balance")<10000*env->query("rate_gold"))
		{
			message_vision("$N不屑的看了$n一眼说道：“我们这儿可是收费服务，每次"+env->query("rate_gold")+"两黄金，我看你这穷酸样儿怕是没钱消费啊。”\n",this_object(),this_player());
			return 1;
		}
	message_vision("$N对$n说：“你如果自己会锻造，我这炉子你随便用。如果想让我帮你，那可就要收费了，每次"+env->query("rate_gold")+"两黄金。\n“你已经把装备放入熔炉并打算让我帮你锻造了么？”(回答yes or no)\n",this_object(),this_player());
	input_to((: forge :));
  return 1;
}

int ask_add()
{
	object env = environment(this_object());
	if (check()==2)
		return 1;
	if (this_player()->query("balance")<10000*env->query("rate_gold"))
		{
			message_vision("$N不屑的看了$n一眼说道：“我们这儿可是收费服务，每次"+env->query("rate_gold")+"两黄金，我看你这穷酸样儿怕是没钱消费啊。”\n",this_object(),this_player());
			return 1;
		}
	message_vision("$N对$n说：“你如果自己会锻造强化，我这炉子你随便用。如果想让我帮你，那可就要收费了，每次"+env->query("rate_gold")+"两黄金。\n“你已经把装备放入熔炉并打算让我帮你锻造强化了么？”(回答yes or no)\n",this_object(),this_player());
	input_to((: add_equip :));
  return 1;
}

int ask_business()
{
	object owner=this_player(), me=this_object();
	object env = environment(this_object());
	if (check()==2)
		return 1;
	if (me->query("boss_id")!=owner->query("id"))
		{
			message_vision("$N端详了$n半天，挠着头问道：“老板，你被毁容啦？我怎么认不出你了！”\n",me,owner);
			return 1;
		}
	tell_object(owner,"伙计凑到你的耳朵边悄悄对你说道：“老板，我们的收费标准是每次"+env->query("rate_gold")+"两黄金，到现在为止咱们已经赚了"+env->query("balance")+"两黄金了。”\n");
	return 1;
}

int ask_adjust()
{
	object env = environment(this_object());
	object owner=this_player(), me=this_object();
	if (check()==2)
		return 1;
	if (env->query("owner_id")!=owner->query("id"))
		{
			message_vision("$N端详了$n半天，挠着头问道：“老板，你被毁容啦？我怎么认不出你了！”\n",me,owner);
			return 1;
		}
	message_vision("$N问$n道：“老板，你想每次收取几两黄金？目前的收费标准是"+env->query("rate_gold")+"两黄金每次。”\n请输入数值：\n",this_object(),this_player());
	input_to((: rate_gold :));
		
	return 1;
}

int rate_gold(string arg)
{
	object owner=this_player(), me=this_object();
	object env = environment(this_object());
	int gold;
	if (check()==2)
		return 1;
	if ( !arg || sscanf(arg, "%d", gold) != 1)
		{
			tell_object(owner,"请输入一个整数！\n");
			return 1;
		}
	if (gold<10)
		{
			tell_object(owner,"每次收费不能低于10两黄金！\n");
			return 1;
		}
	if (gold>100)
		{
			tell_object(owner,"每次收费不能高于100两黄金！\n");
			return 1;
		}
	env->set("rate_gold",gold);
	message_vision("$N对$n应道：“老板，已经将收费标准按您的要求调整为"+gold+"两黄金每次。”\n",me,owner);
	return 1;
}

void forge(string arg)
{
	object item, ob, auxiliary, *inv;
	object env = environment(this_object());
	object me=this_object();
  int i, j, capacity, bonus,count=0;
  bonus = me->query("forging")/20-(me->query("forging")*me->query("forging"))/50000;
  bonus = me->query("forging")/100+random(bonus);
  if (check()==2)
		return;
  if(arg!="y"&&arg!="Y"&&arg!="yes"&&arg!="YES")
		{
			message_vision("想清楚再来吧！\n",me,this_player());
			return;
		}
  if( me->is_busy() )
    {
			message_vision("铁铺伙计怒道：“你等一下好不好，没看我正忙着呢么！”\n",me,this_player());
			return;
		}
  if (!ob = present("rong lu", environment(me)) )
  	{
			message_vision("铁铺伙计大惊失色：“我的熔炉呢？！”\n",me,this_player());
			return;
		}
	inv = all_inventory(ob); 
    for (i = 0; i < sizeof(inv); i++) 
		{
		  if (!inv[i]->query("newgem") && !inv[i]->query("forge")&&!inv[i]->is_tanjing())
		  	{
					message_vision("铁铺伙计嘟嘟囔囔的说：“这炉子里都什么乱七八糟的东西啊？”\n",me,this_player());
					return;
				}
		 if (inv[i]->is_tanjing())
		 {
			 auxiliary=inv[i];
			 count+=1;
			 if (count>1)
			 {
				 message_vision("铁铺伙计叹道：“"+inv[i]->query("name")+"这种好东西居然一下就放多个？真败家啊！”\n",me,this_player());
				 return;
			 }
		 }
		  if (inv[i]->query("forge"))
			  {
				  if(objectp(item))
				  	{
							item->move(ob);
							message_vision("铁铺伙计摆了摆手说：“这样可不行，炉子里只能有一件装备！”\n",me,this_player());
							return;
						}
			    else 
			    	{
			    	item = inv[i];
			      if (!item->move(environment(me)))
			      	{
								item->move(ob);
								message_vision("铁铺伙计满脸倦容的说：“我今天太累了，你明儿个再来吧。”\n",me,this_player());
								return;
							}
		        }
		    }
		}
	if(!objectp(item))
	 	{
			message_vision("铁铺伙计看了看熔炉，转头瞪大了眼珠嚷道：“炉子里一件装备都没有，你到底想锻造什么？”\n",me,this_player());
			return;
		}
	inv = all_inventory(ob);
	item->move(ob);
	capacity = sizeof(inv);
	if (auxiliary)
	capacity-=1;
  if (me->query("forging") < capacity * 100&&!auxiliary)
		{
			message_vision("$N无奈的耸了耸肩对$n说：“实在对不住，以我现在的水平没办法做这个活儿，你还是找别人试试看吧。\n",me,this_player());
			return;
		}
  if (!capacity)
		{
			message_vision("$N摇着头对$n说道：“缺少用来和" + item->name() + "一起锻造的材料啊！”\n",me,this_player());
			return;
		}
	if (!item->query("forge/max"))
		{
			message_vision("$N摇着头对$n说道：“" + item->name() + "无法和其它材料融合！”\n",me,this_player());
			return;
		}
	if (item->query("forge/times") >= item->query("forge/times_max"))
		{
			message_vision("$N摇着头对$n说道：“" + item->name() + "实在经不起再次锻造了！\n",me,this_player());
			return;
		}
	if (item->query("forge/max") < capacity)
		{
			message_vision("$N摇着头对$n说道：“" + item->name() + "无法和这么多材料融合！\n",me,this_player());		
	  	return;
		}
	inv-=({auxiliary});
	destruct(auxiliary);
  for (j = 0; j < sizeof(inv); j++) 
	{
	  if (!inv[j]->query("newgem")&&!inv[j]->is_tanjing())
	  	{
	  		message_vision("这炉子有问题了，通知becool吧。\n",me,this_player());
	  		return;
	  	}
	  	
    if ( item->query("weapon_prop") &&
		  	 inv[j]->query("type") == "siling" )
		{
		    message_vision("目前四灵宝石还不能镶嵌到武器上。\n",me,this_player());
		  	return;
		}
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
一口气，擦了擦头上的汗水，似乎很不舍得的把自己的杰作递给了$n。\n"NOR, me,this_player());
	item->add("forge/times",1);
	item->set("forge/capacity",capacity);
	if (!item->move(this_player()))
		item->move(environment(me));
	item->set("is_forging",1);
	item->set("forge/bonus",bonus);
	ob->delete("in_use");
	me->delete_temp("is_forging");
	this_player()->add("balance",-10000*env->query("rate_gold"));
  env->add("balance",env->query("rate_gold"));
	me->start_busy(3);
	F_GEMS->generate_newitem(item, bonus, 1);
	if (capacity>3)
	CHANNEL_D->do_channel(this_object(), "jh", HIW"听说有一件"+item->query("name")+HIW+"在"+environment(me)->query("short")+HIW+"问世。", -1);
	return;
}

void add_equip(string arg)
{
	object item, ob, auxiliary, *inv;
	object env = environment(this_object());
	object me=this_object();
  int i, j, capacity, bonus,count=0;
  bonus = me->query("forging")/20-(me->query("forging")*me->query("forging"))/50000;
  bonus = me->query("forging")/100+random(bonus);
  if (check()==2)
		return;
  if(arg!="y"&&arg!="Y"&&arg!="yes"&&arg!="YES")
		{
			message_vision("想清楚再来吧！\n",me,this_player());
			return;
		}
  if( me->is_busy() )
    {
			message_vision("铁铺伙计怒道：“你等一下好不好，没看我正忙着呢么！”\n",me,this_player());
			return;
		}
  if (!ob = present("rong lu", environment(me)) )
  	{
			message_vision("铁铺伙计大惊失色：“我的熔炉呢？！”\n",me,this_player());
			return;
	}
	ob->set("in_use",1);
	inv = all_inventory(ob); 
    for (i = 0; i < sizeof(inv); i++) 
		{
		  if (inv[i]->query("id")!="tian yue" && !inv[i]->query("weapon_prop"))
		  	{
					message_vision("铁铺伙计嘟嘟囔囔的说：“这炉子里都什么乱七八糟的东西啊？没有天月魄或者没有武器是无法强化的！”\n",me,this_player());
					return;
			}
		  if (inv[i]->query("weapon_prop"))
			  {
				  if(objectp(item))
				  	{
							item->move(ob);
							message_vision("铁铺伙计摆了摆手说：“这样可不行，炉子里只能有一件武器！”\n",me,this_player());
							return;
						}
			    else 
			    	{
			    	item = inv[i];
			      if (!item->move(environment(me)))
			      	{
								item->move(ob);
								message_vision("铁铺伙计满脸倦容的说：“我今天太累了，你明儿个再来吧。”\n",me,this_player());
								return;
							}
		        }
		    }

		}
	if(!objectp(item))
	 	{
			message_vision("铁铺伙计看了看熔炉，转头瞪大了眼珠嚷道：“炉子里一件装备都没有，你到底想锻造什么？”\n",me,this_player());
			return;
		}

	inv = all_inventory(ob);
	item->move(ob);
	capacity = sizeof(inv);
//	write("宝石数量/物品数量："+capacity+"\n");
  if (!capacity)
		{
			message_vision("$N摇着头对$n说道：“缺少用来和" + item->name() + "一起强化的材料啊！”\n",me,this_player());
			return;
		}
	if (item->query("level")==0 || item->query("forge/times_max")==0)
		{
			message_vision("$N摇着头对$n说道：“" + item->name() + "无法继续强化！”\n",me,this_player());
			return;
		}
	if (item->query("forge/add_times") >= item->query("level") || item->query("forge/add_times") > 10)
		{
			message_vision("$N摇着头对$n说道：“" + item->name() + "已经不能再次强化了！\n",me,this_player());
			return;
		}
	if (capacity > 1)
		{
			message_vision("$N摇着头对$n偷笑说道：即使多加了宝石也是没有任何其他效果的！\n",me,this_player());		
	  	//return;
		}
//	inv-=({auxiliary});
//	destruct(auxiliary);
  for (j = 0; j < sizeof(inv); j++) 
	{
	  if (!inv[j]->query("newgem")&&!inv[j]->is_tanjing())
	  	{
	  		message_vision("这炉子有问题了，通知巫师吧。\n",me,this_player());
	  		return;
	  	}
	  	
  
    //改变item的公有属性

	//2.增加物品重量
  	item->add("item/weight", inv[j]->query_weight()>>3);
  	//3.改变物品的价值
  	item->add("item/value", inv[j]->query("value")>>3);
  	destruct(inv[j]);
  }
	bonus=item->query("level")-1;
	if (bonus>9)
	{
		bonus=1;
	}
if (random(add_rdm[bonus])==0)
{


  message_vision(HIY"$N往熔炉里大把大把的添着柴火，拉着风箱，并仔细的观察着里面火焰的颜色，过了
一会儿，已经通红的" + item->name() + HIY"的锋刃上隐隐泛出几道暗色的光芒，似乎愈发锋利了！$N从炉
中取出" + item->name() + HIY"，拿着铁锤叮叮当当的一通砸，长吁了一口气，擦了擦头上的汗水，随手将
" + item->name() + HIY"递还给了$n。\n"NOR, me,this_player());

	item->add("forge/add_times",1);
	count=random(add_count[bonus]);
//	write("此次基础点数："+add_base[bonus]+","+add_count[bonus]+"\n");
//	write("此次随机点数："+count+"\n");
	count+=add_base[bonus];
//	write("此次总点数："+count+"\n");
	item->add("weapon/damage",count);
	item->add("weapon_prop/damage",count);
	CHANNEL_D->do_channel(this_object(), "jh", HIW"听说有一件"+item->query("name")+HIW+"在"+environment(me)->query("short")+HIW+"进行了锻造强化。", -1);
}
else
	{
  message_vision(HIY"$N往熔炉里大把大把的添着柴火，拉着风箱，并仔细的观察着里面火焰的颜色，突然
炉内火焰颜色巨变，$N赶紧从炉内抽出"+ item->name() + HIY",连忙擦擦头上的汗,将武器递还给$n后说道：“
强化失败了！”说完把东西向$n怀里一丢.\n"NOR, me,this_player());
	}
//	item->set("forge/capacity",capacity);
	if (!item->move(this_player()))
		item->move(environment(me));
	item->set("is_forging",1);
//	item->set("forge/bonus",bonus);
	ob->delete("in_use");
	me->delete_temp("is_forging");
	this_player()->add("balance",-10000*env->query("rate_gold"));
	env->add("balance",env->query("rate_gold"));
	me->start_busy(3);

	/*F_GEMS->generate_newitem(item, bonus, 1);
	if (capacity>3)
	CHANNEL_D->do_channel(this_object(), "jh", HIW"听说有一件"+item->query("name")+HIW+"在"+environment(me)->query("short")+HIW+"问世。", -1);*/
	return;
}
