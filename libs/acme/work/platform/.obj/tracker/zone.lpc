/**
 * A service object for tracking zones and their instances.
 * 
 * @author devo@eotl
 * @alias ZoneTracker
 */
#pragma no_clone
#include <sys/xml.h>
#include <zone.h>

private inherit ZoneLib;
private inherit FileLib;

// ([ str id : ZoneInfo zone ])
private mapping zones;
// ([ str id : ZoneInstance instance ])
private mapping instances;
private int instance_counter;

public void setup();
public string new_zone(string zone_id);
public int load_config(string zone_id);
public string new_instance(string zone_id, string label);
public string query_starting_instance(string zone_id, string session_id);
public string query_flavor(string zone_id);
protected string get_instance_id(string zone_id, int instance_count);

/**
 * Setup the ZoneTracker.
 */
public void setup() {
  zones = ([ ]);
  instances = ([ ]);
}

/**
 * Invoked to initiate a zone in the system. This can happen anytime for any
 * valid zone, but it will necessarily always have occured by the time the 
 * first object loaded from a zone is initialized.
 * 
 * @param  zone_id       the zone id of the new zone, same as the system path
 * @return the zone id for success, 0 for failure
 */
public string new_zone(string zone_id) {
  if (member(zones, zone_id)) {
    return 0;
  }
  if (!valid_zone_id(zone_id)) {
    return 0;
  }
  struct ZoneInfo parent;
  string parent_id = get_parent_zone(zone_id);
  if (parent_id) {
    if (!member(zones, parent_id)) {
      parent_id = new_zone(parent_id);
    } 
    parent = zones[parent_id];
  }
  zones[zone_id] = (<ZoneInfo> 
    id: zone_id,
    parent: parent_id,
    root: zone_id,
    children: ([ ]),
    instances: ([ ])
  );
  if (parent) {
    parent->children += ([ zone_id ]);
  }

  load_config(zone_id);
  return zone_id;
}

/**
 * Reload configuration from the zone config file for the specified zone.
 * 
 * @param  zone_id       the zone id to configure
 * @return 0 for failure, 1 for success
 */
public int load_config(string zone_id) {
  object logger = LoggerFactory->get_logger(THISO);
  struct ZoneInfo zone = zones[zone_id];
  if (!zone) {
    return 0;
  }
  string zone_file = zone->root + "/" ZONE_FILE;
  if (!file_exists(zone_file)) {
    return 0;
  }
  mixed *xml = xml_parse(read_file(zone_file));
  if (xml[XML_TAG_NAME] != "zone") {
    logger->info("invalid zone.xml: root tag must be <zone>");
    return 0;
  }
  if (member(xml[XML_TAG_ATTRIBUTES], "flavor")) {
    zone->flavor = xml[XML_TAG_ATTRIBUTES]["flavor"];
  } else {
    zone->flavor = 0;
  }
  return 1;
}

/**
 * Invoked to initialize a new "zone instance" in the system.
 * 
 * @param  zone_id       the zone id spawning the new instance
 * @param  label         a friendly label for the new instance
 * @return the instance id of the newly created instance
 */
public string new_instance(string zone_id, string label) {
  int instance_count = ++instance_counter;
  string instance_id = get_instance_id(zone_id, instance_count);
  instances[instance_id] = (<ZoneInstanceInfo> 
    id: instance_id,
    zone: zone_id,
    instance_count: instance_count,
    label: label
  );
  zones[zone_id]->instances += ([ instance_id ]);
  return instance_id;
}

/**
 * Get the zone instance to use for new sessions. This will always be a zone
 * instance with a specific default label. If no matching label is found, a
 * new instance will be created with that label.
 * 
 * @param  zone_id       the zone to get the instance for
 * @param  session_id    the session id of the new session
 * @return the zone instance id of the starting zone instance for the specified
 *         session
 */
public string query_starting_instance(string zone_id, string session_id) {
  if (!member(zones, zone_id)) {
    zone_id = new_zone(zone_id);
  }
  struct ZoneInfo zone = zones[zone_id];
  if (sizeof(zone->instances)) {
    string instance_id;
    foreach (instance_id : zone->instances) {
      if (instances[instance_id]->label == DEFAULT_INSTANCE) {
        return instance_id;
      }
    }
    return instance_id;
  } 
  return new_instance(zone_id, DEFAULT_INSTANCE);
}

/**
 * Get a zone's configured flavor.
 * 
 * @param  zone_id       the zone being queried
 * @return the flavor of the specified zone
 */
public string query_flavor(string zone_id) {
  struct ZoneInfo zone = zones[zone_id];
  if (!zone) {
    return 0;
  }
  return zone->flavor;
}

/**
 * Get a zone instance id from its constituent parts.
 * 
 * @param  zone_id        the zone id
 * @param  instance_count the instance count
 * @return the zone instance id
 */
protected string get_instance_id(string zone_id, int instance_count) {
  return sprintf("%s#%d", zone_id, instance_count);
}

/**
 * Constructor.
 */
public void create() {
  setup();
}
