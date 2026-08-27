//Codazo. Kilidor Dic'01
inherit "/std/commands/base_command";
#include <comandos.h>
#define COSTE         5
#define PROP_NAME     "FIGHTER_COMMAND"
#define PROP_TIME     5
#define DANYO_CODAZO  LVL-random(15)+(caster->query_str()/10)
#define LOG_FILE     "codazo"
 
void setup()
{
  set_command_name("codazo");
  target_type = "one";
  lockout = 0;
  only_combat();
  set_help_string(
    "\n\n"
    "Nombre del Comando:  Codazo\n"
    "Coste de GP:         5\n"
    "Sintaxis:            codazo <objetivo>\n"
    "Descripcion: \n"
    "Tan importante como el manejo de las armas es la tecnica de "
    "lucha cuerpo a cuerpo de un guerrero. Asi, a parte de sus manos, "
    "pueden utilizar sus codos para producir mas danyo si no posee armas. "
    "Pero esta habilidad no exime de llevar armas asi que puede ser una "
    "habilidad muy poderosa si se ejecuta en el momento preciso.\n" 
    "Por supuesto, en la cantidad de danyo a inflinjir, influye la fuerza "
    "con la que se ejecuta el golpe y el nivel.\n");
}
 
int codazo(string str, object ob)
{
   return ::exec_command(str,ob);
}
 
int do_command(object target, object caster)
{
  int danyo = DANYO_CODAZO;
  int tmproll, result, achit, defenderac, THAC0;
  THAC0=(int)caster->query_thac0();
  tmproll=roll(1,200);
  achit = ((THAC0 - (int)caster->query_tohit_bonus()) - tmproll);
  defenderac = (int)target->query_total_ac();
  result = (achit - defenderac);

 if(caster->query_property("flipped")>1 && caster->query_level()<21)
  FALLO("No puedes aplicar esta habilidad con tal estado de descontrol.\n")
   if(caster->QP("flipped") > 2)
    FALLO("No puedes aplicar esta habilidad con tal estado de descontrol.\n")
  if(caster->QP("Cargando") || caster->QP("Carga"))
    FALLO("No puedes aplicar esta habilidad en este momento.\n")
  if(caster->QTP(PROP_NAME) && !DEBUG(caster))
    FALLO("No estas preparado todavia para poder llevar a cabo otra accion de esta magnitud.\n")
  if(!command_cost(COSTE,caster,0))
    FALLO("Estas demasiado cansado como para poder golpear con el codo.\n");
  if (member_array(target,caster->query_attacker_list())>-1)
  {
   if (result < 1)
    {
     tell_object(caster,"Con suma rapidez mueves tu brazo "
                     "y golpeas a "+target->QCN+" en su cara con tu codo.\n");
     tell_room(ENV(caster),caster->QCN+" se mueve con suma rapidez "
                      "mueve su brazo y golpea a "+target->QCN+" duramente "
                      "en la cara con su codo.\n",({caster,target}));
     tell_object(target,"\n"+caster->QCN+" te golpea duramente en la cara con su codo.\n");
     caster->ATP(PROP_NAME,1,PROP_TIME);
     command_damage(-danyo, caster, target);
     write_file(LOG_FILE,"Target: "+target->query_level()+" Caster: "+caster->query_level()+" Damage: "+danyo+".\n");
    return 1;
    }
   else
    {
     tell_object(caster,"Con suma rapidez mueves tu brazo "
                     "y no consigues golpear a "+target->QCN+" con tu golpe.\n");
     tell_room(ENV(caster),caster->QCN+" se mueve con suma rapidez "
                      "mueve su brazo hacia "+target->QCN+" fallando.\n",({caster,target}));
     tell_object(target,"\n"+caster->QCN+" no consigue golpearte con su codo.\n");
     caster->ATP(PROP_NAME,1,PROP_TIME);
     return 1;
    }
  }
  else 
  {
  notify_fail("No estas con lucha con "+target->QCN+".\n");
  return 0;
  }
}
