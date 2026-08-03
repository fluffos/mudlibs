// bags_up.h 丐帮升袋 system
// Newcode by looklove 2000/8/25
// change gb_up.c to gabs_up.h at 2001.9.28 and recode

int promotion_checking(object who, object ob);

mixed names = ({
({"道德经", "沙袋", HIM"粉红绸衫"NOR,"牛皮酒袋","铁甲","指套","竹剑","玉箫",
"金刚经","七伤拳谱","太极十三势","虎皮","肘後备急方","灰狼皮","硫磺"}),
({"麻布袋","黑龙鞭","围棋","灰狼皮",HIW"银钥匙"NOR,"鱼篓","绣花针",
"铁罗汉","刀法概要","图画","玉真散","回阳五龙膏","寓意草"}),
({"内功心法","洗髓经",YEL"千年首乌"NOR,"竹哨","星宿毒经","摩诃僧诋律"}),
});

void dest(object ob)
{
    	if (ob) destruct(ob);
}

int get_object(object ob)
{
        if(userp(ob)) return 1;
        return 0;
}

int accept_object(object who, object ob)
{
    	if (promotion_checking(who, ob)) {
        	call_out("dest", 1, ob);
        	return 1;
    	}
    	return 0;
}

string ask_me()
{
        object ob, me;
        int bg_lvl, bags, exp, htlvl;
        string target;

        me = this_player();
        ob = this_object();
	bags = (int)me->query("gb/bags");  		// 目前袋数
	bg_lvl = (int)me->query_skill("begging",1); 	//叫化绝活级别
	exp = (int)me->query("combat_exp",1); 		// 当前exp
	htlvl = (int)me->query_skill("huntian-qigong",1); //混天气功级别

	if ( me->query("family/family_name") != "丐帮" )
		return RANK_D->query_respect(me)+"不是本帮弟子，何有此问？ ";

	if ( me->query_temp("sd_target"))
		return RANK_D->query_respect(me)+"我不是让你去找"+me->query_temp("sd_target")+"了吗？快去吧。";

	if ( bags >= 3 )
		return RANK_D->query_respect(me)+"已经技压群雄了，不知功劳多少。";

	if ( bg_lvl < 60 && bags >= 2 )
		return RANK_D->query_respect(me)+"的叫化绝活等级还不够，要多多加油！";

	if ( bg_lvl < 30 || bags < 1)
		return RANK_D->query_respect(me)+"在帮中资历尚浅，叫化绝活等级还不够，不能升袋。";

	if ( me->set_temp("sd_target"))
		return "还不快去？";

        target = names[bags-1][random(sizeof(names[bags-1]))];
        me->set_temp("sd_target", target);
        return "好吧，你若要升袋，需得先弄点成绩出来，你去把" + target +CYN"给我找来。";
}

int promotion_checking(object who, object ob)
{
	int bag,exp;
	if ( who->query("family/family_name") != "丐帮" )
		return 0;
	if ( ob->query("name") != (string)who->query_temp("sd_target")) {
		command("say 这东西我要来没用。");
		return 0;
	}
	if (userp(ob)) {
		command("say " + RANK_D->query_rude(who) +"，居然敢欺骗本舵主，拿命来把！");
		return 0;
	}

	bag=(int)who->query("gb/bags",1);
	exp=(bag*500);
	who->add("gb/bags",1);
	who->add("max_neili",10);
	who->add("combat_exp",exp);

	command("nod " + who->query("id"));
	command("say 干得好！从今天开始，你就升为"+chinese_number(who->query("gb/bags")) + "袋弟子，好好干！\n");
	who->set("title",sprintf("丐帮%s%s袋弟子", who->query("gb/fenduo"),chinese_number(who->query("gb/bags"))));
	who->delete_temp("sd_target");
	return 1;
}

int ask_bag()
{
    	object me = this_player();
    	int i, bag ,lvl;
    	mapping skl;
    	string *sname, fenduo;

	bag = me->query("gb/bags");
	lvl = bag - 2 ;
	fenduo = me->query("gb/fenduo");

	if (me->query("family/family_name")!="丐帮" ) {
		command("say " + RANK_D->query_respect(me) + "与我丐帮素无来往，此话不知从何说起。\n");
		return 1;
	}
	if ( bag < 3 ){
		command("say " + RANK_D->query_respect(me) + "在帮中职位太低，先加油升袋吧。\n");
		return 1;
	}
	if (bag == 9 ){
        	command("say " + RANK_D->query_respect(me) + "在帮中已是九袋长老，还想升到哪里去？\n");
		command("sneer "+me->query("id"));
		if (!me->query("title"))
			me->set("title",HIW"丐帮九袋长老"NOR);
		return 1;
	}
	if ((int)me->query("shen") < 100000 * lvl ){
		command("say 我丐帮乃堂堂名门正派，"+RANK_D->query_respect(me) +"是否应该多做点侠义之事。");
		return 1;
	}
	if ((me->query_skill("huntian-qigong",1)) < (bag+1) * 25 ){
		command("say 混天气功是我派武功的根基，"+RANK_D->query_respect(me) +"若想成为"+chinese_number(bag+1)+"袋弟子，至少要达到 "+chinese_number((bag+1)*25)+" 级才可以。");
		return 1;
	}
	if ((me->query("job_time/丐帮") + me->query("job_time/报效国家") + me->query("job_time/抓蛇")) <  200 * bag ) {
		command("say 我丐帮乃堂堂名门正派，"+RANK_D->query_respect(me)	+"应该为国为民多做点贡献才好。");
		command("say 没事的时候多去帮帮陈、鲁、吴三位长老吧。");
		return 1;
	}

	skl = me->query_skills();
	if (mapp(skl)) sname = keys(skl);

	for(i=0; i<sizeof(skl); i++){
		if (SKILL_D(sname[i])->type2() == "worker") continue;
		if ( me->query_temp("user_type") =="worker" && skl[sname[i]] >= 200) continue;
		me->set_skill(sname[i],skl[sname[i]] + 1);
		if (me->query_skill("bangjue", 1) > 200)
			me->set_skill("bangjue", 200);
		if (me->query_skill("begging", 1) > 200)
			me->set_skill("begging", 200);
		if (me->query_skill("stealing", 1) > 200)
			me->set_skill("stealing", 200);
		if (me->query_skill("dagou-zhen", 1) > 200)
			me->set_skill("dagou-zhen", 200);
		if (me->query_skill("checking", 1) > 200)
			me->set_skill("checking", 200);
		if (me->query_skill("literate", 1) > me->query("int") * 10)
			me->set_skill("literate", me->query("int") * 10);
	}
/*
	for(i=0; i<sizeof(sname); i++){
		if( me->query_skill(skilllimit[i]) > lvllimit[i] )
			me->set_skill(skilllimit[i],lvllimit[i] );
	}
*/
	me->add("gb/bags",1);
	bag = bag + 1;
	me->add("max_neili", 15 * (bag));
	command("congra " + me->query("id"));

	if (bag < 8){
		command("say 干得好！从今天开始，你就是丐帮" + chinese_number(bag) + "袋弟子，好好干！\n");
		me->set("title",sprintf("丐帮%s%s袋弟子", fenduo, chinese_number(bag)));
	}
	else if (bag == 8){
		command("say 干得好！从今天开始，你就是丐帮" + chinese_number(bag) + "袋弟子，好好干！\n");
		me->set("title",sprintf(YEL"丐帮%s%s袋副舵主"NOR, fenduo, chinese_number(bag)));
	}
	else if (bag == 9){
		command("say 干得好！从今天开始，你就是丐帮"+ chinese_number(bag) + "袋长老，好好干！\n");
		me->set("title",sprintf(HIW"丐帮%s袋长老"NOR, chinese_number(bag)) );
	}
	return 1;
}
