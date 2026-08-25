#include <ansi.h>

mixed get_suggest(string n_id,string what);
mixed set_suggest(string n_id, string what, mixed val);
void discuss_suggest(string n_id);
void announce_suggest(string n_id);
void add_suggest(string n_id,string topic,mixed para,string who,string *areas);

mixed do_check_can_surrender(string who)
{
        if( !mapp(COUNTRY_D->get_country(who)) )
                return "只有国王才有权提议投降！\n";
        else return 1;
}
mixed do_check_surrender_para(string *para, string who)
{
	string cc, area, *areas;
	
	area = CHAR_D->get_char(who,"area");
	do_check_can_surrender(who);
	if( !sizeof(para)||sizeof(para)!=2||!stringp(cc=para[1]) ) return "错误的格式。\n";
	if( !mapp(COUNTRY_D->get_country(cc)) ) return "没有这个国家！\n";
	if( COUNTRY_D->get_country(who,"init_time") >= (time() - 5*24*3600) ) //独立少于5天
		return "你才开疆立国，怎能轻言投降？\n";
	areas = AREA_D->check_area("nation",who);
	if( sizeof(areas)>2 ) return "你尚有数城之地，怎能轻言投降？\n"; 
	areas = AREA_D->check_area("nation",cc);
	if( sizeof(areas)<10 ) return "对方亦非强国，这个选择不太明智吧？\n";
	if( (COUNTRY_D->get_country(cc,"soldier")/5)<COUNTRY_D->get_country(who,"soldier") )
		return "两国胜败还是未知数，怎可向对方屈服呢？\n";
	if( (COUNTRY_D->get_country(cc,"population")/5)<COUNTRY_D->get_country(who,"soldier") )
		return "两国胜败还是未知数，怎可向对方屈服呢？\n";
	foreach(string aa in areas){
		if( AREA_D->get_distance(area, aa)!=1 )continue;

		set_suggest(who, "str", "举国向"+COUNTRY_D->get_country(cc,"name")+"投降");
                set_suggest(who,"reason","国势虚弱");

		add_suggest(who,"surrender",({cc}), who, ({area}));

		announce_suggest(who);
        	call_out("discuss_suggest",2,who);
        	return 1;
        } 
	
	return "两国距离太远，投降了也没什么好处！\n";
}	
void do_surrender(string n_id)
{
	string cc, *list, tmp, his;
	mixed wear;
	cc = get_suggest(n_id,"para")[0];
	his= COUNTRY_D->get_country(n_id,"name")+"举国向"+COUNTRY_D->get_country(cc,"name")+"投降！\n";

	CHAR_D->set_char(n_id, "reputation", to_int(CHAR_D->get_char(n_id,"reputation")/10));
	CHAR_D->set_char(n_id, "gold",CHAR_D->get_char(n_id,"gold")/5 );
	CHAR_D->set_char(n_id,"h",0);

	wear=CHAR_D->get_char(n_id,"wear");
	if(mapp(wear)) {
		map_delete(wear,"weapon");
		map_delete(wear,"horse");
		CHAR_D->set_char(n_id,"wear",wear);
	}

	list = CHAR_D->check_char("nation", n_id);
	foreach(tmp in list){
		CHAR_D->set_char(tmp, "nation", cc);
		CHAR_D->set_char(tmp, "ranknation", 0);
		CHAR_D->set_char(tmp, "reputation", 
                        to_int(CHAR_D->get_char(tmp,"reputation")*0.8));
	}
	list = AREA_D->check_area("nation",n_id);
	foreach(tmp in list){
		AREA_D->set_area(tmp,"nation", cc);
	}
	//Added by suicide for penalty king who chanrang 
        /*if (COUNTRY_D->get_country(n_id,"level")==1)
          {CHAR_D->set_char(n_id,"reputation",CHAR_D->get_char(n_id,"reputation")/5);
           CHAR_D->set_char(n_id,"gold",CHAR_D->get_char(n_id,"gold")/3);}
        else
          {CHAR_D->set_char(n_id,"reputation",CHAR_D->get_char(n_id,"reputation")/10*4);
           CHAR_D->set_char(cc,"gold",CHAR_D->get_char(cc,"gold")/2);}*/
        //added end 帝国君主投降降%80声望,金降2/3
        //          一般君主让位降%60声望,金降1/2.

	COUNTRY_D->remove_country(n_id);
	tell(users(), HIR+his+NOR);
	return;
}
