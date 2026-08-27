// Traducido por Lummen 28-7-97
// Modificado por Guldan Jun'98

#include <spells.h>

#define	ABS(i) MAX(i,-i)
#define BASESTAT 15

#define CHARISMA_SAVE 12
// Variables Globales
mapping environment_mods;

// Prototipos
int	fix_damage(object,object,int);
int	wrong_alignment(object);
int	punish_align(object);
object	check_melee_protector(object,object);
void	set_environment_mods(mapping);
mapping	query_environment_mods();
int	implement_environment_mods(object,int);

// Implementacion

int bard_fix_damage(object caster,object victim,int damage,string type);

int wiz_fix_damage(object caster,object victim,int damage,string type)
{
   if(caster->query_guild_name() == "bard") return bard_fix_damage(caster,victim,damage,type);
   damage = (damage * (int)caster->query_int())/BASESTAT;
   damage = (damage * (100-(int)victim->query_property(type)))/100;
   // LUCK! Taniwha 1995
   if((damage < 0) && (random(victim->query_cha()) > CHARISMA_SAVE)) damage = damage / 2;
   return damage;
}
int bard_fix_damage(object caster,object victim,int damage,string type)
{
   damage = (damage * (int)caster->query_cha())/BASESTAT;
   damage = (damage * (100-(int)victim->query_property(type)))/100;
   // LUCK! Taniwha 1995
   if((damage < 0) && (random(victim->query_cha()) > CHARISMA_SAVE)) damage = damage / 2;
   return damage;
}
int cleric_fix_damage(object caster,object victim,int damage,string type)
{
   int align;
   if((string)caster->query_guild_name() == "paladin")
   {
       align = (int)victim->query_align();
       /* harm good */
       if((damage < 0) && (align < 0)) return 0;
       /* heal evil */
       if((damage > 0) && (align > 0)) return 0;
   }
   if((string)caster->query_guild_name() == "antipaladin")
   {
       align = (int)victim->query_align();
       /* harm evil */
       if((damage < 0) && (align > 0)) return 0;
       /* heal good */
       if((damage > 0) && (align < 0)) return 0;
   }
   damage = (damage * (int)caster->query_wis())/BASESTAT;
   damage = (damage * (100-(int)victim->query_property(type)))/100;
   // LUCK! Taniwha 1995
   if((damage < 0) && (random(victim->query_cha()) > CHARISMA_SAVE)) damage = damage / 2;
   return damage;
}
mixed find_unique_match(string find,mixed inx)
{
mixed *olist;
   int i,j;
   olist = find_match(find,inx);
   for(i = 0; i < sizeof(olist); i++)
   {
      for(j = sizeof(olist)-1; j > i; j--)
      {
         if(olist[j] == olist[i]) olist = delete(olist,j,1);
      }
   }
	// PARCHE ANTI HECHIZOS A ESPIRITUS
   if (!TO->query_allowed_on_ghosts()) {
		j = sizeof(olist)-1;
		while (j >= 0 && olist[j]->query_dead()) {
			//olist = delete(olist,j,1);
			olist -= ({ olist[j] });
			j--;
		}
   }
   return olist;
}
mixed find_one_match(string find,mixed inx)
{
mixed *olist;
   int i=0;
   int j;
   olist = find_match(find,inx);
   if ( (j=sizeof(olist)) < 1 )
      return 0;
   else { // PARCHE PARA EVITAR HECHIZOS A ESPIRITUS!!!
	if (!TO->query_allowed_on_ghosts()) {
		while (i < j && (olist[i]->query_dead() ||
			olist[i]->query_hidden()))
			i++;
		if (i == j)
			return 0;
	}
	// ke triste habria ke arreglar esto para q se vea mejol
	else {
		while (i < j && olist[i]->query_hidden())
			i++;
		if (i == j)
			return 0;
	}
        return olist[i];
   }
}

// NEW, Tyrael - Oct '01
// usado para poder usar "all" en hechizos a un solo objetivo
// de forma que se escoja uno de los presentes al azar
// salvo el tu_no, que suele ser el caster
// anyadido chekeo de property por si el caster lleva un bicho
// que le pertenece, "duenyo".
// cambiar, en lugar de QCN que apunte al objeto,
// para que los NPCs tb puedan llevar bichos y tal.
// mirar lo de salir dejando el bicho por ahi, o poder
// reclamarlo al entrar otra vez (poner otra prop "duenyo_name"
// o algo asi.
mixed find_one_random_match(string find,mixed inx, object tu_no)
{
mixed *olist;
mixed *mylist;
   int i=0,a=0;
   int j;
	mylist = ({ });
   olist = find_match(find,inx);
   if ( (j=sizeof(olist)) < 1 )
      return 0;
   else { // PARCHE PARA EVITAR HECHIZOS A ESPIRITUS!!!
	while (i < j) {
		if (!tu_no || (olist[i] != tu_no &&
		    olist[i]->query_property("duenyo") != tu_no->QCN)) {
			if (!olist[i]->query_hidden()
				&& (olist[i]->query_alive()
			   || TO->query_allowed_on_ghosts())) {
				mylist += ({olist[i]});
				a++;
			}
		}
		i++;
	}
  }
  if (!a)
	return 0;
  return mylist[random(a)];
}

void set_environment_mods(mapping m)
{
  environment_mods=copy(m);
}

mapping query_environment_mods()
{
  return environment_mods;
}

int implement_environment_mods(object caster,int damage)
{
  string location=ENV(caster)->QP("location");
  int adj;

  if (!location || !environment_mods || undefinedp(environment_mods[location])) return damage;
  adj=environment_mods[location];
  if (!adj) tell_object(caster,"Tu hechizo no tiene ningun efecto!\n");
  else if (adj<100) tell_object(caster,"Tu hechizo parece que no funciona tan bien como de costumbre.\n");
  else if (adj>100) tell_object(caster,"Tu hechizo parece funcionar mejor que de costumbre.\n");
  return damage*adj/100;
}  

int fix_damage(object caster,object target,int damage)
{
  int tmp=target->query_align()*damage;

  if ( (caster->QGN()=="paladin" && tmp>0) ||
       (caster->QGN()=="antipaladin" && tmp<0) ||
       wrong_alignment(caster) )
  {
    punish_align(caster);
    return 0;
  }

  //tmp=ABS(damage);
  tmp=damage;
  tmp+=tmp*caster->query_spell_bonus()/100+caster->query_magic_bonus();
  if (damage<0) tmp=-tmp;
  return implement_environment_mods(caster,tmp);
}

int wrong_alignment(object ob)
{
  switch (ob->QGN())
  {
    case "paladin":
      return (ob->query_align()>0);
    case "antipaladin":
      return (ob->query_align()<0);
  }
  return 0;
}

int punish_align(object ob)
{
  tell_object(ob,"Te sientes un ser desgraciadamente impuro, perdiendo "
      "toda la confianza que tenias en ti mismo.\n");
  ob->set_xp(0);
  return 1;
}

object check_melee_protector(object victim, object doer)
{
  int i;
  object *prots = victim->query_protector();
  object prot; 

  if(i=sizeof(prots))
  {
    prot = prots[random(i)];
    if (prot && (ENV(prot)==ENV(victim)) && (prot->query_protect_valid(doer,victim)))
    {
      tell_object(prot,"Proteges "+victim->QCN+" del ataque.\n");
      tell_object(victim,prot->QCN+" te protege valientemente.\n");
      tell_object(doer,prot->QCN+" se interpone en la linea de tu objetivo sufriendo tu ataque!\n");
      tell_room(ENV(victim),prot->QCN+" protege valientemente a "+victim->QCN+" del ataque de "+doer->QCN+".\n",({doer,victim,prot}));
      return prot;
    }
  }
  return victim;
}
