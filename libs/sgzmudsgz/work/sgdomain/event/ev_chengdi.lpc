// ev_chengdi.c
// 
void final_announce(string p_nation);
mixed can_chengdi(string p_nation) {
	int pop;
	string *list;
	pop = COUNTRY_D->get_country(p_nation,"population");
	if(pop<1000000) return "全国人口不足。\n";
	pop = COUNTRY_D->get_country(p_nation,"soldier");
	if(pop<100000) return "全国兵力不足。\n";
	pop = COUNTRY_D->get_country(p_nation,"gold");
	if(pop<100000) return "国库金不足。\n";
	if(CHAR_D->get_char(p_nation,"ju")<7)
		return "国王爵位太低。\n";

	if(COUNTRY_D->get_country(p_nation,"level")==1) return "贵国已经是帝国了。\n";

//  5  不能是附庸国	this will be consider later
	list=CHAR_D->check_char("nation",p_nation);
	list=filter_array(list,(:CHAR_D->get_char($1,"type")==0:));
	if(sizeof(list)<100) 
		return "将领(三国中的真实人物)人数不够。\n";
	return 1;
}


void chengdi_announce(string s) {
	replace_string( s, "%^RESET%^", "%^RESET%^%^H_GREEN%^");
	tell(users(),"%^H_GREEN%^【称帝】"+s+"%^RESET%^");
}
void clear_nation_position(string p_nation) {
	string *list,area;

	area=CHAR_D->get_char(p_nation,"area");
	chengdi_announce("南化老仙：昨日夜观星相，"+AREA_D->get_area(area,"name")+
       "上空帝星灿烂，当有真龙天子降临。\n");


	area=AREA_D->get_area(p_nation,"area");
	list=CHAR_D->check_char("nation",p_nation);
	list=filter_array(list,(:CHAR_D->get_char($1,"ranknation")>1:));
	foreach (string id in list) {
		CHAR_D->set_char(id,"ranknation",0);
	}
	return;
}
void increase_safe(string p_nation) {
	string *list,a;
	int safe;
	a=CHAR_D->get_char(p_nation,"area");

	chengdi_announce("汉献帝：昨夜梦见一长蛇从"+AREA_D->get_area(a,"name")+
		"升起，落下后啃朕之左足。\n");


	chengdi_announce("国舅董承：此不详之兆，只怕"+AREA_D->get_area(a,"name")+
		CHAR_D->get_char(p_nation,"name")+"有异心。\n");
	chengdi_announce("汉献帝：唉！\n");

	list=AREA_D->check_area("nation",p_nation);
	foreach(string s in list) {
		AREA_D->set_area(s,"safe",AREA_D->get_area(s,"safe")+10);
	}


}
void increase_loyalty (string p_nation) {
	string *list,a;
	int loy;
	a=CHAR_D->get_char(p_nation,"area");
	if(a=="changan") 
		chengdi_announce("长安童谣：长安有双王，二王升天盛世长。\n");
	else
		chengdi_announce(AREA_D->get_area(a,"name")+"童谣：长安一个王，"+
			AREA_D->get_area(a,"name")+"一个王，二王升天盛世长。\n");

	list=CHAR_D->check_char("nation",p_nation);
	foreach(string s in list) {
		CHAR_D->set_char(s,"loyalty",CHAR_D->get_char(s,"loyalty")+10);
	}
}
void refuse (string p_nation,int ts) {
	string nm=CHAR_D->get_char(p_nation,"name");
	if(ts==1) {
		chengdi_announce(nm+"：此是不可乱讲，吾身为汉臣，岂可做此不忠之事。\n");
		return;
	}
	else
		chengdi_announce(nm+"：话虽如此，但天道无常，不可尽信。\n");
}
void pleed(string p_nation,int ts) {
	string *list;
	string id1,id2,id3;
	string name,nm;
	list=CHAR_D->check_char("nation",p_nation);
	list-=({p_nation});
	id1=list[random(sizeof(list))];
	list-=({id1});
	id2=list[random(sizeof(list))];
	list-=({id2});
	id3=list[random(sizeof(list))];

	nm=CHAR_D->get_char(p_nation,"name");
	if(ts==1) {
		name=CHAR_D->get_char(id1,"name");
		chengdi_announce(name+"：吾王万岁，臣有一句话不知当讲不当讲。\n");
		chengdi_announce(nm+"：请讲。\n");
		chengdi_announce(name+"：大王英明神武，虽尧舜不过如此，今天下三分归之有二，何不龙袍加. . .\n");
		return;
	}
	if(ts==2) {
		name=CHAR_D->get_char(id1,"name")+"，"+
		CHAR_D->get_char(id2,"name")+"，"+
		CHAR_D->get_char(id3,"name");
		chengdi_announce(name+"：大王不必过虑，今天像，童谣皆应此事，吾主岂可逆天行事。\n");
		return;
	}
	chengdi_announce("众"+COUNTRY_D->get_country(p_nation,"name")+"将官其声道：今汉朝黯弱，汉帝无能，致使天下不平，连年征战，民不聊生。\n");
	chengdi_announce("大王上应天意，下顺民心，平定四海，救百姓于水火，此天大幸也。\n");
	chengdi_announce(nm+"沉吟不语。\n");
	return;
}
void agree(string p_id,int ts) {
	string dis;
	string ns=CHAR_D->get_char(p_id,"name");
	switch(ts) {
		case 1:
		dis=ns+"沉吟半晌，猛然抬头道：好吧就依你们的。
        说罢从口袋里掏出一张揉得皱巴巴的纸，清清嗓子，朗声读道：";
		break;
		case 2:
		dis="    朕闻昔者帝尧禅位于虞、舜，舜亦以命禹。周德不兴，秦以火德替之。
        嬴政暴虐，高祖遂斩白蛇起于泗水，咸有汉室。故天命不于常，惟归";
		break;
		case 3:
		dis="有德。今汉道陵迟，世失其序，四民流徙，托身他方，携白首于山野，
        弃稚子于沟壑，顾故乡而哀叹，向阡陌而流涕，饿厄困苦，亦已甚矣。";
		break;
		case 4:
		dis="    大乱兹昏，兵戈纷起，群凶肆逆，宇内颠覆。奸王嘿嘿，匹夫狂狷，
        行不垄义。窃据郢梁，侵夺荆益，聚党众于湘渑，谋夺天下。老朽子龙，";
		break;
		case 5:
		dis="    拥甲兵于河汉，虎耽中原，虽则气愤风云，志安社稷，终为君孤臣寡，无
        力回天。";
		break;
		case 6:
    		dis="    朕先考弘烈，人神告征，皇灵降瑞，诞维亮彩，因天下之失望，顺宇
        内之推心，爰举义旗，誓清妖孽。起事于徐青之际，淮扬震惊，北击袁绍，";
		break;
		case 7:
		dis="南荡孙坚，东平陶谦，西灭曹操。麾毫所指，无不披靡，金矛之至，俱为
        土齑。南连百越，北尽三河，铁骑成群，玉轴相接。海陵红粟，仓储之积";
		break;
		case 8:
		dis="靡穷，江浦黄旗，治平之功何远。班声动而北风起，剑气冲而南斗平，喑呜
        则山岳崩颓，叱咤则风云变色。";
		break;
		case 9:
		dis= "   今受德坤至，欲靖天下。朕以天命不可以不答，祖业不可以久替，四海
        不可以无主。率土式望，在朕一人。"+ns+"畏天明命，又恐国祚将湮于地，谨

        择元日，与百寮登坛受皇帝玺绶，告类于天神，惟神乡祚于"+
		AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"name")+"，永绥四海。";
		break;
		case 10:
		dis=ns+"读毕，负手而立，凝望远山，只觉得天下英雄舍我其谁。";
		break;
		case 11:
		dis="汉献帝闻毕大哭，大叫一声：天亡我也，昏迷不醒人世。";
		break;
	}
	chengdi_announce(dis+"\n");

}
void chengdi_step(string p_nation,int step) {
	switch(step) {
		case 1:	clear_nation_position(p_nation);break;
		case 2:	increase_loyalty(p_nation);	break;
		case 3: increase_safe(p_nation); break;
		case 4: pleed(p_nation,1); break;
		case 5: refuse(p_nation,1); break;
		case 6: pleed(p_nation,2); break;
		case 7: refuse(p_nation,2); break;
		case 8: pleed(p_nation,3); break;
		case 9: agree(p_nation,1); break;
		case 10: agree(p_nation,2); break;
		case 11: agree(p_nation,3); break;
		case 12: agree(p_nation,4); break;
		case 13: agree(p_nation,5); break;
		case 14: agree(p_nation,6); break;
		case 15: agree(p_nation,7); break;
		case 16: agree(p_nation,8); break;
		case 17: agree(p_nation,9); break;
		case 18: agree(p_nation,10); break;
		case 19: agree(p_nation,11); break;
		case 20: break;
		case 21: final_announce(p_nation); break;
		default:
			return;
	}
	step++;
	call_out("chengdi_step",4,p_nation,step);
}
void final_announce(string p_nation) {
	string dis;
	dis=CHAR_D->get_char(p_nation,"name");
	dis+="于"+DAY_D->query_chinese_day()+"称帝。\n";
	chengdi_announce(dis);
	HIS(dis);
	
}
mixed do_chengdi(string p_nation) {
	int pop;
	pop=COUNTRY_D->get_country(p_nation,"gold");
	COUNTRY_D->set_country(p_nation,"gold",pop-100000);
	pop=CHAR_D->get_char(p_nation,"reputation"); // p_nation is the king's id
	CHAR_D->set_char(p_nation,"reputation",pop*2);
	COUNTRY_D->set_country(p_nation,"level",1);
	call_out("chengdi_step",1,p_nation,1);
}

