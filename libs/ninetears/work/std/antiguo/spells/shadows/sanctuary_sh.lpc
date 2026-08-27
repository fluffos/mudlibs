#include <spells.h>

object *madesave, *failsave;
object my_player;

void setshadow(object ob)
{
  object *outed, *attlist;
  int i;
  outed=ob->query_call_outed();
  for (i=0;i<sizeof(outed);i++)
  {
    if (!madesave) madesave=({outed[i]});
    else madesave +=({outed[i]});
  }
  attlist=ob->query_attacker_list();
  for (i=0;i<sizeof(attlist); i++)
  {
    if (!madesave) madesave=({attlist[i]});
    else madesave+=({attlist[i]});
  }
  shadow(ob,1);
  my_player=ob;
}

void destruct_sanct_shadow()
{
  destruct(TO);
}

int query_sanc()
{
  return 1;
}

void attack_by(object ob)
{
  object guild;
  int save, level;

  guild=ob->query_guild_ob();
  level=ob->query_level();
// save=guild->query_saving_throw("spell", level);
  save=15-(level/3);

  if (member_array(ob, madesave) > -1) 
   {
     destruct_sanct_shadow();
     return my_player->attack_by(ob);
   }
  if (member_array(ob, failsave) > -1)
  {
    tell_object(my_player,ob->QCN+" comienza a atacarte pero se retira "
    "del combate bruscamente.\n");
    tell_object(ob,"No te atreves a atacar a "+my_player->QCN+" ahora.\n");
    tell_room(ENV(my_player),ob->QCN+" intenta atacar a "+my_player->QCN+" pero se retira del combate.\n",({ob, my_player}));
    ob->stop_fight(my_player);
    my_player->stop_fight(ob);
    return;
  }
  if ((random(19)+1)>=save)
  {
    tell_object(my_player, ob->QCN+" rompe tu santuario y te golpea!!!\n");
    destruct_sanct_shadow();
    if (sizeof(madesave)) madesave+=({ob});
    else madesave=({ob});
    return my_player->attack_by(ob);
  }
  else
  {
    tell_object(my_player, ob->QCN+" ha intentado atacarte, pero el santuario repele el ataque.\n");
    tell_object(ob, "You try TO attack "+my_player->QCN+" but you're suddenly compelled TO sTOp.\n");
    tell_room(ENV(my_player),ob->QCN+" attempts TO attack "+my_player->QCN+", but cannot continue.\n",({ob,my_player}));
    if (sizeof(failsave)) failsave+=({ob});
    else failsave=({ob});
    ob->stop_fight(my_player);
    my_player->stop_fight(ob);
    return;
  }
}

void attack_ob(object ob)
{
  if (member_array(ob,madesave)>-1) return my_player->attack_ob(ob);
  tell_object(my_player,"No puedes instigar a otro bajo los efectos del Santuario.\n");
}

int adjust_hp()
{
  return 0;
}