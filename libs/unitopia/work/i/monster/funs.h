// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /i/monster/funs.h
// Description: Funktionen, die von /i/living benoetigt werden
// Author:      
// Modified by: 
//
// $Log: funs.h,v $
// Revision 1.5  2001/10/05 20:55:36  freaky
// Sichtbarkeit von Redefinitionen korrigiert.
//
// Revision 1.4  2001/04/06 23:35:42  gnomi
// Header eingebaut.
//
// Revision 1.3  2001/03/15 15:14:52  freaky
// query-scar-description rausgenommen
//
// Revision 1.2  2001/01/30 23:59:00  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

nomask int query_wiz_level() {}
nomask string *query_opfer() {}
nomask int query_moerder() {}
void add_sum_comm(int i) {}
void add_sum_move(int i) {}
varargs mixed query_eye_option(string str) {}
string query_sp_short_name() {}
string query_real_name() {}
int query_extended_hp_view() {}
