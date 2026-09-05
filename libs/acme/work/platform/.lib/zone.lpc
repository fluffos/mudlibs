/**
 * A library for manipulating zones of rooms and objects.
 *
 * @author devo@eotl
 * @alias ZoneLib
 */
#pragma no_clone
#include <zone.h>
#include <object.h>

private inherit ObjectLib;

struct ZoneInfo {
  string id;
  string parent;
  mapping children;  // ([ zone_id ])
  mapping instances;  // ([ instance_id ])
  string root;
  string flavor;
};

struct ZoneInstanceInfo {
  string id;
  string zone;
  int instance_count;
  string label;
};

protected int valid_zone_id(string zone_id);
protected string get_parent_zone(string zone_id);
protected string get_zone(object ob);

/**
 * Test whether a zone id is valid.
 * 
 * @param  zone_id       the zone id
 * @return 1 if is a valid zone id, otherwise 0
 */
protected int valid_zone_id(string zone_id) {
  return (strstr(zone_id, ZONE_DELIM CATEGORY_DELIM) == -1);
}

/**
 * Get the parent zone id of a given zone id.
 * 
 * @param  zone_id       the zone id
 * @return the parent zone id
 */
protected string get_parent_zone(string zone_id) {
  if (!valid_zone_id(zone_id)) {
    return 0;
  }
  string *parts = explode(zone_id, ZONE_DELIM);
  if (sizeof(parts) == 1) {
    return 0;
  } else {
    return implode(parts[0..<2], ZONE_DELIM);
  }
}

/**
 * Get the zone an object belongs to.
 *
 * @param  ob the object to query
 * @return    the object's zone
 */
protected string get_zone(object ob) {
  return get_path_info(ob)[PATH_INFO_ZONE];
}
