#include "parse_command.h"
string *lng,
       *shrt,
       *adjs,
       *plu,
       *name;
mapping verb,
        plural;
int *cur_desc;

void create() {
  adjs = ({ });
  lng = ({ "" });
  shrt = ({ "" });
  plu = ({ });
  name = ({ });
  verb = ([ ]);
  plural = ([ ]);
  cur_desc = ({ });
} /* create() */

string short() {
  string *ret;
  int i;

  ret = ({ });
  for (i=0;i<sizeof(cur_desc);i++)
    ret += ({ shrt[cur_desc[i]] });
  return query_multiple_short(ret);
} /* short() */

string *pretty_short() {
  string *ret;
  int i;

  ret = ({ });
  for (i=0;i<sizeof(cur_desc);i++)
    ret += ({ shrt[cur_desc[i]] });
  return ret;
} /* pretty_short() */

string query_plural() {
  string *ret;
  int i;

  ret = ({ });
  for (i=0;i<sizeof(cur_desc);i++)
    ret += ({ pluralize(shrt[cur_desc[i]]) });
  return query_multiple_short(ret);
} /* query_plural() */

string *pretty_plural() {
  string *ret;
  int i;

  ret = ({ });
  for (i=0;i<sizeof(cur_desc);i++)
    ret += ({ pluralize(shrt[cur_desc[i]]) });
  return ret;
} /* query_plural() */

string long() {
  int i;
  string ret;

  ret = "";
  for (i=0;i<sizeof(cur_desc);i++) {
    if (!lng[cur_desc[i]])
      continue;
    ret += lng[cur_desc[i]];
  }
  if (ret == "")
    return "Error in items.\n";
  return ret;
} /* long() */

/*
void set_long(string s) { lng[cur_desc] = s; }
string query_long() { return lng[cur_desc]; }
 */
int *query_cur_desc() { return cur_desc; }
mapping query_verbs() { return verb; }
mapping query_plurals() { return plural; }

string *query_lng() { return lng; }
string *query_shrt() { return shrt; }

int drop() { return 1; }
int get() { return 1; }

void setup_item(mixed nam, string long) {
  string *bits, s;
  int i;

  if (pointerp(nam)) {
    if (sizeof(nam) > 0)
      shrt += ({ nam[0] });
    for (i=0;i<sizeof(nam);i++) {
      bits = explode(nam[i], " ");
      name += ({ (s=bits[sizeof(bits)-1]) });
      if (!verb[s]) {
        verb[s] = ({ bits[0..sizeof(bits)-2], sizeof(lng) });
        plural[(s=pluralize(s))] = ({ bits[0..sizeof(bits)-2], sizeof(lng) });
      } else {
        verb[s] += ({ bits[0..sizeof(bits)-2], sizeof(lng) });
        plural[(s=pluralize(s))] += ({ bits[0..sizeof(bits)-2], sizeof(lng) });
      }
      plu += ({ s });
      adjs += bits[0..sizeof(bits)-2];
    }
    lng += ({ long });
    return ;
  }
  shrt += ({ nam });
  bits = explode(nam, " ");
  name += ({ (s=bits[sizeof(bits)-1]) });
  if (!verb[s]) {
    verb[s] = ({ bits[0..sizeof(bits)-2], sizeof(lng) });
    plural[(s=pluralize(s))] = ({ bits[0..sizeof(bits)-2], sizeof(lng) });
  } else {
/* Dey are both existant... */
    verb[s] += ({ bits[0..sizeof(bits)-2], sizeof(lng) });
    plural[(s=pluralize(s))] += ({ bits[0..sizeof(bits)-2], sizeof(lng) });
  }
  plu += ({ s });
  adjs += bits[0..sizeof(bits)-2];
  lng += ({ long });
} /* setup_item() */

int modify_item(string str, string new_long) {
  int i;

  if ((i = member_array(str, shrt)) == -1)
    return 0;
/* Got a match... */
  lng[i] = new_long;
  return 1;
} /* modify_exit() */

int remove_item(string str, string new_long) {
  int i;
  string *inds;

  if ((i = member_array(str, shrt)) == -1)
    return 0;
/* Ok, got him.  Now we need to track down all the bits.  Sigh. */
/* this is a mess.  I am not sure I want to do it.  So I won't for now. */
} /* remove_item() */

string *parse_command_id_list() { return name; }
string *parse_command_plural_id_list() { return plu; }
string *parse_command_adjectiv_id_list() { return adjs; }

object query_parse_id(mixed *arr) {
  string *bits;
  mixed stuff;
  int i, j;

/* all case */
  if (arr[P_THING] == 0) {
    bits = explode(arr[P_STR], " ");
    if (!(stuff = plural[bits[sizeof(bits)-1]]))
      if (!(stuff = verb[bits[sizeof(bits)-1]]))
        return 0;
    cur_desc = ({ });
    for (j=0;j<sizeof(stuff);j+=2) {
      for (i=0;i<sizeof(bits)-2;i++)
        if (member_array(bits[i], stuff[j]) == -1)
          break;
      if (i < sizeof(bits)-2)
        continue;
      cur_desc += ({ stuff[j+1] });
    }
    return this_object();
  }
  if (arr[P_THING] < 0) { /* specific object case */
    bits = explode(arr[P_STR], " ");
    if (!(stuff = verb[bits[sizeof(bits)-1]]))
      return 0;
    for (j=0;j<sizeof(stuff);j+=2) {
      for (i=0;i<sizeof(bits)-2;i++)
        if (member_array(bits[i], stuff[j]) == -1)
          break;
      if (i < (sizeof(bits) - 2) || ++arr[P_THING] != 0)
        continue;
/* Get the current thingy out of the list */
      cur_desc = ({ stuff[j+1] });
      arr[P_THING] = -10321;
      return this_object();
    }
    return 0;
  }
/* Lots of objects case.  The objects are specified though. */
  bits = explode(arr[P_STR], " ");
  if (!(stuff = plural[bits[sizeof(bits)-1]]))
    if (!(stuff = verb[bits[sizeof(bits)-1]]))
      return 0;
  cur_desc = ({ });
  for (j=0;j<sizeof(stuff);j+=2) {
    for (i=0;i<sizeof(bits)-2;i++)
      if (member_array(bits[i], stuff[j]) == -1)
        continue;
    if (i < sizeof(bits)-2)
      continue;
    cur_desc += ({ stuff[j+1] });
    arr[P_THING]--;
    if (arr[P_THING] <= 0) {
      arr[P_THING] = -10786;
      return this_object();
    }
  }
  return this_object();
} /* query_parse_id() */

void dest_me() {
  destruct(this_object());
  return ;
} /* dest_me() */

void dwep() {
  destruct(this_object());
  return ;
} /* dwep() */

int move() { return 1; }
