#include <wizard.h>

string format(string str) {
   int x,s,l;
   string buf = "";

   for (x = 0; x < sizeof(str); x++) {
      if (str[x] == '"')
         if (s = !s)
            buf += "~[060";
         else
            buf += "~CDEF";
      else {
         buf += str[x..x];
         if (!s && member(",;:",str[x]) != -1)
            buf += " ";
      }
   }

   buf = implode(explode(buf,", }"),"}");
   buf = implode(explode(buf,", ]"),"]");

   return buf;
}

int main(string str) {
   string file, stat, buf, line, *zeros = ({}), *map = ({});
   mapping data = ([]);
   object what = find_thing(str);
   int long = 0, x, cols, player;
   int width = this_player()->query_term_width() - 1;

   if (!str) {
      msg("You need to specify an object to stat!");
      return 1;
   }

   if ( !what ) {
      msg("Sorry, I couldn't find "+str+".");
      return 1;
   }

   player = what->query_is_player();
   file = "/secure/odin"->get_save_file_name((what->query_unique_id()))+".o";
   stat = what->get_stat();

   if ((string)what == str)
      buf = "~CTITStat: ~CDEF"+str;
   else
      buf = "~CTITStat: ~CDEF"+str+" (~CTIT"+(string)what+"~CDEF)";
   if (file)
      buf += "\n~CTITFile: ~CDEF"+file;
   msg(buf);

   if (!stat) {
      msg("This object does not work with stat and probably never will.");
      return 1;
   }

   foreach( line : explode(stat,"\n") ) {
      string a, b;
      if (sscanf(line,"%s %s",a,b) != 2)
         continue;
      if (b == "0") {
         zeros += ({ a });
      } else {
         if (sizeof(a) > long)
            long = sizeof(a) + 1;
         data += ([a:cleanup_string(b)]);
      }
   }

   if (player)
      data -= (["password"]);

   foreach( line : sort_array(m_indices(data),#'>) ) {
      string type = "unknown";

      if (data[line][0] == '"') {
         type = "string";
         data[line] = regreplace(data[line], "~", "~TILD", 0);
         data[line] = (strlen(data[line])>20?"~[030":"~[060") + data[line][1..<2];
      } else if (data[line][0..1] == "([") {
         type = "mapping";
         data[line] = format(data[line]);
         if (player) {
            map += ({line});
            continue;
         }
      } else if (data[line][0..1] == "({") {
         type = "array";
         data[line] = format(data[line]);
      } else if (member(data[line],'.') == -1)
         type = "int";
      else
         type = "float";

      msg("~[060"+pad(line,long,0)+"~[010"+pad(type,8,0)+"~CDEF"+data[line],long+8);
   }

   if (sizeof(map)) {
      buf = "~CTITMappings (output supressed):~[060\n";
      long = width / 5;
      map = sort_array(map,#'>);
      foreach( line : map )
         if (sizeof(line) > long)
             long = sizeof(line) + 2;
      cols = width / long;
      for (x = 0; x < sizeof(map); x++) {
         buf += pad(map[x],long,0);
         if (x%cols == cols)
            buf += "\n";
      }
      msg(buf+"~CDEF");
   }

   if (sizeof(zeros)) {
      buf = "~CTITUnset (zero) Variables:~[060\n";
      long = width / 5;
      zeros = sort_array(zeros,#'>);
      foreach( line : zeros )
         if (sizeof(line) > long)
             long = sizeof(line) + 2;
      cols = width / long;
      for (x = 0; x < sizeof(zeros); x++) {
         buf += pad(zeros[x],long,0);
         if (x%cols == cols)
            buf += "\n";
      }
      msg(buf+"~CDEF");
   }

   return 1;
}
