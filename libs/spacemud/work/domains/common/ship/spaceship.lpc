inherit "/std/virtual_room"; 

// Implement abstract functions from virtual_room (these override the defaults)
mixed *generate_environment_design(int size) { 
    // This will generate a 2D map for a single Z-level (Z=0) for spaceships.
    string *design_2d;
    switch (size) {
        case 3..5: // Small ship
            design_2d = ({
                "#######",
                "#C#E#L#", // C=Cockpit, E=Engine, L=Life Support
                "#H# #H#",
                "#H# #H#",
                "#M# #M#", // M=Mess Hall
                "#######"
            });
            break;
        case 6..8: // Medium ship
            design_2d = ({
                "###########",
                "#C# #R# #L#", // C=Cockpit, R=Cargo, L=Life Support
                "#H#H#H#H#H#",
                "#E# #B# #M#", // E=Engine, B=Bridge, M=Medbay
                "#H#H#H#H#H#",
                "#W# #G# #D#", // W=Weapons, G=Galley, D=Dorm
                "###########"
            });
            break;
        default: // Large/Default ship
            design_2d = ({
                "#############",
                "#C# # # #R# #",
                "#H#H#H#H#H#H#",
                "#E# #B# # #L#",
                "#H#H#H#H#H#H#",
                "#M# # # #G# #",
                "#H#H#H#H#H#H#",
                "#D# #W# #P# #", // P=Prison
                "#############"
            });
            break;
    }
    // For a 2D design, wrap it in an array to represent a single Z-level.
    return ({ design_2d });
}

string get_brief_description_suffix(int type_char) {
    switch (type_char) {
        case 'C': return "cockpit";
        case 'E': return "engine room";
        case 'L': return "life support room";
        case 'H': return "corridor";
        case 'M': return "mess hall";
        case 'R': return "cargo bay";
        case 'B': return "bridge";
        case 'G': return "galley";
        case 'D': return "dormitories";
        case 'W': return "weapons bay";
        case 'P': return "prison block";
        default: return "unidentified ship area";
    }
}

void generate_room_details(int type_char) {
    switch (type_char) {
        case 'C':
            set_long("This is the cockpit of the spaceship. Control panels glow softly, "
                     "and a large viewport offers a panoramic view of space.");
            add_item("panels", "control panels", "A myriad of buttons and screens, all flashing.");
            add_item("viewport", "The main window, showing stars streaking by.");
            set_light(1);
            set_smell("A faint metallic scent.");
            break;
        case 'E':
            set_long("The engine room. Massive conduits hum with raw power, and the air "
                     "is thick with the smell of ozone and hot metal.");
            add_item("conduits", "Large, glowing pipes carrying energy.");
            set_light(1);
            set_smell("Ozone and hot metal.");
            set_listen("A deep, continuous hum.");
            break;
        case 'L':
            set_long("The ship's life support systems. Various machines whir and click, "
                     "filtering the air and recycling water.");
            add_item("machines", "Life support machines, busy at work.");
            set_light(0); // Dimly lit
            set_smell("Sterile, recycled air.");
            break;
        case 'H':
            set_long("A standard spaceship corridor. The walls are seamless, and "
                     "emergency lights illuminate the path.");
            set_light(0); // Dimly lit
            break;
        case 'M':
            set_long("The mess hall, or what's left of it. Tables are overturned, "
                     "and food dispensers are scattered about.");
            add_item("tables", "Overturned tables.");
            add_item("dispensers", "Broken food dispensers.");
            set_light(1);
            set_smell("Stale rations.");
            break;
        case 'B': // Bridge
            set_long("The main bridge of the spaceship, where command decisions are made. "
                     "Several consoles are arrayed in front of a large main viewscreen.");
            set_light(1);
            break;
        case 'R': // Cargo
            set_long("A spacious cargo bay, currently filled with empty crates and some discarded equipment.");
            add_item("crates", "Empty storage crates.");
            set_light(0);
            break;
        default:
            set_long("An unknown area of the spaceship. The damage here is extensive.");
            set_light(-1); // Very dark
            set_smell("The acrid smell of burnt wiring.");
            break;
    }
}

// **IMPORTANT:** Each blueprint now needs its own virtual_create method.
// This is what the MUD driver calls when it encounters a path like /domains/common/ship/spaceship/<instance_id>/...
object virtual_create(string arg) {
    // arg format: instance_id/size/x/y/z or instance_id/size/x/y (for 2D)
    // We simply create a new instance of THIS FILE (spaceship.c) and pass the arg to its create().
    return new (__FILE__, arg);
}