//whuan
//duan zhenchun

#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;
int ask_yideng(); //询问一灯大师的路径
int ask_xiangsi();//相思三剑

void create()
{
	set_name("段正淳", ({ "duan zhengchun", "zhengchun", "duan"}));
	set("long","他身形高大，一袭紫袍着身，衬得一张国字脸不怒自威。\n");
	set("title", HIM"镇南王"NOR);
	set("gender", "男性");
	set("age", 43);
	set("inquiry", ([
		"段誉" : "便是在下犬子，不久前负气离家出走，唉 ... 可问阁下知否他的下落？",
		"南帝" : "南帝段智兴已经不在人世了。",
		"南僧" : (: ask_yideng() :),	
		"一灯大师" : (: ask_yideng() :),		
		"相思三剑" : (: ask_xiangsi() :),
		]));

	set_skill("finger", 300);
	set_skill("force", 300);
	set_skill("strike", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("cuff", 300);
	set_skill("literate", 300);
	set_skill("yiyang-zhi", 300);
	set_skill("duanjia-jian",300);
	set_skill("duanshi-shenfa",300);
	set_skill("duanjia-xinfa",300);
	set_skill("qingyan-zhang", 300);
	set_skill("jinyu-quan", 300);
	map_skill("cuff","jinyu-quan");
	map_skill("sword","sun-finger");
	map_skill("dodge","duanshi-shenfa");
	map_skill("parry", "duanjia-jian");
	map_skill("force","duanjia-xinfa");
	map_skill("strike","qingyan-zhang");
	map_skill("finger","yiyang-zhi");
	prepare_skill("finger","yiyang-zhi");

	set("str", 28);
	set("int", 25);
	set("con", 28);
	set("dex", 28);
	set("max_qi", 1200);
	set("qi",1200);
	set("max_jing", 800);
	set("jing",800);
	set("max_neili", 1800);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 80);
	set("combat_exp", 3000000);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("yiyangzhi/sword",1);
	create_family("大理段家", 15 , "传人");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
	}) );

	setup();
	carry_object("/d/city/obj/changjian")->wield();
	carry_object("/d/dalicheng/obj/zipao")->wear();
}

void attempt_apprentice(object ob)
{
	mapping fam;
	if (!mapp(fam=ob->query("family"))
		|| fam["family_name"] !="大理段家") {
		command("say "+RANK_D->query_respect(ob)+"还是先在段家做做别的事再来找我吧。");
		return;
	}
  
  if (fam["master_id"] =="yideng dashi"){
    command("say 你有幸得一灯大师亲自指点，就不需要我费心了。");
    return;	
  }
  
  if ((int)ob->query("betrayer")>=1){
  	command("say 大理王府岂可将绝技传给不忠之人。");
  	command("say 你去吧。");
  	return;
  }  	
  
	if ((int)ob->query_skill("duanjia-xinfa",1)<100) {
		command("say 我们段家的内功是天南一绝，你还要多下下功夫。");
		return;
	}

	if ((int)ob->query("score",1)<1000) {
		command("say 从你身上看不到你的忠诚，你得为大理王府做点什么。");
		return;
	}
  
	message_vision("$N双膝跪倒，对着$n说道：“镇南王在上，在下誓死效忠！”\n\n$n哈哈大笑两声，爱卿平身，将$N从地上扶起。\n\n",ob,this_object());
	command("recruit " + ob->query("id"));
	if(ob->query("gender")=="男性")
	  ob->set("title", HIR"大理王府"+HIC"武将"NOR);
	else
		ob->set("title", HIR"大理王府"+HIC"女侍"NOR);
//title系统记录玩家title by seagate@pkuxkx
	ob->set_title(TITLE_RANK, ob->query("title"));
  return;
}

int ask_yideng()
{
	object me=this_player();
	//要通过一灯task
	mapping myfam;
  myfam = (mapping)me->query("family");
        
  if (myfam && myfam["family_name"] != "大理王府"){
    command("ah "+(string)me->query("id"));
    command("say "+ RANK_D->query_respect(me) +"这话从何说起？n");
    return 1;
  }
    
	if(!me->query("task_duan3")){
		command("dunno");
		return 1;
  }	

	if ((int)me->query("score",1)<1500) {
		command("say 你得为段家做点什么，不然我如何指点你？");
		return 1;
	}	
	
	command("say 一灯大师隐居在桃源，你福缘深厚，也曾有缘得他指点。");
	command("say 一灯大师深通大理段式一阳指绝技，或可指点你一二。");
	command("say 你可以直接从桃源瀑布的捷径上去。\n");
	me->set_temp("dali/ask_yideng",1);
	return 1;
}

int ask_xiangsi()
{
	object me=this_player();
	mapping myfam;
  myfam = (mapping)me->query("family");
        
  if (myfam && myfam["family_name"] != "大理王府"){
    command("ah "+(string)me->query("id"));
    command("say "+ RANK_D->query_respect(me) +"这话从何说起？n");
    return 1;
  }

	if ((int)me->query("score",1)<1500) {
		command("say 你得为段家做点什么，不然我如何指点你？");
		return 1;
	}	
	
	if ((int)me->query("yiyangzhi/ask_aluo")>=3){
    command("cry2");                                
    command("say 谢谢你帮我带回阿萝的消息，我这就将相思三剑的绝技传授给你。\n");
    message_vision("$N指点了$n运指于剑的技巧，并把相思三剑的绝技传授给了$n。\n",this_object(),me);
    if(me->query_skill("sun-finger",1)>=200){
    	tell_object(me,"你的一阳指根基扎实，很快你就领悟了这些绝招。\n");
    	me->set("yiyangzhi/sword",1);
    	me->set("yiyangzhi/xiangsi",1);        
    }                                          
    else
    	tell_object(me,"你的一阳指根基不够扎实，听了半天也没听懂。\n");	
	}
	else{
    command("think");
    command("say 我生平所爱女子中，唯有无量山女子阿萝最是难忘。");
    command("sigh");
    command("say 自当年一别，至今杳无音讯，如你能带回有关阿萝的只字片语，我必以绝技相授。");
    me->set_temp("dali/ask_aluo",1);
  }
  return 1;
}       
                                             
