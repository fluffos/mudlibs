/**
 * Keep track of all the fairy godmothers.  Make sure they don't do any
 * thing naughty.  This also controls the costs for the godmother
 * service.
 * @author Pinkfish
 */
#include <panic.h>
#include <config.h>

#define HARRY_SHADOW "/std/shadows/misc/harry_shadow"

object* _panicers;
object* _godmothers;
object* _queue;

#define FREE_NAME "free trip"
#define THRESHOLD 50
#define DAY (60*60*24)

/* Prototypes */

void continue_panicing(string str, object panicer);
private object startup_godmother(object ob);

/* Functions */

void create() {
  _panicers = ({ });
  _godmothers = allocate(NUM_GODMOTHERS);
  _queue = ({ });
} /* setup() */

/**
 * Return an array of all the godmothers.  This is the current set of
 * used godmothers.
 * @return an array of objects of godmothers
 */
object *query_godmothers() { return copy(_godmothers); }

/**
 * Check to see if there are any free godmothers.  Are you being
 * served?
 * @return 1 if there is a free one, 0 if there is not
 */
int free_godmothers() {
  int i;

  for (i=0;i<sizeof(_godmothers);i++) {
    if (!_godmothers[i]) {
      return 1;
    }
  }
  return 0;
} /* free_godmothers() */

/**
 * This method handles a player panicing.
 * <p>
 * This is the fairy godmother controller for panicing.
 * <p>
 * When someone panics it calls on this object to help fix them
 * up.
 * @param panicer the person panicing
 * @return 0 if they were unmable to panic, 1 if they were
 */
int do_startup(object panicer) {
  int j;

  if (environment(panicer) &&
      environment(panicer)->query_property("no godmother")) {
    notify_fail(environment(panicer)->query_property("no godmother"));
    return 0;
  }

  if (panicer->query_property("attacked godmother") &&
      (panicer->query_property("attacked godmother")+DAY*10) > time()) {
    notify_fail("You attacked a godmother!  No help for you!\n");
    return 0;
  }

  if (sizeof(panicer->query_attacker_list())) {
    notify_fail("You cannot use a godmother whilst you are in a fight.\n");
    return 0;
  }

  panicer->remove_property("attacked godmother");

  for (j = 0; j < sizeof(_panicers); j++) {
    if (!_panicers[j]) {
      _panicers = _panicers[0..j-1]+_panicers[j+1..];
      j--;
    } else if (_panicers[j] == panicer) {
      notify_fail("You are already requesting assistance.  Be patient.\n");
      return 0;
    }
  }
    
/*  
  if (!free_godmothers()) {
    notify_fail("Too many people are requesting help from the godmothers "
          "for you to be dealt with.  Try "
          "again in a few minutes.\n");
    if (!_queue) {
      int i;
      int waiting;
      int max_wait;

      _queue = 1;
    }
    return 0;
  }
 */
  if (!panicer) {
    panicer = this_player();
  }
  if (panicer->query_level() < 10 ||
      !arrayp(environment(panicer)->query_exits()) ||
      !sizeof(environment(panicer)->query_exits()) ||
      !environment(panicer)) {
    write("You feel help is on its way.\n");
    panicer->add_property("godmother", FREE_NAME);
    continue_panicing("y", panicer);
  } else {
    panicer->remove_property("godmother");
    if (panicer->query_level() < 50) {
      int max_gp;

      max_gp = panicer->query_max_gp();
      if (panicer->query_gp() < max_gp/3) {
        notify_fail("You do not have enough guild points to summon "
                    "a godmother.  You need at least "+(max_gp/3)+".\n");
        return 0;
      }
      write("This will cost you all of your current guild points and "
            "social points, and leave you feeling a little weak.  "
            "Do you wish to continue? ");
      input_to("continue_panicing", 0, panicer);
    } else {
      if (panicer->query_max_deaths() <= panicer->query_deaths()) {
        notify_fail("You do not have a life to spend on a godmother.\n");
        return 0;
      }
      write("This will cost you a life, do you wish to continue? ");
      input_to("continue_panicing", 0, panicer);
    }
  }
  return 1;
} /* do_startup() */

/** @ignore yes */
private void do_check_queue() {
   _queue -= ({ 0 });
   if (sizeof(_queue)) {
      if (startup_godmother(_queue[0])) {
         _queue = _queue[1..];
      }
   }
} /* do_check_queue() */

/** @ignore yes */
private void setup_harrass_callout() {
  int i;
  int check_queue;
  int waiting;
  int max_wait;

  for (i=0;i<sizeof(_godmothers);i++) {
    if (_godmothers[i]) {
      waiting = _godmothers[i]->query_waiting();
      if (waiting > FIRST_WAIT_TIME && environment(_godmothers[i])) {
        _godmothers[i]->hurry_up();
      }
      if (!environment(_godmothers[i])) {
         _godmothers[i]->dest_me();
         check_queue = 1;
      }
      if (waiting > max_wait) {
        max_wait = waiting;
      }
    }
  }
  if (max_wait < FIRST_WAIT_TIME) {
    call_out("do_hurry_up", FIRST_WAIT_TIME-max_wait+2);
  }
  if (check_queue) {
    do_check_queue();
  }
} /* setup_harrass_callout() */

/** @ignore yes */
void continue_panicing(string str, object panicer) {

  str = lower_case(str);
  if (!str || str == "" || (str[0] != 'y' && str[0] != 'n')) {
    if (panicer->query_level() < 100) {
      write("This will cost you all of your current guild points and "
            "social points and leave you feeling a little weak.  "
            "Do you wish to continue? ");
      input_to("continue_panicing", 0, panicer);
      return ;
    } else {
      write("This will cost you a life, do you wish to continue? ");
      input_to("continue_panicing", 0, panicer);
      return ;
    }
  }

  if (str[0] == 'n') {
    write("Ok.  They do not show up to help you.  Good luck.\n");
    return ;
  }

  if (!startup_godmother(panicer)) {
    write("You hope a godmother will turn up sometime soon.\n");
    _queue += ({ panicer });
    setup_harrass_callout();
  }
} /* startup_godmother() */

private object startup_godmother(object ob) {
  object godmother;
  int i;

  /* Which fairy godmother do you get? */
  /* Only done 2 so far... */
  i = random(NUM_GODMOTHERS);
  if (_godmothers[i]) {
     int num;

     do {
        num++;
        i = (i + 1) % NUM_GODMOTHERS;
     } while (_godmothers[i] && num < NUM_GODMOTHERS);
  }

  if (!_godmothers[i]) {
    switch (i) {
    case 0 :
       godmother = clone_object(GODMOTHER_DIR+"granny");
       break;
    case 1 :
       godmother = clone_object(GODMOTHER_DIR+"magrat");
       break;
    }
    _godmothers[i] = godmother;
    godmother->move(environment(ob));
    godmother->do_panic(ob);
    _panicers += ({ ob });
    return godmother;
  }
  return 0;
} /* continue_panicing() */

/**
 * Called by the godmother when the person has completed their
 * paniced transaction.
 * @param person the person who paniced
 * @param ok did they complete it ok?
 */
void finish_panic(object person, int ok) {
  int i;

  if (member_array(person, _panicers) == -1) {
    write("Consistancy error, they never paniced.\n");
    return ;
  }
  _panicers -= ({ person });
  if (ok) {
    if (person->query_property("godmother") == FREE_NAME) {
    } else if (person->query_level() < THRESHOLD) {
      person->adjust_tmp_con(-2);
      person->set_gp(0);
      person->set_social_points(0);
    } else if (person->query_level() >= THRESHOLD &&
        person->query_max_deaths() > person->query_deaths()) {
      person->adjust_max_deaths(-1);
    }
    person->remove_property("godmother");
    call_out( function (object person) {
      person->move_with_look(CONFIG_START_LOCATION, "$N appears out of nowhere.",
                             "$N disappears with a pop.");
                 if ( person->query_ghost() ) {
                   person->remove_ghost();
                   clone_object( HARRY_SHADOW )->setup_shadow( person,
                        "a fairy godmother" );
                 }
              }, 2, person);
  }
  for (i=0;i<sizeof(_godmothers);i++)  {
    if (_godmothers[i] == previous_object()) {
      _godmothers[i]->move("/room/rubbish");
      _godmothers[i] = 0;
    }
  }

  do_check_queue();

  if (!sizeof(_queue)) {
     remove_call_out("do_hurry_up");
  }
} /* finish_panic() */

/**
 * Give the players a nudge if they are taking to long.
 */
void do_hurry_up() {
  int i;
  int waiting;
  int max_wait;

  if (!sizeof(_queue)) {
    return ;
  }

  for (i=0;i<sizeof(_godmothers);i++) {
    if (_godmothers[i]) {
      if (!environment(_godmothers[i])) {
        _godmothers[i]->dest_me();
        _godmothers[i] = 0;
      } else {
        waiting = _godmothers[i]->query_waiting();
        if (waiting > FIRST_WAIT_TIME) {
          if (waiting > FINISH_WAIT_TIME) {
            _godmothers[i]->finish_up();
          } else {
            _godmothers[i]->hurry_up();
          }
        }
        if (waiting > max_wait) {
          max_wait = waiting;
        }
      }
    }
  }
  if (max_wait > 0) {
    if (FINISH_WAIT_TIME - max_wait < 10) {
      call_out("do_hurry_up", 10);
    } else {
      call_out("do_hurry_up", FINISH_WAIT_TIME-max_wait);
    }
  }
} /* do_hurry_up() */

/** @ignore yes */
void dest_me() {
  int i;

  for (i=0;i<sizeof(_godmothers);i++) {
    if (_godmothers[i]) {
      _godmothers[i]->dest_me();
    }
  }
  destruct(this_object());
} /* dest_me() */
