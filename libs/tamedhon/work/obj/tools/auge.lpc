//
// ----------------------------------------------------------------------------
// Datei:        auge.c
// Autor:        Rommy
// Datum:        12.09.2008
// ----------------------------------------------------------------------------
// Beschreibung: Das magische Auge zeigt Raummeldungen an.
//               Hilfreich beim Testen
// ----------------------------------------------------------------------------
// Aenderungen:
// 03.03.2009  Rommy  Farbe veraenderbar und Bug bei mehreren Augen ausgebaut
//                    Setzen von Owner vereinfacht
// 22.07.2009  Rommy  temperaturresistenter
// 15.04.2012  Rommy  remove falls owner netztot ist


inherit "/std/npc";

#pragma strong_types
#include <properties.h>
#include <language.h>
#include <wizlevels.h>
#include <vt100.h>

string auge_hilfe();
void tell(string str);

object owner;   // An wen sendet das Auge Meldungen?
string color;   // Welche Farbe haben die Meldungen des Auges?


void create() {
    string cloner;
    string *cl;
    if (!clonep(this_object())) return;
    ::create();

    // owner setzen (magiername oder NOBODY:testiename aus P_CLONER)
    cloner = this_object()->QueryProp(P_CLONER);
    cl = explode(cloner, ":");
    if (sizeof(cl) > 1)
        cloner = cl[1];

    owner = find_player(cloner);
    if (!owner) {
        say("Fehler. Cloner: "+cloner+"\n");
        this_object()->remove();
        return;
    }

    create_default_npc(5);

    SetProp(P_NAME, "Auge");
    SetProp(P_NAME_ADJ, "magisch");
    SetProp(P_GENDER, NEUTER);
    SetProp(P_SHORT,
      "Das magische Auge von "+capitalize(getuid(owner)));
    SetProp(P_LONG,
      "Ohne das geringste Geräusch von sich zu geben, schwebt das magische "
      "Auge hier und beobachtet wachsam alles, was geschieht. Es hat lange, "
      "schwarze Wimpern und seine Iris ist violett. Die Pupille ist "
      "ständig in Bewegung und alles, was sie wahrnimmt, meldet das Auge "
      "direkt an seinen Besitzer.");
    AddId(({"auge","\nauge_"+getuid(owner)}));
    AddAdjective(({"magische","magisches"}));
    SetProp(P_RACE, "Monster");
    SetProp(P_MSGIN, "schwebt herein");
    SetProp(P_MSGOUT, "schwebt");
    SetProp(P_MMSGIN, "erscheint aus dem Nichts");
    SetProp(P_MMSGOUT, "verschwindet spurlos");
    SetProp(P_ALIGN, 1000);
    SetProp(P_SIZE, 10);
    SetProp(P_AVERAGE_SIZE, 10);
    SetProp(P_TEMPERATURE_RANGE, ([0:-200, 1:200]));
    SetProp(P_NOATTACK, "schwebt irritiert aus Deiner Reichweite.");
    SetProp(P_INFO, break_string(
      "Mit \"auge hilfe\" wird die Hilfe angezeigt.", 70));

    color = VT_CYAN;

    enable_commands();
    set_living_name("auge_"+getuid(owner));

    AddCmd("auge","auge");
}


int auge(string arg) {
    string dir;
    string farbe;
    notify_fail("Das magische Auge hat Dich nicht verstanden.\n");
    if (owner != this_player()) {
        notify_fail("Das magische Auge ignoriert Dich völlig.\n");
        return 0;
    }
    if (!arg || arg == "hilfe") {
        tell(auge_hilfe());
        return 1;
    }
    if (arg == "destruct" || arg == "zu")  {
        say(break_string("Das magische Auge blinzelt langsam und löst "
          "sich dann in Luft auf."));
        remove();
        return 1;
    }
    if (sscanf(arg, "farbe %s", farbe) == 1) {
        switch (farbe) {
            case "yellow":
            case "gelb":
            case "braun":   color = VT_YELLOW;
                            break;
            case "red":
            case "rot":     color = VT_RED;
                            break;
            case "lila":
            case "magenta": color = VT_MAGENTA;
                            break;
            case "cyan":
            case "blau":
            case "hellblau":color = VT_CYAN;
                            break;
            case "normal":
            case "weiss":
            default:        color = "";
        }
        tell("Farbe geändert. Mögliche Farben: gelb, rot, lila, cyan und normal.\n");
        return 1;
    }

    if (sscanf(arg, "go %s", dir) == 1) {
        switch (dir) {
            case "norden":
            case "n":     command("norden"); break;
            case "sueden":
            case "s":     command("süden"); break;
            case "osten":
            case "o":     command("osten");  break;
            case "westen":
            case "w":     command("westen"); break;
            case "oben":  command("oben");   break;
            case "unten": command("unten");  break;
            case "nordwesten":
            case "nw":    command("nordwesten"); break;
            case "nordosten":
            case "no":    command("nordosten");  break;
            case "suedwesten":
            case "sw":    command("südwesten"); break;
            case "suedosten":
            case "so":    command("südosten");  break;
            default:
            tell("Das magische Auge kann nicht nach "+dir+" schweben.\n");
        }
        return 1;
    }
    return 0;
}


string auge_hilfe() {
  return
    "Das magische Auge flüstert Dir zu:\n"
    "  auge zu               Zerstört das Auge\n"
    "  auge farbe <farbe>    Ändert die Farbe der Meldung\n"
    "  auge go <richtung>    Schickt Auge nach <richtung>\n";
}


void tell(string text) {
    if (!this_object() || !environment() || !owner || !interactive(owner)) {
        // owner gibt es nicht oder ist netztot
        this_object()->remove();
        return;
    }
    tell_object(owner, color + text + VT_NORMAL);
}


void catch_tell(string msg) {
    if (!msg || msg == "")
        return;
    else
        tell(msg);
}

