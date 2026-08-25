#include <ansi.h>

string *list_countries();
string set_country(string p_id,string para_name,mixed para_value);
mixed  get_country(string p_id,string para_name);
int is_friend(string n1, string n2);

void check_relation()
{
	string *ns;
	mapping friends,tmp;

	ns = list_countries();

	foreach(string n in ns){
		friends = get_country(n,"friends");
		tmp = friends;
		if( !sizeof(friends) ) continue;
		foreach(string f in keys(friends)){
			if( time()>friends[f] ){
				map_delete(tmp, f);
				tell(users(),HIR+sprintf("【大事记】%s与%s解除同盟．\n",
                                	COUNTRY_D->get_country(n,"name"),COUNTRY_D->get_country(f,"name"))+NOR);
				continue;
			};
			if( member_array(f,list_countries())==-1 ) map_delete(tmp, f);
		}
		set_country(n,"friends", tmp);
	}
}
int is_friend(string n1, string n2)
{
	mapping friends;

	friends = get_country(n1,"friends");
	if( mapp(friends)&&(member_array(n2, keys(friends))!=1) ) return 1;

	friends = get_country(n2,"friends");
	if( mapp(friends)&&(member_array(n1, keys(friends))!=1) ) return 1;

	return 0;
}
