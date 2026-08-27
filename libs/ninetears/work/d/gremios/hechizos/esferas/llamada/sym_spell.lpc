// Soporte pa los clerigos de gestur por idem.

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Transformacion de Simbolo"
#define	NIVEL	7
#define	ESCUELA	({""})
#define	ESFERA	({"llamada"})
#define	CANCION	""
object sym,simbolo;
string faith;

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("none");
  set_range(0);
  set_help_desc("Este hechizo tan solo es concedido por los dioses a "
                "a aquellos que demuestran mayor devocion. Los efectos y "
                "costes del hechizo varian segun la deidad del clerigo. Un simbolo "
                "sagrado se requiere para poder llevar a cabo la consumacion "
                "del hechizo.\n");
  set_gp_cost(NIVEL);
  set_casting_time(3);
  set_rounds(({ "round1","round2","round3"}));
}

string help() 
{
  switch (TP->query_guild_name())
  {
    case "Cleriga de Lloth":
      return ::help()+
        "    Para las adoradoras de Lloth, su simbolo sagrado "
        "invoca y anima un familiar aranya. La aranya puede seguirte y "
        "proteger, durante almenos 1 turno por nivel. Al mismo tiempo "
        "podra volver al simbolo, para invocarla en otra ocasion. "
        "Si la aranya muere el simbolo no podra ser recuperado. Adicio"
        "nalmente tienes el comando 'despedir aranya' con el cual "
        "la aranya podra volver al simbolo sagrado.\n";
    case "Clerigo de Lummen":
      return ::help()+
        "    Para los seguidores de Lummen, su simbolo sagrado puede "
        "fracturar en varios trozos tu simbolofour leaves, con el "
        "proposito de protegerte del danyo de los ataques. "
        "Este hechizo durara 1 turno / nivel, y bloqueara 4*nivel Pv producidos "
        "por un ataque. Despues de que todas estas condiciones se produzcan, "
        "el simbolo sagrado volvera a reconstruirse. \n"
        "NOTA: Si no tienes carga disponible, o se produce el hechizo cuando "
        "estas intentando cargar algo, posiblemente no reciviras el simbolo "
        "hasta momentos despues.";
    case "Clerigo de Gestur":
      return ::help()+
        "    Para los seguidores de Gestur, tu simbolo sagrado "
        "crecera y se convertira en un gran martillo encantado. El poder del "
        "encantamiento sera de +1 por cada 6 niveles del hechicero, con un "
        "maximo de +5.  The martillo solo sera efectivo en las manos del "
        "seguidor de Gestur, y no se grabara. El simbolo sagrado es destruido "
        "durante el hechizo. El danyo siempre se incrementa con el nivel del "
        "hechicero.\n";
  case "antipaladin":
      return ::help()+
        "    For Dark Lords the Holy Symbol will grow into "
        "a mystical sword with unspeakable powers.  Though the "
        "Evil Knight is Lawful the sword knows no bounds "
        "so beware.  The sword will not save and the symbol "
        "will be destroyed in the casting.\n";
  case "paladin":
      return ::help()+
        "    Para Los Grandes Caballeros Del Bien, La Transformacion "
        "De La Cruz De Plata Supone Conseguir Una Poderosa Espada "
        "Que Es Capaz De Repeler A Cualquier Enemigo Gracias Al Poder "
        "Magico Que Contiene En Su Seno.\n"
        "    Tan Solo Los Paladines Mas Justos Y Devotos Seran Capaces "
        "De Utilizar La Maxima Fuerza Escondida.\n";
  }
  return ::help();
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{

  tell_object(caster,"Haces unos gestos extranyos mientras formulas unas calmadas palabras.\n");
  tell_room(ENV(caster),caster->QCN+" hace unos extranyos gestos mientras formula unas calmadas palabras.\n",caster);
  
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_room(ENV(caster),caster->QCN+" levanta su simbolo sagrado, pronunciando silabas de fe y devocion.\n",caster);
  tell_object(caster,"Levantas tu simbolo sagrado, pronunciando silabas de fe y devocion.\n");
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  
  int i,has_symbol;
  mixed symbol;

  // Gestur'98   Para que funcione el simbolo de gestur sin que se llame
  // sym_Clerigo de Gestur.c
  switch (faith=caster->query_guild_name())
  {
    case "Clerigo de Gestur":
      faith="gestur";
      break;
    case "Clerigo de Lummen":
      faith="lummen";
      break;
    case "Cleriga de Lloth":
      faith="lloth";
      break;
  }

  symbol=find_match("simbolos sagrados",caster);
  
  has_symbol=0;
  for (i=0;i<sizeof(symbol);i++)
    if (symbol[i]->QP("faith")==faith)
    {
      simbolo=symbol[i];
      has_symbol=1;
      break;
    }

  if (!has_symbol)
  {
    tell_object(caster,"Necesitas un simbolo sagrado para este hechizo.\n");
    return 1;
  }
  if (caster->query_skin_spell())
  {
    tell_object(caster,"No puedes completar este hechizo por el momento.\n");
    tell_room(ENV(caster),caster->QCN+" deja de formular.\n",caster);
    return 0;
  }

  sym=clone_object(OBJETOS+"sym_"+lower_case(faith));
  sym->setup_spell(caster);
  simbolo->dest_me();
  return 0;
}
