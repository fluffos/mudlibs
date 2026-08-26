/**
 * This is the include file to deal with the nomic system for the
 * player council.
 * @author Pinkfish
 * @started Fri Jun 23 20:10:40 PDT 2000
 */
#ifndef __NOMIC_SYSTEM__
/** @ignore yes */
#define __NOMIC_SYSTEM__


/**
 * This is the class to handle ammendments to the rule
 * @member ammender the person doing the ammendments
 * @member text the text of the ammendment
 * @member date_ammended when it was ammended
 */
class nomic_ammendment {
   string ammender;
   string text;
   int date_ammended;
}

/**
 * The information on nomic rules.
 * @member id the id of the rule (unique)
 * @member date_create when the rule was created
 * @member creator who created the rule
 * @member text the text of the rule
 * @member ammendments the ammendments to the rule
 */
class nomic_rule {
   int id;
   int date_created;
   string creator;
   string text;
   class nomic_ammendment* ammendments;
}

/**
 * The information needed for each nomic area.
 * @member new_type_num the next numbers to use in each type area
 * @member rules the rules for the area
 */
class nomic_area {
   int* new_type_num;
   class nomic_rule* rules;
}

/**
 * This method sets up a new nomic rule for someone to vote on.
 * @member type the type of the new rule
 * @member rule the new rule (or ammended rule)
 * @member new_rule_type if the rule typ eis to change types, this is the new
 * type
 * @member comments any comments associated with the rule
 * @member yes_votes the current set of yes votes
 * @member no_votes the current set of no votes
 * @member voted the current bunch of people that have voted
 * @member state the state of the current rule
 * @member date_added the date this new rule discussion was added
 * @member date_event the date of the last state change event
 */
class new_nomic_rule {
   int type;
   class nomic_rule rule;
   int new_rule_type;
   string* comments;
   int yes_votes;
   int no_votes;
   string* voted;
   int state;
   int date_added;
   int date_event;
}

/**
 * This is the default set of types for the nomic system.
 */
#define NOMIC_DEFAULT_TYPE_NUMS ({ 100, 300, 2000 })

/**
 * The immutable rule type.  Effects everyone.
 */
#define NOMIC_TYPE_IMMUTABLE 0
/**
 * The general rule type.  Effects everyone.
 */
#define NOMIC_TYPE_GENERAL   1
/**
 * The citizen rule type.  Only effects citizens.
 */
#define NOMIC_TYPE_CITIZEN   2

/**
 * The error define for nomic functions.
 */
#define NOMIC_ERROR -1

/**
 * This sets up the type of the new rule to be a real new rule.
 */
#define NOMIC_TYPE_RULE_ADD     1
/**
 * This changes the text of the rule.  Ammends it.
 */
#define NOMIC_TYPE_RULE_AMMEND  2
/**
 * This moves the rule type from one rule set to another.
 */
#define NOMIC_TYPE_RULE_MOVE    3

/**
 * This is the state for when it is being looked at by the council.
 */
#define NOMIC_STATE_COUNCIL_REVIEW 1
/**
 * This is the state for when it is being voted on by the council.
 */
#define NOMIC_STATE_COUNCIL_VOTE   2
/**
 * This is the state for when it is being voted on by the citizens.
 */
#define NOMIC_STATE_CITIZEN_VOTE   3

#endif
