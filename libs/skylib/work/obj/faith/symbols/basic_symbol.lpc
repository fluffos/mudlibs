/**
 * The Holy Symbol Inherit.
 * Sandoz, 24th July 2001
 * Edited by Shaydz/Love
 * 17th June 2005
 */

inherit ARMOUR_OBJ;

nosave string deity, long_desc;

/** @ignore yes */
void set_long_desc( string _long ) { long_desc = _long; }

/** @ignore yes */
int consider_alignment( object *obs );

/** @ignore yes */
string do_compare( int al, object o );

/** @ignore yes */
string query_long_desc() { return long_desc; }

/** @ignore yes */
string query_deity() { return deity; }

/** @ignore yes */
void set_deity( string _name ) {
    deity = _name;
    add_adjective( lower_case(deity) );
    add_property( deity, 1 );
} /* set_deity() */

/** @ignore yes */
string get_long() {
    return long_desc+( TP->query_deity() == deity ? "  Your deity allows you "
                       "to discover your fellow followers.  To find others of "
                       "your ilk, use the 'list' command.  Your deity may also "
                       "allow you to discover the alignment of others, simply "
                       "'use' this holy symbol to observe those around "
                       "you.\n" : "\n" );
} /* get_long() */

/** @ignore yes */
void create() {
    ::create();
    set_name("symbol");
    set_short("holy symbol");
    add_adjective("holy");
    add_alias( ({"amulet", "jewellery"}) );
    add_plural( ({"amulets", "jewellery"}) );

    add_property("holy symbol", 1 );
    add_property("no_recycle", 1 );
    add_property("shop type", "jewellers");

    set_long( (: get_long :) );

    set_type("necklace");
    setup_armour(1200);
    set_damage_chance(10);
    set_value(6000);
    set_weight(4);

    TO->setup();

} /* setup() */

/** @ignore yes */
void init() {
    add_command("list", "worshippers");
    add_command("use","symbol to observe <indirect:living:here>", (: consider_alignment($1) :));
} /* init() */

/** @ignore yes */
int do_list() {
    string *worshippers;

    if( TP->query_deity() != deity ) {
        add_failed_mess("Your connection with "+deity+" is too weak to get "
            "anything useful out of "+the_short()+".\n");
        return 0;
    }

    worshippers = DEITY_H->query_worshippers( deity );
    worshippers = filter( worshippers, (: !creatorp($1) :) );
    worshippers = map( worshippers, (: CAP($1) :) );

    if( !sizeof( worshippers = sort_array( worshippers, 1 ) ) ) {
        add_failed_mess("There are no worshippers currently in the service "
            "of "+deity+".\n");
        return 0;
    }

    add_succeeded_mess( ({ query_multiple_short(worshippers)+" are the "
        "players currently in the service of "+deity+", with a total of "+
        query_num( sizeof(worshippers) )+" worshipper"+
        ( sizeof(worshippers) > 1 ? "s" : "" )+".\n",
        "$N briefly clasp$s "+TO->poss_short()+" in $p hand.\n"}) );

    return 1;

} /* do_list() */

int consider_alignment( object *obs ) {
    int ok;
    object ob;
    
    ok=0;
    if( TP->query_deity()!=deity ) {
        switch(deity){
           case "Dilabi":
               add_failed_mess("If you attempt to use the symbol of Dilabi "
                               "again without worshipping him, you may find "
                               "that your next meal is your last.\n");
               break;
           case "Elytra":
               add_failed_mess("Elytra can provide you with far more than any "
                               "other god.  Perhaps you should consider "
                               "converting before taking advantage of her "
                               "symbol again.\n");
               break;
           case "Lumen":
               add_failed_mess("Perhaps you should consider following the path "
                               "of peace and healing before attempting to "
                               "use Lumen's symbol again. \n");
               break;
           case "Savons":
               add_failed_mess("You are not even close to being "
                               "knowledgeable enough to use the symbol of "
                               "Savons.\n");
               break;
           case "Visam":
               add_failed_mess("It is only when you understand the balance "
                               "of nature that you can use a symbol of "
                               "Visam.\n");
               break;
           default:
               add_failed_mess("You are not a worshipper of "+deity+".  You need "
                               "to have faith before using this symbol.\n");
               break;
           }
        return 0;
    }

    if( sizeof(obs) > 1 )
        obs -= ({ TP });

    if( sizeof(obs) > 5 ) {
        add_failed_mess("You can only consider 5 things at once.\n");
        return 0;
    }

    switch( TP->check_dark( ENV(TP)->query_light() ) ) {
      case -2..-1 :
        add_failed_mess("It's too dark to consider anyone.\n");
        return 0;
      case 1..2 :
        add_failed_mess("It's too bright to consider anyone.\n");
        return 0;
      default :
    }


    tell_room(ENV(TP),TP->query_short()+" gazes at "+TP->HIS+" holy symol.\n",TP);
    tell_object(TP,"You gaze into your holy symbol.\n");
    TP->adjust_gp(-(sizeof(obs)*10));
    
    foreach( ob in obs ) {
        if( !living(ob) )
            continue;

        if( ob == TP ) {
            if( sizeof(obs) == 1 ) {
                write("You feel nothing but scorn from "+deity+" for needing to consider your own"
                      " spiritual worth.\n");
                ok++;
            }
            continue;
        }

        
        ok++;

        write( do_compare( ob->query_al(), ob )+"\n");

        }
    if( !ok ) {
        add_failed_mess("You need to consider someone.\n");
        return 0;
    }

    return 1;
   
} /* consider_alignment() */

/** @ignore yes */
string do_compare( int al, object o ) {
    string ret;

    ret = "$C$$who$";

        switch( al ) {
          case -10000..-5201:
            ret = "%^BOLD%^%^WHITE%^"+ret+" glows a blinding white";
          break;
          case -5200..-2501:
            ret = "%^BOLD%^%^WHITE%^"+ret+" glows extremely white";
          break;
          case -2500..-1251:
            ret = "%^WHITE%^"+ret+" glows very white";
          break;
          case -1250..-601:
            ret = "%^WHITE%^"+ret+" glows fairly white";
          break;
          case -600..-301:
            ret = "%^CYAN%^"+ret+" glows faintly blue";
          break;
          case -300..300:
            ret = "%^CYAN%^"+ret+" glows blue";
          break;
          case 301..600:
            ret = "%^BOLD%^%^CYAN%^"+ret+" glows bright blue";
          break;
          case 601..1250:
            ret = "%^RED%^"+ret+" glows fairly red";
          break;
          case 1251..2500:
            ret = "%^RED%^"+ret+" glows quite red";
          break;
          case 2501..4800:
            ret = "%^BOLD%^%^RED%^"+ret+" glows very red";
          break;
          case 4801..10000:
            ret = "%^BOLD%^%^RED%^"+ret+" glows extremely red";
          break;
          default:
            ret = "%^CYAN%^"+ret+" glows blue";
        }
        ret = replace_string( ret, "$who$", o->the_short() );

    return ret + ".%^RESET%^";

} /* do_compare() */

