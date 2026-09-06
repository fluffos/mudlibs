#include "../priest.h"

string *prayers;

create() {
    prayers = ({
      "Pater noster, qui es in caelis, sanctificetur nomen tuum. Adveniat regnum tuum. Fiat voluntas tua, sicut in caelo et in terra. Panem nostrum quotidianum da nobis hodie, et dimitte nobis debita nostra sicut et nos dimittimus debitoribus nostris. Et ne nos inducas in tentationem, sed libera nos a malo. Amen.",
      "Verbum supernum prodiens, Nec Patris linquens dexteram, Ad opus suum \
exiens, Venit ad vitae vesperam.",
      "In mortem a discipulo Suis tradendus aemulis, Prius in vitae ferculo Se \
tradidit discipulis.",
      "Quibus sub bina specie Carnem dedit et sanguinem; Ut duplicis \
substantiae Totum cibaret hominem.",
      "Se nascens dedit socium, Convescens in edulium, Se moriens in pretium, \
Se regnans dat in praemium.",
      "O salutaris hostia, Quae caeli pandis ostium, Bella premunt hostilia; \
Da robur, fer auxilium.",
      "Uni trinoque Domino Sit sempiterna gloria: Qui vitam sine termino Nobis \
donet in patria. Amen.",
    });
}

status pray_cmd(object who, object sym, string arg)
{
    string str;
    status quietly;

    if(arg) {
	if(arg != "quietly")
	    return notify_fail("Pray what?? (quietly?)"),0;
	else quietly = 1;
    }

    if(who->query_ghost()) return 0;

    if(environment(who)->is_priest_sanctum() && VESPER_D->query_vespers()) {
	if(DELAY_D->query_delay(who, DELAY_TYPE_VESPER)>=0) {
	    sym->inc_faith(3 + random(3));
	    DELAY_D->add_delay(who, DELAY_TYPE_VESPER, VESPER_DELAY);
	}
	who->tell_me("You chant a humble prayer and feel the presence of "
	  GOD_NAME " everywhere around you.");
	environment(who)->tell_here(sprintf("%s chants a prayer for %s.",
	    capitalize(who->query_real_name()), GOD_NAME), who);
	return 1;
    }
    if(DELAY_D->query_delay(who, DELAY_TYPE_PRAY)>=0) {
	sym->inc_faith(1);
	DELAY_D->add_delay(who, DELAY_TYPE_PRAY, PRAY_DELAY);
    }
    str = prayers[random(sizeof(prayers))];
    if(quietly) environment(who)->tell_here(
	  ":%<me.capname>% mumbles a prayer.",0,0,who,who,0,0);
    else
	environment(who)->tell_here(
	  ":%<me.capname>% utters a prayer: %<1>%.",0,({0,str}),who,who,0,0);
    who->tell_me(sprintf("You pray%s: %s", quietly ? " quietly": "", str));
    return 1;
}
