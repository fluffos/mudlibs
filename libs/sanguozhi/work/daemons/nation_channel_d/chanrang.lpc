#include <ansi.h>

mixed get_suggest(string n_id,string what);
mixed set_suggest(string n_id, string what, mixed val);
void discuss_suggest(string n_id);
void announce_suggest(string n_id);
void add_suggest(string n_id,string topic,mixed para,string who,string *areas);

mixed do_check_can_chanrang(string who)
{
	if( !wizardp(this_body()) ) 
		return "for wizard test only!\n";
        if( !mapp(COUNTRY_D->get_country(who)) )
                return "只有国王才有权提议禅让！\n";
        else return 1;
}
mixed do_check_chanrang_para(string *para, string who)
{
	string newking;
	object ob;
	mapping tmp;

	if( !arrayp(para)||!sizeof(para)||sizeof(para)!=2 )
		return "错误的格式。\n";
	if( !(newking=para[1])||!mapp(CHAR_D->get_char(newking,"")) )
		return "你要把王位禅让给谁？\n";
	if( !objectp(ob=find_body(newking)) )
		return CHAR_D->get_char(newking,"name")+"现在不在线上，无法禅让给他！\n";
	if( ob->query_literate()<200 )
		return CHAR_D->get_char(newking,"name")+"文学修养太低，恐怕难以担当此重任啊！\n";
	if( CHAR_D->get_char(newking, "reputation")<50000 )
		return CHAR_D->get_char(newking,"name")+"声望不足，恐怕难以服众啊！\n";
	if( CHAR_D->get_char_loyalty(newking,who)!=100 )
		return CHAR_D->get_char(newking,"name")+"并非忠心耿耿之人，不能把你未完的大业交给他！\n";
	if( !mapp(tmp=CHAR_D->get_char(newking,"nc"))||tmp[who]<2000 )
		return CHAR_D->get_char(newking,"name")+"并未为我国有大贡献，不能担当国君之位！\n";
	//Added by suicide for control can't chanrang to npc to avoid punish	
        if (CHAR_D->get_char(newking,"type")==TYPE_NPC)
            return CHAR_D->get_char(newking,"name")+"是个NPC，这样做太草率了吧！\n";  
        
	set_suggest(who, "str", "把国君之位禅让给"+CHAR_D->get_char(newking,"name"));
       	set_suggest(who,"reason","德不服众，且久有隐归田园之心");

	add_suggest(who,"chanrang", ({newking}) , who, ({ }));

	announce_suggest(who);
        call_out("discuss_suggest",2,who);
}	
void do_chanrang(string n_id)
{
	string cc, *list, tmp, his, area;
	mapping data;

	cc = get_suggest(n_id,"para")[0];
	his= CHAR_D->get_char(n_id,"name")+"把国君之位禅让给"+CHAR_D->get_char(cc,"name")+"！\n";
	area=CHAR_D->get_char(cc,"area");
	tell(users(), HIR+his+NOR);
 
        //Added by suicide for penalty king who chanrang 
        if (COUNTRY_D->get_country(n_id,"level")==1)
          {CHAR_D->set_char(n_id,"reputation",CHAR_D->get_char(n_id,"reputation")/4);
           CHAR_D->set_char(cc,"reputation",CHAR_D->get_char(cc,"reputation")*4);}
        else
          {CHAR_D->set_char(n_id,"reputation",CHAR_D->get_char(n_id,"reputation")/2);
           CHAR_D->set_char(cc,"reputation",CHAR_D->get_char(cc,"reputation")*2);}
        //added end 帝国君主让位降3/4声望,因为在独立和称帝时翻了两番,被禅让人4倍
        //          一般君主让位降1/2声望,因为在独立时翻了一番,被禅让人2倍.
        COUNTRY_D->add_country(cc, area);
	list = CHAR_D->check_char("nation", n_id);
	foreach(tmp in list)
		CHAR_D->set_char(tmp, "nation", cc);

	list = AREA_D->check_area("nation",n_id);
	foreach(tmp in list)
		AREA_D->set_area(tmp,"nation", cc);

	data = COUNTRY_D->get_country(n_id,"");
	COUNTRY_D->remove_country(n_id);
	foreach(tmp in keys(data))
		COUNTRY_D->set_country(cc, tmp, data[tmp]);

	CHAR_D->set_char(n_id, "ranknation", 0);
	

	// the old king commits suicide and remove his character.
 
	return;
}
