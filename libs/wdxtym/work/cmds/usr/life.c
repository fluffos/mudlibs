// 生活技能 by 潇湘夜雨(bianco)
#define WORK "$busy$"
#include <ansi.h>

inherit F_CLEAN_UP;
int show(object me,string where);
int work(object me,string arg,string where);
int shouhuo(object me,string arg,string oldwhere);
int jixu(object me);
int halt_working(object me);


int main(object me, string arg)
{
	object ob;
	string r,where;
where=environment(me)->query("short");
//	if (environment(me)->query("pigging"))
//		return notify_fail("你还是安心的拱猪吧！\n");
	if (me->is_in_prison())
		return notify_fail("好好的做你的牢吧。\n");
		
if (environment(me)->query("close_room"))
return notify_fail("你想把这里拆了?。\n");

	if (me->is_ghost())
		return notify_fail("你还是等还了阳再说吧。\n");
		
		if (arg=="sell")
{
if (!me->query("life_sell"))
me->set("life_sell",1);
else
me->delete("life_sell");
me->force_me("life");
return 1;
}

	if (me->is_busy()&&arg!="cancel")
	{
		return notify_fail("你现在正忙，等有空了再说吧！\n");
		}

	if (me->is_fighting())
		return notify_fail("你还是把眼前的敌人放倒再说吧！\n");
		
if (!arg)
show(me,where);
 else
 work(me,arg,where);
}
int show(object me,string where)
{
string msg;

msg= HIR "◎"HIY "武动仙途生活系统：" HIR "◎"NOR+ZJBR;
msg+=HIG"——————————————————————"NOR+ZJBR;
msg+=HIW"伐树次数:"+me->query("life/cuttree")+ZJBR;
msg+="钓鱼次数:"+me->query("life/fishing")+ZJBR;
msg+="割草次数:"+me->query("life/mowing")+ZJBR;
msg+="种田次数"NOR":"+me->query("life/farming")+ZJBR;
msg+=HIG"————————此地可以进行————————"NOR"\n";
msg+=ZJOBACTS2+ZJMENUF(2,2,10,25);
if (me->is_busy())
msg+="取消工作:life halt"ZJSEP;
else
if (strsrch(where,"树林")!=-1||strsrch(where,"森林")!=-1||strsrch(where,"密林")!=-1)
msg+="伐树:life cuttree"ZJSEP;
else
 if (strsrch(where,"岸")!=-1||strsrch(where,"湖")!=-1||strsrch(where,"河")!=-1||strsrch(where,"河")!=-1||strsrch(where,"流域")!=-1||strsrch(where,"江")!=-1)
 msg+="钓鱼:life fishing"ZJSEP;
else
 if (strsrch(where,"草地")!=-1||strsrch(where,"草原")!=-1||strsrch(where,"草丛")!=-1) 
msg+="割草:life mowing"ZJSEP;
else
if (strsrch(where,"田地")!=-1||strsrch(where,"农田")!=-1||strsrch(where,"田野")!=-1)
msg+="种田:life farming"ZJSEP;
else
msg+="此地无可进行工作:life"ZJSEP;
if (!me->query("life_sell"))
msg+=HIY"自动售卖"HIW"：未开启"NOR":life sell";
else
msg+=HIY"自动售卖"HIC"：已开启"NOR":life sell";
write(ZJOBLONG+msg+"\n");
return 1;
}

int work(object me,string arg,string where)
{
 if (arg=="cuttree")
     {
     object weapon;
     if (!objectp(weapon = me->query_temp("weapon")))
     return notify_fail("你连家伙都没有，怎么?你是想用拳头撸吗？\n");
     if (strsrch(where,"树林")==-1&&strsrch(where,"森林")==-1&&strsrch(where,"密林")==-1)
      	return notify_fail("你要砍什么?这里有树吗??。\n");
         write("你抡起手中的"+weapon->name()+"对准一颗树砍了起来\n");
         
    }
    else
    if (arg=="fishing")
    {
     object handing;
     if (!objectp(handing = me->query_temp("handing"))||handing->query("id")!="diao gan")
     return notify_fail("你的鱼竿呢?还是先把它拿在手中先吧\n");
     if (strsrch(where,"岸")!=-1&&strsrch(where,"湖")!=-1&&strsrch(where,"河")!=-1&&strsrch(where,"流域")!=-1&&strsrch(where,"江")!=-1)
      	return notify_fail("你要什么钓鱼?这鬼地方有个啥鱼都没有！\n");
         write("你把手中的"+handing->name()+"甩进了"+where+"下，慢慢的等待鱼儿上钩。\n");
             
    }
     else
    if (arg=="mowing")
    {
     object weapon;
     if (!objectp(weapon = me->query_temp("weapon")))
     return notify_fail("你连家伙都没有，怎么?你是想用拳头割草吗？\n");
     if (strsrch(where,"草地")==-1&&strsrch(where,"草原")==-1&&strsrch(where,"草丛")==-1)
      	return notify_fail("你要什么割什么草,这里什么草都没有！。\n");
         write("你抡起手中的"+weapon->name()+"对准一堆草割了起来。\n");
                      
    }
    else
    if (arg=="farming")
    {
     object handing;
     if (!objectp(handing = me->query_temp("handing"))||(handing->query("id")!="gao tou"||handing->query("id")!="chu tou"))
     return notify_fail("你的锄头呢?还是先把它拿在手中先吧！\n");
     if (strsrch(where,"田地")==-1&&strsrch(where,"农田")==-1&&strsrch(where,"田野")==-1)
      	return notify_fail("你要什么种什么田?这鬼地方没法种田！\n");
         write("你抡起手中的锄头，开始种田，以期收获粮食。\n");            
    }
    else
    return 1;
  me->set_temp("continue_life",1);    
me->set_temp("lifegz/where",where);    
me->set_temp("lifegz/arg",arg);    
if (me->is_busy()==0)
  me->start_busy(bind((: call_other, __FILE__, "jixu" :), me),
      bind((: call_other, __FILE__, "halt_working" :), me));
//    call_out("shouhuo",6,me,arg,where);        
    return 1;
}

int jixu(object me)
{
string msg;
if (!me->query_temp("lifegz/arg"))
return 0;

if (!me->query_temp("continue_life"))
{
msg = "继续工作中";
work(me,me->query_temp("lifegz/arg"),me->query_temp("lifegz/where"));
return 1;
}
else
	switch (me->query_temp("continue_life"))
	{
	case 1:
		msg = WORK"工作中■□□□□\n";
		break;
	case 2:
		msg = WORK"工作中■■□□□\n";
		break;
	case 3:
		msg = WORK"工作中■■■□□\n";
		break;
		case 4:
		msg = WORK"工作中■■■■□\n";
		break;
		case 5:
		msg = WORK"工作中■■■■■\n";
		break;
	default:
	msg = "◆"HIR+ZJURL("cmds:halt")+"点击可停止工作"NOR+"◆";
	write(msg+"\n");	
	shouhuo(me,me->query_temp("lifegz/arg"),me->query_temp("lifegz/where"));	
	return 1;
		break;
	}
	write(msg+"\n");	
	me->add_temp("continue_life",1);
return 1;
}


int shouhuo(object me,string arg,string oldwhere)
{

string where;
object cailiao;
int exp,pot;
if (!objectp(me))
return 1;
exp=30+random(100)+random(me->query_skill("lifeskill",1));
pot=30+random(100)+random(me->query_skill("lifeskill",1));
where=environment(me)->query("short");
if (where!=oldwhere)
{
 me->delete("continue_life",1);
 remove_call_out("shouhuo");
write(HIR"你离开了"+oldwhere+",工作自动停止\n"NOR);        
return 1;    
}
if (arg=="cuttree")
{
me->add("life/cuttree",1);
cailiao = new("/clone/life/wood/wood"+(1+random(3)));
write(HIR"在你的辛勤砍伐下，一颗树终于倒下了，你急忙把它捡起来。\n"NOR);            
}

if (arg=="fishing")
{
me->add("life/fishing",1);
cailiao = new("/clone/life/fish/fish"+(1+random(3)));
write(HIR"你等了良久，见到鱼竿剧烈的摆动，赶忙拉起鱼竿，恭喜你收获了一条"+cailiao->query("name")+"\n"NOR);            
}

if (arg=="mowing")
{
me->add("life/mowing",1);
cailiao = new("/clone/life/grass/grass"+(1+random(3)));
write(HIR"你辛勤了良久，一撮撮草聚成了一堆，你思考再三觉得事宜，便把草堆拾了起来。\n"NOR);            
}

if (arg=="farming")
{
me->add("life/farming",1);
cailiao = new("/clone/life/rice/rice"+(1+random(3)));
write(HIR"在你的辛勤劳作下，"+where+"迎来了收获，你获得了一袋大米。\n"NOR);            
}
cailiao->move(me);
me->add("combat_exp",exp);
me->add("potential",pot);
write(HIY"你辛勤劳作，得到了锻炼,赢得了:"+exp+"点修为和"+pot+"点潜能\n"NOR);
me->delete_temp("continue_life");
if (me->query("life_sell"))
me->force_me("sellob "+cailiao->query("id"));
return 1;
}


int halt_working(object me)
{
me->delete_temp("lifegz/where");    
me->delete_temp("lifegz/arg");    
me->delete_temp("continue_life");
	write("你停下了手中的工作。\n");
	}
int help(object me)
{
	write(@HELP
生活系统。
HELP );
	return 1;
}

