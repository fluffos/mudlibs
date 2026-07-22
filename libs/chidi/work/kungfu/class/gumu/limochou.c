// limochou.c 李莫愁
// By Kayin @ CuteRabbit Studio 99-3-29 11:48 new 
inherit BHNPC;
inherit F_MASTER;
#include <ansi.h>
int do_look(string target);
string ask_zhen();
void create()
{
	set_name("李莫愁", ({ "li mochou", "li","mochou" }));
	set("nickname",HIR"赤炼仙子"NOR);
	set("long",
		"她生得极为美貌，但冰冷的目光让人不寒而立，\n");
	set("gender", "女性");
	set("age", 34);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("per",29);
	set("str", 30);
	set("dex", 35);
	set("con", 17);
	set("int", 25);

	set("bpzhen",10);
	
	set("shen",600000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);

	set("combat_exp", 5000000);
	set("score", 8500);	
	
	set_skill("force",350);
	set_skill("yunu-xinfa",350);
	set_skill("literate",300);
	set_skill("meinu-quanfa",300);
	set_skill("tianluo-diwang",300);
	set_skill("wudu-shenzhang",300);
	set_skill("swsb-shou",300);
	set_skill("unarmed",300);
	set_skill("dodge",400);
	set_skill("whip",300);
	set_skill("xianyun-bufa",400);
	set_skill("throwing",400);
	set_skill("parry",300);

	map_skill("force","yunu-xinfa");
	map_skill("unarmed","wudu-shenzhang");
	map_skill("dodge","xianyun-bufa");
	map_skill("parry","swsb-shou");
	map_skill("whip","swsb-shou");
        set("inquiry", ([
	    "冰魄银针":(: ask_zhen :),
	    "小龙女" : "那是我的师妹。你问她想干什么？",
	    "林朝英" : "那是我的师祖，不该你问的你别问，小心我宰了你。",

	]));
	set("chat_chance", 10);
	set("chat_msg", ({
	    "李莫愁纵声而歌，音调凄婉，歌道：「问世间，情是何物，直教生死相许？」\n",
	    "李莫愁歌道：「天南地北双飞客，老翅几回寒暑？」\n",
	    "李莫愁唱道：「欢乐趣，离别苦，就中更有痴儿女。」\n",
	    "李莫愁唱道：「君应有语，渺万里层云，千山暮雪，只影向谁去？」\n",
	    "李莫愁词意悲切，声调更是哀怨，唱道：「横汾路，寂寞当年箫鼓。荒烟依旧平楚。」\n",
	    "李莫愁歌道：「招魂些何嗟及，山鬼自啼风雨。」\n",
	    "李莫愁唱道：「天也妒，未信兴，莺儿燕子俱黄土。」\n",
	    "李莫愁唱道：「千秋万古，为留待骚人，狂歌痛饮，来访雁丘处。」\n",
	}) );

	
	create_family("古墓派", 3, "弟子");
	setup();
        carry_object("/d/gumu/obj/fuchen")->wield();
           carry_object("/d/city/obj/cloth")->wear();

}
void attempt_apprentice(object ob)
{
        mapping myfam;
       	 myfam = (mapping)ob->query("family");
        if(!myfam && myfam["family_name"] != "古墓派")
        {
        	command("say 对不起，我不收别派弟子。");
        	return;
        }
         
        if(ob->query("class")!="taoist")
		{
			command("say 你已经是我师妹的弟子了，你还来找我干嘛？");
			return;
		}
	if ((int)ob->query("shen") > - 50000) {
		command("say " + RANK_D->query_respect(ob) +
			"是否还不够狠毒？");
		return;
	}

	
	if( (int)ob->query_dex()< 30){
		command("say 你的身法太差.");
		return;
	}
	if( (int)ob->query_int() < 45){
		command("say 你的悟性太差。");
		return;
	}
	if((int)ob->query_skill("yunu-xinfa",1)< 200){
		command("say 你的玉女心法太差了。");
		return ;
	}
	if((int)ob->query_skill("tianluo-diwang",1)<150){
		command("say 你的天罗地网势火候不够。");
		return ;
	}
	if((int)ob->query_skill("xianyun-bufa",1)<150){
		command("say 你的纤云步法太生疏了。");
		return ;
	}
	if((int)ob->query("max_neili")< 1000){
		command("say 你的内功修为不够。");
		return ;
	}
	
			
        	command("say 好吧，我就收下你了。");
		command("recruit " + ob->query("id"));
		if( (string)ob->query("class") != "taoist")
		ob->set("class", "taoist");
}

string ask_zhen()
{
	object me=this_player();
	object obn;
	mapping myfam;
	if (query("bpzhen") < 1)
		return "我这里已经没有玉蜂针了。\n";

	 myfam = (mapping)me->query("family");
        if(myfam && myfam["family_name"] == "古墓派")
       	if(myfam["generation"] == 4)
            {
            	if(me->query("class")=="taoist")
            	{
            		obn=new("/d/gumu/obj/bpzhen");
            		obn->move(me);
            		add("bpzhen", -1);
            		return "这些冰魄银针就送给你吧。\n";
            	}
            	else
            	{
            		command("say 你是我师妹的弟子，我干嘛要给你？.\n");
            		return 0;
            	}
        }
        else
        {
        	return 0;
        }
}	
int do_look(string target)
{
	object me;

	me = this_player();
	if (target=="li" || target=="li mochou" || target=="mochou" )
           if ((string)me->query("gender") != "女性") {
		   message("vision",
   HIY "李莫愁大怒，喝道：我最恨你们这些薄情的臭男人！去死吧！\n"
       "李莫愁决心杀死" + me->name() +"\n"
   NOR, environment(), this_object() );
                   kill_ob(this_player());
           }
}
