/** 
* A standard fire object.
* @author Windy, May '01
*/

inherit "/obj/vessel";

#define FUEL_MAX 5000

int level,
fuel,
permanent = 0;

string creator;

string get_short();
string get_long();
int consume( object ob );
int add_fuel( int i );
void consume2( string mess, int wood );
string atmosphere();
int do_extinguish();

/** @ignore yes */
void create()
{
    level = 1;
    fuel = 200;
    FUEL_H -> add_burner( TO );

    ::create();
}

/** @ignore yes */
void setup()
{
    set_name("fire");
    set_short( (: get_short :) );
    set_long( (: get_long :) );
    set_light(50);
    add_property("there","burning on the floor");
    add_alias("campfire");

    reset_get();
    reset_drop();
}

/** @ignore yes */
void dest_me()
{
    FUEL_H -> remove_burner( TO );
    ::dest_me();
}

/** @ignore yes */
void init()
{
    set_heart_beat(1);
    TP -> add_command("extinguish", TO, "fire",
      (: do_extinguish :) );
}

/** @ignore yes */
int test_add( object ob, int notused )
{
    if( !ob )
        return 0;

    set_heart_beat(1);
    consume( ob );
    return 1;
}

/**
* Get the level that this fire is at.
* @return the level
*/
int query_level()
{
    switch( fuel )
    {
    case 1..1250:
        add_alias("campfire");
        remove_alias("inferno");
        set_light(20);
        return 1;
    case 1251..2500:
        add_alias("campfire");
        remove_alias("inferno");
        set_light(30);
        return 2;
    case 2501..3500:
        add_alias("campfire");
        set_light(40);
        remove_alias("inferno");
        return 3;
    case 3501..5000:
        add_alias("inferno");
        remove_alias("campfire");
        set_light(50);
        return 4;
    }
}

/**
* Get the amount of fuel this fire has. When it reaches 0 fuel, the
* fire will burn out.
* @return the amount of fuel
*/
int query_fuel() { return fuel; }

/** @ignore yes */
int consume( object ob )
{
    int wood = 0;
    int wt;

    if( !ob )
        return 0;

    wt = ob -> query_weight();

    if( !wt )
        wt = 1;

    if( ob -> query_material() == "wood" ||
      ob -> query_material() == "wooden" ||
      ob -> query_property("fuel") ||
      strsrch( ob -> query_short(), "wood" ) != -1 )
    {
        add_fuel( wt );

        switch( wt )
        {
        case -1000..20: wood = 1; break;
        case 21..75: wood = 2; break;
        case 76..125: wood = 3; break;
        default: wood = 4;
        }

        call_out( "consume2", 2, ob -> the_short(),
          wood );

        ob -> call_out( "dest_me", 3 );

        return 1;
    }

    // Well, it's not wood, but we'll live anyway.

    add_fuel( 3 );
    call_out( "consume2", 3, ob -> the_short(), wood );

    ob -> call_out( "dest_me", 3 );


    return 1;
}

/** @ignore yes */
string get_short()
{
    switch( query_level() )
    {
    case 1: return "%^ORANGE%^small campfire%^RESET%^"; break;
    case 2: return "%^ORANGE%^roaring campfire%^RESET%^"; break;
    case 3: return "%^ORANGE%^large fire%^RESET%^"; break;
    case 4: return "%^RED%^BOLD%^towering inferno%^RESET%^"; break;
    default: return "broken fire. please notify a cre."; break;
    }
}

/** @ignore yes */
string get_long()
{
    string s;

    switch( query_level() )
    {
    case 1: s = "This small campfire relaxes you as you sit near it. "+
        "You seem to be recovering slightly faster than normal.\n"; break;
    case 2: s = "This roaring campfire invites you to sit near it and "+
        "relax. You seem to be recovering slightly faster than normal.\n"; 
        break;
    case 3: s = "This large fire is truly a wonder to behold. You seem to "+
        "be recovering slightly faster than normal.\n"; break;
    case 4: s = "Wow, a pyromaniac's dream fire! You seem to be "+
        "recovering slightly faster than normal.\n"; break;
    default: s = "a broken fire. please notify a cre."; break;
    }
    if( creator )
        s += "It was built by "+ creator +".\n";

    return s;
}

/** @ignore yes */
int add_fuel( int i )
{
    int oldlevel = query_level();

    if( fuel + i > FUEL_MAX )
        fuel = FUEL_MAX;
    else
        fuel += i;

    if( fuel == 20 )
        tell_room( ENV( TO ), "The fire starts to splutter. You feel it doesn't have "+
          "much life left.\n");

    if( fuel == 10 )
        tell_room( ENV( TO ), "The fire is really spluttering now. It's almost burned "+
          "out.\n");

    if( fuel == 5 )
        tell_room( ENV( TO ), "The fire is on its last breath.\n");

    if( fuel <= 0 )
    {
        tell_room( ENV( TO ), "The fire burns out.\n");
        TO -> dest_me();
        return 0;
    }


    if( query_level() > oldlevel )
        tell_room( ENV( TO ), "The fire surges and grows larger!\n");
    else if( query_level() < oldlevel )
        tell_room( ENV( TO ), "The fire sputters and becomes smaller.\n");

    level = query_level();

    if( level != oldlevel )
    {
        set_short( (: get_short() :) );
        set_long( (: get_long() :) );
    }

    return 1;
}

/** @ignore yes */
void heart_beat()
{
    int heal = query_level() * 3;

    if( !sizeof( filter( INV(ENV(TO)), (: living($1) :) ) ) )
    {
        set_heart_beat(0);
        return;
    }

    if( !random( 20 ) )
        tell_room( ENV( TO ), atmosphere() ); // Some atmosphere messages


    foreach( object ob in all_inventory( ENV( TO ) ) )
    {
        if( !userp( ob ) )
            continue;


        if( ob -> query_hp() + heal > ob -> query_max_hp() )
            ob -> set_hp( ob -> query_max_hp() );
        else
            ob -> adjust_hp( heal );
    }


}

/** @ignore yes */
void consume2( string mess, int wood )
{
    if( wood == 4 )
        tell_room( ENV( TO ), "The fire roars as it consumes "+ mess +"!\n");
    else if( wood == 3 )
        tell_room( ENV( TO ), "The fire burns far brighter as it consumes "+
          mess +".\n");
    else if( wood == 2 )
        tell_room( ENV( TO ), "The fire burns much brighter as it consumes "+
          mess +".\n");
    else if( wood )
        tell_room( ENV( TO ), "The fire burns brighter as it consumes "+ mess +".\n");
    else
        tell_room( ENV( TO ), "The fire consumes "+ mess +".\n");
}

/** Sets the amount of fuel in the fire.
* @param fuel the amount of fuel
*/
void set_fuel( int i ) { fuel = i; }

/** @ignore yes */
string atmosphere()
{
    return choice( ({
        "The fire crackles and pops.\n",
        "The fire sends a shower of sparks into the air.\n",
        "You feel warm sitting next to the fire.\n",
        "The fire's flames wave in the wind.\n"
      }) );
}

/** @ignore yes */
void consume_fuel()
{
    if( !permanent ) // if it's not permanent, consume some fuel
        add_fuel( -1 ); // Consume some fuel
}

/** 
* Make this fire a permanent fire (it will never run out of fuel)
* @param i 1 for permanent, 0 for normal
*/
void set_permanent( int i ) { permanent = i; }

/**
* Get whether this is a permanent fire.
* @return 1 for permanent, 0 for normal
*/
int query_permanent() { return permanent; }

/** @ignore yes */
void set_creator( string str ) { creator = str; }

/** @ignore yes */
string query_creator() { return creator; }

/** @ignore yes */
int do_extinguish()
{
    if( !creator )
    {
        add_failed_mess("You are unable to extinguish the fire.\n");
        return 0;
    }

    if( TP -> query_short() != creator )
    {
        add_failed_mess( creator +" wouldn't be too happy if you were to extinguish "+
          "the fire!\n");
        return 0;
    }

    add_succeeded_mess("$N $V the fire.\nThe fire goes out.\n");
    FUEL_H -> remove_burner( TO );
    dest_me();

    return 1;
}
