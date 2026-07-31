// NPC: /d/ruzhou/npc/xi-laifu.c  办喜宴出现的喜来福老板
// llm 99/07/09

#include <ansi.h>

inherit NPC;
int ask_party();
void start_party(object ob,object me);
int do_start();
int do_serve();
void finish_party(object me,object ob);
int give_money(object me,object ob);
int do_kill(string arg);
int do_exert(string arg);
int do_steal(string arg);

void create()
{
	set_name("喜来福",({"xi laifu","xi","laifu" }));
   set("title", "迎宾楼老板");
   set("age", 42);
   set("gender", "男性");
   set("attitude", "friendly");
   set("combat_exp", 50000);
   set_skill("unarmed", 100);
   set_skill("dodge", 100);
   set_skill("parry", 100);
   set("per", 20);

	set("inquiry", ([
		"name": "喜来福呵呵笑道：“小可名字有点福气，姓喜名来福，就是这里的老板。\n",
		"here": "喜来福摇头晃脑地说：“我们迎宾楼可是方圆几十里的名楼，办喜宴还得要来我们这里。”\n",
		"宴" : (: ask_party :),
		"喜宴" : (: ask_party :),
		"席" : (: ask_party :),
		"酒席" : (: ask_party :),
		"喜酒" : (: ask_party :),
		"酒宴" : (: ask_party :),
		"party" : (: ask_party :),
		]) );
   setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
   object me=this_player();
   ::init();
	if( interactive(me) && !is_fighting() )
   {
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
   add_action("do_serve", "kaixi");
   add_action("do_finish", "jieshu");
   add_action("do_start", "kaishi");
   add_action("do_kill", ({"kill","fight","hit","perform"}));
   add_action("do_steal", "steal");
   add_action("do_exert", "exert");
}

int greeting(object me)
{

   if( !me || environment(me) != environment() ) return 0;

   if(me->query_temp("married_party") )//新人
   {
   	write("喜老板对你拱手道：“喜宴布置得差不多了，等客人来齐了您问我喜宴就行了！”\n");
   }
   else if(!query_temp("party_finish"))//喜宴未结束，吃喜酒的人
   {
      write("喜老板点点头：“哟！您来吃喜酒呀！新人的礼金由我代收，交给我就行。”\n");
   }
	else
   {
   	write("喜老板一拱手：“您吃好，慢走！”\n");
   }
   return 1;
}

int accept_object(object me, object ob)
{
   int i;
	if(query_temp("party_finish"))
   	return notify_fail("喜老板呵呵一笑：“您来迟了，喜宴已经结束了，您还是直接给新人吧！”\n");
   if (!ob->query("money_id"))
     	return notify_fail("喜老板皱了皱眉头：“如今早就不时兴送东西了，喝喜酒还是给现金的好！”\n");
   if(me->query_temp("marry_patty"))
   	return notify_fail("喜老板一愣，又笑道：“自己给自己送礼？也没有这样吃饱了撑着的事吧！”\n");
   i = ob->value();
   CHANNEL_D->do_channel(this_object(), "chat",
	   sprintf("%s恭贺%s和%s新婚大喜，送上贺礼"+MONEY_D->price_str(i)+"！\n",me->name(),query("name1"),query("name2")));
	add("chat_amount",1);//口水永远不干
	add("money",i);//记录送来的礼金数
   return 1;
}

int ask_party()
{
   object me,ob,wife;
   ob=this_object();
   me=this_player();
   if( me->query_temp("host_of_party") )
   {
   	message_vision("$N对$n说：“您的喜宴不是正在开着吗？”\n", ob, me);
   	return 1;
   }
   if( (string)me->query("gender")=="女性" )
   {
     message_vision("$N笑着对$n说道：“媒婆是以新郎的名义在这订酒席，还是叫你的丈夫来问吧！”\n", ob,me);
     return 1;
   }
	if( !me->query_temp("married_party") )
   {
   	message_vision("$N翻了翻帐本，对$n迟疑的问道：“媒婆好象没有在我这里给您订喜筵，会不会搞错了？”\n", ob,me);
   	return 1;
   }
   if( !objectp(wife=present(me->query("couple/couple_id"), environment(me))) )
   {
   	message_vision("$N对$n说：新娘子都没来，这喜宴怎么开？\n", ob,me);
      return 1;
   }
   if( ob->query_temp("ready_to_party") )
   {
   	message_vision("$N对$n不好意思的说：我这正开着一席呢，要不您明儿再来吧！\n",ob,me);
   	return 1;
   }
   if( (string)environment(ob)->query("short")!="喜福堂" )
   {
   	message_vision("$N对$n为难的说：“对不起，等我回店准备了再说吧！”\n",ob,me);
   	return 1;
   }
   if( me->query_temp("ready_to_ask") )
   {
   	message_vision("$N对$n不耐烦的说道：“不是都说了吗？你怎么问个没完！”\n",ob,me);
   	return 1;
   }
   me->set_temp("ready_to_ask",1);//新郎问过了的记号
   ob->set_temp("ready_to_party",1);//老板开始记号
   me->set_temp("host_of_party",1);//新郎的记号
   me->delete_temp("married_party");
   call_out("start_party",1,ob,me);
}

void start_party(object ob,object me)
{
   command("chat* "+name()+"一拱手道：“良宵一刻值千金，酒不醉人人自醉，今日迎宾楼荣幸地为" + me->query("name") +
		"\n大开喜宴，恭迎各位前来捧场！\n\n");
   message_vision("喜老板转身又对$N小声问了几句。\n",me);
   message_vision("您要开始，就输入 kaishi，如果想开席，就输入 kaixi，\n"
   "大家吃饱了，喝足了就可以结束了(jieshu)。");
   me->delete_temp("ready_to_ask");
   me->set_temp("ready_to_party", 1);//新郎准备开始记号
}

int do_start()
{
   object me,ob,usr,obj,*list;
   int i;
   me = this_player();
	ob = this_object();

   if( !me->query_temp("host_of_party") )
     return notify_fail(name()+"对你说：“你又不是新郎官！喊什么喊？”\n");
   if( !ob->query_temp("ready_to_party") )
     return notify_fail(name()+"对你说：“开始什么呀，现在又没人办婚宴！”\n");
   if( me->query_temp("party_start_already") )
     return notify_fail(name()+"笑呵呵地对你说：“你看这不是已经开始了嘛！”\n");

   message_vision("$N对$n点点头说：“喜老板，喜宴可以开始了！”\n\n"
		"$n立刻大声喊着：“给客人上～～喜～～酒～～”\n\n",me,ob);
   me->set_temp("party_start_already", 1);//新郎已经开始记号
   me->delete_temp("ready_to_party");
   tell_room( environment(ob), HIY"喜老板又手一挥，几个彩衣乐手立刻吹起唢呐、奏起喜乐。\n"NOR);

   list = all_inventory(environment(me));
   i = sizeof(list);
   while (i--)
   {
       usr= list[i];
       if( obj=new(__DIR__"obj/xijiu"))
       obj->move(usr);
   }
   tell_room(environment(usr), "\n从内堂走出一排漂亮的黄衫少女，依次走到每个人面前。\n"
		"黄衫少女递给你一杯斟满喜酒的玉盏又走开了去。\n");
   call_out("finish_party", 500, me,ob);
   return 1;
}

int do_serve()
{
   object ob=this_object();
   object me=this_player();
   object food;
   if( !me->query_temp("host_of_party") )
     return notify_fail(name()+"斜眼瞪了你一眼道：“主人没说话，你嚷什么？！”\n");
   if( !me->query_temp("party_start_already") )
     return notify_fail(name()+"对你笑说：“还没告诉我开始(kaishi)，我怎么好开席？”\n");

   message_vision("$N大声嚷嚷着：上菜，上菜！\n", me);

   tell_room(environment(me), "“来啦！”四五个小伙计从内堂鱼贯而出，一盘盘美味佳肴立刻摆上了桌。\n");
   if(food=new(__DIR__"obj/jiuyan"))
        food->move(environment(me));
   return 1;
}

int do_finish()
{
   object ob=this_object();
   object me=this_player();

   if( !me->query_temp("host_of_party") )
     return notify_fail(name()+"不满意地瞪了你一眼：“你吃你的，不关你事不要乱说话！”\n");

   if( !me->query_temp("party_start_already") )
     return notify_fail(name()+"呵呵笑道：“喜筵不是已经结束了吗！”\n");
   message_vision("$N对$n说道：“客人吃得都不错，十分感谢喜老板的安排！”\n", me, ob);
   remove_call_out("finish_party");
   call_out("finish_party", 2, me,ob);
   return 1;
}

void finish_party(object me,object ob)
{
   int i;
   object *list,ob1,ob2,usr;

   message_vision(HIC"\n$N大声说道：“小小薄宴，怠慢诸位，$n的喜宴就此结束，多谢大家光临！\n"NOR, ob,me);
   command("gongxi " + me->query("id"));

   me->set_temp("party_finish",1);
   me->delete_temp("party_start_already");
   me->delete_temp("host_of_party");
	message("vision","\n一旁的黄衫少女连忙上来把酒席上的残羹剩菜收拾干净抬下去。\n",environment(me));
   if(ob1=present("jiuxi", environment(ob)))
      destruct (ob1);
   list = all_inventory(environment(ob));
   i = sizeof(list);
   while (i--)
   {
       usr= list[i];
       ob2=new(__DIR__"obj/xitang");
       ob2->set("name",me->name()+"和"+me->query("couple/couple_name")+"的喜糖");
       ob2->move(usr);
   }
   tell_room(environment(usr), "\n喜老板吩咐手下的伙计把喜糖一包包地发给每一个人。\n");
   remove_call_out("give_money");
   call_out("give_money",1,me,ob);
}

int give_money(object me,object ob)
{
	if( !me || environment(me) != environment(ob) )
   {
   	message_vision("喜老板突然向四周一看：“咦？人去哪里了，连代收的礼金都不要了？”一边\n"
      "摇着头一边向内堂走去，伙计、黄衫少女也一齐走进去，喜福堂一下子空下来了。\n",ob);
		ob->move("/d/city/empty");//不要直接dest，以备查
	   return  1;
   }
   message_vision("\n喜老板笑呵呵地走到$N面前，一挥手，旁边的小伙计捧过来一盘银两，喜老板说道：\n"
   "“这是小可代二位收下的客人送上的礼金，一共是"+MONEY_D->price_str((int)ob->query("money"))+"\n"
   "现在交给您，可得收好！”说完，将钱如数交给$N。然后一齐走进内堂不见了。\n",me);
	MONEY_D->pay_player(me,(int)ob->query("money"));
  	ob->move("/d/city/empty");//不要直接dest，以备查
	return 1;
}

int do_kill(string arg)
{
   object me = this_player();
   object ob = this_object();

   if(!arg || present(arg,environment(ob))!=ob) return 0;

   message_vision("$N脸色不大对，好象动了杀机！\n$n对$N直摇头：这大喜的日子动手干什么啊！\n", me,ob);
   return 1;
}

int do_exert(string arg)
{
   object me = this_player();
   object ob = this_object();
   message_vision("$N鬼鬼祟祟地一运气。\n$n对$N瞪了一眼，说：刚吃过饭，不要乱用内功！\n", me,ob);
   return 1;
}

int do_steal(string arg)
{
   object me = this_player();
   object ob = this_object();
   message_vision("$N伸出手，想要偷点什么。\n$n对$N骂道：怎可随便光天化日施盗行窃！\n",me,ob);
     return 1;
}
