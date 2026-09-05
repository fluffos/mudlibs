// disguised.c 伪装和伪装识别相关的算法集成
// by seagate@pkuxkx 2010/12/05
//伪装需要相关物品支持，物品身上必须有以下和伪装术相关的属性：
// min_level -- 使用该物品的最低伪装术级别
// max_level -- 使用该物品可以获得伪装术提升的最高级别
// add_level -- 该物品的伪装复杂度增益
// max_complex -- 该伪装物品最大能够支持的复杂度

#include <ansi.h>

//检验是否可以伪装的函数，如果函数不通过则不允许进行伪装
int valid_disguise(object obj, object user)
{
	int min_l, disg_sk, per;
	
	if ( !obj->query("min_level") ||
		   obj->query("min_level") < 0 )
	  min_l=0;
	else
		min_l=obj->query("min_level");
	
	disg_sk=user->query_skill("disguise", 1);
	per=user->query_per();
//容貌惩罚，20容貌是伪装术最好的容貌要求，否则都因为容貌过于不普通而带来容貌惩罚
//容貌超过30，将带来3倍的容貌惩罚
  if ( per<=20 )
		per = (20 - per) * 5;
	else if ( per<=30 )
		per = (per - 20) * 5;
	else
		per = 50 + (per - 30) * 15;
	
	if ( !min_l )
		return 1;
	else if ( !disg_sk )
		return 0;
	else if ( min_l <= disg_sk - per )
		return 1;
	else
		return 0;
}

//查询本次伪装的复杂度
//复杂度由三个部分组成：使用者的伪装技能，物品的伪装增益，使用者容貌带来的伪装惩罚
int query_complex(object obj, object user)
{
	int disg_sk, disg_add, per;
	
	disg_sk=user->query_skill("disguise", 1);
	disg_add=obj->query("add_level");
	per=user->query_per();
//容貌惩罚，20容貌是伪装术最好的容貌要求，否则都因为容貌过于不普通而带来容貌惩罚
//容貌超过30，将带来3倍的容貌惩罚
	if ( per<20 )
		per = (20 - per) * 5;
	else if ( per<=30 )
		per = (per - 20) * 5;
	else
		per = 50 + (per - 30) * 15;

//本身不具备伪装术则无法获得任何伪装术复杂度，也就是说只要有识别术就能识破对方的伪装	
	if ( disg_sk + disg_add - per <=0 || !disg_sk )
		return 1;
	else
	{
		if ( disg_sk + disg_add - per>=obj->query("max_complex") && 
			   obj->query("max_complex") )
			return obj->query("max_complex");
		else
		  return disg_sk + disg_add - per;
	}
}

//查询本次识别的复杂度
//识别伪装的复杂度组成由anti-disguise技能等级，悟性增益两个部分组成
int query_anti_complex(object user)
{
	int anti_sk,u_int;
	
	anti_sk=user->query_skill("anti-disguise", 1);
	u_int=user->query_int();
	
	if ( u_int <= 50 )
		u_int=0;
	else if ( u_int <=100 )
		u_int=u_int-50;
	else
		u_int=50+ (u_int-100) * 2;
	
	if ( !anti_sk )
		return 1;
	else
		return anti_sk+u_int;
}

//查询识别伪装的时候可以识别的伪装层数
int query_anti_level(object user)
{
	return 1;
}

//提升伪装术或者伪装识别技能函数，其中type为提升的技能类型，0为伪装术，1为伪装识别技能
// complex是本次伪装或者本次识别的复杂度
int improve_disguise(int type, int complex, object user)
{
	int key;
	
	if ( !type )
	{
		key=user->query_per();
		if ( !complex )
			user->improve_skill("disguise", 1);
		else if ( key>=15 && key<=25 )
			user->improve_skill("disguise", complex*3/2);
		else if ( key<=30 )
			user->improve_skill("disguise", complex*2/3);
		else
			user->improve_skill("disguise", complex/3);
	}
	else 
	{
		key=user->query_int();
		if ( !complex )
			user->improve_skill("anti-disguise", 1);
		else if ( key<=50 )
			user->improve_skill("anti-disguise", complex/3);
		else if ( key<=100 )
			user->improve_skill("anti-disguise", complex*2/3);
		else
			user->improve_skill("anti-disguise", complex*3/2);
	}
}