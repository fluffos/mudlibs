// longer.c 小龙女
#include <ansi.h>
inherit NPC;
inherit F_AQUESTMASTER;
string ask_me();
string ask3();
string ask2();
void consider();
void heal();

string s_skill;
string ask_special_skill();
void create()
{
         set_name("小龙女", ({ "xiao longnu","longnu","longer"}));
        set("title",HIR "古墓派" NOR + MAG "传人" NOR);
        set("long",
                "她就是古墓派第三代传人小龙女，容颜极美，只是脸上稍带白色。\n"
                "她是神雕大侠扬过的妻子。\n");
        set("gender", "女性");
        set("age", 29);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 18);
        set("int", 32);
        set("con", 20);
        set("dex", 50);
        set("per", 50);
        set("hubo", 1);
        set("suxin", 1);
        set("max_qi", 4000);
        set("max_jing", 4000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 100);
        set("combat_exp", 10000000);
        set("score", 100000);
	 set("book_count", 1);
        set("chat_chance", 100);
        set("chat_msg", ({
	   (: heal :),
	}));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: consider :)
        }) );
   
	 set_skill("force", 280);
        set_skill("yunu-xinjing", 280);
        set_skill("changhen-xinfa", 280);
	set_skill("cuff", 280);
	set_skill("meinu-quan", 280);
        set_skill("dodge", 300);
        set_skill("xianyun", 300);
        set_skill("parry", 280);
        set_skill("whip", 280);
        set_skill("changhen-bian", 300);
	set_skill("throwing",280);
	set_skill("qianmie-shou",280);
        set_skill("literate", 150);
        set_skill("qufengshu", 180);
	set_skill("yunu-jianfa",280);
        set_skill("sword",300);

        map_skill("force", "yunu-xinjing");
	map_skill("cuff", "meinu-quan");
        map_skill("dodge", "xianyun");
	map_skill("sword","yunu-jianfa");
        map_skill("parry", "changhen-bian");
        map_skill("whip", "changhen-bian");
	map_skill("throwing","qianmie-shou");

        prepare_skill("cuff", "meinu-quan");
	
        set("chat_chance", 100);
		// 特别技能指导能力
		s_skill = "master-taiyin";
	 set("inquiry", ([
                "淑女剑" : (: ask_me :),
		"机关"   : (: ask3 :),
		"左右互搏": (: ask2 :),
                s_skill       : (: ask_special_skill :),
        ]) );
      
        create_family("古墓派" , 3, "传人");
        setup();
        carry_object("/d/gumu/npc/obj/lingsuo");
        carry_object("/clone/weapon/changjian");
        carry_object("/d/gumu/npc/obj/white")->wear();
}
void init()
{
add_action("give_wsquest","quest");
}


string ask_special_skill()
{
	object user;
	int cur_lvl;
	
	user = this_player();
	if (!user->query_temp("mark/ok_"+s_skill))
	{
		// max lvl == 20
		if ((cur_lvl = SPECIAL_D->query_level(user, s_skill)) >= 20 )
			return "你的技能已经太高，在下已经无法指点你了。\n";
		
		// lvl <= user_lvl /2
		if (cur_lvl*2 +2 > (int)user->query("level"))
			return "受你的等级限制，我无法继续指点你"+to_chinese(s_skill);
		
		if (user->query("level_used")>= user->query("level"))
			return "你的特别潜能点数已经用完了。";
		
		if (YINYANG_D->query_yinyang(user) != "太阴")
			return "你的内功并没有显现出太阴气息，恕在下无法指导。\n";
		
		if (!SPECIAL_D->query_level(user, "master-con"))
			return "你先要修习"+to_chinese("master-con")+"(master-con)才能修练"+to_chinese(s_skill)+"。";
		
		user->set_temp("mark/gold_"+s_skill, 1);
		return "好吧，你身上带学费了么？学习第"+chinese_number(cur_lvl+1)+"级"+to_chinese(s_skill)
			+"需要花费"+chinese_number(SPECIAL_D->query_money(user, s_skill))+"两黄金。\n";
	}
	else if (user->query("level_used") < user->query("level"))
	{
		user->delete_temp("mark/ok_"+s_skill);
		if ((cur_lvl = SPECIAL_D->query_level(user, s_skill)) < 20 )
		{
			user->add("special/"+s_skill, 1);
			user->add("level_used",1);
			message_vision(query("name")+"在$N耳边轻声说了几句控制太阴气息的诀窍。\n", user);
			tell_object(user, "你的"+to_chinese(s_skill)+"("+s_skill+")进步了！\n");
			tell_object(user, "你感觉内功的太阴气息也随之增强了。\n");
			return "可曾见过过儿的一对雕儿？";
		}
	}
	return "什么？";
}

int accept_object(object user, object ob)
{
	if (user->query_temp("mark/gold_"+s_skill) && ob->query("money_id") 
			&& ob->value() >= SPECIAL_D->query_money(user, s_skill)* 10000)
	{
		message_vision(query("name")+"同意指点$N一下"+to_chinese(s_skill)+"的问题。\n", user);
		user->delete_temp("mark/gold_"+s_skill);
		user->set_temp("mark/ok_"+s_skill, 1);
		return 1;
	}
	return 0;
}

void attempt_apprentice(object ob)
{
	if((string)ob->query("family/family_name")!="古墓派")
		{
		 command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜小虹小玲。"); 
                return;
        	}
   if((int)ob->query("betrayer")>0)
   {
   command("say 学武之人最忌背信弃义，你是判师之人，我怎么能够收你!\n");
   return;
    }
        if((int)ob->query("score")<1000)
{
   command("say 你对我派的贡献还不够，我暂时不能够收你!\n");
   return;
}
	 if ((int)ob->query_skill("yunu-xinjing",1) < 50)
		 {
		 command("say " + RANK_D->query_respect(ob) + "玉女心经太低，再回去好好努力吧。"); 
                return;
        	}
	if (((int)ob->query("dex")+(int)ob->query_skill("dodge",1)/10)<20)
		{
		command("say" + "我古墓派的功夫以轻灵为主，" + RANK_D->query_respect(ob) + "似乎对轻功不太重视吧。");
        	return;
		}
	else
          {
        command("say 好吧，"+RANK_D->query_respect(ob)+"，我就收下你了！");
        command("recruit "+ob->query("id"));
           }
       
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
	      { if(ob->query("gender")=="女性")
		             	ob->set("title",GRN "古墓派" NOR + MAG +"圣女" NOR);
		else
		ob->set("title",GRN "古墓派" NOR + MAG +"圣使" NOR);
               return;}

}
void re_rank(object student)
{
	         if(student->query("gender")=="女性")
                	student->set("title",GRN "古墓派" NOR + MAG +"圣女" NOR);
		else
		student->set("title",GRN "古墓派" NOR + MAG +"圣使" NOR);	
		return;
             
}
string ask_me()
{
        mapping fam;
        object ob;
	object me=this_player();
            if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "古墓派")
             return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
	if((int)me->query_temp("sword1")==1)
	return "你已经拿了一把宝剑了，还想要第二把呀";
        if((int)me->query_skill("yunu-jianfa",1)<80)
        return "你的玉女剑法太底，要了淑女剑也发挥不出它的威力。";
        if (query("book_count") < 1)
                return "你来晚了，本派的淑女剑不在此处。";
        add("book_count", -1);
        ob = new("/d/gumu/obj/sword1");
        ob->move(this_player());
	me->set_temp("sword1",1);
        return "好吧，这把淑女剑你拿回去好好保管。";
}

string ask3()
{	mapping fam;
	object me=this_player();
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "古墓派" )
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
	if (me->query("score")<500)
		return "墓洞可是我古墓派的重地，不是一般人能进去的。\n";
	else 
		{me->set("jiguan",1);
		return "好吧，我就把机关的秘密告诉你吧，你好自为之。\n";
	}
}
string ask2()
{mapping fam;
	object me=this_player();
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "古墓派" )
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
	else
	{
	message_vision("小龙女说道：“好吧，我就教你双手互搏吧。”\n",me);
	if (me->query_skill("yunu-xinjing",1)<80)               
	{ message_vision("$N练了半天，还是没练会。”\n",me);
               
	return "也许是你玉女心法不够，静不下心来练吧。\n";}
 if (me->query("combat_exp")>500000)
	{message_vision("$N练了半天，还是没练会。”\n",me);
	return "也许是你经验太高，不习惯于左右互搏吧。\n";}
	message_vision("$N练了半天，学会了左右互搏之技。\n",me);
	me->set("hubo",1);
	me->set("suxin",1);
	return "记住，不要用我教你的来作恶，不然我决不轻饶。\n";
	}
}	
void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
         switch( random(2) )
        {
            case 0:
            command("wield jian");
            command("perform sword.suxin " + target->query("id"));
            command("unwield jian");
             break;
            case 1:
            command("wield lingsuo");
            command("perform whip.chan " +target->query("id"));
            command("unwield lingsuo");
             break;
             }
}
void heal()
{
	object ob=this_object();
	
	if (ob->query("eff_qi") < ob->query("max_qi"))
	{
		command("exert heal");
		command("enforce 100");
		return;
	}

	if (ob->query("qi") < ob->query("eff_qi"))
	{
		command("exert recover");
		return;
	}

	if (ob->query("jing") < ob->query("eff_jing"))
		command("exert regenerate");

	return;
}
	
