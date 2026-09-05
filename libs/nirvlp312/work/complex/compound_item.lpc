/****************************************************************************
  compound_item.c -- a simple item enhanced by compound/component-complexity
                written by Ugh, May-98, for Tubmud
****************************************************************************/
inherit "basic/compound_component"; // Ugh May-14-98
inherit "complex/item";

void init() {
  compound_component::init();
}

public int id(string str) {
  return compound_component::id(str) || item::id(str);
}

status get(string str) {  // Alfe 15-Mar-1995
  return item::get(str) && compound_component::get(str);
}

varargs status add_inventory(object ob, string which, string preposition) {
  return
    compound_component::add_inventory(ob,which,preposition) ||
    item::add_inventory(ob,which,preposition);
}

object *get_inventory(string str, string preposition) {
  return
    compound_component::get_inventory(str,preposition) ||
    item::get_inventory(str,preposition);
}

string long(string str) {
  return
    compound_component::long(str) ||
    item::long(str);
}

varargs string query_name(string str) {
  return
    compound_component::query_name(str) ||
    item::query_name();
}

varargs int query_gender(string str) {
  return
    compound_component::query_gender(str) ||
    item::query_gender(str);
}

varargs mixed query_property(string prop, string str) {
  return
    compound_component::query_property(prop,str) ||
    item::query_property(prop,str);
}

varargs int query_encumbrance(string str) {
  if (str)
    return
      compound_component::query_encumbrance(str) ||
      item::query_encumbrance();
  else
    return
      compound_component::query_encumbrance() +
      item::query_encumbrance();
}

varargs int query_value(string str) {
  if (str)
    return
      compound_component::query_value(str) ||
      item::query_value();
  else
    return
      compound_component::query_value() +
      item::query_value();
}
