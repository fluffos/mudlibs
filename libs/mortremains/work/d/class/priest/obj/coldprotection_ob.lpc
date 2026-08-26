//ilz-2

#include <p_spells.h>              
#include <magic.h>

inherit OBJECT;

void create() {
    seteuid(getuid());
    set("id", ({ "#PROT_COLD#" }) );
    set("prevent_drop", 1);
    set("dest_at_die", 1);
}

int begin_spell(object caster) {
    set("level", caster->query_level());

    set("enchantment", DIM);
    set("schools", ({ "abjuration" }) );
    caster->resistance("cold", 50);

    message("spell", "You feel more resistant to cold, now.\n",
      caster);
    call_out("remove", caster->query_level() * 30 );
    return 1;
}

int remove() {
    object caster = environment(this_object());

    if ((caster) && living(caster)) {
	tell_object(caster, "Your protection from cold spell ends.\n");
	caster->resistance("cold", 200); 
    }
    return ::remove();
}                                                  

/* EOF */
