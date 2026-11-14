#include "/gilden/paladine/paladin_extern.h"
#include <properties.h>
#include <combat.h>
#include <new_skills.h>
#include <class.h>

varargs void create_default_paladin(int level, int glevel, int maxhp)
{
  if(intp(maxhp))
    create_default_npc(level, maxhp);
  else
    create_default_npc(level);
  SetProp(P_XP, QueryProp(P_XP) * 4 / 3);

  if (glevel < 1) glevel = 1; 
  if (glevel > 15) glevel = 15; 
  SetProp(P_GUILD, "paladine");
  SetProp(P_GUILD_LEVEL, glevel);
  AddId( ({"\npaladin_npc", "NOWIMPY", "NOCONTROL"}) );
  call_other("/gilden/paladine", "learn_paladin_skills",
      1000 + 600 * glevel);

  seteuid(geteuid(this_object()));
  clone_object("/gilden/paladine/armour/wappenrock")->move(this_object());
  command("trage alles");
}

void Attack(object enemy)
{ 
  int g;

  if (!QueryProp(P_DISABLE_SPELLS))
  {
    g = QueryProp(P_GUILD_LEVEL);
    if (!QueryProp(P_TMP_DEFEND_HOOK) && random(2))
    {
      if (random(2) || g < 9 && 
          sizeof(QueryArmours(AT_SHIELD)))
        command("schildparade");
      else
        command("goetterschutz");
    }
    else if (g == 15 && !random(10) && !present("\namaryllion"))
    {
      if (objectp(QueryProp(P_WEAPON)))
        QueryProp(P_WEAPON)->DoUnwield();
      command("talisman");
    }
    else if (random(2) && (enemy->is_class_member(CL_DEMON) || 
          enemy->is_class_member(CL_UNDEAD)))
    {
      command("verbannung");
    }
    else if (QueryProp(P_HP) < QueryProp(P_MAX_HP) / 5 && !random(3))
    {
//      command("behandle mich");  // funktioniert irgendwie nicht....
      environment()->Message(sprintf("%s heilt sich.\n", Name(WER,1)));
      AddHp(QueryProp(P_LEVEL) + random(QueryAttribute(A_INT)));
    }
    else if (g >= 10 && random(2))
    {
      command("zielattacke");
    }
    else if (g >= 5 && random(2))
    {
      command("heiligengebet");
    }
  }
  if( objectp(enemy) ) 
    ::Attack(enemy);
}
 
