// The spell object for the fog spell.
// Chronos coded originally.
// 12 Dev 98  Cyanide changed it VERY little, and gave it to mages.

inherit OBJECT;

void create() {
    seteuid(getuid());
    set("id", ({ "fog", "fog cloud", "#FOG_OBJECT#" }) );
    set("prevent_get", 1);
    set("long", @ENDLONG
There is a LOT of fog in this area, making it difficult to see anything.
ENDLONG
    );
    set("short", "There is a lot of fog here making it difficult to see.\n");
}

int start_spell(int duration) {
    if (!duration) duration = 1;
    call_out("remove", 30 * duration);
    environment()->set("no_vision", "You can't see a thing through the fog here.\n");
    return 1;
}

void
remove() {
    if (environment()) {
	tell_room(environment(), "The fog dissipates slowly.\n");
	environment()->delete("no_vision") ;
    }
    :: remove() ;
}

/* EOF */
