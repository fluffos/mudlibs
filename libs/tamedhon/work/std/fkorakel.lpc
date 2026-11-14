// Tamedhon MUDlib
//
// fkorakel.c - Das FK-Orakel gibt Auskunft ueber die erlegten FKs
//              eines Spielers
//
// $Date: 2008/03/16 21:00:00 $
/* $Revision: 1.0 $
 * $Log: ekorakel.c,v $
 *
 * Revision 1.0  2008/03/16 21:00:00  TamTam
 * analog zum FP-Orakel aus dem Silberland
 * Initial revision
 *
 */

//
// Beispielhafte Anwendung in einem NPC:
//
//   inherit "std/npc";
//   inherit "std/fkorakel";
//
// und in create():
//
//   AddInfo(({"erstkills","erstkill","erstkiller","ek","eks",
//             "firstkills","firstkill","firstkiller","fk","fks"}),
//             "@@all_questions@@", "sagt: ");
//   AddInfo(ME->QueryQuestions(), symbol_function("fk_info",ME), "sagt: ");
//
//     symbol_function() ist notwendig, da der gefragte Text als Parameter
//     an fk_info() uebergeben werden soll, was bei @@...@@ (process_string)
//     aber nicht der Fall ist.
//
//     Anmerkung: Es kann fuer NPCs Sinn machen, die letztere AddInfo()
//         Zeile in reset() nochmal aufzurufen, um das Info Mapping gegebenen-
//         falls zu aktualisieren, falls neue FK angehaengt wurde.
//
// Will man nur Antworten auf ganz bestimmte Gegenden geben, so kann man
// dieses bei Kenntnis der Namen (ggfs. Erzmagier fragen) mit z.B.:
//
//   AddInfo( "gidhrog", symbol_function("fk_info",ME), "sagt: ");
//
// erreichen!!!
//
// FK-Orakel sind GRUNDSAETZLICH vor dem CLONEN bei einem Erzmagier anzumelden!
//
//

#include <config.h>
#include <wizlevels.h>
#include "/secure/npcmaster.h"
#include <properties.h>
#include <defines.h>
#include <moredef.h>

void create()
{
  log_file("ORAKEL",sprintf("%s: %O %O %O\n",dtime(time()), TI,TP,PO));
}

string fk2str(int max)
{
  string ret;
  ret="Absolut gesehen ";
  switch(max)
  {
  case 0..15:
    ret += "kannst Du keiner Fliege etwas zu leide tun.";
    break;
  case 16..20:
    ret += "bist Du in dieser Region nur als Schmetterlingsfänger bekannt.";
    break;
  case 21..25:
    ret += "hast Du durchaus schon mal etwas erlegt.";
    break;
  case 26..30:
    ret += "hast Du schon einiges erlegt.";
    break;
  case 31..35:
    ret += "hast Du schon etliche Trophäen gesammelt.";
    break;
  case 36..50:
    ret += "könntest Du eigentlich eine Safari leiten.";
    break;
  case 51..75:
    ret += "bist Du ein erfahrener Kämpfer.";
    break;
  default:
    ret += "bist Du der gefürchtetste Kämpfer weit und breit.";
  }
  return ret;
}

string all_questions()
{
  string ss;
  mixed *q;
  int i;

  q=NPCMASTER->QueryQuestions();
  ss="Ich kann Dir Informationen über folgende Gegenden geben: ";

  if(!pointerp(q))
  {
    ss+="Gar keine!";
    return ss;
  }
  if(sizeof(q)>1) {
    for(i=0;i<sizeof(q)-1;i++) {
      ss+=CAP(q[i])+", ";
    }
  }
  if(sizeof(q)>0)
    ss+=CAP(q[sizeof(q)-1])+".";
  return ss;
}

varargs string fk_info(string qid, string dontknow, string know)
{
  string s;
  int q;

  s = sprintf(dontknow || "%s? Darüber habe ich leider "
                          "keine Informationen.", CAP(qid));

  q=NPCMASTER->QueryPercent(qid,getuid(TP));

  if(q && q >= 0)
  {
//     s = sprintf(know || "%s? Also davon hast Du schon ziemlich "
//                 "genau %d Prozent!", CAP(qid),q);
     s = sprintf(know || "%s? %s", CAP(qid),fk2str(q));
  }
  return s;
}

string *QueryQuestions()
{
  mixed *q;

  q=NPCMASTER->QueryQuestions();
  if(pointerp(q))
    return map(q, #'lower_case);
  else
    return ({ "\n_gar_nix_:-/" }) ;
}
