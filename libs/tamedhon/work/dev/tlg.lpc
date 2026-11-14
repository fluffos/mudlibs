/* /dev/tlg
 *
 * hier koennen objecte temporaer ZWISCHENgelagert werden...
 * (xokarr nutzt das - also bitte auch nich loeschen ;) )
 *
 * 05/08/2004 Serii
 *
 * Aenderungen:
 * 11.06.2009  Grynnis  env_temperatur:40 gesetzt, damit Daemonen und Waechter
 *                      keine LP verlieren beim Geleiten
 */

inherit "std/room";

#include <properties.h>
#include <wizlevels.h>
#include <language.h>
#include <moving.h>
#include <player.h>

void create()
{
  ::create();
  SetProp(P_LIGHT,0);
  SetProp(P_INT_SHORT, "/dev/tlg");
  SetProp(P_INT_LONG, " --- Temporäres LagerGerät --- ");
  SetProp(P_INDOORS,0);
  SetProp(P_ENVIRONMENT, ([ENV_TEMPERATURE:40, ENV_TERRAIN:TT_OTHER]));
}

void init()
{object tp;
  ::init();
  tp=this_player();
  if(IS_GOD(tp))return;
  if(query_once_interactive(tp)&&!tp->QueryProp(P_PARALYZED)&&!IS_LEARNER(tp)){tp->move("/room/jail",M_GO|M_SILENT);return;}
}
