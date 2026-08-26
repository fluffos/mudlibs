
#include <parser.h>

inherit COMMAND_BASE;

string var_name = "map_prop ";
string fname;

/*
 * This will add a property to a player.
 */
mixed cmd(string player, string name, string value) {
   mixed *args;
   string file;
   string *bits;
   mapping map_prop;
   int i, found;

   seteuid("Root");

   fname = "/save/players/" + player[0..0] + "/" + player;

   /* Restore them... */
   map_prop = ([ ]);
   if ("/secure/login"->test_user(player)) {
      file = unguarded( (: read_file(fname+".o") :));
      if(!file)
        return notify_fail("Error reading player file " + fname + ".\n");
      
      bits = explode(file, "\n");
      map_prop = ([ ]);
      for (i = 0; i < sizeof(bits); i++) {
         if (bits[i][0..strlen(var_name)-1] == var_name) {
            map_prop = restore_variable(bits[i][strlen(var_name) + 0..]);
            found = 1;
            break;
         }
      }
      if(!found || !map_prop)
        return notify_fail("Failed to find property mapping.\n");
      
      args = PARSER->parse_args(value);
      if (args && sizeof(args[0]) > 0) {
         map_prop[name] = args[0][0];
         if (i < sizeof(bits)) {
            bits[i] = var_name + save_variable(map_prop);
         } else {
            bits += ({ var_name + save_variable(map_prop) });
         }

         
         unguarded( (: rm(fname + ".old") :) );
         
         unguarded( (: rename(fname+".o", fname+".old") :) );

         unguarded( (: write_file(fname + ".o",
                                  implode($(bits), "\n") + "\n") :));
         
         write(sprintf("Added property %s to %s; value = %O\n",
                       name, player, args[0][0]));
      } else {
         write("No useful args...\n");
      }
   } else {
      write("Unable to find player "+player+".\n");
   }
   return 1;
} /* cmd() */

mixed *query_patterns() {
  return ({ "<word> <string:quoted> <string>", (: cmd($4[0], $4[1], $4[2]) :),
            });
} /* query_patterns() */
