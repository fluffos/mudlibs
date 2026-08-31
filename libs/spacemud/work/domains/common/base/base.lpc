
inherit "/std/virtual_room"; 

mixed *generate_environment_design(int size) { 
    // Example for a multi-level base (e.g., an underground complex or multi-story building)
    mixed *design; 
    int z_levels = 3;
    if (size > 6) z_levels = 4;
    if (size > 8) z_levels = 5;

    design = allocate(z_levels);

    // Z-level 0 (Basement / Sub-level 1)
    design[0] = ({
        "#######",
        "#S#E#L#", // S=Storage, E=Engineering, L=Lab
        "#H# #H#",
        "#P# #R#", // P=Power, R=Recycling
        "#######"
    });

    // Z-level 1 (Ground Floor / Main Level)
    if (z_levels > 1) {
        design[1] = ({
            "  ###  ",
            " #C#H# ", // C=Command, H=Hallway
            " #H#B# ", // B=Barracks
            " #H#G# ", // G=Guard Post
            "  ###  "
        });
    } else {
        design[0] = ({ "#####", "#HCH#", "#####" }); // Simple command room
    }

    // Z-level 2 (Upper Floor / Research / Admin)
    if (z_levels > 2) {
        design[2] = ({
            "   #   ",
            "  #A#  ", // A=Admin
            "  #D#  ", // D=Dorms
            "  #O#  ", // O=Office
            "   #   "
        });
    }

    // Z-level 3 (Surface Access / Helipad)
    if (z_levels > 3) {
        design[3] = ({
            "       ",
            "  #X#  ", // X=Exit/Surface Access
            "   #   ",
            "       ",
            "       "
        });
    }

    // Z-level 4 (Roof / Antenna Array)
    if (z_levels > 4) {
        design[4] = ({
            "   #   ",
            "  #F#  ", // F=Antenna Field
            "   #   ",
            "       ",
            "       "
        });
    }

    return design;
}

string get_brief_description_suffix(int type_char) {
    switch (type_char) {
        case 'H': return "base corridor";
        case 'S': return "storage room";
        case 'E': return "engineering section";
        case 'L': return "research lab";
        case 'P': return "power distribution room";
        case 'R': return "recycling unit";
        case 'C': return "command center";
        case 'B': return "barracks";
        case 'G': return "guard post";
        case 'A': return "administration office";
        case 'D': return "dormitory";
        case 'O': return "private office";
        case 'X': return "surface access point";
        case 'F': return "antenna field";
        default: return "unidentified base area";
    }
}

void generate_room_details(int type_char) {
    switch (type_char) {
        case 'H':
            set_long("A standard base corridor, made of reinforced concrete and steel. The air smells faintly of ozone.");
            set_light(1);
            break;
        case 'C':
            set_long("The central command center of the base, bristling with communication equipment and tactical displays.");
            add_item("displays", "Large holographic displays showing troop movements.");
            set_light(1);
            set_listen("The quiet chatter of comms.");
            break;
        case 'S':
            set_long("A large, well-stocked storage room. Various crates and supplies are neatly stacked here.");
            add_item("crates", "Wooden and metal crates, some marked 'FRAGILE'.");
            set_light(0);
            break;
        case 'X':
            set_long("This elevator shaft leads up to the surface. A heavy blast door stands ready to seal the opening.");
            add_item("blast door", "A thick, armored door.");
            set_light(1);
            break;
        case 'F':
            set_long("An open rooftop platform, dominated by large, rotating antenna dishes. The wind whips past here.");
            add_item("dishes", "Large, parabolic antenna dishes aimed at the sky.");
            set_light(1);
            set_listen("The hum and whine of electronics, and the rush of wind.");
            break;
        default:
            set_long("An undescribed area within the base. It seems to be a utility or maintenance space.");
            set_light(0);
            break;
    }
}

// **IMPORTANT:** Each blueprint now needs its own virtual_create method.
object virtual_create(string arg) {
    return new (__FILE__, arg);
}