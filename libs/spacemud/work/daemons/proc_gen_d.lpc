// Central daemon for managing procedurally generated instances

inherit M_DAEMON_DATA; 
inherit M_STATEFUL;

//  Private variables 
private mapping instance_templates = ([]); // Defines types like "spaceship", "space station"
private mapping active_instances = ([]); // Stores data for all currently active generated instances

// Private Functions
private string generate_instance_name(string type, string id);

//  Setup 
void create() {
    ::create();

    // Define the available instance types and their virtual object paths
    // This mapping can eventually be loaded from a configuration file for easier modification.
    instance_templates = ([
        "spaceship": ([
            "path": "/domains/common/ship/spaceship",
            "name": "ship", // For descriptive purposes
            "description_prefix": "ship",
            "sizes_range": ({3, 9})
        ]),
        "space station": ([
            "path": "/domains/common/station/space_station",
            "name": "station",
            "description_prefix": "station",
            "sizes_range": ({4, 12})
        ]),
        "base": ([
            "path": "/domains/common/base/base",
            "name": "base",
            "description_prefix": "base",
            "sizes_range": ({2, 8})
        ]),
        // Example of how to add a new type:
        //"underground bunker": ([
        //    "path": "/domains/your_domain/bunker/underground_bunker", // Path to your new blueprint
        //    "name": "bunker",
        //    "description_prefix": "bunker",
        //    "sizes_range": ({3, 7}) // Define typical sizes for bunkers
        //])
    ]);
}

//  Public API Functions 

// Called by Chief Voss to request a new mission instance
// Returns a mapping of mission details to be put in the shuttle_pass
mapping request_new_instance(string type, int size) {
    
    string instance_blueprint_path;
    object blueprint_ob;
    string instance_id;
    mixed *generated_design; 
    string generated_name;

    if (!instance_templates[type]) {
        error("PROC_GEN_D: Unknown instance type: " + type);
        return 0;
    }

    instance_blueprint_path = instance_templates[type]["path"];

    // Load the blueprint object to call its generate_environment_design()
    if (!(blueprint_ob = load_object(instance_blueprint_path))) {
        error("PROC_GEN_D: Could not load blueprint: " + instance_blueprint_path);
        return 0;
    }

    // Generate a unique ID for this specific instance
    instance_id = type + "_" + time() + "_" + random(99999);

    // generated_design will implicitly store a mixed* array
    generated_design = blueprint_ob->generate_environment_design(size);
    if (!generated_design || sizeof(generated_design) == 0) {
        error("PROC_GEN_D: Failed to generate design for " + type + " instance: " + instance_id);
        return 0;
    }

    // Generate a unique name for this instance
    generated_name = generate_instance_name(type, instance_id);

    // Store all specific data for this active instance
    active_instances[instance_id] = ([
        "type": type,
        "size": size,
        "blueprint_path": instance_blueprint_path, // Path to the blueprint (controller)
        "design": generated_design,
        "name": generated_name,
        "creation_time": time(),
        "last_accessed": time(), // Track for cleanup
        // Add more instance-specific data here (e.g., mission objectives, specific damaged areas)
    ]);

    // Return a simplified mapping suitable for the mission pass/Chief Voss
    return ([
        "instance_id": instance_id,
        "instance_path": instance_blueprint_path, // Path to the controller (e.g., /domains/common/ship/spaceship)
        "description_prefix": instance_templates[type]["description_prefix"],
        "size": size,
        "name": generated_name,
        // Mission specific details will be added by Chief Voss based on this, or could be generated here
    ]);
}

// Called by rooms (virtual_room) to retrieve data for their specific instance
mapping query_instance_data(string instance_id) {
    if (!active_instances[instance_id]) {
        // Optionally, try to load from disk if not in memory (for persistent instances)
        return 0; // Instance not found
    }
    // Update last accessed time for cleanup purposes
    active_instances[instance_id]["last_accessed"] = time();
    return active_instances[instance_id];
}

// Called to remove an instance (e.g., mission completed, expired, all players left)
void remove_instance(string instance_id) {
    if (active_instances[instance_id]) {
        map_delete(active_instances, instance_id);
        // Inform players if anyone was still there, or logs.
        // Potentially save state if needed before removal for long-term tracking.
    }
}

// Get information about available instance types for Chief Voss
mapping query_instance_types() {
    return instance_templates;
}

//  Internal Helper Functions 

// Generates a unique, readable name for a new instance
private string generate_instance_name(string type, string id) { 
    string base_name;
    switch (type) {
        case "spaceship": base_name = "Vanguard"; break;
        case "space station": base_name = "Outpost"; break;
        case "base": base_name = "Fortress"; break;
        case "underground bunker": base_name = "Bastion"; break; // Example for new type
        default: base_name = "Unit"; break;
    }
    // A simple naming scheme for demonstration. Could be much more complex.
    return sprintf("%s %s-%s", base_name, capitalize(type), id[<5..<1]); // E.g., "Vanguard Spaceship-99999"
}

// Example: Periodic cleanup of old instances
void clean_old_instances() {
    foreach (string instance_id, mapping data in active_instances) {
        // Example: Remove instances not accessed in 2 hours
        if (time() - data["last_accessed"] > (120 * 60)) {
            // Check if there are players in the instance before removal if necessary
            // For now, simple removal
            remove_instance(instance_id);
            // debug_message("Cleaned up old instance: " + instance_id);
        }
    }
}

// You might set a call_out to run clean_old_instances periodically
void setup() {
    set_call_interval(60); // Run every minute
}

// Called by M_STATEFUL if inherited, or can be called explicitly
int state_update() {
    clean_old_instances();
    return 1; // Keep stateful active
}