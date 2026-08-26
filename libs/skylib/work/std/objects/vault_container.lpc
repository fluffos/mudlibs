/**
 * This is a custom vault container.  Do not use it if you
 * are not absolutely certain in what you are doing, use
 * /obj/cont_save instead.
 * @author Sandoz, 2002.
 */

nosave inherit BAGGAGE_OBJ;

nosave string save_file, size;
private nosave int no_save, call_id, change;

/** @ignore yes */
private void init_save() {
    if( call_id ) {
        remove_call_out( call_id );
        call_id = 0;
    }

    if( !no_save && find_call_out("do_save") == -1 )
        call_id = call_out("do_save", 1 );

} /* init_save() */

/** @ignore yes */
int test_remove( object thing, int flag, mixed dest ) {
    change = 1;
    init_save();
    return ::test_remove( thing, flag, dest );
} /* test_remove() */

/** @ignore yes */
int test_add( object ob, int flag ) {
    change = 1;
    init_save();
    return 1;
} /* test_add() */

/** @ignore yes */
void forced_save() {
    if( save_file && save_file != "") {
        unguarded( (: write_file, save_file,
            save_variable( query_dynamic_auto_load() ), 1 :) );
    }
} /* forced_save() */

/** @ignore yes */
void do_save() {
    if( call_id )
        remove_call_out( call_id );

    if( change && !no_save && save_file && save_file != "") {
        change = 0;
        unguarded( (: write_file, save_file,
            save_variable( query_dynamic_auto_load() ), 1 :) );
    }

} /* do_save() */

/** @ignore yes */
void check_euid() {
    if( PO )
        seteuid( geteuid( PO ) );
} /* check_euid() */

/** @ignore yes */
void set_no_save( int i ) { no_save = i; }

/** @ignore yes */
void set_size( string str ) { size = str; }

/**
 * This method returns the current save file for the container.
 * @return the current save file
 */
string query_save_file() { return save_file; }

/** @ignore yes */
void set_save_file( string file, object thing ) {
    mixed data;

    if( !stringp(file) || file == "") {
        printf("Trying to set an invalid save file.\n");
        return;
    }

    if( file[<2..] != ".o" )
        file += ".o";

    save_file = file;

    INV(TO)->dest_me();

    if( sizeof(INV(TO)) )
        map( INV(TO), (: destruct($1) :) );

    if( !no_save && file_exists( save_file ) ) {
        if( data = unguarded( (: read_file, save_file :) ) )
            data = restore_variable( data );
    }

    if( thing )
        set_player( thing );

    if( sizeof( data ) ) {
        int s_tmp, c_tmp;
        s_tmp = no_save;
        c_tmp = change;
        no_save = 1;
        init_dynamic_arg( data, 0 );
        no_save = s_tmp;
        change = c_tmp;
    }

} /* set_save_file() */

/** @ignore yes */
string short( int dark ) {
    if( size )
        return size+" "+::short( dark );
    return ::short( dark );
} /* short() */

/** @ignore yes */
string long( string word, int dark ) {
    string str;

    switch( query_loc_weight() * 100 / query_max_weight() ) {
      case 0 :
        str = "";
      break;
      case 1..10 :
        str = "It is almost completely empty.\n";
      break;
      case 11..25 :
        str = "It is almost empty.\n";
      break;
      case 26..45 :
        str = "It is less than half full.\n";
      break;
      case 46..55 :
        str = "Is is about half full.\n";
      break;
      case 56..75 :
        str = "It is more than half full.\n";
      break;
      case 76..90 :
        str = "It is almost full.\n";
      break;
      case 91..99 :
        str = "It is almost completely full.\n";
      break;
      default :
        str = "It is quite full.\n";
    }

    if( size )
        return replace_string( ::long( word, dark ), "$size$", size ) + str;

    return ::long( word, dark ) + str;

} /* long() */

/** @ignore yes */
string *parse_command_adjectiv_id_list() {
    if( size )
        return explode( size, " ") + ::parse_command_adjectiv_id_list();
    return ::parse_command_adjectiv_id_list();
} /* parse_command_adjectiv_id_list() */

/** @ignore yes */
mixed stats() {
    return ::stats() + ({
        ({"owner", query_ownership() }),
        ({"size", size }),
        ({"no save", no_save }),
        ({"change", change }),
        ({"save file", save_file }),
    });
} /* stats() */
