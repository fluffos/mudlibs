#ifndef _VARCONST_H_
#define _VARCONST_H_

// desc
#define BGM(x) string query_default_bgm() { return x; }
#define NAME(x) string query_default_name() { return x; }
#define LOOK(x) string query_default_look() { return x; }
#define LONG(x) string query_default_long() { return x; }
#define SHORT(x) string query_default_short() { return x; }
#define DISTANT(x) string query_default_distant() { return x; }
#define SPECIFIC(x) string query_default_specific() { return x; }
#define TASTE(x) string query_default_taste() { return x; }
#define PLURAL(x) string query_default_plural() { return x; }
#define UNIT(x) string query_default_unit() { return x; }
#define UNITS(x) string query_default_units() { return x; }
#define ALT_PLURAL(x) string *query_default_alt_plural() { return x; }
#define TYPE(x) string query_type() { return x; }
#define ALT_NAME(x) string *query_default_alt_name() { return x; }
// condition
#define CONDITION(x) int query_default_max_condition() { return x; }
#define DEST_ON_BREAK(x) int query_default_dest_on_break() { return x; }
#define UNBREAKABLE(x) int query_default_unbreakable() { return x; }
// decay
#define PERISHABLE(x) int query_perishable() { QBODY("perishable", x) }
// item...
#define WEIGHT(x) int query_default_weight() { return x; }
#define BULK(x) int query_default_bulk() { return x; }
#define VALUE(x) int query_default_value() { return x; }
#define DROPPABLE(x) int query_default_droppable() { return x; }
#define GETTABLE(x) int query_default_gettable() { return x; }
#define HOLDABLE(x) int query_default_holdable() { return x; }
// apparel
#define FLEXIBLE(x) int query_default_flexible() { return x; }
#define SIZE(x) int query_default_size() { return x; }
#define BODY_PARTS(x) int query_default_body_parts() { return x; }
// weapon
#define WEAPON_TYPE(x) string query_default_weapon_type() { return x; }
// room
#define CAN_BUILD(x) int query_default_can_build() { return x; }
// scenery
#define PHRASE(x) string query_default_phrase() { return x; }
#define ASPECT(x) mapping query_default_aspects() { return x; }
// food
#define FOOD_VALUE(x) int query_default_food_value() { return x; }
#define DRINK_VALUE(x) int query_default_drink_value() { return x; }
#define FOOD_BUFF(x) mapping query_default_buff() { return x; }
#define FOOD_BUFF_TIME(x) int query_default_buff_time() { return x; }
// critters
#define FACTION(x) string query_default_faction() { return x; }

#endif
