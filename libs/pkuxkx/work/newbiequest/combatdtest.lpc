// letter.c 书信，超度任务往来凭证
#include "combat.h"

#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(YEL"测试工具"NOR, ({"letter"}));
  set_weight(100);
  if( clonep() )
  	set_default_object(__FILE__);
  else {
  	set("unit", "个");
    set("long","这是战斗系数测试工具。\n");
    set("material", "paper");
  }
}

void init()
{
	tell_object(this_player(), file_name(environment(this_player())));
	add_action("do_test","testd");
	add_action("do_time", "time");
	add_action("do_allow", "allow");
	add_action("do_xinfang","xinfang");
}

int do_allow(string arg)
{
  return LOGIN_D->add_allowed_id(arg);
}

int do_time()
{
	printf("当前日期：%s %d", ctime(time()), time());
	return 1;
}

int do_xinfang(string arg)
{
  object *tl;
  int lp;
  
  tl=filter_array(filter_array(children(USER_OB), (: userp :)), (: $1->query("family/family_name") == "天龙寺" :));
  printf("%d\n", sizeof(tl));
  for(lp=0;lp<sizeof(tl);lp++)
    if ( time()-tl[lp]->query("myroom/time")<=15*3600*24 )
       printf("%s的%s(%s)有嫌疑，mud_age：%f天，存款：%d金子，新房持有时间%f天\n",
                  tl[lp]->query("family/family_name"), tl[lp]->query("name"), tl[lp]->query("id"),
                  (float)(tl[lp]->query("mud_age")*1.0/3600/24), (int)(tl[lp]->query("advance_balance")*100+ tl[lp]->query("balance")/10000),
                  (float)( (time()-tl[lp]->query("myroom/time"))*1.0/3600/24) );
  return 1;
}

int do_test(string arg)
{
  int rate,rate2,lp;
  int idata1, idata2, rate3, level, loops;
  
  if ( sscanf(arg, "%d %d %d %d", idata1, idata2, level, loops)!=4 )
  {
  	write("命令格式错误。\n");
  	return 1;
  }
  
  rate=0;
  rate2=0;
  rate3=0;
  for(lp=0;lp<loops;lp++)
  {
  	rate+=F_KUNGFU->hit_rate( idata1, idata2, level, 0, 0);
  	rate2+=F_KUNGFU->hit_rate2( idata1, idata2, 10, level, 0, 0);
  	rate3+=F_KUNGFU->hit_rate2( idata1, idata2, -10, level, 0, 0);
  }
  
  printf("%s命中率[标准公式]为%.2f%%\n命中率[p=10]为%.2f%%\n命中率[p=-10]为%.2f%%\n", gctime(0,0), rate*100.0/loops, rate2*100.0/loops, rate3*100.0/loops);
  
  return 1;
}