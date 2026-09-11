// web_d.c by fire on May 1999
// this daemons holds most common used web functions

// get a groups chinese name if return "" can't show on the web
string get_group_name(string gid) {
	string n_id;

	if(gid[0..6]=="nation.") {
		n_id=gid[7..<1];
		if(!COUNTRY_D->nation_exist(n_id))
			return "";
		return COUNTRY_D->get_country(n_id,"name")+"留言";
	}

	if(gid=="caolu") return mud_name()+"留言板"; 
	if(gid=="marriage") return "喜结良缘";
	if(gid=="newbie") return "新手帮助"; 
	if(gid=="ranks") return "三国排名"; 
	if(gid=="war") return "三国战火"; 
	if(gid=="progress") return "巫师通告"; 
	return "";
}

int valid_group(string gid) {
	return sizeof(get_group_name(gid));
}
string url_encode(string inp) {
	return replace_string(inp," ","+");	
}
string url_decode(string inp) {
	return replace_string(inp,"+"," ");	
}
