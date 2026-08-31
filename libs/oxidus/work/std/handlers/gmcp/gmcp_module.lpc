// /std/ext/gmcp/gmcp_module.c
//
// Created:     2024/02/23: Gesslar
// Last Change: 2024/02/23: Gesslar
//
// 2024/02/23: Gesslar - Created

#include <gmcp_defines.h>

inherit STD_DAEMON;

private nosave mapping cooldowns = ([]);
protected nosave mapping cooldown_limits = ([]);

int cooldown_check(string cooldown, object prev) {
  int limit = cooldown_limits[cooldown];
  int now = time();
  int next;
  string cooldown_label = query_privs(prev);

  if(!limit)
    return 1;

  if(!cooldowns[cooldown])
    cooldowns[cooldown] = ([]);

  next = cooldowns[cooldown][cooldown_label];
  if(next && next > now)
    return 0;

  return 1;
}

void apply_cooldown(string cooldown, object prev) {
  int limit = cooldown_limits[cooldown];
  int now = time();
  string cooldown_label = query_privs(prev);

  if(!limit)
    return;

  if(!cooldowns[cooldown])
    cooldowns[cooldown] = ([]);

  cooldowns[cooldown][cooldown_label] = now + limit;
}

mapping query_cooldowns() {
  return copy(cooldowns);
}

int query_gmcp_module() {
  return 1;
}
