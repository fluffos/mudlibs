/* Function written by Stormdragon (though it is not from Wallowing afaik) - Acius
 */

#include <file_security.h>


mixed *targets;
string to_file;
mixed to_command;

mixed *build_targets(string str) {
  mixed *parts;

  parts = filter(map(explode(str, ","),#'find_player),lambda( ({ 'x  }), ({ #'?, 'x, 1, 0 }) ) );
  return parts;
}

void paste(mixed str) {
  int i;
  int j;
  mixed obs;

  if (targets) {
    for(i=0;i<sizeof(targets);i++) {
      if (stringp(str))
        tell_object(targets[i], str+"\n");
      else {
        for(j=0;j<sizeof(str);j++) {
          tell_object(targets[i], str[j]+"\n");
        }
      }
    }
  }
  else {
    if (stringp(str)) {
      str = ({ str });
    }
    for(j=0;j<sizeof(str);j++) {
      if (to_command)
        to_command->main(str[j]);
      else if (to_file)
        write_file(to_file, str[j]+"\n");
      else
        map(
          filter(
            all_inventory(
              environment(
                this_player()
              )
            ) - ({ this_player() }),
            #'living
          ),
      	  #'tell_object,
      	  str[j]+"\n");
    }
  }
}

input(string str) {
  if (str == ".") {
    drop_interface();
    return;
  }
  paste(str);
}

main(string str) {
  string file, who, redirect;
  int size;

  targets = 0;
  to_file = 0;
  to_command = 0;
  if (str) {
    if (sscanf(str, "as %s", to_file)==1) {
      who = 0;
      to_file = this_player()->make_path_absolute(to_file);
      if (!query_write_access(to_file, this_player())) {
        notify_fail("You can't write to "+to_file+".\n");
        return 0;
      }
      rm(to_file);
    }
    else if (sscanf(str, "|%s",  redirect)==1);
    else if (sscanf(str, "%s|%s", file, redirect)==2);
    else if (sscanf(str, "to %s", who) == 1);
    else if (sscanf(str, "%s to %s", file, who)==2);
    else if (sscanf(str, "%s %s", file, who)==2);
    else
      file = str;
    if (redirect) {
      object ob;

      if (file)
        while(file[<1]==' ')
          file=file[0..<2];
      while(redirect[0]==' ')
        redirect=redirect[1..];
      if ((to_command = find_cmd(redirect)) == 0) {
         notify_fail("No such command: "+redirect+".\n");
         return 0;
      }
      ob = find_object(to_command);
      if (!ob) {
        if (catch(call_other(to_command, "load"))) {
          notify_fail(to_command+" has got bugs.\n");
          return 0;
        }
        ob = find_object(to_command);
      }
      to_command = ob;
    }
    if (who) {
      targets = build_targets(who);
      if (!targets || !sizeof(targets)) {
        notify_fail("No targets\n");
        return 0;
      }
    }
    if (file) {
      string *text;

      file = this_player()->make_path_absolute(file);
      if (!query_read_access(file)) {
        notify_fail("You don't have access to "+file+"\n");
        return 0;
      }
      size = file_size(file);
      switch (size) {
        case -2: {
          notify_fail(file+" is a directory\n");
          return 0;
        }
        case -1: {
          notify_fail("File not found: "+file+"\n");
          return 0;
        }
        case 0: {
          notify_fail(file+" is empty\n");
          return 0;
        }
        default:
          ;
      }
      if (size > 8000) {
        notify_fail(file+" is too big to paste.\n");
        return 0;
      }
      text = explode(read_file(file), "\n");
      paste(text);
      return 1;
    }
  }
  add_interface("input", "|");
  return 1;
}

help() {
 write("Usage:\n"+
   "\tpaste as <file>        :paste to a file\n"+
   "\tpaste                  :paste input to say()\n"+
   "\tpaste to <who>         :paste input to target(s)\n"+
   "\tpaste |<command>       :paste input to a command\n"+
   "\tpaste <file>           :paste file to say() & exit\n"+
   "\tpaste <file> to <who>  :paste file to target(s) & exit\n"+
   "\tpaste <file>|<command> :paste file to a command & exit\n"+
   "\n"+
 "<file> is a path (relative or absolute\n"+
 "<who> may be either a person, or a comma seperated list of people.\n"+
 "<command> is any command in your path.\n"+
 "To end input, type a fullstop by itself on a line.\n");
}
