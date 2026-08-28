#define MASTER "/home/aluna/Magic/master"

inherit ITEM;
string location;
get() { return 0;}

create_item()
{
    set_name(({"Sphere of Power","sphere","stone","stone sphere","sphere of stone",
	"moss covered stone","mossy stone"}));
    set_short("A large moss covered stone sphere");
    set_long(wrap("It is a moss covered sphere of stone with radius of 2 to 2.5 meters. "+
	"It must be very heavy and probably cannot be carried by anything, except "+
	"the gods. The rock appears to be somewhat transparent."));
    set_smell("It smells mossy.\n");
    set_taste("It tastes rocky.\n");
    set_listen("It emits a faint humming sound.\n");
    set_material ("stone");
    set_dimensions(200,250,200);
    set_no_get(1);
    set_no_clean_up(1);
}

init()
{
    add_action("cmd_push","push");
    add_action("cmd_peer","peer");
}

int
cmd_push(string str)
{
    string what, where;
    string *exits, *dest;
    int ep, ep_max, idx;
    notify_fail ("Push what?\n");
    return 0;

    if(sscanf(str,"%s to %s",what,where)<2)
    {
	write ("Push "+what+" to where?\n");
	return 1;
    }
    if(!id(what))
	return;
    if(THIS->query_is_fighting())
    {
	write("You cannot push it now! You are fighting for your life.\n");
	return 1;
    }
    exits=environment(THIS)->query_exit_dir();
    dest=environment(THIS)->query_exit_dest();
    idx=member_array(where, exits);
    if(idx<0)
    {
	tell_object(THIS,"You cannot push it to that direction!\n");
	return 1;
    }
    ep=THIS->query_ep();
    ep_max=THIS->query_max_ep();
    if(ep<ep_max/2)
    {
	THIS->set_ep(0);
	tell_object(THIS,"You try to push the sphere but you can't make it move an inch.\n");
	tell_room(environment(THIS),
	  THIS->query_cap_name()+" groans as "+THIS->query_pronoun()+
	  " tries to push the stone to "+where+".\n",
	  ({THIS}));
    }
    THIS->add_ep(-ep_max/2);
    THOB->move(dest[idx]);
    tell_room(environment(THIS),
      THIS->query_cap_name()+" manages to push the sphere to "+where+"!\n",
      ({THIS}));
    tell_object(THIS, "You manage to push the sphere to "+where+"!\n");
    tell_room(environment(THOB),
      "A large sphere of stone rolls in!\n");
    return 1;
}

cmd_peer(string str)
{
    string what;
    if(!str)
    {
	notify_fail ("Peer what?\n");
	return 0;
    }
    if(sscanf(str,"into %s",what)<1)
    {
	write ("Peer into what?\n");
	return 1;
    }
    if(!id(what))
	return;

    write(wrap("You peer into the stone and see infinity of myriads shapes, stars and symbols. "+
	"Finally you shake yourself out of it and remember only one thing: "+
	THOB->study_true_name(THIS)+".\n"));

    return 1;
}

string study_true_name(object who)
{
    string *known, *notknown, *all, true_name;
    int i;
    notknown=({});
    known=who->query_known_true_meanings();
    switch (sizeof(known))
    {
    case 0:
	all=MASTER->query_tech_names();
	break;
    case 1:
	all=MASTER->query_form_names();
	break;
    case 2:
	all=MASTER->query_power_names();
	break;
    default:
	all=MASTER->query_all_names();
	break;
    }
    for (i=0; i<sizeof(all); i++)
	if(member_array(all[i],known)<0)
	    notknown+=({all[i]});
    if(sizeof(notknown) && !THIS->query_shrine (base_name(ENV(THOB))))
	true_name=who->create_magical_true_name(notknown[random(sizeof(notknown))]);
    else
	return "nothing";

    THIS->add_shrine(base_name(ENV(THOB)));
    write_file ("/log/sphere", ctime(time()) + " :: "+
      THIS->query_cap_name()+" learned "+true_name+
      " ("+THIS->query_magical_true_meaning(true_name)+") from "+
      explode(base_name(ENV(THOB)), "/")[<1]+"\n");

    return true_name;
}
