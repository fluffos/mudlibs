#include <std.h>
inherit OBJECT;

#include <kwike.h>

int flav, i;

void
create()
{
    ::create();
    set_value(7);
    set_weight(7);
    set_short("squishie");
    set_id(({ "squishie" }));
}

void
init()
{
    ::init();
    add_action("cmd_drink", "drink");
}

int
cmd_drink(string what)
{
    object cup;

    if (!id(what))
        return 0;

    if (environment(this_object()) != this_player())
        return notify_fail("Pick the squishie up before trying to drink it.\n");

    if (!this_player()->add_quenched(this_player()->query_level()*4))
        return notify_fail("You brain is too numb to drink that!\n");

    switch (flav) {
        case 0: /* lemon-lime */
            if (this_player()->query_hp() - 5 < i)
                return notify_fail("Your tongue is too sore to drink!\n");
            write("The sour lemon squishie makes your tongue cringe!");
            this_player()->damage(i);
            this_player()->add_sp(i*7);
            break;
        case 1: /* watermelon */
            this_player()->heal(i*3);
            write("The sweet watermelon runs through you and you feel replenished...");
            break;
        case 2: /* banana */
            this_player()->add_poisoning(-(i*(random(5)+10)));
            this_player()->heal(i/2+7);
            write("The power of apu's fresh bananas cleanses your soul and you feel pure...");
            break;
        case 3: /* barley */
            this_player()->damage(i);
            this_player()->add_mp(i*7);
            write("The barley bites into your senses... you can feel the magic inside you...");
            break;
        case 4: /* strawberry */
            switch (this_player()->query_gender()) {
                case "female":
                if(this_player()->query_race() != "nymph")
                    this_player()->set_gender("male");
                    write("The strawberries energize inside you and make you hungry for more...");
                    break;
            }
            this_player()->heal(i/3);
            break;
    }

    cup = new(OBJECT);
    cup->set_short("An empty cup");
    cup->set_long("An empty cup which once contaned a squishie.");
    cup->set_id(({ "cup", "sippie cup", "empty cup" }));
    cup->set_value(3);
    cup->set_weight(1);
    cup->set_destroy(1);
    cup->move(environment(this_object()));

    remove();
    return 1;
}

void
set_flavor(int flavor)
{
    set_short(flavors[flavor]+" squishie");
    set_long("The "+flavors[flavor]+" squishie: "+flavor_descriptions[flavor]);
    set_id(({ "squishie", flavors[flavor]+" squishie" }));
    i = random(this_player()->query_level() / 2) * 3 / 2;
    flav = flavor;
}
