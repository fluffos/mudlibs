/*
 * /basic/fakeitem.c
 *
 * It's a fake item!
 */

#include <grammar.h>

virtual inherit "basic/synonym";

private mapping descriptions;
  /* since the description is a function of the name of the fakeitem, let's
     do it just so ... with a function, erm .. I mean .. a mapping */

/*
 * add_item ()
 * add one description for one or more ids
 */
void add_item(mixed name, mixed description) {
  if (pointerp(description))
    description = lambda(0,({ (#'capitalize),
                              ({ (#'message2string),
                                 quote(description) }) }));
  if (pointerp(name))
    map(name, #'add_item, description);
  else if (stringp(name))
    descriptions = (descriptions||([])) + 
                   ([lower_case(name):description]);
}

/*
 * remove_item ()
 * remove one or more fakeitems
 */
void remove_item(string name) {
  if (pointerp (name))
    map(name, #'remove_item);
  else if (descriptions) 
    m_delete(descriptions, lower_case(name));
}

/*
 * set_one_item_description ()
 * does the same as add_item () (see above)
 */
void set_one_item_description(mixed name, mixed description) {
  add_item(name, description);
}

/*
 * set_item_descriptions ()
 * set the descriptions for a list of items
 */
#if 0 // for ease of use with persistence
void set_item_descriptions(mixed *names, mixed *descs) {
    int i;
    descriptions = 0;
    for (i = 0; i < sizeof (names); i++)
        add_item(names[i], descs[i]);
}
#else
varargs void set_item_descriptions(mixed *names, mixed *descs) {
    int i;
    mixed h;
    descriptions = 0;
    if (!descs) {
      h = names;
      names = h[0];
      descs = h[1];
    }
    for (i = 0; i < sizeof (names); i++)
        add_item(names[i], descs[i]);
}
#endif

/*
 * set_items ()
 * the same as set_item_descriptions, with the difference, that
 * items and descriptions are intermingled in one flat array
 */
void set_items(mixed *items) {
  int i;
  descriptions = 0;
  for (i = 0; i < sizeof(items); i+=2)
    add_item(items[i],items[i+1]);  
}

/*
 * query_fakeitem_long ()
 * returns the description for a fakeitem, if there is one
 */
mixed query_fakeitem_long(string name) {
  return descriptions && name &&
         funcall(descriptions[get_synonym(lower_case(name))]);
}

mixed long(string name) {
  return query_fakeitem_long(name);
}

/*
 * query_items ()
 * gives back an array whose first item is a list of the fakeitems
 * and whose second item is a list of the corresponding descriptions
 * to those fakeitems
 */
mixed *query_items() {
  string *names;
  return (!descriptions ? ({ 0, 0 }) : 
          ({ m_indices(descriptions), 
             map (m_values(descriptions), #'funcall) }));
}

/*
 * query_fakeitem_id ()
 * will return 1 if it is called with a name of a fakeitem 
 */
status query_fakeitem_id(string name) {
  return descriptions && name &&
         (member(m_indices(descriptions),
                 get_synonym(lower_case(name))) > -1);
}

/*
 * query_id() will return all the fakeitem-ids in as array
 */
string *query_id() {
  return descriptions && m_indices(descriptions);
}

status id(string name) {
  return query_fakeitem_id(name);
}

/* this is only a short time in here (hopefully) */
mixed query_long(string str) {
  return query_fakeitem_long(str);
}

#if 1
private mapping action_items; // action_id -> item -> result
private mixed *action_rules;  // ([rules],[[action_ids]])

void add_item_action(mixed item, mixed rules, string action_id, mixed result) {
  int i, j;

  if (!pointerp(item))
    item = ({item});
  if (!pointerp(rules))
    rules = ({rules});
  if (!action_items)
    action_items = ([]);
  if (!member(action_items,action_id))
    action_items[action_id] = ([]);
  if (!action_rules)
    action_rules = ({({}),({})});
  if (!result)
    return;
  for (i = sizeof(item); i-->0; )
    action_items[action_id][item[i]] = result;
  for (i = sizeof(rules); i>0; i--)
    if ((j = member(action_rules[0],rules[<i])) >= 0)
      action_rules[1][j] += ({action_id});
    else {
      action_rules[0] += ({rules[<i]});
      action_rules[1] += ({({action_id})});
    }
  update_actions();
}

void add_item_actions(mixed *actions) {
  filter(actions, lambda(({'r}),({#'apply,#'add_item_action,'r})));
}

void add_item_action_error_message(string verb, mixed mess) {
  add_action_error_message(verb,mess);
}

private status do_item_action(string rule, mapping args) {
  int i, j;
  mixed result;
  string name;

  if (!action_rules || (i = member(action_rules[0],rule)) < 0)
    return 0;
  name = args[G_FAKEITEM] == this_object() && get_synonym(args[G_FAKEITEM,1]);
  if (!name)
    return 0;
  for (j = sizeof(action_rules[1][i]); j>0; j--) {
    result = action_items[action_rules[1][i][<j]];
    if (!result)
      continue;
    result = result[name];
    if (closurep(result))
      result = funcall(result,args);
    if (!result)
      continue;
    if (pointerp(result) || stringp(result))
      message(result);
    return 1;
  }
  return 0;
}

private void add_item_action_rules() {
  int i;

  if (action_rules) {
    for (i = sizeof(action_rules[0]); i>0; i--) 
      add_action_rule(action_rules[0][<i],action_rules[0][<i],#'do_item_action);
  }
}

void init() {
  add_item_action_rules();
}
#endif

