inherit ARMOR;

int access = 0;
string color = "white";

void set_color( int c_int ) {
    switch(c_int) {
    case 1..2 : color = "blue"; break;
    case 3 : color = "green"; break;
    case 4 : color = "yellow"; break;
    case 5 : color = "orange"; break;
    case 6 : color = "red"; break;
    case 7 : color = "gold"; break;
    case 8 : color = "platinum"; break;
    default : color = "white"; c_int = 0; break;
    }
    access = c_int;
    set("value", c_int * 50);
}

int query_access() { return access; }

string query_short() { return "a "+color+" ID badge"; }

string query_long() {
    string long;

    long = "A combination ID badge and card key. It appears "+
    "to be made to 'swipe' through special electronic "+
    "locks.";

    return wrap(long);
}

string query_color() { return color; }

void create() {
    set_armor_type("amulet");
    set("dest_at_sell", 1);
    set("color", "@@query_color");
    set("id", ({ "badge", "key", "card key", 
      "card", "#CARD#", query("color")+" badge" }) );
    set("short", "@@query_short");
    set("long", "@@query_long");
}

