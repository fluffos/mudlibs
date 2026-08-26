// This is the global alias server from Portals.
// euid setting added by Pallando
// Grendel added wizard-only aliases, about 7-5-93.

#define GLOBAL_ALIASES "adm/etc/global_aliases"

mapping galias;
mapping wgalias;
mapping xgalias;
mapping wxgalias;

void create()
{
   int i;
   string *line;
   string alias,expansion;

   seteuid(getuid());

   line = explode(read_file(GLOBAL_ALIASES),"\n");

   galias = ([ ]);
   xgalias = ([ ]);
   wgalias = ([ ]);
   wxgalias = ([ ]);

   for(i = 0; i < sizeof(line); i++)
   {
      if(line[i] == "" || line[i][0] == '#')
         continue;
      if(sscanf(line[i],"%s %s",alias,expansion) != 2)
      {
         write("Error parsing "+GLOBAL_ALIASES+" for global aliases.\n");
         return;
      }

      if(strlen(alias) > 1 && alias[0] == '>')
      {
	  alias=alias[1..strlen(alias)-1];
	  if(strlen(alias) > 1 && alias[0] == '$')
	     wxgalias += ([ alias[1..strlen(alias)-1] : expansion ]);
	  else
	     wgalias += ([ alias : expansion ]);
      }
      else
      {
	  if(strlen(alias) > 1 && alias[0] == '$')
	     xgalias += ([ alias[1..strlen(alias)-1] : expansion ]);
	  else
	     galias += ([ alias : expansion ]);
      }
   }
}

mixed do_global_alias(string str)
{
   if(wizardp(this_player()) && !undefinedp(wgalias[str]))
	return(wgalias[str]);
   return galias[str];
}

mapping query_global_aliases()
{ return wizardp(this_player()) ? wgalias + galias + ([]) : galias + ([]); }
mapping query_global_xaliases()
{ return wizardp(this_player()) ? wxgalias + xgalias + ([]) : xgalias + ([]); }
