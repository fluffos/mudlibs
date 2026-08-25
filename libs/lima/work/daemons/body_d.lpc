/* Do not remove the headers from this file! see /USAGE for more info. */

// body_d.c - Daemon for providing limbs to ADVERSARY objects.
//   Iizuka@Lima Bean: Feb. 9, 1997
//   Badly extended, 2019, 2020. <Tsath>

#include <limbs.h>

inherit M_DAEMON_DATA;
inherit CLASS_LIMB;

private
mapping body_types = ([]);

mapping get_body(string type)
{
   if (!undefinedp(body_types[type]))
      return copy(body_types[type]);
   else
      return ([]);
}

mapping get_body_size(string type)
{
   mapping body = get_body(type);
   mapping sizes = ([]);
   foreach (string limb, class limb l in body)
   {
      if (l.max_health > 0)
         sizes[limb] = l.max_health;
   }
   return sizes;
}

int body_exist(string type)
{
   return !undefinedp(body_types[type]) ? 1 : 0;
}

void add_body(string body_name, mapping body_limbs)
{
   if (body_name && body_limbs)
      body_types[body_name] = body_limbs;
   save_me();
}

string *list_body_types()
{
   return keys(body_types);
}

void add_limb_to_body(string bname, string limb, int new_health, int new_max, string new_parent, int new_flags)
{
   if (member_array(bname, keys(body_types)) < 0)
   {
      write("Bad body name!\n");
      return;
   }

   body_types[bname][limb] = new (class limb, health
                                  : new_health, max_health
                                  : new_max, parent
                                  : new_parent, flags
                                  : new_flags);
   save_me();
}

void remove_limb_from_body(string body_name, string limb_name)
{
   map_delete(body_types[body_name], limb_name);
   save_me();
}

void remove_body(string body_name)
{
   map_delete(body_types, body_name);
   save_me();
}
