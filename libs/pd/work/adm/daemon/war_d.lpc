
#include <std.h>
#include <dirs.h>
#include <faction_cl.h>
#include <security.h>

#define SAVE_FILE DIR_SECURE_DAEMONS_SAVE+"/war_d.o" 

inherit DAEMON;

class Alliance *alliances;
class Faction *factions;


void saveme();
void restoreme();
int add_faction(string name);
int remove_faction(string name);
class Faction query_faction(string name);
void add_criteria(string name, string type,
  string func, mixed args, mixed value);
class FuncCheck *query_criteria(string name);
string *query_player_factions(object tp);
string *query_faction_alliances(string name);
int add_alliance(string name);
int remove_alliance(string name);
class Alliance query_alliance(string name);
void rename_alliance(string oldname, string newname);
void set_enemies(string name, string *enemies);
void add_enemy(string name, string enemy);
void remove_enemy(string name, string enemy);
string *query_enemies(string name);
void set_death(string name, string enemy, int perc);
void set_allies(string name, string *allies);
void add_ally(string name, string ally);
void remove_ally(string name, string ally);
string *query_allies(string name);
void set_score(string name, mapping m);
void add_score(string name, string key, mixed value);
mapping query_score(string name);
mixed *query_conflict(object p1, object p2);


void debugprint(mixed stuff) {
  if (this_player()) {
    printf("%O\n", stuff);
  }
}


void saveme() {
  seteuid(UID_SECURE_DAEMONSAVE);
  save_object(SAVE_FILE);
  seteuid(getuid());
}
void restoreme() {
  seteuid(UID_SECURE_DAEMONSAVE);
  restore_object(SAVE_FILE);
  seteuid(getuid());
}

void create() {
  restoreme();
  if (!sizeof(factions))
    factions = ({});
  if (!sizeof(alliances))
    alliances = ({});
}

int add_faction(string name) {
  class Faction f;
  if (query_faction(name))
    return 0;
  f = new(class Faction);
  f->name = name;
  f->member_criteria = ({});
  factions += ({ f });
  saveme();
  return 1;
}

int remove_faction(string name) {
  class Faction f = query_faction(name);
  if (!f)
    return 0;
  factions -= ({ f });
  saveme();
  return 1;
}

class Faction query_faction(string name) {
  foreach (class Faction f in factions)
    if (f && f->name == name)
      return f;
  return 0;
}

void add_criteria(string name, string type,
string func, mixed args, mixed value) {
  class Faction f = query_faction(name);
  if (f) {
    class FuncCheck c = new(class FuncCheck);
    c->type = type;
    c->func = func;
    c->args = args;
    c->value = value;
    if (!f->member_criteria)
      f->member_criteria = ({ });
    f->member_criteria += ({ c });
    saveme();
  }
}

class FuncCheck *query_criteria(string name) {
  class Faction f = query_faction(name);
  if (f)
    return f->member_criteria || ({});
  return ({});
}

string *query_player_factions(object tp) {
  class Faction *members = ({});
  foreach (class Faction f in factions) {
    int passed = 0;
    foreach (class FuncCheck check in (f->member_criteria || ({})) ) {
      mixed ret, args, tmp;

      // get the function arguments ready
      tmp = check->args;
      if (tmp) {
        if (!arrayp(tmp)) {
          tmp = ({ tmp });
        }
        // replace some special argument placeholders
        for (int i = 0; i < sizeof(tmp); i++) {
          if (stringp(tmp[i]) && tmp[i] == "$tp") {
            tmp[i] = tp;
          }
        }
        args = tmp;
      }

      // call lfuns differently from others...
      switch (check->type) {
        case "lfun":
          if (!args) args = ({});
          args = ({ check->func }) + args;
          ret = call_other(tp, args);
        break;
        case "sefun": case "sfun": case "simulefun": case "simul_efun":
        case "efun":
          ret = evaluate(check->func, args);
        break;
      }

      if (ret != check->value)
        break;
      else
        passed++;

    }

    if (passed >= sizeof(f->member_criteria)) {

      members += ({ f });
    }

  }

  if (sizeof(members)) {
    return map(members, (: $1->name :) );
  }

  return 0;
}

// returns all alliances the faction "name" is in
string *query_faction_alliances(string name) {
  class Alliance *a = filter(alliances,
    (: member_array($2, $1->allied_factions) != -1 :),
    name
  );
  if (sizeof(a)) {
    return map(a, (: $1->name :) );
  }
  return 0;
}

int add_alliance(string name) {
  class Alliance a;
  if (query_alliance(name))
    return 0;
  a = new(class Alliance);
  a->name = name;
  a->allied_factions = ({});
  a->enemy_alliances = ({});
  a->score = ([]);
  a->death = ([]);
  alliances += ({ a });
  saveme();
  return 1;
}

int remove_alliance(string name) {
  class Alliance a = query_alliance(name);
  if (!a)
    return 0;
  alliances -= ({ a });
  saveme();
  return 1;
}

class Alliance query_alliance(string name) {
  foreach (class Alliance a in alliances)
    if (a && a->name == name)
      return a;
  return 0;
}

void rename_alliance(string oldname, string newname) {
  class Alliance a;

  a = query_alliance(newname);
  if (a) return;

  a = query_alliance(oldname);
  if (a) {
    a->name = newname;
    foreach (class Alliance check in alliances - ({ a }) ) {
      if (member_array(oldname, check->enemy_alliances)) {
        check->enemy_alliances =
          check->enemy_alliances - ({ oldname }) + ({ newname });
      }
      if (check->death[oldname]) {
        check->death[newname] = check->death[oldname];
        map_delete(check->death, oldname);
      }
    }
    saveme();
  }
}

void set_enemies(string name, string *enemies) {
  class Alliance a = query_alliance(name);
  if (a) {
    a->enemy_alliances = enemies;
    saveme();
  }
}

void add_enemy(string name, string enemy) {
  set_enemies(name, query_enemies(name) + ({ enemy }) );
}

void remove_enemy(string name, string enemy) {
  set_enemies(name, query_enemies(name) - ({ enemy }) );
}

string *query_enemies(string name) {
  class Alliance a = query_alliance(name);
  if (a)
    return a->enemy_alliances || ({});
  return ({});
}

void set_death(string name, string enemy, int perc) {
  class Alliance a = query_alliance(name);
  if (a) {
    if (member_array(enemy, query_enemies(name)) != -1) {
      a->death[enemy] = perc;
    }
  }
}

void set_allies(string name, string *allies) {
  class Alliance a = query_alliance(name);
  if (a) {
    a->allied_factions = allies;
    saveme();
  }
}

void add_ally(string name, string ally) {
  set_allies(name, query_allies(name) + ({ ally }) );
}

void remove_ally(string name, string ally) {
  set_allies(name, query_allies(name) - ({ ally }) );
}

string *query_allies(string name) {
  class Alliance a = query_alliance(name);
  if (a)
    return a->allied_factions || ({});
  return ({});
}

void set_score(string name, mapping m) {
  class Alliance a = query_alliance(name);
  if (a) {
    a->score = m;
    saveme();
  }
}

void add_score(string name, string key, mixed value) {
  class Alliance a = query_alliance(name);
  if (a) {
    if (!a->score[key])
      a->score[key] = value;
    else
      a->score[key] += value;
    saveme();
  }
}

mapping query_score(string name) {
  class Alliance a = query_alliance(name);
  if (a)
    return copy(a->score) || ([]);
  return ([]);
}

mixed *query_conflict(object p1, object p2) {
  string *f1;
  string *f2;
  class Alliance *a1;
  class Alliance *a2;
  string *n1 = ({});
  string *n2 = ({});
  string desc1, desc2;
  int perc = 100;
  mixed *possibles = ({});

  // find all factions each player belongs to...
  f1 = query_player_factions(p1);
  f2 = query_player_factions(p2);

  if (!sizeof(f1) || !sizeof(f2)) return 0;

  // then find all alliances each of their factions is in
  foreach (string fcheck in f1)
    n1 += query_faction_alliances(fcheck);
  foreach (string fcheck in f2)
    n2 += query_faction_alliances(fcheck);

  a1 = filter(map(n1, (: query_alliance($1) :) ), (: $1 :) );
  a2 = filter(map(n2, (: query_alliance($1) :) ), (: $1 :) );

  if (!sizeof(a1) || !sizeof(a2)) return 0;

  n1 = map(a1, (: $1->name :) );
  n2 = map(a2, (: $1->name :) );

  // then, filter down to only the alliances of p1 that are enemies
  // of the alliances of p2 and vice-versa
  a1 = filter(a1, (: sizeof( $1->enemy_alliances & $2 ) :), n2);
  a2 = filter(a2, (: sizeof( $1->enemy_alliances & $2 ) :), n1);

  if (!sizeof(a1) || !sizeof(a2)) return 0;

  n1 = map(a1, (: $1->name :) );
  n2 = map(a2, (: $1->name :) );

  foreach (class Alliance acheck in a1) {
    foreach (string name in n2) {
      int temp = acheck->death[name];
      // make a list of possible conflicts to use
      possibles += ({ ({ acheck->name, name, temp || perc }) });
    }
  }
  foreach (class Alliance acheck in a2) {
    foreach (string name in n1) {
      int temp = acheck->death[name];
      possibles += ({ ({ name, acheck->name, temp || perc }) });
    }
  }

  possibles = sort_array(possibles,
    function(mixed *arr1, mixed *arr2) {
      if (arr1[2] < arr2[2]) return -1;
      if (arr1[2] > arr2[2]) return 1;
      return 0;
    }
  );

  // this should be the lowest death penalty possible
  return possibles[0];
}

