/*
 * /kernel/simul/security.c
 *
 * This file contains the simul_efuns concerning the security system
 */

#include "/sys/kernel.h"

int check_previous_privilege(mixed priv) {
  return SECURITY->check_privilege(priv,2);
}

mixed get_privilege(object ob) {
  return (function_exists("query_privilege",ob)==ACCESS &&
          ob->query_privilege());
}

