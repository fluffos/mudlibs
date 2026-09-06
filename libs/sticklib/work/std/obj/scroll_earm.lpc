#include <treasure.h>

mixed *data;

void
create_treasure()
{
    set_name("parchment scroll");
    set_short("Parchment Scroll");
    set_id(({ "parchment", "scroll" }));
    set_long("It is a scroll which allows you to enchant an armour. "
             "Small print says: You can only enchant an armour once. "
             "Might not work for armour that is already enchanted.");
    set_read("It is a scroll which allows you to enchant an armour. "
             "Small print says: You can only enchant an armour once. "
             "Might not work for armour that is already enchanted.");

    set_value(800);
}

int
begin_invoke (object me, mixed *data)
{
    mixed tgt;
    object target, env;

    if (!data) {
        me->tell_me ("Enchant which armour?");
        return 0;
    }

    if (pointerp (data)) {
        tgt = data[0];
    } else {
        tgt = data;
    }

    if (!tgt) {
        me->tell_me ("Enchant which armour?");
        return 0;
    }

    if (stringp (tgt)) {
        target = present (tgt, me);

        if (!target) {
            me->tell_me ("You don't have any \"" + tgt + "\"");
            return 0;
        }
    } else if (objectp (tgt)) {
        target = present (tgt, me);

        if (!target) {
            me->tell_me ("You don't have any \"" + tgt->query_name() + "\"");
            return 0;
        }
    } else {
        me->tell_me ("Enchant what?!");
        return 0;
    }

    if (!target->is_armour()) {
        me->tell_me (":%<it.capname>% is not an armour, so it can't be "
                     "enchanted this way.",
                     0, 0, 0, 0, target);
        return 0;
    }

    if (target->query_worn()) {
        me->tell_me(":You have to take off %<it.name>% first.",
                    0, 0, 0, 0, target);
        return 0;
    }

    me->tell_me ("You begin reciting the parchment scroll.");

    env = environment (me);

    data = ({ target, env });
    return 1;
}

int
end_invoke (object me, mixed *data)
{
    object ob, env, scroll;
    string n, tgt, t;
    int ac, v, m;

    ob  = data[0];
    env = data[1];

    if (env != environment (me)) {
        me->tell_me ("Your movement breaks your concentration!");
        return 0;
    }

    if (!ob || !present(ob, me)) {
        me->tell_me ("You've lost your target!");
        return 0;
    }

    if (ob->query_worn()) {
        me->tell_me(":You have to take off %<it.name>% first.",
                    0, 0, 0, 0, ob);
        return 0;
    }

    scroll = this_object();

    me->tell_me(":You recite %<it.name>% at %<him.name>%.", 0, 0, 0,
                ob, scroll);
    env->tell_here(
        ":%<me.capname>% recites %<him.name>% at %<it.name>%.",
	0, 0, ({ me }), me, scroll, ob);

    ac = (int)ob->query_ac();
    m = (int)ob->query_magic();
    t = (string)ob->query_type();
    v = (int)ob->query_value();

    // This only gives +1, OR, removes minor (-1) arcane curse (-1).

    if (((t == "armour") && (ac > 5))
        || ((t == "helmet") && (ac > 2))
        || ((t == "leggings") && (ac > 2))
        || ((t == "shield") && (ac > 2))
        || ((t == "amulet") && (ac > 2))
        || ((t == "belt") && (ac > 2))
        || ((t == "boots") && (ac > 2))
        || ((t == "bracers") && (ac > 2))
        || ((t == "cloak") && (ac > 2))
        || ((t == "gloves") && (ac > 2))
        || ((t == "mask") && (ac > 2))
        || ((t == "ring") && (ac > 2))
        || ob->is_blessed()
        || ob->is_cursed()
        || ob->query_psionic_energy()
        || ob->id("obsidian")
        || (m > 0)
        || (m < -2)
        || (random(101) > 97)) {
        env->tell_here(":%<it.capname>% glows briefly, but fades.",
                       0, 0, 0, 0, 0, ob);
    } else {
        m++;
        if (m > 0) v += 750;
        env->tell_here(":%<it.capname>% glows brightly for a moment!",
                       0, 0, 0, 0, 0, ob);
        ob->set_value(v);
        ob->set_magic(m);
        // We'll allow them to see the magic
        ob->add_identified_by(me);
    }

    return 1;
}

