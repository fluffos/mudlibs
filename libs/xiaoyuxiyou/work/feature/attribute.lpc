// attribute.c

#include <dbase.h>
#include <skill.h>

int query_max_gift()
{
	int level = this_object()->query_level();
	level = 40+level/2;
	if( !userp(this_object()) )
	{
		if( this_object()->max_gift()>0 )
		 	return this_object()->max_gift();
	}
	return level;
}

//膂力--1点增加4点物理攻击，1点物理防御，2点HP
int query_str()
{
	int pp,final= (int)query("str") + query("gift_modify/str") + query_temp("apply/strength");
	if(final>query_max_gift()) 
		final=query_max_gift();	
	if( this_object()->query_skill("longxiang-li",2)>100 )
	{
		pp = 5;
		pp+= (this_object()->query_skill("longxiang-li",1)-100)/150;
		final+= final*pp/100;
	}	
	return final;
}
//胆识--出招快慢，1点增加3点精力
int query_cor()
{
	int final= (int)query("cor") + query("gift_modify/cor") + query_temp("apply/courage");
	if(final>query_max_gift()) 
		final=query_max_gift();	
	return final;
}
//悟性--领悟成功率，1点增加2点精力
int query_int()
{
	int pp,final;
	final = (int)query("int") +query("gift_modify/int")+ query_temp("apply/intelligence");
	if((int)query_skill("literate",1)>60) 
		final += ((int)query_skill("literate",1)-60)/10;
	if(final>query_max_gift()) 
		final=query_max_gift();	
	//知时	悟性上限+5%
	if( this_object()->query_skill("zhishi",2)>100 )
	{
		pp = 5;
		pp+= (this_object()->query_skill("zhishi",1)-100)/150;
		final+= final*pp/100;
	}				
	return final;	
}
//灵性--1点增加4点法术攻击，1点法术防御，2点MP;MP的恢复
int query_spi()
{
	int pp,final;
	final = (int)query("spi") + query("gift_modify/spi") + query_temp("apply/spirituality");
	if((int)query_skill("spells",1)>60) 
		final += ((int)query_skill("spells",1)-60)/60;
	if(final>query_max_gift()) 
		final=query_max_gift();	
	if( this_object()->query_skill("liuli-xindeng",2)>100 )
	{
		pp = 5;
		pp+= (this_object()->query_skill("liuli-xindeng",1)-100)/150;
		final+= final*pp/100;
	}		
	return final;
}
//定力--1点增加2点法术防御，2点物理防御
int query_cps()
{
	int final= (int)query("cps") + query("gift_modify/cps")+ query_temp("apply/composure");
	if(final>query_max_gift()) 
		final=query_max_gift();	
	return final;
}
//容貌--解密触发率 以及诱惑类招式成功率
int query_per()
{
	int pp,final= (int)query("per")+ query("gift_modify/per")+ query_temp("apply/personality");
	if((int)query_skill("zhuyan",1)>100) 
		final += ((int)query_skill("zhuyan",1)-100)/50;
	if(final>query_max_gift()) 
		final=query_max_gift();
	//摄魄	魅力+5%
	if( this_object()->query_skill("shehun",2)>100 )
	{
		pp = 5;
		pp+= (this_object()->query_skill("shehun",1)-100)/150;
		final+= final*pp/100;
	}	
	return final;
}
//根骨--1点增加50点HP，20点MP；精力以及HP的恢复
int query_con()
{
	int final;
	final = (int)query("con") +query_temp("apply/constitution")+ query("gift_modify/con");
	if((int)query_skill("force",1)>60) 
		final += ((int)query_skill("force",1)-60)/60;
	if(final>query_max_gift()) 
		final=query_max_gift();		
	return final;
}
//福缘--掉落率以及恢复率
int query_kar()
{
	int final;
	final = (int)query("kar") + query_temp("apply/karma") + query("gift_modify/kar");
	if(final>query_max_gift()) 
		final=query_max_gift();			
	return final;
}

//物理攻击力
int query_combat_damage()
{
	object weapon;
	int p,damage;
	if( !weapon=query_temp("weapon") )
		damage = 0;
	else	damage = weapon->query_combat_damage();
	if( weapon = query_temp("secondary_weapon") )
		damage+= weapon->query_combat_damage();
	if( query_str()>0 )
		damage+= query_str()*4;	
	damage+= query_temp("apply/combat_damage");	
	damage+= this_object()->query_level()*3;
	if( this_object()->query_skill("zhidi-chenggang",2)>1 )
	{
		if( this_object()->query_skill("zhidi-chenggang",1)>100 )
		{
			p = (this_object()->query_skill("zhidi-chenggang",1)-100)/150+1;
			damage = damage*(100+p)/100;
		}
	}
	else if( this_object()->query_skill("jingang-zhenshen",2)>1 )
	{
		p = (this_object()->query_skill("jingang-zhenshen",1)-100)/150+3;
		damage = damage*(100+p)/100;
	}
	return damage;	
}
//物理防御力
int query_combat_def()
{
	int p,def = 0;
	def+= query_str();
	def+= query_cps()*2;
	def+= query_temp("apply/combat_def");
	def+= this_object()->query_level()*4;
	if( this_object()->query_skill("jingang-zhenshen",2)>1 )
	{
		p = (this_object()->query_skill("jingang-zhenshen",1)-100)/150+3;
		def = def*(100+p)/100;
	}
	return def;
}
//法术攻击力
int query_spells_damage()
{
	object weapon;
	int p,damage;
	if( !weapon=query_temp("weapon") )
		damage = 0;
	else	damage = weapon->query_spells_damage();
	if( weapon = query_temp("secondary_weapon") )
		damage+= weapon->query_spells_damage();
	if( query_str()>0 )
		damage+= query_spi()*4;	
	damage+= query_temp("apply/spells_damage");	
	damage+= this_object()->query_level()*3;
	if( this_object()->query_skill("huanyu-hufeng",2)>1 )
	{
		if( this_object()->query_skill("huanyu-hufeng",1)>100 )
		{
			p = (this_object()->query_skill("huanyu-hufeng",1)-100)/150+1;
			damage = damage*(100+p)/100;
		}
	}
	else if( this_object()->query_skill("tianlong-chanchang",2)>1 )
	{
		p = (this_object()->query_skill("tianlong-chanchang",1)-100)/150+3;
		damage = damage*(100+p)/100;
	}	
	return damage;	
}
//法术防御力
int query_spells_def()
{
	int pp,def = 0;
	def+= query_spi();
	def+= query_cps()*2;
	def+= query_temp("apply/spells_def");
	def+= this_object()->query_level()*5;
	//嫁梦	法术防御+1%
	if( this_object()->query_skill("jiameng",2)>100 )
	{
		pp = 1;
		pp+= (this_object()->query_skill("jiameng",1)-100)/300;
		def+= def*pp/100;
	}
	else if( this_object()->query_skill("tianlong-chanchang",2)>1 )
	{
		pp = (this_object()->query_skill("tianlong-chanchang",1)-100)/150+3;
		def = def*(100+pp)/100;
	}
	return def;
}

//最大寿元 -1为不堕轮回
int query_life()
{
	return this_object()->query_max_life();											
}