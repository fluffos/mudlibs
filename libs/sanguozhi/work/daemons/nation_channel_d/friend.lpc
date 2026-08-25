#include <ansi.h>

mixed get_suggest(string n_id,string what);
mixed set_suggest(string n_id, string what, mixed val);
void discuss_suggest(string n_id);
void announce_suggest(string n_id);
void add_suggest(string n_id,string topic,mixed para,string who,string *areas);

mixed do_check_can_friend(string who)
{
	if( !wizardp(this_body()) )
		return "for test only!\n";
        if( !mapp(COUNTRY_D->get_country(who)) )
                return "只有国王才有权提议结盟\n";
        else return 1;
}
mixed do_check_friend_para(string *para, string who)
{
	int time;
	string cc;
	
	if( sizeof(para)!=3||!stringp(cc=para[1])||!stringp(para[2]) ) 
		return "错误的格式。\n";
	time = to_int(para[2]);
	if( !mapp(COUNTRY_D->get_country(cc)) )
		return "没有这个国家！\n";
	if( cc == who )
		return "不大可能与自己结盟吧？";
	if( COUNTRY_D->is_friend(who, cc) )
		return "你们已经是盟友关系了！\n";
	if( time<=0 )
		return "结盟时间不可能是负数吧？\n";
	if( time>15 )
		return "最长的盟约是十五天。";

	set_suggest(who, "str", "向"+COUNTRY_D->get_country(cc,"name")+"请求结盟");
        set_suggest(who,"reason","结盟是达成国家统一的捷径");

	add_suggest(who,"friend", ({cc, time}), who, ({ }));

	announce_suggest(who);
        call_out("discuss_suggest",2,who);
        return 1;
}	
void do_friend(string n_id)
{
	int time;
	string his, cc;
	
	cc = get_suggest(n_id, "para")[0];
	time = get_suggest(n_id, "para")[1];
	his = HIC+COUNTRY_D->get_country(n_id,"name")+"向"
		+COUNTRY_D->get_country(cc,"name")+"送去了一封结盟"+
		chinese_number(time)+"天的协议书！\n\n"+NOR;
	tell(users(), his );

	if( mapp(get_suggest(cc,0))&&sizeof(get_suggest(cc,0)) ){
		his = COUNTRY_D->get_country(cc,"name")+"正在讨论军国大事，结盟的事被忽略了！\n";
		tell(users(), his );
		return;
	}
	add_suggest(cc,"answer_friend", ({n_id, time}), 0, ({ }));
	set_suggest(cc, "str", "同"+COUNTRY_D->get_country(n_id,"name")+"结盟"+chinese_number(time)+"天");
	set_suggest(cc,"reason",COUNTRY_D->get_country(n_id,"name")+"向我国提出了结盟的请求");
	announce_suggest(cc);
        call_out("discuss_suggest",2,cc);

        return;
}
void do_answer_friend(string n_id)
{
	int time;
	string cc, his;
	mapping ff;

	cc = get_suggest(n_id, "para")[0];
        time = get_suggest(n_id, "para")[1];
	his = COUNTRY_D->get_country(n_id,"name")+"与"+COUNTRY_D->get_country(cc,"name")+
		"达成了结盟"+chinese_number(time)+"天的协议！";
	tell(users(), HIR+his+NOR);

	ff = COUNTRY_D->get_country(n_id,"friends");
	if( !mapp(ff)||!sizeof(ff) ) ff = ([ ]);
	ff[cc] = time()+time*86400;
	COUNTRY_D->set_country(n_id,"friends", ff);

	return;
}
