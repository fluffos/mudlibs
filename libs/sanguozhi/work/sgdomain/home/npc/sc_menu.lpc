//qb.c this is used to give qb command by fire on Jan 1999

#include <menu.h>
#include <mudlib.h>
#include <verb.h>
#include <ppl.h>
inherit __DIR__+"free_menu";

void do_getmeat()
{
	object o_h,o;
	mixed ret;
	o=slave;
	o_h=SGHOME(p_id);
	ret=o_h->has_chufang();

	modal_pop();
	poped=0;

	master->targetted_action("$N对$T道：$S饿了，回家去拿些吃的来。\n",o);

        DELAY_D->delay_simple_action(o,"$N道：遵命！\n",1);

	if(!stringp(ret)&&(MONEY_D->sub_all_money(master,500)==1)) {
		master->add_food(500);
	        DELAY_D->delay_targetted_action(o,master,
			"$N转身端来一碗烧肉给$T递上。\n",2);
		DELAY_D->delay_simple_action(master,
			"$N抓起肉只两口便吃完了。\n",3);
		DELAY_D->delay_targetted_action(master,o,
			"$N把空碗还给$T。\n",4);
	}
	else {
		if(!stringp(ret))
			ret="没钱买米了";
	        DELAY_D->delay_targetted_action(o,master,
			"$N对$T道：报告$R，家里"+ret+"，所以没有吃的。\n",2);
		DELAY_D->delay_simple_action(master,
			"$N勒了勒腰带，看来又得要饭了。\n",3);
	        DELAY_D->delay_simple_action(o,"$N躲在一旁偷偷地笑着。\n",4);
		DELAY_D->delay_targetted_action(master,slave,
			"$N一脚踢到$T的屁股上，混帐的$r，给我滚下去。\n",5);

	}
	call_out("quit_menu_application",6);
}

void do_gethorse()
{
	object env=environment(master),o_h;
	object o=slave;
	mixed m_wear;
	m_wear=CHAR_D->get_char(p_id,"wear");
	if(!m_wear) m_wear=([]);
	
	modal_pop();
	poped=0;
	master->targetted_action("$N对$T道：$S要远行，快些牵马来。\n",o);
	if(!m_wear["horse"]) {
        	DELAY_D->delay_targetted_action(o,master,
				"$N对$T小声道：$R想必是胡涂了，您还没有坐骑呢。\n",1);
		DELAY_D->delay_simple_action(master,"$N一脸茫然。\n",2);
		call_out("quit_menu_application",3);
		return;
	}
	if(env->is_troop()){
	        DELAY_D->delay_targetted_action(o,master,
			"$N对$T小声道：在军中，$R的马小的可不敢乱牵。\n",1);
		DELAY_D->delay_simple_action(master,"$N一脸茫然。\n",2);
		call_out("quit_menu_application",3);
		return;
	}

	if(env->is_indoors()){
	        DELAY_D->delay_targetted_action(o,master,
			"$N对$T小声道：$R想必是胡涂了，此处牵马多有不便。\n",1);
		DELAY_D->delay_simple_action(master,"$N一脸茫然。\n",2);
		call_out("quit_menu_application",3);
		return;
	}
	if(env->is_horse()){
	        DELAY_D->delay_targetted_action(o,master,
			"$N对$T小声道：$R想必是胡涂了，您已经骑在马上了。\n",1);
		DELAY_D->delay_simple_action(this_body(),"$N一脸茫然。\n",2);
		call_out("quit_menu_application",3);
		return;
	}
	o_h=OBJ_D->find_my_obj(p_id,m_wear["horse"]);
	if(!objectp(o_h))
		o_h=OBJ_D->clone_obj(m_wear["horse"]);
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
        DELAY_D->delay_targetted_action(o,master,"$N转身牵来$n1p的"+o_h->short()+
		"，把缰绳给$T递上。\n",2);
	DELAY_D->delay_simple_action(master,"$N满意地点了点头。\n",3);
	call_out("quit_menu_application",5);
}

void do_getwine()
{
	poped=0;
	modal_pop();

	if(MONEY_D->sub_poket_money(master,300)==1) {
		master->add_drink(500);
		master->targetted_action(
			"$N对$T道：给你几两银子，$S口渴，快去打些酒来。\n",slave);
	
	        DELAY_D->delay_simple_action(slave,"$N道：遵命！\n",1);
	        DELAY_D->delay_targetted_action(slave,master,
			"$N转身端来一碗酒给$T递上。\n",2);
		DELAY_D->delay_simple_action(master,
			"$N端起酒『咕嘟』一口气喝干了。\n",3);
		DELAY_D->delay_targetted_action(master,slave,
			"$N把空酒碗还给$T。\n",4);
	}
	else {
		master->targetted_action(
			"$N对$T道：$R能不能道对面家里要点水喝。\n",slave);
	
	        DELAY_D->delay_targetted_action(slave,master,
			"$N对$T道，让我要饭去，我可不干，要要你自己去。\n",1);

		DELAY_D->delay_targetted_action(master,slave,
			"$N一脚踢到$T的屁股上，没用的$r，给我滚下去。\n",2);
		
	        DELAY_D->delay_simple_action(slave,"$N道：遵命！\n",3);

	}
    	call_out("quit_menu_application",5);

}


void do_call(string str)
{
    object o_h,o_k;
    string *ids,id;
    o_h=SGHOME(p_id);
	ids=o_h->check_npc("pre_id",str);
    if(!sizeof(ids))  {
	write("你家没有"+str+"。\n");
	return;
    }
	poped=0;
    	modal_pop();
	
	id=ids[0];
	o_k=o_h->load_npc(id);

	o_k->move(master->query_room());
    call_out("quit_menu_application",5);

    master->targetted_action("$N对$T道：$R辛苦一下，把$o叫过来。\n",slave,o_k);

    DELAY_D->delay_simple_action(slave,"$N点头道：是，转身离开了。\n",2);
    DELAY_D->delay_targetted_action(slave,o_k,"$N把$T领来了。\n",3);
    DELAY_D->delay_targetted_action(o_k,master,"$N对$T鞠躬道：站到一旁。\n",3);

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


    add_menu_item(toplevel, new_menu_item("询问情况",	(: do_getinfo :) ,"3"));
    add_menu_item(toplevel, new_menu_item("赏赐物品",	(: get_input_then_call,
		(: do_praise :) ,"赏赐何物：" :) ,"4"));


    add_menu_item(toplevel, new_menu_item("改变ID",	(: get_input_then_call,
		(: do_changeid :) ,"变为何ID：" :) ,"9"));


    add_menu_item(toplevel, new_menu_item("撤职", 	(: get_input_then_call,
	(: do_demote :) ,"确认撤职吗(y/n)？" :) ,"a"));

    add_menu_item(toplevel, new_menu_item("拿酒来",	(: do_getwine :) ,"b"));
    add_menu_item(toplevel, new_menu_item("拿肉来",	(: do_getmeat :) ,"c"));
    add_menu_item(toplevel, new_menu_item("牵马来",	(: do_gethorse :) ,"d"));


    add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, space);
    set_menu_prompt (toplevel, "输入指令[12349q]: ");
}
