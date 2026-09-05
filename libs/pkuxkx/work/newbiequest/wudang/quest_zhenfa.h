// quest_zhenfa.h 广场阵法演练头文件
// seagate@pkuxkx

#include <ansi.h>
string *zheng_wx=({HIY"金"NOR,HIB"水"NOR,HIG"木"NOR,HIR"火"NOR,YEL"土"NOR});
string *ni_wx=({HIY"金"NOR,HIG"木"NOR,YEL"土"NOR,HIB"水"NOR,HIR"火"NOR});
//如果定义__ZF_ROOM__就认为对象是房间，将房间相关函数载入给对象
//否则认为是npc，将npc相关函数载入给对象
#ifdef __ZF_ROOM__

void init()
{
	add_action("do_zhenfa", "zhenfa");
	add_action("do_zouwei", "zouwei");
}

/*演练阵法的时候随机抽出正五行还是反五行，二轮之后五行反转
  会出现4个道童陪练，主要是体现真实性，还有就是稍微减低难度。
  阵法演练用到属性quest_zhenfa，该属性下有以下几个设定：
  start         --开始，表示可以演练阵法。
  prac_zhenfa   --演练阵法中！这时候你就不能离开本房间了。
  prac_fail     --演练阵法失败
  success       --演练阵法成功
  zhenfa_no     --阵法站位的序号
  zhenfa_name   --演练的阵法名称，目前只有正反五行阵两种
  real_zhanwei  --需要你走到的下一个阵法方位
  fact_zhanwei  --你现在实际的阵法方位
  in_zouwei     --你在一轮演练中是否走过位，走过就不能再走了。
*/
int do_zhenfa()
{
	object *ob;
	int lp,wx,flow;
	
	ob=allocate(5);
	ob[0]=this_player();
	
	if(!ob[0]->query_temp("quest_zhenfa/start"))
		return notify_fail("现在教习太紧张了，演习阵法的教习都在使用中！请到广场上排队吧。\n");
	else if(ob[0]->is_busy()||ob[0]->is_fighting())
		return notify_fail("你现在正忙着呢。\n");
	else if(ob[0]->query_temp("quest_zhenfa/prac_zhenfa"))
		return notify_fail("你正在演习阵法当中！\n");
	else if(ob[0]->query_temp("quest_zhenfa/prac_fail"))
		return notify_fail("刚才的阵法演习中你始终和他人无法配合，先回去总结总结再回来吧。\n");
	else if(ob[0]->query_temp("quest_zhenfa/success"))
		return notify_fail("刚才的阵法演习中你和他人配合的天衣无缝，可以回去找"+ob[0]->query_temp("quest_zhenfa/promoter")+"领赏了。\n");
	
	ob[0]->set_temp("quest_zhenfa/prac_zhenfa",1);
	for(lp=1;lp<=4;lp++) {
		ob[lp]=new("/newbiequest/wudang/npc/daotong");
		ob[lp]->move(this_object());
		ob[lp]->set_temp("quest_zhenfa/prac_zhenfa",1);
	}

//wx代表五行方位，处于五行阵的第几个方位	
	wx=random(5);
//flow代表阵法的方向，五行阵分为正反两个方向，正五行代表五行相生排阵，反五行代表五行相克排阵。
//0--代表正五行 1--代表反五行
	flow=random(2);
	for(lp=0;lp<5;lp++) {
		ob[lp]->set_temp("quest_zhenfa/zhenfa_no",(wx+lp)%5);
	  ob[lp]->set_temp("quest_zhenfa/real_zhanwei", flow?ni_wx[(wx+lp)%5]:zheng_wx[(wx+lp)%5]);
	  if(flow)
	  	ob[lp]->set_temp("quest_zhenfa/zhenfa_name","『"+HIC"反五行阵"NOR+"』");
	  else
	  	ob[lp]->set_temp("quest_zhenfa/zhenfa_name","『"+HIM"正五行阵"NOR+"』");
	}
  
  if(flow) {
	  write("阵法教习从远处跑过说到：今天练『"+HIC"反五行阵"NOR+"』，请大家注意走位(zouwei)！\n");
	  write("『"+HIM+"正五行阵"+NOR+"』按照五行相生进行排阵，金生水，水生木，木生火，火生土，土生金。\n");
	  write("『"+HIC+"反五行阵"+NOR+"』按照五行相克进行排阵，金克木，木克土，土克水，水克火，火克金。\n");
	  write("大家一会儿按照我公布的方位走(zouwei)到自己负责的位置中，然后注意按照『"+HIC"反五行阵"NOR+"』开始走位(zouwei)。\n");
  }
  else {
	  write("阵法教习从远处跑过说到：今天练『"+HIM"正五行阵"NOR+"』，请大家注意走位(zouwei)！\n");
	  write("『"+HIM+"正五行阵"+NOR+"』按照五行相生进行排阵，金生水，水生木，木生火，火生土，土生金。\n");
	  write("『"+HIC+"反五行阵"+NOR+"』按照五行相克进行排阵，金克木，木克土，土克水，水克火，火克金。\n");
	  write("大家一会儿按照我公布的方位走(zouwei)到自己负责的位置中，然后注意按照『"+HIM"正五行阵"NOR+"』开始走位(zouwei)。\n");
  }
	for(lp=0;lp<5;lp++)
	  write(ob[lp]->name()+"一会儿站在"+ob[lp]->query_temp("quest_zhenfa/real_zhanwei")+"位。\n");
	for(lp=1;lp<5;lp++)
	  ob[lp]->start_zouwei();
	remove_call_out("in_zhenfa");
	call_out("in_zhenfa",15,ob,flow,1);
	return 1;
}

void in_zhenfa(object *ob,int flow,int times)
{
	string name;
	int lp,zw;
	
	if(!ob[0]->query_temp("quest_zhenfa/fact_zhanwei")) {
		ob[0]->set_temp("quest_zhenfa/prac_fail",1);
		ob[0]->delete_temp("quest_zhenfa/zhenfa_no");
		ob[0]->delete_temp("quest_zhenfa/real_zhanwei");
		ob[0]->delete_temp("quest_zhenfa/fact_zhanwei");
		ob[0]->delete_temp("quest_zhenfa/prac_zhenfa");
	  ob[0]->delete_temp("quest_zhenfa/in_zouwei");
		for(lp=1;lp<=4;lp++)
		  destruct(ob[lp]);
		write("你站在这里发傻，导致整个阵型全乱套了，气得阵法教习跳起来只骂娘！\n");
		return;
	}
	if(ob[0]->query_temp("quest_zhenfa/fact_zhanwei")!=ob[0]->query_temp("quest_zhenfa/real_zhanwei")) {
		for(lp=1;lp<=4;lp++)
		  if(ob[lp]->query_temp("quest_zhenfa/fact_zhanwei")==ob[0]->query_temp("quest_zhenfa/fact_zhanwei")) {
		  	name=ob[lp]->name();
		  	destruct(ob[lp]);
		  	ob[0]->receive_damage("qi",80, "演习阵法受伤");
		  	ob[0]->receive_wound("qi",20, "演习阵法受伤");
		  	write("你和"+name+"撞到了一起，两个人都受伤了，出去疗疗伤再回来演习阵法吧。\n");
		  }
		  else
		  	destruct(ob[lp]);
		ob[0]->set_temp("quest_zhenfa/prac_fail",1);
		ob[0]->delete_temp("quest_zhenfa/zhenfa_no");
		ob[0]->delete_temp("quest_zhenfa/real_zhanwei");
		ob[0]->delete_temp("quest_zhenfa/fact_zhanwei");
		ob[0]->delete_temp("quest_zhenfa/prac_zhenfa");
	  ob[0]->delete_temp("quest_zhenfa/in_zouwei");
		write("你站错了方位，整个五行阵全都乱套了，大家只好都停下来！\n");
		return;
	}
	if(times==3) {
		if((flow+1)%2) {
			write("阵法教习挥挥了旗子喊道：正反五行变换开始，现在变为『"+HIC"反五行阵"NOR+"』。\n");
			write("大家从自己现在的位置按照『"+HIC"反五行阵"NOR+NOR+"』的要求往下走一步。\n");
		}
		else {
			write("阵法教习挥挥了旗子喊道：正反五行变换开始，现在变为『"+HIM"正五行阵"NOR+"』。\n");
			write("大家从自己现在的位置按照『"+HIM"正五行阵"NOR+"』的要求往下走一步。\n");
	  }	
		for(lp=0;lp<5;lp++) {
			if((flow+1)%2) {
				ob[lp]->set_temp("quest_zhenfa/zhenfa_name","『"+HIC"反五行阵"NOR+"』");
			  zw=member_array(ob[lp]->query_temp("quest_zhenfa/real_zhanwei"),ni_wx);
			}
			else {
				ob[lp]->set_temp("quest_zhenfa/zhenfa_name","『"+HIM"正五行阵"NOR+"』");
				zw=member_array(ob[lp]->query_temp("quest_zhenfa/real_zhanwei"),zheng_wx);
		  }
			zw=(zw+1)%5;
		  ob[lp]->set_temp("quest_zhenfa/zhenfa_no",zw);
	    ob[lp]->set_temp("quest_zhenfa/real_zhanwei", (flow+1)%2?ni_wx[zw]:zheng_wx[zw]);
	    ob[lp]->delete_temp("quest_zhenfa/in_zouwei");
	  }
	  for(lp=1;lp<5;lp++)
	    ob[lp]->start_zouwei();
	  remove_call_out("in_zhenfa");
	  call_out("in_zhenfa",15,ob,(flow+1)%2,times+1);
	  return;
	}
	if(times>4) {
		ob[0]->set_temp("quest_zhenfa/success",1);
		ob[0]->delete_temp("quest_zhenfa/zhenfa_no");
		ob[0]->delete_temp("quest_zhenfa/real_zhanwei");
		ob[0]->delete_temp("quest_zhenfa/fact_zhanwei");
		ob[0]->delete_temp("quest_zhenfa/prac_zhenfa");
	  ob[0]->delete_temp("quest_zhenfa/in_zouwei");
	  for(lp=1;lp<5;lp++)
	    destruct(ob[lp]);
		write("阵法教习挥了挥旗喊道：五行阵演练到此结束，大家走位都非常精确，看来以后有希望演练武当秘传的真武七截阵。\n");
		return;
	}

	if(flow)
		write("阵法教习挥了挥旗喊道：大家从自己现在的位置按照『"+HIC"反五行阵"NOR+"』的要求往下走一步。\n");
	else
		write("阵法教习挥了挥旗喊道：大家从自己现在的位置按照『"+HIM"正五行阵"NOR+"』的要求往下走一步。\n");

	for(lp=0;lp<5;lp++) {
		zw=ob[lp]->query_temp("quest_zhenfa/zhenfa_no");
		zw=(zw+1)%5;
		ob[lp]->set_temp("quest_zhenfa/zhenfa_no",zw);
	  ob[lp]->set_temp("quest_zhenfa/real_zhanwei", flow?ni_wx[zw]:zheng_wx[zw]);
	  ob[lp]->delete_temp("quest_zhenfa/in_zouwei");
	}
	for(lp=1;lp<5;lp++)
	  ob[lp]->start_zouwei();

	remove_call_out("in_zhenfa");
	call_out("in_zhenfa",15,ob,flow,times+1);
	return;
}

int do_zouwei(string arg)
{
	object me;
	string wuxing;
	me=this_player();
	
  if(!me->query_temp("quest_zhenfa/prac_zhenfa"))
  	return notify_fail("你还没有开始阵法演习。\n");
	else if(me->query_temp("quest_zhenfa/in_zouwei"))
		return notify_fail("你已经开始按照五行阵法进行走位了。\n");
	else if(!arg)
		return notify_fail("走位的命令格式是zouwei [金|木|水|火|土]\n");
	else if(arg!="金"&&arg!="木"&&arg!="水"&&arg!="火"&&arg!="土")
		return notify_fail("走位的命令格式是zouwei [金|木|水|火|土]\n");
	
	switch(arg) {
		case "金":
			wuxing=HIY"金"NOR;
			break;
		case "木":
			wuxing=HIG"木"NOR;
			break;
		case "水":
			wuxing=HIB"水"NOR;
			break;
		case "火":
			wuxing=HIR"火"NOR;
			break;
		case "土":
			wuxing=YEL"土"NOR;
			break;
	}
	if(!me->query_temp("quest_zhenfa/fact_zhanwei"))
		write("你按照"+me->query_temp("quest_zhenfa/zhenfa_name")+"的要求开始走向"+wuxing+"位。\n");
	else
		write("你按照"+me->query_temp("quest_zhenfa/zhenfa_name")+"的要求从"+me->query_temp("quest_zhenfa/fact_zhanwei")+"位走向"+wuxing+"位。\n");
	me->set_temp("quest_zhenfa/fact_zhanwei",wuxing);
	me->set_temp("quest_zhenfa/in_zouwei",1);
	return 1;
}

//如果旁边房间有人在演习阵法则不应该走到那个校场打扰对方。
int valid_leave(object me,string dir)
{       
	mapping exits=query("exits");
	object env,item;
  
  if(strsrch(exits[dir],"jiaochang")>=0) {
  	if(!(env=find_object(exits[dir])))
  		env=load_object(exits[dir]);
  	foreach(item in deep_inventory(env))
  		if(userp(item)&&item->query_temp("quest_zhenfa/prac_zhenfa"))
  			return notify_fail("房间中已经有人在演习阵法，请等对方演习结束再进去吧。\n");
  }

  if(me->query_temp("quest_zhenfa/prac_zhenfa"))
  	return notify_fail("你正在演习阵法，请演习完阵法以后再离开！\n");

  return ::valid_leave(me,dir);
}
#else

void start_zouwei()
{
	object me=this_object();
	string wuxing;

  wuxing=me->query_temp("quest_zhenfa/real_zhanwei");
	call_out("delay_zouwei",random(5)+1,wuxing);
}

void delay_zouwei(string wuxing)
{
	object me=this_object();
	if(!me->query_temp("quest_zhenfa/fact_zhanwei"))
		tell_room(environment(), me->name()+"按照"+me->query_temp("quest_zhenfa/zhenfa_name")+"的要求开始走向"+wuxing+"位。\n");
	else
		tell_room(environment(), me->name()+"按照"+me->query_temp("quest_zhenfa/zhenfa_name")+"的要求从"+me->query_temp("quest_zhenfa/fact_zhanwei")+"位走向"+wuxing+"位。\n");

	me->set_temp("quest_zhenfa/fact_zhanwei",wuxing);
}

string start_zhenfa(string name,string questid)
{
	object me;
	
	me=this_player();
	this_object()->newbieStart(name,questid);
	me->set_temp("quest_zhenfa/promoter",this_object()->query("name"));
	me->set_temp("quest_zhenfa/start",1);
	
	this_object()->newbieDesc("到广场旁边的小校场上学习阵法演练（zhenfa）。\n");
	return "武当派以真武七截阵闻名天下，每个拜入武当的入门弟子都需要学习阵法演练（zhenfa），\n我们就从最简单的五行阵开始吧，旁边小校场上有教习教大家怎么行走五行阵。";
}

#endif
