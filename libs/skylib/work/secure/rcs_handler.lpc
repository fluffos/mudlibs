
#define SAVE_FILE "/secure/rcs_handler.o"

mapping _locks = ([]);

void create()  {
   unguarded((: restore_object, SAVE_FILE :));
}

void add_lock(mixed cre, string file)  {
   string name;
   if( file[0] != '/' )
      file = "/" + file;

   if (stringp(cre))  name = lower_case(cre);
   else name = cre->query_name();
   if (undefinedp(_locks[name]))
      _locks[name] = ({ file });
   else if ( member_array( file, _locks[name] ) < 0 )
      _locks[name] += ({ file });
   unguarded((: save_object, SAVE_FILE :));

   return;
}


void remove_lock(mixed cre, string file)  {
   string name;
   if( file[0] != '/' )
      file = "/" + file;

   if (stringp(cre))  name = lower_case(cre);
   else name = cre->query_name();
   if (!undefinedp(_locks[name]))  {
      _locks[name] -= ({ file });
      unguarded((: save_object, SAVE_FILE :));
   }

   return;
}
/**
 * Return a mapping of non-creators who have files locked and which files
 * those people have locked.
 */
mapping query_non_creators() {
  mapping res;
  string person;

  res = ([ ]);
  foreach(person in keys(_locks)) {
    if( !creatorp(person) )
       res[person] = _locks[person];
  }
  return res;
}

string *query_locks(mixed cre)  {
   string name;

   if (stringp(cre))  name = lower_case(cre);
   else name = cre->query_name();
   return _locks[name];
}
