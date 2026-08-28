#include "/d/damned/virtual/virtual_table.h"
#include <daemons.h>
#include <dirs.h>

class v_table *armours;

int clean_up() {
  return 0;
}

void create() {
  int i, sz, last;
  class v_table next_item;
  string *file, w_type, tmp, arg_s;
  mixed *argv;

  seteuid(getuid());
  armours = ({});
  file = read_database(DIR_DATA_DAMNED+"/armour_types");
  sz = sizeof(file);
  last = 0;
  for(i=0; i<=sz; i++) {
    if(i == sz || sscanf(file[i], "(%s):", w_type) == 1) {
      if(next_item) {
        if(arg_s && strlen(arg_s)) {
          arg_s = replace_string(arg_s, "\n", " ");
          argv = map_array(explode(arg_s, ";"), (: call_other, REFS_D, "resolv_str" :));
          next_item->args += ({ argv });
        }
        else next_item->args += ({ ({}) });
        arg_s = "";
        armours += ({ next_item });
      }
      if(sz == i) return;
      next_item = new(class v_table);
      next_item->type = w_type;
      next_item->funcs = ({});
      next_item->args = ({});
      last = 0;
      continue;
    }
    if(sscanf(file[i], "%s:::", tmp) == 1) {
      if(last && arg_s && strlen(arg_s)) {
        arg_s = replace_string(arg_s, "\n", " ");
        argv = map_array(explode(arg_s, ";"), (: call_other, REFS_D, "resolv_str" :));
        next_item->args += ({ argv });
      }
      else if(last) next_item->args += ({ ({}) });
      arg_s = "";
      next_item->funcs += ({ "set_"+tmp });
      last = 1;
      continue;
    }
    arg_s += file[i];
  }
  write("Error, reached end prematurely.");
}

class v_table get_table(string w_type) {
  int i;

  i = sizeof(armours);
  while(i--)
    if(armours[i]->type == w_type) return armours[i];
  return 0;
}
