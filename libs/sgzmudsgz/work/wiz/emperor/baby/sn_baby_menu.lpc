void create( )
{
    set_privilege(1);
    toplevel = new_menu("");
    quit_item = new_menu_item("退下", (:quit_old_place:), "q");
    seperator = new_seperator
    ("----------------------------------------------------------------------");
    space = new_seperator
    ("                                                                      ");

    add_menu_item(toplevel, seperator);
    add_menu_item(toplevel, space);
    add_menu_item(toplevel, new_menu_item("逗孩子玩",	(: do_play :) ,"1"));
    add_menu_item(toplevel, new_menu_item("给孩子喂奶",	(: do_weinai :) ,"2"));
    add_menu_item(toplevel, new_menu_item("教孩子说话",	(: do_teach :) ,"3"));
    add_menu_item(toplevel, new_menu_item("给孩子起名",	(: get_input_then_call,
		(: do_changeid :) ,"变为何名：" :) ,"4"));
    add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, space);
    set_menu_prompt (toplevel, "输入指令[1234q]: ");
}

void start_menu()
{

	poped=1;

	init_menu_application( toplevel );
	call_out("quit_menu_application",50);

}

