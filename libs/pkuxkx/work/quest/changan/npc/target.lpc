
#include <ansi.h>
#include "/quest/changan/quest.h"

inherit FAMILY_NPC;

varargs void wield_weapon(string weapon);
varargs string *init_anti_busy(int times, string *busys);
protected void init_cloth();
string ask_tongji();
string ask_message();
varargs void clean_citizens(object *citizens);

void create()
{
	set_name("路人甲", ({ "luren jia", "luren" }) );
	set("gender", "男性" );
	set("age", 22+random(10));
	set("combat_exp", 10000000);
	
  set("food",500);
  set("water",500);
	set("chat_chance", 25);
	set("uni_target", 1);

  set("inquiry", ([
    "盗贼" : (: ask_tongji :),
    "消息" : (: ask_message :),
  ]) );
  
  call_out("clean_self", 900);
	setup();
  carry_object("/clone/armor/bianfuxuejia")->wear();
}

void init()
{
	add_action("do_testify","testify");
}

//初始化任务npc
varargs void init_quest(string keyid, object criminal) 
{
	object *citizens, citizen, loc;
	int diff, others, lp;
	string location, floc, *busys;
	string *age_type=({"青年","中年","老年"});
	string *cloth_type=({"绸衫","布衣","棉袄"});
	string *boots_type=({"凉鞋","布鞋","靴子"});
	mapping age_map=
	(["青年":20, "中年":40, "老年":60]);
	string *names, full_name;
	
	if ( !TITLE_BASE->is_quest(keyid) )
		return;
	
	diff=TITLE_BASE->query_quest(keyid, "difficulty");
	location=TITLE_BASE->query_quest(keyid, "location");
	floc=TITLE_LV1->query_location(location);
//下面初始化npc武功相关属性	
	family_skill(this_object(), "random", 100+diff*(400+diff*50), 1);
	set("level", 10+diff*30);
	set("combat_exp", to_int(ceil(pow(10+diff*(40+diff*5), 3)*100)));
	set("max_qi", 5000+diff*(5000+diff*diff*5000) );
	set("eff_qi", 5000+diff*(5000+diff*diff*5000) );
  set("qi", 5000+diff*(5000+diff*diff*5000) );
	set("max_jing", 5000+diff*(5000+diff*diff*5000) );
	set("eff_jing", 5000+diff*(5000+diff*diff*5000) );
  set("jing", 5000+diff*(5000+diff*diff*5000) );
  set("max_jingli", 3000+diff*(3000+diff*5000) );
  set("jingli", 3000+diff*(3000+diff*5000) );
  set("max_neili", 3000+diff*(3000+diff*5000) );
  set("neili", 3000+diff*(3000+diff*5000) );
  set_temp("apply/damage", 50+diff*(100+diff*50));
  set_temp("apply/attack", 50+diff*(50+diff*50));
  set_temp("apply/defense", 50+diff*(50+diff*50));
  set_temp("apply/armor", 50+diff*(100+diff*50));
  if ( diff )
  	set_temp("apply/kf_anti_hr", diff);         //普通以上难度，npc会导致玩家特殊技能命中下降
  
  if ( diff>2 )
  	set_temp("apply/kf_hit_rate", diff);        //困难难度，npc特殊技能命中提升
  
  if ( diff>1 )
  	set_temp("apply/kf_def_wound", 10+diff*5 );  //挑战以上难度，npc会拥有一定程度的化学防御力
  
  if ( diff>1 )
  	busys=init_anti_busy(diff-1);                //挑战难度，npc会拥有随机一种busy免疫效果，困难难度，npc拥有随机两种busy免疫效果
//下面初始化npc的特征
//特征分为性别（男/女）、身高（高/矮）、身形（胖/廋）、年龄（青年/中年/老年）、衣服颜色（深色/浅色）、衣服材质（绸衫/布衣/棉袄）、鞋子颜色（深色/浅色）、鞋子类型（凉鞋/布鞋/靴子）
  set("special/gender", random(2)?"男性":"女性");
  set("gender", query("special/gender"));
  set("special/high", random(2)?"高":"矮");
  set("special/body", random(2)?"胖":"廋");
  set("special/age", age_type[random(sizeof(age_type))]);
  set("age", age_map[query("special/age")]+random(20));
  set("special/cloth_color", random(2)?"深色":"浅色");
  set("special/cloth_type", cloth_type[random(sizeof(age_type))]);
  set("special/boots_color", random(2)?"深色":"浅色");
  set("special/boots_type", boots_type[random(sizeof(age_type))]);
  init_cloth();                         //初始化npc的衣服
	wield_weapon();                       //初始化npc的武器
//获取随即名字  
  if ( query("gender")=="男性" )
  	full_name=NAME_D->create_name();
  else
  	full_name=NAME_D->create_female_name();
  
  names=explode(full_name,"@");
  set_name(names[0], ({names[1],"luren"}));
  if ( query("gender")=="男性" )
  {
  	if ( query("special/high")=="高" )
  	{
  		if ( query("special/body")=="胖" )
  			set("long", CYN"这是一位高大魁梧的行人。\n"NOR);
  		else
  		  set("long", CYN"这是一位宛如一根竹竿的行人。\n"NOR);
  	}
  	else
  	{
  		if ( query("special/body")=="胖" )
  			set("long",CYN "这是一位矮小粗胖的行人。\n"NOR);
  		else
  		  set("long", CYN"这是一位矮小灵活的行人。\n"NOR);
  	}
  }
  else
  {
  	if ( query("special/high")=="高" )
  	{
  		if ( query("special/body")=="胖" )
  			set("long", MAG"这是一位身材异常魁梧高大的行人。\n"NOR);
  		else
  		  set("long", MAG"这是一个丰胸细腰，身材苗条挺拔的行人。\n"NOR);
  	}
  	else
  	{
  		if ( query("special/body")=="胖" )
  			set("long", MAG"这是一位身材丰满矮小的行人。\n"NOR);
  		else
  		  set("long", MAG"这是一位娇小玲珑的行人。\n"NOR);
  	}
  }
  set("per", 25+random(10));  	
  
//记录玩家特征
  set("quest_user", TITLE_BASE->query_quest(keyid, "user"));
  set("questid", keyid);
  if ( objectp(criminal) )
  	set("criminal", criminal);
  else
    set("criminal", 1);
  	
//初始化配角列表
  if ( !objectp(criminal) )
  {
    citizens=({this_object()});
    others=random(3)+5;
    set("citizens", others+1);
    for(lp=0;lp<others;lp++)
    {
  	  citizen=new("/quest/changan/npc/target");
  	  citizen->init_quest(keyid, this_object());
  	  citizens+=({citizen});
    }
    set_temp("citizens", citizens); //记录本任务的所有npc
  }
  else
  	set("citizens", criminal->query("citizens"));
  
//随机将npc放到任务点
  if ( !objectp(criminal) )
  {
    if ( !(loc=find_object(floc)) )
		  loc=load_object(floc);
	
	  for(lp=0;lp<sizeof(citizens);lp++)
	  {
	  	citizens[lp]->move(loc);
	  	if ( random(100)>=30 )
	  		citizens[lp]->random_move();
	  }
	  //每分钟检查任务是否存在，不存在任务则npc消失
	  call_out("check_quest", 60, keyid, citizens);
	}	

}

varargs void wield_weapon(string weapon)
{
	if(!weapon && query("use_weapon1"))
		wield_weapon(query("use_weapon1"));
	if(!weapon && query("use_weapon2"))
		wield_weapon(query("use_weapon2"));
	if(!weapon)
		return;
	switch(weapon)
	{
	case "sword":
		carry_object("/clone/weapon/changjian")->wield();
		break;
	case "blade":
		carry_object("/clone/weapon/gangdao")->wield();
		break;
	case "staff":
		carry_object("/clone/weapon/gangzhang")->wield();
		break;
	case "whip":
		carry_object("/clone/weapon/changbian")->wield();
		break;
	case "zhen":
		set("gender", "无性");
		carry_object("/d/city/obj/flower_shoe")->wear();
		carry_object("/d/city/obj/pink_cloth")->wear();
		carry_object("/d/city/obj/goldring")->wear();
		carry_object("/d/city/obj/necklace")->wear();
		carry_object("/d/quanzhou/obj/xiuhua")->wield();
		carry_object("/d/riyuejiao/obj/xiuhuajia");
		break;
	case "dagger":
                carry_object("/clone/weapon/bishou")->wield();
		break;
        case "xiao":
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/npc/obj/yuxiao")->wield();
         break;
         case "ling":
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/obj/shenghuo-ling")->wield();
         break;
	case "hammer":
		carry_object("/d/dalunsi/npc/obj/iron-falun")->wield();
		break;
	default:
	}
	return;
}

//设置npc的随机免疫busy属性
varargs string *init_anti_busy(int times, string *busys)
{
	string *tbusy, rbusy, *result;
	
	if ( !busys )
		tbusy=({"dianxue", "jiemai", "fenjin", "confuse", "body"});
	else
		tbusy=busys;
	
	rbusy=tbusy[random(sizeof(tbusy))];
	set_temp("apply/cant_busy_"+rbusy,1);

	result=({});
	if ( times> 1 )
		result=init_anti_busy(times-1, tbusy-({rbusy}));
	
	result=result+({rbusy});
	return result;
}

//检查任务是否存在，不存在任务则自动清理npc
void check_quest(string keyid, object *citizens)
{
	int lp;
		
	if ( !TITLE_BASE->is_quest(keyid) )
	{
		clean_citizens(citizens);
		return;
	}
	
	call_out("check_quest", 60, keyid, citizens);
}

//确认罪犯身份，直接进入逮捕流程，击败罪犯以后将可以去衙门领取奖励
string ask_tongji()
{
	object me=this_player(), ob=this_object(),criminal;
	string keyid;
	
	if ( me->query("id") != ob->query("quest_user") ||
		   !(keyid=me->query("changan/lv1/questid")) ||
		   ob->query("questid")!=me->query("changan/lv1/questid") )
	  return "长安的治安也太乱了一点，赶紧躲到乡下老家去。\n";		
	
	if ( me->query("changan/lv1/finds")<ob->query("citizens")-1 )
		return "你还没有发现谁从商铺里面偷走东西吗？继续问问附近路人吧。\n";
  
  if ( ob->is_fighting() ||
  	   ob->is_busy() )
  	return "我正忙着呢！\n";
  
  if ( ob->query("find_crim") ||
  	   me->query("changan/lv1/findsuc") )
  {
		TITLE_BASE->complete_quest(keyid, me, 1);
		me->delete("changan/lv1");
		tell_object(me, "你没有抓住机会逮住罪犯，罪犯趁机逃跑了。\n");
		if ( ob->query("criminal") && 
		   objectp(criminal=ob->query("criminal")) )
		  criminal->clean_citizens();
		else if ( ob->query("criminal") && 
		   !objectp(ob->query("criminal")) )
		  ob->clean_citizens();
		return "你问的事情我不清楚啊。\n";
  }
	
	if ( ob->query("criminal") && 
		   objectp(ob->query("criminal")) &&
		   !me->query("changan/lv1/finderr") )
	{
		me->set("changan/lv1/finderr",1);
		return "你找错人了吧？看来还需要仔细观察啊。\n";
	}
	else if ( ob->query("criminal") && 
		   objectp(criminal=ob->query("criminal")) )
	{
		TITLE_BASE->complete_quest(keyid, me, 1);
		me->delete("changan/lv1");
		tell_object(me, "你寻找线索消耗了太多的时间，引起了盗贼的怀疑，盗贼逃离了长安城。\n");
		criminal->clean_citizens();
		return "你问的事情我不清楚啊。\n";
	}
	else if ( ob->query("criminal") && 
		   !objectp(ob->query("criminal")) )
  {
  	me->set("changan/lv1/findsuc",1);
  	ob->set("find_crim",1);
  	ob->kill_ob(me);
  	me->kill_ob(ob);
  	set("uni_target", me);
  	tell_object(me, "你发现了正准备潜逃的罪犯，拦住了罪犯的去路。\n");
  	call_out("check_fight", 5, me); 
  	return "敢拦住老子的去路，去死吧！\n";
  }
	
	return "你问的事情我不清楚啊。\n";
}

//询问犯罪特征，罪犯会给出错误的特征或者不回答，路人会给出正确的特征或者不回答
string ask_message()
{
	object ob=this_object(), criminal;
	object me=this_player();
	string *kcrim, *vcrim, rcrim,*msgs;
	mapping crim_info=
	(["gender":
		(["男性":({"当时我正路过这个商铺，看见一个男子在附近鬼鬼祟祟地不知道干嘛。\n",
			         "前几天我去那家店里买东西的时候总发现一个流浪汉在附近转悠。\n",
			         "我感觉这些路边的流浪汉嫌疑非常大。\n"}),
		  "女性":({"我记不太清楚了，不过当时有一道黑影从店后面翻墙而入，象一个女盗贼。\n",
		           "最近这条街上多了很多女流浪者，估计是她们干的。\n",
		           "那天我在附近乘凉，就感觉那时候有一个女流浪者走得比较急，拌了我一下，怀疑就是她干的。\n"})]),
		"high":
		(["高":({"我家就在那家商铺后身，当天晚上看见有一个高个子从商铺后面翻墙而出。\n",
		         "我注意到那天傍晚有一个高个子的在附近鬼鬼崇崇地转悠了好几次。\n",
		         "前一阵子有一个高个子的顾客每天都到店里来，但是从不买东西，出事以后就再也没有看见这个人了。\n"}),
		  "矮":({"我记不太清楚了，不过当时有一道黑影从店后面翻墙而入，个子不太高。\n",
		         "前几天我去那家店里买东西的时候总有一个矮个子的流民在附近转悠。\n",
		         "当时我正路过这个商铺，看见一个矮个子的流民在附近鬼鬼祟祟地不知道干嘛。\n",})]),	
		"body":
		(["胖":({"我家就在那家商铺后身，当天晚上看见有一个人从商铺后面翻墙而出，身材有点胖。\n",
		         "我注意到那天傍晚有一个有点发胖的人的在附近鬼鬼崇崇地转悠了好几次。\n",
		         "前一阵子有一个微微发福的顾客每天都到店里来，但是从不买东西，出事以后就再也没有看见这个人了。\n"}),
			"廋":({"我记不太清楚了，不过当时有一道黑影从店后面翻墙而出，长得有点偏廋。\n",
		         "前几天我去那家店里买东西的时候总有一个象个猴子一样的流民在附近转悠。\n",
		         "当时我正路过这个商铺，看见一个竹竿似的流民在附近鬼鬼祟祟地不知道干嘛。\n",})]),
		"age":
		(["青年":({"当时我注意到这个人了，就是没敢上前，不过那个盗贼非常年轻。\n",
			         "这个案件我有点印象，那时候我看见有一个青年人背着一大袋东西从那家店铺的后门出来。\n",
			         "这个案件肯定是附近的那帮年轻人干的。\n"}),
			"中年":({"这个事情百分百是街头黑衣帮的那些人干的，那些人也老大不小了，还在到处混日子。\n",
			         "当时我注意到这个人了，就是没敢上前，是一个中年人。\n",
			         "这个案件我有点印象，那时候我看见有一个中年人背着一大袋东西从那家店铺的后门出来。\n"}),
			"老年":({"世风日下啊，头发花白了还出来干这种事情。\n",
			         "这个世道太乱了，都白发苍苍的还出来偷东西。\n",
			         "长安城没法住人了，都快半只脚埋入棺材的人还出来偷东西。\n"})]),
		"cloth_color":
		(["深色":({"我记得当时有一个身穿深色衣服的人非常值得怀疑"}),
			"浅色":({"我记得当时有一个身穿浅色衣服的人非常值得怀疑"})]),
		"cloth_type":
		(["绸衫":({"当时晚上我看见有一个身穿丝绸衣服的人总在附近出没。\n"}),
			"布衣":({"当时有一个身穿布衣的流民从店铺后面翻墙而出。\n"}),
			"棉袄":({"只记得当时那个人身穿夹袄，非常破旧了，就这点印象非常深刻。\n"})]),
	  "boots_color":
	  (["深色":({"我记得当时有一个脚上穿着深色鞋子的人非常值得怀疑"}),
			"浅色":({"我记得当时有一个脚上穿着浅色鞋子的人非常值得怀疑"})]),
	  "boots_type":
	  (["凉鞋":({"当时晚上我看见有一个脚上穿着一双凉鞋的人总在附近出没。\n"}),
	  	"布鞋":({"当时有一个脚上穿着一双布鞋的流民从店铺后面翻墙而出。\n"}),
	  	"靴子":({"只记得当时那个人脚上穿着一双靴子，非常破旧了，就这点印象非常深刻。\n"})])]);

	if ( me->query("id") != ob->query("quest_user") ||
		   !me->query("changan/lv1/questid") ||
		   ob->query("questid")!=me->query("changan/lv1/questid") )
	  return "你找错人了。\n";

	if ( ob->query("confirm_msg") )
		return "你已经问过了，我这里就了解那么多消息。\n";
	
	if ( (random(100)<30 &&
		    me->query("changan/lv1/find_nomsg")<2) ||
		    !ob->query("criminal") )
	{
		ob->set("confirm_msg",1);
		me->add("changan/lv1/find_nomsg",1);
		if ( ob->query("criminal") )
		  me->add("changan/lv1/finds",1);
		return "我啥消息也不了解啊。\n";
	}
	else
	{
		if ( ob->query("criminal") && 
		     objectp(criminal=ob->query("criminal")) )
		{
			kcrim=keys(crim_info);
			if ( arrayp(me->query("changan/lv1/asked_spec")) )
				kcrim=kcrim-me->query("changan/lv1/asked_spec");
      if ( !sizeof(kcrim) )
      	return 	"我啥消息也不了解啊。\n";
      			
			rcrim=kcrim[random(sizeof(kcrim))];
			msgs=crim_info[rcrim][criminal->query("special/"+rcrim)];
			ob->set("confirm_msg",1);
			me->add("changan/lv1/finds",1);
			if ( arrayp(me->query("changan/lv1/asked_spec")) )
			  me->set("changan/lv1/asked_spec", me->query("changan/lv1/asked_spec")+({rcrim}));
			else
				me->set("changan/lv1/asked_spec", ({rcrim}));
				
			return msgs[random(sizeof(msgs))];
		}
		else if ( ob->query("criminal") && 
		     !objectp(ob->query("criminal")) )
		{
			kcrim=keys(crim_info);
			if ( arrayp(me->query("changan/lv1/asked_spec")) )
				kcrim=kcrim-me->query("changan/lv1/asked_spec");
      if ( !sizeof(kcrim) )
      	return 	"我啥消息也不了解啊。\n";
      			
			rcrim=kcrim[random(sizeof(kcrim))];
			vcrim=keys(crim_info[rcrim]);
			vcrim=vcrim-({ob->query("special/"+rcrim)});
			msgs=crim_info[rcrim][vcrim[random(sizeof(vcrim))]];
			ob->set("confirm_msg",1);
			me->add("changan/lv1/finds",1);
			if ( arrayp(me->query("changan/lv1/asked_spec")) )
			  me->set("changan/lv1/asked_spec", me->query("changan/lv1/asked_spec")+({rcrim}));
			else
				me->set("changan/lv1/asked_spec", ({rcrim}));
				
			return msgs[random(sizeof(msgs))];
		}
	}
}

void die()
{
	object me, ob=this_object();
	string keyid;
	
	if ( !objectp(me=query("uni_target")) )
	{
		set("eff_qi", query("max_qi"));
		set("qi", query("max_qi"));
		return;
	}
	
	if ( environment(me)!=environment(this_object()) )
	{
		set("eff_qi", query("max_qi"));
		set("qi", query("max_qi"));
		return;
	}
	
	if ( me->query("id") != ob->query("quest_user") ||
		   !(keyid=me->query("changan/lv1/questid")) ||
		   ob->query("questid")!=me->query("changan/lv1/questid") )
	{
		set("eff_qi", query("max_qi"));
		set("qi", query("max_qi"));
		return;
	}
	
	if ( me->query("changan/lv1/success") )
	{
		set("eff_qi", query("max_qi"));
		set("qi", query("max_qi"));
		return;
	}
	
	me->set("changan/lv1/success",5);
	clean_citizens();
	if ( TITLE_BASE->complete_quest(keyid, me, 0) )
	  tell_object(me, "你抓住了罪犯，并将罪犯交给附近巡街的金吾卫，可以去衙门领取奖励了。\n");
}

void unconcious()
{
	die();
}

//向官府指证罪犯，指证模式下奖励是抓捕罪犯模式奖励的1/5（由changan/lv/success属性的数值来控制奖励系数）
int do_testify(string arg)
{
	object me=this_player(), ob,criminal;
	string keyid;
	
	if ( !arg )
	{
		tell_object(me, "命令格式是testify npcid");
		return 1;
	}
	
	if ( !objectp(ob=present(arg, environment(me))) )
	{
		tell_object(me, "命令格式是testify npcid");
		return 1;
	}
	
	if ( me->query("id") != ob->query("quest_user") ||
		   !(keyid=me->query("changan/lv1/questid")) ||
		   ob->query("questid")!=me->query("changan/lv1/questid") )
	{
	  tell_object(me, "你指证的对象似乎和这个案件没有任何牵连。\n");
	  return 1;
	}		
	
	if ( me->query("changan/lv1/finds")<ob->query("citizens")-1 )
  {
  	tell_object(me, "你没有采集到足够的证据，请不要轻易地下结论。\n");		
		return 1;
	}
  
  if ( ob->query("find_crim") ||
  	   me->query("changan/lv1/finderr") )
  {
  	if ( ob->query("criminal") && 
		   !objectp(ob->query("criminal")) )
		  criminal=ob;
		else if ( ob->query("criminal") && 
		   objectp(ob->query("criminal")) )
		  criminal=ob->query("criminal");
		
		TITLE_BASE->complete_quest(keyid, me, 1);
		me->delete("changan/lv1");
		tell_object(me, "你没有抓住机会逮住罪犯，罪犯趁机逃跑了。\n");
		if ( objectp(criminal) )
		  criminal->clean_citizens();
		return 1;
  }
	
	if ( ob->query("criminal") && 
		   objectp(criminal=ob->query("criminal")) )
	{
		TITLE_BASE->complete_quest(keyid, me, 1);
		me->delete("changan/lv1");
		tell_object(me, "你向附近的金吾卫错误地指证上铺的盗劫犯，惊动了真正的盗贼，使得他立即逃离长安城。\n");
		criminal->clean_citizens();
		return 1;
	}
	else if ( ob->query("criminal") && 
		   !objectp(ob->query("criminal")) )
  {
    me->set("changan/lv1/success",1);
  	ob->clean_citizens();
  	TITLE_BASE->complete_quest(keyid, me, 0);
  	tell_object(me, "你发现了正准备潜逃的罪犯，向附近巡街的金吾卫举报了，可以去衙门领奖了。\n");
  	return 1;
  }
  return 0;
}

//检查是否结束战斗，如果战斗结束则设置标记禁止重新开始战斗
void check_fight(object me)
{
	object ob=this_object();
	
	if ( living(ob) &&
		   !ob->is_fighting(me) )
	  ob->set("uni_target",1);
	else
		call_out("check_fight", 5, me); 
}

//初始化npc的服装特征
protected void init_cloth()
{
	object ob=this_object(),cloth,boots;
	
	if ( ob->query("gender")=="男性" )
	{
	  cloth=carry_object(__DIR__"obj/male-cloth");
	  boots=carry_object(__DIR__"obj/male-shoe");

	}
	else
	{
	  cloth=carry_object(__DIR__"obj/female-cloth");
	  boots=carry_object(__DIR__"obj/female-shoe");
	}
	
	cloth->init_cloth(ob);
	boots->init_boots(ob);
	cloth->wear();
	boots->wear();
}

//清除本任务相关的所有npc
varargs void clean_citizens(object *citizens)
{
	object *ct;
	int lp;
	
	if ( !arrayp(citizens) &&
		   arrayp(query_temp("citizens")) )
	  ct=query_temp("citizens");
	else if ( arrayp(citizens) )
		ct=citizens;
	
	if ( arrayp(ct) )
	{
		for(lp=0;lp<sizeof(ct);lp++)
		  if ( objectp(ct[lp]) && ct[lp]!=this_object() )
		  	destruct(ct[lp]);
		
		call_out("clean_self",1);
	}
}

protected void clean_self()
{
	destruct(this_object());
}