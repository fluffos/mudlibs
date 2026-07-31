// ping.c 平一指
#include <ansi.h>;
inherit NPC;
int ask_me();
int ask_over();
int ask_working();
string ask_me1();
string ask_renshen();
string ask_flower();

#include <ansi.h>
void create()
{
    set_name("平一指", ({ "ping yizhi", "ping", "yizhi" }));
    set("title", "药铺老板");
    set("gender", "男性");
    set("long", "他就是医术高超的「杀人神医」平一指。可是他性格古怪，不是什么人都医的。\n");
    set("age", 65);
    set("int", 30);
    
    set("qi", 200000);
    set("max_qi", 200000);
    set("jing", 200000);
    set("max_jing", 200000);
    set("shen_type", 0);
    set("combat_exp", 500000);
    set("attitude", "heroism");
    set_skill("unarmed", 80);
    set_skill("dodge", 80);
    set_skill("parry", 60);
    set_temp("apply/attack", 70);
    set_temp("apply/defense", 70);
    set_temp("apply/damage", 50);
        set("inquiry", ([
    "治病":(:ask_me:),
    "神药": (: ask_me1 :),
    "人参": (: ask_renshen :),
   "幽昙仙花": (: ask_flower :),
     "潜能丹": (: ask_me1 :),
    "work" : (: ask_working :),
     "报酬" : (: ask_over :),
     "工资" : (: ask_over :),   
        ]) );
    setup();
    add_money("gold", 1);
    carry_object("/clone/misc/changpao")->wear();
}

void init()
{	
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting()&&!ob->query_temp("fengyaoover") ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	int eff_qi,max_qi,hurt;
	if( !ob || environment(ob) != environment() ) return;
	eff_qi = ob->query("eff_qi");
	max_qi = ob->query("max_qi");
	if(100*eff_qi/max_qi<=50) hurt = 3;
	else if(100*eff_qi/max_qi<=70) hurt = 2;
	else if(100*eff_qi/max_qi<=95) hurt = 1;
	else hurt = 0;
	switch(hurt)
	{
		case 1 : message_vision("平一指满脸关切地对$N说道：这位" + RANK_D->query_respect(ob)
				+ "看来受了点轻伤，我这由上好的丹药，不知是否要买些？\n",ob);
			 break;
		case 2 : message_vision("平一指对$N说道：这位" + RANK_D->query_respect(ob)+"看来受伤不轻，买些丹药回去吧！\n",ob);
		         break;
		case 3 : message_vision("平一指冷冷地对$N说道：这位" + RANK_D->query_respect(ob)+"伤重垂危，命不久矣，嘿嘿！\n",ob);
		         break;
		default : command("look "+ob->query("id"));
		         break;
        }
      if(!ob->query_temp("fengyaobegin"))
           say( "平一指冷冷地说道：小店正缺人手，这位" + RANK_D->query_respect(ob)
				+ "有意的话，可以"CYN" 〖"HIR"ask ping about work"NOR CYN"〗\n"NOR);
}
string value_string(int value)
{
    if( value < 1 ) value = 1;
    else    if( value < 100 )
        return chinese_number(value) + "文钱";
    else    if( value < 10000 )
        return chinese_number(value/100) + "两白银"
            + (value%100? "又" + chinese_number(value%100) + "文钱": "");
    else
        return chinese_number(value/10000) + "两黄金"
            +( (value%10000)/100 ? chinese_number((value%10000)/100) + "两白银" : "")
            +( (value%10000)%100 ? "又" + chinese_number((value%10000)%100) + "文钱": "");
}
int ask_me()
{
        object ob;
    mapping inv;
    string str,*cond;
    int i;
        ob=this_player(); 
    inv=ob->query_conditions();
       if (((int)this_player()->query("eff_qi") == (int)this_player()->query("max_qi"))
         && ((int)this_player()->query("eff_jing") == (int)this_player()->query("max_jing"))
    && !sizeof(inv)){
                command("say 我给你打量几眼,呃,你现在不需要治病!");
        return 1;
    }
        tell_object(ob, "\n平一指抬头看了你几眼。\n");
    str="";
    if (sizeof(inv)){
        cond=keys(inv);
        for (i=0;i<sizeof(inv);i++){
            if (cond[i]=="drunk")
            str+="看你脸红红的，一定是喝醉了！";
            if (cond[i]=="killer"){
                command("say 官府正通缉你呢，你还是快走吧！");
                return 1;
            }
    }
    ob->set_temp("count",sizeof(inv)*10);
    }
        if ( (int)this_player()->query("eff_qi") < (int)this_player()->query("max_qi") )
        {
             ob->add_temp("count",5); 
             str+="呃,你真气受了点损伤! \n";
         }
    if ( (int)this_player()->query("eff_jing") < (int)this_player()->query("max_jing") )
        {
                 ob->add_temp("count",5);
                 str+="呃,你精元受了点损伤! \n";
        }            
        str+="有"+value_string(1000* ob->query_temp("count"))+"吗？先给钱，后治病！ \n";
        command("say "+str);
                return 1;
}
int ask_over()
{
 object me,mon;
 int bonus,exp,pot,tempp,kar;
 me = this_player();
 kar = me->query("kar");
  if (!me->query_temp("fengyaoover")) {
//    message_vision("平一指惊讶的对$N说道：“哦！ 你再开什么玩笑，我这不是养老院。”\n",me);
   tell_object(me,"平一指惊讶的对你说道：“哦！ 你再开什么玩笑，我这不是养老院。”\n");

    return 1;
    }
    me->delete_temp("fengyaoover");
  if (me->query_temp("fengyaow")) {
  	if(random(kar)>=4)
  	
 {
//    message_vision("平一指哼了一声，对$N说：“你是怎么搞的，乱分药，是想砸我的招牌吗？\n           看在你还努力的份上还是赏你点钱吧。”\n",me);
   tell_object(me,"平一指哼了一声，对你说：“你是怎么搞的，乱分药，是想砸我的招牌吗？\n           看在你还努力的份上还是赏你点钱吧。”\n");

     exp = 1000 + random(500);
     pot = 300 + random(100);
    me->add("combat_exp", exp);
    me->add("potential", pot);
   tell_object(me,"你被奖励了："HIR + chinese_number(exp) + NOR"点经验，"HIR+ chinese_number(pot) + NOR"点潜能。 \n");
    me->delete_temp("fengyaow");
    return 1;
 }
 	   
//        message_vision(" 平一指哼了一声，对$N说：你是怎么搞的，乱分药，是想砸我的招牌吗？\n",me);
   tell_object(me," 平一指哼了一声，对你说：你是怎么搞的，乱分药，是想砸我的招牌吗？\n");

        return 1;

    }
//   message_vision("平一指笑着对$N说：“小兄弟还不错嘛，可以可以，这是你应该得的。”\n",me);
   tell_object(me,"平一指笑着对你说：“小兄弟还不错嘛，可以可以，这是你应该得的。”\n");

     exp = 1600 + random(1000);
     pot = 450 + random(150);
/*
    bonus = (int) me->query("combat_exp");
    tempp = bonus;
    bonus += exp;
*/
    me->add("combat_exp", exp);
/*
    bonus = (int) me->query("potential");
    bonus += pot;
   mon = new("/clone/money/silver");
    mon->set_amount(exp/5);
  mon->move(me);
*/
    me->add("potential", pot);
    me->add("money", 100);

   tell_object(me,"你被奖励了："HIR + chinese_number(exp) + NOR"点经验，"HIR+ chinese_number(pot) + NOR"点潜能和1两白银。 \n");
    bonus=(int) me->query("potential");
    return 1;
}
int ask_working()
{
   object me;
   me = this_player();
     if((int)(me->query("combat_exp")) > 80000000)
      { message_vision("平一指对$N说道：“阁下一代高手，战斗经验大于八千万,小店劳烦不起。呵。。。呵。。。”\n",me);
        return 1;
     }
   if((int)(me->query("zjb_dj/dj")) > 5)
      { message_vision("平一指对$N说道：“阁下等级这么高，小店劳烦不起。呵。。。呵。。。”\n",me);
        return 1;
     }
   if (me->query_temp("fengyaobegin"))
      { message_vision("平一指对$N说道：“你不是已经要了工作了，还不去干！”\n",me);
        return 1;
     }
    if ((int)(me->query("qi")) < 50)        
         { message_vision("平一指对$N说道：“算了吧你，都这样了还想工作，把药分错了会出人命的。”\n",me);
        return 1;
     }
   if (me->query_temp("fengyaoover"))
       { message_vision("平一指对$N说道：“哦？ 你连自己的工资也不要。”\n",me);
         message_vision("平一指对$N说道：“好吧，既然这样我也就不勉强你了。”\n",me);
         message_vision("平一指对$N说道：“那你就到内室去帮我再分次药吧。”\n",me);
         me->delete_temp("fengyaow");
         me->delete_temp("fengyaoover");
         me->set_temp("fengyaobegin",1);
         return 1;
     }
   
   message_vision("平一指对$N说道：“好吧，那你就到内室去帮我分分药吧。”\n",me);
   me->set_temp("fengyaobegin",1);
   return 1;
}
int accept_object(object who, object ob)
{
    if (who->query_temp("count"))
        if (ob->query("money_id") && ob->value() >= who->query_temp("count")*1000){ 
                who->set("eff_qi",who->query("max_qi"));
                who->set("eff_jing",who->query("max_jing"));
                who->set("eff_gin",who->query("max_gin"));
                who->apply_condition("drunk",0);
                tell_object(who, "平一指拿出些药丸给你服下，不一会，你的气色看起来好多了。\n");
            who->set_temp("count",0);
            destruct(ob);
                return 1;
            }  else
                tell_object(who, "平一指冷冷一笑：你的诚意不够，还是请回吧！\n");
            destruct(ob);
    return 1;
}
string ask_me1()
{
    return "我...我不知道！";
}
string ask_renshen()
{
        object ob;
         if (this_player()->query("zjb_money") < 5) 
return "得了吧,就你钱庄那点钱,也想买这么贵的东西！";
     ob = new("/u/zjb/obj/renshen");     
     ob->move(this_player()); ;
     this_player()->add("zjb_money",-5);
return "这东西可贵的很需要五枚星空币,我已经在钱庄帮您把钱转过来了";
}

string ask_flower()
{
        object ob;
            if (this_player()->query("zjb_money") < 300)
return "得了吧,就你钱庄那点钱,也想买这么贵的东西！";

     ob = new("/d/gaochang/obj/youtan");   
     ob->move(this_player()); ;
     this_player()->add("zjb_money",-300);
return "这东西可贵的很需要三百枚星空币,我已经在钱庄帮您把钱转过来了";
}
