/*
 * a simple party server
 *
 * written by Coogan, 19-Apr-99
 * Note: Do not update/destruct this object while there are parties in the
 *       game!
 *
 */

#pragma strong_types

#include <kernel.h>
#include <event.h>
#include <message.h>
#include <global_commands.h>  // added global_, Coogan, 02-May-01

inherit ACCESS;
inherit "basic/create";

private mapping parties;

void create() {
  set_global_listening_event("logout", 1);
  listen_event("logout", EPRIO_HANDLE);
}

void notify_destruct() {
  object *m;
  set_global_listening_event("logout", 0);
  unlisten_event("logout", EPRIO_HANDLE);
  if (sizeof(parties)) {
    m = flatten_array(m_values(parties, 0));
    send_message(({ M_TARGETS, m, "ATTENTION: The party server was "
                    "destructed. All parties are removed!" }));
  }
}

object* query_party_members(object leader) {
  if (!member(parties || ([ ]), leader))
    return 0;
  return parties[leader] - ({ 0 });
}

varargs object query_party_leader(object o) {
  object *n;
  if (!o)
    o = this_player() || this_interactive();
  if (!o)
    return 0;
  n = m_indices(filter(parties || ([ ]),
                       lambda(({ 'leader, 'members, 'who }),
                              ({ #'>, ({ #'member, 'members, 'who }), -1 })),
                       o)) - ({ 0 });
  if (sizeof(n))
    return n[0];
}

varargs status query_is_party_leader(object o) {
  if (!o)
    o = this_player();
  return (o, member(parties || ([ ]), o));
}

// returns the leader name, if m is member of a party
varargs status query_is_party_member(object o) {
  if (!o)
    o = this_player();
  return !!query_party_leader(o);
}

status create_party() {
  if (!this_player())
    return 0;
  if (this_player() != this_interactive() ||
      load_name(previous_object()) != COMMANDS_MISC ||
      member(parties || ([ ]), this_player()))
    return 0;
  if (!parties)
    parties = ([ this_player() : ({ this_player() }) ]);
  else
    parties += ([ this_player() : ({ this_player() }) ]);
  return 1;
}

status add_to_party(object o) {
  if (!this_player() || !o)
    return 0;
  if (!query_is_party_leader())
    return 0;
  parties[this_player()] += ({ o });
  return 1;
}

status change_party_leader_to(object o) {
  object l;
  if (this_player() != this_interactive()      ||
      !parties                                 ||
      !query_is_party_leader(this_player())    ||
      !query_is_party_member(o)                ||
      member(parties[this_player()], o) == -1)
    return 0;
  parties += ([ o : query_party_members(this_player()) ]);
  parties -= ([ this_player() ]);
  return 1;
}

object leave_party(object o) {
  object nl, l, *m;
  nl = 0;
  m_delete(parties, 0);                      // Coogan, 15-Jan-2003
  if (query_is_party_leader(o)) {            // attention.
    m = query_party_members(o) - ({ o });
    if (!sizeof(m)) {                        // only the leader is member
      m_delete(parties, o);
    } else {
      nl = sort_objects(m, "query_level", #'>)[<1];  // new leader!
      parties += ([ nl : parties[o] ]);
      parties -= ([ o ]);
      parties[nl] -= ({ o });
    }
  } else {
    parties[query_party_leader(o)] -= ({ o });
  }
  return nl;
}

void receive_event(mapping e, string type, int prio) {
  object nl, *ol;
  if (prio != EPRIO_HANDLE ||
      type != "logout")
    return;
  if (query_is_party_member(e[E_AGENT])) {
    ol = query_party_members(query_party_leader(e[E_AGENT])) - ({ e[E_AGENT] });
    nl = leave_party(e[E_AGENT]);
    if (sizeof(ol))
      send_message(({ M_TARGETS, ol, M_THE, e[E_AGENT], " left the party." }));
    if (nl)
      send_message(({ M_TARGETS, ol, M_THE, nl, M_VERB, "are", nl,
                      " the new party leader!" }));
  }
}

mapping query_parties() {
  return parties || ([ ]);
}

void refresh() {                      // Coogan, 15-Jan-2003
  if (parties)
    m_delete(parties, 0);
}

