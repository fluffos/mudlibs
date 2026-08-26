// a_sword - An Ornate Rapier
// Carried by the thief in the Labyrinth of Woe

inherit WEAPON;

void create() {
    set("short", "an ornate rapier");
    set("long", "@@query_long");
    set("name", "ornate rapier");
    set("id", ({ "sword", "rapier", "ornate rapier" }) );
    set_weapon_type("sword/short");
    set_bonus(3);
    set("value", 4000);
    set ("wield_func", "glow") ;
    set ("unwield_func", "noglow") ;
    set("natt_bonus", 1);
}

string query_long() {
    string str = (@EndLong
An exquisite example of craftsmanship, this beautiful weapon is
crafted of the finest steel, and is set with diamonds and rubies.
EndLong
    );
    if (query("light"))
	str += "The sword is glowing brightly.\n";

    return str;
}

void glow() {
    write ("The sword begins to glow in your hand.\n") ;
    say ("The sword begins to glow in "+
      possessive(this_player()->query("gender"))+" hand.\n") ;  
    set ("light", 1) ;
}

void noglow() {
    write ("The sword stops glowing.\n") ;
    say ("It ceases to glow.\n") ;
    set("light", 0) ;
}
