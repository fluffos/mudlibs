#ifndef __AUTOSAVE_H
#define __AUTOSAVE_H

void setup();
void heart_beat();
nomask void save_player(string nom);
void pre_save();
nomask void actually_save_player(string nom);
nomask int restore_player(string nom);
int remove();
string query_name();

#endif __AUTOSAVE_H
