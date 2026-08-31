inherit CONTAINER;
inherit M_MESSAGES;

int touched = 0;
int activation_step = 0;
int max_step = 5;
object activator;
object key;
string destination;


void object_arrived();

void mudlib_setup(string d)
{
    ::mudlib_setup();
    destination = d;
    set_id("archway", "portal");
    set_weight(2500);
    set_proper_name("a plexus archway");
    set_in_room_desc("A archway with blue and white symbols on the surrounding edge.");
    add_adj("plexus");
    add_relation("in", VERY_LARGE);
    set_default_relation("in");
    set_long("This large stone archway stands in the middle of the room. You can see right through it. It seems inactive.");
    add_hook("object_arrived", (: object_arrived:));
}

void call_out_chain()
{
    string *msgs;

    switch (activation_step)
    {
    case 1:
        simple_action("The center of $n becomes bright white, then a swirling portal of lights.");
        break;
    case 2:
        simple_action("$N $vbeep and $vboop in weird tones.");
        break;
    case 3:
        if (environment(this_object()) == environment(activator))
        {
            targetted_action("$T $v1are sucked into the center and $n1 $v1disappear.", activator);
            activator->move(destination);
            msgs = activator->get_player_message("menter");
            tell_from_inside(environment(activator), msgs[1], 0, ({activator}));
            activator->force_look(1);
        }
        break;
    case 4:
        simple_action("$N $vbecome silent again and the lights fade.");
        break;
    case 5:
        tell(activator, "Your plexus key reappears in your inventory again.\n");
        key->move(activator);
        activator = 0;
        break;
    }
    if (activation_step < max_step)
    {
        activation_step++;
        call_out("call_out_chain", random(4) + 2);
    }
}

void object_arrived(object ob)
{
    activator = this_body();
    key = ob;
    activation_step = 1;
    call_out("call_out_chain", random(4) + 2);
}

void touch_effect(object who)
{
    if (touched)
        targetted_action("The archway briefly flashes at $p1 touch, hums, but then falls silent again.\n",who);
    touched = 0;
}

void do_touch()
{
    object who = this_body();
    touched = 1;
    call_out("touch_effect", 2, who);
}

int is_node_portal()
{
    return 1;
}

mixed indirect_put_obj_wrd_obj(object ob1, string prep, object ob2)
{
    if (activator)
        return "The plexus archway seems busy right now.";
    return 1;
}

int query_hide_contents()
{
    return 1;
}

string query_hint()
{
    return this_body()->query_level()<10 ? "This portal allows you to travel to other worlds, but not yet." : "Find a key.";
}