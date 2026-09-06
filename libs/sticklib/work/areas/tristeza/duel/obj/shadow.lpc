/*
**
** (C) Tron.
**
** shadow.c - basic shadow ob
**
*****************************/

public  object shadowed;
private string short, long;

status
do_shadow(object ob) {
    if(ob->query_prevent_shadow())
    {
	call_out("undo_shadow", 1);
	return 0;
    }

    shadowed=ob;
    shadow(ob);

    return 1;
}

void
undo_shadow() {
    destruct(this_object());
}

object *
query_shadow(object ob) {
    object sh;
    object *ret;

    if(!ob) sh=this_object();
    else sh=ob;

    if (shadow(sh)) {
	ret=({sh});

	while (sh)
	    if(shadow(sh))
		ret+=({sh});
    }

    return ret;
}

void
set_short(string str) {short=str;}

void
set_long(string str) {long=str;}

string
short() {
    if(!short)
	return (string)shadowed->short();

    return short;
}

string
query_long() {
    if(!long)
	return shadowed->query_long();
}
