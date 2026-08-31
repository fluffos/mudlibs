// An item representing a mission pass for a procedurally generated instance.
inherit OBJ; 
inherit M_GETTABLE;

private mapping mission_details; // Stores the data received from PROC_GEN_D
private string shuttle; // Virtual shuttle file path

void setup() {
    set_id("pass", "shuttle pass");
    set_adj("shuttle");
    set_weight(0.1);
    set_value(0); // Mission critical, not for sale
}

// The 'arg' to create will be the mission_details mapping
void create(mapping arg) {
    ::create(); // Call parent create first
    if (arg) {
        mission_details = arg;
        // Set a more descriptive short based on mission details
        //set_short("a shuttle pass for the " + (mission_details["name"] || "unnamed instance"));
    }
}

// Function to generate a dynamic long description
string long() {
    // Moved local variable declaration to the top of the function
    string expiry_str;

    string desc = "This is a digital shuttle pass, granting you access to a specific mission.\n\n";

    if (mission_details["instance_id"]) {
        desc += "Instance ID: " + mission_details["instance_id"] + "\n";
    }
    if (mission_details["name"]) {
        desc += "Mission Target: " + mission_details["name"] + " (" + capitalize(mission_details["description_prefix"]) + ")\n";
    }
    if (mission_details["mission"]) {
        desc += "Mission Brief: " + mission_details["mission"] + "\n";
    }
    if (mission_details["problem"]) {
        desc += "Details: " + mission_details["problem"] + "\n";
    }
    if (mission_details["size"]) {
        desc += "Estimated Size: " + mission_details["size"] + " sections\n";
    }
    if (mission_details["expiry"]) {
        // Convert timestamp to human-readable format
        // This assumes a function like ctime() is available globally or through an inherit.
        // If not, you'll need to write a helper to format the time.
        expiry_str = ctime(mission_details["expiry"]);
        desc += "Expires: " + expiry_str + "\n";
    } else {
        desc += "Expiry: Not set (check with Chief Voss)\n";
    }

    return desc;
}

// Generate virtual shuttle file path for the mission instance
string shuttle_file()
{
   if (!shuttle)
      shuttle = mission_details["shuttle_object"] + "/server/" + time_ns();
   return shuttle;
}

// Allow other objects (like the shuttle) to query mission details
mapping query_mission_details() {
    return mission_details;
}

// Optionally, add a use verb for the player to use the pass
mixed direct_use_obj() {
    return 1; // Can always try to use it
}

mixed indirect_use_obj_with_obj(object target_obj) {
    if (target_obj->is_shuttle()) { // Assuming shuttles have an is_shuttle() LFun
        return 1; // Can use pass with a shuttle
    }
    return 0; // Cannot use with other objects
}

int is_docking_pass()
{
  return 1;
}

// Example use command
void use(string arg) {
    
    object shuttle;

    if (!arg || (arg != "pass with shuttle" && arg != "shuttle pass with shuttle")) {
        write("You can use the shuttle pass with a shuttle to embark on your mission.\n");
        return;
    }
    shuttle = present("shuttle", environment(this_body())); // Assignment only now

    if (!shuttle) {
        write("There's no shuttle here to use the pass with!\n");
        return;
    }

    if (!shuttle->can_embark(mission_details)) { // Shuttle checks if it can take this mission
        write("The shuttle reports it cannot embark on this mission with this pass.\n");
        return;
    }

    // Embarkation successful, destroy pass
    write("You hand the shuttle pass to the pilot, who validates it and prepares for departure.\n");
    destruct(this_object());
    shuttle->embark(mission_details); // Tell the shuttle to start the mission
}

// Function to check if the pass is expired (called by shuttle or Chief Voss)
int is_expired() {
    if (!mission_details || !mission_details["expiry"]) {
        return 0; // No expiry set means it doesn't expire via this check
    }
    return time() > mission_details["expiry"];
}
