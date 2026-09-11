//qb.c this is used to give qb command by fire on Jan 1999

#include <menu.h>
#include <mudlib.h>
#include <verb.h>
inherit MENUS;
inherit M_ACCESS;
inherit M_GRAMMAR;
inherit M_GLOB;
MENU toplevel;
MENU_ITEM quit_item;
MENU_ITEM seperator;

void do_getwine();
void do_cut(string str);
void do_getmeat();
void do_gethorse();
void do_getmoney(string str);
void do_nonsense();
void real_quit();

private object master,o;
private int poped;
private string p_id,n_id;

void do_getwine()
{
	poped=0;
    modal_pop();
	if(objectp(o))
	{
		this_body()->add_drink(500);
		this_body()->targetted_action(
			"$N对$T道：$S口渴，快些拿酒来。\n",o);
        DELAY_D->delay_simple_action(o,"$N道：遵命！\n",1);
        DELAY_D->delay_targetted_action(o,this_body(),
			"$N转身端来一碗酒给$T递上。\n",2);
		DELAY_D->delay_simple_action(this_body(),
			"$N端起酒『咕嘟』一口气喝干了。\n",3);

		DELAY_D->delay_targetted_action(this_body(),o,
			"$N把空酒碗还给$T。\n",4);
	}
	call_out("quit_menu_application",5);
}

void do_getmeat()
{
    modal_pop();
	poped=0;
	if(objectp(o))
	{
		this_body()->add_food(500);
		this_body()->targetted_action(
			"$N对$T道：$S饿了，快些拿肉来。\n",o);
        DELAY_D->delay_simple_action(o,"$N道：遵命！\n",1);
        DELAY_D->delay_targetted_action(o,this_body(),
			"$N转身端来一碗烧肉给$T递上。\n",2);
		DELAY_D->delay_simple_action(this_body(),
			"$N抓起肉只两口便吃完了。\n",3);

		DELAY_D->delay_targetted_action(this_body(),o,
			"$N把空碗还给$T。\n",4);
	}
	call_out("quit_menu_application",5);
}

void do_gethorse()
{
	object env=environment(this_body()),o_h;
	string p_id;
	mixed m_wear;
	p_id=this_body()->query_id()[0];
	m_wear=CHAR_D->get_char(p_id,"wear");
	if(!m_wear) m_wear=([]);
	
    modal_pop();
	poped=0;
	if(objectp(o))
	{
		this_body()->targetted_action(
			"$N对$T道：$S要远行，快些牵马来。\n",o);
		if(!m_wear["horse"]) {
	        DELAY_D->delay_targetted_action(o,this_body(),
				"$N对$T小声道：$R想必是胡涂了，您还没有坐骑呢。\n",1);
			DELAY_D->delay_simple_action(this_body(),
				"$N一脸茫然。\n",2);
			call_out("quit_menu_application",3);
			return;

		}
		if(env->is_indoors()){
	        DELAY_D->delay_targetted_action(o,this_body(),
				"$N对$T小声道：$R想必是胡涂了，此处牵马多有不便。\n",1);
			DELAY_D->delay_simple_action(this_body(),
				"$N一脸茫然。\n",2);
			call_out("quit_menu_application",3);
			return;
		}
		if(env->is_horse()){
	        DELAY_D->delay_targetted_action(o,this_body(),
				"$N对$T小声道：$R想必是胡涂了，您已经骑在马上了。\n",1);
			DELAY_D->delay_simple_action(this_body(),
				"$N一脸茫然。\n",2);
			call_out("quit_menu_application",3);
			return;
		}
		o_h=OBJ_D->find_my_obj(p_id,m_wear["horse"]);
		if(!objectp(o_h))
		{	o_h=OBJ_D->clone_obj(m_wear["horse"]);
		}
		else {
			object *rs,h_env;
			h_env=environment(o_h);
			if(objectp(h_env)&&(h_env!=env)) {
				tell_environment(o_h,o_h->short()+"听到主人的召唤，一溜烟的跑了。\n");
				rs=o_h->get_riders();
			
				if(sizeof(rs)) {
					foreach(object r in rs) {
						r->move(h_env);
						r->simple_action("$N猝不及防，摔了一个大马趴。\n");
					}
				}
			}
		}
		o_h->set_owner(p_id);
		o_h->move(env);
        DELAY_D->delay_simple_action(o,"$N道：遵命！\n",1);
        DELAY_D->delay_targetted_action(o,this_body(),
			"$N转身牵来$n1p的"+o_h->short()+
			"，把缰绳给$T递上。\n",2);
		DELAY_D->delay_simple_action(this_body(),
			"$N满意地点了点头。\n",3);
	}
	call_out("quit_menu_application",5);
}


void do_getmoney(string str)
{
    object o_money;
	int p_money=to_int(str);
	int p_gold=CHAR_D->get_char(p_id,"gold");
	if(p_money<1) p_money=1;
	if(p_gold<p_money)
	{
		write("库里没有那么多钱。\n");
		return;
	}
	poped=0;
    modal_pop();
	CHAR_D->set_char(p_id,"gold",(p_gold-p_money));
	o_money=new(M_GOLD);
    o_money->set_m_num(p_money);
    o_money->move(this_body());
	if(objectp(o))
	{
		this_body()->targetted_action(
			"$N对$T道：拿钱盒来。\n",o);
        DELAY_D->delay_simple_action(o,"$N道：遵命！\n",1);
        DELAY_D->delay_targetted_action(o,this_body(),
			"$N转身捧来一只紫金钱盒。\n",2);
		DELAY_D->delay_simple_action(this_body(),
			"$N从钱盒里拿出"+chinese_number(p_money)+"两金子。\n",3);

		DELAY_D->delay_targetted_action(this_body(),o,
			"$N把钱盒还给$T，嘱咐道：小心收好了。\n",4);
	}
	call_out("quit_menu_application",5);
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
    call_out("quit_menu_application",5);

    this_body()->targetted_action("$N对$T道：兄弟们很辛苦了，这$O就赏给兄弟们吧。\n",o,o_obj);
    this_body()->targetted_action("$N将$O递给$T。\n",o,o_obj);

    DELAY_D->delay_simple_action(o,"$N高兴地跳了起来。\n",1);

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

void do_nonsense()
{
	poped=0;
    modal_pop();
	if(objectp(o))
	{
		this_body()->targetted_action(
			"$N对$T嘀嘀咕咕不知说了些什么。\n",o);
        DELAY_D->delay_simple_action(o,"$N一脸茫然不知所云。\n",1);
	}
	call_out("quit_menu_application",2);
}

void create()
{
    set_privilege(1);
    toplevel = new_menu("\n请对亲兵下达指令：");
    quit_item = new_menu_item("退下", (:quit_menu_application:), "q");
    seperator = new_seperator
    ("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");
    add_menu_item(toplevel, seperator);
    add_menu_item(toplevel, new_menu_item("快拿酒来",	(: do_getwine :) ,"1"));
    add_menu_item(toplevel, new_menu_item("快拿肉来",	(: do_getmeat :) ,"2"));
    add_menu_item(toplevel, new_menu_item("快牵马来",	(: do_gethorse :) ,"3"));
    add_menu_item(toplevel, new_menu_item("快拿钱来",	(: get_input_then_call,
		(: do_getmoney :) ,"拿多少钱[1]：" :) ,"4"));
    add_menu_item(toplevel, new_menu_item("赏赐物品",	(: get_input_then_call,
		(: do_praise :) ,"赏赐何物：" :) ,"5"));
    add_menu_item(toplevel, new_menu_item("去找人",	(: do_nonsense :) ,"6"));
    add_menu_item(toplevel, new_menu_item("准备裁人",	(: get_input_then_call, 
		(: do_cut :), "裁减人数：" :), "0"));

        add_menu_item(toplevel, quit_item);
        add_menu_item(toplevel, seperator);
        set_menu_prompt (toplevel, "输入指令[12340q]: ");
}

void start_menu()
{
	p_id=this_body()->query_id()[0];
	n_id=p_id+" qb";
	poped=1;
	master=this_body();
	o=CHAR_D->find_char(n_id);

	init_menu_application( toplevel );
	call_out("quit_menu_application",50);
}
void do_cut(string str)
{
    int p_realqb,p_qb=to_int(str);
	mixed myarmy;
	if(!p_qb)
	{
		write("很好，不要随便裁人。\n");
		return;
	}
	myarmy=CHAR_D->get_char(p_id,"myarmy");
	p_realqb=myarmy["qbnum"];
	if(p_realqb<p_qb)
	{
		write("你没有那么多亲兵。\n");
		return;
	}

    modal_pop();
	poped=0;
	myarmy["qbnum"]-=p_qb;
	if(objectp(o))
	{
		this_body()->targetted_action(
			"$N对$T道：兄弟们跟本官已久，也该回家看望看望了，\n"+
			"传我话，让"+chinese_number(p_qb)+"个兄弟回家吧。\n",o);
        DELAY_D->delay_simple_action(o,"$N道：遵命！\n",1);
        DELAY_D->delay_targetted_action(o,this_body(),
			"$N一脚踢在$T的屁屁上，印出一个清楚的鞋印。\n",2);
		DELAY_D->delay_simple_action(this_body(),
			"$N疼得嗷嗷直叫。\n",3);
	}
	call_out("quit_menu_application",4);

}

void quit_menu_application()
{
	if(poped)
		modal_pop();
	remove_call_out("quit_menu_application");
	if(objectp(o))
	{
		int p_gold=CHAR_D->get_char(p_id,"gold");
		if(p_gold&&(random(20)==9))
		{
			CHAR_D->set_char(p_id,"gold",p_gold-1);
			this_body()->targetted_action(
				"$N对$T道：从库里提一两金子，给弟兄们买酒去吧。\n",o);
	        DELAY_D->delay_targetted_action(o,this_body(),
				"$N高兴地跳了起来，连连称谢$T的赏赐。\n",1);
	        DELAY_D->delay_simple_action(this_body(),
				"$N接着道：现在没事了，先退下吧。\n",2);
			DELAY_D->delay_simple_action(o,
				"$N道：遵命！\n",3);
			call_out("real_quit",4);
		}
		else
		{
			this_body()->targetted_action(
				"$N对$T道：现在没事了，先退下吧。\n",o);
			DELAY_D->delay_simple_action(o,
				"$N道：遵命！\n",1);
			call_out("real_quit",2);
		}
	}
	else 
		real_quit();
}
void real_quit()
{
	string p_id=this_body()->query_id()[0];
	string n_id=p_id+" qb";
	CHAR_D->remove_char(n_id);
    destruct(this_object());
}
