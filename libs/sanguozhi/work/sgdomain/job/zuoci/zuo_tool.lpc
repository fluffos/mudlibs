#include <mudlib.h>
#include <ansi.h>
#define NCITY "taiyuan"
#define WCITY "longxi"

inherit M_WEAPON;
inherit M_VALUE;

int succ_job(object who, string here);
int find_room(object who, string room, string next);
int find_area(object who, string here, string where);
int find_rooma(object who, string beg, string end,string p_area);
mapping expend_net(mapping net,string beg,string end ,string p_area);

int do_award(object usr, string here);
string *find_path(string STA, string END);

void setup() {
        set_id("magic mirror", HIY+"阴"+HIR+"阳"+NOR+"宝镜", "mirror");
        set_unit("柄");
        set_in_room_desc("一柄左慈特制的"+HIY+"阴"+HIR+"阳"+NOR+"宝镜"+"(magic mirror)");
        set_attack_ability(2);
        set_attack_power(10);
        set_defence_ability(1);
        set_combat_messages("combat-blade");
        set_value(5000);
        set_currency_type("coin");
}
int direct_use_obj()
{
        return 1;
}
int do_use_it()
{ 	mapping job;
	object who, env;
	string here, filename, *names, name;

	who = this_body();
	job = who->query_job("zuo ci", "");
	who->start_busy(3, "你正忙着探索呢！");

        if( who->query_cur_hp() < 20 ){
		write("还是休息一会再干吧。\n");
		return 1;
        } else who->set_cur_hp(who->query_cur_hp()-15);

	if( !job || !mapp(job) || job["beg_time"] <= 0 ){
		who->simple_action("$N装模作样的拿着"+this_object()->short()+"转来转去。\n");
		return 1;
	};

	env = environment(who);
	if( env->is_horse() ){
		write("在马上是不能看风水的。\n");
		return 1;
	};
	here = env->get_area();
	if( !here||here==""||!stringp(here)||here == "huayin" ) {
		write("很显然，不是这儿。\n");
		return 1;
	}
	filename = file_name(env);
	names = explode(filename, "/");
	name = names[sizeof(names)-1];

	if( name == job["room"] ) succ_job(who, here);
	else if( here == job["area"] ) 
		find_rooma(who, name, job["room"],here);
	else find_area(who, here, job["area"]);

	return 1;
}
int succ_job(object who, string here)
{
	string name;

	name = who->query_id()[0];
	who->simple_action("$N满意的点了点头：此处风水极佳，定有良臣猛将！\n");
	write("你的任务完成了！\n");
	who->finish_job("zuo ci");
	ROBOT->robot_test(who, (: do_award :), here);
	
	return 1;
}
int do_award(object usr, string here)
{
	int gold, rep, point;
	string name, *sks, skill;

	name = usr->query_id()[0];
	gold = 22000+random(22000);
	rep  = 140+random(60);
	sks  = keys(usr->get_sg_skills());

	if( usr->query_robot() ){
		write("抱歉，错误的答案，没有任何奖励，下次再努力吧！\n");
		return 2;
	}
	CHAR_D->set_char(name, "reputation",
                        CHAR_D->get_char(name,"reputation")+rep);
        usr->set_all_con_money(usr->query_all_con_money()+gold);
	if( AREA_D->get_area(here, "nation") ){
		CHAR_D->set_char_loyalty(name,AREA_D->get_area(here,"nation"),
			CHAR_D->get_char_loyalty(name,AREA_D->get_area(here,"nation"))+1);
			write("你与"+COUNTRY_D->get_country(AREA_D->get_area(here,"nation"),"name")+"的友好度提高了！\n");
	};
	write("你被奖励了"+chinese_number(gold/100)+"两白银。\n");
	write("你的声望提高了"+chinese_number(rep)+"。\n");

	if( !sks||!arrayp(sks)||!sizeof(sks) ) return 1;
	sks = filter_array(sks, (: SG_SKILL_D->query_type($1)==4 :));
	if( !sks||!arrayp(sks)||!sizeof(sks) ) return 1;
	skill = sks[random(sizeof(sks))];
	point = usr->query_job("zuo ci", "count");
	if( point>200 ) point = 200;
	point = point + 50 + random(50);

	usr->award_exp(point ,skill);
	write("你的%^H_CYAN%^"+SG_SKILL_D->query_name(skill)+"%^RESET%^提高了"
		+chinese_number(point)+"点！\n");

	return 1;
}
int find_area(object who, string here, string where)
{
	int n1, w1, n2, w2, dis;
	string msg;

	n1 = AREA_D->get_distance(here, NCITY);
	w1 = AREA_D->get_distance(here, WCITY);
	n2 = AREA_D->get_distance(where, NCITY);
	w2 = AREA_D->get_distance(where, WCITY);
	dis = (n1-n2)*(n1-n2)+(w1-w2)*(w1-w2);
	
	if( w1 > w2 ) msg = "西";
	else if( w1 < w2 ) msg = "东";
	else msg = "";
	if( n1 > n2 ) msg = msg + "北";
	else if( n1 < n2 ) msg = msg + "南";
	else msg = msg + "";
	if( !msg || msg == "" )msg = "周围";
	else msg = msg + "方";

	if( dis <= 2 )msg = msg + "极近的";
	else if( dis <= 16 ) msg = msg + "不远的";
	else if( dis <= 36 ) msg = msg + "较远的";
	else msg = msg + "极远的";

	this_body()->simple_action("$N一边嘴里发出叽哩咕噜的声音，一边转动着手里的"+this_object()->short()+"。\n");
	write("你发现"+msg+"的城市有点奇异。\n");

	return 1;
}
string *find_path(string STA, string END)
{
        int i, j, k;
        object ob;
        mapping exits;
        string *checked_rooms;
        string *curren_rooms;
        mixed *main_rooms;
        string room;
        string *path;
        string *tmp_curren_rooms;
        string *tmp_checked_curren_rooms;
        mapping *tmp_main_rooms;

        main_rooms = ({ });
        checked_rooms = ({ });
        curren_rooms = ({ });
        ob = load_object( STA );
        exits = ob->query_exits();

        main_rooms = main_rooms + ({ ({exits}), });
        checked_rooms = checked_rooms + ({ STA });
        curren_rooms = values( exits );
        checked_rooms = checked_rooms + curren_rooms;

        while( member_array(END, curren_rooms) == -1 ){
                tmp_checked_curren_rooms = ({ });
                tmp_main_rooms = ({ });
                for( i = 0; i < sizeof(curren_rooms); i++){
                        ob = load_object( curren_rooms[i] );
                        if( !ob || !objectp(ob) )continue;
                        exits = ob->query_exits();
                        tmp_curren_rooms = values( exits );
                        for( j = 0; j < sizeof(exits); j++){
                		if( member_array(tmp_curren_rooms[j], checked_rooms) == -1)
                			checked_rooms = checked_rooms + ({ tmp_curren_rooms[j] });
        			if( member_array(tmp_curren_rooms[j], tmp_checked_curren_rooms) ==-1)
					tmp_checked_curren_rooms = tmp_checked_curren_rooms +({tmp_curren_rooms[j]});
                        };
                        tmp_main_rooms = tmp_main_rooms + ({ exits });
                };
                main_rooms -= ({ tmp_main_rooms }); // - and then + for array
                main_rooms = main_rooms + ({ tmp_main_rooms });
                curren_rooms = tmp_checked_curren_rooms;
        };

        path = ({ });
        room = END;

        for( i = sizeof(main_rooms) - 1; i >= 0; i--){
                tmp_main_rooms = main_rooms[i];
                for( j = 0; j < sizeof(tmp_main_rooms); j++){
                        exits = tmp_main_rooms[j];
                        for( k = 0; k < sizeof(exits); k++){
                                if( room == values(exits)[k] ){
                                        path = path + ({ keys(exits)[k] });
                                        ob = load_object( room );
                                        exits = ob->query_exits();
                        		room = exits[DIRECTION_D->oppdir(path[sizeof(path)-1])];
                                        break;
                                };
                        };
                };
        };

        return path;
}
int find_room(object who, string room, string next)
{
	int nn, ww, dd;
        string ss, *path, msg;

        path = find_path(room, next);

	who->simple_action("$N一边嘴里发出叽哩咕噜的声音，一边转动着手里的"+this_object()->short()+"。\n");
	if( !path || !arrayp(path) || !sizeof(path) ){
		write("但是没有任何发现。\n");
		return 1;
	};
	nn = 0; ww = 0; dd = 0; msg = "";
	foreach(ss in path){
		if( ss == "north" ) nn++;
		else if( ss == "south") nn--;
		else if( ss == "east" ) ww--;
		else if( ss == "west" ) ww++;
		else if( ss == "northwest") {nn++;ww++;}
		else if( ss == "northeast") {nn++;ww--;}
		else if( ss == "southwest") {nn--;ww++;}
		else if( ss == "southeast") {nn--;ww--;}
		else if( ss == "northup")   {nn++;dd--;}
		else if( ss == "northdown") {nn++;dd++;}
		else if( ss == "southup")   {nn--;dd--;}
		else if( ss == "southdown") {nn--;dd++;}
		else if( ss == "eastup")    {ww--;dd--;}
		else if( ss == "eastdown")  {ww--;dd++;}
		else if( ss == "westup")    {ww++;dd--;}
		else if( ss == "westdown")  {ww++;dd++;}
	}
	if( ww > 0 ) msg = "西";
        else if( ww < 0 ) msg = "东";
        else msg = "";
        if( nn > 0 ) msg = msg + "北";
        else if( nn < 0 ) msg = msg + "南";
        else msg = msg + "";
        if( !msg || msg == "" )msg = "周围";
        else msg = msg + "方";

        if( nn*nn+ww*ww <= 4 )msg = msg + "极近的";
        else if(  nn*nn+ww*ww <= 16 ) msg = msg + "不远的";
        else if(  nn*nn+ww*ww <= 36 ) msg = msg + "较远的";
        else msg = msg + "极远的";
	
	if( dd > 0 ) msg = msg + "高处";
	else if( dd < 0 ) msg = msg + "低处";
	else msg = msg + "地方";

	write("你已经找到要找的城市了！\n");
        write("你发现"+msg+"有点奇异。\n");

	return 1;
}

mapping expend_net(mapping net,string beg,string end ,string p_area) {
	string *ls;
	int have_new_leave=0;
	if(!sizeof(net)) { 
		net=([]);
		net[beg]=([]);
		net[beg]["can_exp"]=1;
	}
//	tell_user("fire",sprintf("%O\n",net));
	ls=keys(net);
	if(member_array(end,ls)!=-1) // got it
		  return net;
	foreach(string l in ls) {
	   if(net[l]["can_exp"]) {
	      	mixed exts;
            	string *es,n_room,*tmp;
			net[l]["can_exp"]=0;
	      	exts=AREA(p_area)->get_room(l,"e"); 
			if(sizeof(exts)) {

            	es=keys(exts); 
			foreach(string e in es) {
				n_room=exts[e];
				tmp=explode(n_room,"/");
				n_room=tmp[sizeof(tmp)-1];
				if(member_array(n_room,ls)==-1) { 
					net[n_room]=([]);
					net[n_room]["can_exp"]=1;
					net[n_room]["old"]=l;
					net[l][n_room]=e;
					have_new_leave=1;
				}
			}
		}
		if(have_new_leave)
		return expend_net(net,beg,end,p_area); // recrusive
	   }
	}
	return net; // didn't find it
}

int find_rooma(object who, string beg, string end,string p_area)
{
	int nn, ww, dd;
      	string ss, *path, msg;
	string *rms;
	mapping net=([]);

	net=expend_net(net,beg,end,p_area);
	rms=keys(net);
	
	if(!sizeof(rms)) path=({});
	else {
		string cur=end,tmp;
		path=({});
		while(cur!=beg) {
			if(!mapp(net[cur])) {
				write("就是这个城市，但具体位置还测不出来。在换个房间试验一下。\n");
				return;
			}
			tmp=net[cur]["old"];
			path+=({net[tmp][cur]});
			cur=tmp;
		}
	}
	who->simple_action("$N一边嘴里发出叽哩咕噜的声音，一边转动着手里的"+this_object()->short()+"。\n");
	if( !path || !arrayp(path) || !sizeof(path) ){
		write("但是没有任何发现。\n");
		return 1;
	};
	nn = 0; ww = 0; dd = 0; msg = "";
	foreach(ss in path){
		if( ss == "north" ) nn++;
		else if( ss == "south") nn--;
		else if( ss == "east" ) ww--;
		else if( ss == "west" ) ww++;
		else if( ss == "northwest") {nn++;ww++;}
		else if( ss == "northeast") {nn++;ww--;}
		else if( ss == "southwest") {nn--;ww++;}
		else if( ss == "southeast") {nn--;ww--;}
		else if( ss == "northup")   {nn++;dd--;}
		else if( ss == "northdown") {nn++;dd++;}
		else if( ss == "southup")   {nn--;dd--;}
		else if( ss == "southdown") {nn--;dd++;}
		else if( ss == "eastup")    {ww--;dd--;}
		else if( ss == "eastdown")  {ww--;dd++;}
		else if( ss == "westup")    {ww++;dd--;}
		else if( ss == "westdown")  {ww++;dd++;}
	}
	if( ww > 0 ) msg = "西";
        else if( ww < 0 ) msg = "东";
        else msg = "";
        if( nn > 0 ) msg = msg + "北";
        else if( nn < 0 ) msg = msg + "南";
        else msg = msg + "";
        if( !msg || msg == "" )msg = "周围";
        else msg = msg + "方";
        if( nn*nn+ww*ww <= 4 )msg = msg + "极近的";
        else if(  nn*nn+ww*ww <= 16 ) msg = msg + "不远的";
        else if(  nn*nn+ww*ww <= 36 ) msg = msg + "较远的";
        else msg = msg + "极远的";
	if( dd > 0 ) msg = msg + "高处";
	else if( dd < 0 ) msg = msg + "低处";
	else msg = msg + "地方";
	write("你已经找到要找的城市了！\n");
        write("你发现"+msg+"有点奇异。\n");
	return 1;
}


