// union_channel_d.c
// this is used for union
// by row on Feb 2000
inherit __DIR__+"union_channel_d/suggest";

nosave protected mapping wiz_listeners=([]);

mixed query_list(string p_nation) {
	string *list;
	list=users()->query_body()->query_primary_id();

	list=filter_array(list, (: stringp($1) :));
	list=filter_array(list,(:CHAR_D->get_char($1,"is_jury")!=1:));
//	if(!wiz_listeners[p_nation])
//		wiz_listeners[p_nation]=({});
//	list-=wiz_listeners[p_nation];
//	list+=wiz_listeners[p_nation];
	return list;
}
void deliever_tell(string p_id,string n_id,string msg) {
	string *list;
	string teller;
	if(!p_id) teller="某人：";
	else teller=CHAR_D->get_char(p_id,"name")+"：";
	if(p_id=="no teller") teller="";
	
	if(!sizeof(msg)) msg="。。。";
	list=query_list(n_id);
	msg="%^H_YELLOW%^【东汉宫廷】"+teller+msg;
	if(msg[<1]!='\n')
		msg+="\n";
	msg=replace_string(msg,"%^RESET%^","%^RESET%^%^H_YELLOW%^");
	msg+="%^RESET%^";
	if(sizeof(list)) {
		foreach(string id in list) 
			tell_user(id,msg);
	}

}

mixed deliever_semote(string p_id,string n_id,string msg)
{
	string p1,p2;
	int n;
	mixed ss;
	object o;
	if(!msg) {deliever_tell(p_id,n_id,msg); return 0;}
	n=sscanf(msg,"%s %s",p1,p2);
	if(n!=2) {
		ss=SOUL_D->get_soul(msg,"",({}));
		if(arrayp(ss)){
			deliever_tell("no teller",n_id,ss[1][1]);
			return 1;
		}
		return "什么？\n";
	}
	else {
		o=find_body(p2);
		if(!objectp(o))
			o=CHAR_D->find_char(p2);
		if(objectp(o)) {
			ss=SOUL_D->get_soul(p1,"LIV",({o}));
			if(arrayp(ss)) {
				deliever_tell("no teller",n_id,ss[1][2]);
				return 1;
			}
		}
		return "什么？\n";
	}
}

void deliever_emote(string p_id,string n_id,string msg)
{
	deliever_tell("no teller",n_id,CHAR_D->get_char(p_id,"name")+msg);
}
void deliever_secure(string p_id, string n_id, string msg)
{
	string *list, teller;

	list = query_list(n_id);
	list = filter_array(list, (: CHAR_D->get_char($1, "ranknation"):) );

	if(!p_id) teller="某人：";
        else teller=CHAR_D->get_char(p_id,"name")+"：";
        if( p_id=="no teller" ) teller="";
        if(!sizeof(msg)) msg="。。。";

        msg="%^H_YELLOW%^【东汉宫廷】"+teller+msg;
        if(msg[<1]!='\n') msg+="\n";
        msg=replace_string(msg,"%^RESET%^","%^RESET%^%^H_CYAN%^");
        msg+="%^RESET%^";
        if(sizeof(list)) {
                foreach(string id in list)
                        tell_user(id,msg);
        }

}
void add_wiz_listener(string p_id,string n_id) {
	if(!wiz_listeners[n_id])
		wiz_listeners[n_id]=({});
	wiz_listeners[n_id]-=({p_id});
	wiz_listeners[n_id]+=({p_id});
}
void sub_wiz_listener(string p_id,string n_id) {
	if(!wiz_listeners[n_id])
		wiz_listeners[n_id]=({});
	wiz_listeners[n_id]-=({p_id});
}

mixed deliever_enter(string p_id, string msg) {

	string n_id;
	object o;
	if(!msg) msg="";
	if(msg[0]=='+') // wizard regist
	{
		o=find_body(p_id);
		if(!objectp(o)) return "wrong\n";
		if(!wizardp(o)) return "只有巫师及宫廷官员才可收听该频道。\n";
		n_id=msg[1..<1];
		if (n_id == "all") {
                        string *countries = COUNTRY_D->list_countries();
			string country;
			foreach(country in countries)
				add_wiz_listener(p_id, country);
		}
		else {
	                if(!COUNTRY_D->nation_exist(n_id))
	                        return "没有这个国家。\n";
	                add_wiz_listener(p_id,n_id);
		}
		return "ok\n";
	}

	if(msg[0]=='-') // wizard regist
	{
                o=find_body(p_id);
                if(!objectp(o)) return "wrong\n";
                if(!wizardp(o)) return "你要做什么？\n";
                n_id=msg[1..<1];
                if (n_id == "all") {
                        string *countries = COUNTRY_D->list_countries();
                        string country;
                        foreach(country in countries)
				sub_wiz_listener(p_id, country);
                }
                else {
                        if(!COUNTRY_D->nation_exist(n_id))
                                return "没有这个国家。\n";
			sub_wiz_listener(p_id,n_id);
                }
		return "ok\n";
	}
		
	n_id=CHAR_D->get_char(p_id,"nation");
	if(!n_id) return "只有官员才能使用国家频道。\n";
	switch(msg[0]) {
	case '*': // this is a semote
		return deliever_semote(p_id,n_id,msg[1..<1]);
	case ':': // this is an emote;
		deliever_emote(p_id,n_id,msg[1..<1]);
		return 1;
	case '$': // this is a suggestion
		return deliever_suggest(p_id,n_id,msg[1..<1]);
//		return "suggestion not ready\n";
	case '#': // this is a vote
		return deliever_vote(p_id,n_id,msg[1..<1]);
	case '@': // national secure channel by flee Dec 27 1999
		return deliever_secure(p_id,n_id, msg[1..<1]);
	default: 
		deliever_tell(p_id,n_id,msg);
	}
}
int clean_up()
{	return 0;
}
