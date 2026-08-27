// Traducido por Lummen 27-7-97

#include <spells.h>
#define TABLE "/table/stats_table"

mixed spells;
mixed minor_spheres; // Las escuelas se tratan como esferas
mixed major_spheres;
mixed neutral_spheres;
int salvation;

void create() 
{
  spells=([]);
  minor_spheres=({});
  neutral_spheres=({});
  major_spheres=({});
  salvation=0;
}
  
void spell_commands() 
{
  add_action("show_spells", "hechizos");
  add_action("show_spheres","esferas");
  add_action("show_schools","escuelas");
  add_action("cast", "cast");
  add_action("cast", "formular");
}

string help_spell(string str) 
{
  object guild=TO->query_guild_ob();
  string spell_dir;

  if (!guild)
	return "";
  spell_dir=guild->query_spell_directory();
  if (!mappingp(spells)) spells=([]);
  if (!m_sizeof(spells)) return ""; 
  if (!spells[str]) return "";

  return ((string)(spell_dir+spells[str][S_OBJECT])->help(str));
}
 
int show_spells(string str) 
{
  string *frog;

  if (!mappingp(spells)) spells=([]);
  if (!m_sizeof(spells))
  {
    write("Todavia no conoces ningun hechizo.\n");
    return 1;
  }

  frog = m_indices(spells);
  write("Los hechizos que conoces son:\n");
  printf("%#-*s\n",TO->query_cols(),implode(frog,"\n"));
  return 1;
}

// Will cast the spell after a round of casting time
int cast(string str) 
{
  int i;
  object guild=TO->query_guild_ob();
  object *equipo;
  string *s,s1,spell_dir=guild->query_spell_directory(),kk;

  if (TO->query_property("nocast"))
  {
    notify_fail("No puedes invocar el poder para realizar esto ahora.\n");
    return 0;
  }

  if (TO->query_property("stillcasting"))
  {
    notify_fail("No puedes formular otro hechizo hasta que transcurra algun tiempo.\n");
    return 0;
  }

  if (ENV(TO)->query_property("nocast"))
  {
    notify_fail("Los poderes misticos son demasido debiles aqui como para afectar a alguien.\n");
    return 0;
  }
 
  if (!str) 
  {
    notify_fail("Uso: formular <hechizo> [<objetivo>]\n");
    return 0;
  }

  if (TO->query_dead())
  {
    notify_fail("Los espiritus no pueden formular hechizos.\n");
    return 0;
  }

  if (!TO->query_guild_ob())
  {
    notify_fail("Formulando hechizos sin pertenecer a un gremio?\n");
    return 0;
  }
  else switch ((TO->query_guild_ob())->query_base())
  {
    case "mg_drow":
    case "mg_bueno":
    case "ladron":
      equipo=TO->query_worn_ob();
      for (i=0;i<sizeof(equipo);i++)
        if ( (equipo[i]->query_material()==2) &&
             (equipo[i]->query_armour_name()!="cota de malla elfica") &&
             (equipo[i]->query_armour_name()!="cota de malla drow") )
          switch (equipo[i]->query_armour_type())
          {
            case 1:     // Armaduras
            case 3:     // Yelmos
            case 8:     // Guanteletes
              notify_fail("No puedes formular hechizos mientras lleves "
                "puestos objetos metalicos.\n");
              return 0;
          }
  }

  s=explode(str," ");
  s1=s[0];
  i=1;
  while (!spells[s1] && i<sizeof(s)) s1 = implode(s[0..i++], " ");
  if (DEBUG(TO)) tell_object(TO,"\nStr: "+str+".\n");

  if (!spells[s1]) 
  {
    notify_fail("No conoces ningun hechizo llamado "+str+".\n");
    return 0;
  }
  
  kk=spell_dir+spells[s1][S_OBJECT];
  if (DEBUG(TO)) tell_object(TO,"El archivo es "+kk+".\n");
  
  return (int)call_other(kk,"cast_spell",implode(s[i..sizeof(s)]," "));
}

mixed query_spells()
{
  return spells;
}

int borra_spells()
{
  spells=({ });
  return 1;

}


int add_spell(string name, mixed ob) 
{
  int i;
  mapping tmp;

  if (pointerp(spells)) 
  {
    tmp=([]);
    for (i=0;i<sizeof(spells);i+=2) tmp[spells[i]]=spells[i+1];
    spells=tmp;
  }

  if (!mappingp(spells)) spells=([]);
  spells[name]=({ob});
  return 1;
}

int remove_spell(string name) 
{
  spells=m_delete(spells,name);
  return 1;
}

int reset_spellarray() 
{
  spells=([]);
  return 1;
}

int query_spell(string type) 
{
  if (!mappingp(spells)) return 0;
  return spells[type];
}

int remove_sphere(string);

int add_sphere(string name,string power)
{
  if (!pointerp(minor_spheres)) minor_spheres=({});
  if (!pointerp(major_spheres)) major_spheres=({});
  if (!pointerp(neutral_spheres)) neutral_spheres=({});
  remove_sphere(name);

  switch (power)
  {
    case "menor":
      minor_spheres+=({name});
      break ;
    case "neutral":
      neutral_spheres+=({name});
      break;
    case "mayor":
      major_spheres+=({name});
      break;
    default:
      neutral_spheres+=({name});
      break;
  }      
  
  return 1;
}

int add_spheres(mixed list)
{
  int i;

  if (!pointerp(minor_spheres)) minor_spheres=({});
  if (!pointerp(major_spheres)) major_spheres=({});
  if (!pointerp(neutral_spheres)) neutral_spheres=({});

  for (i=0;i<sizeof(list);i++)
    if (sizeof(list[i])<2) neutral_spheres+=({list[i]});
    else switch (list[i][1])
    {
      case "menor":
        minor_spheres+=({list[i][0]});
        break;
      case "mayor":
        major_spheres+=({list[i][0]});
        break;
      case "neutral":
        neutral_spheres+=({list[i][0]});
        break;
    }

  return 1;
}

int remove_sphere(string name)
{
  minor_spheres-=({name});
  major_spheres-=({name});
  neutral_spheres-=({name});
  return 1;
}

int reset_spheres()
{
  minor_spheres=({});
  major_spheres=({});
  neutral_spheres=({});
  return 1;
}

int query_max_spell_level(string esfera)
{
  return 9;
}

mixed query_spheres() 
{
  return minor_spheres+major_spheres+neutral_spheres+({});
} 

mixed query_minor_spheres()
{
  return minor_spheres+({});
}

mixed query_neutral_spheres()
{
  return neutral_spheres+({});
}

mixed query_major_spheres()
{
  return major_spheres+({});
}

mixed query_sphere(string name)
{
// esto es un peligro para los hechizos q lo usan ahora ya q aun no tan
// las esferas!
  if ( member_array(name, minor_spheres) != -1 ) return 1;
  if ( member_array(name, neutral_spheres) != -1 ) return 2;
  if ( member_array(name, major_spheres) != -1 ) return 3;
  return 0;
}

mixed query_minor_sphere(string name)
{
  if ( member_array(name, minor_spheres) != -1 ) return 1;
  return 0;
}

mixed query_neutral_sphere(string name)
{
  if ( member_array(name, neutral_spheres) != -1 ) return 1;
  return 0;
}

mixed query_major_sphere(string name)
{
  if ( member_array(name, major_spheres) != -1 ) return 1;
  return 0;
}

mixed query_sphere_level(string name)
{
  switch( query_sphere(name) )
  {
    case 1:
      return "menor";
    case 2:
      return "neutral";
    case 3:
      return "mayor";
    default:
      return 0;
  }
  return 0;
}

int show_spheres()
{
  int written=0, i;

 /* if ( (guild->query_spell_directory()!=CLERIC_ROOT) &&
       (guild->query_spell_directory()!=DRUID_ROOT) )
  {
    notify_fail("No usas esferas.\n");
    return 0;
  } */

  for (i=0;i<sizeof(minor_spheres);i++,written++)
       write(minor_spheres[i]+" (Menor)\n");
  for (i=0;i<sizeof(neutral_spheres);i++,written++)
        write(neutral_spheres[i]+" (Neutral)\n");
  for (i=0;i<sizeof(major_spheres);i++,written++)
      write(major_spheres[i]+" (Mayor)\n");

  if (!written)
  {
    notify_fail("No tienes esferas.\n");
    return 0;
  }
  return written;
}

int show_schools()
{
  int written=0,i;

/*  if ( (guild->query_spell_directory()!=MAGE_ROOT) &&
       (guild->query_spell_directory()!=BARD_ROOT) )
  {
    notify_fail("No usas escuelas.\n");
    return 0;
  }
*/
  for (i=0;i<sizeof(minor_spheres);i++,written++ ) write(minor_spheres[i]+" (Menor)\n");
  for (i=0;i<sizeof(neutral_spheres);i++,written++) write(neutral_spheres[i]+" (Neutral)\n");
  for (i=0;i<sizeof(major_spheres);i++,written++) write(major_spheres[i]+" (Mayor)\n");

  if (!written)
  {
    notify_fail("No perteneces a ninguna escuela.\n");
    return 0;
  }
  return written;
}

// ATENCION: PARA HACER DANYO, SE DAN VALORES POSITIVOS DE DAMAGE!
int spell_damage(int damage,string type,string sphere,int salvation,object caster)
{
  int i=random(600);

	//tell_object(TO, "Danyo: "+damage+"\n");

// bug fixed - Tyrael
  if (damage>0)
  {
    damage=damage*(100-TO->query_res(type))/100;
	//tell_object(TO, "Danyo tras res: "+damage+"\n");
    if (TO->spell_saving_throw(caster,sphere)) damage=damage*salvation/100;
	//tell_object(TO, "Danyo tras salv: "+damage+"\n");
  }
  if (caster)
  {
    if (i<caster->query_cha())  // Critico
    {
      switch (i)
      {
        case 0:
          damage*=2;
          caster->adjust_gp(2);
          break;
        default:
          damage*=1.5;
          caster->adjust_gp(1);
      }
    }
    else if (i>599-TO->query_cha()) // Pifia
    {
      switch (i)
      {
        case 599:
          damage=0;
          caster->adjust_gp(-2);
          break;
        default:
          damage/=2;
          caster->adjust_gp(-1);
      }
    }
  }
	//tell_object(TO, "Danyo tras crit. final: "+damage+"\n");

// El tercer parametro a 1 indica que es danyo de hechizo llamado
// desde aqui. Solo se tiene en cuenta para shadows como piel de piedra
// ya que el adjust_hp sencillamente no lo mira, esta ahi pero no lo usa.
  if(!caster)
     TO->adjust_hp(-damage,0,1);
  else
     TO->adjust_hp(-damage,caster,1);
  return damage;
}

int set_salvation(int i)
{
  salvation=i;
}

int query_salvation()
{
  return salvation;
}

int adjust_salvation(int i)
{
  salvation+=i;
}

// esto necesita una remodelaaaaciooooooooooooon ke pa ke!
int spell_saving_throw(object caster,string esfera)
{
  int base=1;           
  int tirada=random(200);
	int calc;

  if (tirada<=caster->query_cha()) return 0;
  if (tirada>=(199-TO->query_cha())) return 1;

  // asi no hay dios ke meta hechizos a alguien de lev 50!
  //if (TO->query_guild_ob()!="") base=random(4)+4;

  if (TO->query_guild_ob()!="") base=random(4)+1;

  base*=TO->QL;
  // tengo que mirar bien como rula lo del salvation...
  //base+=(TO->query_sphere(esfera)-caster->query_sphere(esfera))*10+salvation;
  // feo feo, hasta no tener hecho lo de esferas ahi keda xD
	if (TO->query_guild_name() == "mago de agband")
		calc = 3;
	else
		calc = 0;		
	if (caster->query_guild_name() == "mago de agband")
		calc -= 3;
	base+=calc*10+salvation;

  return tirada<=base;
}

int query_res(string tipo)
{
  int natural=MAX(MIN(TO->QOP(tipo),MAX_RES_NATURAL),MIN_RES_NATURAL);
  int spell=MAX(MIN(TO->QTP(tipo),MAX_RES_SPELL),MIN_RES_SPELL);
  int objeto=MAX(MIN(TO->QSP(tipo),MAX_RES_OBJETO),MIN_RES_OBJETO);

  return MAX(MIN(natural+spell+objeto,MAX_RES_TOTAL),MIN_RES_TOTAL);
}

int query_spell_skill()
{
  if (TO->query_guild_ob())
    switch (TO->query_guild_ob()->query_main_skill())
    {
      case "wis":
        return TO->query_wis();
    }
  return TO->query_int();
}

int query_spell_bonus()
{
  return TABLE->calc_spell_bonus(TO->query_spell_skill());
}

int query_magic_bonus()
{
  return TABLE->calc_magic_bonus(TO->query_spell_skill());
}
