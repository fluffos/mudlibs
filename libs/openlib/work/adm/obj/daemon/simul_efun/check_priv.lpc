/*  -*- LPC -*-  */
#include <daemons.h>

mixed
t_unguarded(mixed priv, function code)
{
  return SECURITY_D->eval_unguarded(priv, code);
}

int
check_priv(mixed priv)
{
  return SECURITY_D->check_privilege(priv, 1);
  // first object on stack will be simul_efun (security_d is taken off always)
}

int
check_previous_priv(mixed priv)
{
  return SECURITY_D->check_privilege(priv, 2);
  // first object on stack will be simul_efun (security_d is taken off always)
}

mixed
query_privs(object ob)
{
  mixed priv = restore_variable(efun::query_privs(ob));

  return priv;
}

int
set_privs(object ob, mixed priv)
{
//  if( !check_previous_priv(1) ) return 0;

  efun::set_privs(ob, save_variable(priv));
  return 1;
}
