//
// Wunderland Mudlib
//
// sys/events.h -- events macros
//
// $Log: events.h,v $
// Revision 1.7  2002/07/04 07:18:50  Fiona
// STOP_HANDLE neu
//

#ifndef __EVENTS_H__
#define __EVENTS_H__

#define EVENTD "/secure/eventd"

// Die Send-Modi (nur jeweils einer):
#define EM_SIMPLE      0   // Standard Modus - maximale Performance
#define EM_COPY        1   // einfache Kopie des Daten-Mappings
#define EM_DEEP_COPY   2   // echte Kopie des Daten-Mappings
#define EM_NO_MODIFY   2   // Alias auf EM_DEEP_COPY - kein modify moeglich
#define EM_NO_CANCEL  32   // Event kann nicht abgebrochen werden

// Zusatzmodi
#define EM_STOP_CANCEL 64  // Ereignis stoppt beim Abbruch
#define EM_STOP_HANDLE 128 // Ereignis stoppt beim Handler

// DEBUG-Modi
#define EM_FAKE        4   // Simuliert den Event nur intern im Eventd
                           // interessant i.V.m. EM_DEBUG, um alle Lauscher
                           // auf einen Event zu finden
#define EM_COMPLEX     8   // Mehr Daten (E_RECEIVERS)
#define EM_DEBUG      16   // maximale Infos (E_DEBUG_INFO)

// Data-Mapping Defines, die immer vorhanden sind:
#define E_SENDER       "e_sender"       // Sender-Objekt (auto)
#define E_ACTOR        "e_actor"        // wenn Sender/Akteur verschieden
#define E_DESTINATIONS "e_destinations" // Zielobjekte bei send()
#define E_COMMAND      "e_command"      // ausloesendes Kommando (auto)

// weitere eventuelle Data-Mapping Defines
#define E_MODIFIERS    "e_modifiers"  // die Modifizierer
#define E_CANCELLER    "e_canceller"  // die Abbrecher
#define E_HANDLER      "e_handler"    // die Handler
#define E_REACTORS     "e_reactors"   // die Reagierer
#define E_STOPPED      "e_stopped"    // Infos von EM_STOP_CANCEL
#define E_SILENT       "e_silent"     // Lauscher bekommen nichts mit

// Interessant wohl nur fuer Handler und Sender
#define E_CANCELLED    "e_cancelled"  // Abbruch-Info
#define E_HANDLED      "e_handled"    // Handler-Info

// Interessant bei manchen Events fuer alle Lauscher, vor allem die Handler
#define E_USE_NFAIL    "e_use_nfail"  // notify_fail() statt tell_object() benutzen

// Defines im Complex-Mode
#define E_RECEIVERS    "e_receivers"  // *object - alle Empfaenger

// Defines im Debug-Mode
#define E_DEBUG_INFO   "e_debug_info" // ({ Prios, Closures, Kosten })

// Vorgaben fuer 'unkritische' Lauscher
#define EPRIO_MODIFY           700
#define EPRIO_CANCEL           400
#define EPRIO_HANDLE           100
#define EPRIO_DEF_HANDLE         0
#define EPRIO_REACT          (-300)
#define EPRIO_NOTIFY         (-999)

#define EPRIO_C_HANDLE     (-10000)
#define EPRIO_C_REACT      (-10300)
#define EPRIO_C_NOTIFY     (-10999)

// wir beschraenken erstmal nix
#define VALID_EVENT(x) (1)

#endif // __EVENTS_H__
