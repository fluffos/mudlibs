#include "include/description.h"
#include "include/id.h"
#include "include/object.h"

private nosave mapping loot_properties = ([]);

/**
 * @param {mapping} data - The basic setup for all virtual objects.
 * @returns {void}
 */
void virtual_mudlib_setup(mapping data) {
  assert_arg(
    mapp(data),
    1,
    "Invalid data passed to "+file_name()+". Got "+sprintf("%O", data)+"."
  );

  data["id"] && set_id(data["id"]);
  data["adj"] && set_adj(data["adj"]);
  data["name"] && set_name(data["name"]);
  data["short"] && set_short(data["short"]);
  data["long"] && set_long(data["long"]);

  if(pointerp(data["additional ids"])) {
    each(data["additional ids"], (: add_id($1) :));
  }

  // Set additional properties
  if(mapp(data["properties"]))
    foreach(string key, mixed value in data["properties"])
      loot_properties[key] = value;

  pointerp(data["material"]) && call_if(this_object(), "add_material", data["material"]...);
}

mixed query_loot_property(string key) {
  return loot_properties[key];
}

mapping query_loot_properties() {
  return copy(loot_properties);
}

void clear_loot_properties() {
  loot_properties = ([]);
}
