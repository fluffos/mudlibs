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
    write("Abres tu boca y tragas tanta agua que la cierras en el acto.\n");
    say(TP->query_cap_name()+" mueve la boca expulsando burbujas de aire.\n",TP);
    return 1;
}
void set_up_location(string str)
{
    up_loc = str;
    add_exit("arriba",up_loc,"plain");
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
      tell_object(player, "%^CYAN%^Que raro, no sientes la necesidad "+
                  "de respirar.%^RESET%^\n");
      return;
   }
    player->do_death(player->query_race_ob());
    tell_object(player,"Al menos hay una consolacion, vas a deshacer el peinado de pelo de Jakel de mala manera.\n");
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
	notify_fail("Ya estas nadando hacia "+verb+".\n");
	return 0;
    }
    tell_object(ob,"Comienzas a nadar hacia "+verb+".\n");
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
	notify_fail("Parece que no consigues llegar a ningun sitio "
	  "en esa direccion.\n");
	return 0;
    }
    tell_object(ob,"Nadas hacia "+verb+".\n");
    return 1;
}
