#pragma strong_types

#include <grammar.h>
#include <describe.h>
#include <event.h>
#include <message.h>
#include <combat.h>

#ifndef G_HAND
#define G_HAND "<hand>"
#endif
#ifndef G_HAND2
#define G_HAND2 "<hand2>"
#endif

inherit "basic/create";

status send_unwear_event(object *armours,object player) {
  mapping e;
  send_event("unwear",e=([ E_AGENT: player,
                           E_TARGET: armours,
                           E_MESSAGES: ([ 0 : 
                               ({ M_ARG,E_AGENT,M_VERB,"remove",M_ARG,E_AGENT,
                                  M_POSSESSIVE,M_ARG,E_AGENT,
                                  M_OBJECT,M_NONE,M_ARG,E_TARGET,"." }) ]) ]),
             environment(player));
  return e[E_SUCCESS];
}

status send_unwield_event(object *armours,object player) {
  mapping e;
  send_event("unwield",e=([ E_AGENT: player,
                            E_WEAPON: armours,
                            E_MESSAGES: ([ 0 :
                              ({M_ARG,E_AGENT,M_VERB,"let",M_ARG,E_AGENT,
                                " go of ",M_POSSESSIVE,M_ARG,E_AGENT,
                                M_OBJECT,M_NONE,M_ARG,E_WEAPON,"."}) ]) ]),
             environment(player));
  return e[E_SUCCESS];
}

private void receive_other_event(mapping e) {
  mixed h;
  object *weapons,*armours;
  h=filter(e[E_TARGET],#'present,e[E_AGENT]);
  weapons=filter(h,"query_wielded",e[E_AGENT]);
  armours=filter(h,"query_worn",e[E_AGENT]);
  if (sizeof(weapons))
    send_unwield_event(weapons,e[E_AGENT]);
  if (sizeof(armours))
    send_unwear_event(armours,e[E_AGENT]);
  weapons=filter(h,"query_wielded",e[E_AGENT]);
  armours=filter(h,"query_worn",e[E_AGENT]);
  e[E_TARGET]-=weapons;
  e[E_TARGET]-=armours;
}

private void receive_move_event(mapping e, string t, int p) {
  int i;
  mixed h;
  switch (p) {
  case 500:
    if (!e[E_FROM])
      return;
    if (h = environment(e[E_AGENT])->query_blocked(e[E_DIR],e[E_AGENT])) {
      h = filter_objects(h, "test_sight", 0, 1);  // added silently arg,
                                                  // Coogan, 18-Dec-00
      if (random(e[E_AGENT]->query_dex()) < 
          random(fold_left(#'+,map_objects(h,"query_dex")))) {
        send_message(({h,M_VERB,"block",h,M_S,e[E_AGENT]," way ",
                       e[E_DIR],"."}));
        cancel_event();
      }
      else {
        send_message(({h,M_VERB,"try",h," to ","block ",M_S,e[E_AGENT],
                       " way, but ",M_SUBJECT,e[E_AGENT],M_PRONOUN,e[E_AGENT],
                       M_VERB,"slip",e[E_AGENT]," out of ",
                       M_POSSESSIVE,h," grasp."}));
      }
    }
    break;
  }
}

void create() {
  listen_event("wield",0);
  listen_event("unwield",0);
  listen_event("wear",0);
  listen_event("unwear",0);
  set_global_listening_event("wield",1);
  set_global_listening_event("unwield",1);
  set_global_listening_event("wear",1);
  set_global_listening_event("unwear",1);
  // the following are for the prevention of dropping, giving ... of worn
  // or wielded items
  listen_event("drop",500,#'receive_other_event);
  listen_event("give",500,#'receive_other_event);
  listen_event("put",500,#'receive_other_event);
  listen_event("take",500,#'receive_other_event);
  set_global_listening_event("drop",1);
  set_global_listening_event("give",1);
  set_global_listening_event("put",1);
  set_global_listening_event("take",1);

  listen_event("move",500,#'receive_move_event);
  set_global_listening_event("move",1);
}

void notify_destruct() {  // Coogan, 28-01-2000
  unlisten_event("wield",0);
  unlisten_event("unwield",0);
  unlisten_event("wear",0);
  unlisten_event("unwear",0);
  set_global_listening_event("wield",0);
  set_global_listening_event("unwield",0);
  set_global_listening_event("wear",0);
  set_global_listening_event("unwear",0);
  unlisten_event("drop",500,#'receive_other_event);
  unlisten_event("give",500,#'receive_other_event);
  unlisten_event("put",500,#'receive_other_event);
  unlisten_event("take",500,#'receive_other_event);
  set_global_listening_event("drop",0);
  set_global_listening_event("give",0);
  set_global_listening_event("put",0);
  set_global_listening_event("take",0);
  unlisten_event("move",500,#'receive_move_event);
  set_global_listening_event("move",0);
}

int do_action(string action,mapping args) {
  mixed h;
  object ob, *not_weapon, *not_armour;
  mixed temp, temp2, msg;
  int i;
  mapping armour,e;
  object body;

  msg=({});
  switch (action) {
  case "wear":
    h = args[G_ALL];
    not_armour=h-filter(h,#'present,this_player());
    h-=not_armour;
    if (sizeof(not_armour=filter_objects(not_armour,"short")))
      msg+=({ ({ M_WRITE,M_PL,M_PL_VERB,"are"," not carrying ",M_THE,
                 M_OBJECT,not_armour,"." }) });
    not_armour=h-filter_objects(h,"query_property",P_WEARABLE);
    h-=not_armour;
    if (sizeof(not_armour=filter_objects(not_armour,"short")))
      msg+=({ ({ M_WRITE,M_THE,not_armour,M_VERB,"cannot",not_armour,
                 " be worn." }) });
    not_armour=filter(h,"query_worn",this_player());
    h-=not_armour;
    if (sizeof(not_armour=filter_objects(not_armour,"short")))
      msg+=({ ({ M_WRITE,M_PL,M_PL_VERB,"are"," already wearing ",
                 M_THE,M_OBJECT,not_armour,"." }) });
    if (args[G_ALL,1][1])
      h = h[0..args[G_ALL,1][1]-1];
    if (!sizeof(h))
      return notify_fail(msg), 0;
    send_event("wear",e=([ E_AGENT: this_player(),
                           E_TARGET: h,
                           E_BODY: this_player()->query_body(),
                           E_MESSAGES: ([ 0 : 
                             ({ M_ARG,E_AGENT,M_VERB,"wear",M_ARG,E_AGENT,
                                M_POSSESSIVE,M_ARG,E_AGENT,
                                M_OBJECT,M_NONE,M_ARG,E_TARGET,"." }) ]) ]),
               environment(this_player()));
    return e[E_SUCCESS];
  case "unwear":
    h = args[G_ALL];
    not_armour=h-filter_objects(h,"query_worn",this_player());
    h-=not_armour;
    if (sizeof(not_armour=filter_objects(not_armour,"short")))
      msg+=({ ({ M_WRITE,M_PL,M_PL_VERB,"are"," not wearing ",
                 M_THE,M_OBJECT,not_armour,
                 "." }) });
    if (args[G_ALL,1][1])
      h = h[0..args[G_ALL,1][1]-1];
    if (!sizeof(h))
      return notify_fail(msg), 0;
    return send_unwear_event(h,this_player());
  case "wield":
    return 0;
    h = args[G_ALL] || ({ args[G_OBJECT] });
    not_weapon=h-filter(h,#'present,this_player());
    h-=not_weapon;
    if (sizeof(not_weapon=filter_objects(not_weapon,"short")))
      msg+=({ ({ M_WRITE,M_PL,M_PL_VERB,"are"," not carrying ",M_THE,
                 M_OBJECT,not_weapon,"." }) });
    not_weapon=h-filter_objects(h,"query_property",P_WIELDABLE);
    h-=not_weapon;
    if (sizeof(not_weapon=filter_objects(not_weapon,"short")))
      msg+=({ ({ M_WRITE,M_THE,not_weapon,M_VERB,"cannot",not_weapon,
                 " be wielded." }) });
    if (args[G_ALL] && args[G_ALL,1][1])
      h = h[0..args[G_ALL,1][1]-1];
    if (!sizeof(h))
      return notify_fail(msg), 0;
    body = this_player()->query_body();
    if (ob=args[G_OBJECT]) {
      if (args[G_WORD]) {
        if (member(body->query_hands(), args[G_WORD]+" hand") < 0)
          return notify_fail("You don't have a "+args[G_WORD]+" hand.\n"), 0;
        else
          args += ([ G_HAND : body; args[G_WORD]+" hand" ]);
      }
      else if (args[G_HAND] &&
               (args[G_HAND] != body ||
                member(body->query_hands(), args[G_HAND,1]) < 0))
        return notify_fail("You cannot wield it there.\n"), 0;
      if (args[G_HAND2] &&
          (args[G_HAND2] != body ||
           member(body->query_hands(), args[G_HAND2,1]) < 0))
        return notify_fail("You cannot wield it there.\n"), 0;
      if (args[G_HAND2] && ob->query_property(P_WIELDABLE) < 2)
        return notify_fail("You can only wield it in one hand.\n"), 0;
      if (args[G_HAND2] && args[G_HAND,1]==args[G_HAND2,1])
        return notify_fail("Please give different hands if you want to wield"
                           " it in two hands.\n"), 0;
    }
    send_event("wield",e=([ E_AGENT: this_player(),
                            E_WEAPON: h,
                            E_WHERE: (args[G_HAND2]?
                                      ({ args[G_HAND,1],args[G_HAND2,1] }) :
                                      args[G_HAND] && ({ args[G_HAND,1] })),
                            E_MESSAGES: ([ 0 : 
                              ({M_ARG,E_AGENT,M_VERB,"wield",M_ARG,E_AGENT,
                                M_POSSESSIVE,M_ARG,E_AGENT,
                                M_OBJECT,M_NONE,M_ARG,E_WEAPON,
                                " in ",M_POSSESSIVE,M_ARG,E_AGENT,
                                M_NONE,M_ARG,E_WHERE,"."}) ]) ]),
               environment(this_player()));
    return e[E_SUCCESS];
  case "unwield":
    return 0;
    h = args[G_ALL];
    not_weapon=h-filter(h,"query_wielded",this_player());
    h-=not_weapon;
    if (sizeof(not_weapon=filter_objects(not_weapon,"short")))
      msg+=({ ({ M_WRITE,M_PL,M_PL_VERB,"are"," not wielding ",
                 M_THE,M_OBJECT,not_weapon,"." }) });
    if (args[G_ALL,1][1])
      h = h[0..args[G_ALL,1][1]-1];
    if (!sizeof(h))
      return notify_fail(msg), 0;
    return send_unwield_event(h,this_player());
  case "attack":
    if (member(args[G_ALL_LIVINGS],this_player()) >= 0) {
      args[G_ALL_LIVINGS] -= ({ this_player() });
      if (!sizeof(args[G_ALL_LIVINGS]))
        return notify_fail(({ ({ M_WRITE,"Attack ",M_SUBJECT,M_PL,M_OBJECT,
                                 M_PL,"? No way!" }) })), 0;
    }
    h = filter(args[G_ALL_LIVINGS],"query_fighting",this_player());
    if (sizeof(h) == sizeof(args[G_ALL_LIVINGS]))
      return notify_fail("Yes, yes.\n"), 0;
    else
      args[G_ALL_LIVINGS] -= h;
    if (args[G_ALL_LIVINGS,1][1])
      args[G_ALL_LIVINGS] = args[G_ALL_LIVINGS][0..args[G_ALL_LIVINGS,1][1]-1];
    send_event("start_fight",
               ([ E_AGENT : this_player(),
                  E_TARGET : args[G_ALL_LIVINGS],
                  E_MESSAGES : ([ 0 : 
                                  ({ M_ARG,E_AGENT,M_VERB,"turn",
                                     M_ARG,E_AGENT," to attack ",
                                     M_OBJECT,M_ARG,E_TARGET,"!" }) ]) ]),
               environment(this_player()));
    return 1;
  case "stop_fight":
    if (args[G_ALL_LIVINGS]) {
      args[G_ALL_LIVINGS] = 
        filter(args[G_ALL_LIVINGS],"query_fighting",this_player());
      if (args[G_ALL_LIVINGS,1][1])
        args[G_ALL_LIVINGS] =
          args[G_ALL_LIVINGS][0..args[G_ALL_LIVINGS,1][1]-1];
    } else if (h = this_player()->query_fighting()) {
      args[G_ALL_LIVINGS] = m_indices(h);
    } 
    if (!sizeof(args[G_ALL_LIVINGS]))
      return 0;
    send_event("stop_fight",
               ([ E_AGENT : this_player(),
                  E_TARGET : args[G_ALL_LIVINGS],
                  E_MESSAGES : ([ 0 : 
                                  ({ M_ARG,E_AGENT,M_VERB,"stop",
                                     M_ARG,E_AGENT," fighting ",
                                     M_OBJECT,M_ARG,E_TARGET,"." }) ]) ]),
               environment(this_player()));
    return 1;
  case "join":
    if (member(args[G_ALL_LIVINGS],this_player()) >= 0) {
      args[G_ALL_LIVINGS] -= ({ this_player() });
      if (!sizeof(args[G_ALL_LIVINGS]))
        return notify_fail(({ ({ M_WRITE,"You can't join ",
                                 M_SUBJECT,M_PL,M_OBJECT,
                                 M_PL,"." }) })), 0;
    }
    h = filter(args[G_ALL_LIVINGS],"query_fighting",this_player());
    // do we want to join our enemies?
    if (sizeof(h)) {
      args[G_ALL_LIVINGS] -= h;
      if (!sizeof(args[G_ALL_LIVINGS]))
        return notify_fail(({ ({ M_WRITE,"Join ",
                                 M_SUBJECT,M_PL,M_OBJECT,h,"? No, ",
                                 M_SUBJECT,h,h,M_VERB,"are",h," your ",
                                 M_DESCRIBE_GROUP,"enemy",h,"." }) })), 0;
    }
    // collect all objects that are fought with
    h = args[G_ALL_LIVINGS] - 
        filter_objects(args[G_ALL_LIVINGS],"query_fighting");
    if (sizeof(h)) {
      args[G_ALL_LIVINGS] -= h;
      if (!sizeof(args[G_ALL_LIVINGS]))
        return notify_fail(({ ({ M_WRITE,"But ",h,M_VERB,"are",h,
                                 " not fighting anybody." }) })), 0;
    }
    h = map_objects(args[G_ALL_LIVINGS],"query_fighting");
    args[G_ALL_LIVINGS] = m_indices(fold_left(#'+,h,([])));
    h = filter(args[G_ALL_LIVINGS],"query_fighting",this_player());
    if (sizeof(h) == sizeof(args[G_ALL_LIVINGS]))
      return notify_fail("Yes, yes.\n"), 0;
    else
      args[G_ALL_LIVINGS] -= h;
    if (args[G_ALL_LIVINGS,1][1])
      args[G_ALL_LIVINGS] = args[G_ALL_LIVINGS][0..args[G_ALL_LIVINGS,1][1]-1];
    send_event("start_fight",
               ([ E_AGENT : this_player(),
                  E_TARGET : args[G_ALL_LIVINGS],
                  E_MESSAGES : ([ 0 : 
                                  ({ M_ARG,E_AGENT,M_VERB,"turn",
                                     M_ARG,E_AGENT," to attack ",
                                     M_OBJECT,M_ARG,E_TARGET,"!" }) ]) ]),
               environment(this_player()));
    return 1;
  case "stop_hunting":
    if (this_player()->query_hunting()) {
      this_player()->stop_hunting();
      return 1;
    } else {
      return notify_fail("You are not hunting anyone.\n"), 0;
    }
    break;
  case "block":
    environment(this_player())->set_blocking(this_player(),args[G_EXIT]);
    h = environment(this_player())->query_blocking(this_player());
    if (h)
      write("You are now blocking the exit "+h+".\n");
    else
      return notify_fail("That doesn't seem to work here.\n"), 0;
    return 1;
    break;
  case "stop_block":
    h = environment(this_player())->query_blocking(this_player());
    if (h && (!args[G_EXIT] || args[G_EXIT] == h))
    {
      environment(this_player())->set_blocking(this_player(),0);
      write("You stop blocking the exit "+h+".\n");
      return 1;
    }
    else if (args[G_EXIT])
      return notify_fail("But you are not blocking the exit "+args[G_EXIT]+
                         "!\n"), 0;
    else 
      return notify_fail("But you are not blocking any exit!\n"), 0;
    break;
  case "follow":
    if (this_player()->query_following(args[G_LIVING]))
      return notify_fail("But you are already following "+
                         describe(args[G_LIVING],ARTICLE_THE)+".\n"), 0;
    if (this_player() == args[G_LIVING])
      return notify_fail("You can't follow yourself.\n"), 0;
    this_player()->set_following(args[G_LIVING]);
    send_message(({M_WRITE,M_PL,M_PL_VERB,"start"," to follow ",M_OBJECT,M_THE,
                   args[G_LIVING],"."}));
    return 1;
  case "stop_follow":
    h = args[G_LIVING]||args[G_ANY_LIVING];
    if (h) {
      if (this_player()->query_following(h)) {
        this_player()->stop_following(h);
        send_message(({M_WRITE,M_PL,M_PL_VERB,"stop"," following ",
                       M_OBJECT,M_THE,h,"."}));
      } else {
        return notify_fail("You are not following that.\n"), 0;
      }
    } else if (h = this_player()->query_following()) {
      this_player()->stop_following();
      send_message(({M_WRITE,M_PL,M_PL_VERB,"stop"," following ",
                     M_OBJECT,M_THE,m_indices(h),"."}));
    } else {
      return notify_fail("You are not following anything.\n"), 0;
    }
    return 1;
  case "list_followed":
    h = this_player()->query_following();
    send_message(({"You are following ",
                   (sizeof(h) ? m_indices(h) : "nobody"),"."}));
    return 1;
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 24-Mar-2011
}

private string fail_wield(object weapon,object agent,string where) {
  mixed h;
  if (h=agent->query_wielded(weapon))
    return "already_wielded";
  else if (sizeof(h=agent->query_weapons(where)))
    return "hand_occupied";
  else
    return "no_working_hands";
}

void receive_event(mapping e,string t,int p) {
  mixed h,g;
  int i;
  mixed msg;

  if (e[E_HANDLED])
    return;
  e[E_HANDLED] = 1;
  msg=({});
  switch (t) {
  case "wear":
    h = sort_objects(e[E_TARGET],"query_layer",#'>);
    for (i=sizeof(h); i; i--)
      if (!h[<i]->wear_clothing(e[E_BODY]))
        e[E_TARGET] -= ({ h[<i] });
    if (!sizeof(e[E_TARGET])) {
      msg = ({ M_TARGETS,e[E_AGENT],"you couldn't wear ",M_ARTICLE,
               "your",h,"." });
      if (e[E_AGENT] == this_player())
        notify_fail(({ msg }));
      else
        send_message(msg);
    }
    else {
      e[E_SUCCESS] = 1;
      map_messages(e[E_MESSAGES],e);
    }
    break;
  case "unwear":
    h = sort_objects(e[E_TARGET],"query_layer",#'<);
    for (i=sizeof(h); i; i--)
      if (!h[<i]->unwear_clothing())
        e[E_TARGET] -= ({ h[<1] });
    if (!sizeof(e[E_TARGET])) {
      msg = ({ M_TARGETS,e[E_AGENT],"you couldn't remove ",M_ARTICLE,
               "your",h,"." });
      if (e[E_AGENT] == this_player())
        notify_fail(({ msg }));
      else
        send_message(msg);
    }
    else {
      e[E_SUCCESS] = 1;
      map_messages(e[E_MESSAGES],e);
    }
    break;
  case "wield":
    h = e[E_WEAPON]-filter(e[E_WEAPON],"wield_weapon",e[E_AGENT],
                                 e[E_WHERE]);
    if (sizeof(h)) {
      e[E_WEAPON] -= h;
      h = factorize(h,#'fail_wield,({ e[E_AGENT],e[E_WHERE] }));
      if (sizeof(h["already_wielded"]))
        msg += ({ ({ M_TARGETS,e[E_AGENT],
                     "but you already wield ",M_THE,h["already_wielded"],
                     "." }) });
      if (sizeof(h["hand_occupied"])) {
        g = e[E_AGENT]->query_wielded(e[E_AGENT]->query_weapons(e[E_WHERE]));
        msg += ({ ({ M_TARGETS,e[E_AGENT],
                     M_ARTICLE,"your",g,M_VERB,"are",g,
                     " already occupied, so you cannot wield ",
                     M_ARTICLE,"your",h["hand_occupied"],"." }) });
      }
      if (sizeof(h["no_working_hands"]))
        msg += ({ ({ M_TARGETS,e[E_AGENT],
                     "but you do not have any working hands to wield ",
                     M_THE,h["no_working_hands"]," in." }) });
    }
    if (sizeof(e[E_WEAPON])) {
      e[E_WHERE] = e[E_AGENT]->query_wielded(e[E_WEAPON]);
      e[E_SUCCESS] = 1;
      map_messages(e[E_MESSAGES],e);
    }
    else
      if (e[E_AGENT]==this_player())
        notify_fail(msg);
      else
        message(msg);
    break;
  case "unwield":
    map(e[E_WEAPON],"remove_weapon",e[E_AGENT]);
    e[E_SUCCESS] = 1;
    with_player(e[E_AGENT],#'map_messages,({ e[E_MESSAGES],e }));
    break;
  }
}
