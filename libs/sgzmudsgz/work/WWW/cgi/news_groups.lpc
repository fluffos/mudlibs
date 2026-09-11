// news_groups.c by fire on May,2000
// this file is used for user to select news from different groups
mapping groups=([]);
mapping ngroups=([]);
void fill_groups() {
	string myname=mud_name();
	string *gids;
	string n_id,name;
	groups=([]);
	ngroups=([]);
	gids=NEWS_D->get_groups();
	foreach (string gid in gids) {
		name=WEB_D->get_group_name(gid);
		if(!sizeof(name)) continue;
		name+="("+sizeof(NEWS_D->get_messages(gid))+")";
		if(gid[0..6]=="nation.") {
			ngroups[gid]=name;
			continue;
		}
		groups[gid]=name;

	}

}

string main() {
	int i=0;
	string ret="
		<html>
		<head>
		<title>News Groups</title>
		<meta http-equiv='Content-Type' content='text/html; charset=gb2312'>
		
	";
	fill_groups();
	foreach(string gid,string gnm in groups) {
		ret+="<a href='/cgi/news_titles.cgi?="+gid+"' target='titles'>"+gnm+"</a><br>\n";

	}
	ret+="<hr>";
	foreach(string gid,string gnm in ngroups) {
		ret+="<a href='/cgi/news_titles.cgi?="+WEB_D->url_encode(gid)+"' target='titles'>"+gnm+"</a><br>\n";

	}

	ret+= "</body>
		</html> ";
	return ret;
}

