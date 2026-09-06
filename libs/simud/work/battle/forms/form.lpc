/** This file defines combat forms. These are where your
 * default actions in combat come from.
 *
 * Documentation here is thus far abysmal, and will hopefully
 * improve.
 */

#include <battle.h>

string query_name() { return "generic form"; }

string query_change_message() {
  return "~Name ~verbchange forms to '"+query_name()+"'.";
}

string * query_weapon_types() {
  return ({"combat.weapon.unarmed"});
}

string query_action_desc(string name) {
  return "Description of '"+name+"' action.";
}

string query_reaction_desc(string name) {
  return query_action_desc(name)+" *BUG A WIZARD TO FIX THIS*";
}

string *query_default_actions() {  return ({ }); }
string *query_actions() {  return ({ }); }
string *query_reactions() {  return ({ }); }

string *query_all_actions() {
  return this_object()->query_actions() +
         this_object()->query_reactions();
}

/** This function gets called from the living object if action is being
 * considered, but no action is on the queue. The job of this function is,
 * if desired, to push an action onto the action queue. If no action is
 * pushed, that's ok too, but you'll sit around like an idiot while getting
 * pounded.
 *
 * A caveat: This function is only called when readiness reaches 1000. It is
 * possible for some actions to have a lower readiness requirement than this,
 * but living doesn't know whether you are going to choose one of those, so
 * it waits until 1000 (the maximum readiness requirement) is reached before
 * having the form select an action. This (usually) guarantees that the action
 * triggers immediately, which helps avoid certain noxious sorts of confusion.
 */
void default_action( object who ) {
  string *list = who->query_form_actions() - query_reactions();
  string actfile;
  if( !sizeof(list) ) return;
  actfile = "/battle/actions/"+list[random(sizeof(list))];
  actfile->main();
}

int query_form_level(int x) {
  int f;
  for (f = 9; f > 1; f--) {
    if (x > (pow(2,f)*100)-100)
      return f;
  }
  return 1;
}
