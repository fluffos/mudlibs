//扫荡加上转世奖励
int main(object me, string arg)
{   object ob;
     int exp=60000;
     int pot=80000;
     int mar=10000;
  /*    int zhuanshi=me->query("zhuanshi");
    exp+=exp*(zhuanshi*5)/10;
    pot+=pot*(zhuanshi*5)/10;
    mar+=mar*(zhuanshi*5)/10;
    write(exp+"\n"); */
     if(me->query("shimen/today")<1000) return notify_fail("你的师门次数不足1000，还不能进行扫荡\n");
     
   /*  if(! objectp(ob = present(arg, environment(me))))
			return notify_fail("这里没有这个人，你怎么扫荡师门？\n"); */
	if(me->query("shimen/today")>=20000) return notify_fail("你的师门次数已经满了\n");
	if(!arg) {
	tell_object(me,"你要用那种扫荡类型\n");
	tell_object(me,HIR"高级扫荡: "NOR"100灵石扫荡100次师门获得100%的收益"ZJURL("cmds:sao -gao")ZJSIZE(20)"高级扫荡"NOR+"\n");
	tell_object(me,HIM"中级扫荡: "NOR"100灵石票扫荡100次师门获得70%的收益"ZJURL("cmds:sao -zhong")ZJSIZE(20)"中级扫荡"NOR+"\n");
	tell_object(me,HIW"低级扫荡: "NOR"100黄金扫荡100次师门获得50%的收益 "ZJURL("cmds:sao -di")ZJSIZE(20)"低级扫荡"NOR+"\n");
	}
	if(arg=="-gao"){
    if(me->query("yuanbao")<100){
    return notify_fail("你的灵石不足100\n");
    }
	me->add("shimen/today",100);
	me->add("yuanbao",-100);
	me->add("combat_exp",exp);
	me->add("potential",pot);
	me->add("experience",mar);
	tell_object(me,HIC"你花费100灵石扫荡了100师门获得了\n");
	tell_object(me,HIG+exp+"修为\n");
	tell_object(me,HIG+pot+"潜能\n");
	tell_object(me,HIG+mar+"实战体会\n");
	tell_object(me,ZJURL("cmds:sao -gao")ZJSIZE(20)"继续高级扫荡"NOR+"\n");

	}
	if(arg=="-zhong"){
	if(me->query("yuanbao_2")<100){
    return notify_fail("你的灵石票不足100\n");
    }
    //只有70%的收益
    write(exp+"\n");
    exp=exp*7/10;
    pot=pot*7/10;
    mar=mar*7/10;
    write("exp:"+exp+"\n");
	me->add("shimen/today",100);
	me->add("yuanbao_2",-100);
	me->add("combat_exp",exp);
	me->add("potential",pot);
	me->add("experience",mar);
	tell_object(me,HIC"你花费100灵石票扫荡了100师门获得了\n");
	tell_object(me,HIG+exp+"修为\n");
	tell_object(me,HIG+pot+"潜能\n");
	tell_object(me,HIG+mar+"实战体会\n");
	tell_object(me,ZJURL("cmds:sao -zhong")ZJSIZE(20)"继续中级扫荡"NOR+"\n");
	}
	if(arg=="-di"){
	if(me->query("balance")<1000000){
    return notify_fail("你钱庄的钱不足100黄金\n");
    }
    write(exp+"\n");
    exp=exp*5/10;
    pot=pot*5/10;
    mar=mar*5/10;
    write("exp:"+exp+"\n");
	me->add("shimen/today",100);
	me->add("balance",-1000000);
	me->add("combat_exp",exp);
	me->add("potential",pot);
	me->add("experience",mar);
	tell_object(me,HIC"你花费100黄金扫荡了100师门获得了\n");
	tell_object(me,HIG+exp+"修为\n");
	tell_object(me,HIG+pot+"潜能\n");
	tell_object(me,HIG+mar+"实战体会\n");
	tell_object(me,ZJURL("cmds:sao -di")ZJSIZE(20)"继续低级扫荡"NOR+"\n");
	 }
	   /**   
	   if(me->query("shimen/today")>1000){
	  me->add("shimen/today",100);
	  if(me->query("shimen/today")>=4000) me->set("shimen/today",4000);
	  
	  me->add("combet_exp",3000);
	  me->add("potential",4000);
	  me->add("gongxian",25);
	  tell_object(me,CYN+ob->name()+"告诉你，你花费了100次师门次数扫荡获得了了3000修为4000潜能25的师门贡献\n"NOR);
	  return 1;
	 }else{
	 tell_object(me,CYN+ob->name()+"告诉你: 你的师门次数不足1000无法进行扫荡\n"NOR);
	 return 1;
	 }/**/
	 }