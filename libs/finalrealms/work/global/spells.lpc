#include "spells.h"

mixed spells;
mixed minor_spheres; // Also used by schools.
mixed major_spheres;
mixed neutral_spheres;

//object guild;
//string spell_dir;

/* here is the start on the new spells.c i will try to make
 *   Baldrick, started july '93
 * Added Major/Minor/Neutral spheres.  This won't be used til
 * FR-III, probably, but I want it there for FR-2.5.  For now
 * it'll work exactly the same; but since the spheres are saved
 * on the player, I want the data to be there so we can easily
 * change the functions later.  --Wonderflug, august '95.
 */

void create() 
{
  spells = ([ ]);
  minor_spheres = ({ });
  neutral_spheres = ({ });
  major_spheres = ({ });
  //guild = this_player()->query_guild_ob();
}
  
/*
void init_spells()
{
  spell_dir = guild->query_spell_directory();
}
*/

void spell_commands() 
{
  add_action("show_spells", "spells");
  add_action("show_spheres", "spheres");
  add_action("show_schools", "schools");
  add_action("cast", "cast");
  /* this is a reset of the spellarray,the players will have to
   * learn again..
   * Baldrick. sept '93 */
  //add_action("reset_spellarray", "reset_spells");
}

/*  If you have a function help() in the spell itself.  It will print the
 *  string you return there. 
 */
string help_spell(string str) 
{
  object guild;
  string spell_dir;

  if (!mappingp(spells))
    spells = ([ ]);
  if(!m_sizeof(spells))
    return 0;
  if (!spells[str])
    return 0;
  guild = this_player()->query_guild_ob();
  spell_dir = guild->query_spell_directory();

  /* Since I have removed the /std/spells from the spellaray
  * do I have to put it here..Baldrick sept '93 */
  return ((string)(spell_dir+spells[str][S_OBJECT])->help(str));
}
 
/*
 * Lists spells you know
 */
int show_spells(string str) 
  {
  string *frog;

  if (!mappingp(spells))
   spells = ([ ]);
  if (!m_sizeof(spells)) {
    write("You don't know any spells yet.\n");
    return 1;
  }

  frog = m_indices(spells);
  write("You know the following spells:\n");
  printf("%#-*s\n", this_player()->query_cols(), implode(frog, "\n"));
  return 1;
}

/* Will cast the spell after a round of casting time */
int cast(string str) 
{
  int j;
  string *s,s1;
  object guild;
  string spell_dir;

  if( this_player()->query_property("nocast") )
  {
    tell_object(this_player(), "You cannot seem to summon the power "+
      "within you right now.\n");
    return 1;
  }

  if ( this_player()->query_property("stillcasting") )
  {
    tell_object(this_player(), "You cannot cast another spell again so soon "
      "after your last one.\n");
    return 1;
  }

  if (environment(this_player())->query_property("nocast"))
  {
    tell_object(this_player(),"The mystical powers seem to be too "+
      "weak here to affect anything.\n");
    return 1;
  }
 
  if (!str) 
  {
    notify_fail("Usage: cast <spell> [<target>]\n");
    return 0;
  }
  /* Dead players should not cast spells!
   * Baldrick.
   */
//if(this_player()->query_property("dead"))
//Radix was here, doubtful this was necessary
// Dec 14, 1995
  if(this_player()->query_dead())
  {
    notify_fail("Ghosts cannot cast spells.\n");
    return 0;
  }

  guild=(object)this_player()->query_guild_ob();

  /* The spellcasters shall not be able to cast spells when in full armour. 
   * Modify by Baldrick. oct '94.
   * Changed a bit, now it tests on the legality of the armour.
   */
// Taniwha 28/09/95, we now have armour restrictions in globally, not needed, also not 100% consistant with other code
/*
  if (armours = this_player()->query_worn_ob())
  {
    for (i=0;i<sizeof(armours);i++)
    {
      if (!guild->query_legal_armour((string)armours[i]->
                                   query_armour_type_name()))
      {
        notify_fail("You can not cast spells while wearing this armour.\n");
        return 0;
      }
      }
   }
*/
  s = explode(str, " ");
  s1 = s[0];
  j = 1;
  while (!spells[s1] && j < sizeof(s))
    s1 = implode(s[0..j++], " ");
  if (!spells[s1]) 
  {
    notify_fail("You don't know any "+str+" spell.\n");
    return 0;
  }
  /* ok we found our spell...
   * cast it...
   * Or, at least try to ;)
   */
  /* the Spell_dir is used to reduce space in the spellarray */
  spell_dir = guild->query_spell_directory();
  return (int)call_other(spell_dir + spells[s1][S_OBJECT], "cast_spell",
                           implode(s[j..sizeof(s)], " "));
} /* Cast */

mixed query_spells() { return spells; }

int add_spell(string name, mixed ob) 
{
  int i;
  mapping tmp;

  if (pointerp(spells)) 
  {
    tmp = ([ ]);
    for (i=0;i<sizeof(spells);i+=2)
      tmp[spells[i]] = spells[i+1];
    spells = tmp;
  }
  if (!mappingp(spells))
    spells = ([ ]);
  spells[name] = ({ ob });
  return 1;
}

int remove_spell(string name) 
{
  spells = m_delete(spells, name);
  return 1;
}

int reset_spellarray() 
{
  spells = ([ ]);
  // write ("Bing.\n");
  return 1;
}

int query_spell(string type) 
{
  if (!mappingp(spells)) return 0;
  return spells[type];
}

/* the sphere code.. added by Baldrick october '93 to use by 
 * add_spell code in the guilds..*
 * Fubaring by Wonderflug, August 95.
 */

int add_sphere(string name, string power)
{
  if (!pointerp(minor_spheres))
    minor_spheres = ({ });
  if (!pointerp(major_spheres))
    major_spheres = ({ });
  if (!pointerp(neutral_spheres))
    neutral_spheres = ({ });

  switch( power )
  {
    case "minor":
      minor_spheres += ({ name, });
      break ;
    case "neutral":
      neutral_spheres += ({ name, });
      break;
    case "major":
      major_spheres += ({ name, });
      break;
    default:
      /* For backward compatibility. */
      neutral_spheres += ({ name, });
      break;
  }      
  
  return 1;
}

int add_spheres(mixed list)
{
  int i;

  if (!pointerp(minor_spheres))
    minor_spheres = ({ });
  if (!pointerp(major_spheres))
    major_spheres = ({ });
  if (!pointerp(neutral_spheres))
    neutral_spheres = ({ });

  for ( i=0; i<sizeof(list); i++ )
  {
    if ( sizeof(list[i]) < 2 )
    {
      /* Again, for backward compatibility. */
      neutral_spheres += ({ list[i] });
      continue;
    }
    switch( list[i][1] )
    {
      case "minor":
        minor_spheres += ({ list[i][0] });
        break;
      case "major":
        major_spheres += ({ list[i][0] });
        break;
      case "neutral":
        neutral_spheres += ({ list[i][0] });
        break;
      default:
        break;
    } /* switch */
  } /* for */

  return 1;
}

/*
int remove_sphere(string name)
  {
  spheres = m_delete(spheres, name);
  return 1;
  }
*/

int reset_spheres()
{
  minor_spheres = ({ });
  major_spheres = ({ });
  neutral_spheres = ({ });
  return 1;
}

/* This we keep completely backward compatible.  Just return
 * the sum of all 3.
 */
mixed query_spheres() 
{
  return minor_spheres + major_spheres + neutral_spheres + ({ });
} 

/* Extensions */
mixed query_minor_spheres() { return minor_spheres + ({ }); }
mixed query_neutral_spheres() { return neutral_spheres + ({ }); }
mixed query_major_spheres() { return major_spheres + ({ }); }

/* Slight change, to reflect the power of the sphere for the player */
mixed query_sphere(string name)
{
  if ( member_array(name, minor_spheres) != -1 )
    return 1;
  if ( member_array(name, neutral_spheres) != -1 )
    return 2;
  if ( member_array(name, major_spheres) != -1 )
    return 3;

  return 0;
}

mixed query_minor_sphere(string name)
{
  if ( member_array(name, minor_spheres) != -1 )
    return 1;
  return 0;
}

mixed query_neutral_sphere(string name)
{
  if ( member_array(name, neutral_spheres) != -1 )
    return 1;
  return 0;
}

mixed query_major_sphere(string name)
{
  if ( member_array(name, major_spheres) != -1 )
    return 1;
  return 0;
}

/* Another extension. Just returns the string instead of a number. */
mixed query_sphere_level(string name)
{
  switch( query_sphere(name) )
  {
    case 1:
      return "minor";
    case 2:
      return "neutral";
    case 3:
      return "major";
    default:
      return 0;
  }
  return 0;
}


int show_spheres()
{
  object guild;
  int written, i;

  guild = this_player()->query_guild_ob();

  written = 0;

  if ((!guild) || ((string)guild->query_spell_directory()!=CLERIC_ROOT))
  {
    notify_fail("You don't need spheres.\n");
    return 0;
  }

  /* Could format it better, but I don't care. */
  for ( i=0; i<sizeof(minor_spheres); i++, written++ )
    write(minor_spheres[i]+" (Minor)\n");
  for ( i=0; i<sizeof(neutral_spheres); i++, written++ )
    write(neutral_spheres[i]+" (Neutral)\n");
  for ( i=0; i<sizeof(major_spheres); i++, written++ )
    write(major_spheres[i]+" (Major)\n");
 
  if (!written)
  {
    notify_fail("You are sphereless.\n");
    return 0;
  }
  return written;
} /* int show spheres..*/
 
int show_schools()
{ 
  object guild;
  int written, i;

  guild = this_player()->query_guild_ob();

  if ((string)guild->query_spell_directory()!=MAGE_ROOT)
  {
    notify_fail("You dont need schools.\n");
    return 0;
  }

  written = 0;
  for ( i=0; i<sizeof(minor_spheres); i++, written++ )
    write(minor_spheres[i]+" (Minor)\n");
  for ( i=0; i<sizeof(neutral_spheres); i++, written++ )
    write(neutral_spheres[i]+" (Neutral)\n");
  for ( i=0; i<sizeof(major_spheres); i++, written++ )
    write(major_spheres[i]+" (Major)\n");

  if (!written)
  {
    notify_fail("You don't belong to any schools.\n");
    return 0;
  }
  return written;
} /* int show schools..*/

/*** damage and resistance routine for different damage types ***/
/*** added by Eerevann 2-11-94 ***/
/* resist calcs in /std/spells/patch.c */

int spell_damage(mixed target, int damage, string type,object caster)
{
    if(!caster) target->adjust_hp(-damage);
    else target->adjust_hp(-damage,caster);
  return 1;
}

/* hmm, could we put this one somewhere else ? save up some memory.
 * Baldrick, just peeping around.. */

int spell_saving_throw(mixed target, int damage, string save_type)
{

 /*** SAVING THROW ***/
 /*** make save if random(level+20) > 15 ***/

 if ( (random( (target->query_level() )+20)) > 15)
    damage = damage/2;  /*** save for half damage ***/
  
 return damage;

}
