#include <lib.h>
#include <vendor_types.h>
inherit LIB_BOOK;

void create(){
    ::create();
    SetKeyName("cheatbook");
    SetId( ({"book","cheatsbook" }) );
    SetAdjectives( ({"cheat", "cheats"}) );
    SetShort("a cheat book");
    SetLong("This is a book with explicit tricks you can use to advance your character. To read it, you must read the chapters in it. For example, 'read chapter 1 in cheatbook', or 'read index in cheatbook'");
    SetProperties(([
                "no steal" : 1,
                ]));
    SetMass(3);
    SetBaseCost("universal credits",10);
    SetVendorType(VT_TREASURE);
    SetTitle("The Cheat Book");
    SetSource("/doc/cheats");
    SetDefaultRead("Try \"read chapter 1 in cheatbook\" or "
            "\"read index in cheatbook\"");

}
void init(){
    ::init();
}
