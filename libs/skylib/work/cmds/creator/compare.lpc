
#include <creator.h>

inherit COMMAND_BASE;

/** @ignore yes */
string format_data( object *items, object victim, object target ) {
    int size;
    string vname, tname;

    vname = victim->the_short();
    tname = target->the_short();

    switch( size = sizeof( items ) ) {
      case 0:
        if( victim == TP )
            return "None of your objects were cloned by "+tname;
        return "No objects in "+vname+" were cloned by "+tname;
      case 1:
        return "One object, "+items[0]->the_short()+" in "+
            victim->poss_short()+" whole inventory was cloned by "+tname;
      default:
        return query_num( size )+" objects in "+
            victim->poss_short()+" whole inventory were cloned by "+tname;
    }

} /* format_data() */

/** @ignore yes */
void describe_objects( object p1, object p2 ) {
    object *obs;

    obs = filter( deep_inventory(p1), (: $1->query_cloned_by() &&
        $1->query_cloned_by() == $2 :), p2->query_name() );

    tell_object( TP, "$P$compare$P$"+format_data( obs, p1, p2 )+".\n");

} /* describe_objects() */

/** @ignore yes */
int cmd( object player1, object player2 ) {
    describe_objects( player1, player2 );
    describe_objects( player2, player1 );
    return 1;
} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({ "<indirect:wiz-present> {against|with|and} "
      "<indirect:wiz-present>",
      (: cmd( $1[0][0], $1[1][0] ) :) });
} /* query_patterns() */
