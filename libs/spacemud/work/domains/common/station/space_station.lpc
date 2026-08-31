inherit "/std/virtual_room"; 

mixed *generate_environment_design(int size) { 
    // This function will now generate a 3D array of strings.
    mixed *design; 

    int z_levels = 3;
    if (size > 8) z_levels = 4;
    if (size > 10) z_levels = 5;

    design = allocate(z_levels);

    // Z-level 0 (Lower Habitation/Cargo)
    design[0] = ({
        " ##### ",
        "#R#S#C#", // R=Rooms, S=Storage, C=Cargo Bay
        "#H# #H#",
        "#R#L#R#", // L=Lower Access (Ladder/Lift)
        " ##### "
    });

    // Z-level 1 (Main Operations/Habitation)
    if (z_levels > 1) {
        design[1] = ({
            "  ###  ",
            " #HOH# ", // O=Offices
            " #M#M# ", // M=Medical
            " #HBH# ", // B=Barracks
            "  ###  "
        });
    } else {
        // If only 1 Z-level, make Z-0 a bit more central for smaller instances
        design[0] = ({ "#####", "#HCH#", "#####" }); // Simple control room
    }

    // Z-level 2 (Command/Upper Access)
    if (z_levels > 2) {
        design[2] = ({
            "   #   ",
            "  #T#  ", // T=Traffic Control
            "  #K#  ", // K=Kitchen
            "  #U#  ", // U=Upper Access (Ladder/Lift)
            "   #   "
        });
    }

    // Z-level 3 (Observation/Airlock)
    if (z_levels > 3) {
        design[3] = ({
            "       ",
            "  #A#  ", // A=Airlock
            "  #V#  ", // V=Observation Deck
            "       ",
            "       "
        });
    }

    // Z-level 4 (Antenna/Exterior Access)
    if (z_levels > 4) {
        design[4] = ({
            "   #   ",
            "  #X#  ", // X=Exterior Access/Antenna array
            "   #   ",
            "       ",
            "       "
        });
    }

    return design;
}

string get_brief_description_suffix(int type_char) {
    switch (type_char) {
        case 'H': return "station corridor";
        case 'L': return "lower access point";
        case 'U': return "upper access point";
        case 'R': return "residential pod";
        case 'S': return "storage section";
        case 'C': return "cargo bay";
        case 'O': return "office space";
        case 'M': return "medical bay";
        case 'B': return "barracks";
        case 'T': return "traffic control center";
        case 'K': return "kitchen/mess hall";
        case 'A': return "docking airlock";
        case 'V': return "observation deck";
        case 'X': return "exterior maintenance platform";
        default: return "unidentified station area";
    }
}

void generate_room_details(int type_char) {
    switch (type_char) {
        case 'H':
            set_long("A curved corridor within the station's living quarters. The air is filtered and slightly stale.");
            set_light(1);
            set_smell("Recycled air, faint cooking odors.");
            break;
        case 'L':
            set_long("This access point connects to the lower levels via a heavy-duty lift. The machinery hums softly.");
            add_item("lift", "A large platform lift, designed for cargo and personnel.");
            set_light(1);
            set_listen("The hum of the lift's machinery.");
            break;
        case 'U':
            set_long("An access shaft leading to the station's upper decks. A narrow ladder descends to lower areas.");
            add_item("ladder", "A sturdy metal ladder for vertical travel.");
            set_light(1);
            break;
        case 'R':
            set_long("A compact, functional residential pod, designed for efficient use of space.");
            add_item("bunk", "A narrow bunk bed.");
            set_light(0);
            break;
        case 'A':
            set_long("The main airlock, typically used for external spacewalks or shuttle docking. "
                     "Its heavy blast doors are currently sealed.");
            add_item("blast doors", "Thick, reinforced doors designed to withstand vacuum.");
            set_light(1);
            set_listen("The faint hiss of pressure seals.");
            break;
        case 'T':
            set_long("The station's traffic control center. Multiple screens display telemetry from nearby vessels.");
            add_item("screens", "Digital displays showing flight paths.");
            set_light(1);
            set_listen("The quiet beeping of radar.");
            break;
        default:
            set_long("An undescribed area of the space station. It seems to be a storage or maintenance space.");
            set_light(0);
            break;
    }
}

// **IMPORTANT:** Each blueprint now needs its own virtual_create method.
object virtual_create(string arg) {
    return new (__FILE__, arg);
}