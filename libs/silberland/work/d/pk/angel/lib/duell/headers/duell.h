/*******************************************************************************
 * Duell System fuer den Ehrenbuerger-Orden und die NPCs in der Stadt der Ehre
 * Datei: duell.h
 * Autor: Angel (avs@sbox.tu-graz.ac.at)
 */

#ifndef __DUELL_H__
#define __DUELL_H__

#define P_DUELL_DURATION 		 600 // 10 Minuten
#define P_PROLONGATE_DUELL               600 // 10 Minuten Verlaengerung
#define P_REFRESH_TIME                   300 //  5 Minuten
#define P_CHALLENGE_DURATION             120 //  2 Minuten
#define P_DUELL_PENALTY_TIME		     780 // 13 Minuten
#define P_MAX_CHOOSE_TIME                180 //  3 Minuten Zeit zu waehlen
#define P_MODIFY_SUMMONED_DAMAGE           0 //  Faktor zur Modifizierung der
                                             //  Staerke von beschworenen Kreaturen.
#define P_ILLEGAL_ITEMS     ({ "Nahrung", "magierblut", "sarnakmaske", "kanne", "msack" })  //  Die unerlaubten Gegenstaende im Duell:

#endif // __DUELL_H__


  // Prototypen Deklaration:

#ifdef NEED_PROTOTYPES_ALL

#define NEED_PROTOTYPES_ORDEN
#define NEED_PROTOTYPES_DUELL
#define NEED_PROTOTYPES_NPC
#define NEED_PROTOTYPES_VARS_GET
#define NEED_PROTOTYPES_VARS_SET
#define NEED_PROTOTYPES_REWARDS

#endif


#ifdef NEED_PROTOTYPES_ORDEN
#ifndef __DUELL_H_PROTOTYPES_ORDEN__
#define __DUELL_H_PROTOTYPES_ORDEN__

  // Funktionen fuer Orden
  int wear (string args);
  int put_off (string args);
  int show_commands (string args);
  int attempt_wear (string args);
  int attempt_kill (string args);
  object verify_opponent (string name);
  object check_orden (object opponent);
  string message_penalty (int penalty, int opponent);

#endif
#endif


#ifdef NEED_PROTOTYPES_DUELL
#ifndef __DUELL_H_PROTOTYPES_DUELL__
#define __DUELL_H_PROTOTYPES_DUELL__

  // Variablen im Orden (fuer Duell):

  nosave int    MayGet;	            // Einmal darf der orden mit M_GET
   			            // weitergegeben werden (beim clone)
  nosave int    challenge_time;     // Zeit der Herausforderung
  nosave int    challenger;         // Haben wir gefordert? (1)
                                    // oder wurden wir gefordert? (2)
  nosave object challenge_opponent; // Herausforderer Speichern
  nosave object duell_opponent;     // Duellgegner Speichern
  nosave int    wartezeit;          // Besiegte Spieler muessen warten,
                                    // bis sie wieder kaempfen duerfen
  nosave int    fatality_mode;      // Wollen es die Duellanten
                                    // wissen? (Sicherungen aus!)
  nosave int    honour_mode;        // Duell ohne Bewegung!
  nosave int    wish_for_break_off; // Will jemand aufgeben?
  nosave object potential_opponent; // Ein NPC dem man ein Pfand gegeben hat.

  // Funktionen fuer das Duell
  void save_life (object player, int duration);
  int check_duell ();
  int akzeptiere (object gegner, int fatality, int honour);
  int keep_alife ();
  int request_end (string reason);
  int confirm_end ();
  void save_life (object player, int duration);
  void remove_safety (object player);
  void no_save_life (object player, int duration);
  int after_life ();
  varargs void break_off_duell (int silent);
  int paralyze (int zeit, object player);
  int freeze_in_place ();
  void finish_duell ();
  int is_element (mixed arr, object el);
  int is_registered (object ob);
  int is_registering (object ob);

#endif
#endif


#ifdef NEED_PROTOTYPES_NPC
#ifndef __DUELL_H_PROTOTYPES_NPC__
#define __DUELL_H_PROTOTYPES_NPC__

  // NPC-spezifische Funktionen
  int  get_pawn_value ();
  void set_pawn_value (int value);
  int get_safe_challenge_duration ();
  void set_safe_challenge_duration ();

#endif
#endif


#ifdef NEED_PROTOTYPES_REWARDS
#ifndef __DUELL_H_PROTOTYPES_REWARDS__
#define __DUELL_H_PROTOTYPES_REWARDS__

  // Variablen fuer den Orden (pawn/reward)
  nosave mixed duell_results; // ({winner, looser, time})
  nosave object pawn_item;    // Ein Gegenstand den sich ein NPC
                              // Gegner behaelt falls er gewinnt,
                              // andernfalls jedoch zurueckgibt.


  // Funktionen fuer die rewards/pawns
  int query_objects (int silent);
  int choose_object ();
  int find_bounty (string args);
  int set_pawn (object obj);
  object get_pawn ();
  int set_pot_opponent (object obj);
  object get_pot_opponent ();

#endif
#endif

#ifdef NEED_PROTOTYPES_VARS_SET
#ifndef __DUELL_H_PROTOTYPES_VARS_SET__
#define __DUELL_H_PROTOTYPES_VARS_SET__

  //Funktionen zum Setzten von Variablen
  void set_challenge_opponent(object opponent);
  void set_duell_opponent(object opponent);
  void set_challenge_time(int zeit);
  void set_challenger (int value);
  void set_wartezeit (int value);
  void set_wish_for_break_off (int value);
  void set_duell_results (mixed res);

#endif
#endif

#ifdef NEED_PROTOTYPES_VARS_GET
#ifndef __DUELL_H_PROTOTYPES_VARS_GET__
#define __DUELL_H_PROTOTYPES_VARS_GET__

  // Funktionen zur Auswertung von Variablen
  object get_challenge_opponent();
  object get_duell_opponent();
  int get_challenge_time();
  int get_challenger ();
  int get_wartezeit ();
  int get_wish_for_break_off ();
  mixed get_duell_results (int number);

#endif
#endif
