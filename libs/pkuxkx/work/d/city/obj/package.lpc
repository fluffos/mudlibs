#include <ansi.h>
#include <title.h>
#include <command.h>
inherit ITEM;	



void create()
{
        set_name(HIC"测试包"NOR,({ "test package","bao"}) );
        set_weight(4000);
        set("unit", "个");
        set("value", 10);
        set("material", "steel");
        set("long", "这是一个测试包。\n");                
        set("no_drop",1);
        set("no_get",1);
		
        setup();
}

void init()
{

    add_action("do_test","test");
    add_action("do_rehash","rehash");
    add_action("do_children","children");
    add_action("do_t1","t1");


}

int hit_rate(int owner_data, int target_data, int rate_level, object owner, object target)
{
  int *rate_coef=({1000, 500, 333, 250, 200, 167, 143,   //S到B-
                         125, 111, 100, 90,  80,  70,    //C+到D-
                         60,  50,  40,  30,  20,  10});  //E+到F-
  int idata1, idata2,a,b;
  int owner_hr, target_hr,ori_rate_lv;
  string * lv_des=({"S","A+","A","A-","B+","B","B-","C+","C","C-","D+","D","D-","E+","E","E-","F+","F","F-",});
  ori_rate_lv=rate_level;
//数据初始化，保证数据足够大，使得概率更准确一点  
  if ( owner_data<1000 && target_data<1000 )
  {
    idata1=owner_data*100;
    idata2=target_data*100;
  }
  else if ( owner_data>=100000000 || target_data>=100000000 )
  {
    idata1=owner_data/1000;
    idata2=target_data/1000;
  }
  else if ( owner_data>=10000000 || target_data>=10000000 )
  {
    idata1=owner_data/100;
    idata2=target_data/100;
  }
  else if ( owner_data>=1000000 || target_data>=1000000 )
  {
    idata1=owner_data/10;
    idata2=target_data/10;
  }
  else
  {
    idata1=owner_data;
    idata2=target_data;
  }
  
  //命中率受到发起方先天身法的影响，调整几率范围大致在-10%到+10%区间内
  idata1=idata1*(owner->query("dex")+150)/180;
//如果是负数或者0，则置最小值1  
  if ( idata1<=0 )
    idata1=5;
  
  if ( idata2<=0 )
    idata2=5;

//命中率级别调整检查，对于攻击方提供kf_hit_rate属性来上调命中率级别
//                    对于防御方提供kf_anti_hr属性来下调命中率级别
  if ( objectp(owner) && ( owner_hr=owner->query_kf_hitrate() ) )
  {
    //攻击者只能最多上调命中率级别三级
    if ( owner_hr>3 )
      owner_hr=3;
    if ( owner_hr<-5 )
      owner_hr=-5;
      
    rate_level-=owner_hr;
  }
  
  if ( objectp(target) && ( target_hr=target->query_kf_antirate() ) )
  {
    //防御者只能最多下调命中率级别三级
    if ( target_hr>3 )
      target_hr=3;
    if ( target_hr<0 )
      target_hr=0;
    
    rate_level+=target_hr;
  }

//削减命中率，在高命中率级别idata2/idata1比值过大区间命中率下跌速度不够快速  
  if ( idata2>=idata1*2 && rate_level<=11 && rate_level>6 )
    rate_level++;
  else if ( idata2>=idata1*2 && rate_level<=6 && rate_level>3 )
    rate_level+=2;
  else if ( idata2>=idata1*2 && rate_level<=3 )
    rate_level+=3;
    
//提升命中率，在低命中率级别idata1/idata2过大区间命中率上升速率不够快速
  if ( idata1>=idata2*2 && rate_level<15 && rate_level>=12 )
    rate_level--;
  else if ( idata1>=idata2*2 && rate_level>=15 )
    rate_level-=2;
  
  if ( rate_level<0 )
    rate_level=0;
  
  if ( rate_level>18 )
    rate_level=18;
	a=random(idata1);
	b=random(idata2)*100/rate_coef[rate_level];
  tell_object(owner,"敌人原始命中级别："+lv_des[ori_rate_lv]+"/敌人当前命中级别："+lv_des[rate_level]+"||与自己相当敌人参数："+a+",自己参数："+b+"。");
  if (a>b)
  tell_object(owner,HIR"中\n"NOR);
  else
  tell_object(owner,HIW"不中\n"NOR);
  if ( random(idata1)>random(idata2)*100/rate_coef[rate_level] )
    return 1;
  else
    return 0;
}
int do_t1()
{
	object me=this_player();
	if (time()-me->query_temp("testxxxx")<2&&!wizardp(me))
	return notify_fail("too fast.\n");
	me->set_temp("testxxxx",time());
	return hit_rate(this_player()->query("combat_exp"), this_player()->query("combat_exp"), 6, me, me);
}