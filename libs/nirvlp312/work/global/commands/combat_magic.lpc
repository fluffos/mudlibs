/*
 * global/commands/combat_magic
 *
 * This file is for wizards, testing the combat system. It is used
 * automatically, if a body is found in global/commands/magic.
 * If you change something of the event handling here (not combat related),
 * please keep in mind, that the functions *_spell() only overload the
 * functions of global/commands/magic, so that perhaps the event handling
 * has to be changed there too.
 *
 * Coogan, 14-Dec-98
 *
 */

#pragma strong_types

#include <server.h>
#include <combat.h>
#include <event.h>
#include <grammar.h>
#include <describe.h>

inherit "global/commands/magic";

// the next few functions are meant to coordinate the casting of spells
// with other actions (like the casting of other spells) of one 'actor'
private void run_spell(mapping spell, int call_id);
private void abort_spell(mapping spell, int call_id);
private status try_spell(mapping spell);


private void
run_spell(mapping spell, int call_id) {
  string *req, *sha;
  object body;
  send_event(E_MAGIC, spell);
  req = spell[C_RESOURCES];
  sha = spell[C_SHARED_RESOURCES];
  body = this_player()->query_body();
  if (sizeof(req) + sizeof(sha) && body)
    body->free_resources(req, sha, call_id);
  if (body && spell[C_FIGHTPLAN_KEY])
    body->schedule_next_action(spell);
}

private void
abort_spell(mapping spell, int call_id) {
  string *req, *sha;
  object body;
  SE_MAGIC->locate_spell(spell[E_SPELL])->abort_spell(spell);
  req = spell[C_RESOURCES];
  sha = spell[C_SHARED_RESOURCES];
  body = this_player()->query_body();
  if (sizeof(req)+sizeof(sha))
    body->free_resources(req, sha, call_id);
  if (body)
    this_player()->enqueue_action(lambda(0, ({ #'try_spell, spell })));
}

private status
try_spell(mapping spell) {
  string *req, *sha;
  object body;
  mixed h;
  h = SE_MAGIC->locate_spell(spell[E_SPELL]);

  body = this_player()->query_body();
  req = spell[C_RESOURCES] || ({ });
  sha = (body ? (body->query_used_resources()) - req : ({ }));
  if (!body && sizeof(req) + sizeof(sha)) // nowhere to require the resources
    return 0;
  if (!body->can_substitute_resources(&req, &sha))
    return 0;
  spell[C_RESOURCES] = req;
  spell[C_SHARED_RESOURCES] = sha;

  if (!h->init_spell(spell))
    return 0;
  spell[E_SUCCESS] = calculate_success(spell);

  h = COMBAT_SERVER->get_combat_coordinator(spell[E_AGENT])->
        schedule_call(spell[E_DELAY],
                      lambda(({ 'call }),
                             ({ #'run_spell, spell, 'call })),
                      lambda(({ 'call }),
                             ({ #'abort_spell, spell, 'call })));
  if (sizeof(req) + sizeof(sha))
    body->require_and_share_resources(req, sha, h);
  return 1;
}

//private // not private as long as still called from global/commands/magic
status cast_spell(mapping data) {
  object pl;
  mapping se;
  string spell;
  mixed tmp;
  int level, delay;
  string lore_path, art_path;

  switch (sizeof(tmp=SE_MAGIC->identify_spell(data[E_SPELL], data[E_AGENT]))) {
    case 0: return notify_fail("Cast which spell?\n",-1), 0;
    case 1: break;
    default:
      notify_fail("Which spell do you want to cast: " +
                  make_list(tmp, 0, " or ") + "?\n");
      return 0;
  }
  spell = tmp[0];
  if (!(se = SE_MAGIC->query_spell_event(spell)))
    return SE_MAGIC->magic_error("\""+spell+"\": Invalid spell!"), 0;
  se[E_SPELL]  = spell;

  se += ([ E_TYPE  : "magic";       0,
           E_AGENT : data[E_AGENT]; data[E_AGENT]->query_name(), ]);
  if (data[E_TARGET])
    se += ([ E_TARGET : data[E_TARGET];
                        describe(data[E_TARGET], ARTICLE_NONE) ]);
  if (data[E_COMPONENT])
    se += ([ E_COMPONENT : data[E_COMPONENT];
                           describe(data[E_COMPONENT], ARTICLE_NONE) ]);

  if (data[E_AGENT]->query_sp() < se[E_COST]) {
    notify_fail("You feel too exhausted to cast this spell.\n");
    return 0;
  }

  if (!SE_MAGIC->locate_spell(spell))
    return 0;

  lore_path = SE_MAGIC->query_magic_skill_path(se[E_LORE]);
  art_path  = SE_MAGIC->query_magic_skill_path(se[E_ART]);

  if (!se[E_AGENT]->query_skill(lore_path) ||
      !se[E_AGENT]->query_skill(art_path)  ||
      !se[E_AGENT]->query_spells(spell))
    return notify_fail("Cast which spell?\n"), 0;

  if (se[E_AGENT]->query_modified_skill(lore_path) < se[E_LORE,1] ||
      se[E_AGENT]->query_modified_skill(art_path)  < se[E_ART,1])
    return notify_fail("You are too unexperienced to cast this spell.\n"), 0;

  if (tmp = data[E_AGENT]->query_body()) // this is for spells from a fightplan
    tmp->add_fightplan_key(se);
  data[E_AGENT]->enqueue_action(lambda(0, ({ #'try_spell, se })));
  return 1;
}

