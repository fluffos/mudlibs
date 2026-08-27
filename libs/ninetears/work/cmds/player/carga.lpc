// encumbrance cmd from player.c, now external. Morgoth 2/Mar/95
// Retocado y tracudido por Leviathan'02
// Arreglao pa q los colores no rayen tanto 02.11.2002

#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

void setup() { position = 0; }

string query_usage() { return "carga"; }

string query_short_help() { return "Muestra la carga actual y la carga maxima."; }

int cmd (string arg, object me) {
	int now;
	int max;
	int dif;
	now=me->query_loc_weight();
	max=me->query_max_weight();
	dif=max-now;
	write("\nTu inventario actual pesa %^GREEN%^BOLD%^"+now+"%^RESET%^.\nPuedes "+
		"cargar hasta %^RED%^BOLD%^"+max+"%^RESET%^.\nLo que deja %^YELLOW%^"+
		dif+" %^RESET%^libres en este momento.\n%^RESET%^");
	return 1;
}
