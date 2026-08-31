//  Tirun Times
//  News System
//  By Whit

#define EDITOR ""
#define REPORTERS ({  })

mapping a;

void create() {
	a=([]);
}

int is_member(string s) {
	if(wizardp(find_player(s))) return 1;
	if(member_array(s, REPORTERS) == -1 && s != EDITOR) return 0;
	if(!a[s]) return 0;
	return 1;
}

int add_article(string user, string title, string contents) {
	if(!is_member(user)) return 0;
	if(!a[user]) a[user] = ([]);
	if(!a[user]["articles"]) a[user]["articles"] = ([]);
	if(a[user]["articles"][title]) return 0;
	a[user]["articles"][title]=([]);
	a[user]["articles"][title]["title"]=title;
	a[user]["articles"][title]["contents"]=contents;
	a[user]["articles"][title]["time"]=time();
	return 1;
}

int remove_article(string user, string title) {
	if(!is_member(user)) return 0;
	if(!a[user]) return 0;
	if(!a[user]["articles"]) return 0;
	if(!a[user]["articles"][title]) return 0;
	map_delete(a[user]["articles"], title);
}

mapping get_article(string user, string title) {
	if(!is_member(user)) return 0;
	if(!a[user]["articles"][title]) return 0;
	return a[user]["articles"][title];
}

string *get_members() {
	return REPORTERS + keys(a) + ({ EDITOR });
}

string *get_user_articles(string user) {
	if(!is_member(user)) return 0;
	return keys(a[user]["articles"]);
}

int add_user(string user) {
	if(is_member(user)) return 0;
	a[user] = ([]);
	a[user]["articles"] = ([]);
	a[user]["created"] = time();
	return 1;
}

int remove_user(string user) {
	if(!a[user]) return 0;
	map_delete(a, user);
	return 1;
}
