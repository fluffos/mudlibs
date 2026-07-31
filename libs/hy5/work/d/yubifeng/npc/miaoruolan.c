// miaoruolan.c 苗若兰

#include <ansi.h>
inherit NPC;
int ask_me();
void create()
{
	set_name("苗若兰", ({ "miao ruolan", "ruolan", "miao" }) );
	set("gender", "女性");
	set("age", 17);
	set("long","她是天下第一高手，“打遍天下无敌手”的“金面佛”苗人凤之女。只是自小家教，不习武功。\n");
	set("attitude", "friendly");
	set("str", 15);
	set("int", 15);
	set("con", 19);
	set("dex", 17);
	set("per", 34);
	set("combat_exp", 2000);

	set("chat_chance", 10);
	set("chat_msg", ({
		"苗若兰幽幽地道：当年那个可怜的小男孩现在也不知怎么样了？\n",
		"苗若兰皱了皱秀眉：爹爹怎么还没上山？\n",
        }) );
	        set("inquiry", ([
                "搭救" : (: ask_me :),
        ]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
int ask_me()
{
	int i;

	object who = this_player();
	object where = environment(who);
    
        if(((int)who->query("jinyong/book2")!=1))
	{
		message_vision("$N对$n说道： 你在说什么啊！\n",this_object(),who);
		return 1;	
	}
	

	  	if(((int)who->query("jinyong/book2")>=2))
	{
		message_vision("$N对$n说道： 我听不懂,你在说什么啊！\n",this_object(),who);
		call_out("destroying", 0);     
		return 1;	
	}
	
	
        if((!(int)who->query_temp("killtian1")))
	{
		message_vision("$N对$n说道： 你没杀了杜希孟 我逃不出去！\n",this_object(),who);
		return 1;	
	}
	
	command("thank " + who->query("id"));
	message_vision("$N对$n说道： 谢谢大侠教命之恩。\n",this_object(),who);
	message_vision("胡大哥，就在雪山上。快去帮他吧。\n",this_object());

	
	i = 500+random(800);
	who->set("jinyong/book2",2);
	who->add("combat_exp",i+9880);
	who->add("potential",i*12);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"你赢得了"+chinese_number(i+9880)+"点经验"+
	           chinese_number(i*12)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
	who->save();
	call_out("destroying", 0);                       
	return 1;
}
void destroying()
{   
object ob=this_object();
   message_vision(HIM"$N说完闪了闪身就消失在门外......\n"NOR,ob);
destruct(this_object());
   return;      
}