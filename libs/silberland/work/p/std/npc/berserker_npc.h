#include "/gilden/berserker/berserker_extern.h"
#include <properties.h>
#include <combat.h>
#include <new_skills.h>

varargs void create_default_berserker(int level, int glevel, int maxhp)
{
  if(intp(maxhp))
    create_default_npc(level, maxhp);
  else
    create_default_npc(level);
  SetProp(P_XP, QueryProp(P_XP) * 4 / 3);

  if( glevel < 1 ) glevel = 1; 
  if( glevel > 10 ) glevel = 10; 
  SetProp(P_GUILD, "berserker");
  SetProp(P_GUILD_LEVEL, glevel);
  AddId( ({"\nberserker_npc", "NOWIMPY", "NOCONTROL"}) );
  call_other("/gilden/berserker", "learn_berserker_skills",
      1000 * glevel, 1000 * glevel);

  seteuid(geteuid(this_object()));
  clone_object("/gilden/berserker/obj/stirnband")->move(this_object());
  command("trage alles");
}

void Attack(object enemy)
{ 
  if( !QueryProp(P_DISABLE_SPELLS) )
  {
    if( QueryProp(P_GUILD_LEVEL) >= 6 && !QueryProp(P_TMP_DEFEND_HOOK) && 
        random(2) )
    {
      command("eisenhaut");
    }
    else if(QueryProp(P_GUILD_LEVEL) >= 5 && 
        !present("\nberserker_willenskraft",this_object()) && random(2) )
    {
      command("willenskraft");
    }
    else if( QueryProp(P_GUILD_LEVEL) >= 3 && !QueryProp(P_PREFERED_ENEMY) && 
        !random(4) && sizeof(PresentEnemies()) > 1 && interactive(enemy) )
    {
      command("augeinauge " + getuid(enemy));
    }
    else if ( time() - enemy->QueryProp(P_LAST_RAMMEN_TIME) < 4 )
    {
      command("zertreten");
    }
    else if( QueryProp(P_GUILD_LEVEL) >= 8 && enemy->QueryProp(P_DEAF) && 
        enemy->QueryProp(P_BLIND) )
    {
      SetProp(P_LAST_WUETEN_TIME, time());
      command("rammen");
    }
    else if( QueryProp(P_GUILD_LEVEL) >= 10 && 
        QueryProp(P_HP) < QueryProp(P_MAX_HP) / 3 )
    {
      command("blutrausch");
    }
    else if( QueryProp(P_GUILD_LEVEL) >= 9 && sizeof(PresentEnemies()) > 1 && 
        random(3) )
    {
      command("schlachtruf");
    }
    else if( QueryProp(P_GUILD_LEVEL) >= 7 && 
              enemy->QueryProp(P_HP) < 4 * enemy->QueryProp(P_MAX_HP) / 10) 
    {
      command("spalten");
    }
    else if( QueryProp(P_GUILD_LEVEL) >= 5 && random(10) < 3 && 
        !enemy->QueryProp(P_DEAF) )
    {
      command("kampfschrei");
    }
    else
    {
      switch( 100 * enemy->QueryProp(P_SIZE) / QueryProp(P_SIZE))
      {
        case 0..30: 
          command("zertreten"); 
          break;
        case 80..300: 
          if( random(3) && QueryProp(P_GUILD_LEVEL) >= 6 ) 
            command("kopfstoss");
          else 
            command("rammen"); 
          break;
        default:
          command("rammen"); 
          break;
      }
    }
  }
  if( objectp(enemy) ) 
    ::Attack(enemy);
}
 
