//  equip.c
// seagate@pkuxkx 2014/12/03
// 装备增加属性gem_prop，存放宝石所增益的属性值
// gem_prop属性会累积到玩家临时数据区的gem_prop下，当该值累积超过gem_equip_limit
// 所限定的阀值，则会触发宝石所带来增益的最大值限定。

// seagate@pkuxkx 2015/01/11
// 1、对鉴定和装备属性应用方面代码进行重构
//    抽离对单条属性鉴定的代码为独立函数get_idf_msg
//    抽离对单条装备属性应用或者剥离玩家的代码为独立函数applied_character
//    提高代码的可维护性，为下一步增加更多功能降低代码维护工作量
// 2、装备属性应用中支持属性值为mapping的结构，也就是说属性存在子属性，子属性
//    目前仅支持技能id，比如**伤害类限定特定技能伤害的属性dmg_map，具体该词条解释见identify.h

//加入鉴定加伤害功能
//加入

inherit F_TAOZHUANG;
#include <dbase.h>
#include <weapon.h>
#include <ansi.h>
#include <identify.h>

//对未知属性的鉴定
//char_key/char_val为未知属性的关键字和值
//idf_level为鉴定级别
//equip_type为鉴定的装备类型描述，分别是武器、装备、套装
protected string get_idf_msg(string char_key, mixed char_val, int idf_level, string equip_type);

//将属性应用到人物身上
//其中appl_type分为suit，armor，weapon；分别代表套装，装备，武器
//    appl_direct分为equip和unequip，分别代表装备和卸除
protected void applied_character(object ob, string char_key, mixed char_val, string appl_type, string appl_direct );

int is_equip() {return 1;}

int wear()
{
  object owner;
  mapping armor_prop, applied_prop, *suit_prop, gem_prop;
  string *apply, type, suitid, *suitkey;
  string *spe_effect=({"armor_effect_armor_vs_force","armor_effect_healup","armor_effect_rebound"});

  // Only character object can wear armors.
  if (!environment()) return 0;
  if( !(owner = environment())->is_character() ) return 0;

  // If already worn, just recognize it.
  if( query("equipped") ) return 1;
  
  if( query("unique_owner") && 
      userp(owner) &&
      query("unique_owner") != owner->query("id") )
    return notify_fail("你不是该装备的拥有者！\n");
  
  //防止autoload装备被其他人装备 by seagate 2014/02/18
  if ( query("gem_ob_autoloaded") &&
       userp(owner) &&
       query("owner_id") &&
       query("owner_id") != owner->query("id") )     
    return notify_fail("你不是该装备的拥有者！\n");

  // Check if we have "armor_prop" defined.
  if( !mapp(armor_prop = query("armor_prop")) )
    return notify_fail("你只能穿戴可当作护具的东西。\n");
  if( mapp(query("weapon_prop")) )
    return notify_fail("你只能装备可当作护具的东西。\n");
  type = query("armor_type");

  if( type != "finger" && owner->query_temp("armor/" + type) )
    return notify_fail("你已经穿戴了同类型的护具了。\n");
  if( type == "finger")
  {
    if(owner->query_temp("armor/finger") && owner->query_temp("armor/secondary_finger"))
    return notify_fail("你已经穿戴了两个这种类型的装备了。\n");
    if(owner->query_temp("armor/finger"))
    owner->set_temp("armor/secondary_finger", this_object());
    else
    owner->set_temp("armor/finger", this_object());
  }
  if (type == "shield" && owner->query_temp("weapon") && owner->query_temp("secondary_weapon"))
    return notify_fail("你必须空出一只手才能装备盾牌。\n");
  if( type != "finger")
  owner->set_temp("armor/" + type, this_object());
  apply = keys(armor_prop);
  applied_prop = owner->query_temp("apply");
  if( !mapp(applied_prop) ) applied_prop = ([]);
    
  gem_prop=query("gem_prop");
  if ( !mapp(gem_prop) ) gem_prop=([]);
  
//增加对装备套装的支持 by seagate@pkuxkx
//suit_prop是一个mapping array，里面每一个map中limit属性表示触发的最小套装装备数量，
//其他就是加载到apply的属性
  if ( (suitid=this_object()->query("suit")) &&
       (suit_prop=this_object()->query("suit_prop")) )
  {
    owner->set_temp("suit/"+suitid+"/"+type, this_object());
    for(int i=0; i<sizeof(suit_prop); i++)
    {
      if ( sizeof(owner->query_temp("suit/" +suitid ) )>=suit_prop[i]["limit"] &&
           !owner->query_temp("suit_equip/"+ sprintf("%s_%d",suitid, suit_prop[i]["limit"]) ) )
      {
        suitkey=keys(suit_prop[i]);
        for(int j=0; j<sizeof(suitkey);j++)
        {
          if ( suitkey[j]=="limit" )
            continue;

          if ( suitkey[j]=="armor_effect_armor_vs_force" )   //取消装备上的该属性
            continue;
          
          applied_character(owner, suitkey[j], suit_prop[i][suitkey[j]], "suit", "equip" );
        }
        owner->set_temp("suit_equip/"+ sprintf("%s_%d",suitid, suit_prop[i]["limit"]),1);
      }
    }
  }

  for(int i = 0; i<sizeof(apply); i++)
  {
    if ( apply[i]=="armor_effect_armor_vs_force" )   //取消装备上的该属性
      continue;
    
    applied_character(owner, apply[i], armor_prop[apply[i]], "armor", "equip" );
  }  
    
  owner->set_temp("apply", applied_prop);
  set("equipped", "worn");
  check_taozhuang_wear(owner,this_object());
  return 1;
}

//查询武器速度
int query_speed()
{
  int wspd;
  
  if (!mapp(query("weapon_prop")) )
    return 0;
  
  wspd=query("weapon_speed");
  if ( wspd )
    return wspd;
  else
    return 100;
}

int wield()
{
  object owner, old_weapon;
  mapping weapon_prop,gem_prop;
  string *apply, type;
  int flag,j=0;
  
  //先检查owner是否存在然后再检查是否是character
  //by seagate@pkuxkx
  owner=environment();
  if ( !owner || !objectp(owner) )
    return 0;
  // Only character object can wear armors.
  if( !owner->is_character() ) return 0;

  // If already wielded, just recognize it.
  if( query("equipped") ) return 1;
  
  if( query("unique_owner") && 
      userp(owner) &&
      query("unique_owner") != owner->query("id") )
    return notify_fail("你不是该装备的拥有者！\n");  
    
  //防止autoload装备被其他人装备 by seagate 2014/02/18
  if ( query("gem_ob_autoloaded") &&
       userp(owner) &&
       query("owner_id") &&
       query("owner_id") != owner->query("id") )     
    return notify_fail("你不是该装备的拥有者！\n");

  // Check if we have "weapon_prop" defined.
  if( !mapp(weapon_prop = query("weapon_prop")) )
    return notify_fail("你只能装备可当作武器的东西。\n");

  gem_prop=query("gem_prop");
  if ( !mapp(gem_prop) ) gem_prop=([]);

  flag = query("flag");

  if( flag & TWO_HANDED ) {
    if( owner->query_temp("weapon")
    ||  owner->query_temp("secondary_weapon")
    ||  owner->query_temp("armor/shield") )
      return notify_fail("你必须空出双手才能装备双手武器。\n");
    owner->set_temp("weapon", this_object());
  }
  else 
  {

    // If we are are using any weapon?
    if( !(old_weapon = owner->query_temp("weapon")) &&
        ( !owner->query_temp("secondary_weapon") ||
          !owner->query_temp("armor/shield") ) )
      owner->set_temp("weapon", this_object());
    //如果第一个武器是双手武器---add by vast
    else if ( objectp(old_weapon) && 
              old_weapon->query("flag") & TWO_HANDED )
      return notify_fail("你必须放下双手武器，才能装备其他武器。\n");
    // If we still have a free hand?
    else if( !owner->query_temp("secondary_weapon") &&  
             !owner->query_temp("armor/shield") ) 
    {      
        owner->set_temp("secondary_weapon", this_object());
        j=1;
    } else
      return notify_fail("你必须空出一只手来使用武器。\n");
  }
  
  apply = keys(weapon_prop);
  for(int i = 0; i<sizeof(apply); i++)
  {
    if ( j && apply[i]=="damage")
      continue;

    applied_character(owner, apply[i], weapon_prop[apply[i]], "weapon", "equip" );
  }
  
  owner->reset_action();
  set("equipped", "wielded");
  check_taozhuang_wear(owner,this_object());
  return 1;
}

int unequip()
{
  object owner;
  mapping prop, applied_prop, *suit_prop, gem_prop;
  string *apply, equipped, suitid, *suitkey;
  string *spe_effect=({"armor_effect_armor_vs_force","armor_effect_healup","armor_effect_rebound"});
  int j=0, p1, p2, gemp;

//        if( !(owner = environment())->is_character() ) return 0;
  if( !(owner = environment())
      || !owner->is_character() )
{
    delete("equipped");
    return 1;
}

  if( !stringp(equipped = query("equipped")) )
    return notify_fail("你目前并没有装备这样东西。\n");

  if( equipped=="wielded" ) {
    if( (object)owner->query_temp("weapon") == this_object() )
      owner->delete_temp("weapon");
    else if( (object)owner->query_temp("secondary_weapon") == this_object() )
    {
      owner->delete_temp("secondary_weapon");
      j=1;
    }
      
    prop = query("weapon_prop");
    owner->reset_action();
  } else if( equipped=="worn" ) {
    if(query("armor_type") == "finger")
    {
            if( (object)owner->query_temp("armor/finger") == this_object() )
              owner->delete_temp("armor/finger");
            else if( (object)owner->query_temp("armor/secondary_finger") == this_object() )
              owner->delete_temp("armor/secondary_finger");
    }
    else
    owner->delete_temp("armor/" + query("armor_type") );
    prop = query("armor_prop");
  }

  apply = keys(prop);
  applied_prop = owner->query_temp("apply");
  gem_prop=query("gem_prop");
  if ( !mapp(gem_prop) ) gem_prop=([]);
//增加对装备套装的支持 by seagate@pkuxkx
//suit_prop是一个mapping array，里面每一个map中limit属性表示触发的最小套装装备数量，
//其他就是加载到apply的属性
  if ( equipped=="worn" &&
       (suitid=this_object()->query("suit")) &&
       (suit_prop=this_object()->query("suit_prop")) )
  {
    owner->delete_temp("suit/"+suitid+"/"+this_object()->query("armor_type") );
    for(p1=0; p1<sizeof(suit_prop); p1++)
    {
      if ( sizeof(owner->query_temp("suit/" +suitid ) )<suit_prop[p1]["limit"] &&
           owner->query_temp("suit_equip/"+ sprintf("%s_%d",suitid, suit_prop[p1]["limit"]) ) )
      {
        suitkey=keys(suit_prop[p1]);
        for(p2=0; p2<sizeof(suitkey);p2++)
        {
          if ( suitkey[p2]=="limit" )
            continue;
            
          if ( suitkey[p2]=="armor_effect_armor_vs_force" )   //取消装备上的该属性
            continue;
          
          applied_character(owner, suitkey[p2], suit_prop[p1][suitkey[p2]], "suit", "unequip" );
        }
        owner->delete_temp("suit_equip/"+ sprintf("%s_%d",suitid, suit_prop[p1]["limit"]));
      }
    }
  }
  
  for(int i = 0; i<sizeof(apply); i++)
  {
    
    if ( equipped=="worn" && 
         apply[i]=="armor_effect_armor_vs_force" )   //取消装备上的该属性
      continue;
    
    // To support array apply, we cannot add_temp() here.
    if ( j && apply[i]=="damage" )
      continue;
    
    if ( equipped=="worn" )
      applied_character(owner, apply[i], prop[apply[i]], "armor", "unequip" );
    else
      applied_character(owner, apply[i], prop[apply[i]], "weapon", "unequip" );
  }
  
  delete("equipped");
  check_taozhuang_remove(owner,this_object());
  return 1;
}

//增加装备的鉴定功能
//idf_level:鉴定级别，同identify.h中关于鉴定级别的定义
//player为鉴定者，鉴定者不一定需要有
varargs string identify(int idf_level, object player)
{
  object ob=this_object(), mt;
  mapping prop,*suit_prop, subprop;
  string idf_rslt,*suitkey, *propkey, msg, *subk, substr;
  int i, j, k, sl;
  //IL_INIT级别的时候无法鉴定出任何有用信息
  if ( idf_level==IL_INIT )
    return "";
  
  if ( objectp(mt=find_object(MONITOR_D)) )
    mt=load_object(MONITOR_D);
//  write(mt);
  if (ob->query("weapon_prop"))
  {//武器类
      idf_rslt = CYN"\n=========="NOR+ob->query("name")+NOR+"("+ob->query("id")+")"+CYN"==========\n"NOR;
      idf_rslt+= HIY"★"NOR+MAG"基本属性：\n"NOR;
      idf_rslt+= "      可塑性:"+HIC+ob->query("forge/max")+"("+ob->query("forge/capacity")+")\n"+NOR;
      idf_rslt+= "      再生力:"+HIC+ob->query("forge/times_max")+"("+ob->query("forge/times")+")\n"+NOR;
      idf_rslt+= "      强化度:"+HIC+ob->query("level")+"("+ob->query("forge/add_times")+")\n"+NOR;
      idf_rslt+= "      耐久度:"+HIC+ob->query("rigidity")+"\n"NOR;
      idf_rslt+= sprintf("      速  度:"HIC"%.2f\n"NOR,ob->query_speed()*1.0/100);
      idf_rslt+= "\n"+HIY"★"NOR+MAG"附加属性：\n"NOR;
      prop=ob->query("weapon_prop");
      propkey=keys(prop);
      for (i=0;i<sizeof(propkey);i++)
        idf_rslt+=get_idf_msg(propkey[i], prop[propkey[i]], idf_level, "武器");
      if ( ob->is_gems() && idf_level==IL_FULL && !ob->query("no_report_jh") )
	  {
		 if( ( to_int(ob->query("forge/max")) >= 3 || 
             ( to_int(ob->query("forge/max")) >= 2 && 
               ob->query("weapon/damage")>=180 ) ||
             ob->query("weapon/damage")>=210 ) ) 
		{
			msg = "";
			if ( ob->query("forge/max")>1 )
			  msg = "可塑性是"+CHINESE_D->chinese_number(to_int(ob->query("forge/max"))) + "的";
		   if ( objectp(player) )  
			  CHANNEL_D->do_channel(load_object(MONITOR_D),"jh","听说"+player->query("name")+"鉴定出一"
                   +ob->query("unit")+msg+ob->name()+"啦。", -1);  

		}
		if ( objectp(player) )
			i=player->query_skill("identification",1);
		else
			i=0;
		if (i>1000)
		{
			if (!player->query("jobs/bxs/last_time") || (time()-player->query("jobs/bxs/last_time")>360000))
			{
				 write(HIC"你的鉴定术久未提升，无法再进行更详细的鉴定了！\n"NOR); 
			}
			else 
			{
				k=i;
				if (i>3000)
				{
					i=3000;
				}
				j=i;
				if (i>1000)
					i-=895;

				i=(int)(i/105);
				sl=random(100);
				//	write("点数为:"+i+","+sl+"\n");
				if (sl<i)
					{
						if (k>8000)
						{
							k=10+random(6);
						}
						else
						{
							k=random(j/300)+1;
						}
						ob->add("weapon/damage",k);
						ob->add("weapon_prop/damage",k);
						CHANNEL_D->do_channel(load_object(MONITOR_D),"jh","听说鉴定大师"+player->query("name")+"鉴定时火眼金睛，辨别出武器特性上的各种细微差别。", -1);  
					}
					else
					{
						i*=3;
						i>>=1;
						if (sl<i)
						{
						ob->add("level",1);
						CHANNEL_D->do_channel(load_object(MONITOR_D),"jh","听说鉴定大师"+player->query("name")+"鉴定时狗眼识珠，辨别出武器品质上的差别。", -1);  
						}
					}
			}
		}
	  }

  }
  
  if(ob->query("armor_prop"))
  {//盔甲类
      idf_rslt = CYN"\n=========="NOR+ob->query("name")+NOR+"("+ob->query("id")+")"+CYN"==========\n"NOR;
      idf_rslt+= HIY"★"NOR+MAG"基本属性：\n"NOR;
      idf_rslt+= "      可塑性:"+HIC+ob->query("forge/max")+"("+ob->query("forge/capacity")+")\n"+NOR;
      idf_rslt+= "      再生力:"+HIC+ob->query("forge/times_max")+"("+ob->query("forge/times")+")\n"+NOR;
      idf_rslt+= "\n"+HIY"★"NOR+MAG"附加属性：\n"NOR;            
      prop=ob->query("armor_prop");
      propkey=keys(prop);
      for (i=0;i<sizeof(propkey);i++)
        idf_rslt+=get_idf_msg(propkey[i], prop[propkey[i]], idf_level, "盔甲");

      if ( ob->is_gems() && idf_level==IL_FULL && !ob->query("no_report_jh") &&
           ( ( ( ob->query("armor_type")=="finger" || 
                 ob->query("armor_type")=="neck" ) &&
               to_int(ob->query("forge/max")) >= 2 ) || 
             to_int(ob->query("forge/max")) >= 3 ) ) 
      {
        msg = "";
        if ( ob->query("forge/max")>1 )
          msg = "可塑性是"+CHINESE_D->chinese_number(to_int(ob->query("forge/max"))) + "的";
        if ( objectp(player) )  
          CHANNEL_D->do_channel(load_object(MONITOR_D),"jh","听说"+player->query("name")+"鉴定出一"
                   +ob->query("unit")+msg+ob->name()+"啦。", -1);  
      }
      
      //鉴定增加对套装的支持 by seagate@pkuxkx
      //套装供有下列属性 suit 存放suitid， suit_name存放套装名称， suit_prop 为 mapping *，存放套装属性，每个mapping的limit为最少装备件数
      if ( ob->query("suit") &&
           (suit_prop=ob->query("suit_prop")) )
      {
        idf_rslt+= "\n"+HIY"★"NOR+ob->query("suit_name") + MAG"属性：\n"NOR;
        for ( i=0; i<sizeof(suit_prop); i++ )
        {
          suitkey=keys(suit_prop[i]);
          idf_rslt+= "凑齐"+chinese_number(suit_prop[i]["limit"])+"件装备拥有额外套装属性：\n";
          for ( j=0; j<sizeof(suitkey); j++ )
          {                        
            if ( suitkey[j]=="limit" )
              continue;

            idf_rslt+=get_idf_msg(suitkey[j], suit_prop[i][suitkey[j]], idf_level, "套装");
          }
        }
      
        if ( objectp(player) && idf_level==IL_FULL && !ob->query("no_report_jh") )  
          CHANNEL_D->do_channel(load_object(MONITOR_D),"jh","听说"+player->query("name")+"鉴定出套装"+ob->query("suit_name")+"组件之一"+ob->name()+"。", -1);  
      }
  }
  
  if ( idf_level==IL_FULL && ob->is_gems() )
      ob->set("no_report_jh", 1);
	


  return idf_rslt;
}

//返回物品是否需要鉴定
//对于需要鉴定物品，返回鉴定类型
//0为不能鉴定的物品，
//1为直接调用物品本身的identify函数鉴定就可以的物品
//2为武器装备，需要鉴定技能鉴定
int is_identify()
{
  object ob=this_object();
  
  if ( ob->is_gems() )
  {
    //对于已经完全鉴定完毕的物品，直接转换成无需鉴定状态
    if ( ob->query("identified")==2 )
      return IDF_SIMPLE;
    else
      return IDF_EQUIP;
  }
  else
    return IDF_SIMPLE;
}

//校验鉴定能否鉴定该物品的方法
varargs int valid_identify(object player)
{
  object ob=this_object();
  int level, type;
  //草图不能鉴定
  if ( ob->is_draft() )
    return 0; 
  
  //不可鉴定物品不能鉴定
  if ( (type=ob->is_identify())==IDF_CANT )
    return 0;
  
  if ( ob->query("sockets") )
  {
    if ( objectp(player) && userp(player) )
      tell_object(player, "请将待鉴定物品升级以后再来尝试鉴定。\n");
    return 0;
  }
  
  level=ob->get_idflevel();
  if ( !level && type!=IDF_SIMPLE ) //从未鉴定过的物品并且非简单物品，需要对鉴定者的鉴定能力进行判定
  {
    if ( objectp(player) && 
         userp(player) && 
         player->query_skill("identification",1)<50 )
    {
      tell_object(player, "鉴定技能不足无法鉴定出任何有价值信息。\n");
      return 0;
    }
  
    if ( objectp(player) && 
         userp(player) && 
         player->query_temp("cannotidentify") )
    {
      tell_object(player, "你正在鉴定其他物品，无法分心鉴定这件宝物。\n");
      return 0;
    }
    
    //不存在鉴定者无法给你鉴定
    if ( !objectp(player) )
      return 0;
    
    //非玩家如果本身设定的鉴定级别判定无法通过则无法鉴定
    if ( objectp(player) &&
         !userp(player) &&
         !player->get_idflevel(ob) )
      return 0;
  }
  
  if( !ob->query("weapon_prop") && 
      !ob->query("armor_prop") )
    return 0;
  
  return 1;
}

//设定物品的鉴定级别
//被鉴定者鉴定以后设定对物品的鉴定程度
varargs int set_idflevel(object player)
{
  int idflvl, source;
  object ob=this_object();
  
  idflvl=ob->query("identified");
  if ( objectp(player) &&
       userp(player) )
  {
    if ( player->query_skill("identification",1) >= 50 && 
         player->query_skill("identification",1) < 100 )
      source = IL_SIMPLE; //技术鉴定
    else if ( player->query_skill("identification",1) >= 100 )
      source = IL_FULL; //图谱鉴定
    
    if ( present("bingqi pu",player) )
      source = IL_FULL; //图谱鉴定
  }
  else if ( objectp(player) 
    && !userp(player) )
    source=player->get_idflevel(ob);   //如果非玩家鉴定，鉴定级别由鉴定者自身定义的鉴定级别确定
                                       //对于鉴定者本身的鉴定级别函数，提供了输入鉴定物品的选项
  else
    return 0;       //如果无鉴定者无法设定鉴定级别
  
  if ( idflvl<source)
    ob->set("identified", source);
  
  return 1;
}

//显示物品的鉴定级别
//所有鉴定级别定义采用标准定义，具体见IL_系列define，不管内部如何定义，外部统一采用该返回值定义
varargs int get_idflevel(object item)
{
  object ob=this_object();
  
  if ( objectp(item) )
    return item->get_idflevel();
  //简单物件直接显示详细信息
  else if ( ob->is_identify()==IDF_SIMPLE )
    return IL_FULL;
  else
    return ob->query("identified");  
}

//增加destme函数，在weapon断掉后一段时间自动消失
int destroyme(object me)
{
  if (environment(me))
    message_vision(me->query("name") + "由于损坏严重，慢慢变成碎片消失了......\n",me);
  destruct(me);
  return 1;
}
int destme()
{
  call_out("destroyme",30,this_object());
  return 1;
}

mapping query_action()
{
  return WEAPON_D->query_action();
}

//对未知属性的鉴定
//char_key/char_val为未知属性的关键字和值
//idf_level为鉴定级别
//equip_type为鉴定的装备类型描述，分别是武器、装备、套装
protected string get_idf_msg(string char_key, mixed char_val, int idf_level, string equip_type)
{
  object ob=this_object();
  string char_idf, substr;
  int sl;
  string *subk;
  
  if ( member_array( char_key, keys(identify_effect_set) )== -1 )
  {
    if ( intp(char_val) )
    {
      char_idf=sprintf(HIR"      未知属性: %s〖%d〗\n"NOR, char_key, char_val);
      log_file("wiz/attribute", sprintf(HIR"%s%s:      未知属性: %s〖%d〗\n"NOR, equip_type, base_name(ob), char_key, char_val));
    }
    else 
    {
      char_idf=sprintf(HIR"      未知属性: %s\n"NOR, char_key);
      log_file("wiz/attribute", sprintf(HIR"%s%s:      未知属性: %s〖%O〗\n"NOR, equip_type, base_name(ob), char_key, char_val));
    }
  }
  else
  {
    if (idf_level==IL_FULL)
    {
      char_idf="";
      if ( intp(char_val) )
        char_idf=sprintf("      %s : "HIC"%d%s\n"NOR,   identify_effect_set[char_key][0], char_val, identify_effect_set[char_key][1]);
      else if ( mapp(char_val) )
      {
        subk=keys(char_val);
        for(sl=0;sl<sizeof(subk);sl++)
        {
          if ( stringp(subk[sl]) )
          {
            if ( subk[sl]=="unarmed" )
              substr=replace_string(identify_effect_set[char_key][0],  "$sk$", "空手");
            else
              substr=replace_string(identify_effect_set[char_key][0],  "$sk$", replace_string(to_chinese(subk[sl]),"基本",""));
          }
          else
            substr=identify_effect_set[char_key][0];
                
          char_idf+=sprintf("      %s : "HIC"%d%s\n"NOR,   substr, char_val[subk[sl]], identify_effect_set[char_key][1]);
        }
      }
      else      
        char_idf=sprintf("      %s : "HIC"%O%s\n"NOR,   identify_effect_set[char_key][0], char_val, identify_effect_set[char_key][1]);
    }
    else if ( idf_level==IL_SIMPLE)
    {
      char_idf="";
      if ( mapp(char_val) )
      {
        subk=keys(char_val);
        for(sl=0;sl<sizeof(subk);sl++)
        {
          if ( stringp(subk[sl]) )
          {
            if ( subk[sl]=="unarmed" )
              substr=replace_string(identify_effect_set[char_key][0],  "$sk$", "空手");
            else
              substr=replace_string(identify_effect_set[char_key][0],  "$sk$", replace_string(to_chinese(subk[sl]),"基本",""));
          }
          else
            substr=identify_effect_set[char_key][0];
                
          char_idf+=sprintf("      %s : "HIC"有\n"NOR,   substr);
        }
      }
      else 
        char_idf=sprintf("      %s : "HIC"有\n"NOR,   identify_effect_set[char_key][0]);
    }
  }
  
  return char_idf;
}

//将属性应用到人物身上
//其中appl_type分为suit，armor，weapon；分别代表套装，装备，武器
//    appl_direct分为equip和unequip，分别代表装备和卸除
protected void applied_character(object ob, string char_key, mixed char_val, string appl_type, string appl_direct )
{
  mapping applied_prop, gem_prop, mchar;
  string *subk, sk;
  int lp, gemp, vl;
  
  applied_prop=ob->query_temp("apply");
  if( !mapp(applied_prop) ) 
    applied_prop = ([]);
  
  if ( mapp(char_val) )
    mchar=([])+char_val;
  
  if ( appl_direct=="equip" )
  {
    if ( undefinedp(applied_prop[char_key]) )
      applied_prop[char_key]=char_val;
    else if ( intp(char_val) )
      applied_prop[char_key]+=char_val;
    else if ( mapp(char_val) )
    { 
      if ( !mapp(applied_prop[char_key]) )
        applied_prop[char_key]=([]);
    
      subk=keys(mchar);
      for(lp=0;lp<sizeof(subk);lp++)
      {
        vl=0+mchar[subk[lp]];
        sk=""+subk[lp];
        if ( undefinedp(applied_prop[char_key][sk]) )
          applied_prop[char_key][sk]=vl;
        else
          applied_prop[char_key][sk]+=vl;
      }
    }
  }
  else
  {
    if ( intp(char_val) )
      applied_prop[char_key]-=char_val;
    else if ( mapp(char_val) )
    { 
      subk=keys(mchar);
      for(lp=0;lp<sizeof(subk);lp++)
      {
          vl=0+mchar[subk[lp]];
          sk=""+subk[lp];
          applied_prop[char_key][sk]-=vl;
      }
    }
  }
  
  //本段代码是支持装备中存在限定装备属性最大值的处理
  if ( appl_type!="suit" )
  {
    gem_prop=this_object()->query("gem_prop");
    if ( !mapp(gem_prop) ) gem_prop=([]);
  
    if ( !undefinedp(gem_prop[char_key]) &&
         !undefinedp(gem_equip_limit[char_key]) )
    {
      if ( appl_direct=="equip" )
      {
        ob->add_temp("gem_prop/"+char_key, gem_prop[char_key] );
        if ( gem_equip_limit[char_key]>0 && 
             ob->query_temp("gem_prop/"+char_key)>gem_equip_limit[char_key] )
        {
          applied_prop[char_key]=applied_prop[char_key]+gem_equip_limit[char_key]-ob->query_temp("gem_prop/"+char_key);
          ob->add_temp("gem_limit_prop/"+char_key, ob->query_temp("gem_prop/"+char_key)-gem_equip_limit[char_key]);
          ob->set_temp("gem_prop/"+char_key, gem_equip_limit[char_key]);
        }
        else if ( gem_equip_limit[char_key]<0 && 
             ob->query_temp("gem_prop/"+char_key)<gem_equip_limit[char_key] )
        {
          applied_prop[char_key]=applied_prop[char_key]+gem_equip_limit[char_key]-ob->query_temp("gem_prop/"+char_key);
          ob->add_temp("gem_limit_prop/"+char_key, ob->query_temp("gem_prop/"+char_key)-gem_equip_limit[char_key]);
          ob->set_temp("gem_prop/"+char_key, gem_equip_limit[char_key]);
        }
      }
      else
      {
        gemp=gem_prop[char_key];
        if ( ob->query_temp("gem_limit_prop/"+char_key) && 
             ((ob->query_temp("gem_limit_prop/"+char_key)>gemp &&
               gem_equip_limit[char_key]>0) ||
             (ob->query_temp("gem_limit_prop/"+char_key)<gemp &&
               gem_equip_limit[char_key]<0)) )
        {
          ob->add_temp("gem_limit_prop/"+char_key, -gemp);
          ob->add_temp("apply/" + char_key, gemp);
          gemp=0;
        }
        else if ( ob->query_temp("gem_limit_prop/"+char_key) && 
           ((ob->query_temp("gem_limit_prop/"+char_key)<=gemp &&
             gem_equip_limit[char_key]>0) ||
            (ob->query_temp("gem_limit_prop/"+char_key)>=gemp &&
             gem_equip_limit[char_key]<0)) )
        {
          ob->add_temp("apply/" + char_key,  ob->query_temp("gem_limit_prop/"+char_key) );
          gemp=gemp-ob->query_temp("gem_limit_prop/"+char_key);
          ob->delete_temp("gem_limit_prop/"+char_key);        
        }
      
        ob->add_temp("gem_prop/"+char_key, -gemp );
        if ( gem_equip_limit[char_key]>0 && 
             ob->query_temp("gem_prop/"+char_key)+gemp>=0 &&
             ob->query_temp("gem_prop/"+char_key)<0 )
        {
          ob->add_temp("apply/" + char_key, -ob->query_temp("gem_prop/"+char_key));
          ob->delete_temp("gem_prop/"+char_key);
        }
        else if ( gem_equip_limit[char_key]<0 && 
             ob->query_temp("gem_prop/"+char_key)+gemp<=0 &&
             ob->query_temp("gem_prop/"+char_key)>0 )
        {
          ob->add_temp("apply/" + char_key, -ob->query_temp("gem_prop/"+char_key));
          ob->delete_temp("gem_prop/"+char_key);
        }
      }
    }
  }
    
  if ( userp(ob) &&
       char_key=="max_qi" )
  {
    ob->set("max_qi", ob->query_max_qi() );
    if ( ob->query("eff_qi") > ob->query("max_qi") )
      ob->set("eff_qi", ob->query("max_qi") );
  }
      
  if ( userp(ob) &&
       char_key=="max_jing" )
  {
    ob->set("max_jing", ob->query_max_jing() );
    if ( ob->query("eff_jing") > ob->query("max_jing") )
      ob->set("eff_jing", ob->query("max_jing") );
  }
}