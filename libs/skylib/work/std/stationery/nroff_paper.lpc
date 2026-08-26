
inherit PAPER_OBJ;

string file_name;

/** @ignore yes */
void create() {
    seteuid(getuid());
    ::create();
} /* create() */

void set_file_name(string fname) {
    file_name = fname;
} /* set_file_name() */

string query_file_name() {
    return file_name;
} /* query_file_name() */

/** @ignore yes */
mixed query_read_mess() {
    mixed stuff;
    string str;

    stuff = ({ });
    if( file_name ) {
        str = unguarded( (: NROFF_H->cat_file( file_name+"_nroff", 1 ) :) );
        if( !str ) {
            unguarded( (: NROFF_H->create_nroff( file_name,
                file_name+"_nroff") :) );
            str = unguarded( (: NROFF_H->cat_file( file_name+"_nroff",
                1 ) :) );
        }
        if( str ) {
            stuff = ({ ({ str, 0, "common", 0 }) });
        } else {
            stuff = ({ ({"Unable to nroff file.\n", 0, "common", 0 }) });
        }
    }

    return ::query_read_mess() + stuff;

} /* query_read_mess() */
