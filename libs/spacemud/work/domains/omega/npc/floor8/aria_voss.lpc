/* Do not remove the headers from this file! see /USAGE for more info. */

inherit LIVING;
inherit M_CONVERSATION;
inherit M_STATEFUL;

#define PROC_GEN_D "/daemons/proc_gen_d" // Define the daemon path

#define MAX_MISSIONS 3
#define RENEW_MISSIONS_MINUTES 120
#define PUSHY_CUSTOMER_PENALTY 10
#define PASS_EXPIRY 60

private mapping current_missions = ([]); // Renamed from 'missions' to avoid confusion
private mapping volunteers = ([]);

mapping volunteers() {
    return volunteers;
}

void generate_key(string key) {
    // Moved all local variable declarations to the very beginning of the function
    object pass;
    int expiry;
    mapping mission_data;

    expiry = time() + (60 * PASS_EXPIRY); // Assignment only now

    // Check if the player already has an active mission
    if (volunteers[this_body()->query_name()] && volunteers[this_body()->query_name()] > time()) {
        this_object()->targetted_action(
            "$N $vsay to $t, \"HEY! You already got a mission! Finish that first, see me when done.\"", this_body());
        volunteers[this_body()->query_name()] += (60 * PUSHY_CUSTOMER_PENALTY); // Add penalty
        return;
    }

    // Get the specific mission data from our internal tracking
    mission_data = current_missions[key]; // Assignment only now
    if (!mission_data) {
        this_object()->targetted_action("$N $vsay to $t, \"I can't find that mission right now. It might have expired or been taken.\"", this_body());
        return;
    }

    // Assign expiry to the mission instance (within the daemon) and the volunteer
    // Pass the expiry to the daemon to manage it. The pass payload will also reflect this.
    mission_data["expiry"] = expiry;
    volunteers[this_body()->query_name()] = expiry;

    TBUG(mission_data);
    // Create the shuttle pass with the generalized mission data
    pass = new ("/domains/common/item/shuttle_pass", mission_data); // Assignment only now
    pass->move(this_body());

    this_object()->targetted_action("$N $vhand the $o to $t.", this_body(), pass);
    map_delete(current_missions, key); // Remove mission after it's been given out by Voss
}

void complete_mission(string who) {
    map_delete(volunteers, who || this_body()->query_name());
    // Potentially call PROC_GEN_D->remove_instance(instance_id) here if mission success means instance removal
}

void generate_missions() {
    
    string *problems;
    mapping instance_types;
    string *instance_type_keys;
    int i; // Loop counter
    string chosen_type_key;
    mapping type_info;
    int *sizes_range;
    int size;
    mapping proc_gen_data;
    string *problem_details;
    string mission_title;
    string mission_problem;

    problems = ({
        "Core Failure|<bld>Power Core Failure:<res> The primary power source has malfunctioned, leading to a complete systems shutdown.",
        "Comm Array Dmg|<bld>Communication Array Damage:<res> Antennas or communication systems have been damaged, rendering them unable to send or receive signals.",
        "Navi Error|<bld>Navigational System Malfunction:<res> A critical error in the navigational systems has left the unit adrift and unable to correct its course or send distress signals.",
        "Hull Breach|<bld>Hull Breach:<res> A breach in the hull has caused an emergency lockdown, sealing off sections and disabling communication.",
        "Virus|<bld>Computer Virus:<res> A malicious software attack has crippled onboard computers, preventing any form of communication.",
        "Engine|<bld>Engine Overload:<res> The engines have experienced a catastrophic failure, resulting in an emergency shutdown of all systems.",
        "Life Support|<bld>Life Support System Failure:<res> The life support systems have failed, putting the crew in immediate danger and prioritizing internal emergency protocols over external communication.",
        "Hostiles|<bld>Hostile Boarding:<res> The unit has been boarded by hostile forces, who have disabled communication to avoid detection.",
        "Asteroid|<bld>Asteroid Collision:<res> An unexpected collision with an asteroid or space debris has caused significant damage, disrupting all communication channels.",
        "Interference|<bld>Electromagnetic Interference:<res> A nearby cosmic anomaly or enemy device is emitting strong electromagnetic waves, blocking all outgoing and incoming signals."
    });

    current_missions = ([]); // Clear existing missions

    instance_types = PROC_GEN_D->query_instance_types(); // Assignment only now
    instance_type_keys = keys(instance_types);

    for (i = 0; i < MAX_MISSIONS; i++) {
        chosen_type_key = choice(instance_type_keys);
        type_info = instance_types[chosen_type_key];

        // Random size within the defined range for this instance type
        sizes_range = type_info["sizes_range"];
        size = random(sizes_range[1] - sizes_range[0] + 1) + sizes_range[0];

        // Request a new instance from the daemon
        proc_gen_data = PROC_GEN_D->request_new_instance(chosen_type_key, size);

        if (!proc_gen_data) {
            // Handle error if daemon fails to generate instance
            continue;
        }

        problem_details = explode(choice(problems), "|");
        mission_title = problem_details[0];
        mission_problem = problem_details[1];

        current_missions["mission" + i] = proc_gen_data; // Store the daemon's generated data
        current_missions["mission" + i]["mission"] = mission_title; // Add mission-specific problem details
        current_missions["mission" + i]["problem"] = mission_problem;
        current_missions["mission" + i]["shuttle_object"] = "/domains/common/ship/shuttle"; // Path to the actual shuttle object that transports
    }
}

void setup_chats() {
    mapping responses = (["hello": "Sorry, I do not have time to chat. Did you have a question?@@help"]);
    mapping options = ([
        "hello": "Hello, Chief Voss.",
        "help": "Can I assist the landing operations of Omega Station in some way?"
    ]);
    string *confirmations = ({
        "My team and I will handle the", "We'll attempt to help the", "I decided on the",
        "I've picked the", "We are going for the", "Let's do the", "The", "Umm.. the",
        "The team has decided that we go for the"
    });
    string mission_txt = "I have the following distress calls right now - check back later for other missions:\n\n";
    string mission_list = "";

    // Build mission_list for conversation
    foreach (string key in keys(current_missions)) {
        mission_list += key + ",";
    }
    if (strlen(mission_list) > 0) {
        mission_list = mission_list[0.. < 2]; // Remove trailing comma
    }

    foreach (string key, mapping mish in current_missions) {
        // Use the new 'name' field from the daemon's generated data for display
        mission_txt += sprintf("     <%d>%s<res>:\n     %s\n\n",
                               148, mish["name"] || "Unnamed Instance", mish["problem"]);

        options[key] = sprintf("%s <%d>%s<res>!",
                               choice(confirmations), 148, mish["name"] || "Unnamed Instance");

        responses[key] = ({
            "Okay, " + (mish["name"] || "the mission") + " it is then.@@@@nothanks," + mission_list,
            (: generate_key, key :)
        });
    }

    responses["help"] = ({
        mission_txt + "...",
        "Let me know if you want to help with one of these and I'll give you a terminal key to summon a " +
        "transport.",
        "Higher category of instance usually means more people needed to handle the situation.",
        "So what will it be?@@nothanks," + mission_list
    });
    options["nothanks"] = "Nevermind, not right now then. My team is not quite ready.";
    responses["nothanks"] = "Stop wasting my time.@@@@" + mission_list;
    set_responses(responses);
    set_options(options);
}

void begin_conversation() {
    if (!sizeof(keys(current_missions))) {
        generate_missions();
    }
    setup_chats();
    set_start(({"hello"}));

    ::begin_conversation();
}

void setup() {
    set_gender(2);
    set_name("Aria Voss");
    add_id("aria", "voss", "aria voss", "chief");
    set_proper_name("Aria Voss");
    set_in_room_desc("Chief landing controller Aria Voss");
    set_long("Behind the main counter stands the chief landing controller, Aria Voss, a seasoned veteran with sharp "
             "eyes and an an air of authority. She wears a crisp uniform adorned with insignias of her rank and years of "
             "service. Her short-cropped hair is streaked with silver, hinting at her vast experience, and her focused "
             "expression reveals a mind always at work, juggling multiple tasks at once. A headset is permanently "
             "affixed to her ear, connecting her to various transport channels and station personnel.");

    set_call_interval(RENEW_MISSIONS_MINUTES);
}

int state_update() {
    if (!sizeof(keys(current_missions))) {
        generate_missions();
        setup_chats(); // Rebuild chats if missions regenerated
        return 1;
    }
    // You might also want to do other checks here, e.g., if any missions expired from `volunteers`
    return 1;
}

string query_location() {
    return "Omega Terminal";
}

string query_starsystem() {
    return "Omega";
}

string *query_variants(string main_mish) {
    if (!sizeof(keys(current_missions))) {
        generate_missions();
    }
    return map(values(current_missions), (: $1["name"] + ": " + $1["mission"] :));
}

string query_hint(int level) {
    return "Chief Aria Voss provides missions to various distressed instances around Omega Terminal.";
}