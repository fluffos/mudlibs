/* the standard curses/diseases stuff.
 *
 * Partially rewritten by Quark, nov 97  Woah, he actually DID something!!!!
 *
 * See /std/curses/curses.txt on how to make your own curse
 *
 * Important functions:
 * int add_curse(string name);  to add the curse, returns 0 if the curse doesn't 
 *      			exist else 1
 * int add_disease(string name);  same as add_curse but for diseases (:
 * int remove_curse(string name, object remover);  To remove a curse.
 *                              will return 1 on success,  0 if the player isn't 
 *  				cursed with that curse and -1 on failure to remove.
 * int remove_disease(string name, object remover); same as remove_curse
 * string *query_curses()   returns the curses you currently have
 * string *query_diseases() same as query_curses
 * 
 */

#define CURSE_TAB "/table/curse_tab"

mapping curses,
        diseases;

void create() {
  curses = ([ ]);
  diseases = ([ ]);
}

string query_curse(string name) {
  if (!mappingp(curses))
    curses = ([ ]);
  if (!curses[name])
    return 0;
  return curses[name];
}

string query_disease(string name) {
  if (!mappingp(diseases))
    diseases = ([ ]);
  if (!diseases[name])
    return 0;
  return diseases[name];
}

string *query_curses() { return keys(curses); }
string  *query_diseases() { return keys(diseases); }

int add_disease(string name) {
  object ob;
  if (!mappingp(diseases))
    diseases = ([ ]);
  if(!ob = CURSE_TAB->query_disease(name))
    return 0;
  diseases[name] = ob;
  ob->init_curse(this_object());
  ob->player_start(this_object());
  return 1;
}

int remove_disease(string name, object remover) {
  if (!mappingp(diseases))
    diseases = ([ ]);
  if (!diseases[name])
    return 0;
  if(remover)
   { 
    if(diseases[name]->prevent_remove(this_object(), remover))
     return -1;
   }
  diseases[name]->curse_end(this_object());
  diseases[name]->player_quit(this_object());
  diseases = m_delete(diseases, name);
  return 1;
}

int add_curse(string name) {
  object ob;

  if (!mappingp(curses))
    curses = ([ ]);
  if(!ob = CURSE_TAB->query_curse(name))
    return 0;
  curses[name] = ob;
  ob->init_curse(this_object());
  ob->player_start(this_object());
  return 1;
}

int remove_curse(string name, object remover) {
  int i;

  if (!mappingp(curses))
    curses = ([ ]);
  if (!curses[name])
    return 0;
  if(remover)
   { 
     if(curses[name]->prevent_remove(this_object(), remover))
     return -1;
   }
  curses[name]->curse_end(this_object());
  curses[name]->player_quit(this_object());
  curses = m_delete(curses, name);
  return 1;
}



void curses_quit() {
  int i;
  string *names;

  if (!mappingp(diseases))
    diseases = ([ ]);
  if (!mappingp(curses))
    curses = ([ ]);
  names = keys(curses);
  for (i=0;i<sizeof(names);i++)
    catch(curses[names[i]]->player_quit(this_object()));
  names = keys(diseases);
  for (i=0;i<sizeof(names);i++)
    catch(diseases[names[i]]->player_quit(this_object()));
}


void curses_start() {
  int i;
  string *names;

  if (!mappingp(diseases))
    diseases = ([ ]);
  if (!mappingp(curses))
    curses = ([ ]);
  names = keys(curses);
  for (i=0;i<sizeof(names);i++)
    catch(curses[names[i]]->player_start(this_object()));
  names = keys(diseases);
  for (i=0;i<sizeof(names);i++)
    catch(diseases[names[i]]->player_start(this_object()));
}

void curses_heart_beat() {
  int i;
  string *names;

  if (!mappingp(diseases))
    diseases = ([ ]);
  if (!mappingp(curses))
    curses = ([ ]);
  names = keys(curses);
  for (i=0;i<sizeof(names);i++)
    catch(curses[names[i]]->curse_heart_beat(this_object()));
  names = keys(diseases);
  for (i=0;i<sizeof(names);i++)
    catch(diseases[names[i]]->curse_heart_beat(this_object()));
}
