#include <grammar.h>
#include <event.h>
#include <describe.h>
#include <kernel.h>
#include <server.h>
#include <message.h>

#define FAIL(who,mess) return (with_player((who),#'notify_fail,(mess)))

inherit "basic/create";

// Ugh Jul-5-1995
void
create() {
  set_global_listening_event("open",  1);
  set_global_listening_event("close", 1);
  set_global_listening_event("lock",  1);
  set_global_listening_event("unlock",1);
  listen_event("open");
  listen_event("close");
  listen_event("lock");
  listen_event("unlock");
}

status
do_action (string verb, mapping args) {
  mapping event;
  object key;
  event = ([
             E_AGENT  : this_player()       ; this_player()->query_name(),
             E_TARGET : args[G_INDIRECT]    ; args[G_INDIRECT,1],
             E_ID     : args[G_INDIRECT,1]  ; 0,
             E_SUCCESS: 1                   ; 0,  // be optimistic first
          ]);
  switch (verb) {
    case "unlock":
    case "lock":
    case "open":
    case "close":
      if (key = args[G_OBJECT]) {
        if (member((all_environment(key) || ({ })), this_player()) < 0) {
            notify_fail("You don't have "+
                        describe(key == environment(this_player()) ? 
                                 args[G_OBJECT,1] : key, ARTICLE_THE) + ".\n");
            return 0;
        }
        if (environment(key) != this_player() &&  // Coogan, 20-Mar-98
            !environment(key)->id("keyring"))     // Coogan, 06-Jul-99
          return
            notify_fail(({({ M_WRITE, "You don't have ", M_THE,
                             M_SIMPLE_DESCRIBE, M_OBJECT, key,
                             " at hand!" })})), 0;
        event[E_KEY] = key;
      }
      break;
#if 0 // obsolete by Ugh Mar-31-98
    case "open_handleless":
      verb = "open";
      break;
    case "close_handleless":
      verb = "close";
      break;
    case "unlock_keyless":
      verb = "unlock";
      break;
    case "lock_keyless":
      verb = "lock";
      break;
#endif
    default:
      return 0;
  }
  send_event(verb,event,environment(this_player()));
  return event[E_SUCCESS];
}

void
receive_event(mapping event, string type, int prio) {
  object who, what, key;
  if (event[E_HANDLED])  // Alfe 95-Jun-20
    return;
  event[E_HANDLED]=1;  // we will handle it now  Alfe 95-Jun-20
  who  = event[E_AGENT];
  what = event[E_TARGET];
  key  = event[E_KEY];
  if (!(event[E_SUCCESS] = what->apply_action(type, 0, event)))
    switch (type) {
      case "open":
        if (event[E_TARGET]->query_open())
          break;
      case "close":
        if (type == "close" && !event[E_TARGET]->query_open())
          break;
        if (who)
          FAIL(who, break_string("You can't " + type + " " +
               (describe((what == environment(who)
                          ? event[E_ID] || event[E_TARGET,1] : what),
                         ARTICLE_THE) ||
               what->query_objective() || "it") + ".\n", 78));
        break;
    case "lock":
      if (event[E_TARGET]->query_lock())
        break;
    case "unlock":
      if (type == "unlock" && !event[E_TARGET]->query_lock())
        break;
      if (who) {
        if (key)
          FAIL(who,
               break_string("You can't " + type + " " +
                            (describe((what == environment(who)
                                       ? event[E_ID] || event[E_TARGET,1]
                                       : what),
                                       ARTICLE_THE) ||
                            what->query_objective() || "it") + " with " +
                            (describe((key == environment(who)
                                       ? event[E_ID] || event[E_TARGET,1]
                                       : key),
                                       ARTICLE_THE) || "that") + ".\n",78));
        else 
          FAIL(who,
               break_string("You can't " + type + " " +
                 (describe((what == environment(who)
                            ? event[E_ID] || event[E_TARGET,1] : what),
                           ARTICLE_THE)||
                  what->query_objective() || "it") +
                 " without a key.\n", 78));
      }
      break;
    default: return;
    }
  if (event[E_SUCCESS] && mappingp(event[E_SUCCESS,1]))
    send_event(event[E_SUCCESS,1][E_TYPE], event[E_SUCCESS,1],
               ({ environment(event[E_SUCCESS,1][E_AGENT]) }));
}

