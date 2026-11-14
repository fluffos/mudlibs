// Dieses File ist Teil der UNItopia MUDlib
// -----------------------------------------------------------------
// File:        /sys/editor.h
// Description: Defines fuer den Spieler-LPC-EDitor
// Author:      Mammi (17.01.99)
//
// $Log: editor.h,v $
// Revision 1.7  2009-10-14 19:48:46  gnomi
// WebMUD-Editor statt des Mini-ED verwenden.
//
// Revision 1.6  2003/07/16 00:56:42  gnomi
// Typo.
//
// Revision 1.5  2002/08/31 01:17:24  gnomi
// Defines fuer die neuen Parameter des mini-ed.
//
// Revision 1.4  2001/06/19 23:45:53  gnomi
// MINI_ED-KOnstanten unterscheiden sich von den ED-Konstanten.
//
// Revision 1.3  2001/04/28 03:42:43  gnomi
// Defines fuer den Mini-Ed eingetragen.
//
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef EDITOR_H
#define EDITOR_H 1

#define ED_UNRECOGNIZED_COMMAND      1
#define ED_HELP_1                    2
#define ED_HELP_2                    3
#define ED_SUBST_LINES_HELP          4
#define ED_SUBST_LINES_FAILED        5
#define ED_SUBST_LINES_GLOBAL_FAILED 6  
#define ED_MOVE_LINES_FAILED         7
#define ED_START_TEXT                8
#define ED_NEW_TEXT                  9
#define ED_APPEND_TEXT               10
#define ED_MAX_SIZE_OVERRUN          11
#define ED_TEXT_RESTORED             12
#define ED_TEXT_CHANGED              13
#define ED_MARKER_HELP               14
#define ED_NUMBERS_ON                15
#define ED_NUMBERS_OFF               16
#define ED_ALREADY_EDITING           17
#define ED_AT_END                    18

#define ED_MSGS_SIZE                 18


#define ED_STD_MSGS ([ \
     ED_UNRECOGNIZED_COMMAND: \
"Der Befehl existiert nicht oder er ist so nicht ausfuehrbar.\n", \
     ED_HELP_1: 0, \
     ED_HELP_2: 0, \
     ED_SUBST_LINES_HELP: \
"s/<orginal>/<neu>[/<optionen>]\n", \
     ED_SUBST_LINES_FAILED: \
"Die Ersetzung schlug fehl.\n", \
     ED_SUBST_LINES_GLOBAL_FAILED: \
"Das Ersetzungsmuster darf das zu ersetzende nicht enthalten, wenn die\n" \
"Option 'g' (globale Ersetzung) genutzt wird.\n", \
     ED_MOVE_LINES_FAILED: \
"Du hst eine ungueltige Zielzeile angegeben.\n", \
     ED_START_TEXT: \
"Diese Texteingabe funktioniert wie der ED --- Tippe h fuer Hilfe.\n", \
     ED_NEW_TEXT: \
"Du beginnst einen neuen Text.\n", \
     ED_APPEND_TEXT: 0, \
     ED_MAX_SIZE_OVERRUN: 0, \
     ED_TEXT_RESTORED: \
"Aktueller Text durch Originaltext ersetzt.\n", \
     ED_TEXT_CHANGED: \
"Der Text wurde veraendert (x fuer Abspeichern und Ende, Q fuer Ende)\n", \
     ED_MARKER_HELP: \
"Benutze 'k<buchstabe>' zum Markieren einer Zeile.\n", \
     ED_NUMBERS_ON: \
"Zeilennummernanzeige ist jetzt eingeschaltet.\n", \
     ED_NUMBERS_OFF: \
"Zeilennummernanzeige ist jetzt ausgeschaltet.\n", \
     ED_ALREADY_EDITING: \
"Du schreibst schon einen Text.\n", \
     ED_AT_END: \
"Du bist am Ende des Textes (tippe a fuer Anhaengen neuen Textes).\n", \
])

// Noch ein paar Defines fuer den Mini-Ed
#define MINI_ED_ALREADY_EDITING     257
#define MINI_ED_START_TEXT          258
#define MINI_ED_PLAYER_INFO         259
#define MINI_ED_WIZ_INFO            260
#define MINI_ED_MAX_SIZE_OVERRUN    261
#define MINI_ED_NAME                262

#define MINI_ED_STD_MSGS ([ \
     MINI_ED_START_TEXT: \
"Gib nun den Text ein. Mit '**' oder '.' beenden, mit '~q' abbrechen.\n", \
     MINI_ED_ALREADY_EDITING: \
"Du schreibst schon einen Text.\n", \
     MINI_ED_PLAYER_INFO: \
"Mit '~e' kommt man in den ED.\n", \
     MINI_ED_WIZ_INFO: \
"Mit '~e' kommt man in den ED, mit ~x in den XED und mit ~p in den Player-ED.\n", \
     MINI_ED_MAX_SIZE_OVERRUN: \
"Mehr als %d Zeilen darfst Du nicht schreiben.\n", \
     MINI_ED_NAME: \
"Editor", \
])

#define MINI_ED_WRAP_LEN	1
#define MINI_ED_FORCE_WRAP	2

#endif // EDITOR_H
