// zhu.c this_object()->query("name")
// CLEANSWORD 1996/2/2

inherit NPC;
inherit F_DEALER;
inherit F_MAILQUEST;

#include <ansi.h>
#define	BOOKNUM		      4
#define SHELFNUM        8
#define RETRY           9

int ask_question();
int ask_rule();
int do_guess(string arg);
int do_listq(string arg);
string RandomDigtal();
int ask_job();
int ask_code();
int ask_gift();
int ask_done();
int re_name();
void create()
{
	set_name("朱熹", ({ "zhu xi", "zhu", "xi"}));
	set("long", "朱先生被称为当世第一大文学家，肚子里的墨水比海还要深。\n");
	set("gender", "男性");
  set("title", HIY"大文豪"NOR);
	set("age", 65);
  set("start_room","/d/nanchang/shuyuan2");
	set_skill("literate", 300);
        set_skill("music", 30);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 400000);
	set("shen_type", 1);
  set("vendor_goods",({
        __DIR__"obj/shu2",
        "/d/city/obj/baodian",
        }));
	set("inquiry", ([
		"题" : (: ask_question :),
		"question" : (: ask_question :),
		"规则" : (: ask_rule :),
    "rank" : "输入apply就可以知道具体的改发了。",
		"rule" : (: ask_rule :),
    /*"工号" : (: ask_code :),
    "口令" : (: ask_code :),*/
/*
    "礼物" : (: ask_gift :),
    "gift" : (: ask_gift :),
*/
	       ]) );
	setup();

	set("chat_chance", 3);
	set("chat_msg", ({
		this_object()->query("name")+"说道：普天之下，莫非王土；率土之滨，莫非王臣。\n",
		this_object()->query("name")+"说道：出家人，小过损益焉；无妄大过，未济咸困之。\n",
		this_object()->query("name")+"说道：大学之道，在明明德。在亲民，在止于至善。 \n",
		this_object()->query("name")+"说道：格物致知，诚意正心，修身齐家，治国平天下。\n",
	}) );
		carry_object("/d/riyuejiao/npc/obj/shuaiyitie");
        carry_object("/clone/misc/cloth")->wear();
        call_out("re_name",0);
}

int re_name()
{
    if (time()<1325341251)
    {
        set_name("夫子", ({ "fu zi", "fuzi", "zi"}));
        delete("inquiry");
        delete("vendor_goods");
        delete("title");
        set("chat_chance",0);
    }
}

void init()
{
	  ::init();
      if (time()<1325341251)
      {
          return;
      }
    add_action("do_list","list");
    add_action("do_buy","buy");
    add_action("do_apply", "apply");
    add_action("do_confirm","confirm");
    add_action("do_guess", ({"guess", "cai"}));
    add_action("do_listq", ({"listq", "lie"}));
    add_action("do_report", "report"); //报告工号
    this_player()->delete_temp("new_rank");    
}


int recognize_apprentice(object ob)
{
     return 1;
}

int accept_object(object who, object ob)
{
        if (ob->query("money_id") && ob->value() >= 1000) 
        {
           message_vision(this_object()->query("name")+"道：“无欢说了，现在推行免费义务教育，免收一切学费”。\n", who);        
        }       
        return 0;
}
int do_apply(string arg)
{
  string type,rank;   
  object me=this_player();
  string msg="你准备将";
  int afford;

   if (!arg) return notify_fail(@LONG
格式： apply <类别> to <称谓>
类别／价格／经验要求：
rude        对自己的粗鲁称呼  五百两黄金   10000000
respect     别人对自己的尊称  五百两黄金   50000000

又：请勿使用不恰当的称谓。不然称呼被取消，五百两
金子就白白扔了。至于恰当与否，则由巫师决定。
友情提醒：不可使用颜色代码。
LONG);
  if (sscanf(arg,"%s to %s",type,rank)!=2)   return notify_fail(@LONG
格式： apply <类别> to <称谓>
类别／价格：
rude          对自己的粗鲁称呼     五百两黄金
respect       别人对自己的尊称     五百两黄金

又：请勿使用不恰当的称谓。不然称呼被取消，五十两
金子就白白扔了。至于恰当与否，则由巫师决定。
友情提醒：不可使用颜色代码。
LONG);
  
  if (type!="respect" && type!="rude")
    return notify_fail("不能设置这种类型的称呼。\n");

  if (type!="respect" && me->query("combat_exp")<1000000) 
    return notify_fail("你经验那么低，本来就没人听说过你，不改也罢。\n");
  if ( type=="respect"&& me->query("combat_exp")<5000000)
    return notify_fail("你本领还不够，别人不会听你这样叫的。\n");

  if( !(afford=me->can_afford(5000000)) )  {
     write("你带的钱不够。\n");
     return 1; 
  } else if( afford == 2 )  {
      write("现金交易，不收银票。你带的现金不够。\n");
      return 1;
  }

        if(strwidth(rank) > 20)
        {
                tell_object(me,"名字也太长了，不可以接受！\n"); 
                return 1;
       }
  switch (type) {
    case "rude"    : msg+="对自己的粗鲁称呼从现在的“"+RANK_D->query_rude(me);break;
    case "respect" :  msg+="别人对自己的尊称从现在的“"+RANK_D->query_respect(me);break;
  }
  msg+="”改成“"+rank+"”，是这样吗？(confirm)\n";
  write(msg);
  me->set_temp("new_rank/type",type);
  me->set_temp("new_rank/ready",1);
  me->set_temp("new_rank/rank",rank);
  return 1;
}

int do_confirm() {
  object me=this_player();
  int afford;

  if (!me->query_temp("new_rank/ready"))
     return notify_fail("你要确认什么？\n");

  if( !(afford=me->can_afford(5000000)) )  {
       write("你带的钱不够。\n");
       return 1; 
  } else if( afford == 2 )  {
      write("现金交易，不收银票。你带的现金不够。\n");
      return 1;
  }

  message_vision("$N拿出五百两金子，交给了$n。\n",me,this_object());
  message_vision("$N点了点头，拿出一份卷宗写了几笔。\n",this_object());
  me->pay_money(5000000);
  if (me->query_temp("new_rank/rank")=="cancel")
     me->delete("rank_info/"+me->query_temp("new_rank/type"));
  else 
     me->set("rank_info/"+me->query_temp("new_rank/type"),me->query_temp("new_rank/rank"));
  write("改动完毕。\n");
 log_file("change_rank",me->query("id")+" changes "+me->query_temp("new_rank/type")+" to "
      +me->query_temp("new_rank/rank")+" on "+ctime(time())+".\n");
 
 me->delete_temp("new_rank");
  return 1;
}
int ask_question()
{
	object me = this_player();
	int i, j, temp;
	string tempstr, result = "";

    
    string ip;
    object* allob;
    int sameip = 0;


        if(query("startroom") != file_name(environment()))
        {
                command("say 我现在在外面，等我回书院再说吧。\n");
                return 1;
        }
        if (time() - me->query("last_question_time")< 45 )
        {
            tell_object(me,this_object()->query("name")+"对你摇了摇头，说：猜谜太伤脑筋，你先休息一下吧。\n");
			if(time() - me->query("last_question_time") < 5)
			{
				if(query("startroom") == file_name(environment()))
				{
					me->move("/d/city/dongdajie1");
		            tell_object(me,this_object()->query("name")+"对你说道：过犹不及，你先出去。\n");
				}
			}
            return 1; 
        }

    ip = query_ip_number(me);
    allob = all_inventory(environment());
    //如果有3个同ip的玩家来问题，就kick到东大街去   
    for(i=0;i<sizeof(allob);i++)
    {
        if(objectp(allob[i]) && userp(allob[i]) && allob[i] != me)
        {
            if(stringp(ip) && stringp(query_ip_number(allob[i])) &&  strcmp(query_ip_number(allob[i]),ip) == 0 && allob[i]->query_temp("qipu_guess"))
            {
                sameip++;
            }
        }
    }
    if(sameip >= 2)
    {
        tell_object(me,this_object()->query("name")+"对你大吼：欺人太甚！汝以夫子何人也？贪婪若斯！\n");
        if(query("startroom") == file_name(environment()))
        {
            me->move("/d/city/dongdajie1");
            tell_object(me,"你被"+this_object()->query("name")+"赶了出来。\n");            
        }
        return 1;
    }
      if (me->query_temp("qipu_guess_win"))
		write(this_object()->query("name")+"笑道：“还想再解一次？好吧，等我准备好就来猜吧。”\n");
	else
	        write(this_object()->query("name")+"匆匆走进书房，不一会又出来了。\n");
		write(this_object()->query("name")+"道：“题目是这样的："+HIC"我有一套" + CHINESE_D->chinese_number(BOOKNUM) + "册《梅花谱》，而书房里有\n");
		write(CHINESE_D->chinese_number(SHELFNUM) + "个书架，现在我把这" + CHINESE_D->chinese_number(BOOKNUM) + "册书分别放到不同的书架上去，你只需猜出\n");
		write("来每册书放在那个书架上即可。”\n"NOR);
		write(this_object()->query("name")+"点点头道：“好了，来"+HIC"猜(guess)"+NOR"吧，也可以先问我"+HIC"规则(rule)"+NOR"。”\n");
	for (i = 0; i < BOOKNUM; i++) {
		temp = random(SHELFNUM) + 1;
		tempstr = "" + temp;
		for (j = 0; j < i; j++) {
			if (tempstr == result[j..j]) {
				temp = random(SHELFNUM) + 1;
				tempstr = "" + temp;
				j = -1;
			}
		}
		result += tempstr;
	}
	me->delete_temp("qipu_guess");
	me->set_temp("qipu_guess/result", result);
  me->set("last_question_time",time());
	return 1;
}

int ask_rule()
{
	write(this_object()->query("name")+"道：“规则很简单，你每次用guess来猜你认为的结果。”\n");
	write(this_object()->query("name")+"道：“例如，你认为第一册在２号架上，二册在１号，三册在７号，四册在５号，那就guess 2175。”\n");
	write(this_object()->query("name")+"道：“我会告诉你全对（指猜对了哪个书架放了哪册的）和书架对（指只猜对哪个书架放书而没有猜对放的是哪册的）的个数。”\n");
	write(this_object()->query("name")+"道：“上面的例子里，如果我放的顺序是一册在１号架上，二册在５号，三册在７号，四册在４号，那么答案应该是1574。”\n");
	write(this_object()->query("name")+"道：“你猜对７号架上是三册，表示你有一个全对，另外你猜对１号和５号架上有书，但是没猜对是哪册，表示你有二个书架对。”\n");
	write(this_object()->query("name")+"道：“明白了吧？可以了就开始猜(guess)吧。”\n");
	write(this_object()->query("name")+"道：“记住你有" + CHINESE_D->chinese_number(RETRY) + "次机会。如果你忘了你以前猜的结果，随时可以用listq来查看的。”\n");
	return 1;
}

string justify_result(string result, string guess)
{
	int i, j, temp, very_right = 0, right = 0;

	for (i = 0; i < BOOKNUM; i++) {
		for (j = 0; j < BOOKNUM; j++) {
			if (guess[i..i] == result[j..j]) {
				if (i == j) very_right++;
				else right++;
			}
		}
	}
	return "全对的有" + CHINESE_D->chinese_number(very_right) + "个，只有书架对的有" + CHINESE_D->chinese_number(right) + "个。\n";
}

int do_guess(string arg)
{
	object me = this_player();
	int i, j, times,pot,lite;
	string result, tempstr1, tempstr2;

	if (!(result = me->query_temp("qipu_guess/result"))) return 0;
	if (!arg) return notify_fail("你要猜什么样的结果？\n");
	if (strwidth(arg) != BOOKNUM) return notify_fail("不是告诉你只有" + CHINESE_D->chinese_number(BOOKNUM) + "册书吗？\n");
	for (i = 1; i < BOOKNUM; i++)
		for (j = 0; j < i; j++)
			if (arg[i..i] == arg[j..j])
				return notify_fail("不是告诉你每册书都放在不同的书架上了吗？！\n");
	me->add_temp("qipu_guess/times", 1);
	times = me->query_temp("qipu_guess/times");
	if (arg == result) {
		if (times < 5) {
			tempstr1 = HIC+this_object()->query("name")+"看着你，惊讶地道：“佩服！你只用了";
			tempstr2 = "就";
		}
		else if (times < RETRY) {
			tempstr1 = HIC+this_object()->query("name")+"点头道：“不错，你只用了";
			tempstr2 = "就";
		}
		else {
			tempstr1 = HIC+this_object()->query("name")+"道：“你很侥幸呀，用完了";
			tempstr2 = "才";
		}
		write(tempstr1 + CHINESE_D->chinese_number(times) + "次机会" + tempstr2 + "猜出来了。”\n"NOR);
		me->delete_temp("qipu_guess");
		me->set_temp("qipu_guess_win", 1);
// alading		pot = (RETRY - times+1)*me->query_kar()*3+random((RETRY - times+1)*me->query_kar()*3);    
		pot = (RETRY - times+1)*me->query_kar()/3+random((RETRY - times+1)*me->query_kar()/3);   
                lite = 10+random(6);
                if(pot>0)
                { 
                    if (times==1)//一次答对的奖励5倍，1/10^4的概率。by Zine
                    {
                        pot=pot*5;
                    }
                 write(HIC+this_object()->query("name")+"对你竖起了大拇指，道：“你真行。”\n"NOR);
                  write(HIC+"你得到了"+ CHINESE_D->chinese_number(pot) + "点潜能。\n"NOR);
                  write(HIC+"你的读书识字进步了 \n"NOR);
                  me->add("potential",pot);
                  me->improve_skill("literate",lite);
         
                 }
                  me->set_temp("last_question_time",time());
	}
	else {
		write(this_object()->query("name")+"道：“你猜的是" + arg + "，" + justify_result(result, arg));
		if (times < RETRY) {
			write(this_object()->query("name")+"道：“你还有" + CHINESE_D->chinese_number(RETRY - times) + "次机会！”\n");
			me->set_temp("qipu_guess/guess" + times, arg);
		}
		else {
			write(this_object()->query("name")+"生气地说：“你可真笨！" + CHINESE_D->chinese_number(RETRY) + "次机会都没猜中！答案应该是" + result + "。”\n");
			write(this_object()->query("name")+"道：“下次再猜吧！”\n");
			me->delete_temp("qipu_guess");
                        me->set_temp("last_question_time",time());
		}
	}
	return 1;
}

int do_listq(string arg)
{
	object me = this_player();
	int i, times;
	string result;

	if (!(result = me->query_temp("qipu_guess/result"))) return 0;
	times = me->query_temp("qipu_guess/times");
	write(this_object()->query("name")+"道：“你以前猜的结果如下：”\n");
	for (i = 1; i <= times; i++) {
		write("第" + CHINESE_D->chinese_number(i) + "次：猜" + me->query_temp("qipu_guess/guess" + i) + "，" + justify_result(result, me->query_temp("qipu_guess/guess" + i)));
	}
	return 1;
}

string RandomDigtal()
{
   string *ABC=({"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"});
   string *DIG=({"0","1","2","3","4","5","6","7","8","9"});
   string MyCode;
   MyCode =  ABC[random(sizeof(ABC))]+ABC[random(sizeof(ABC))];
   MyCode += DIG[random(sizeof(DIG))]+DIG[random(sizeof(DIG))]+DIG[random(sizeof(DIG))];
   return MyCode;
}

