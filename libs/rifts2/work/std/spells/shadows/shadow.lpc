//	A generic shadow which handles updating the linked list
//	via a couple duct-tape-style patches I made to the driver
//	DarkeLIB 0.1
//	-Diewarzau 7/18/95
//	P.S. Hey is it my fault the can't code?

nomask mixed begin_shadow(object ob) {
    if(query_shadowing(this_object())) return 0;
    else return shadow(ob, 1);
}

nomask mixed switch_shadow(object ob) {
    if(!query_shadowing(this_object())) return 0;
    else return shadow(ob, 1);
}

nomask mixed stop_shadow() {
    if(!query_shadowing(this_object())) return 0;
    else return shadow(this_object(), -1);
}

varargs nomask object next_shadow(string func) {
    return query_shadowing(this_object());
}

varargs int remove(object last) {
    object prev;

    if(last) prev = last;
    else prev = previous_object();
    if(origin() != "local" && prev && prev != this_object()) {
        if(query_shadowing(this_object()))
	    query_shadowing(this_object())->remove(prev);
	return 0;
    }
    destruct(this_object());
    return 1;
}

void external_destruct(object who) {
    if(!objectp(who) || !query_shadowing(this_object())) return;
    if(who != this_object()) {
      query_shadowing(this_object())->external_destruct(who);
      return;
    }
    destruct(this_object());
}

