//qb.c this is used to give qb command by fire on Jan 1999

#include <menu.h>
#include <mudlib.h>
#include <verb.h>
#include <ppl.h>
inherit __DIR__+"free_menu";


void saltobody(string val) {
	int num,v;
	num=to_int(val);
	if(num<=0) return;
	if(num>1000) return;
	v=num*10000;
	if(MONEY_D->sub_salary_money(master,v)==-1) {
		write("库存没有那么多钱。\n");
		return;
	}
	MONEY_D->add_poket_money(master,v);

	poped=0;
	modal_pop();
	call_out("quit_menu_application",5);

	master->targetted_action("$N对$T道：给$S从库里提"+chinese_number(num)+
		"两黄金。\n",slave);
	DELAY_D->delay_targetted_action(slave,master,"$N对$T道：没问题。\n",2);
	DELAY_D->delay_targetted_action(master,slave,"$N满意地点点头。\n",4);
	
}


void bodytosal(string val) {
	int num,v;
	num=to_int(val);
	if(num<=0) return;
	if(num>1000) return;
	v=num*10000;
	if(MONEY_D->sub_poket_money(master,v)==-1) {
		write("你身上没有那么多钱。\n");
		return;
	}
	MONEY_D->add_salary_money(master,v);

	poped=0;
	modal_pop();
	call_out("quit_menu_application",5);

	master->targetted_action("$N掏出"+chinese_number(num)+
		"两金子抵给$T道，把这些钱存到库里。\n",slave);
	DELAY_D->delay_targetted_action(slave,master,"$N对$T道：没问题。\n",2);
	DELAY_D->delay_targetted_action(master,slave,"$N满意地点点头。\n",4);
	
}


void banktosal(string val) {
	int num,v;
	num=to_int(val);
	if(num<=0) return;
	if(num>1000) return;
	v=num*10000;
	if(MONEY_D->sub_bank_money(master,v)==-1) {
		write("钱庄里没有那么多钱。\n");
		return;
	}
	MONEY_D->add_salary_money(master,v);

	poped=0;
	modal_pop();
	call_out("quit_menu_application",5);

	master->targetted_action("$N对$T道：去把钱庄里的"+chinese_number(num)+
		"两金子转到库里。\n",slave);
	DELAY_D->delay_targetted_action(slave,master,"$N对$T道：没问题。\n",2);
	DELAY_D->delay_targetted_action(master,slave,"$N满意地点点头。\n",4);
	
}


void saltobank(string val) {
	int num,v;
	num=to_int(val);
	if(num<=0) return;
	if(num>1000) return;
	v=num*10000;

        if(MONEY_D->get_bank_money(master)>50000000) {
                write("钱庄不能存更多钱了。\n");
                return;
        }
	if(MONEY_D->sub_salary_money(master,v)==-1) {
		write("库里没有那么多钱。\n");
		return;
	}


	MONEY_D->add_bank_money(master,v);

	poped=0;
	modal_pop();
	call_out("quit_menu_application",5);

	master->targetted_action("$N对$T道：去把库里的"+chinese_number(num)+
		"两金子转到钱庄的帐上。\n",slave);
	DELAY_D->delay_targetted_action(slave,master,"$N对$T道：没问题。\n",2);
	DELAY_D->delay_targetted_action(master,slave,"$N满意地点点头。\n",4);
	
}
void create( )
{
    set_privilege(1);
    toplevel = new_menu("\n请对帐房先生下达指令：");
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

    add_menu_item(toplevel, new_menu_item("库存->钱庄",	(: get_input_then_call,
		(: saltobank :) ,"钱数(金1-1000)：" :) ,"4"));

    add_menu_item(toplevel, new_menu_item("钱庄->库存",	(: get_input_then_call,
		(: banktosal :) ,"钱数(金1-1000)：" :) ,"5"));

    add_menu_item(toplevel, new_menu_item("身上->库存",	(: get_input_then_call,
		(: bodytosal :) ,"钱数(金1-1000)：" :) ,"6"));
    add_menu_item(toplevel, new_menu_item("库存->身上",	(: get_input_then_call,
		(: saltobody :) ,"钱数(金1-1000)：" :) ,"7"));


    add_menu_item(toplevel, new_menu_item("改变ID",	(: get_input_then_call,
		(: do_changeid :) ,"变为何ID：" :) ,"9"));

    add_menu_item(toplevel, new_menu_item("撤职", 	(: get_input_then_call,
	(: do_demote :) ,"确认撤职吗(y/n)？" :) ,"a"));

    add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, space);
    set_menu_prompt (toplevel, "输入指令[12345679q]: ");
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
