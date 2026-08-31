// /std/virtual_room.c
// Common base class for all procedurally generated room instances.
// Inherit a basic room/environment object (e.g., /std/room)
inherit INDOOR_ROOM; 
// Include the daemon
#define PROC_GEN_D "/daemon/proc_gen_d"

//  Private variables 
protected string instance_id;
protected int current_x, current_y, current_z; // Z for up/down
protected int setup_complete; // Flag to ensure setup runs once
protected int environment_size; // Stored here for convenience

//  Functions to be overridden by specific virtual room types 
// The daemon will call generate_environment_design on the *blueprint* itself.
mixed *generate_environment_design(int size) { 
    // This is a generic fallback; specific rooms should override this.
    return ({ ({ "G" }) }); // A single generic room
}

// Provide generic fallback descriptions
string get_brief_description_suffix(int type_char) {
    switch (type_char) {
        case ' ': return "empty space";
        case '#': return "solid wall";
        default: return "generic area";
    }
}

// Provide generic fallback details
void generate_room_details(int type_char) {
    set_long("This is a generic procedurally generated room. It has no specific details defined.\n");
    set_light(0); // Dimly lit by default
}

//  Common (Generalized) Functions 

void setup() {
    // Common setup for all virtual rooms.
    // Can set default brief or cost here, if applicable.
}

void create(string arg) {
    
    string tmp_id;
    int tmp_size, tmp_x, tmp_y, tmp_z;

    if (!arg) {
        // This object is being loaded directly without virtual arguments.
        // Useful for testing the blueprint itself, but not for instance rooms.
        ::create();
        return;
    }

    // Parse the argument string to extract instance_id, size, and coordinates
    // Format: instance_id/size/x/y/z (or x/y/0 for 2D)

    if (sscanf(arg, "%s/%d/%d/%d/%d", tmp_id, tmp_size, tmp_x, tmp_y, tmp_z) == 5) {
        instance_id = tmp_id;
        environment_size = tmp_size;
        current_x = tmp_x;
        current_y = tmp_y;
        current_z = tmp_z;
    } else if (sscanf(arg, "%s/%d/%d/%d", tmp_id, tmp_size, tmp_x, tmp_y) == 4) {
        // 2D format, assume Z=0
        instance_id = tmp_id;
        environment_size = tmp_size;
        current_x = tmp_x;
        current_y = tmp_y;
        current_z = 0;
    } else {
        // Invalid arguments, or just instance_id/size without coords (e.g., for virtual_create controller)
        instance_id = arg; // Treat whole arg as instance_id or blueprint path
        environment_size = 0; // Default size
        current_x = 0; current_y = 0; current_z = 0; // Default coords
    }

    ::create(); // Call parent create after parsing args
}

// Queries the daemon for the design map specific to this instance_id
mixed *query_environment_design() { 
    mapping instance_data = PROC_GEN_D->query_instance_data(instance_id);
    if (instance_data && instance_data["design"]) {
        return instance_data["design"];
    }
    // Fallback: This indicates an error or missing instance data.
    error("Virtual Room: No design map found for instance_id: " + instance_id + " at " + file_name(this_object()) + "\n");
    return ({ ({ " " }) }); // Return empty map to prevent further errors
}

// Retrieves random valid coordinates within this instance's design
int *get_random_room_coords() {
    mixed *design = query_environment_design();

    int z_max;
    int x_max, y_max;
    int rand_x, rand_y, rand_z;

    if (!design || sizeof(design) < 1 || !design[0] || sizeof(design[0]) < 1 || strlen(design[0][0]) < 1) {
        return ({0, 0, 0});
    }

    z_max = sizeof(design); // Assignment only now
    
    do {
        rand_z = random(z_max);
        if (design[rand_z]) {
            x_max = sizeof(design[rand_z]);
            if (x_max > 0 && design[rand_z][0]) {
                y_max = strlen(design[rand_z][0]);
            } else {
                x_max = 0; y_max = 0;
            }
        } else {
            rand_z = -1; // Force re-roll
        }

        if (x_max == 0 || y_max == 0) {
            continue;
        }

        rand_x = random(x_max);
        rand_y = random(y_max);
    } while (rand_z == -1 || design[rand_z][rand_x][rand_y] == ' '); // Reroll if it's an empty space

    return ({rand_x, rand_y, rand_z});
}

string get_size_name() {
    switch (environment_size) {
        case 0..3: return "small";
        case 4..6: return "large";
        case 7..9: return "quite large";
        case 10..15: return "huge";
        default: return "gigantic";
    }
}

// Queries the daemon for the name specific to this instance_id
string query_environment_name() {
    mapping instance_data = PROC_GEN_D->query_instance_data(instance_id);
    if (instance_data && instance_data["name"]) {
        return instance_data["name"];
    }
    return "Unnamed Generated Instance"; // Fallback
}

int *query_coords() {
    return ({current_x, current_y, current_z});
}