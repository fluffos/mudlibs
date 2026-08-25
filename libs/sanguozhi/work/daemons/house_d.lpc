// House daemons, handle house information
// By fire@sgz, 1 Sep 1999
#include <security.h>

#define SAVE_FILE "/data/daemons/house_d"
#define PIC_PATH "/sgdomain/home/pic/"

inherit M_ACCESS;

private mapping houses=([]);
void save_data()
{
	unguarded(1, (: save_object, SAVE_FILE, 1 :));
	return;
}
void create()
{
        unguarded(1, (: restore_object, SAVE_FILE, 1 :));
        return;
}
string *list_houses()
{
	return keys( houses );
}
mixed get_house(string str, string para)
{

	if((!str)||(str=="")) return houses;
	if(str=="list") return keys(houses);
	if(!houses[str]) return 0;
	if((!para)||(para=="")) return houses[str];
	
	return houses[str][para];
}
mixed set_house(string str, string para, mixed value)
{
	if(!houses[str]) return "no such house\n";
	if(value==0)
		map_delete(houses[str],para);
	else
		houses[str][para]=value;
	save_data();
	return houses[str];
}
string remove_house(string str)
{
	if(!houses[str]) return "no such house\n";
	map_delete(houses,str);
	save_data();
	return "ok\n";
}
string* check_house(string para_name,mixed para_value)
{       string* ret;
        string* list;
        list=keys(houses);
        ret=filter_array(list, (:houses[$1][$(para_name)]==$(para_value):));
        return ret;
}
void remove() {
	save_data();
}
mixed init_level(string rm,int level) {
	int price,room;
	if(!mapp(houses[rm])) return "no such house\n";
	switch(level) {
		case 0:
			price=20;room=1;break;
		case 1:
			price=100;room=3;break;
		case 2:
			price=500;room=5;break;
		case 3:
			price=1000;room=7;break;
		case 4:
			price=2000;room=10;break;
		default :
			level=5;
			price=5000;room=20;break;
	}
	houses[rm]["level"]=level;
	houses[rm]["price"]=price;
	houses[rm]["room"]=room;
	save_data();
	return houses[rm];
}
void init() {
	string *fs;
	string id;	
	fs=get_dir(PIC_PATH+"*.pic");
	foreach(string f in fs) {
		id=explode(f,".")[0];
		if(!mapp(houses[id]))
			houses[id]=([]);
	}
	save_data();
}
string house_list() {
	string ret="";
	string *ls;
	ret="ID           名    称    等级  价钱   房间\n";
	ret+="-------------------------------------------\n";
	ls=keys(houses);
	foreach(string h in ls) {
		ret+=sprintf("%-12s %-10s %2d   %6d   %2d\n",
			h,houses[h]["name"],
			houses[h]["level"],
			houses[h]["price"],
			houses[h]["room"]);
	}
	return ret;
}
string show_house_pic(string h) {
	string pic;
	pic=read_file(PIC_PATH+h+".pic");
	if(pic[<1]!='\n') pic+="\n";
	return pic;
}
string stat_me(string rm) {
	string ret,h;
	if((!rm)||(rm=="")) rm="list";
	if(rm=="list")
		return house_list();
	if(!houses[rm]) return "没有这种房子。\n";
	h=rm;
	ret=show_house_pic(h);
	ret+="ID           名    称    等级  价钱   房间\n";
	ret+="-------------------------------------------\n";
	ret+=sprintf("%-12s %-10s %2d   %6d   %2d\n",
		h,houses[h]["name"],
		houses[h]["level"],
		houses[h]["price"],
		houses[h]["room"]);
	return ret;
}