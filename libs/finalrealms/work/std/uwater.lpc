inherit "/std/room";

nosave string up_loc;
nosave string death_loc;

void event_enter(object target, string MESG, object FROM)
{
    if(!target) return;
    if(!target->query_property("free_action"))
    {
	target->add_static_property("nocast",1);
	target->add_static_property("noguild",1);
          target->set_wetness(300);
    }
}
void init()
{
    ::init();
    add_action("no_can_do", "say");
    add_action("no_can_do", "shout");
    add_action("no_can_do", "lsay");
    add_action("no_can_do", "'");
}
int no_can_do(string str)
{
    write("Erm ?, you are underwater right ??.\n");
    say(TP->query_cap_name()+" swallows some water and grimaces.\n",TP);
    return 1;
}
void set_up_location(string str)
{
    up_loc = str;
    add_exit("up",up_loc,"plain");
}
void set_death_location(mixed str)
{
    if(stringp(death_loc))
	death_loc = str;
    if(pointerp(str))
	death_loc = str[random(sizeof(str))];
}

void create()
{
    ::create();
    add_property("location","underwater");
}

void DO_DROWN(object player,object from )
{
   if(player->query_property("free_action"))
   {
      tell_object(player, "%^CYAN%^Strange, you haven't the urge or need "+
                  "to breathe.%^RESET%^\n");
      return;
   }
    player->do_death(player->query_race_ob());
    tell_object(player,"Well, there's one consolation, this is going to mess Grimbrands hairdo something terrible.\n");
    if(death_loc && load_object(death_loc))
    {
	player->move(death_loc);
	player->look_me();
    }

}
#define MOVE_DELAY 10

int do_exit_command(string str, mixed verb, object ob, object foll)
{
    int delay;
    if(!ob && this_player() ) ob = this_player();
    if(!ob) return 0;

    if(!verb)
	verb = query_verb();
    if(ob->query_property("IS_SWIMMING"))
    {
	notify_fail("You are already swimming to the "+verb+".\n");
	return 0;
    }
    tell_object(ob,"You start swimming "+verb+".\n");
    switch((ob->query_race_ob())->
      query_swim_stamina(ob))
    {
    case 11..50 : delay = MOVE_DELAY -1; break;
    case 51..100 : delay = MOVE_DELAY -2; break;
    case 101..200 : delay = MOVE_DELAY -3; break;
    case 201..400 : delay = MOVE_DELAY -4; break;
    case 401..100000: delay = 0; break;
    default : delay = MOVE_DELAY; break;
    }

    if( ob->query_property("free_action") )
	delay = 0;
    call_out("really_do_exit_command", delay, str, verb, ob, foll);
    ob->add_timed_property("IS_SWIMMING",1,MOVE_DELAY);
    return 1;
}

int really_do_exit_command(string str, mixed verb, object ob, object foll)
{
    if(!ob && this_player() ) ob = this_player();
    if(!ob) return 0;
    ob->remove_timed_property("IS_SWIMMING");
    ob->remove_static_property("nocast");
    ob->remove_static_property("noguild");
    if(!::do_exit_command(str, verb, ob, foll))
    {
	notify_fail("You can't seem to get anywhere in "
	  "that direction.\n");
	return 0;
    }
    tell_object(ob,"You swim "+verb+".\n");
    return 1;
}
