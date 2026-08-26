/**
 * This is the well inherit to be used in rooms.
 * It creates a hidden well object.
 * @author Sandoz, 15th September 2001.
 */

nosave object well;

class well_data {
    string well_name;
    string well_long;
    mixed well_adj;
    string pump_name;
    string pump_desc;
    string cover_name;
    string cover_desc;
    int max_volume;
    int visible;
    string position;
    int cond;
}

class well_data data;

int do_move_cover( string );
int do_pump_water( string );
void make_well();
void do_fill_well();

/**
 * This method returns the well object in the room.
 * @return the well object
 */
object query_well_ob() { return well; }

/**
 * This method returns the name of the well in the room.
 * @return the name of the well object
 */
string query_well_name() {
    if( data && data->well_name )
        return data->well_name;
    return "well";
} /* query_well_name() */

/**
 * This method sets up the main parameters of the well.  Such as the
 * descs for pumps, well covers, etc.  It should be called in the
 * setup function of the inheriting room.  The adjectives should be a
 * string of words separated by spaces, e.g. "old stone"
 * @param w_name the name of the well
 * @param w_long the long description of the well object
 * @param w_adj the adjectives to add to the well object
 * @param p_name the name of the pump object
 * @param p_desc the description of the pump object
 * @param c_name the name of the well cover object
 * @param c_desc the description of the well cover object
 * @param max_vol the maximum water capacity of the well
 * @param vis whether or not the well should be a visible object
 * @param pos the position to set for the well object
 * @param cond the percentual condition of the well
 */
varargs void setup_well( string w_name, string w_long, mixed w_adj,
                         string p_name, string p_desc, string c_name,
                         string c_desc, int max_vol, int vis, string pos,
                         int cond ) {
    data = new ( class well_data );

    if( w_name )
        data->well_name = w_name;

    if( w_long )
        data->well_long = w_long;

    if( w_adj )
        data->well_adj = w_adj;

    if( p_name ) {
        data->pump_name = p_name;
        data->pump_desc = p_desc;
    }

    if( c_name ) {
        data->cover_name = c_name;
        data->cover_desc = c_desc;
    }

    data->max_volume = ( max_vol ? max_vol : 1700000 );

    if( vis ) {
        data->visible = 1;
        if( pos )
            data->position = pos;
    }

    if( cond )
        data->cond = cond;

} /* setup_well() */

/** @ignore yes */
string well_long() {
    if( data && data->well_long )
        return data->well_long;
    return "This is a basic well.\n";
} /* well_long() */

/** @ignore yes */
void make_well() {
    if( !well && data->max_volume ) {
        well = clone_object( VESSEL_OBJ );
        well->set_name( query_well_name() );
        well->set_short( query_well_name() );
        well->set_long( (: well_long :) );
        well->reset_get();
        well->set_leak_rate(0);
        well->set_weight(10000);
        well->set_max_volume( data->max_volume );
        if( data->well_adj )
            well->add_adjective( data->well_adj );
        if( data->pump_name )
            TO->add_item( data->pump_name, data->pump_desc );
        if( data->cover_name ) {
            TO->add_item( data->cover_name, data->cover_desc );
            well->set_open_trap( TO, "do_open_well" );
        } else
            well->set_stuck(1);
        if( !data->visible )
            TO->add_hidden_object(well);
        else if( data->position )
            well->add_property("there", data->position );
        if( data->cond )
            well->set_percentage( data->cond );
    }
} /* make_well() */

/** @ignore yes */
void do_fill_well() {
    object water;
    int vol;

    if( !well )
        return;

    if( !water = present("Water", well ) ) {
        water = clone_object(WATER_OBJ);
        water->move(well);
    }

    if( water->query_amount() < data->max_volume ) {
        if( ( vol = well->query_max_volume() - well->query_volume()
            + water->query_amount() ) >= data->max_volume )
            water->set_amount( data->max_volume );
        else
            water->set_amount(vol);
    }

} /* do_fill_well() */

/** @ignore yes */
int do_open_well( string word ) {
    if( !data->cover_name ) {
        add_failed_mess("$I cannot be opened or closed.\n", ({ well }) );
        return 0;
    }
    if( word == "open" ) {
        well->set_open();
        add_succeeded_mess("$N move$s the "+data->cover_name+" and "
                "open$s $I.\n", ({ well }) );
        return 1;
    } else {
        well->set_closed();
        add_succeeded_mess("$N move$s the "+data->cover_name+" and "
            "close$s $I.\n", ({ well }) );
        return 1;
    }

} /* do_open_well() */

/** @ignore yes */
int do_move_cover( string word ) {
    if( !word || !data->cover_name || word != data->cover_name )
        return 0;
    return do_open_well( well->query_closed() ? "open" : "close" );
} /* do_move_cover() */

/** @ignore yes */
int do_pump_water( string str ) {
    object water;

    if( !data->pump_name ) {
        add_failed_mess("This "+query_well_name()+" doesn't seem to have a "
            "pump.\n");
        return 0;
    }

    if( !str || str != "water" ) {
        add_failed_mess("Try \"pump water\" to use the pump.\n");
        return 0;
    }

    if( well->query_closed() ) {
        str = ( data->cover_name ? "all over the "+data->cover_name+" and " :
            "") + "onto the ground";
        water = clone_object(WATER_OBJ);
        water->move(TO);
    } else {
        str = "into the "+query_well_name();
        do_fill_well();
    }

    add_succeeded_mess("$N operate$s the "+data->pump_name+" and water "
        "cascades "+str+".\n");
    return 1;

} /* do_pump_water() */

/** @ignore yes */
void init() {
    if( data->cover_name )
        add_command("move", "<string'object'>", (: do_move_cover($4[0]) :) );
    if( data->pump_name )
        add_command("pump", "<string'water'>", (: do_pump_water($4[0]) :) );
} /* init() */

/** @ignore yes */
void reset() {
    if( data ) {
        if( !well )
            make_well();
        do_fill_well();
    }
} /* reset() */

/** @ignore yes */
void dest_me() {
    if( well )
        well->dest_me();
} /* dest_me() */

/** @ignore yes */
mixed stats() {
    if( data )
        return ({ ({ "well name" , query_well_name() }),
                  ({ "well pump name", data->pump_name }),
                  ({ "well cover name", data->cover_name }),
                  ({ "well max volume", data->max_volume }),
               });

    return ({ });

} /* stats() */
