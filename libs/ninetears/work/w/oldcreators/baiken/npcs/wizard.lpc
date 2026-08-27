// Guldan Jun'98

#include "hechizos.h"
#include "path.h"
inherit "/obj/monster";
#define	MHP	100

int niveles=0,turnos=0,GRADO=0;
string gente="";
object *sombras=({0,0,0,0,0,0});

int query_res(string tipo)
{
    return 7+7*GRADO+::query_res(tipo);
}

void do_death(object killer)
{
    if (killer) write_file("/d/oficios/wizards/logs/"+TO->query_cap_name(),
	  TO->query_cap_name()+" ("+TO->query_level()+") matado por "
	  +killer->query_cap_name()+" ("+killer->query_level()+") "+ctime(time())+".\n"
	  "\tAyudado por "+gente+" ("+niveles+").\n"
	  "\tTurnos: "+turnos+".\n");
    for (int i=0;i<sizeof(sombras);i++) if (sombras[i]) sombras[i]->dest_me();
    tell_room(ENV(TO),"Las sombras invocadas por "+query_cap_name()+" desaparecen "
      "tras su muerte.\n");
    ::do_death(killer);
}

void setup()
{
    //  add_property("invulnerable_hechizos",GRADO);
    //  adjust_tmp_damage_bon(GRADO+1);
    //  adjust_tmp_tohit_bon(GRADO*10+10);
}

void init()
{
    add_attack_spell(10,"misil menor",({"/std/spells/wizard/mmissile","cast_spell",0,0}));
    if (GRADO) add_attack_spell(10*GRADO,"beso",({"/std/spells/wizard/vamp_touch","cast_spell",0,0}));
    if (GRADO) add_attack_spell(10*GRADO,"relampago",({"/std/spells/wizard/lightning","cast_spell",0,0}));
    if (GRADO) add_attack_spell(10*GRADO,"relampago sombra",({"/std/spells/wizard/shadow_lightning","cast_spell",0,0}));
    if (GRADO) add_attack_spell(10*GRADO,"bola fuego",({"/std/spells/wizard/fireball","cast_spell",1,0}));
    if (GRADO) add_attack_spell(10*GRADO,"tormenta hielo",({"/std/spells/wizard/ice_storm","cast_spell",1,0}));
    if (GRADO>1) add_attack_spell(40,"misil mayor",({"/std/spells/wizard/mmmissile","cast_spell",0,0}));
    if (GRADO>2) add_attack_spell(40,"tormenta acida",({"/std/spells/wizard/acid_cloud","cast_spell",1,0}));
    add_attack_spell(40,"disipar",({"/std/spells/wizard/dispell_magic","cast_spell",0,0}));
    add_attack_spell(10,"reducir",({"/std/spells/wizard/reducir","cast_spell",0,0}));
    add_attack_spell(10,"relentizar",({"/std/spells/wizard/slow","cast_spell",0,0}));
    //  if (GRADO==5) add_attack_spell(20,"meteoros diminutos",({"/std/spells/wizard/minute_meteor","cast_spell",0,0}));
    //  if (GRADO==5) add_attack_spell(20,"pw stun",({"/std/spells/wizard/pw_stun","cast_spell",0,0}));
    ::init();
}

mixed attack_by(object att)
{
    object *malos=query_attacker_list();
    int NO_MAGO=(att->query_guild_name()!=TO->query_guild_name());
    int i;

    gente="";
    niveles=0;
    turnos++;

    if (att->query_property("flipped") && !att->query_property("disminuido")) REDUCIR(att->query_name(),TO,0);

    for (i=0;i<sizeof(malos);i++)
    {
	niveles+=malos[i]->query_level();
	gente+=malos[i]->query_name()+",";
    }

    if (NO_MAGO)
	for (i=0;i<sizeof(sombras);i++)
	    if (!sombras[i])
	    {
		tell_room(ETO,"Una pequenya aura se arremolina alrededor de "+query_cap_name()+".\n"
		  "Una puerta extradimensional se abre ante el y pronuncia unas palabras de poder.\n"
		  "Del portal aparece una especie de sombra que se desliza por el suelo.\n");
		sombras[i]=clone_object(NPCS+"sombra");
		sombras[i]->set_spell(TO);
		sombras[i]->move(ETO);
		break;
	    }
    if (!TO->query_mirror_spell() && NO_MAGO && !random(8)) ESPEJO(query_name(),TO,0);
    if (!TO->query_spirit_armour_spell() && NO_MAGO) AURA(query_name(),TO,0);
    if (!query_property("armour_on")) ARMOUR(query_name(),TO,0);
    if (!TO->query_mirror_spell() && random(2)) ESPEJO(query_name(),TO,0);
    return ::attack_by(att);
}

int adjust_hp(int i,object att)
{
    if (i>MHP) DESC(gente+","+att->query_name(),TO,0);
    return ::adjust_hp(i,att);
}
