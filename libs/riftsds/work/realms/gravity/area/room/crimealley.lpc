// /realms/gravity/area/room/crimealley.c
#include <lib.h>

inherit LIB_ROOM;

string *villains = ({
    "The Joker", "Harley Quinn", "The Riddler", "Penguin", "Two-Face", 
    "Scarecrow", "Poison Ivy", "Bane", "Mr. Freeze", "Catwoman"
});
int villain_spawned; // Flag to indicate whether a villain has already been spawned

void SpawnVillain(); // Declare the function before its usage

void create() {
    room::create();
    SetShort("A mysterious room");
    SetLong("In the heart of Gotham City lies Crime Alley - a forsaken stretch of pavement steeped in tragedy. Once known as Park Row, this decaying urban corridor was transformed by sorrow and violence.  Dim street lights cast feeble glimmers on graffiti-covered walls, revealing the scars of countless crimes. Abandoned storefronts sag under the weight of despair, their windows shattered long ago. Leslie Thompkins tends to the wounded and broken in her weathered clinic.  Bruce Wayne, now Batman, returns here on moonless nights. He places wilted flowers at the spot where his parents fell, vowing to protect others from the same fate. Crime Alley remains - a scar on Gotham's soul, a testament to loss and resilience.");
    
    SetExits( ([
        "south" : "/realms/gravity/area/room/vault", // Example exit, adjust as needed
    ]) );

    SetClimate("indoors");
    SetAmbientLight(30);
    SetInventory(([]));
}

void init() {
    ::init();
    if(!villain_spawned) { // Check if a villain has already been spawned
        call_out((: SpawnVillain :), 1);
        villain_spawned = 1; // Set the flag to indicate a villain has been spawned
    }
}

void SpawnVillain() {
    object villain;
    string villain_name;

    villain = new("/realms/gravity/area/npc/random_villain");
    villain_name = villains[random(sizeof(villains))];

    villain->SetKeyName(lower_case(villain_name));
    villain->SetId(({ lower_case(villain_name), "villain" }));
    villain->SetShort("a villain named " + villain_name);
    villain->SetLong("This is the notorious " + villain_name + ", one of Batman's most feared adversaries.");
    villain->SetLevel(10 + random(10));
    villain->SetGender(random(2) ? "male" : "female");

    villain->eventMove(this_object());
    message("info", "A villain named " + villain_name + " appears!", this_object());
}
