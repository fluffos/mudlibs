#include <daemons.h>

inherit DAEMON;

#define COLUMNS 4
int cmd_heartbeats()
{
    string *outp=({}), real_output;
    mixed out2;
    string s=0;
    string col;
    object *ob;
    int i;
    int at_column;
    if(s && s != "") { 
      write("Object Name");
      write("---------------------");
      i = sizeof( ob = objects() );
      out2=({});
      while(i--)
      {
          if (query_heart_beat(ob[i])) {
            out2 += ({ file_name(ob[i]) });
          }
      }
      this_player()->more(implode(out2, "\n"));
      return 1;
    }
    write("Object Name");
    write("---------------------");
    i = sizeof( ob = objects() );

    while(i--)
    {

        if (query_heart_beat(ob[i])) 
        {
            if (ob[i]->is_player())
                outp += ({ "%^RED%^%^BOLD%^"+ob[i]->query_name()+"%^RESET%^" });

            else if (ob[i]->is_monster())
                outp += ({ "%^BLUE%^%^BOLD%^"+ob[i]->query_name()+"%^RESET%^" });
            else outp += ({ ob[i]->query_name() });
        }
    }
    outp = outp;
    real_output = "";
    out2="";
    at_column = 0;
    i = sizeof(outp);
    while(i--)
    {
        real_output += arrange_string(outp[i], 20); at_column++;
        if (at_column >= 4) { out2+=real_output+"\n"; at_column=0;real_output=""; 
        }
    }

    this_player()->more(explode(out2, "\n"));
    return 1;
}

