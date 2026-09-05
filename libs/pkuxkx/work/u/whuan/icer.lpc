//冰冰 levelup升级npc                                                                                                
//by kiden@pkuxkx                                                                                                
#include <ansi.h>
inherit NPC;                                                                                           

string* gifts =({
	"str","int","dex","con","kar","per","spi",
	}); 

void create()                                                                                          
{  
	set_name("冰冰", ({ "icer npc"}) ); 
	set("gender","女性");   
	set("age",25);
	set("per",40); 
	set("str",40); 
	set("int",40); 
	set("dex",40); 
	set("con",40); 
	set("kar",40);
	set("attitude", "friendly");
	set("combat_exp", 2000000000);
	set("apply/attack",  300000); 
	set("apply/defense", 30000);
	set("inquiry",([
	   ]));
	setup();
	carry_object("/d/huashan/obj/greenrobe")->wear();
}

void init()
{
	add_action("level_up","levelup"); 
	add_action("level_query","levelquery"); 
}
int level_query(string arg)
{
	object me=this_player();
	int level,exp,gold,repute;
	string str;
	if(!arg)
		{
		tell_object(me,HIY"请输入一个数字!\n"NOR);
		return 1;
		}
	sscanf(arg,"%d",level);
	if (level>100) 
		{
			tell_object(me,HIY"北大侠客行最多支持100级!\n"NOR);
			return 1;
		}
	if (level>0) 
		{
			exp=level*level*level*400;
			repute=level*20000;
			gold=level*10;
			tell_object(me,HIY"升级到"+HIC+level+NOR+HIY"级，需要经验值达到"+HIC+exp+NOR+HIY",需要声望达到"+HIC+repute+NOR+HIY"，需要缴纳存款"+HIC+gold+HIY"两黄金!\n"NOR);
		}
	return 1;	
}

int level_up()
{
	object me=this_player();
	int level=(int)me->query("level")+1;
	int exp,repute,gold;
	string gift;
	string cgift;
	if (me->query("combat_exp")<level*level*level*400)
		{
		tell_object(me,HIY"你的经验不够升到下一级，至少需要"+level*level*level*400+"点经验！\n"NOR);	
		return 1;
		}
	if (me->query("repute")<level*20000)
		{
		tell_object(me,HIY"你的声望太低了，至少需要"+level*20000+"点声望！\n"NOR);
		return 1;	
		}
	if (me->query("balance")<level*10*10000)
		{
		tell_object(me,HIY"你的存款不够，至少需要"+level*10+"gold的存款！\n"NOR);
		return 1;	
		}
	exp=level*level*120;
	repute=level*200;
	gold=level*10*10000;
	me->add("combat_exp",-exp);
	me->add("repute",-repute);
	me->add("balance",-gold);
	me->add("level",1);
	tell_object(me,HIY"恭喜你，你升到了"+level+"级！\n"NOR);
	if (random(5)==3)
		{
		gift=gifts[random(sizeof(gifts))];
		me->add(gift,1);
		me->add("xiantian/"+gift+"/level",1);
		if (gift=="str") cgift="膂力";
		if (gift=="int") cgift="悟性";
		if (gift=="con") cgift="根骨";
		if (gift=="dex") cgift="身法";
		if (gift=="per") cgift="容貌";
		if (gift=="kar") cgift="福缘";
		if (gift=="spi") cgift="灵性";
		tell_object(me,HIY"你的先天"+cgift+"增加了！\n"NOR);
	  }
	return 1;
}
