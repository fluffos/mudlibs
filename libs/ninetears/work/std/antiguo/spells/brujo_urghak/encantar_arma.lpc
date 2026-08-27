//Paris. Junio '98

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Encantar arma"
#define	NIVEL	5
#define	ESCUELA	({"wizwar"})
#define	ESFERA	({""})
#define	CANCION	""
#define	GP_COSTE	150
#define	MIN_LEVEL	30

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_spell_level(NIVEL);
  set_target_type("item");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este hechizo encanta un arma con una poderosa aura magica "
    "que la hace que esta se torne en un arma temible pudiendo "
    "atravesar armaduras cual cuchillo caliente parte los bloques "
    "de mantequilla. El encantamiento requiere un componente "
    "base: El Cuerno de Unicornio. Ademas se puede incrementar "
    "la potencia del hechizo si el Mago tiene en su poder las "
    "Runas de Encantamiento, las cuales se encuentran dispersas "
    "por los Reinos en manos de temibles enemigos.\n");               
  set_gp_cost(NIVEL);
  set_casting_time(4);
  set_rounds(({"round1","round2","round3","round4"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"Levantas tus brazos al aire para permitir que la energia entre en tu cuerpo.\n");
  tell_room(ENV(caster),caster->QCN+" levanta sus brazos al aire al tiempo que empieza a cantar haciendole "
    "estremecer de placer al recorrer la energia su cuerpo.\n",caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"La energia acumulada en tu cuerpo es canalizada hacia tus manos que adquieren un brillo rojizo.\n");
  tell_room(ENV(caster),"La energia acumulada por "+caster->QCN+" es redireccionada a sus manos que adquieren un brillo rojizo.\n",caster);
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"Estas en el punto alguido del hechizo, tu cantico se torna grave y te contoneas al son de la musica que tu mismo pronuncias.\n");
  tell_room(ENV(caster),caster->QCN+" cambia el tono de su cante a otro mas grave y empieza a irradiar calor debido a la energia que atesora.\n",caster);
  return 0;
}

int round4(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int i,tiradas,dados=1;
  object basico=present("cuerno de unicornio",caster),
         objeto1= present("runa de dragon",caster),
         objeto2= present("runa de basilisco",caster),
         objeto3= present("runa de leon",caster),
         objeto4= present("runa de ucorno",caster);
             
  if (!basico)
  {
    tell_object(caster,"Despues de tanto trabajo y no tienes el componente "
      "esencial para el hechizo? Todo tu trabajo se va al garete por esta "
      "falta de conocimiento.\n");
    tell_room(ENV(caster),caster->QCN+" sufre una desconcentracion de ultima "
      "hora cuando se da cuanta que le falta el componente esencial para este "
      "hechizo y pierde el hechizo.\n",caster);
    return -1;
  }

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (!target->query_weapon())
  {
    tell_object(caster, "Te das cuenta que estas intentando hechar sobre un objeto que no es un arma tu hechizo de encantar arma, por lo que el hechizo te falla.\n");
    tell_room(ENV(caster),caster->QCN+" se da cuenta que intentaba hechar el hechizo sobre un objeto que no era un arma, por lo que pierde toda la energia acumulada hasta ahora.\n");
    basico->dest_me();
    return -1;
  }

  if (target->query_enchant()>0)
  {
    tell_object(caster,"Al finalizar su hechizo el arma se rebela y se niega a que le introduzcas un nuevo encantamiento.\n");
    tell_room(ENV(caster),"Al recibir el hechizo de "+caster->QCN+" sobre ella, el arma se rebela, ya que ya estaba encantada.\n",caster);
    basico->dest_me();
    return -1;
  }
  if(sizeof(target->query_ataques())>2)
  {
     tell_object(caster,"El Arma no puede absorver la magia que le transmites "
                        "debido a sus propiedades intrinsecas.\n");
     basico->dest_me();
     tell_room(ENV(caster),"Al finalizar el hechizo, "+caster->QCN+", ve como "
                        "todo su trabajo se desperdicia debido a un imprevisto.\n ",
                        ({ caster }));
     return -1;
  }
     
     

  tell_object(caster,"Finalizas tu hechizo en un estallido multicolor en el cual la energia hasta ahora acumulada en ti pasa rapidamente de ti al arma a encantar.\n");
  tell_room(ENV(caster),"El hechizo de "+caster->QCN+" finaliza en una explosion multicolor en la que la energia acumulada en su cuerpo pasa al arma a ser encantada.\n",caster);

  if(objeto1){ objeto1->dest_me(); dados ++; }
  if(objeto2){ objeto2->dest_me(); dados ++; }
  if(objeto3){ objeto3->dest_me(); dados ++; }
  if(objeto4){ objeto4->dest_me(); dados ++; }
  
  tiradas=caster->QL/10;
  target->add_attack("encantada","burn",dados,tiradas,0);
  target->reset_drop();
  if (basico) basico->dest_me();

  return 1;
}
