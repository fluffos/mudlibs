varargs int do_attack(object me, object victim, object weapon, int attack_type, string attack_msg);
protected int is_hubo(object me);
protected int is_hubei(object me);

object find_skill(string skill)
{
    object sk;
    if(!objectp(sk=load_object("/kungfu/skill/"+skill)))
    {
        sk = load_object("/kungfu/player_skill/"+skill);
    }
    return sk;
}

string choose_attack_skill(object me,object weapon)
{
    mapping prepare;
    string skill = "";

    prepare = me->query_skill_prepare();
    if (!prepare) prepare = ([]);
    if( objectp(weapon) )  skill = weapon->query("skill_type");
    else if ( sizeof(prepare) == 0)  skill = "unarmed";
    else if ( sizeof(prepare) == 1)  skill = (keys(prepare))[0];
    else if ( sizeof(prepare) == 2)  skill = (keys(prepare))[me->query_temp("action_flag")];              

    return skill;
}

//计算攻击速度，攻击速度以100为单位，每100表示可以出一招
//比如200表示一个心跳可以出两招，50表示2个心跳出一招
varargs int attack_speed(object me, object weapon, int hubo, int hubei)
{
	int spd, base, allspd, hbspd, dexspd, skspd, buff, wspd;
	string attack_skill, martial_skill;
	
	attack_skill = choose_attack_skill(me,weapon);
	martial_skill = me->query_skill_mapped(attack_skill);
//武器的基本速度，兵器本身带有属性weapon_speed属性，表示兵器的基本攻击速度
//如果该属性没有置，则默认武器攻击速度100；
	if ( !objectp(weapon) )
		base=120;
	else
		base=weapon->query_speed();
//如果未设置速度属性则取默认值100	
	if ( !base )
		base=100;

//互博和互备之间不能叠加，互博是基础速度翻倍，互备是基础速度的1.5倍	
// hbspd 计算互搏互备的加成效果，互搏100表示提高100%，互备提高50%，这是第一个加成因素 by lordstar 2017/9/12
	if ( hubo )
		hbspd=100;
	else if ( hubei )
		hbspd=50;
	else
		hbspd=0;
  
  //先天身法能影响攻速，攻速影响范围是基础攻速的+-10%
// dexspd 计算先天身法的加成效果，这是第二个加成因素 by lordstar 2017/9/12
  dexspd = (me->query("dex")-30)/2;
	
//提供攻击技能本身附带的攻击速度影响，攻击技能将提供额外的以基本速度为
//计数单位的百分比影响，只能在-200%到+200%范围内浮动
// skspd 计算技能的加成效果，这是第三个加成因素 by lordstar 2017/9/12
	if ( martial_skill )
	{
	  skspd=find_skill(martial_skill)->skill_speed(me);
    if ( skspd < -200 )
  	  skspd=-200;
    else if ( skspd> 200 )
  	  skspd=200;
//	  spd+=base*skspd/100;
	}
	
//增加属性apply/attack_speed提供外部装备等对攻击速度的额外影响
//该属性属于基于基本武器速度的百分比影响，效果取值范围在-500%到500%之间。
// buff 计算外部加成的效果，这是第四个加成因素 by lordstar 2017/9/12
	buff=me->query_temp("apply/attack_speed");
	if ( buff>500 )
		buff=500;
	else if ( buff<-500 )
		buff=-500;
	
//	spd+=base*buff/100;
// allspd 计算所有四个加成因素的总和，当总和大于零时，进行乘数计算；当总和小于零时，应当是进行除数计算！原先用减号计算是错误的！ by lordstar 2017/9/12
	allspd = hbspd + dexspd + skspd + buff;
	if (allspd>=0)
	{
		spd=base*(100+allspd)/100;
	}
	else
	{
		spd=base*100/(100-allspd);
	}		

	if (spd>800)
	{
		spd=800;
	}
//提供最小为10的速度	
	if ( spd<10 )
		return 10;
	else
	  return spd;
}

//判断是否左右互搏
int is_hubo(object me)
{
	if (me->query("zyhb")||me->query_temp("can_zyhb")) 
		return 1;
	else
		return 0;
}

//互博攻击
protected void hubo_attack(object me,object victim)
{
	if ( is_hubo(me) )
    combat_msg(HIR "$N使出「左右互搏」的绝技，左手一晃又准备出一招！\n" NOR,1, me,victim);
  me->changewield();
  me->set_temp("action_flag",1);
  do_attack(me,victim,me->query_temp("weapon"),TYPE_QUICK);
  me->changewield();
  me->set_temp("action_flag",0);
}

//判断是否互备功夫
//返回值0表示不存在互备功夫
//返回值1表示互备了兵器功夫
//返回值2表示互备了拳脚功夫
int is_hubei(object me)
{
	string *wp, *wpre;
	
  //互备了空手功夫，或者使用的是辟邪剑法的时候
  if( (!objectp(me->query_temp("weapon"))
      && sizeof(me->query_skill_prepare()) > 1) )
    return 2;
  //互备了兵器功夫时（以下分具体的情况）
  else if((me->query_temp("weapon"))&&(me->query_temp("secondary_weapon")))
  {
    wp=({});
    
    if ( sizeof(me->query_wprepare())>1 )
    {
    	wp+=({(me->query_temp("weapon"))->query("skill_type")});
    	wp+=({(me->query_temp("secondary_weapon"))->query("skill_type")});
    	wpre=sort_array(keys(me->query_wprepare()), (: strcmp :) );
    	wp=sort_array(wp, (: strcmp :) );
    	if ( wp[0]==wpre[0] &&
    		   wp[1]==wpre[1] )
    	  return 1;
    }
  }
  
  return 0;
}