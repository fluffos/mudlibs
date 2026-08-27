// Tyrael - Jun'02 - Algo parecido al spell.c para comandos

#include <spells.h>
inherit BASES+"patch";
 
void comando_instant(string sp_eff, object caster, object *victimas)
{
	if (caster->query_property("instant") ||
	random(caster->QL + caster->query_cha()) > random(100)) {
	caster->remove_spell_effect(sp_eff);
	call_other(TO, da_func, params);
	}
}