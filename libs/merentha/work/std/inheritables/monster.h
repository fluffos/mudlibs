// Petrarch
// Merentha Lib 1.0
// monster.h

#ifndef __MONSTER_H__
#define __MONSTER_H__

int force_me(string str);
void receive_message(string msgclass, string message);
int move_player(mixed dest);
void says(string str);
void emotes(string str);
varargs void catch_tell(mixed args);
int is_monster();

#endif
