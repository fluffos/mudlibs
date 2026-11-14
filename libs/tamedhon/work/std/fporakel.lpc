// Tamedhon MUDlib
//
// fporakel.c - Das FP-Orakel gibt Auskunft ueber die gefundenen FPs
//              eines Spielers
//
// $Date: 2008/03/16 21:00:00 $
/* $Revision: 1.3 $
 * $Log: fporakel.c,v $
 *
 * Revision 1.3  2008/03/16 21:00:00  TamTam
 * angepasst an das Tamedhon
 *
 * Revision 1.2  2001/01/03 18:33:11  Zordan
 * redundanten Code entfernt
 *
 * Revision 1.1  2001/01/03 18:31:20  Zordan
 * Initial revision
 *
 */

//
// Beispielhafte Anwendung in einem NPC:
//
//   inherit "std/npc";
//   inherit "std/fporakel";
//
// und in create():
//
//   AddInfo(({"forscherpunkte","forschen","fp","fps"}),
//             "@@all_questions@@", "sagt: ");
//   AddInfo(ME->QueryQuestions(), symbol_function("fp_info",ME), "sagt: ");
//
//     symbol_function() ist notwendig, da der gefragte Text als Parameter
//     an fp_info() uebergeben werden soll, was bei @@...@@ (process_string)
//     aber nicht der Fall ist.
//
//     Anmerkung: Es kann fuer NPCs Sinn machen, die letztere AddInfo()
//         Zeile in reset() nochmal aufzurufen, um das Info Mapping gegebenen-
//         falls zu aktualisieren, falls neue FP angehaengt wurden.
//
// Will man nur Antworten auf ganz bestimmte Gegenden geben, so kann man
// dieses bei Kenntnis der Namen (ggfs. Erzmagier fragen) mit z.B.:
//
//   AddInfo( "gidhrog", symbol_function("fp_info",ME), "sagt: ");
//
// erreichen!!!
//
// FP-Orakel sind GRUNDSAETZLICH vor dem CLONEN bei einem Erzmagier anzumelden!
//
//

#include <config.h>
#include <wizlevels.h>
#include "/secure/exploration.h"
#include <properties.h>
#include <defines.h>
#include <moredef.h>

void create()
{
  log_file("ORAKEL",sprintf("%s: %O %O %O\n",dtime(time()), TI,TP,PO));
}

string fp2str(int max)
{
  string ret;
  ret="Absolut gesehen ";
  switch(max)
  {
  case 0..15:
    ret += "kennst Du nur wenig von dieser Region.";
    break;
  case 16..20:
    ret += "solltest Du Dich vielleicht noch genauer umsehen.";
    break;
  case 21..25:
    ret += "bist Du durchaus schon herumgekommen.";
    break;
  case 26..30:
    ret += "hast Du schon einiges gesehen.";
    break;
  case 31..35:
    ret += "bist Du schon weit herumgekommen.";
    break;
  case 36..50:
    ret += "könntest Du eigentlich einen Reiseführer herausbringen.";
    break;
  case 51..75:
    ret += "hast Du schon sehr viel gesehen.";
    break;
  default:
    ret += "besitzt Du eine hervorragende Ortskenntnis.";
  }
  return ret;
}

string all_questions()
{
  string ss;
  mixed *q;
  int i;

  q=EPMASTER->QueryQuestions();
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

varargs string fp_info(string qid, string dontknow, string know)
{
  string s;
  int q;

  s = sprintf(dontknow || "%s? Darüber habe ich leider "
                          "keine Informationen.", CAP(qid));

  q=EPMASTER->QueryPercent(qid,getuid(TP));

  if(q && q >= 0)
  {
//     s = sprintf(know || "%s? Also davon kennst Du ziemlich "
//                 "genau %d Prozent!", CAP(qid),q);
     s = sprintf(know || "%s? %s", CAP(qid),fp2str(q));
  }
  return s;
}

string *QueryQuestions()
{
  mixed *q;

  q=EPMASTER->QueryQuestions();
  if(pointerp(q))
    return map(q, #'lower_case);
  else
    return ({ "\n_gar_nix_:-/" }) ;
}
