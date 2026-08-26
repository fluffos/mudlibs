/**
 * Doll
 * Mahray
 */

#define POSITIONS ({ "upwards", "backwards", "downwards", "sideways" })

inherit OBJECT_OBJ;

int pos;

void setup(){
    set_name("doll");
    set_short("wooden doll");
    add_extra_look(TO);
    add_adjective("wooden");
    add_alias("toy");
    add_plural("toys");

    set_long("This is a rather poorly made wooden doll.  There are numerous "
        "marks where the carver has slipped, and it is dressed in cheap "
        "cotton clothing.  Its arms and legs can be moved around to make "
        "it assume different positions.\n");

    set_weight(15);
    set_value(250);

} /* setup */

void init(){
    TP->add_command("move", TO,
        "{arms|legs|limbs} [of|on] <direct:object:me>");
} /* init */

int do_move() {
    int i;

    i = random( sizeof( POSITIONS ) );
    if( i == pos )
        i = ( i + 1 ) % sizeof( POSITIONS );
    pos = i;

    add_succeeded_mess("$N fiddle$s with the limbs of $D, and manage$s to "
        "move some of them to different positions.\n");
    return 1;

} /* do_move */

/** @ignore yes */
mapping query_dynamic_auto_load() {
    mapping map;
    if( !clonep(TO) )
        return 0;
    map = ([ "::" : ::query_dynamic_auto_load() ]);
    if( pos )
        map["pos"] = pos;
    return map;
} /* query_dynamic_auto_load() */

/** @ignore yes */
void init_dynamic_arg( mapping map ) {
    if( map["::"] )
        ::init_dynamic_arg( map["::"] );
    if( map["pos"] )
        pos = map["pos"];
} /* init_dynamic_arg() */

string extra_look() {
    return "The limbs of the wooden doll are pointing vaguely "+
           POSITIONS[pos]+".\n";
} /* extra_look() */
