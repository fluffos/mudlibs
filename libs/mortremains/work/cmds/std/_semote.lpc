// file:   semote.c
// mudlib: Basis
// date:   1992/09/25
// cleaned-up by Zeus, also added formatted output 25/02/1993

#include <config.h>
#include <daemons.h>
#include <emoted.h>

#define SPACES "                                                                               "

int
compare(string one, string two) {
        return strcmp(one, two);
}

int
cmd_semote(string arg) {
     string *list, *output;
     int index, x, y, rows, cols, l;
     int length, num, i, targeted;
     string verb, result;

     if(arg) {
          targeted = 0;
          if(sscanf(arg, "%s/t", verb)) targeted = 1;
          else verb = arg;
          if(targeted) {
               result = (string)EMOTE_D->query_temote(verb);
               if(result) write(result);
          } else {
               result = (string)EMOTE_D->query_emote(verb);
               if(result) write(result);
          }
          if(!result) notify_fail("semote: unable to find " + arg + "\n");
          return (result != 0);
     }
     list = sort_array((string *)EMOTE_D->query_keys(),"compare",this_object());
     num = sizeof(list);
     for(index = 0; index < num; index++) {
          i = strlen(list[index]);
          if(i > length) length = i;
     }
     length ++;
     if(length > 75) length = 75;
     cols = 80 / (length + 4); // change 4 to increase or reduce no. of columns
     if(!cols) cols = 1;
     rows = num / cols;
     if(rows * cols < num) rows++;
     output = allocate(rows);
     for(y = 0; y < rows; y++) {
          output[y] = "";
          for(x = 0; x < cols; x++) {
               index = x * rows + y;
               if(index > num - 1) break;
               l = strlen(list[index]);
               output[y] += "  "+list[index];
               if(length - l > 0) output[y] += (SPACES[1 .. (length - l)]);
          }
     }
     this_player()->more(output);
     return 1;
}

int help() {
	write ("Usage: semote <argument>\n\n"+
"With an argument, semote will show you the soul entry for the soul command\n"+
"<argument>. Without an argument, semote will list all available commands.\n"+
"\nSee also: temote, edemote.\n") ;
	return 1 ;
}
