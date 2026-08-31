#include <daemons.h>
#include <gmcp_defines.h>

inherit __DIR__ "gmcp_module";

void manage_hierarchy(mapping current, string key, int version, int depth);

void setup() {
  cooldown_limits = ([
    GMCP_PKG_CORE_PING : 60,
  ]);
}

void Hello(mapping data) {
  object prev = previous_object();
  string key, value;

  // Core.Hello should only arrive from the login object at the start of the
  // connection.
  if(base_name(prev) != LOGIN_OB)
    return;

  foreach(key, value in data) {
    map_delete(data, key);
    data[lower_case(key)] = value;
  }

  prev->set_gmcp_client(data);
}

void Supports(string submodule, mixed data) {
  object prev = previous_object(1) || previous_object();
  mapping supports = prev->query_gmcp_supports();

  switch(submodule) {
    case "Set": {
      supports = ([ ]);
      foreach(string item in data) {
        // Splitting the package.module version format
        string *parts = explode(item, " ");
        string full_name = parts[0];
        int version = to_int(parts[1]);
        string *path = explode(full_name, ".");

        // Building the hierarchical structure
        mapping current = supports;
        for(int i = 0; i < sizeof(path); i++) {
          string key = path[i];
          // If it's the last element, set the version
          if(i == sizeof(path) - 1) {
            if(sizeof(path) == 1) { // Directly under the root
              if(!current[key])
                current[key] = ([ "version": version ]);
              else
                current[key]["version"] = version;
            } else { // It's a module or submodule
              string type = (i == 1) ? "modules" : "submodules";
              if(!current[type])
                current[type] = ([ ]);

              if(!current[type][key])
                current[type][key] = ([ "version": version ]);
              else
                current[type][key]["version"] = version;
            }
          } else { // Not the last element, navigate or create the structure
            if(!current[key])
              current[key] = ([ ]);
            current = current[key];
          }
        }
      }
      break;
    }
    case "Add" : {
      if(stringp(data))
        data = ({ data });

      foreach(string item in data) {
        string *parts = explode(item, " ");
        string full_name = parts[0];
        int version = to_int(parts[1]);
        string *path = explode(full_name, ".");

        mapping current = supports;

        for(int i = 0; i < sizeof(path); i++) {
          string key = path[i];
          if(i == sizeof(path) - 1) {
            // Handle setting the version for package/module/submodule
            manage_hierarchy(current, key, version, sizeof(path));
          } else {
            if(!current[key])
              current[key] = ([ "modules": ([ ]) ]);
            current = current[key]["modules"];
          }
        }
      }
      break;
    }
    case "Remove" : {
      string *path, key, last_key;
      mapping current;
      int i;

      if(stringp(data))
        data = ({ data });

      // Iterate over items to remove
      foreach(string item in data) {
        // Split item into path, ignoring version numbers
        sscanf(item, "%s %*s", item);
        path = explode(item, ".");
        current = supports; // Reset to root for each item

        // Navigate to the correct location in the hierarchy
        for(i = 0; i < sizeof(path) - 1; i++) {
          key = path[i];
          if(!current[key] || !mapp(current[key]["modules"]))
            // Path does not exist or is malformed, skip this item
            break; // Use 'break' to exit the current iteration

          if(i < sizeof(path) - 2) // Not yet at the parent of the target
            current = current[key]["modules"];

        }

        if(i < sizeof(path) - 1)
          // If the loop exited early, the path was invalid, skip to next item
          continue;

        // At the parent of the target, remove the target
        last_key = path[<1];
          if(sizeof(path) == 1) // Removing a package
            map_delete(current, last_key);
          else // Removing a module or submodule
            map_delete(current[key]["modules"], last_key);

          break;
      }
    }
  }
  prev->set_gmcp_supports(supports);
}

void manage_hierarchy(mapping current, string key, int version, int depth) {
  if(depth == 1) // Directly under root
    current[key] = ([ "version": version ]);
  else { // Module or submodule
    string type = (depth == 2) ? "modules" : "submodules";
    if(!current[type])
      current[type] = ([ ]);

    current[type][key] = ([ "version": version ]);
  }
}

void Ping(int time) {
  object prev = previous_object();

  if(!cooldown_check(GMCP_PKG_CORE_PING, prev))
    return;

  apply_cooldown(GMCP_PKG_CORE_PING, prev);

  if(!time)
    return;

  GMCP_D->send_gmcp(prev, GMCP_PKG_CORE_PING);
}
