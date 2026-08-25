//qb.c this is used to give qb command by fire on Jan 1999

#include <menu.h>
#include <mudlib.h>
#include <verb.h>
#include <ppl.h>
inherit __DIR__+"free_menu";
void do_addcook(string str) {
	string f_name;
	object ob,o_h;
	mixed * cook;
	int val;
	if(OBJ_D->get_obj(str,"type")!="food") {
		write("没有"+str+"这种食物。\n");
		return; 
	}
	f_name=OBJ_D->get_obj(str,"name");
	ob=present(str,master);
	if(!objectp(ob)) {
		write("你身上没有"+f_name+"。\n");
		return;
	}
	o_h=SGHOME(p_id);
	cook=o_h->get_npc(n_id,"cook");
	if(!sizeof(cook)) cook=({"wotou"});
	if(member_array(str,cook)!=-1) {
		write("你的厨师已经会做"+f_name+"了。\n");
		return;
	}
	if(sizeof(cook)>10) {
		write("你的厨师手艺够高，不需要在学新花样了。\n");
		return;
	}
	modal_pop();
	poped=0;
	
	master->targetted_action(
		"$N对$T道：$m，看看这个，能不能学着做呀。说着递给$t$O。\n",slave,ob);

	ob->move(slave);
		
        DELAY_D->delay_targetted_action(slave,master,
		"$N仔细研究着"+f_name+"。\n",2);
	val=OBJ_D->get_obj(str,"value");
	val=val*10+20000;
        DELAY_D->delay_targetted_action(slave,master,
		"$N对$T道：没问题，"+f_name+
		"应该不难做，$R能不能给我"+CHINESE_D->chinese_value(val)+
		"，我出去买些原料来配配看。\n",4);
	if(MONEY_D->sub_poket_money(master,val)==1) {
	        DELAY_D->delay_targetted_action(slave,master,
			"$T对$N道：好，好，这是"+CHINESE_D->chinese_value(val)
			+"，你这就去准备吧。\n",5);
		cook+=({str});
		o_h->set_npc(n_id,"cook",cook);

	}
	else 
	        DELAY_D->delay_targetted_action(slave,master,
			"$T对$N一皱眉头道：要花这么多钱，这事回头再说吧。。\n",5);
	destruct(ob);
	call_out("quit_menu_application",6);
}

void do_reqfood(string str) {
	string f_name;
	object ob,o_h;
	mixed * cook;
	int val;
	
	if(OBJ_D->get_obj(str,"type")!="food") {
		write("没有"+str+"这种食物。\n");
		return; 
	}

	f_name=OBJ_D->get_obj(str,"name");

	o_h=SGHOME(p_id);
	cook=o_h->get_npc(n_id,"cook");
	if(!sizeof(cook)) cook=({"wotou"});
	if(member_array(str,cook)==-1) {
		write("你的厨师还不会做"+f_name+"了。\n");
		return;
	}

	modal_pop();
	poped=0;
	
	master->targetted_action(
		"$N对$T道：$m，听说你的"+f_name+"做得不错。做一"+
		OBJ_D->get_obj(str,"unit")+"给$S尝尝。\n",slave);

	val=OBJ_D->get_obj(str,"value");
	val=val/4;

	if(MONEY_D->sub_all_money(master,val)==1) {
	        DELAY_D->delay_targetted_action(slave,master,
			"$N对$T道：好，好，稍微等一等，我这就做好。\n",2);
		ob=OBJ_D->clone_obj(str);
		ob->move(master);

	        DELAY_D->delay_targetted_action(slave,master,
			"$N对$T道：好了，说着把一"+OBJ_D->get_obj(str,"unit")+
			"刚搞定的"+f_name+"递到$n1p手里。\n",5);

	}
	else 
	        DELAY_D->delay_targetted_action(slave,master,
			"$N对$T一皱眉头道：家里连买米的钱都没有了，哪能做"+f_name+"？\n",2);
	call_out("quit_menu_application",6);

}



void do_askcook() {

	object o_h;
	mixed * cook;
	string msg;
	o_h=SGHOME(p_id);

	cook=o_h->get_npc(n_id,"cook");
	if(!sizeof(cook)) cook=({"wotou"});

	modal_pop();
	poped=0;

	master->targetted_action(
		"$N对$T道：$m，你会做些什么好吃的呀。\n",slave);

	msg="$N对$T鞠躬道：回$R，$s会做以下东西：\n";
	foreach(string s in cook) {
		msg+=OBJ_D->get_obj(s,"name")+"("+s+")\n";
	}


        DELAY_D->delay_targetted_action(slave,master,
		msg,3);
	if(sizeof(cook)<3)
		msg="$N一脚踢到$T的屁股上，蠢材，才会做这么点东西，给我滚下去。\n";
	else if(sizeof(cook)<7)
		msg="$N对$T点点头，不错，但还要努力。\n";
	else
		msg="$n泣不成声地抱着$t说：好你个$n1r真有出息哇！$n0a我总算盼到了这一天呐！\n";

        DELAY_D->delay_targetted_action(master,slave,
		msg,5);

	call_out("quit_menu_application",6);
}


void create( )
{
    set_privilege(1);
    toplevel = new_menu("\n请对大厨师下达指令：");
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

    add_menu_item(toplevel, new_menu_item("改变ID",	(: get_input_then_call,
		(: do_changeid :) ,"变为何ID：" :) ,"9"));

    add_menu_item(toplevel, new_menu_item("撤职", 	(: get_input_then_call,
	(: do_demote :) ,"确认撤职吗(y/n)？" :) ,"a"));

    add_menu_item(toplevel, new_menu_item("询问手艺",	(: do_askcook :) ,"b"));
    add_menu_item(toplevel, new_menu_item("增加手艺",	(: get_input_then_call,
		(: do_addcook :) ,"学做哪东西：" :) ,"c"));

    add_menu_item(toplevel, new_menu_item("点吃的",	(: get_input_then_call,
		(: do_reqfood :) ,"点些什么：" :) ,"d"));

    add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, space);
    set_menu_prompt (toplevel, "输入指令[12345679q]: ");
}