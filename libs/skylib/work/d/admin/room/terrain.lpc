
#include <terrain.h>

inherit ROOM_OBJ;

string terrain_name;
object generator;

void setup() {
    set_short("terrain-maker room");
    set_determinate("the ");
    set_light( 100 );

    set_long("This room is quite bare, save a notice that has been "
        "taped on the door.  The walls have been painted with scenes of "
        "deserts and forests, oceans and mountains, caves and swamps, "
        "and all manner of other types of terrains.\n"
        "Use \"help here\" to list the room's commands.\n");

    add_exit("common", "/d/admin/common", "path" );

    add_sign("The large notice has furled corners and has been taped "
      "and re-taped to the door.\n",
      "Due to the incomprehensible help in this room, this \n"
      "notice was put up to help with the confusion.\n"
      "\n"
      "1.  To get information on a certain terrain, you\n"
      "    need to select that terrain by typing \n"
      "    \"terrain <terrain_name>\".\n"
      "\n"
      "2.  To remove floating or fixed locations within the terrain,\n"
      "    type \"list floating\" or \"list fixed\".\n"
      "\n"
      "    remove floating <path of terrain> <all 6 co ordinates> <level>\n"
      "    remove fixed <path of room>\n"
      "\n"
      "3.  To add a floating location, same as above, only use add.\n"
      "    For both removing and adding, no commas and no .c at the end\n"
      "    of path names.  When removing/adding fixed locations, all\n"
      "    locations must be done one by one.\n", 0, "notice");

} /* setup() */

void reset() {
    if( !generator ) {
        generator = clone_object("/handlers/terrain_things/dungeon_maker");
        generator->move(TO);
    }
} /* reset() */

mixed help_function() {
    return "The available commands are:\n\n"+
           "    terrain  -  set terrain name\n"+
           "    list     -  list locations in current terrain\n"+
           "    member   -  find locations matching coordinates\n"+
           "    add      -  add a new location\n"+
           "    remove   -  remove an old location\n"+
           "    clear    -  clear all clones and connections\n";
} /* help_function() */

int do_terrain( string name ) {
    if( !name ) {
        if( stringp( terrain_name ) )
            write("Terrain name is "+ terrain_name +".\n");
        else
            write("There is no terrain name set.\n");
        return 1;
    }

    write("Terrain name set to "+name+".\n");
    terrain_name = name;
    return 1;

} /* do_terrain() */

int do_list( string word ) {
    int i, size, cols;
    string list;
    mapping locations;
    mixed keys, values;

    if( !terrain_name ) {
        write("There is no current terrain name.\n");
        return 1;
    }

    if( !TERRAIN_MAP->get_data_file( terrain_name ) ) {
        write("There are no locations in the terrain "+terrain_name+".\n");
        return 1;
    }

    cols = (int)TP->query_cols();

    if( word == "fixed" ) {
        locations = (mapping)TERRAIN_MAP->query_fixed_locations( terrain_name );
        size = sizeof( locations );

        if( !size ) {
            write( "There are no fixed locations in the terrain "+
                terrain_name+".\n");
            return 1;
        }

        keys = keys( locations );
        values = values( locations );

        list = "The terrain "+terrain_name+" has the following fixed "
            "location"+( size == 1 ? "" : "s")+":\n";

        for( i = 0; i < size; i++ )
            list += sprintf("% 5d - %-=*s\n", i + 1, cols - 9,
                keys[ i ]+" at ("+values[ i ][ 0 ]+", "+values[ i ][ 1 ]+", "+
                values[ i ][ 2 ]+")");
        TP->more_string( list, "Fixed");
        return 1;
    }

    locations = (mapping)TERRAIN_MAP->query_floating_locations( terrain_name );
    size = sizeof( locations );

    if( !size ) {
        write( "There are no floating locations in the terrain "+
            terrain_name+".\n");
        return 1;
    }

    list = "The terrain "+ terrain_name +" has the following floating "+
        "location"+ ( size == 1 ? "" : "s")+":\n";

    for( i = 0; i < size; i++ )
        if( sizeof( locations[ i ][ 1 ] ) == 3 )
            list += sprintf("% 5d - %-=*s\n", i + 1, cols - 9,
                locations[ i ][ 0 ]+" at ("+locations[ i ][ 1 ][ 0 ]+", "+
                locations[ i ][ 1 ][ 1 ]+", "+locations[ i ][ 1 ][ 2 ]+
                "), level "+locations[ i ][ 2 ] );
        else
            list += sprintf("% 5d - %-=*s\n", i + 1, cols - 9,
                locations[ i ][ 0 ]+" from ("+locations[ i ][ 1 ][ 0 ]+", "+
                locations[ i ][ 1 ][ 1 ]+", "+locations[ i ][ 1 ][ 2 ]+
                ") to ("+locations[ i ][ 1 ][ 3 ]+", "+
                locations[ i ][ 1 ][ 4 ]+", "+
                locations[ i ][ 1 ][ 5 ]+"), level "+ locations[ i ][ 2 ] );

    TP->more_string( list, "Floating");
    return 1;

} /* do_list() */

int do_member( string type, int *co_ords ) {
    int i, size, cols;
    string list, location;
    mixed locations;

    if( !terrain_name ) {
        write("There is no current terrain name.\n");
        return 1;
    }

    if( type == "fixed" ) {
        TERRAIN_MAP->get_data_file( terrain_name );
        location = (string)TERRAIN_MAP->member_fixed_locations( co_ords );

        if( !location ) {
            write("There is no fixed location in the terrain "+
                terrain_name+" at ("+co_ords[ 0 ]+", "+co_ords[ 1 ]+", "+
                co_ords[ 2 ]+").\n");
            return 1;
        }
        write("The terrain "+terrain_name+" has "+location+" as a fixed "+
            "location at ("+co_ords[ 0 ]+", "+co_ords[ 1 ]+", "+
            co_ords[ 2 ]+").\n");
        return 1;
    }

    TERRAIN_MAP->get_data_file( terrain_name );
    locations = (mixed *)TERRAIN_MAP->member_floating_locations( co_ords );
    size = sizeof( locations ) / 2;

    if( !size ) {
        write("There are no floating locations in the terrain "+
            terrain_name+" at ("+co_ords[ 0 ]+", "+co_ords[ 1 ]+", "+
            co_ords[ 2 ]+").\n");
        return 1;
    }

    list = "There "+( size == 1 ? "is one floating location" :
        "are "+query_num( size )+" floating locations")+" in the terrain "+
        terrain_name+" at ("+co_ords[ 0 ]+", "+co_ords[ 1 ]+", "+
        co_ords[ 2 ]+"):\n";

    cols = (int)TP->query_cols();

    for( i = 0; i < size; i++ )
        list += sprintf("% 5d - %-=*s\n", i + 1, cols - 9,
            locations[ 2 * i ]+", level "+locations[ 2 * i + 1 ] );

    TP->more_string( list, "Member");
    return 1;

} /* do_member() */

int do_add( string type, string location, int *co_ords, int level ) {
    if( !terrain_name ) {
        write("There is no current terrain name.\n");
        return 1;
    }

    if( type == "fixed" ) {
        if( !TERRAIN_MAP->add_fixed_location( terrain_name, location, co_ords ) ) {
            write("The fixed location "+location+" in the terrain "+
                terrain_name+" already exists.\n");
            return 1;
        }
        write("The fixed location "+location+" has been added to the "
            "terrain "+terrain_name+" at coordinates ("+co_ords[ 0 ]+", "+
            co_ords[ 1 ]+", "+co_ords[ 2 ]+").\n");
        return 1;
    }

    TERRAIN_MAP->add_floating_location( terrain_name, location, co_ords, level );

    if( sizeof( co_ords ) == 6 )
        write("A floating location using "+location+" has been added to the "+
            "terrain "+terrain_name+" from coordinates ("+co_ords[ 0 ]+", "+
            co_ords[ 1 ]+", "+co_ords[ 2 ]+") to coordinates ("+co_ords[ 3 ]+
            ", "+co_ords[ 4 ]+", "+co_ords[ 5 ]+") at level "+level+".\n");
    else
        write("A floating location using "+location+" has been added to the "+
            "terrain "+terrain_name+" at coordinates ("+co_ords[ 0 ]+", "+
            co_ords[ 1 ]+", "+co_ords[ 2 ]+") and level "+level+".\n");

    return 1;

} /* do_add() */

int do_remove( string type, string file, int *co_ords ) {
    if( !terrain_name ) {
        write("There is no current terrain name.\n");
        return 1;
    }

    if( type == "fixed" ) {
        if( !TERRAIN_MAP->delete_fixed_location( terrain_name, file ) ) {
            write("There is no fixed location "+file+" in the terrain "+
                terrain_name+" to remove.\n");
            return 1;
        }
        write("The fixed location "+file+" has been removed from the "
            "terrain "+terrain_name+".\n");
        return 1;
    }

    if( !TERRAIN_MAP->delete_floating_location( terrain_name, file, co_ords ) ) {
        if( sizeof( co_ords ) == 6 )
            write("There is no floating location using "+file+" in the "
                "terrain "+terrain_name+" from coordinates ("+co_ords[ 0 ]+
                ", "+co_ords[ 1 ]+", "+co_ords[ 2 ]+") to coordinates ("+
                co_ords[ 3 ]+", "+co_ords[ 4 ]+", "+co_ords[ 5 ]+") to "
                "remove.\n");
        else
            write("There is no floating location using "+file+" in the "
                "terrain "+terrain_name+" at coordinates ("+co_ords[ 0 ]+
                ", "+co_ords[ 1 ]+", "+co_ords[ 2 ]+") to remove.\n");
        return 1;
    }

    if( sizeof( co_ords ) == 6 )
        write("The floating location using "+file+" in the terrain "+
            terrain_name+" from coordinates ("+co_ords[ 0 ]+", "+
            co_ords[ 1 ]+", "+co_ords[ 2 ]+") to coordinates ("+
            co_ords[ 3 ]+", "+co_ords[ 4 ]+", "+co_ords[ 5 ] +") has been "
            "removed.\n");
    else
        write("The floating location using "+file+" in the terrain "+
            terrain_name+" at coordinates ("+co_ords[ 0 ]+", "+
            co_ords[ 1 ]+", "+co_ords[ 2 ]+") has been removed.\n");

    return 1;

} /* do_remove() */

int do_clear() {
    if( !terrain_name ) {
        write("There is no current terrain name.\n");
        return 1;
    }

    TERRAIN_MAP->clear_cloned_locations( terrain_name );
    TERRAIN_MAP->clear_connections( terrain_name );

    write("Clones and connections cleared for the terrain "+
        terrain_name+".\n");
    return 1;

} /* do_clear() */

void init() {
    ::init();

    add_command("terrain", "<string'name'>", (: do_terrain($4[0]) :) );
    add_command("terrain", "", (: do_terrain(0) :) );

    add_command("list", "{fixed|floating}", (: do_list($4[0]) :) );

    add_command("member", "{fixed|floating} "
        "<number'coord1'> <number'coord2'> <number'coord3'>",
        (: do_member( $4[0], $4[1..3] ) :) );

    add_command("add", "fixed <string'file'> <number'coord1'> "
        "<number'coord2'> <number'coord3'>",
        (: do_add("fixed", $4[1], $4[2..4], 0 ) :) );
    add_command("add", "floating <string'file'> <number'coord1'> "
        "<number'coord2'> <number'coord3'> <number'level'>",
        (: do_add("floating", $4[1], $4[2..4], $4[5] ) :) );
    add_command("add", "floating <string'file'> <number'coord1'> "
        "<number'coord2'> <number'coord3'> <number'coord4'> "
        "<number'coord5'> <number'coord6'> <number'level'>",
        (: do_add("floating", $4[1], $4[2..7], $4[8] ) :) );

    add_command("remove", "fixed <string'file'>",
        (: do_remove("fixed", $4[0], 0 ) :) );
    add_command("remove", "floating <string'file'> <number'coord1'> "
        "<number'coord2'> <number'coord3'>",
        (: do_remove("floating", $4[1], $4[2..4] ) :) );
    add_command("remove", "floating <string'file'> <number'coord1'> "
        "<number'coord2'> <number'coord3'> <number'coord4'> "
        "<number'coord5'> <number'coord6'>",
        (: do_remove("floating", $4[1], $4[2..7] ) :) );

    add_command("clear", "");

} /* init() */
