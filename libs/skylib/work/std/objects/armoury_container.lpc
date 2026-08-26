/**
 * This object is used by the armoury to act as a bare bones container,
 * so that your moves would be hundreds of times faster.
 * @author Sandoz
 */

/** @ignore yes */
int no_event_enter() { return 1; }

/** @ignore yes */
int no_init() { return 1; }

/** @ignore yes */
string query_name() { return "armoury recycle bin"; }

/** @ignore yes */
int test_remove( object thing, int flag, mixed dest ) { return 1; }

/** @ignore yes */
int test_add( object thing, int flag ) { return 1; }

/** @ignore yes */
int add_weight( int number ) { return 1; }

/** @ignore yes */
void dest_me() {
    INV(TO)->dest_me();
    destruct(TO);
} /* dest_me() */
