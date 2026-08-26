
inherit OBJECT_OBJ;

object our_pub;

/** @ignore yes */
void create() {
    ::create();
    set_name("menu");
    reset_get();
} /* create() */

/** @ignore yes */
void set_pub(object pub) { our_pub = pub; }

/** @ignore yes */
object query_pub() { return our_pub; }

/** @ignore yes */
void init() { add_command("list", "[menu]"); }

/** @ignore yes */
int do_list() {
    write(our_pub->read());
    TP->add_succeeded(TO);
    return 1;
} /* do_list() */

/** @ignore yes */
mixed query_read_mess() {
    string mess;

    if( our_pub && stringp( mess = our_pub->read() ) && sizeof(mess) )
        return ({ ({ mess, 0, "common", 1 }) }) + ::query_read_mess();

    return ::query_read_mess();

} /* query_read_mess() */

/** @ignore yes */
string long( string str, int dark ) { return (string)our_pub->read(); }
