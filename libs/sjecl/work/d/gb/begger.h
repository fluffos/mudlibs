// begger.h
// by Looklove@SJ
// include for beggers :)
// 2001.9.27 海口

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) ) {
                remove_call_out("begging");
                call_out("begging", 1, ob);
        }
        add_action("do_kill", "kill");
        add_action("do_kill", "tk");
        add_action("do_kill", "teamkill");
        add_action("do_kill", "hit");
}

void dest(object obj)
{
    	if (obj) destruct(obj);
}

int do_kill(string arg)
{
        object ob,ob2;
        object me = this_player();
        ob2 = this_object();

        if (!arg) return 0;
        ob = present(arg, environment(me));

        if (ob == this_object() || ob == me) return 0;
        if (!ob || !ob->is_character()|| !living(ob2)) return 0;
        if ( query("gb/bags") <= 3 ) return 0;

        if ( userp(ob) && ob->query("family/family_name") == "丐帮") {
                if ( userp(me) && me->query("family/family_name") == "丐帮") {
                message_vision(ob2->name()+"对$N叫道：你居然杀自己的同门？我宰了你！\n", me);
                message_vision(ob2->name()+"对$N叫道：兄弟快走，$n要对你下手！\n", ob, me);
                command("guard " + ob->query("id"));
                }
                else {
                        message_vision(ob2->name()+"对$N喝道：大胆，居然敢对我丐帮弟子下手！\n", me);
                        message_vision(ob2->name()+"对$N叫道：兄弟快走，$n要对你下手！\n", ob, me);
                        command("guard " + ob->query("id"));
                }
                return 1;
        }
        return 0;
}

void begging(object ob)
{
        if( !ob || environment(ob) != environment()
                || ( ob->query("family/family_name") == "丐帮")
                || (int)ob->query("age") < 15
                || query("gb/bags") >= 8
          ) return;

        switch( random(10) ) {
                case 0:
                       command("look " + ob->query("id"));
                       break;
                case 1:
                       command("beg silver from " + ob->query("id"));
                       break;
                case 2:
                       command("beg1 " + ob->query("id"));
                       command("beg gold from " + ob->query("id"));
                       break;
                case 3:
                       command("beg jiudai from " + ob->query("id"));
                       break;
                case 4:
                       command("hi " + ob->query("id"));
                       break;
                case 5:
                       command("beg coin from " + ob->query("id"));
                       break;
                case 6:
                       command("lazy");
                       break;
                case 7:
                       command("dig");
                       break;
                case 8:
                       command("bow " + ob->query("id"));
                       break;
                case 9:
                       command("chitchat " + ob->query("id"));
                       command("beg all from " + ob->query("id"));
                       break;
        }
}
int accept_object(object me, object obj)
{
        object ob;
        ob = this_player();

	if ( userp(obj) || query("gb/bags") >= 6 )  return 0;

        if ( (obj->query("money_id")) && obj->value() >= 100000 ) {
                 command("touch " + ob->query("id"));
        }
        else if ( (obj->query("money_id")) && obj->value() >= 1000 ) {
                 command("joythank " + ob->query("id"));
        }
        else if ( obj->query("id") == "kao ya" ||
	 obj->query("id") == "jiu dai"||
	 obj->query("id") == "yue bing"||
	 obj->query("id") == "bao zi"||
	 obj->query("id") == "man tou"||
	 obj->query("id") == "jiu dai") {
		command("thank");
	}
	else if (obj->query("money_id") && obj->value() >= 1) {
		command("thank " + ob->query("id"));
	}
	else {
		command("shrug " + ob->query("id"));
		command("say 这东西还是你自己留着把。");
		return notify_fail("");
	}

	ob->start_busy(1);
//	call_out("dest", 1, obj);
        return 1;
}