/*
// Don't know who did this file.  Probably Wayfarer.
// (92-12-06) Pallando added 3 lines of code to do_nicknames()
*/
mapping nicknames;

string do_nicknames(string str)
{
   int i;
   string *words;
   string ret;

   if(!str)
      return "";

   if(!nicknames)
      return str;

   if (str[0..7] == "nickname")
        return str;

   words = explode(str," ");

   for(i = 1; i < sizeof(words); i++)
   {
      ret = words[i];
      if(ret != "\\" && ret[0] == '\\')
         words[i] = ret[1..strlen(ret)];
      else
         if(nicknames[words[i]])
            words[i] = nicknames[words[i]];
      else
         if(words[i] == "##")
            words[i] = call_other( this_object(), "query", "cwf" );
// Previous 3 lines added by Pallando (92-12-06) for editing defaults
   }
   
   ret = implode(words, " ");

   return ret;
}

void remove_nickname(string nm)
{
    if (!nicknames)
         return;
    map_delete(nicknames,nm);
}

void set_nicknames(string nm, string rnm)
{
   if(!nicknames)
      nicknames = ([]);

   nicknames[nm] = rnm;
}

mapping query_nicknames()
{
   if (!nicknames) {
      return ([]);
   }
   return nicknames;
}

mixed query_nickname(mixed nick)
{
   return nicknames[nick];
}

void empty_nicknames()
{
	nicknames = ([]);
}
