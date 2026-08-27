//  -*- LPC -*-
// security.c:  Security related simul-efuns
//
// Copyright (C) 1996 Tim McIntosh (tmcintos@dm.imaginary.com)
//
// This program is part of the OpenLib Mudlib distribution; it
// is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published
// by the Free Software Foundation; either version 2 of the License,
// or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// If you acquired this program as part of the OpenLib Mudlib
// distribution, you should have received a copy of the GNU
// General Public License in the file /doc/GPL; if not,
// write to the Free Software Foundation, Inc., 675 Mass Ave,
// Cambridge, MA 02139, USA.
//
#include <daemons.h>
#include <security.h>

// The unguarded function: evaluate 'code' at privilege level 'priv'

varargs mixed
unguarded(function code, mixed priv)
{
  return SECURITY_D->eval_unguarded(code, priv);
}

// Return a priv as a printable string

string
sprint_priv(mixed priv)
{
  if( stringp(priv) )
    return priv;
  else
    return sprintf("%i", priv);
}

// Useful for checking everything in the call stack to make sure the
// operation has priv=='priv' level access

int
check_priv(mixed priv)
{
  return SECURITY_D->check_privilege(priv, 1);
  // first object on stack will be simul_efun (security_d is taken off always)
}

// Useful when you know this_object() is secure..checks everything else

int
check_previous_priv(mixed priv)
{
  return SECURITY_D->check_privilege(priv, 2);
  // first object on stack will be simul_efun (security_d is taken off always)
}

// Get the privs of an object (returns 1,0 or a string)

mixed
query_privs(object ob)
{
  mixed priv = restore_variable(efun::query_privs(ob));

  return priv;
}

// Set privs of an object; HANDLE WITH CARE!!  Right now only priv==1 objects
// can use this

int
set_privs(object ob, mixed priv)
{
  if( !check_previous_priv(1) ) return 0;

  efun::set_privs(ob, save_variable(priv));
  return 1;
}

// Does an admin with username 'a' exist?

int
admin_exists(string a)
{
  if(!a) return 0;
  return SECURITY_D->member_domain(ADMIN_DOMAIN, a);
}

// Does a wizard with username 'w' exist?

int
wizard_exists(string w)
{
  if(!w) return 0;
  return SECURITY_D->wizard_exists(w);
}

// Does a domain with name 'd' exist?

int
domain_exists(string d)
{
  if(!d) return 0;
  return SECURITY_D->domain_exists(d);
}

// Is the username 'name' a member of 'domain'?

int
member_domain(string name, string domain)
{
  return SECURITY_D->member_domain(domain, name);
}

// Is the username 'name' an administrator of 'domain'?

int
admin_domain(string name, string domain)
{
  return SECURITY_D->admin_domain(domain, name);
}

/*
 * Functions for checking status of objects
 *
 * Some of these exist right now for compatibility with foreign code and
 * should eventually be removed.
 *
 */

int
visitorp(object ob)
{
  return 0;
}

// Is 'ob' a wizard?

int
wizardp(object ob)
{
  /* 
   * This code should really probably look like this:
   *
   * mixed priv = query_privs(ob);
   *
   * if( !living(ob) )
   *   return 0;
   *
   * if( stringp(priv) && SECURITY_D->wizard_exists(priv) )
   *   return 1;
   * else if( intp(priv) && priv == 1 )
   *   return 1;
   * else
   *   return 0;
   *
   * --Tim
   */
  string name = ob->query_name();  // this is probably insecure...

  if( name )
    return SECURITY_D->wizard_exists(name);
  else
    return 0;
}

// is 'ob' an administrator of the mud?

int
adminp(object ob)
{
  /*
   * Note:  see wizardp() above for how this should probably look
   */
  string name = ob->query_name();  // this is probably insecure...

  if( name )
    return SECURITY_D->member_domain(ADMIN_DOMAIN, name);
  else
    return 0;
}

// This is tagged for removal as it is currently meaningless.
// An Arch could possibly be defined as a _member_ of the domain "Admin"
// and true Admins could be defined as _administrators_ of the domain "Admin"
// --Tim

int
archp(object ob)
{
  return 1;
}
