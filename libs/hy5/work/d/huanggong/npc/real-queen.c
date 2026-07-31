#include <ansi.h>
inherit NPC;
int ask_me();
void create()
{
        set_name(HIY "皇太后" NOR, ({ "empress","queen"}));
        set("shen_type", 0);
        set("age",43);
        set("gender", "女性");
      set("per",24);
        set("long",
                "她生得矮矮胖胖，也许是终年不见阳光，所以她的脸色显得很苍白。\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("inquiry", ([
                "陷害" : "你什么意思......。\n",
                "营救" : (: ask_me :),
        ]));
      
  setup();
//        carry_object("/clone/misc/pink_cloth")->wear();
}
int ask_me()
{
	int i;

	object who = this_player();
	object where = environment(who);
	

	  	if(((int)who->query("jinyong/book7")!=3))
	{
		message_vision("$N对$n说道： 我听不懂,你在说什么啊！\n",this_object(),who);
		call_out("destroying", 0);     
		return 1;	
	}
	command("thank " + who->query("id"));
	message_vision("$N对$n说道： 谢谢教命之恩。\n",this_object(),who);
	message_vision("$N对$n说道： 神龙救阴谋叛逆，真不知道如何是好 。\n",this_object(),who);
if(((int)who->query("jinyong/book7")==3))
{	
	i = 300+random(800);
	who->set("jinyong/book7",4);
	who->add("combat_exp",i+9880);
	who->add("potential",i*12);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"你赢得了"+chinese_number(i+9880)+"点经验"+
	           chinese_number(i*12)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
	who->save();
}
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