/*  /std/autogm.c

 *  Made for DarkeMUD

 *  Created by Geldron 071096

 *  Copyright (c) 1996

 *  Do not remove this header

 */



int drop() {

    if(TP && TO->query_short())

	message("drop", "You must keep " + LOW(TO->query_short()) + ".", TP);

    return 1;

}



int put() {

    if(TP && TO->query_short())

	message("put", "You must keep " + LOW(TO->query_short()) + ".", TP);

    return 1;

}



int get() {

    if(TP && TO->query_short())

	message("get", "You must keep " + LOW(TO->query_short()) + ".", TP);

    return 1;

}



int query_always_keep() { return 1; }



string *query_auto_load() { return({ ({ base_name(TO) }), ({ }) }); }

