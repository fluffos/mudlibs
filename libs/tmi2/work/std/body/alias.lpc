// alias.c
// storage and retrieval of aliases
// Author: Wayfarer (Some of my code may still exist here. :))
// Zak found a couple of bugs which were screwing up global aliases for
// people who didn't have any personal ones set. Mobydick installed his
// patches on 2-26-93
// Inspiral reported a bug with xverbs.  Guile fixed this but on 7-20-93
// and removed a few unnecessary if() statements while at it.

#include <uid.h>
#include <daemons.h>
#include <commands.h>


mapping alias;
mapping xverb;

void add_alias(string verb, string cmd);

mapping query_nalias()
{
   if(alias)
      return alias + ([]);
   else 
      return ([]);
}

mapping query_xalias()
{
   if(xverb)
      return xverb + ([]);
   else 
      return ([]);
}
mapping query_aliases ()
{ 
  if (!alias)
    alias = ([]);
  if (!xverb)
    xverb = ([]);
  return alias + xverb; 
}

string query_alias (string str)
{
  string ret;
  if (!alias)
    alias = ([]);
  ret = alias[str];
  if (!ret)
    {
      if (!xverb)
	xverb = ([]);
      ret = xverb[str];
    }
  return ret;
}

// this should have been here so buddha added it.
void clear_aliases() { 
  if(geteuid(previous_object()) != ROOT_UID && file_name(previous_object())
    != CMD_ALIAS)
      return;
  alias = ([ ]);
  xverb = ([ ]);
}
  
void add_alias (string verb, string cmd)
{
  if(geteuid(previous_object()) != ROOT_UID && file_name(previous_object())
    != CMD_ALIAS)
      return;
  if (verb[0] == '$' && strlen(verb) > 1)
    {
      if(!xverb)
         xverb = ([]);
      verb = verb[1 .. strlen(verb) - 1];
      if(xverb[verb])
         xverb[verb] = cmd;
      xverb += ([ verb : cmd ]);
   }
  else 
    if (alias[verb])
      alias[verb] = cmd;
    else
      alias += ([ verb : cmd ]);
}

void remove_alias (string verb)
{
  if (alias[verb])
     map_delete(alias,verb);
  else
    if (xverb[verb])
      map_delete(xverb,verb);
}

string
replace_words (string orig, string *words)
{
  string ret, tmp;
  string *parts;
  int i, num;

  parts = explode (orig+"$","$");
  // if(!parts)
  // return orig;
  // Commented out by Guile - This never happens, unless orig is not a
  // string, and we'd have an error anyways for bad type to +
  ret = orig;
  for (i = 0; i < sizeof(parts); i++)
    {
      if (parts[i][0] == '*')
	ret = replace_string(orig,"$*",implode(words," "));
      else 
	{
	  if (sscanf(parts[i],"%d%*s",num) == 0)
	    if (sscanf(parts[i],"%d",num) == 0)
	      continue;
	  if (num > 0 && num <= sizeof(words))
	    {
	      tmp = sprintf ("$%d",num);
	      ret = replace_string(ret,tmp,words[num-1]);
	    }
	}
    }
  return ret;
}


nomask string do_xverb (string str)
{
  string *xv, ret, tmp, *words;
  int i, lenxv;
  mapping tmpxv;

  if (!xverb)
     xverb = ([ ]) ;
   tmpxv = (mapping)GA_SERVER_D->query_global_xaliases() + xverb ;
  xv = keys (tmpxv);
  for (i = 0; i < sizeof(xv); i++)
  {
     lenxv = strlen(xv[i]);
     if(str[0 .. lenxv - 1] == xv[i])
     {
 //        if(strlen(str) > 1)
 //           str = str[1 .. strlen(str) - 1];
           if(strlen(str) > lenxv)
               str = str[lenxv..strlen(str)-1];
        else str = "";
         words = explode(str+" "," ");
        // if(!words)
        // words = ({ str });
        // Commented out by Guile - Why this check again? 
         ret = replace_words(tmpxv[xv[i]],words);
        return ret;
     }
  }
  return 0;
}

nomask string do_alias (string str)
{
  string *words, tmp, ret;
  
  if (!str || str == "")
    return "";
  tmp = do_xverb(str);
  if (tmp)
    return tmp;
  if (!alias)
     alias = ([ ]) ;
  tmp = str;
  words = explode(str+" "," ");
  if (!words || sizeof(words) == 0)
    words = ({tmp});
  if(!(tmp = alias[words[0]]))
    tmp = (mixed)GA_SERVER_D->do_global_alias(words[0]);
  if(tmp)
    {
      ret = replace_words(tmp,words[1..(sizeof(words)+1)]);
      return ret;
    }
  return implode (words," ");
}
