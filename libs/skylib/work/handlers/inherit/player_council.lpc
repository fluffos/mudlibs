/**
 * This handler is for the control of player houses.
 * @author Pinkfish
 * @started Fri Jun 23 22:50:02 PDT 2000
 */
#include <nomic_system.h>
inherit "/handlers/inherit/citizens";
inherit "/handlers/inherit/nomic_rules";

private mapping _new_rules;
private mapping _new_citizens;

void create() {
   _new_rules = ([ ]);
   _new_citizens = ([ ]);
   citizens::create();
   nomic_rules::create();
} /* create() */

/**
 * This method puts a new rule up for voting.  It is first placed into
 * the hands of the magistrates, then into the hands of the players.
 * @param area the area for the rule to be voted on in
 * @param type the type of the rules
 * @param text the text associated with the new rule
 * @return 1 on success, 0 on failure
 */
int add_new_rule_for_voting(string area, int type, string creator,
                            string text) {
   class new_nomic_rule fluff;

   if (!is_magistrate_of(area, creator)) {
      return 0;
   }
   fluff = new(class new_nomic_rule);
   fluff->type = NOMIC_TYPE_RULE_ADD;
   flkuff->rule = new(class nomic_rule);
   fluff->rule->creator = creator;
   fluff->rule->text = text;
   fluff->rule->type = type;
   fluff->comments = ({ });
   fluff->voted = ({ });
   fluff->state = NOMIC_STATE_COUNCIL_DISCUSS;
   fluff->date_added = time();
   fluff->date_event = time();
   fluff->yes_votes = 0;
   fluff->no_votes = 0;
   _new_rules[area] += ({ fluff });
   return 1;
} /* add_new_rule_for_voting() */

/**
 * This method puts up a request to move a rule from one type to another.
 * @param area the area to do the move in
 * @param rule_no the rule number to move
 * @param type the type to move the rule to
 * @param creator the creator of this request
 * @return 1 on success, 0 on failure
 */
int add_move_rule_type(string area, int rule_no, int type, string creator) {
   class new_nomic_rule fluff;
   class nomic_rule bing;

   bing = query_nomic_rule(area, rule_no);
   if (!bing) {
      return 0;
   }
   if (bing->type == type) {
      return 0;
   }
   fluff = new(class new_nomic_rule);
   fluff->type = NOMIC_TYPE_RULE_MOVE;
   fluff->rule = bing;
   fluff->new_rule_type = type;
   fluff->comments = ({ });
   fluff->voted = ({ });
   fluff->state = NOMIC_STATE_COUNCIL_DISCUSS;
   fluff->date_added = time();
   fluff->date_event = time();
   fluff->yes_votes = 0;
   fluff->no_votes = 0;
   _new_rules[area] += ({ fluff });
   return 1;
} /* add_move_rule_type() */

/**
 * This method adds in a request to ammend a rule.
 * @param area the area to put the ammendment in
 * @param rule_no the rule to ammend
 * @param ammendment the ammendment text
 * @param creator the person doing the ammendment
 */
int add_rule_ammendment(string area, int rule_no, string ammendement,
                        string creator) {
   class new_nomic_rule fluff;
   class nomic_rule bing;
   class nomic_ammendment ammend;

   bing = query_nomic_rule(area, rule_no);
   if (!bing) {
      return 0;
   }

   fluff = new(class new_nomic_rule);
   fluff->type = NOMIC_TYPE_RULE_AMMEND;
   fluff->rule = bing;
   fluff->comments = ({ });
   fluff->voted = ({ });
   fluff->state = NOMIC_STATE_COUNCIL_DISCUSS;
   fluff->date_added = time();
   fluff->date_event = time();
   fluff->yes_votes = 0;
   fluff->no_votes = 0;
   _new_rules[area] += ({ fluff });

} /* add_rule_ammendment() */
