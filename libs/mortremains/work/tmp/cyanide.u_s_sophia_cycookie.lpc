// Created by Cyanide for Sophia

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
      cookie_type+" cookie and smile happily.\n");
    remove();
    return 1;
}

/* End of file */
