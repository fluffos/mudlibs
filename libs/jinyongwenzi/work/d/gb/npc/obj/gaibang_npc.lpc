// gaibang_npc.c, recruiting gb_dizi and promoting system
#include <ansi.h>

// npc list for gb 1-3 dai promotion
mixed names = ({
	({
	"白虹剑", "沙袋", "星宿毒经","华山剑谱","黑龙鞭",
	}),
	({
	"小木鼎","七伤拳谱","铁罗汉","大还丹","小还丹",
	}),
	({
         "九转结气丸","天山雪莲","洗髓经","内功心法",
	}),
        ({
         "落英神剑掌谱","碧玉箫","图画","玉真散","回阳玉龙膏",
       	}),
       ({
        "乾坤一气袋","叫化鸡","两仪剑谱","焦尾琴","黄金铙","金刚罩",
      }),
});
          
void killing_object(object who);
string ask_me()
{
	mapping fam, my_fam; 
        object applicant, me;
	int begging_level,position,exp,htlvl;
	string target;

	applicant = this_player();
	me = this_object();
	my_fam  = me->query("family");

// check if this player is gb dizi and meet the requirements for promotion
	if ( !mapp(fam = applicant->query("family")) 
	|| fam["family_name"] != "丐帮" )
		return RANK_D->query_respect(applicant) +
		"不是本帮弟子，何有此问？ \n";	
	position = (int)applicant->query("gb_bags");          // num of bags 
	if ( applicant->query_temp("promotion_target") )
		return RANK_D->query_respect(applicant) +
		"快去完成你的任务，好早日升袋！\n";
	begging_level = (int)applicant->query_skill("begging",1);
	if ( begging_level < 30 ) 
		return RANK_D->query_respect(applicant) +
		"在帮中资历尚浅，不能升袋。\n";
	if ( ( begging_level < 60 ) && ( position == 2 ) )
		return RANK_D->query_respect(applicant) +
		"要多多加油！\n";
	if ( ( begging_level < 80 ) && ( position == 3 ) )
		return RANK_D->query_respect(applicant) +
		"要多加努力才能在帮中出人头地。\n";
	if (( begging_level<100 )&&(position==4))
		return RANK_D->query_respect(applicant) +
		"还是不能升袋。\n";
           exp=(int)applicant->query("combat_exp",1);
           htlvl=(int)applicant->query("huntian-qigong",1);
        if (((exp<150000)||(htlvl<80))&&(position==5))
            return RANK_D->query_respect(applicant) +
		"对于武功方面是否过于忽略了？\n";
        if (position>5)
         return RANK_D->query_respect(applicant)+"已经技压群雄了，找洪帮主去吧。\n";
// the following will random choose a target and assign to this player
        if(applicant->set_temp("promotion_target"))
          return "还不快去？\n";
	target = names[position-1][random(sizeof(names[position-1]))];
	applicant->set_temp("promotion_target", target);
	applicant->set_temp("assigned_by", me->query("name"));	
	return "好吧，你若要升袋，需得先弄点成绩出来。\n" + 
	"你去把" + target +"给我找来。\n";
}
int promotion_checking(object who, object ob)
{
        object me = this_object();
        int bag,exp;
// check if accept corpse from player
        if ( who->query("family/family_name") != "丐帮" ) 
                return 0;
        if ( ob->query("name") != (string)who->query_temp("promotion_target")) {
		command("say 这东西我要来没用。");
		return 0;
	}
/*        if ( !who->query_temp("promotion_target") ) {
		command("say 好啊！不过你得先申请升袋。");
                return 0;
	}*/
        if ( who->query_temp("assigned_by") != me->query("name") ) {
		command("say 好样的！快拿去给给你任务的舵主吧。");
                return 0;
        }

// all right, now it's time to check if the corpse is correct ;
// there is still a bug here, since i can't check if corpse is 
// npc's corpse or a player who has the same name as that npc, 
// although it's illegal.
/*	if ( ob->query("victim_name") 
	!= who->query_temp("promotion_target") ) {
		command("say 嘿嘿。。。，你杀错人了。");
		return 0;
	}*/
	if (userp(ob)) {
		command("say " + RANK_D->query_rude(who) + 
			"，居然敢欺骗本舵主，拿命来把！");
		call_out("killing_object",1,who);
		return 0;
	}
        bag=(int)who->query("gb_bags",1);        
        exp=(bag*bag*1000);
 	who->add("gb_bags",1);	
// benifits from 升袋, 10 maxneili + 1 begging,sttealing level
	who->add("max_neili",10);
	who->set_skill("begging",(int)who->query_skill("begging",1) + 1);
	who->set_skill("stealing",(int)who->query_skill("stealing",1) + 1);
	who->add("combat_exp",exp);
        command("applaud " + who->query("id"));
	command("say 干得好！从今天开始，你就是丐帮" + 
		chinese_number(who->query("gb_bags")) +
		"袋弟子，好好干！\n");
        who->set("title",sprintf("丐帮%s袋弟子",
                chinese_number(who->query("gb_bags"))) );
	who->delete_temp("assigned_by");
	who->delete_temp("promotion_target");
	return 1;
}	


void killing_object(object who)
{
	object me = this_object();
	me->kill_ob(who);
	who->unconcious();
}


void gb_apprentice(object ob)
{
        string prev_family_name;

        if ( (int)ob->query("gb_bags") >= 2  
	&& (prev_family_name = ob->query("family/family_name")) != "丐帮" ) {
                command("say 丐帮可容不下你这种背信弃义的小人！");
                return;
        }

        command("say 好吧，希望" + RANK_D->query_respect(ob) +
        "能好好学习本门武功，将来在江湖中闯出一番作为。");
        command("recruit " + ob->query("id"));
        if ( prev_family_name != "丐帮")
                ob->set("gb_bags", 1);
        ob->set("title",sprintf("丐帮%s袋弟子",
                chinese_number(ob->query("gb_bags"))) );
}
