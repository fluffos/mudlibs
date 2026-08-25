//emperor write it

#include <menu.h>
#include <mudlib.h>
#include <verb.h>
#include <ppl.h>
inherit __DIR__+"free_menu";

void do_query(string str)
{
	object o_h;
	int i,j,k;
	string *baby_list,msg;
	mapping inf;

	o_h=SGHOME(p_id);
	baby_list=CHAR_D->get_char(master,"baby_id");
	poped=0;
    	modal_pop();

	if (!j) {slave->targetted_action("$N朝$T福了一福道：$m，你现在还没孩子。\n",master);return;}

	k=0;
	for(i=0;i<j;i++){
		inf=o_h->get_npc(baby_list[i]);
		if(inf["id"]==str) k=k+1;
	}
	if(!k){slave->targetted_action("$N朝$T福了一福道：$m，你没这个公子或者小姐。\n",master);return;}
	inf=o_h->get_npc(str);
	if(inf["gender"]==1) msg="公子";else msg="小姐";
	slave->targetted_action("$N朝$T福了一福道：$m，你可以对这位"+msg+"做以下事情：\n",master);
	new(__DIR__+"sn_baby_menu")->start_menu();
}

void do_babylist() {
	string msg;
	object o_h;

	string *baby_list;
	int i,j;
	mapping inf;

	
	o_h=SGHOME(p_id);
	baby_list=CHAR_D->get_char(master,"baby_id");
	j=sizeof(baby_list);
	modal_pop();
	poped=0;
	if (!j) {slave->targetted_action("$N对$T道：现在你还没孩子。\n",master);return;}
	msg="$N对$T躬身道：回$R，现在府里共有"+chinese_number(j)+"公子和小姐。\n";

	for(i=0;i<j;i++){
		inf=o_h->get_npc(baby_list[i]);
		msg+=inf["pre_name"]+"  "+inf["id"]+"\n";
	}

	DELAY_D->delay_targetted_action(slave,master,msg,2);
	call_out("quit_menu_application",3);
}

void create( )
{
    set_privilege(1);
    toplevel = new_menu("\n请对侍女下达指令：");
    quit_item = new_menu_item("退下", (:quit_old_place:), "q");
    seperator = new_seperator
    ("----------------------------------------------------------------------");
    space = new_seperator
    ("                                                                      ");

    add_menu_item(toplevel, seperator);
    add_menu_item(toplevel, space);
    add_menu_item(toplevel, new_menu_item("在此恭候",	(: do_stayhere :) ,"1"));


    add_menu_item(toplevel, new_menu_item("询问情况",	(: do_getinfo :) ,"2"));
    add_menu_item(toplevel, new_menu_item("赏赐物品",	(: get_input_then_call,
		(: do_praise :) ,"赏赐何物：" :) ,"3"));


    add_menu_item(toplevel, new_menu_item("改变ID",	(: get_input_then_call,
		(: do_changeid :) ,"变为何ID：" :) ,"4"));


    add_menu_item(toplevel, new_menu_item("询问BABY",	(: get_input_then_call,
		(: do_query :) ,"询问哪个BABY：" :) ,"5"));

    add_menu_item(toplevel, new_menu_item("BABY花名册",	(: do_babylist :) ,"6"));


    add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, space);
    set_menu_prompt (toplevel, "输入指令[123456q]: ");
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

