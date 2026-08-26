
inherit ROOM_OBJ;

mapping room_cont, shop_type;
int max_num, loot;

void create() {
    room_cont = ([ ]);
    shop_type = ([ ]);
    max_num = 8;
    ::create();
    loot = random(10);
    set_keep_room_loaded( 1 );
    call_out("test_cont", 1 );
} /* create() */

mapping query_room_cont() { return room_cont; }

int query_max_num() { return max_num; }

void set_max_num(int i) { max_num = i; }

void add_thing( object ob ) {
    string shr;

    if( !ob || ENV(ob) != TO )
        return;

    shr = (string)ob->query_property("shop type");
    if( !shop_type[shr] )
        shop_type[shr] = ({ ob });
    else
        shop_type[shr] += ({ ob });

    shr = (string)ob->short();

    if( !room_cont[shr] ) {
        room_cont[shr] = ({ ob });
        return;
    }

    if( sizeof(room_cont[shr]) > max_num )
        call_out("do_dest", 1, ob );
    else
        room_cont[shr] += ({ ob });

    return;

} /* add_thing() */

/* for updating etc... */
void test_cont() {
    map( INV(TO), (: add_thing($1) :) );
} /* test_cont() */

void remove_thing( object ob ) {
    mixed arr;
    int i;
    string sh;

    if( !ob || ENV(ob) == TO )
        return;

    sh = (string)ob->query_property("shop type");
    if( shop_type[sh] )
        shop_type[sh] = shop_type[sh] - ({ ob });

    sh = (string)ob->short();
    if( !room_cont[sh] )
        return;

    arr = room_cont[sh];
    if( ( i = member_array( ob, arr ) ) == -1 )
        return;

    if( sizeof(arr) <= 1 ) {
        map_delete( room_cont, sh );
    } else
        room_cont[sh] = delete( arr, i, 1 );

} /* remove_thing() */

void event_enter( object ob ) {
    call_out("add_thing", 1, ob );
} /* event_enter() */

void event_exit( object ob, string mesage, object to ) {
    call_out("remove_thing", 1, ob );
} /* event_exit() */

void do_dest( object thing ) {
    if( !thing )
        return;
    thing->move("/room/rubbish");
} /* do_dest() */

mapping query_shop_type_mapping() { return shop_type; }

int clean_up( int parent ) { return 0; }
