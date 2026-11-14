#include "/gilden/druidenzirkel/druiden_extern.h"
#include <properties.h>
#include <new_skills.h>
#include <combat.h>
#include <moving.h>

#ifndef P_GUILD_SPELLRATE
#define P_GUILD_SPELLRATE "guild_spellrate"
#endif

#define EHANDS ([\
                 FEUER  : " mit flammenden Haenden",\
                 EIS    : " mit scharfen Eiskrallen",\
                 HUMUS  : " mit giftigen Dornenhaenden",\
                 WASSER : " mit gigantischen Wasserfaeusten",\
                 LUFT   : " mit der Kraft eines Wirbelsturms",\
                 ERZ    : " mit toetlichen Stahldornen",\
               ])

#define STRAHL ([\
                 FEUER  : "Feuerball",\
                 EIS    : "Froststrahl",\
                 HUMUS  : "Humusstrahl",\
                 WASSER : "Wasserstrahl",\
                 LUFT   : "Windstoss",\
                 ERZ    : "Erzstrahl",\
               ])

#define AREA ([\
               FEUER  : "ein Feuersturm rast auf Dich zu",\
               EIS    : "ein Hagelsturm prasselt hernieder",\
               WASSER : "eine Sturmflut braust auf Dich zu",\
               LUFT   : "eine Windhose entsteht",\
               ERZ    : "die Erde beginnt zu beben",\
               HUMUS  : "giftige Dornen spriessen aus dem Boden",\
             ])


string element;

mapping element_damage = ([FEUER  : DT_FIRE,
                           WASSER : DT_WATER,
                           HUMUS  : DT_POISON,
                           EIS    : DT_COLD,
                           LUFT   : DT_AIR,
                           ERZ    : DT_MAGIC,
                          ]); 

varargs void create_default_druid(string _element, int level, int glevel, int maxhp)
{

  if(!stringp(_element) || !member(EHANDS, _element))
    element = FEUER;
  else
    element = _element;

  if(intp(maxhp))
    create_default_npc(level, maxhp);
  else
    create_default_npc(level);

  SetProp(P_XP, QueryProp(P_XP) * 4 / 3);
  SetProp(P_HANDS, ({EHANDS[element], QueryProp(P_HANDS)[1], 
                     ({DT_BLUDGEON, element_damage[element]}) }) );

  if(glevel < 1) glevel = 1; 
  if(glevel > 16) glevel = 16; 
  SetProp(P_GUILD, "druidenzirkel");
  SetProp(P_GUILD_LEVEL, glevel);
  AddId( ({"\ndruidenzirkel_npc", "NOWIMPY", "NOCONTROL"}) );
  SetProp(P_RESISTANCE_STRENGTHS, 
      ([DT_FIRE:     -0.3, DT_COLD:     -0.3, DT_WATER: -0.3, DT_AIR:   -0.3, 
        DT_LIGHTNING:-0.1, DT_EXPLOSION: 0.3, DT_SOUND:  0.0, DT_LIGHT:  0.0,
        DT_MAGIC:    -0.3, DT_ACID:      0.0, DT_POISON:-0.3, DT_TERROR: 0.1])+
      ([element_damage[element]: -1]) );

  seteuid(geteuid(this_object()));
  clone_object("/gilden/druidenzirkel/armour/d_amulett")->move(this_object());
  clone_object("/gilden/druidenzirkel/armour/e_panzer")->move(this_object());
  command("trage alles");
}

int psi(float x) 
{ 
  float ret;

  if(x > 0.0)
    ret = 200.0 + 100 * x * exp(1 + x);
  else if(x < 0.0)
    ret = 1.0 + 50 * (1 + x) ;
  else
    ret = 100.0;
  
  return to_int(ret);
}

string select_element(object enemy)
{
  mapping res;
  mapping p;
  int i;

  p = ([FEUER:1, WASSER:1, EIS:1, HUMUS:1, LUFT:1, ERZ:1]);
  if(mappingp(res = enemy->QueryProp(P_RESISTANCE_STRENGTHS)))
  {
    p[FEUER] = psi(to_float(res[DT_FIRE]));
    p[WASSER] = psi(to_float(res[DT_WATER]));
    p[EIS] = psi(to_float(res[DT_COLD]));
    p[ERZ] = psi(to_float(res[DT_MAGIC]));
    p[LUFT] = psi(to_float(res[DT_AIR]));
    p[HUMUS] = psi(to_float(res[DT_POISON]));
  } 
  p[element] *= 3;
  i = random(p[FEUER] + p[WASSER] + p[LUFT] + p[ERZ] + p[EIS] + p[HUMUS]);
  if(i < p[FEUER]) return FEUER;
  if(i < p[FEUER] + p[WASSER]) return WASSER;
  if(i < p[FEUER] + p[WASSER] + p[LUFT]) return LUFT;
  if(i < p[FEUER] + p[WASSER] + p[LUFT]+ p[ERZ]) return ERZ;
  if(i < p[FEUER] + p[WASSER] + p[LUFT]+ p[ERZ] + p[EIS]) return EIS;
  return HUMUS;
}

void laehmen(object enemy)
{
  tell_object(enemy, break_string(Name(WER,1) + " laehmt Dich durch magische "
        "Ranken, die aus dem Boden wachsen!\n", 78));
  say(break_string(Name(WER,1) + " beschwoert magische Ranken aus dem Boden, "
        "die " + enemy->name(WEN,1) + " behindern.", 78), ({enemy}));
  enemy->ModifySkillAttribute(this_object(), SA_SPEED, 
      100 - QueryProp(P_GUILD_LEVEL) * 4, QueryProp(P_GUILD_LEVEL) * 3);
  enemy->SetProp("laehmen_time", time() + 30); 
}

void create_elemental()
{
  object l;

  say(Name(WER,1) + " beschwoert ein " + capitalize(element) + 
      "elementar zur Hilfe!\n");
  l = clone_object("/gilden/druidenzirkel/npc/elementar");
  l->Customize(element, this_object(), 20000);
l->SetProp(ELEMENTAL_CASTER, 0);
  l->z_kaempfen(this_object(), ({}));
  l->SetProp(ELEMENTAL_OWNER, this_object());
  l->move(environment(this_object()), M_GO);
  SetProp(ELEMENTAL_CASTER, l);
}

void area_spell()
{
  object *enemies;
  int i;
  int dam;

  say(Name(WER,1) + " konzentriert sich und "+
      AREA[element] + "!\n");
  enemies = PresentEnemies();
  dam = 150 + QueryProp(P_LEVEL) * (QueryProp(P_GUILD_LEVEL) + random(6)) / 2;
  for(i = sizeof(enemies) - 1; i >= 0; i--)
  {
    enemies[i]->Defend(dam / 2 + random(dam / 2), element_damage[element], 
      ([SP_SHOW_DAMAGE:1, SP_NAME:"Raumspell", 
        SP_REDUCE_ARMOUR: ([P_BODY: 1])]), this_object());
  }
}

void ball_spell(object enemy, string ele)
{
  string strahl;
  int dam;

  strahl = STRAHL[ele];
  tell_object(enemy, Name(WER,1) + " wirft einen elementaren " + strahl +
      " nach Dir.\n");
  say(Name(WER,1) + " wirft einen elementaren " + strahl + " nach " +
      enemy->name(WEM,1) + ".\n", ({enemy}));
  dam = 100 + QueryProp(P_LEVEL) * (QueryProp(P_GUILD_LEVEL) + random(6));
  if(ele == element)
    dam = 3 * dam / 2;
  enemy->Defend(dam / 3 + random(2 * dam / 3), element_damage[ele], 
      ([SP_SHOW_DAMAGE:1, SP_NAME:strahl, 
        SP_REDUCE_ARMOUR: ([P_BODY: 1])]), this_object());
}

void arrow_spell(object enemy, string ele)
{
  int dam;

  tell_object(enemy, Name(WER,1) + " feuert einen elementaren " +
      capitalize(ele) + "pfeil auf Dich ab.\n");
  say(Name(WER,1) + " feuert einen elementaren " + capitalize(ele) +
      "pfeil auf " + enemy->name(WEN,1) + " ab.\n", ({enemy}));
  dam = 50 + QueryProp(P_LEVEL) * (QueryProp(P_GUILD_LEVEL) + random(6)) / 2;
  if(ele == element)
    dam = 3 * dam / 2;
  enemy->Defend(dam / 4 + random(3 * dam / 4), element_damage[ele], 
      ([SP_SHOW_DAMAGE:1, SP_NAME:capitalize(ele) + "pfeil", 
        SP_REDUCE_ARMOUR: ([P_BODY: 1])]), this_object());
}

void Attack(object enemy)
{ 
  if(!QueryProp(P_DISABLE_SPELLS) && (!QueryProp(P_GUILD_SPELLRATE) || 
        random(100) < QueryProp(P_GUILD_SPELLRATE)) )
  {
    if(QueryProp(P_GUILD_LEVEL) > 10)
    {
      if(enemy->QuerySkillAttribute(SA_SPEED) >= 100 && !random(3) &&
          enemy->QueryProp("laehmen_time") - time() < 0)
        laehmen(enemy);
      else if(!QueryProp(ELEMENTAL_CASTER) && !random(5))
        create_elemental();
      else if(sizeof(PresentEnemies()) > 1 + random(3))
        area_spell();
      else if(random(3))
        ball_spell(enemy, select_element(enemy));
      else
        arrow_spell(enemy, select_element(enemy));
    }
    else if(QueryProp(P_GUILD_LEVEL) > 5 && random(2))
      ball_spell(enemy, select_element(enemy));
    else
      arrow_spell(enemy, select_element(enemy));
  }
  if( objectp(enemy) ) 
    ::Attack(enemy);
}
 
