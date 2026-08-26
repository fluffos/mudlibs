/**
 * This handler deals with all the nomic rules for councils.
 * @author Pinkfish
 * @started Fri Jun 23 19:51:04 PDT 2000
 */
#include <nomic_system.h>

private mapping _rules;

void save_me();

void create() {
   _rules = ([ ]);
} /* create() */

/**
 * This method adds a nomic rule into the system.
 * @param area the area the rule is added in
 * @param type the type of rule to add
 * @param creator the person that created the rule
 * @param text the text associated with the rule
 * @return the new number of the rule, NOMIC_ERROR on fai;l
 */
int add_nomic_rule(string area, int type, string creator, string text) {
   int bing;
   class nomic_rule nomic_rule;

   if (!_rules[area]) {
      return NOMIC_ERROR;
   }
   if (type < 0 || type >= sizeof(_rules[area]->new_type_num)) {
      return NOMIC_ERROR;
   }
   nomic_rule = new(class nomic_rule);
   bing = _rules[area]->new_type_num[type];
   nomic_rule->id = bing;
   nomic_rule->creator = creator;
   nomic_rule->text = text;
   nomic_rule->date_created = time();
   _rules[area]->rules += ({ nomic_rule });
   _rules[area]->new_type_num[type] = bing + 1;
   save_me();
} /* add_nomic_rule() */

/**
 * This method removes a nomic rule from the system.
 * @param area the area the rule is removed in
 * @param id the id of the rule to remove
 * @return the status of the removal, NOMIC_ERROR on fai;l
 */
int remove_nomic_rule(string area, int id) {
   class nomic_rule nomic_rule;

   if (!_rules[area]) {
      return NOMIC_ERROR;
   }
   foreach (nomic_rule in _rules[area]->rules) {
      if (nomic_rule->id == id) {
         _rules[area]->rules -= ({ nomic_rule });
         save_me();
         return 1;
      }
   }
   return 0;
} /* remove_nomic_rule() */

/**
 * This method returns a nomic rule for the specified area.
 * @param area the area to get the rule in
 * @param id the id of the rule to match
 * @return 0 if failed, the class if succeeded
 */
class nomic_rule query_nomic_rule(string area, int id) {
   class nomic_rule nomic_rule;

   if (!_rules[area]) {
      return 0;
   }
   foreach (nomic_rule in _rules[area]->rules) {
      if (nomic_rule->id == id) {
         return copy(nomic_rule);
      }
   }
   return 0;
} /* query_nomic_rule() */

/**
 * This method returns all the nomic rules for the area.
 * @param area the area to get the rule sin
 * @return all the rules
 */
class nomic_rule* query_all_nomic_rules(string area) {
   if (!_rules[area]) {
      return ({ });
   }

   return copy(_rules[area]->rules);
} /* query_all_nomic_rules() */

/**
 * This method creates an new nomic area.
 * @param area the new nomic area name
 * @return 1 on success, 0 on failure
 */
int create_area(string area) {
   class nomic_area new_area;

   if (_rules[area]) {
       return 0;
   }

   new_area = new(class nomic_area);
   new_area->new_type_num = NOMIC_DEFAULT_TYPE_NUMS;
   new_area->rules = ({ });
   _rules[area] = new_area;
   return 1;
} /* create_area() */
