//:COMMAND
// Removes the objects that would be returned from objfind
// See: objfind
// Remove instances of the given class
// Created by Deathblade on 07-Nov-1994
// Modified from objfind.c by someone at sometime
#include <mudlib.h>

inherit CMD;

private object * get_obs(string arg)
{
   return filter_array(objects(), (: base_name($1) == $(arg) :) );
}

private void main(string arg)
{
   object * obs;

   if (!wizardp(this_body()))
   {
      out("This command is for wizard use only.\n");
      return;
   }

   if (!check_privilege(1) && (SECURE_D->query_is_wizard(this_body()->query_userid()) < 3))
   {
      out("Only Wizard Masters and Teachers can use objpurge.\n");
      return;
   }

   obs = get_obs(arg);
   outf("Removing %d objects of class %s\n", sizeof(obs), arg);
   obs->remove();

   obs = filter_array(obs, (: $1 :)); // remove zeros
   outf("Destructing %d objects of class %s\n", sizeof(obs), arg);
   map_array(obs, (: destruct :));
}