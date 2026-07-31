
int main(object me, string arg)
{
   string HUFA_FILE = "/d/biwu/hufa.c";
   object hufa;
   int i;

object *enemy;
   seteuid(getuid());
        
	if(!present("mostaff",me) && !present("shenstaff",me))
		return notify_fail("只能通过神杖或魔杖才能召唤护法。\n");
		if( environment(me)->query("no_fight") )
		return notify_fail("这里没有人打斗！\n");
   //last 0 means do not show position.

   if( (int)me-> query_temp("number") > 1 )
     return notify_fail("你只能召唤两位护法!\n");
   if (me->query("jing")<100) 
	return notify_fail("你精不够!!\n");
   if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("你刚招过护法!!\n");


   me->save();


   message_vision("只听$N大喝一声：左右护法何在！！！！\n", me);
   hufa = new(HUFA_FILE);
   hufa->move(environment(me));
   	 hufa->set_name(me->query("name")+"的左护法",({"dizi"}));
   hufa->set("combat_exp",me->query("combat_exp")/2);
   hufa->set("possessed", me);
   hufa->show(me);

   hufa = new(HUFA_FILE);
   hufa->move(environment(me));
	 hufa->set_name(me->query("name")+"的右护法",({"dizi"}));
   hufa->set("combat_exp",me->query("combat_exp")/2);
   hufa->set("possessed", me);

   hufa->show(me);
    me->add_temp("number", 2);


    me->apply_condition("zdizi_busy",6);
    me->add("jing",-100); 
	   	if(me->is_fighting()) {
  enemy = me->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			hufa->kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(hufa);
			else enemy[i]->kill_ob(hufa);
		}
	}
//me->remove_all_killer();
	}
      return 1;
}
 


int help(object me)
{
    write(@HELP
指令格式: alert 
 
身为武林正邪两派的盟主，可以用召唤两名护法来保护自己。
可用whisper对自己的护法下命令。例如，如果你的护法叫aaa-zuo，用
whisper aaa-zuo kill xiao er即可命令他杀店小二。

HELP
    );
   return 1;
}
 
