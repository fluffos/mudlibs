// Created by Cyanide for Sophia
//Modified June 12, 2000 by Shya for her monster
inherit OBJECT;

#define TYPES ({ "oatmeal", "sugar", \
"mint", "peanut butter", "pecan",  \
"chocolate chip", "oreo" })

// Prototype
void set_cookie_type();

string cookie_type;

void create() {
    set_cookie_type();   // Setsn a random type
    set("author", "cyanide");
    set("long", wrap("Definitely the tastiest "+cookie_type+
	" cookie you have ever seen!") );
    set("short", article(cookie_type)+" "+cookie_type+" cookie");
    set("id", ({ "cookie" }) );
}

void init() {
    add_action("throw", "throw");
    add_action("throw", "toss");
    add_action("eat", "eat");
}

void set_cookie_type() {
    int i;

    i = random(sizeof(TYPES));
    cookie_type = TYPES[i];
}

int eat( string str ) {
    // If this object can't be referred to as 'cookie', 
    // ignore the request
    if (!id(str)) { return 0; }

    write("The best "+cookie_type+" cookie you've ever had!\n");
    say(TPN+" eats "+possessive(TP->query("gender"))+" "+
      cookie_type+" cookie and smiles happily.\n");
    remove();
    return 1;
}

int throw( string str ) {
    string tmp;
    object ob;

    sscanf(str, "%s at %s", tmp, str);
    sscanf(str, "%s to %s", tmp, str);

    if (!tmp) {   // The player didn't use 'at' or 'to'
	write("Throw the cookie to whom?\n");
	return 1;
    }

    ob = find_player( str );

    if (!ob) {
	write(capitalize(str)+" isn't on the MUD!\n");
	return 1;
    }

    if (ob->query("busy")) {
	write("That person is busy at the moment...\n");
	return 1;
    }

    write("You throw "+article(cookie_type)+" "+
      cookie_type+" cookie at "+ob->query("cap_name")+".\n");
    say(TPN+" throws a cookie across the MUD!\n");
    tell_object(ob, TPN+" tosses "+article(cookie_type)+" "+
      cookie_type+
      " cookie to you.\n");

    TO->move( ob );

    return 1;
}
int query_auto_load() { return 1; } 

/* End of file */
