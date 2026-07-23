#define DATA_PATH "/data/party/"
#define ID "party/id"
#define NAME "party/name"
#define CREATING "party/creating"
#define JOINING "party/joining"
#define JOINED "party/joined"
#define LEVEL "party/level"
#define MASTER 1
#define SUBMASTER 2
#define LEADER 3
#define MEMBER 4
#define OUT 5
#define MASTER_NICK "nick/master"
#define SUBMASTER_NICK "nick/submaster"
#define LEADER_NICK "nick/leader"
#define MEMBER_NICK "nick/member"
#define MASTER_NUM "num/master"
#define SUBMASTER_NUM "num/submaster"
#define LEADER_NUM "num/leader"
#define MEMBER_NUM "num/member"
#define PLACE "place"


int del_member(object ob,int level);
int in_home(object ob);
int party_rant(object me,string pname,string pid,int level)
{
	me->set(NAME,pname);
	me->set(ID,pid);
	me->set(LEVEL,level);
} 
int add_member(object ob,string pname,string pid,int level)
{
	object party,master;
	string *member,slevel;
	int limite;
	party=new("/d/obj/party");
	party->set(ID,pid);
	party->restore();
	if(level==MASTER) {
		slevel="master";
		limite=party->query(MASTER_NUM);
	}
	if(level==SUBMASTER) {
		slevel="submaster";
		limite=party->query(SUBMASTER_NUM);
	}
	if(level==LEADER) {
		slevel="leader";
		limite=party->query(LEADER_NUM);
	}
	if(level==MEMBER) {
		slevel="member";
		limite=party->query(MEMBER_NUM);
	}
	if(level==OUT) {
		if(master=find_player(party->query("master")[0]))
			master->command("club "+"开除"+ob->query("name")+"出帮。\n");
		tell_object(ob,"你不再是"+ob->query(NAME)+"的一员了。\n");
		del_member(ob,ob->query(LEVEL));
		ob->delete("party");
		return 0;
	}
	member=party->query(slevel);
	if(limite>0 && sizeof(member)+1>limite) {
		write("这个等级的头领已满。\n");
		destruct(party);
		return 0;
	}
	if(member) {
		if(member_array(ob->query("id"),member)>-1) return 0;
		member=member+({ob->query("id")});
	} else {
		member=({ob->query("id")});
	}
	party_rant(ob,pname,pid,level);
	party->set(slevel,member);
	party->save();
	destruct(party);
	return 1;
}
int del_member(object ob,int level)
{	
	string *member1=({}),*member,slevel;
	int i;
	object party;
	party=new("/d/obj/party");
	party->set(ID,ob->query(ID));
	party->restore();
	if(level==MASTER) slevel="master";
	if(level==SUBMASTER) slevel="submaster";
	if(level==LEADER) slevel="leader";
	if(level==MEMBER) slevel="member";
	member=party->query(slevel);
	for(i=0;i<sizeof(member);i++)
		if(member[i]!=ob->query("id")) member1=member1+({member[i]});
	party->set(slevel,member1);
	party->save();
	destruct(party);
	return 1;
}
int in_home(object ob)
{
	object party;
	object env;
	string str;
	party=new("/d/obj/party");
	party->set(ID,ob->query(ID));
	party->restore();
	str=party->query(PLACE);
	destruct(party);
	if(!str) return 1;
	env=environment(ob);
	if(env && env->query(NAME)==ob->query(NAME) && env->query(ID)==ob->query(ID)) return 1;
	return 0;
}
string mapping_level(int level)
{
	if(level==1) return "master";
	if(level==2) return "submaster";
	if(level==3) return "leader";
	if(level==4) return "member";
}
string party_title(object ob)
{
	object party;
	string str;
	if(!ob->query(ID)) return "";
	party=new("/d/obj/party");
	party->set(ID,ob->query(ID));
	party->restore();
	str=party->query("nick/"+mapping_level(ob->query(LEVEL)));	
	destruct(party);
	return str;
}
int master_limite(object ob)
{
	if(ob->query("combat_exp")<5000000) return 0;
	if(ob->query("daoxing")<5000000) return 0;
	return 1;
}
int member_limite(object ob)
{
	if(ob->query("combat_exp")<1000000) return 0;
	if(ob->query("daoxing")<1000000) return 0;
	return 1;

}