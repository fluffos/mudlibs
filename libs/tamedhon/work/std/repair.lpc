// SilberLand MUDlib
//
// std/repair.c --  Ein Standard-Reparatuer
//
// $Date$
/* $Revision$
 * $Log$
 */

inherit "std/mnpc";

#include <properties.h>
#include <language.h>
#include <combat.h>
#include <bank.h>
#include <defines.h>
#include <moredef.h>

#define RBS(x) break_string(x, 78, Name(WER,1)+" sagt: ", 1)
#define MIN_WEAPON_COST 50
#define MIN_ARMOUR_COST 200

int rep_money;

void create()
{
  if (!clonep(this_object())) return;

  ::create();

  rep_money=0;

  AddId ( "Reparateur" );

  AddInfo( ({"reparatur", "reparieren", "repariere"}),
    "Wenn Du willst, kann ich Deine Waffen und Rüstungen reparieren. Gib "
    "dazu einfach 'repariere <name>' ein. Leider muss ich aber einiges an "
    "Geld dafür verlangen.", "sagt: ");

  AddCmd( ({"repariere", "reparatur"}), "reparatur");
 
}

int rep_auswahl(object ob)
{
  return 1;
}

int reparatur( string str)
{
  object ob;
  int dam, value, wert, kosten, min_kosten;
  if( TP->InFight() )
    return notify_fail("Im Kampf geht das nicht!\n"),0;
  notify_fail(RBS("Was willst Du reparieren lassen?"));
  if( !str ) return 0;
  if( !(ob = present(str, TP)) ) return 0;
  if( dam = ob->QueryProp(P_DAMAGED) )
  {
    if( ! (value = ob->QueryProp(P_VALUE)) )
    {
       write(RBS("Ich repariere keine wertlosen Sachen!"));
       return 1;
    }
    if( ob->QueryProp(P_WEAPON_TYPE))
    {
      wert = ob->QueryProp(P_WC);
      min_kosten=MIN_WEAPON_COST * dam;
    }
    else if( ob->QueryProp(P_ARMOUR_TYPE))
    {
      wert = ob->QueryProp(P_AC); 
      min_kosten=MIN_ARMOUR_COST * dam;
    }
    else
    {
      write(RBS("Ich kann nur Waffen und Rüstungen reparieren."));
      return 1;
    }
    if( ! rep_auswahl(ob) )
      return 1;
    kosten = 3 * value * dam /  (dam+wert) ;
    if( kosten < min_kosten ) kosten = min_kosten; 
    write(RBS("Die Reparatur "+ob->name(WESSEN,1)+" würde "+kosten +
        " Münzen kosten!"));
    write(Name(WER,1)+" fragt Dich: Willst Du das bezahlen?\n");
    write(" (ja/nein) -> ");
    input_to("reparieren2",0, ob, dam, kosten, time());
    return 1;
  }
  else
  {
    write(RBS("Aber "+ ob->name(WER,1)+ " braucht gar keine Reparatur."));
    return 1;
  }
  return 0;
}
  
void reparieren2(string str, object ob, int damrep, int kosten, int zeit)
{ 
  if (!TP) return;
  if (environment(TP) != environment(TO)) {  // Spieler mit !bla rausgegangen...?
    write("Dazu ist es jetzt zu spät!\n");
    return;
  }
  if (time() > (zeit+15))       // 15 Sekunden Zeit
  {
    write(RBS("Du hast Dir zu viel Zeit gelassen! Überlege es Dir "
        "noch einmal... unser Angebot bleibt natürlich bestehen!"));
    return;
  }
  if ((str!="ja") && (str!="j")) 
  {
    write(RBS("Na gut, wie Du meinst. Viel Spass noch damit!"));
    return;
  }
  if (!ob) 
  {
    write(RBS("Nanu, wo ist denn der fragliche Gegenstand " 
        "so plötzlich hinverschwunden??"));
    return;
  }             
  if (environment(ob) != TP) 
  { 
    write(RBS("Nanu, wo ist denn "+ob->name(WER,1)+
        " so plötzlich hinverschwunden??"));
    return;     
  }
  if (damrep > ob->QueryProp(P_DAMAGED)) 
  {
    write(RBS("Huch, irgendwas stimmt da nicht, "+ob->name(WER,1)+
        " ist ja gar nicht mehr so arg beschädigt wie vorhin!"
        " Probier es doch bitte noch einmal..."));
    return;
  } 
  if (TP->QueryMoney() < kosten) 
  {
    write(RBS("Das Problem ist nur, dass Du "+kosten+" Münzen "
        "gar nicht dabei hast! Das Beste ist, Du holst Dir etwas "
        "Geld von der Bank oder pumpst Dir etwas..."));
    return;
  } 
  TP->AddMoney(-kosten);
  rep_money+=kosten;
  if( ob->QueryProp(P_WEAPON_TYPE))
    ob->SetProp(P_WC,ob->QueryProp(P_WC)+damrep);
  else if( ob->QueryProp(P_ARMOUR_TYPE))
    ob->SetProp(P_AC,ob->QueryProp(P_AC)+damrep);
  ob->SetProp(P_DAMAGED, ob->QueryProp(P_DAMAGED)-damrep);
  write(BS(Name(WER,1)+" nimmt Dir "+kosten+" Münzen ab und beginnt "
    "mit der Reparatur "+ob->name(WESSEN,1)+". Kurze Zeit später ist "+
    QueryPronoun()+" fertig und drückt "+ob->QueryPronoun(WEN)+" Dir in "
    "wesentlich besserem Zustand als zuvor in die Hand."));
}

void reset()
{
  ::reset();
  if( rep_money )
    ZENTRALBANK->PayIn(rep_money);
  rep_money=0;
}

