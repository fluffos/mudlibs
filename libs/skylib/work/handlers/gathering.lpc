/**
 * Handler to handle the gathering of implicitly existing
 * objects that require some skill to find, such as herbs.
 * Recognition (ie, knowing what it is once you've found it) may be
 * added later.<p>
 * The data used for gathering comes from two places: the handler's
 * database of gatherable items, and the room's local information.<p>
 * The handler's database contains a class entry for each gatherable:<br>
 * <dl>
 * <dt> skill (string)
 * <dd> The skill needed to find the item.
 * <dt> difficulty (int)
 * <dd> The taskmaster difficulty.
 * <dt> upper (int)
 * <dd> The taskmaster "upper" parameter.
 * <dt> extra (mixed)
 * <dd> The taskmaster "extra" parameter.
 * <dt> season (string *)
 * <dd> The seasons during which the gatherable is available (eg, plants).
 * If this is unset, the default is all seasons.
 * Note that, currently, it is the same season everywhere on the Disc.
 * <dt> quant (int or function pointer returning an int)
 * <dd> The quantity that will be gathered.  The function pointer is
 * passed three parameters: the room, the player, and the name of the
 * gathered item.  This allows, for example, a function to be called
 * on the room to calculate the quantity, such as:
 * <pre><br>
 *     <code>(: $1->room_func($2, $3) :)</code>
 * </pre>
 * <dt> ob (string)
 * <dd> The pathname of the object to be created.  If the object is
 * continuous, the <i>amount</i> of ob is set to <i>quant</i>; otherwise,
 * <i>quant</i> copies of the object are cloned.
 * </dl><p>
 * The room's local information is set when the gatherable is added
 * via add_item(), and consists of:<p>
 * <dl>
 * <dt> item name (string or function pointer returning a string)
 * <dd> The name that will be used to look up the gatherable in the
 * handler's database.  The function pointer is passed two parameters
 * when evaluated: the room, and the player.
 * <dt> scarcity (int or function pointer returning an int)
 * <dd> The percent chance of finding any quantity of the gatherable.
 * This is an additional
 * constraint on finding the gatherable, in addition to any skill
 * requirements and quantity calculations.  A scarcity of 100 (the default)
 * indicates no scarcity constraint.  A scarcity of 0 means that the
 * gatherable will never be found.
 * </dl>
 * @author Jeremy
 */

#include <weather.h>
#include <tasks.h>

#define INIT_FILE "/obj/gatherables/handler.dat"

class item_data {
    string skill;          // skill needed to find this item
    int    difficulty;     // taskmaster difficulty
    int    upper;          // taskmaster "upper" parameter
    mixed  extra;          // taskmaster "extra" parameter
    string *season;        // available season(s)
    mixed  quant;          // quantity (int or (int)(:<code>:))
    string ob;             // filename of object to be created
}

mapping items = ([ ]);

void create() {
    seteuid("/secure/master"->creator_file(file_name(this_object())));
    items = "/handlers/data"->compile_data(({ INIT_FILE }));
} /* create() */

/**
 * This method will return an array of the information associated with
 * the item.  The array consists of:
 * <pre>
 *   ({
 *      skill,       // skill needed to find this item   (string)
 *      difficulty,  // taskmaster difficulty            (int)
 *      upper,       // taskmaster "upper" parameter     (int)
 *      extra,       // taskmaster "extra" parameter     (mixed)
 *      season,      // available season(s)              (string *)
 *      quant,       // quantity (int or (int)(:\<code\>:)) (mixed)
 *      ob           // filename of object to be created (string)
 *    })
 * </pre>
 * @return the item array as detailed above.
 * @param name the name of the item to query
 * @see add_item()
 */
mixed query_item( string name ) {
    class item_data h;

    if (!(items[name])) {
        return 0;
    }
    h = (class item_data)items[name];
    return ({ h->skill, h->difficulty, h->upper, h->extra, h->season,
              h->quant, h->ob });
} /* query_item() */

/**
 * This method adds an item into the current list of gatherable items.
 * @param name the name of the item to add
 * @param skill skill needed to find this item
 * @param diff taskmaster difficulty
 * @param upper taskmaster "upper" parameter
 * @param extra taskmaster "extra" parameter
 * @param season available season(s)
 * @param quant quantity (int or function pointer returning an int)
 * @param ob filename of object to be created
 * @see query_item()
 * @see gather_item()
 */
void add_item( string name, string skill, int diff, int upper, mixed extra,
               string *season, mixed quant, string ob ) {
    class item_data h;

    h = new( class item_data );
    h->skill = skill;
    h->difficulty = diff;
    h->upper = upper;
    h->extra = extra;
    h->season = season;
    h->quant = quant;
    h->ob = ob;
    items[name] = h;
} /* add_item() */

/**
 * This method returns all of the current gatherable items.  It returns
 * this as a mapping of a class, so probably not overly useful except
 * for debugging.
 * @return mapping of a locally defined class
 * @see query_item()
 * @see add_item()
 */
mapping query_items() {
    return items;
} /* query_items() */

/**
 * This method attempts to gather some items in the environment of
 * the specified player.
 * @param word the item to try and gather
 * @param player the player doing the gathering
 * @return an array of gathered objects
 * @see query_item()
 * @see add_item()
 */
object *gather_item( string word, object player ) {
    object env;
    object *basket = ({ }), *hidden, item;
    class item_data h;
    mixed *local_data;
    string name;
    int i, q, j, l, m, result, scarcity;

    if (!objectp(player)) return basket;
    env = environment(player);
    if (!objectp(env)) return basket;
    // Find what items are defined in here
    hidden = match_objects_for_existence( word, ({ env }) );
    if (!arrayp( hidden )) {
       return basket;
    }
    for (i = 0; i < sizeof( hidden ); i++) {
        // If it's an actual object lying here, gather it, too.  Otherwise
        // we may never get to the gatherable due to plural problems.
        if (environment(hidden[i]) == env) {
            basket += ({ hidden[i] });
            continue;
        }
        local_data = hidden[i]->query_gather();
        for (j = 0; j < sizeof(local_data); j++) {
            name = 0;
            scarcity = 100;
            for (l = 0; l < sizeof(local_data[j]); l += 2) {
                // More modifiers can be added as they are needed
                switch (local_data[j][l]) {
                case "item name":
                case "item_name":
                    name = evaluate(local_data[j][l+1], env, player);
                    if (!stringp(name))
                        name = 0;
                    break;
                case "scarcity":
                    scarcity = evaluate(local_data[j][l+1], env,
                                        player, name);
                    if (!intp(scarcity))
                        scarcity = 0;
                    break;
                default:
                }
            }
            if (random(100) >= scarcity)
                continue;
            if (!items[name])
              continue;
            h = items[ name ];
            if (arrayp( h->season ) && sizeof( h->season ))
                if (member_array( WEATHER->query_season(), h->season ) == -1)
                    continue;
            if (stringp( h->skill ))
                result = TASKER->attempt_task(h->difficulty,
                      player->query_skill_bonus(h->skill), h->upper, h->extra);
            else
                result = SUCCEED;
            switch ( result ) {
            case FAIL:
            case BARF:
                continue;
                break;
            case AWARD:
                player->add_skill_level(h->skill, 1, 0);
            default:
            }
            q = evaluate(h->quant, env, player, name);
            if (!q || !intp(q))
                continue;
            item = clone_object( h->ob );
#ifdef NO_DECAY
            item->set_decay_speed(0);
#endif
            if (item->query_continuous()) {
                item->set_amount(q);
                basket += ({ item });
            }
            else {
                basket += ({ item });
                for (m = 1; m < q; m++) {
                    basket += ({ clone_object( h->ob ) });
                }
            }
        } /* for (j...) */
    } /* for (i...) */
    return (basket + ({ }));
} /* gather_item() */
