/* the standard curses/diseases stuff to be inherited into the
 * living object.
 *
 * Should be pretty easy stuff.
 * Some of these functions are player specific... But the remove
 * stuff can be done on npcs too.
 *
 * Curses/diseases objects to interface with this...
 * The object should have some
 * functions defined on it called player_quit, query_remove and
 * player_start.
 * The player_quit function is called when the player quits.  This is
 * used to clean up anthing that might need cleaning up.
 * The query_remove function checks to see if the caller can remove it.
 * this should be used by the clerics remove curse to check this. Should
 * be pased the skill bonus in the appropriate skill.
 * The player_start will be called when the player logs on.
 */

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

mapping query_curses() { return curses; }
mapping query_diseases() { return diseases; }

int add_disease(string name, string ob) {
  if (!mappingp(diseases))
    diseases = ([ ]);
  diseases[name] = ob;
  return 1;
}

int remove_disease(string name) {
  if (!mappingp(diseases))
    diseases = ([ ]);
  if (!diseases[name])
    return 0;
  this_player()->destruct_disease(name);
  diseases = m_delete(diseases, name);
}

int remove_curse(string name) {
  int i;

  if (!mappingp(curses))
    curses = ([ ]);
  if (!curses[name])
    return 0;
  this_player()->destruct_curse(name);
  curses = m_delete(curses, name);
}

int add_curse(string name, string ob) {
  int i;

  if (!mappingp(curses))
    curses = ([ ]);
  if (curses[name])
    remove_curse(name);
  curses[name] = ob;
  return 1;
}

void curses_quit() {
  int i;

  if (!mappingp(diseases))
    diseases = ([ ]);
  if (!mappingp(curses))
    curses = ([ ]);
  filter_mapping(curses, "player_curses_quit", this_object());
  filter_mapping(diseases, "player_curses_quit", this_object());
/*
  for (i=0;i<sizeof(curses);i+=2)
    catch(curses[i+1][0]->player_quit());
  for (i=0;i<sizeof(diseases);i+=2)
    catch(diseases[i+1][0]->player_quit());
 */
}

int player_curses_quit(object ob) {
  catch(ob->player_quit());
}

void curses_start() {
  int i;

  if (!mappingp(diseases))
    diseases = ([ ]);
  if (!mappingp(curses))
    curses = ([ ]);
  filter_mapping(curses, "player_curses_start", this_object());
  filter_mapping(diseases, "player_curses_start", this_object());
/*
  for (i=0;i<sizeof(curses);i+=2)
    catch(curses[i+1][0]->player_start());
  for (i=0;i<sizeof(diseases);i+=2)
    catch(diseases[i+1][0]->player_start());
 */
}

int player_curses_start(object ob) {
  catch(ob->player_start());
}
