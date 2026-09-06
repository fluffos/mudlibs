// This daemon is used to check, if a player can change his order (deity)

#include "../priest.h"

#define SAVE_FILE PRIEST_SAVE_DIR "order_change"

#define MAX_COEF_REQUIREMENT 5000

mapping players;

create() {
    restore_object(SAVE_FILE);
    if(!players || !mappingp(players)) players = ([]);
}

status can_change_order(object pl) {
    object coef_required;
    object sym;

    if(!pl) return 0;
    if(!(coef_required = players[pl->query_real_name()])) return 1;
    if(!(sym = pl->query_guild_object())) return 0;
    if(coef_required <= sym->query_coef()) return 1;
    return 0;
}

void order_changed(object pl) {
    object sym;
    int cur_coef, coef_required;

    if(!pl) return;
    if(!(sym = pl->query_guild_object())) return;
    cur_coef = sym->query_coef();
    if((coef_required = cur_coef/10) > MAX_COEF_REQUIREMENT)
	coef_required = MAX_COEF_REQUIREMENT;
    players[pl->query_real_name()] = cur_coef + coef_required;
    save_object(SAVE_FILE);
}

debug() {
    printf("%O\n", players);
}
