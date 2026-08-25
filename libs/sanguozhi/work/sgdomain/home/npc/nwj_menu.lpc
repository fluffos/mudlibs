//qb.c this is used to give qb command by fire on Jan 1999

#include <menu.h>
#include <mudlib.h>
#include <verb.h>
#include <ppl.h>
#include <edit.h>
inherit __DIR__+"free_menu";

protected mapping r_typ=
([ 
  "path" : ([
		"name" : "%^YELLOW%^走廊%^RESET%^",
		"money" : 2, // 2 gold each
	   ]),
  "bedroom" : ([
		"name" : "%^YELLOW%^卧房%^RESET%^",
		"money" : 10, // 2 gold each
		"num" : 1,
	   ]),

  "bingying" : ([
		"name" : "%^BLUE%^兵营%^RESET%^",
		"money" : 50, // 2 gold each
		"num" : 4,
	   ]),

  "kitchen" : ([
		"name" : "%^GREEN%^厨房%^RESET%^",
		"money" : 10, // 2 gold each
		"num" : 1,
	   ]),

  "malang" : ([
		"name" : "%^GREEN%^马廊%^RESET%^",
		"money" : 10, // 2 gold each
		"num" : 1,
	   ]),
  "liangcang" : ([
		"name" : "%^GREEN%^粮仓%^RESET%^",
		"money" : 30, // 2 gold each
		"num" : 4,
	   ]),

  "cangku" : ([
		"name" : "%^RED%^仓库%^RESET%^",
		"money" : 20, // 2 gold each
		"num" : 1,
	   ]),

  "zhangfang" : ([
		"name" : "%^RED%^帐房%^RESET%^",
		"money" : 10, // 2 gold each
		"num" : 1,
	   ]),

  "shufang" : ([
		"name" : "%^RED%^书房%^RESET%^",
		"money" : 20, // 2 gold each
		"num" : 1,
	   ]),

  "lianwuting" : ([
		"name" : "%^RED%^练武厅%^RESET%^",
		"money" : 30, // 2 gold each
		"num" : 1,
	   ]),

  "keting" : ([
		"name" : "%^GREEN%^客厅%^RESET%^",
		"money" : 40, // 2 gold each
		"num" : 1,
	   ]),

]);

string show_typ() {
	string ret,*ps;
	ps=keys(r_typ);
	ret="目前可建设的房间类型有：\n";
	foreach(string p in ps) {
		ret+=r_typ[p]["name"]+"("+p+")   ";
	}
	ret+="\n请输入要建设的房间类型的ID：";
	return ret;
}		

void done_addroom(string dir,string typ) {
	string *ps;
	object o_h=SGHOME(p_id);
	int curs,path_num,max_num;
	string h_id,here_id,opdir;
	ps=keys(r_typ);
	if(member_array(typ,ps)==-1)
	{
		write("没有"+typ+"这类房间。\n");
		return;
	}
	curs=sizeof(o_h->check_room("t",typ));

	if(r_typ[typ]["num"]&&(curs>=r_typ[typ]["num"])) {
		write("目前"+r_typ[typ]["name"]+"类型房间已经建设满了。\n");
		return;
	}
	path_num=sizeof(o_h->check_room("t","path"));	
	h_id=CHAR_D->get_char(p_id,"h")["id"];
	max_num="/daemons/house_d"->get_house(h_id,"room");
	if(typ=="path") {
		if(path_num>max_num) {
			write("不能再建设更多的走廊了。\n");
			return;
		}
	}
	else {
		if((o_h->get_room("size")-path_num-2)>=max_num) {
			write("你的房子不能再建设更多的功能房间了。\n");
			return;
		}
	}
	if(MONEY_D->sub_all_money(master,r_typ[typ]["money"]*10000)==-1) {
		write("你的钱不够建设新房间了。\n");
		return;
	}
	here_id=master->query_room()->get_id();
	opdir=DIRECTION_D->oppdir(dir);
	o_h->add_room(here_id,dir,opdir,typ,r_typ[typ]["name"]);

	poped=0;
	modal_pop();
	call_out("quit_menu_application",7);

	master->targetted_action("$N对$T道：$S要从这里向"+DIRECTION_D->cdir(dir)+
		"再建设一个"+r_typ[typ]["name"]+"。\n",slave);
	DELAY_D->delay_targetted_action(slave,master,"$N对$T说：要花"+
		chinese_number(r_typ[typ]["money"])+"两金子。\n",2);
	DELAY_D->delay_targetted_action(master,slave,"$N对$T道：没问题。\n",3);
	DELAY_D->delay_targetted_action(slave,master,"$N对$T道：新房间应该很快就建好。\n",4);


}
void do_addroom(string dir) {
	string opdir;
	string t;
	string here_id;
	opdir=DIRECTION_D->oppdir(dir);
	if(!sizeof(opdir)) {
		write(dir+"是无法理解的方向。\n");
		return;
	}
	t=master->query_room()->get_type();
	if((t!="path")&&(t!="hall")) {
		write("只有从门厅或走廊才可以建设新房间。\n");
		return;
	}
	here_id=master->query_room()->get_id();
	if(stringp(SGHOME(p_id)->get_room(here_id,"e")[dir])) {
		write("这个方向以经有房间了。\n");
		return;
	}

	get_input_then_call ((: done_addroom ,dir:) , show_typ());

}
void do_changeroomname(string nam) {
	object o_h=SGHOME(p_id);
	string here_id;
	here_id=master->query_room()->get_id();
	if(sizeof(nam)<1) {	
		write("必需要有个名字。\n");
		return;
	}
	o_h->set_room(here_id,"b",nam);
	o_h->update_room(here_id);

	poped=0;
	modal_pop();
	call_out("quit_menu_application",5);

	master->targetted_action("$N对$T道：$S要把此房间的名称改为"+nam+"。\n",slave);
	DELAY_D->delay_targetted_action(slave,master,"$N对$T道：没问题。\n",2);
	DELAY_D->delay_targetted_action(master,slave,"$N对$T满意地点了点头。\n",3);

}


void done_changeroomdesc( string *lines)
{
	object o_h=SGHOME(p_id);
	string here_id;
	string nam;

	here_id=master->query_room()->get_id();
    if ( !lines )
    {
	    printf("输入中断。\n");
		return;
    }
	nam=implode(lines, "\n");
	nam+="\n";
	o_h->set_room(here_id,"l",nam);
	o_h->update_room(here_id);

	poped=0;
	modal_pop();
	call_out("quit_menu_application",5);

	master->targetted_action("$N对$T道：$S要把此房间的布局改一下。\n",slave);
	DELAY_D->delay_targetted_action(slave,master,"$N对$T道：没问题。\n",2);
	DELAY_D->delay_targetted_action(master,slave,"$N对$T满意地点了点头。\n",3);
    
    
}

void do_changeroomdesc() {
	object o_h=SGHOME(p_id);
	string here_id;
	here_id=master->query_room()->get_id();
	if(here_id=="front") {
		write("这儿的描述不能改。\n");
		return;
	}
    printf("请输入描述\n");

    new(EDIT_OB, EDIT_TEXT, 0, (: done_changeroomdesc:));

}
void do_repairroom() {
	int p_state,p_money;
	object o_here;
	o_here=master->query_room();
	p_state=o_here->get_status();
	if(p_state>80) {
		write("这里现在情况良好，不需要修理。\n");
		return;
	}
	if(p_state==1) {
		write("这里已经没法修了。\n");
		return;
	}
	p_money=(100-p_state)/20;

	if(MONEY_D->sub_all_money(master,p_money*10000)==-1) {
		write("你的钱不够修理房间。\n");
		return;
	}
	poped=0;
	modal_pop();
	o_here->repair();
	call_out("quit_menu_application",7);
	master->targetted_action("$N对$T道：这间屋子长久失修，你把它好好修理一下。\n",slave);
	DELAY_D->delay_targetted_action(slave,master,"$N对$T说：要花"+p_money+"两金子。\n",2);
	DELAY_D->delay_targetted_action(master,slave,"$N对$T道：没问题。\n",3);
	DELAY_D->delay_targetted_action(slave,master,"$N对$T道：房间应该很快就修好。\n",4);
}
void do_destoryroom(string con) {
	object o_h=SGHOME(p_id);
	string here_id,nb_id;
	string *nbs;

	if(con!="y") {
		write("这个问题是要考虑清楚。\n");
		return;
	}
	here_id=master->query_room()->get_id();
	nbs=o_h->get_room(here_id,"e");
	if(sizeof(nbs)>1) {
		write("这个房间有两个以上出口，不能拆。\n");
		return;
	}
	nb_id=nbs[0];
	if((here_id=="front")||(here_id=="enter")) {
		write("这个房间是整坐房的入口，不能拆。\n");
		return;
	}

	if(MONEY_D->sub_all_money(master,20000)==-1) {
		write("你的钱不够拆房间。\n");
		return;
	}
	poped=0;
	modal_pop();
	call_out("quit_menu_application",7);

	o_h->remove_room(here_id);

	master->targetted_action("$N对$T道：$S要把这间房拆掉。\n",slave);
	DELAY_D->delay_targetted_action(slave,master,"$N对$T说：要花"+
		chinese_number(2)+"两金子。\n",2);
	DELAY_D->delay_targetted_action(master,slave,"$N对$T道：没问题。\n",3);
	DELAY_D->delay_targetted_action(slave,master,"$N对$T道：房间已经拆了。\n",4);

}
void create( )
{
    set_privilege(1);
    toplevel = new_menu("\n请对泥瓦匠下达指令：");
    quit_item = new_menu_item("退下", (:quit_old_place:), "q");
    seperator = new_seperator
    ("----------------------------------------------------------------------");
    space = new_seperator
    ("                                                                      ");

    add_menu_item(toplevel, seperator);
    add_menu_item(toplevel, space);
    add_menu_item(toplevel, new_menu_item("在此恭候",	(: do_stayhere :) ,"1"));

    add_menu_item(toplevel, new_menu_item("赏赐物品",	(: get_input_then_call,
		(: do_praise :) ,"赏赐何物：" :) ,"2"));

    add_menu_item(toplevel, new_menu_item("询问情况",	(: do_getinfo :) ,"3"));

    add_menu_item(toplevel, new_menu_item("建设新房间",	(: get_input_then_call,
		(: do_addroom :) ,"新房间的方向：" :) ,"4"));

    add_menu_item(toplevel, new_menu_item("改变房间名称",	(: get_input_then_call,
		(: do_changeroomname :) ,"新的房间名称：" :) ,"5"));

    add_menu_item(toplevel, new_menu_item("改变房间描述",	(: do_changeroomdesc :) ,"6"));

    add_menu_item(toplevel, new_menu_item("拆除房间",	(: get_input_then_call,
		(: do_destoryroom :) ,"确认拆除吗(y/n)？" :) ,"7"));

    add_menu_item(toplevel, new_menu_item("修理房间",	(: do_repairroom :) ,"8"));

    add_menu_item(toplevel, new_menu_item("改变ID",	(: get_input_then_call,
		(: do_changeid :) ,"变为何ID：" :) ,"9"));

    add_menu_item(toplevel, new_menu_item("撤职", 	(: get_input_then_call,
	(: do_demote :) ,"确认撤职吗(y/n)？" :) ,"a"));

    add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, space);
    set_menu_prompt (toplevel, "输入指令[12349q]: ");
}

void start_menu(object m,object s)
{
	master=m;
	slave=s;	
	p_id=master->query_primary_id();
	n_id=slave->get_id();

	poped=1;

	init_menu_application( toplevel );
	call_out("quit_menu_application",50);

}
