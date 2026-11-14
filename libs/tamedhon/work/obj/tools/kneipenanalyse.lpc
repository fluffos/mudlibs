// Magiertool
// ----------------------------------------------------------------------------
// Datei:        kneipenanalyse.c
// Autor:        Rommy@Tamedhon
// Datum:        07.11.2009
// ----------------------------------------------------------------------------
// Beschreibung: Kneipenanalyse-Tool
// ----------------------------------------------------------------------------
// Aenderungen:
// 17.01.2010  Rommy  Gruen fuer < 7.0

inherit "/std/thing";

#include <properties.h>
#include <language.h>
#include <wizlevels.h>
#include <ansi.h>
#include <pub.h>

void create() {
    if (!clonep(this_object()))
        return;
    ::create();

    SetProp(P_NAME, "Kneipen-Tool");
    SetProp(P_SHORT, "Das Kneipen-Tool");
    SetProp(P_LONG,
      "Das Kneipen-Tool ist ein unschlagbares Hilfsmittel, um Insidertipps "
      "für Tamedhons Kneipen zu erhalten. Mit 'analyse' verrät es Magiern "
      "alles Wissenswerte über das Menü der aktuellen Kneipe, welche "
      "Speisen und Getränke besonders zu empfehlen sind und auch, was man "
      "nur mit Vorsicht und in geringen Mengen genießen sollte. "
      "Das Tool beanstandet ein zu gutes Preis/Leistungs- und Heilungs/"
      "Sättigungs-Verhältnis in "+ANSI_LRED+"ROT"+ANSI_NORMAL+
      " beziehungsweise "+ANSI_LYELLOW+"GELB"+ANSI_NORMAL+". "+
      ANSI_LGREEN+"GRUEN"+ANSI_NORMAL+" ist balancekonform.");
    SetProp(P_GENDER, NEUTER);
    AddId(({"kneipentool","kneipen-tool","Tool","tool","pubtool"}));
    SetProp(P_VALUE,1000);
    SetProp(P_WEIGHT,100);
    SetProp(P_NOBUY,1);
    SetProp(P_NOSELL,1);
    SetProp(P_NODROP,1);
    SetProp(P_NEVERDROP,1);
    SetProp(P_AUTOLOADOBJ,1);
    SetProp(P_INFO,
      "Preis:     Preis laut Menü\n"
      "Preisempf: grobe Preisempfehlung des Kneipentools\n"
      "Heal:      Durchschnittlich <Heal> LP und <Heal> MP Heilung\n"
      "Alk:       Alkohol-Gehalt (vgl P_ALCOHOL)\n"
      "Soak:      Sättigung (vgl P_DRINK bzw. P_FOOD)\n"
      "Func:      Sonderfunktion beim Bestellen?\n"
      "H/S:       Heal/(Soak+Alk)\n"
      "           Werte über 7 brauchen eine Begründung an die Balance!\n");

    AddCmd(({"analyse"}), "analysieren");
}

void init() {
    if (!IS_WIZARD(this_player())) {
        write(Name()+" zerfällt in Deinen Händen zu Staub.\n");
        say(Name()+" zerfällt in "+this_player()->name(WESSEN)+" Händen.\n");
        call_out("remove",0);
        return;
    }
    ::init();
}

mixed get_avg(mixed heal) {
    if (intp(heal)) return heal;
    if (pointerp(heal))
        //     (  lp   +   mp  +heal[2]/2+heal[2]/2)/2.0
        return (heal[0]+heal[1]+heal[2])/2.0;
    return 0;
}


int analysieren(string arg) {
    mixed food,drink;
    string analyse;
    object pub;
    int i;
    int empf; // preisempfehlung
    float heal;
    float hs; // heal/soak
    if (!interactive(environment(this_object()))) return 0;
    notify_fail("Syntax: analyse\n");
    if (arg) return 0;
    pub=environment(environment(this_object()));
    if (!pub->isPub()) {
        write("Beweg Dich erst mal in eine Kneipe.\n");
        return 1;
    }
    food=pub->query_food();
    drink=pub->query_drink();
    if (!food && !drink) {
        write("Hier gibt's weder Speisen noch Getränke!\n");
        return 1;
    }
    analyse="";
    analyse+=ANSI_BOLD+
      "Getränke                     Preis Preisempf Heal Alk/Soak Func  H/S"
      +ANSI_NORMAL+"\n";
    for (i=0; i<sizeof(drink); i++) {
        heal=get_avg(drink[i][3]);
        hs=(drink[i][4]+drink[i][5]);
        hs=(hs==0?999.0:heal/hs);
        empf=to_int(heal*3)+drink[i][4]+drink[i][5];
        analyse+=sprintf(
          "%-29.29s %s%5.5d%s  %5.5d    %3.3d %3.3d %3.3d    %s    %s%.3g%s\n",
          drink[i][0],
          to_int(empf*0.8)>drink[i][2]?to_int(empf*0.5)>drink[i][2]?
           ANSI_LRED:ANSI_LYELLOW:ANSI_LGREEN,
          drink[i][2], ANSI_NORMAL, empf, to_int(heal),
          drink[i][4], drink[i][5],
          (closurep(drink[i][6])||stringp(drink[i][6]))?"J":"-",
          hs>7.0?hs>10.0?ANSI_LRED:ANSI_LYELLOW:ANSI_LGREEN,
          hs, ANSI_NORMAL);
    }
    analyse+="\n";
    analyse+=ANSI_BOLD+
      "Speisen                       Preis Preisempf Heal     Soak Func  H/S"
      +ANSI_NORMAL+"\n";
    for (i=0; i<sizeof(food); i++) {
        heal=get_avg(food[i][3]);
        hs=food[i][4];
        hs=(hs==0?999.0:heal/hs);
        empf=to_int(heal*3)+food[i][4];
        analyse+=sprintf(
          "%-29.29s %s%5.5d%s  %5.5d    %3.3d     %3.3d    %s    %s%.3g%s\n",
          food[i][0],
          to_int(empf*0.8)>food[i][2]?to_int(empf*0.5)>food[i][2]?
           ANSI_LRED:ANSI_LYELLOW:ANSI_LGREEN,
          food[i][2], ANSI_NORMAL, empf, to_int(heal), food[i][4],
          (closurep(food[i][5])||stringp(food[i][5]))?"J":"-",
          hs>7.0?hs>10.0?ANSI_LRED:ANSI_LYELLOW:ANSI_LGREEN,
          hs, ANSI_NORMAL);
    }
    write(analyse);
    return 1;
}
