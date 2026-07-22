// 骤现妖身
//lestat for 雪山
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

void remove_effect(object me,int kee,int sen,int force,int mana,int combat_def,int combat_damage,int spells_def,int spells_damage);

int cast(object me, object target)
{
	int t,kee,sen,force,mana,other=0;
	int combat_def,combat_damage,spells_def,spells_damage;
	int c_kee,c_kee2,c_sen,c_sen2,c_force,c_mana;
	string msg,type;
	
	if( me->query_level()<50 )
		return notify_fail("你的人物等级不够。\n");
	if( me->query("class")!="yaomo" )
		return notify_fail("你不是妖魔，现不了妖身。\n");
	if( me->query("family/family_name")!="大雪山" )
		return notify_fail("「骤现妖身」是大雪山绝技。\n");
	if( me->query("mana")<300 )
		return notify_fail("你的法力不够。\n");
	if( me->query_skill("dengxian-dafa",1)<500 )
		return notify_fail("你的登仙大法不够娴熟。\n");
	if( me->query_temp("yaoshen") )
		return notify_fail("你已经现了妖身。\n");
	
	t = me->query_skill("fenghuang-xuemai",1)+me->query_skill("niuzhuan-qiankun",1)+me->query_skill("tunshi-tiandi",1)+me->query_skill("diandao-yinyang",1);
	t/= 100;
	if( t>5 )
		t = 5;
	t = 10-t;	
	if( time()<me->query_temp("last_yaoshen")+t )
		return notify_fail("你不能频繁现妖身。\n");
		
	if( !me->query("family/master_name") )
		other = 1;	
	else
	{
		switch(me->query("family/master_name"))
		{
			case "孔雀公主" :
				type = "七彩孔雀";kee=sen=10000;force=mana=5000;
				combat_damage = combat_def = 500;
				spells_damage = spells_def = 500;
				break;
			case "大鹏明王" :
				type = "摩天大鹏";kee=sen=20000;force=mana=10000;
				combat_damage = combat_def = 800;
				spells_damage = spells_def = 800;
				break;
			case "青狮老魔" :
				type = "青面巨狮";kee=sen=10000;force=mana=5000;
				combat_damage = combat_def = 600;
				spells_damage = spells_def = 300;
				break;
			case "白象尊者" :
				type = "三丈白象";kee=sen=10000;force=mana=5000;
				combat_damage = combat_def = 300;
				spells_damage = spells_def = 600;
				break;
			default : other = 1;break;
		}
	}
	if( other==1 )
	{
		if( me->query_level()<60 )
		{
			type = "扁嘴乌鸦";kee=sen=500;force=mana=300;
			combat_damage = combat_def = 50;
			spells_damage = spells_def = 50;	
		}
		else if( me->query_level()<90 )
		{
			type = "金喙老鹰";kee=sen=1000;force=mana=500;
			combat_damage = combat_def = 100;
			spells_damage = spells_def = 100;	
		}
		else if( me->query_level()<100 )
		{	
			type = "五彩孔雀";kee=sen=3000;force=mana=1000;
			combat_damage = combat_def = 300;
			spells_damage = spells_def = 300;	
		}
		else
		{
			type = "金翅大鹏";kee=sen=5000;force=mana=3000;
			combat_damage = combat_def = 500;
			spells_damage = spells_def = 500;	
		}	
	}		
	
	me->delete_temp("spellslevel");
	me->delete_temp("apply/name");
	me->delete_temp("apply/id");
	me->delete_temp("apply/short");
	me->delete_temp("apply/long");
	me->delete_temp("family");
	me->delete_temp("no_heal_up/bian");
	if(me->query_temp("d_mana")) 
	{
		me->delete_temp("d_mana");
	  	while( environment(me)->is_character() )
	     		me->move(environment(environment(me)));
	} 
	
	message_vision(HIY"\n$N"HIY"念动真言，一道金光闪过，顿时现出了"+type+"的真身！\n\n"NOR,me);
	me->add("mana",-300);
	me->set_temp("d_mana",1);
	me->set_temp("yaoshen",1);
	me->set_temp("apply/name",({type}));
	me->set_temp("spellslevel",1);
	me->set_temp("apply/race","野兽");
	me->set_temp("is_living",1);
	c_mana = me->query_maxmana()-me->query("mana");
	me->add_temp("apply/max_mana",mana);
	me->set("mana",me->query_maxmana()-c_mana);

	c_force = me->query_maxforce()-me->query("force");
	me->add_temp("apply/max_force",force);
	me->set("force",me->query_maxforce()-c_force);
	
	c_kee = me->query("eff_kee")-me->query("kee");
	c_kee2 = me->query_maxkee()-me->query("eff_kee");
	me->add_temp("apply/max_kee",kee);
	me->set("eff_kee",me->query_maxkee()-c_kee2);
	me->set("kee",me->query("eff_kee")-c_kee);
	
	c_sen = me->query("eff_sen")-me->query("sen");
	c_kee2 = me->query_maxsen()-me->query("eff_sen");
	me->add_temp("apply/max_sen",sen);
	me->set("eff_sen",me->query_maxsen()-c_sen2);
	me->set("sen",me->query("eff_sen")-c_sen);
	
	me->add_temp("apply/combat_def",combat_def);
	me->add_temp("apply/combat_damage",combat_damage);
	me->add_temp("apply/spells_def",spells_def);
	me->add_temp("apply/spells_damage",spells_damage);
	
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me,kee,sen,force,mana,combat_def,combat_damage,spells_def,spells_damage :), 900);
	return 1;
}

void remove_effect(object me,int kee,int sen,int force,int mana,int combat_def,int combat_damage,int spells_def,int spells_damage)
{
	int c_kee,c_kee2,c_sen,c_sen2,c_force,c_mana;
	if( !me || !me->query_temp("yaoshen") )	
		return;
	message("vision",HIY+me->name()+HIY"要身摇了摇，却原来是"+me->query("name")+"。\n"NOR,environment(me),me);
	tell_object(me,HIY"你撤去了妖身。\n"NOR);
	me->delete_temp("spellslevel");
	me->delete_temp("apply/name");
	me->delete_temp("apply/id");
	me->delete_temp("apply/short");
	me->delete_temp("apply/long");
	me->delete_temp("family");
	me->delete_temp("yaoshen");
	me->delete_temp("no_heal_up/bian");
	me->delete_temp("is_living");
	me->add_temp("apply/combat_def",-combat_def);
	me->add_temp("apply/combat_damage",-combat_damage);
	me->add_temp("apply/spells_def",-spells_def);
	me->add_temp("apply/spells_damage",-spells_damage);	
	
	if(me->query_temp("d_mana")) 
	{
		me->delete_temp("d_mana");
	  	while( environment(me)->is_character() )
	     		me->move(environment(environment(me)));
	} 
	me->set_temp("last_yaoshen",time());

	c_mana = me->query_maxmana()-me->query("mana");
	me->add_temp("apply/max_mana",-mana);
	me->set("mana",me->query_maxmana()-c_mana);
	if( me->query("mana")<0 )
		me->set("mana",0);

	c_force = me->query_maxforce()-me->query("force");
	me->add_temp("apply/max_force",-force);
	me->set("force",me->query_maxforce()-c_force);
	if( me->query("force")<0 )
		me->set("force",0);
	
	
	c_kee = me->query("eff_kee")-me->query("kee");
	c_kee2 = me->query_maxkee()-me->query("eff_kee");
	me->add_temp("apply/max_kee",-kee);
	me->set("eff_kee",me->query_maxkee()-c_kee2);
	if( me->query("eff_kee")<100 )
		me->set("eff_kee",100);
	me->set("kee",me->query("eff_kee")-c_kee);
	if( me->query("kee")<100 )
		me->set("kee",100);
		
	c_sen = me->query("eff_sen")-me->query("sen");
	c_kee2 = me->query_maxsen()-me->query("eff_sen");
	me->add_temp("apply/max_sen",-sen);
	me->set("eff_sen",me->query_maxsen()-c_sen2);
	if( me->query("eff_sen")<100 )
		me->set("eff_sen",100);
	me->set("sen",me->query("eff_sen")-c_sen);
	if( me->query("sen")<100 )
		me->set("sen",100);
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：骤现妖身
        法术所属：登仙大法
        法术效果：现出自己的妖身，提高自身的各项状态
        	  冷却时间5-10秒
        法术条件：
                  雪山弟子
        	  人物等级50级
                  法力300点，消耗300点
                  登仙大法500级
STR;
        me->start_more(str);
        return 1;
}
