// zhao.c
#include <ansi.h>
inherit NPC;
int ask_me();
void create()
{
	set_name("赵半山", ({"zhao banshan", "zhao", "banshan"}));
	set("title", HIR"红花会"HIG"三当家"NOR);
	set("nickname", HIY "千臂如来" NOR );
	set("gender", "男性");
	set("age", 48);
	set("long", 
"他一张胖胖的脸，笑起来给人一副很慈祥的感觉。他
原是温州王氏太极门掌门大弟子。豪迈豁达，行侠江
湖，一手暗器功夫和太极剑少有能匹敌。屠龙帮风流
云散之后，投入红花会。很得被红花会老当家于万亭
赏识。\n");
	set("attitude", "peaceful");
	set("class", "fighter");
	set("per", 21);
	set("str", 21);
	set("int", 30);
	set("con", 26);
	set("dex", 30);

	set("qi", 7500);
	set("max_qi", 7500);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 12500);
	set("max_neili", 12500);
	set("jiali", 100);
	set("combat_exp", 1000000);

	set_skill("force", 190);
	set_skill("taiji-shengong", 190);
	set_skill("unarmed", 190);
	set_skill("taiji-quan", 190);
	set_skill("throwing", 200);
	set_skill("hanxing-bada", 190);
	set_skill("dodge", 190);
	set_skill("tiyunzong", 190);
	set_skill("mantian-xing", 290);
	set_skill("parry", 190);
	set_skill("sword", 190);
	set_skill("taiji-jian", 190);

	map_skill("force"  , "taiji-shengong");
	map_skill("unarmed", "taiji-quan");
	map_skill("dodge"  , "tiyunzong");
	map_skill("parry"  , "taiji-jian");
	map_skill("sword"  , "taiji-jian");
	map_skill("throwing"  , "hanxing-bada");

	        set("inquiry", ([
                "逃离商家" : (: ask_me :),
        ]) );
	set("chat_chance_combat", 70);  
	set("chat_msg_combat", ({
		(: command("wield changjian") :),
		(: command("haha") :),
		(: command("unwield changjian") :),
		(: command("wield jili") :),
		(: command("unwield jili") :),
	}));
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/weapon/jili")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
int ask_me()
{
	int i;

	object who = this_player();
	object where = environment(who);
  	if(((int)who->query("combat_exp",1)<=1000000))
	{
		message_vision("$N对$n说道： 你的武功太差了，等武功好点再来吧！\n",this_object(),who);
		return 1;	
	}	

	  	if(((int)who->query("jinyong/book1")>=1))
	{
		message_vision("$N对$n说道： 我听不懂,你在说什么啊！\n",this_object(),who);
		call_out("destroying", 0);     
		return 1;	
	}
	command("bow " + who->query("id"));
	message_vision("$N对$n说道： 谢谢大侠教命之恩。\n",this_object(),who);
	message_vision("听说佛山附近有一个姑娘 打败了数派掌门\n",this_object());
	message_vision("如果我也是个掌门，北京掌门人大会 我一定要去见识一下。\n",this_object());

	
	i = random(800);
	who->set("jinyong/book1",1);
	who->add("combat_exp",i+6880);
	who->add("potential",i*8);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"你赢得了"+chinese_number(i+6880)+"点经验"+
	           chinese_number(i*8)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
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