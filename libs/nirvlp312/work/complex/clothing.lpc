/*
 * /complex/clothing.c by Alfe & Ugh 97-May-28
 */

#include <prop/item.h>
#include <libs.h>
#include <message.h>
#include <combat.h>

inherit "basic/wearable";
inherit "complex/item";

private string type;
private int size;
private mapping rigid;

// sets the given bodypart (0 as bodypart means default for the whole body)
// to the given value; if value is negative, the specialisation for this
// bodypart is removed.
varargs void set_rigid(int value,string bodypart) {
  if (value < 0)
    m_delete(rigid,bodypart);
  else
    rigid[bodypart] = value;
}

varargs status query_rigid(string bodypart) {
  mixed h;
  if (m_contains(&h,rigid,bodypart))
    return h;
  else
    return rigid[0];
}

void set_size(int s) { size = s; }
int query_size() { return size; }

void set_type(string t) { type = t; }
string query_type() { return type; }

// this is just available to be overridden if necessary.
int query_layer() { return LIB_CLOTHING->query_layer(query_type()); }

void create() {
  rigid = ([]);
  item::create();  // must be after our create-stuff because it already calls
                   // configure() which may already use e.g. rigid.
}

string query_state_description(status in_output) {
  if (query_worn())
    return "worn";
  else if (!in_output)
    return "unworn\\>|\\<not worn";
}

void configure() {
  item::configure();
  set_property(P_WEARABLE);
  set_id(({ "clothing" }));
  set_short("a non-descript clothing");
  set_name("clothing");
  add_to_property(P_STATE_DESCRIPTION, (#'query_state_description));
}

void notify_move(object from, object to) {
  map_objects(get_wearing_parts(),"unwear",this_object());
}

status drop(int silently) {
  return
    item::drop(silently) ||
    wearable::drop(silently);
}

status prevent_drop() {
  return
    item::prevent_drop() ||
    wearable::prevent_drop();
}
