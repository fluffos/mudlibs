// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

private int needs_contents;

string short();

//:FUNCTION set_needs_contents
//If needs_contents is 1, then the container can only be drunk from if it
//contains a drink.  Otherwise the 'drink' is assumed to be handled as
//part of the container itself (either by also inheriting M_DRINKABLE or
//otherwise).
void set_needs_contents(int x) {
    needs_contents = 1;
}

mixed direct_drink_from_obj() {
    object ob;
    
    if (this_object()->query_closed())
        return short() + "是关着的。\n";

    if (needs_contents)
        ob = first_inventory();
    else
        ob = this_object();
    
    if (!ob)
        return short() + "是空的。\n";

    return ob->direct_drink_obj();
}

void drink_from_it() {
    object ob;
    
    if (needs_contents)
        ob = first_inventory();
    else
        ob = this_object();

    ob->drink_it();
}

