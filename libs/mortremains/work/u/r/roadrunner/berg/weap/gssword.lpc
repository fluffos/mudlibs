#include <mudlib.h>

inherit WEAPON;

void create() {
	seteuid(getuid());

	set("author", "Roadrunner");

	set("name", "Gnome Short Sword");
	set_weapon_type("sword/short");
	set_material_type("metal/iron");
	set("id", ({ "sword", "gnome sword", "short sword" }) );
	set("short", "A Gnome Short Sword");
	set("long", "This is the issued weapon for the Gnome Army.\n"+
	"Most Gnome Guards carry this standard weapon.\n");
	set("nosecond", 0);
	set("value", 250);
	set("damage",({5,20}) );
	set_verbs( ({"slice", "cut", "cut into" }) );
	set_verbs2( ({ "slices", "cuts", "cuts into" }) );
}
