//qb.c this is used to give qb command by fire on Jan 1999

#include <menu.h>
#include <mudlib.h>
#include <verb.h>
#include <ppl.h>
inherit MENUS;
inherit M_ACCESS;
inherit M_GRAMMAR;
inherit M_GLOB;
MENU toplevel;
MENU_ITEM quit_item;
MENU_ITEM seperator;
MENU_ITEM space;

void do_cut(string cf);
void real_quit();
void do_givepos(string str);
void quit_old_place();
protected object master,slave;
protected int poped;
protected string p_id,n_id,master_id;

protected mapping p_pos=
([ 
  "gj" : ([
		"name" : "老管家",
		"num" : 1, // maximum number for one family
		"type" : ({OLDWOMAN,OLDMAN}), // just old man and old woman can do it
	   ]),
  "nwj" : ([
		"name" : "泥瓦匠",
		"num" : 1, // maximum number for one family
		"type" : ({MIDMAN}), // just old man and old woman can do it
	   ]),
  "zfxs" : ([
		"name" : "帐房先生",
		"num" : 1, // maximum number for one family
		"type" : ({OLDMAN}), // just old man and old woman can do it
		"room" : "zhangfang",
	   ]),

  "dcs" : ([
		"name" : "大厨师",
		"num" : 1, // maximum number for one family
		"type" : ({OLDMAN,OLDWOMAN,MIDMAN,MIDWOMAN}), 
		"room" : "kitchen",
	   ]),

  "sc" : ([
		"name" : "随从",
		"num" : 3, // maximum number for one family
		"type" : ({OLDMAN,OLDWOMAN,MIDMAN,MIDWOMAN,YOUNGMAN,YOUNGWOMAN}), 
	   ]),

]);
string show_pos() {
	string ret,*ps;
	ps=keys(p_pos);
	ret="目前有的职位是：\n";
	foreach(string p in ps) {
		ret+=p_pos[p]["name"]+"("+p+")   ";
	}
	ret+="\n请输入要安排到的职务的ID：";
	return ret;
}		
void do_getinfo()
{
	object o_h;
	string p_info;
	int p_cometime,p_salary;
	o_h=SGHOME(p_id);

	poped=0;
    	modal_pop();
	p_cometime=o_h->get_npc(n_id,"cometime");
	p_salary=o_h->get_npc(n_id,"salary");
	p_info="$N对$T道：回$R，$s到府上已有"+CHINESE_D->chinese_period((time()-p_cometime)*90)+
		"，目前的俸银是："+chinese_number(p_salary)+"两银子一个月。\n";
	master->targetted_action(
		"$N对$T道：$m，你在这里的情况怎么样。\n",slave);

        DELAY_D->delay_targetted_action(slave,master,p_info,2);
	call_out("quit_menu_application",5);
}


void do_stayhere()
{
	object env=master->query_room();
	string r_id;
	object o_h;
	o_h=SGHOME(p_id);
	r_id=env->get_id();
	o_h->set_npc(n_id,"room",r_id);

	modal_pop();
	poped=0;

	master->targetted_action(
		"$N对$T道：$m，今后你没事的时候就在此听候调遣。\n",slave);

        DELAY_D->delay_targetted_action(slave,master,
		"$N对$T躬身道：遵命。\n",2);
	call_out("quit_menu_application",3);
}


void do_praise(string str)
{
    object o_obj;
    mixed m_wear;
    o_obj=present(str,master) ;

    if(!objectp(o_obj)) {
	write("你身上没有"+str+"。\n");
	return;
    }

	poped=0;
    	modal_pop();

    call_out("quit_menu_application",5);

    master->targetted_action("$N对$T道：$R辛苦了，这$O就赏给你吧。\n",slave,o_obj);
    master->targetted_action("$N抵给$T$O。\n",slave,o_obj);

    DELAY_D->delay_simple_action(slave,"$N高兴地跳了起来。\n",2);

    destruct(o_obj);
    o_obj=present(str,master) ;
    if(!objectp(o_obj)) { 
       m_wear=CHAR_D->get_char(p_id,"wear");
       if(mapp(m_wear)) {
          string *ks,*vl,o_id;
          int ps;
          ks=keys(m_wear);
	  vl=values(m_wear);
	  ps=member_array(str,vl);
          if(ps==-1) return;
	  o_id=ks[ps];
	  map_delete(m_wear,o_id);
	  CHAR_D->set_char(p_id,"wear",m_wear);
       }
    }
}

void do_changeid(string str)
{
    object o_h;
    o_h=SGHOME(p_id);
	if(strsrch(str," ")>=0) {
		write("ID 中不能有空格。\n");
		return;
	}

    if((sizeof(str)>8)||(sizeof(str)<3)) {
	write("ID必需是3到8个字母。\n");
	return;
    }
	poped=0;
    	modal_pop();

    o_h->set_npc(n_id,"pre_id",str);
    slave=o_h->update_npc(n_id);

    call_out("quit_menu_application",5);

    master->targetted_action("$N对$T道：$R辛苦了，$S赐予你新的ID："+str+"，记住了吗。\n",slave);

    DELAY_D->delay_simple_action(slave,"$N点头道：记住了。\n",2);
}

void create( )
{
    set_privilege(1);
    toplevel = new_menu("\n请对闲人下达指令：");
    quit_item = new_menu_item("退下", (:quit_old_place:), "q");
    seperator = new_seperator
    ("----------------------------------------------------------------------");
    space = new_seperator
    ("                                                                      ");

    add_menu_item(toplevel, seperator);
    add_menu_item(toplevel, space);
    add_menu_item(toplevel, new_menu_item("在此恭候",	(: do_stayhere :) ,"1"));
    add_menu_item(toplevel, new_menu_item("安排职务",	(: get_input_then_call,
		(: do_givepos :) ,show_pos() :), "2"));

    add_menu_item(toplevel, new_menu_item("询问情况",	(: do_getinfo :) ,"3"));
    add_menu_item(toplevel, new_menu_item("赏赐物品",	(: get_input_then_call,
		(: do_praise :) ,"赏赐何物：" :) ,"4"));

    add_menu_item(toplevel, new_menu_item("改变ID",	(: get_input_then_call,
		(: do_changeid :) ,"变为何ID：" :) ,"9"));

    add_menu_item(toplevel, new_menu_item("开除", (: get_input_then_call,
	(: do_cut :) ,"确认开除吗(y/n)？" :) ,"0"));

    add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, space);
    set_menu_prompt (toplevel, "输入指令[123490q]: ");
}

void start_menu(object m,object s)
{
//	string id;
	master=m;
	slave=s;	
//	p_id=master->query_primary_id();
	p_id=slave->get_master();
	n_id=slave->get_id();
	poped=1;
//	sscanf(file_name(s), "/sgdomain/home/npc_server/%s/%s", master_id, id);
	init_menu_application( toplevel );
	call_out("quit_menu_application",50);

}
void do_givepos(string str) 
{
	string *ps;
	object o_h=SGHOME(p_id);
	int curs,my_typ;
	ps=keys(p_pos);
	if(member_array(str,ps)==-1)
	{
		write("没有"+str+"这个职务。\n");
		return;
	}
	curs=sizeof(o_h->check_npc("pos",str));
	if(p_pos[str]["num"]&&(curs>=p_pos[str]["num"])) {
		write("目前"+p_pos[str]["name"]+"的职位已经满了。\n");
		return;
	}
	my_typ=o_h->get_npc(n_id,"typ");
	if(sizeof(p_pos[str]["type"])&&(member_array(my_typ,p_pos[str]["type"])==-1)) {
		write(slave->short()+"不适合"+p_pos[str]["name"]+"这个职位。\n");
		return;
	}

	if(sizeof(p_pos[str]["type"])&&(member_array(my_typ,p_pos[str]["type"])==-1)) {
		write(slave->short()+"不适合"+p_pos[str]["name"]+"这个职位。\n");
		return;
	}

	poped=0;
	modal_pop();
	call_out("quit_menu_application",7);
	o_h->set_npc(n_id,"pos",str);
	slave=o_h->update_npc(n_id);
	master->targetted_action("$N对$T道：$R劳苦功高，$S升你为"+
		p_pos[str]["name"]+"。\n",slave);
	DELAY_D->delay_simple_action(slave,"$N高兴地跳了起来。\n",2);
	DELAY_D->delay_targetted_action(slave,master,"$N对$T道：遵命。\n",3);

	
}
void kill_me() {
	if(objectp(slave))
		destruct(slave);
	
}
void do_cut(string cf)
{	
	object o_h;
	o_h=SGHOME(p_id);
	if(cf!="y") return;
	poped=0;
	modal_pop();

	master->targetted_action(
		"$N对$T道：家境不比当年，养不起你这许多闲人，你回家去吧，\n",slave);
        DELAY_D->delay_simple_action(slave,"$N道：遵命！\n",2);

        DELAY_D->delay_targetted_action(slave,master,
			"$N一脚踢在$T的屁屁上，印出一个清楚的鞋印。\n",3);
	DELAY_D->delay_simple_action(master,
			"$N疼得嗷嗷直叫。\n",4);
	MONEY_D->sub_all_money(master,10000);

	DELAY_D->delay_targetted_action(master,slave,
			"$N赶紧给$T提了一两金子。\n",5);

	DELAY_D->delay_simple_action(slave,
			"$N愤愤离开了。\n",6);
	o_h->remove_npc(n_id);
	call_out("kill_me",7);
	call_out("real_quit",8);
}

void do_demote(string cf)
{	
	object o_h;
	o_h=SGHOME(p_id);
	if(cf!="y") return;
	poped=0;
	modal_pop();

	o_h->set_npc(n_id,"pos","free");
	slave=o_h->update_npc(n_id);

	master->targetted_action(
		"$N对$T道：听说你对你的活不太满意嘛。\n",slave);
        DELAY_D->delay_simple_action(slave,"$N道：不敢。\n",2);

        DELAY_D->delay_targetted_action(master,slave,
			"$N对$T道：你先休息休息也好。暂时当会闲人吧。\n",3);
	DELAY_D->delay_simple_action(slave,
			"$N道：是。\n",4);

	DELAY_D->delay_simple_action(slave,
			"$N闷闷不乐地退到一边。\n",6);

	call_out("real_quit",8);
}


void quit_old_place() {
	object o_h,o_r;
	string p_rm;

	o_h=SGHOME(p_id);
	
	modal_pop();
	poped=0;
	p_rm=o_h->get_npc(n_id,"room");
	o_r=o_h->load_room(p_rm);
	slave->move(o_r);
	master->targetted_action(
		"$N对$T道：现在没事了，先退下吧。\n",slave);

	DELAY_D->delay_targetted_action(slave,master,
		"$N对$T一鞠躬道：是，然后退下了！\n",2);
	call_out("real_quit",4);
}
void quit_menu_application()
{
	if(poped)
		modal_pop();
	poped=0;
	if (!slave) {real_quit(); return;}
	if(objectp(master)) 
	master->targetted_action(
		"$N对$T道：现在没事了，先退下吧。\n",slave);
	DELAY_D->delay_simple_action(slave,
		"$N一鞠躬道：是，然后退到一边！\n",2);
	call_out("real_quit",4);

}
void real_quit()
{
	if(poped)
		modal_pop();
	remove_call_out("quit_menu_application");

	if(objectp(slave))
		slave->set_busy(0);
    destruct(this_object());
}
