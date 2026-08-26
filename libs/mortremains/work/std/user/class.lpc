/*
** This holds all the various class related functions.
** Class and dual classes became enough of a pain to warrant
** this on 10 Aug 97 (Cyanide).
*/

#define DEBUG(x) tell_object(find_player("cyanide"), x)
#include <config.h>

varargs int query_level(string);
int find_class_in_link(string, mapping);

// Cyanide wrote this function originally 12 Mar 1997
// Included class/group level support 10 Aug 1997.

varargs int query_level(string klass) {
   object link;  
   int level, lvlold, flag;
   string *classarray, *CLASSarray;
   mapping classmap;

   link = TO->query_link();
   if (!link) return -1;

   if (!klass) {
      if (member_group(this_object()->query("name"), "root"))
         return ADMIN_LEVEL;
      else 
         if (member_group(this_object()->query("name"), "admin"))
            return ARCH_LEVEL;
            else
               if (link->query("wizard"))
                  return WIZARD_LEVEL;

      level = link->query("level");
      lvlold = link->query("level_old");
      if (!level) level = 0;
      if (lvlold) level+=lvlold;

      return level;
   } else {
      if (find_class_in_link(klass, link->query("Class_old")))
         level = link->query("level_old");
      else
         if (find_class_in_link(klass, link->query("Class")))
            level = link->query("level");
      return level;
   }
}


int find_class_in_link(string str, mapping klasses) {
   int i;
   string *klass, *CLASS;

   if (!klasses) return 0;

   CLASS = keys(klasses);
   klass = values(klasses);

   if (member_array(str, CLASS) != -1) return 1;
   if (member_array(str, klass) != -1) return 1;

   return 0;
}

   

// This function returns a mapping of a user's classes and levels.

mapping query_levels() {
   string Class, Classold;
   int lvl, lvlold;
   mapping levels;
   object link;

   link = this_object()->query_link();
   if (link) {
      lvl = link->query("level");
      lvlold = link->query("level_old");
      Class = values((mapping)link->query("Class"))[0];
      Classold = values((mapping)link->query("Class_old"))[0];

      if (!lvl||!Class) return 0;
      levels = ([ Class : lvl ]);

      if (lvlold) levels = ([ Classold : lvlold ]) + levels;

      return levels;
   }

   return ([ "peasant" : 0 ]);
}


// This function returns a mapping of a user's class groups and levels.

mapping query_levels2() {
   string Class, Classold;
   int lvl, lvlold;
   mapping levels;
   object link;

   link = this_object()->query_link();
   if (link) {
      lvl = link->query("level");
      lvlold = link->query("level_old");
      Class = keys((mapping)link->query("Class"))[0];
      Classold = keys((mapping)link->query("Class_old"))[0];

      if (!lvl||!Class) return 0;
      levels = ([ Class : lvl ]);

      if (lvlold) levels = ([ Classold : lvlold ]) + levels;

      return levels;
   }

   return ([ "peasant" : 0 ]);
}
                                                
