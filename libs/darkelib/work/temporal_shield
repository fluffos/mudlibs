inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","temporal shield");
    set_property("skill","energy manipulation");
    set_property("casting time",7);
    set_property("base mp cost", 60);
    set_property("dev cost", 50);
    set_property("fast dev cost", 120);
    set_property("spell level", 26);
    set_property("moon", "ankh");
    set_property("caster message",
		 "A flux of time forms around $T. ");
    set_property("target message","A flux of time forms around you.");
    set_property("observer message",
		 "A flux of time forms around $T.");
    set_property("spell type",({ "protection" }));
    set_property("target type", "living");
    set_property("protection types", ([ "aether" : 5, "plasma" : 5, "time" : 5, "stress" : 5]) );
    set_property("duration", 280);
    set_property("stack key", "tshield");
    set_property("stack num", 3);
    set_property("must be present", 1);
    return;
}

void info() {
message("help",
"This spell is a kewl magical protection spell.  It protects against all "
"forms of common magical attack.  The protection can be stacked thrice.",
  this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

  ::spell_func(caster, at, power, args, flag);
  return;
}

