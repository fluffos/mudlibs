// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /room/rathaus/div/rollen_weg.inc
// Description: Ausschalten von Funktionen fuer sicherheitskritische NPCs
// Author:	Gnomi
// Modified by:
//
// $Log: rollen_weg.inc,v $
// Revision 1.7  2014/10/18 09:16:50  myonara
// Typanpassungen von irgendjemand
//
// Revision 1.6  2003/12/15 00:03:43  gnomi
// add/set_parse_conversation privatisiert.
//
// Revision 1.5  2001/10/14 19:35:15  sissi
// chat - Funktionen aus /i/tools/chat auch deaktiviert.
//
// Revision 1.4  2001/04/07 00:12:15  gnomi
// Header/CVS-Log eingebaut.
//

// Hiermit werden die Rollen und die chat Funktionen und alle Funktionen,
// welche irgendwelche frei waehlbaren Funktionen aufrufen, deaktiviert.

mixed do_fun_call(mixed ob, string funktion, varargs mixed *parameter) {}
mixed do_efun_call(string funktion, varargs mixed *parameter) {}
void rolle_v2() {}
void rolle() {}
varargs int beginne_rolle(mapping r, string label) {}
varargs int starte_rolle(string rollenname, string label, varargs mixed *params) {}

void add_a_chats(mixed msgs) {}
void add_chats(mixed msgs) {}
void load_a_chat(int chance, mixed chat) {}
void load_chat(int chance, mixed chat) {}

// set_parse_conversation kann beliebige Funktionen aufrufen.
private void add_parse_conversation(object ob, mixed *set) {::add_parse_conversation(ob,set);}
private void set_parse_conversation(object ob, mixed *set) {::set_parse_conversation(ob,set);}
