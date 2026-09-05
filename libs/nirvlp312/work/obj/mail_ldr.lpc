/*
 * mailer field loader/saver
 */

#if 0
#include <mudlib.h>
#include <levels.h>
#include <restore.h>
#else
#include "/include/mudlib.h"
#include "/include/cfg/levels.h"
#include "/include/fn/restore.h"
#endif

#define MAIL_FIELD_SAVE "ob_saves/mail_fld"

mixed *fields;

void reset(status arg) {
  if (arg) return;

  fields = ({
             ({
               "aspirant", "apprentice", "creator",
               "sage",     "lord",       "senior",
               "elder",    "arch",       "admin",
             }),
             ({
               ({}), ({}), ({}),
               ({}), ({}), ({}),
               ({}), ({}), ({}),
             }),
  });
}

void load_fields(object caller) {
  int i;

  if (!caller) return;
  restore_object(MAIL_FIELD_SAVE);
  for (i = 0; i < sizeof(fields[0]); i++) {
    caller->set_field(fields[0][i], fields[1][i]);
  }
}


string get_field_name(int sec_level) {
  return (sec_level >= SEC9)
       ? "admin"
       : (sec_level >= SEC8)
       ? "arch"
       : (sec_level >= SEC7)
       ? "elder"
       : (sec_level >= SEC6)
       ? "senior"
       : (sec_level >= SEC5)
       ? "lord"
       : (sec_level >= SEC4)
       ? "sage"
       : (sec_level >= SEC3)
       ? "creator"
       : (sec_level >= SEC2)
       ? "apprentice"
       : (sec_level >= SEC1)
       ? "aspirant"
       : 0;
}


void add_to_mail_field(string who, int sec_level) {
  int i, j;

  if (!who || !get_field_name(sec_level)) return;
  restore_object(MAIL_FIELD_SAVE);
  who = capitalize(who);
  for (i = 0; i < sizeof(fields[1]); i++) {
    if ((j = member_array(who, fields[1][i])) != -1) {
      fields[1][i] = fields[1][i][0..(j-1)] +
                     fields[1][i][(j+1)..(sizeof(fields[1][i])-1)];
    }
  }
  i = member_array(get_field_name(sec_level), fields[0]);
  fields[1][i] += ({ who });
  save_object(MAIL_FIELD_SAVE);
}

void remove_from_mail_field(string who) {
  int i, j;

  if (!who) return;
  restore_object(MAIL_FIELD_SAVE);
  who = capitalize(who);
  for (i = 0; i < sizeof(fields[1]); i++) {
    if ((j = member_array(who, fields[1][i])) != -1) {
      fields[1][i] = fields[1][i][0..(j-1)] +
                     fields[1][i][(j+1)..(sizeof(fields[1][i])-1)];
    }
  }
  save_object(MAIL_FIELD_SAVE);
}

