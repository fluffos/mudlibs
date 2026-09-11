//qb.c this is used to give qb command by fire on Jan 1999

#include <menu.h>
#include <mudlib.h>
#include <verb.h>
#include <ppl.h>
inherit __DIR__+"free_menu";

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

void do_npclist() {
	string msg;
	object o_h;

	string *ls;
	int i,sum;
	string t_id,t_name,tt_id,t_pos;
	mapping inf;

	o_h=SGHOME(p_id);

	modal_pop();
	poped=0;

	master->targetted_action(
		"$N对$T道：$m，现在家里都雇佣了些什么人。\n",slave);

	ls=o_h->get_npc("list");
	sum=sizeof(ls);
	msg="$N对$T躬身道：回$R，现在府里各种人手共有"+chinese_number(sum)+"人\n";
	for(i=0;i<sum;++i) {
		t_id=ls[i];
		inf=o_h->get_npc(t_id);
		tt_id=inf["pre_id"];
		t_name=inf["sname"]+inf["gname"];
		t_pos=inf["pos"];
		if(!stringp(t_pos)) t_pos="free";
		t_pos=load_object("/sgdomain/home/npc/"+t_pos)->get_type_name();
		msg+=t_name+"("+tt_id+")，职位："+t_pos+"，月银："+
			chinese_number(inf["salary"])+"两。\n";
				
	}
        DELAY_D->delay_targetted_action(slave,master,msg,2);
	call_out("quit_menu_application",3);
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

    add_menu_item(toplevel, new_menu_item("花名册",	(: do_npclist :) ,"b"));

    add_menu_item(toplevel, new_menu_item("召人来",	(: get_input_then_call,
		(: do_call :) ,"召唤何人：" :) ,"c"));

    add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, space);
    set_menu_prompt (toplevel, "输入指令[12349q]: ");
}

