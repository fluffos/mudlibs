void spell_poison( object enemy, int damage, mixed dam_type)
{
  enemy->AddPoison(1+random(2));
  return;
}

void spell_shielddestruct( object enemy, int damage, mixed dam_type)
{
  object *things;
  object ob;
  int x;

  if( !sizeof(things=enemy->QueryArmours(AT_SHIELD)))
    return;

  ob=things[0];
  tell_object(enemy,"  "+Name(WER,2)+" trifft Dein Schild mit voller Kraft!\n");
  ob->TakeFlaw(100);
  if(random(100)>=95 && !ob->id("NODESTRUCT") && !ob->QueryProp(P_CURSED) &&
      ob->QueryProp(P_QUALITY_DECAY)){
    tell_room(environment(enemy),"  "+Name(WER,2)+" zerstoert "+ob->name(WEN,1)+"!\n");
    ob->remove( 1 );
  }
  return;
}


void spell_weapondestruct( object enemy, int damage, mixed dam_type)
{

  object ob;
  int x;

  if((ob=enemy->QueryProp(P_WEAPON)))
  {
    if(!ob->id("NODESTRUCT") && 
      !ob->QueryProp(P_CURSED) && !ob->QueryProp(P_MAGIC) && 
      ob->QueryProp(P_QUALITY_DECAY))
    {
      if(random(1000)>=999){
        tell_object(enemy,"  "+Name(WER,2)+" zerstoert "+ob->name(WEN,1)+"!\n");
        ob->remove( 1 );
        return;
      }
      else if(ob && random(1000)>950 && !ob->QueryProp(P_CURSED) &&
          !ob->QueryProp(P_NODROP))
      {
        tell_object(enemy,break_string("  "+Name(WER,2)+" reisst Dir "+ob->name(WEN,1)+
              " aus den Haenden und steckt "+ob->QueryPronoun(WEN)+" ein!\n", 78));
        ob->move(this_object(),M_NOCHECK);
        return;
      }
    }
    tell_object(enemy,"  "+Name(WER,2)+" schafft es nicht, Dir Deine Waffe "
        "wegzunehmen.\n");
    return;
  }
  tell_object(enemy,"  "+Name(WER,2)+" schaut verbluefft, als "+
      QueryPronoun(WER)+" merkt das Du keine Waffe gezueckt hast.\n");
  return;
}


void spell_moneydestruct( object enemy, int damage, mixed dam_type)
{
  object ob;
  if(ob=deep_present("\ngeld",enemy)){
    tell_object(enemy,"  "+Name(WER,2)+" klaut Dir Geld und frisst es auf!\n");
    ob->AddAmount(-(1000+random(2000)));
  }
  return;
}


void spell_hold( object enemy, int damage, mixed dam_type)
{
  int t;
  object ob;

  t = 2 + random(this_object()->QueryProp(P_LEVEL) / 3);
  if (t > 10) t = 10;

  //  enemy->SetProp(P_DISABLE_ATTACK, t);
  //  enemy->SetProp(P_DISABLE_SPELLS, t);
  /* Move Hook macht probleme beim Sterben.... nochmal genau testen
     if(!enemy->QueryProp(P_TMP_MOVE_HOOK)){
     enemy->SetProp(P_TMP_MOVE_HOOK, ({ time()+t,
     this_object(), "player_tries_to_move" }) );
     }
     */
  if (!ob = present("\nhold", enemy))
  {
    ob = clone_object(SPELLOBJ "hold");
    ob->move(enemy, 2);
    ob->set_time(t);
  }
  else
    ob->set_time(t/2);
  return;
}

void spell_flue( object enemy, int damage, mixed dam_type)
{
  if(random(100)>50 && !present("\nimp", enemy)){
    clone_object("/d/dschungel/dante/weg/obj/dmala.lpc")->move(enemy,M_NOCHECK);
  }
  else if (random(100) > 50 && !present("TURN", enemy))
    clone_object("/d/dschungel/dante/stein/obj/turn.lpc")->move(enemy,M_NOCHECK);
  return;
}

#include "./sprachfluch.h"

void spell_backspeech( object enemy, int damage, mixed dam_type)
{
  spell_sprachfluch(enemy, damage, dam_type);
  return;
}

void spell_brainstorm( object enemy, int damage, mixed dam_type)
{
  clone_object(SPELLOBJ "brainstorm")->move(enemy,M_NOCHECK);
  return;
}

void spell_manadrain( object enemy, int damage, mixed dam_type)
{
  clone_object(SPELLOBJ "mana_drain")->move(enemy,M_NOCHECK);
  return;
}

void spell_strengthdrain( object enemy, int damage, mixed dam_type)
{
  clone_object(SPELLOBJ "strength_drain")->move(enemy,M_NOCHECK);
  return;
}
void spell_bloodloss( object enemy, int damage, mixed dam_type)
{
  clone_object(SPELLOBJ "bloodloss")->move(enemy,M_NOCHECK);
  return;
}

void spell_drop( object enemy, int damage, mixed dam_type)
{
  object ob;
  if( present("\ntrapdoor", environment(enemy)) )
    return;
  ob=clone_object(SPELLOBJ "dig_npc_obj");
  ob->move(environment(enemy),M_NOCHECK);
  ob->start_saug(enemy);
  return;
}

