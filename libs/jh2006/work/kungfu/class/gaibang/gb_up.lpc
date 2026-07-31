// gb_up.c, 丐帮升袋 system
// Newcode by looklove 2000/8/25

#include <ansi.h>

// obj list 
mixed names = ({
        ({
        "道德经", "沙袋", "粉红绸衫","牛皮酒袋","铁甲","指套","竹剑","玉箫",
        }),
        ({
        "金刚经","七伤拳谱","太极十三势","虎皮","肘後备急方","灰狼皮","硫磺",
        }),
        ({
        "麻布袋","黑龙鞭","围棋","灰狼皮","银钥匙","鱼篓","绣花针",
        }),
        ({
        "铁罗汉","刀法概要","图画","玉真散","回阳五龙膏","寓意草",
        }),
       	({
        "内功心法","洗髓经","千年雪参","竹哨","星宿毒经","摩诃僧诋律",
      	}),
});

string ask_me()
{
        object ob, me;
        int bg_lvl,bags,exp,htlvl;
        string target;

        me = this_player();
        ob = this_object();
	bags = (int)me->query("gb_bags");  // 目前袋数
	bg_lvl = (int)me->query_skill("begging",1); //叫化绝活级别
	exp=(int)me->query("combat_exp",1); // 当前exp
	htlvl=(int)me->query_skill("huntian-qigong",1); //混天气功级别

        if ( me->query("family/family_name") != "丐帮" )
                return RANK_D->query_respect(me)+"不是本帮弟子，何有此问？ \n";
        
        if ( me->query_temp("sd_target"))
                return RANK_D->query_respect(me)+"我不是让你去找"+me->query_temp("sd_target")+"了吗？快去吧。\n";
        
        if ( bg_lvl < 30 ) 
                return RANK_D->query_respect(me)+"在帮中资历尚浅，不能升袋。\n";
        
        if ( bg_lvl < 60 && bags == 2 )
                return RANK_D->query_respect(me)+"要多多加油！\n";
        
        if ( bg_lvl < 80 &&  bags == 3 )
                return RANK_D->query_respect(me)+"要多加努力才能在帮中出人头地。\n";
        
        if ( bg_lvl < 100 && bags == 4 )
                return RANK_D->query_respect(me)+"还是不能升袋。\n";
           
        if (((exp<150000)||(htlvl<80))&&(bags==5))
            	return RANK_D->query_respect(me)+"对于武功方面是否过于忽略了？\n";
        
        if (bags>5)
        	return RANK_D->query_respect(me)+"已经技压群雄了，找洪帮主去吧。\n";

        if(me->set_temp("sd_target"))
          	return "还不快去？\n";
	
	// the following will random choose a target and assign to this player        
        target = names[bags-1][random(sizeof(names[bags-1]))];
        me->set_temp("sd_target", target);
        me->set_temp("up_by", ob->query("name"));
        return "好吧，你若要升袋，需得先弄点成绩出来。\n"+"你去把" + target +"给我找来。\n";
}

int promotion_checking(object who, object ob)
{
        object me = this_object();
        int bag,exp;
	
	// check if accept corpse from player
        if ( who->query("family/family_name") != "丐帮" )
                return 0;
        if ( ob->query("name") != (string)who->query_temp("sd_target")) {
                command("say 这东西我要来没用。");
                return 0;
        }
        if ( who->query_temp("up_by") != me->query("name")) {
                command("say 好样的！快拿去给给你任务的舵主吧。");
                return 0;
        }

	// all right, now it's time to check if the corpse is correct ;
	// there is still a bug here, since i can't check if corpse is 
	// obj's name or a player who has the same name as that obj, 
	// although it's illegal.
        
        if (userp(ob)) {
                command("say " + RANK_D->query_rude(who) + 
                        "，居然敢欺骗本舵主，拿命来把！");
                //call_out("killing_object",1,who);
                return 0;
        }
        bag=(int)who->query("gb_bags",1);
        exp=(bag*bag*1000);
        who->add("gb_bags",1);  
        who->add("max_neili",10);
        who->set_skill("begging",(int)who->query_skill("begging",1) + 1);
        who->set_skill("stealing",(int)who->query_skill("stealing",1) + 1);
        who->add("combat_exp",exp);
	command("applaud " + who->query("id"));
        command("say 干得好！从今天开始，你就升为" + 
                chinese_number(who->query("gb_bags")) +
                "袋弟子，好好干！\n");
        who->set("title",sprintf("丐帮%s%s袋弟子",
                who->query("gb/fenduo"),chinese_number(who->query("gb_bags"))) );
        who->delete_temp("up_by");
        who->delete_temp("sd_target");
        return 1;
}       
