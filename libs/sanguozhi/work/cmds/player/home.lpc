// home.c for players by fire on 1/9/1999

#include <mudlib.h>
#define HOME_SERVER "/sgdomain/home/home_server/"
inherit CMD;

private void main(string arg)
{
    string p_id;
    object ob;
    string *msgs;
    mapping home;

    string p_area;
    if (!arg)
    {
	p_id=this_body()->query_primary_id();
	home=CHAR_D->get_char(p_id,"h");
	if(!mapp(home)) {
		write("你还没家呢。\n");
		return;
	}
	if(home["st"]=="building") {
		write("你的家还没建好。\n");
		return;
	}
	if(home["st"]=="updating") {
		write("你的家正在升级。\n");
		return;
	}

	if(home["st"]=="moving") {
		write("你的家还没搬到呢。\n");
		return;
	}
	if(CHAR_D->get_char(p_id,"task")) {
		write("你现在有工作，不能回家。\n");
		return;
	}
	if(CHAR_D->get_char(p_id,"in_prison")){
		write("你现在正在服刑，不能回家。\n");
		return;
	}
	p_area=this_body()->query_room()->get_area();
	if(p_area!=home["a"]) {
		write("你的家在"+AREA_D->get_area(home["a"],"name")+"，不在这个地区。\n");
		return;
	}

	msgs = this_body()->get_player_message("home");
        if (environment(this_body()))
                this_body()->my_action( "你回家喽。\n");
        this_body()->other_action( msgs[1]);

        ob = load_object(HOME_SERVER+p_id+"/front");

        this_body()->move(ob);

        msgs = this_body()->get_player_message("menter");

        tell_environment(this_body(), msgs[1], 0, ({ this_body() }));

//        if ( !(this_body()->test_flag(F_BRIEF)) )
            this_body()->do_game_command("look");
	this_body()->start_busy(2,"你正忙着回家呢。\n");
        return;
    }
    p_id=arg;


    home=CHAR_D->get_char(p_id,"h");
	if(!mapp(home)) {
		write("你要访问的人还没家呢。\n");
		return;
	}
	if(home["st"]!="new") {
		write("你要访问的人的家现在还不能拜访。\n");
		return;
	}
	if(CHAR_D->get_char(this_body()->query_primary_id(),"task")) {
		write("你现在有工作，不能到处串门。\n");
		return;
	}
	if(CHAR_D->get_char(p_id,"in_prison")){
		write("你现在正在服刑，不能拜访他人。\n");
		return;
	}
	p_area=this_body()->query_room()->get_area();
	if(p_area!=home["a"]) {
		write("你要访问的人的家在"+AREA_D->get_area(home["a"],"name")+"，不在这个地区。\n");
		return;
	}

    this_body()->simple_action("$N前往 " + CHAR_D->get_char(p_id,"name") +
      " 的家里找人聊天去了。");

        ob = load_object(HOME_SERVER+p_id+"/front");

        this_body()->move(ob);

    tell_environment(this_body(), this_body()->query_name() +
      "看样子是来 " + CHAR_D->get_char(p_id,"name") + " 家混饭了。\n",
      0, ({ this_body() }));


//    if(!(this_body()->test_flag(F_BRIEF)))
        this_body()->do_game_command("look");
    this_body()->start_busy(2,"你正忙着赶路呢。\n");

    return;
}

