// unix 1998,10
// modified by wind

#include <ansi.h>
#include <ansi.h>
inherit NPC;
//inherit F_CLEAN_UP;
void del_gaoed(object me);

void init()
{
add_action("do_gao","gao");
add_action("xiao_li","dangguan");
}

void create()
{
	set_name("钦差〖包龙星〗", ({"qin chai", "qin"}));
	set("title", HIY"八省总巡捕"NOR);
	set("nick_name", "钦差大人");
        set("gender", "男性");
        set("age", 54);
        set("long",
                "他是京城皇上派来的钦差大臣，手中掌管着兵马大权，\n"
			);

        set("attitude", "peaceful");

        set("str", 27);
        set("int", 25);

	set("neili", 24000);
	set("max_neili", 24000);
	set("jiali", 50);
	set("max_jing", 12000);
	set("eff_jing", 12000);
	set("jing", 12000);
	set("max_qi", 15000);
	set("eff_qi", 15000);
       set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);

        set("combat_exp", 5800000);

        set_skill("blade", 70);
        set_skill("force", 80);
        set_skill("parry", 50);
        set_skill("dodge", 60);
	set_skill("literate", 100);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("whip", 200);
	set_skill("blade", 200);
	set_skill("sword", 200);
	set_skill("hand", 200);
	set_skill("claw", 200);
	set_skill("houquan", 300);
	set_skill("yunlong-xinfa", 300);
	set_skill("yunlong-shengong", 300);
	set_skill("wuhu-duanmendao", 300);
	set_skill("yunlong-jian", 300);
	set_skill("yunlong-shenfa", 300);
	set_skill("yunlong-bian", 300);
	set_skill("yunlong-shou", 300);
	set_skill("yunlong-zhua", 300);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");

	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");

	set("chat_chance_combat", 70);  
	set("chat_msg_combat", ({
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.duoming" :),
                (: perform_action, "sword.guang" :),
                (: perform_action, "sword.jueming" :),
                (: perform_action, "sword.shen" :),                	
                (: perform_action, "sword.xunlei" :),                	                	
                (: exert_function, "recover" :),
                (: perform_action, "unarmed.pofuchenzhou" :),

	}) );

	set("chat_chance", 5);
	set("chat_msg", ({
	"包龙星看看你说:想必你也有冤情?\n",
	"包龙星目视前方说:当年我为戚秦氏翻案差点丢了脑袋\n",
}));
	set("inquiry", ([
	"当官": "包龙星想了想说:想当官那要看你有无这分才能啊!\n",
	"告状": "你想告谁,喝喝我可是很清廉的好官哦!\n",
	"升官": "想升官就让我来考考你(dangguan)\n",
]));
        setup();
          carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/shan-jian")->wield();
}

int accept_object(object who, object ob)
{

if (!ob->query("money_id") )
	{
	tell_object(who, "钦差大人勃然大怒，说道：什么?竟敢对本官行贿？\n");
	message_vision(HIY"包龙星大喝道:大胆狂徒,胆敢行贿，来人给我托下去打!!\n"+
			"几个身强力壮的衙役一佣而上,将$N往外一扔,接着板子\n"+
			"像雨点般打在$N身上,打的$N哭爹喊娘\n"NOR,who);
	message_vision(HIR"突然$N不动了,一个衙役来到包龙星身边耳语了几句\n"+
			"只听包龙星说:这次盏且放过你下次再犯决不轻饶,退堂!!\n"NOR,who);
ob->start_busy(100);
	who->unconcious();
        return 0;
	}     
         if (ob->query("money_id") && ob->value() < 10000000)
	{
	tell_object(who, "钦差大人勃然大怒，说道：什么?竟敢对本官行贿？\n");
	message_vision(HIY"包龙星大喝道:大胆狂徒,胆敢行贿，来人给我托下去打!!\n"+
			"几个身强力壮的衙役一佣而上,将$N往外一扔,接着板子\n"+
			"像雨点般打在$N身上,打的$N哭爹喊娘\n"NOR,who);
	message_vision(HIR"突然$N不动了,一个衙役来到包龙星身边耳语了几句\n"+
			"只听包龙星说:这次盏且放过你下次再犯决不轻饶,退堂!!\n"NOR,who);
ob->start_busy(100);
	who->unconcious();
        return 0;
	}
        else 
        {
	message_vision(HIY"包龙星对$N嘿嘿地笑了几声。\n"NOR,who);
        who->set_temp("gao_paid",1);
	}
	return 1;      
}

void beating(object ob)
{
if (!ob) return;
	message_vision(HIY"包龙星大喝道:大胆狂徒,胆敢诬告,来人,给我托下去打!!\n"+
			"几个身强力壮的衙役一佣而上,将$N往外一扔,接着板子\n"+
			"像雨点般打在$N身上,打的$N哭爹喊娘\n"NOR,ob);
	message_vision(HIR"突然$N不动了,一个衙役来到包龙星身边耳语了几句\n"+
			"只听包龙星说:这次盏且放过你下次再犯决不轻饶,退堂!!\n"NOR,ob);
ob->move("/d/kaifeng/jianyu");
ob->start_busy(100);
	ob->unconcious();
}

void beating2(object ob)
{
if (!ob) return;
	message_vision(HIY"包龙星大喝道:大胆狂徒, 就算你犯了案吧！来人,给我托下去打!!\n"+
			"几个身强力壮的衙役一佣而上,将$N往外一扔,接着板子\n"+
			"像雨点般打在$N身上,打的$N哭爹喊娘\n"NOR,ob);
	message_vision(HIR"突然$N不动了,一个衙役来到包龙星身边耳语了几句\n"+
			"只听包龙星说:这次盏且放过你下次再犯决不轻饶,退堂!!\n"NOR,ob);
	ob->move("/d/kaifeng/jianyu");
ob->start_busy(100);
	ob->unconcious();
}


void dzj(object ob)
{
int j;
if (!ob) return;
message_vision(HIY"两旁衙役高呼:威~~呜~~~!!\n"NOR,ob);
j=random(3);
if (j == 0)
{
remove_call_out("beating");
call_out("beating", 3, ob);
return ;
}
call_out("dzj",j--, ob);
}

void dzj2(object ob)
{
int j;
if (!ob) return;
message_vision(HIY"两旁衙役高呼:威~~呜~~~!!\n"NOR,ob);
j=random(3);
if (j == 0)
{
remove_call_out("beating2");
call_out("beating2", 3, ob);
return ;
}
call_out("dzj2",j--, ob);
}

void del_gaoed(object me)
{
if (!me) return;
        if (objectp(me) &&  me->query_temp("gaoed"))
                me->delete_temp("gaoed");
}

int do_gao(string str)
{
	object ob,me;
	int i;
       me=this_player();
       if (!me->query_temp("gao_paid")) return notify_fail("再怎么也得交点手续费嘛！\n");
       if (me->query_temp("gaoed"))
                return notify_fail("你刚刚才告过了，怎么又来了! \n");
       if (!str) return notify_fail("<Syntax>: gao <player id>\n");
                   ob=find_player(str);
      if (!ob) ob= find_living(str);	
      if (!ob) return notify_fail("找不到你要的疑犯！\n");
      if (me->query("killbyname")!=ob->query("name")) return notify_fail("那人最近没对你做过什么啊！\n");
      
      me->set_temp("gaoed",1);
      if (me->query("pks")>random(50)||me->query("combat_exp")<random(500000))  
        {call_out("dzj", 5, me); }
      else {
        call_out("del_gaoed", 3000, me);
        me->delete_temp("gao_paid");
     	tell_room(environment(ob),"一群衙役一拥而上，把"+
	(string)ob->query("name")+"抓了起来, 然後绑走了.\n", ob);
	tell_object(ob,"一群衙役一拥而上，对你说：有人告你了，跟我们走一趟\n");
	ob->start_busy(50);
	me->set("killbyname",0);
	me->delete("killbyname");
	ob->set_temp("summon_time",time());
	ob->move(environment(me));
        tell_object(me, (string)ob->query("name")+"被抓到了衙门.\n");
	tell_object(ob,"你发现是"+(string)me->query("name")+
	"告你的.\n");
	tell_room(environment(ob),(string)ob->query("name")+"突然被抓"+
	"到衙门来了\n",({me,ob}));
	message_vision("\n$N看到$n站在大堂上暗笑不止,不由心火上升"
		+(string)me->query("name")+ "咂们等着瞧!\n",ob,me);
         call_out("dzj2", 5, ob);	
       }
       return 1;
}


int xiao_li()
{
 object ob;
 ob=this_player();
if (ob->is_busy())
{
	command("say 你正忙着呢。\n");
return 1;
}
	if(ob->query("combat_exp")<5000&&ob->query("meili")<500){
	command("say 我主万岁,需要的是有用之人,你算什么东西。\n")
;
}
else  {
	command("smile");
	command("say 很好,朝庭正是用人之季！" + ob->query("name") + 
        "大侠肯为朝庭效力，我正求之不得！\n");
	ob->set("class", "officer");
	ob->set("weiwang", 0);
}
if (ob->query("class")=="officer"){ 
       if ((ob->query("combat_exp")<10000)&&(ob->query("combat_exp")>5000)) ob->set("title", "翰林院编修");
 else if (ob->query("combat_exp")<15000) ob->set("title","乔阴县师爷");
else if (ob->query("combat_exp")<40000) ob->set("title","乔阴县令");
else if (ob->query("combat_exp")<65000) ob->set("title","雪亭镇县令");
 else if (ob->query("combat_exp")<80000) ob->set("title", "平杨县令");
else if (ob->query("combat_exp")<135000) ob->set("title", "大同县令");
else if (ob->query("combat_exp")<240000) ob->set("title", "凤祥县令");
else if (ob->query("combat_exp")<345000) ob->set("title", "晋阳县令");
else if (ob->query("combat_exp")<450000) ob->set("title", "桐城县令");
else if (ob->query("combat_exp")<560000) ob->set("title", "杭州令");
else if (ob->query("combat_exp")<670000) ob->set("title", "杭州知府");
else if (ob->query("combat_exp")<700000) ob->set("title", "开封知府");
else if (ob->query("combat_exp")<820000) ob->set("title", "广州知府");
else if (ob->query("combat_exp")<950000) ob->set("title", "南京知府");
else if (ob->query("combat_exp")<1200000) ob->set("title", "九门提督");
else if (ob->query("combat_exp")<1250000) ob->set("title", "云贵总督");
else if (ob->query("combat_exp")<1300000) ob->set("title", "两广总督");
else if (ob->query("combat_exp")<2350000) ob->set("title", "两江总督");
else if (ob->query("combat_exp")<3400000) ob->set("title", "礼部尚书员外郎");
else if (ob->query("combat_exp")<4500000) ob->set("title", "礼部尚书");
else if (ob->query("combat_exp")<5600000) ob->set("title", "户部尚书");
else if (ob->query("combat_exp")<6800000) ob->set("title", "钦赐龙图阁大学士");
else if (ob->query("combat_exp")<7000000) ob->set("title", "左丞相");
else if (ob->query("combat_exp")<8200000) ob->set("title", "右丞相");
else if (ob->query("combat_exp")<10000000) ob->set("title", "钦赐一等千里伯");
else if (ob->query("combat_exp")<12000000) ob->set("title", "钦赐二等万户侯");
else if (ob->query("combat_exp")<13000000) ob->set("title", "钦赐一等定北侯");
else if (ob->query("combat_exp")<15000000) ob->set("title", "钦赐二等护国公");
else if (ob->query("combat_exp")<28000000) ob->set("title", "钦赐一等鹿鼎公");
else if (ob->query("combat_exp")<50000000) ob->set("title", "钦赐特等平西王");
else ob->set("title", "兵马统领");
tell_object(ob,"你现在的官衔是[["+ob->query("title")+"]]\n");}
message("system", HIY"圣旨：
由于"+ob->query("name")+"执政有方，特为嘉奖
从即日起荣升为『"+ob->query("title")+"』！
望"+ob->query("name")+"能继续为朝庭效忠！
			钦此\n"NOR,users());
ob->start_busy(10);
       return 1;
 
}

