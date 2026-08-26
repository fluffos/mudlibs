/**
 * A transport NPC, this will be a horse or a camel or whatever.
 * @author Pinkfish
 * @started Tue Sep 21 18:21:13 PDT 1999
 * @changed Fixed up a bunch of things and changed a fair bit
 * - Sandoz, Feb. 2002.
 */

inherit NPC_OBJ;

#include <move_failures.h>
#include <npc/transport.h>
#include <dirs.h>
#include <room.h>
#include <tasks.h>

/** @ignore yes */
#define DO_RUSTLE

/** @ignore yes */
#define WEAR_CMD "/cmds/living/wea_r"
/** @ignore yes */
#define GLANCE_CMD "/cmds/living/glance"

#define ADD_RIDE_COMMAND(xxx,yyy) { \
    TP->add_command( xxx, TO, "["+query_transport_type()+"] <string'direction'>", \
        (: do_ride( $4[0], yyy, "once") :) ); \
    TP->add_command( xxx, TO, "["+query_transport_type()+"] <string'direction'> "\
        "{once|forever|route|roughly|intersection|roughly-intersection}", \
        (: do_ride( $4[0], yyy, $4[1] ) :) ); \
    }

/** @ignore yes */
#define IS_ALLOWED(xxx) \
    if( !is_allowed_to_use( TP->query_name() ) ) { \
        TP->add_failed_mess( TO, xxx ); \
        return 0; \
    }

/**
 * This is the skill base for all the riding skills.
 */
#define TRANSPORT_SKILL_BASE "general.riding."

/**
 * This is the multiplier for the panicing in battle.
 */
#define TRANSPORT_PANIC_IN_BATTLE_MULTIPLIER 4

/**
 * This is the panicing for when the transport sees a battle
 * multiplier.
 */
#define TRANSPORT_PANIC_NORMAL_MULTIPLIER    1

/**
 * This is the panicing divisor for if the horse is riding past.  The
 * faster the horse rides the less the chance.  So we add the speed onto
 * this.
 */
#define TRANSPORT_PANIC_RIDING_DIVISOR       1

/**
 * This is the maximum length of the name the creature can be given.
 */
#define MAX_NAME_LEN                         16

/**
 * @ignore yes
 * These are the move flags for riding the transport.
 */
#define PATH_FOLLOW                          1
#define STOP_AT_INTERSECTION                 2
#define STOP_AFTER_MOVING_ONCE               4

void set_teathered_to( object ob );
object query_teathered_to();
int do_ride( string direction, int speed, string type );
void setup_movement();
int do_allow( string str );
int do_disallow( string str );
int do_list();
int do_name( string name );
int do_offer( object *food );
int do_dress( object *dress );
int do_teather( object *poles );
object* query_riders();
string query_transport_type();
int query_default_direction_difficulty();
int query_default_mount_difficulty();
int query_default_fight_difficulty();
void panic_horse( int multiplier );
void tell_riders( string str );
void set_transport_name( string name );

private int _cur_speed;
private int _cur_exhaustion;
private int _riding_flags;
private int _transport_id;
private string _owner;
private string _last_location;
private string _transport_name;
private string *_allowed;
private string *_route;
private string _cur_direction;
private string _teathered_to_short;
private nosave object _teathered_to;
private nosave object _in_long;
private nosave object _env_repeater;
private nosave object _me_repeater;
private nosave object *_riding;
private nosave int _transport_speed;
private nosave int _max_speed;
private nosave int _max_exhaustion;
private nosave int _move_id;
private nosave int _default_mount_difficulty;
private nosave int _default_direction_difficulty;
private nosave int _default_fight_difficulty;
private nosave int _panic;
private nosave int _last_move;
private nosave int _last_panic;
private nosave string _transport_type;
private nosave string _inside_long;

void create() {
    _max_speed = RIDE_WALK;
    _cur_speed = RIDE_NOT_MOVING;

    _transport_speed = 4;

    _max_exhaustion = 100;
    _cur_exhaustion = 100;

    _riding = ({ });

    _default_direction_difficulty = 500;
    _default_mount_difficulty = 300;
    _default_fight_difficulty = 50;

    add_property("unique", 1 );
    add_property("no_teleport", 1 );

    ::create();

    add_extra_look(TO);

} /* create() */

/** @ignore yes */
string *query_help_files() {
    string *ret;

    if( pointerp( ret = ::query_help_files() ) )
        return ret + ({"mount"});

    return ({"mount"});

} /* query_help_files() */

/** @ignore yes */
int test_add( object ob, int flag ) { return 1; }

/** @ignore yes */
int test_remove( object ob, int flag, mixed dest ) { return 1; }

/** @ignore yes */
void init() {
    string str;

    ::init();

    str = query_name();

    TP->add_command("name", TO, "<direct:living'"+str+"'> as <string'name'>",
        (: do_name($4[1]) :) );

    TP->add_command("mount", TO, "<direct:living>'"+str+"'");
    TP->add_command("dismount", TO, "["+query_transport_type()+"]");

    TP->add_command("allow", TO,
        "<word'player'> to use <direct:living'"+str+"'>",
        (: do_allow($4[0]) :) );
    TP->add_command("allow", TO, "list <direct:living'"+str+"'>",
        (: do_list() :) );
    TP->add_command("disallow", TO,
        "<word'player'> from using <direct:living'"+str+"'>",
        (: do_disallow($4[0]) :) );

    ADD_RIDE_COMMAND("walk", RIDE_WALK );

    if( _max_speed >= RIDE_TROT )
        ADD_RIDE_COMMAND("trot", RIDE_TROT );

    if( _max_speed >= RIDE_CANTER )
        ADD_RIDE_COMMAND("canter", RIDE_CANTER );

    if( _max_speed >= RIDE_GALLOP )
        ADD_RIDE_COMMAND("gallop", RIDE_GALLOP );

    TP->add_command("stop", TO, str);
    TP->add_command("lead", TO, "<direct:living'"+str+"'>");

    TP->add_command("teather", TO,
        "<direct:living'"+str+"'> to <indirect:object>",
        (: do_teather($1) :) );
    TP->add_command("unteather", TO, "<direct:living'"+str+"'>");
    TP->add_command("untie", TO, "<direct:living'"+str+"'>");

    TP->add_command("dress", TO,
        "<direct:living'"+str+"'> {with|in} <indirect:object'garment'>",
        (: do_dress($1) :) );

    TP->add_command("offer", TO,
        "<indirect:object:me'food'> to <direct:living'"+str+"'>",
        (: do_offer($1) :) );

#ifdef DO_RUSTLE
    if( _owner )
        TP->add_command("rustle", TO, "<direct:living'"+str+"'>");
#endif

} /* init() */

/** @ignore yes */
varargs mixed query_contents( string start, object *things, int ignore_liv ) {
    if( !arrayp( things ) ) {
        things = TO->find_inv_match("", TP ) - ({ TP });
        things = filter_array( things, (: ENV($1) == TO :) );
    }

    if( !sizeof( things ) )
        return "";

    if( _in_long )
        things -= ({ _in_long });

    if( !sizeof(things) )
        return 0;

    return ({ ::query_contents( start, things, ignore_liv ), "Ridden by" });

} /* query_contents() */

/**
 * This method returns the string giving some indication about how tired
 * the horse it.
 * @return the exhaustion string of the horse
 */
string query_exhaustion_string() {
    string start;

    start = CAP( HE );

    switch (_cur_exhaustion * 6 / _max_exhaustion) {
      case 5 :
        return start + " looks wonderfully happy and totally rested.\n";
      case 4 :
        return start + " looks a little tired.\n";
      case 3 :
        return start + " looks quite tired.\n";
      case 2 :
        return start + " looks really tired.\n";
      case 1 :
        return start + " looks exhausted.\n";
      case 0 :
        return start + " is totally exhausted.\n";
    }

} /* query_exhaustion_string() */

/** @ignore yes */
string extra_look() { return query_exhaustion_string(); }

/** @ignore yes */
string long( string fluff, int dark ) {
    string str;

    str = "";

    if( ENV(TP) == TO ) {
        // They are in the horse...
        _in_long = TP;

        if( _inside_long ) {
            str += "You are riding on:\n"+::long( fluff, dark );
        } else {
            str += "You are riding on:\n"+_inside_long+
                   query_exhaustion_string();
        }

        _in_long = 0;

        str += "Around " + the_short() + " is:\n";
        str += ( ENV(TO) ? ENV(TO)->long( fluff, dark ) :
            "%^RED%^Limbo! Wandered into an inherit, did we?%^RESET%^\n");

    } else {
        str += ::long( fluff, dark );
    }

    return str;

} /* long() */

/** @ignore yes */
string pretty_short( object player, int no_riding ) {
    string str;

    if( sizeof( _riding - ({ player }) ) && !no_riding ) {
        str = query_multiple_short( _riding - ({ player }) );
        str = player->convert_message(str);
        if( _transport_name ) {
            return str + " riding " + ::pretty_short();
        } else {
            return str + " riding " + add_a( ::pretty_short() );
        }
    }

    return ::pretty_short();

} /* pretty_short() */

/** @ignore yes */
object query_mirror_room() { return ENV(TO); }

/**
 * This method sets the owner of the transport.  This should be used
 * when the owner is changed.
 * @param owner the new owner of the transport
 */
void set_owner( string owner ) {
    int *ids, i;
    string classif;
    object ob;


    // Remove the effect off the old owner and add it to the new one.
    if( _owner && ( ob = find_player(_owner) ) ) {
        classif = TRANSPORT_OWNER_EFFECT->query_classification();
        ids = ob->effects_matching(classif);

        foreach( i in ids )
            TRANSPORT_OWNER_EFFECT->remove_owner( ob, ob->arg_of( i ), i, TO );
    }

    _owner = owner;

    if( _owner && ( ob = find_player(_owner) ) )
        ob->add_effect( TRANSPORT_OWNER_EFFECT, TO );

} /* set_owner() */

/**
 * This method sets the id of the transpot.
 * @param id the id of the transport
 */
void set_transport_id( int id ) { _transport_id = id; }

/**
 * This method returns the id of the transport.
 * @return the id of the transport
 */
int query_transport_id() { return _transport_id; }

/**
 * This method returns the current owner of the transport.
 * @return the current owner of the transport
 */
string query_owner() { return _owner; }

/**
 * This method returns the current owner of the transport, it is used by the
 * pk checking code to make sure that this horse can be used in exciting
 * pk ways.
 * @return the owner
 */
string query_owner_pk_check() { return query_owner(); }

/**
 * This method sets the inside long of the horse.  This is what people
 * will see when they are inside a horse.
 * @param long the inside of the long of the horse
 */
void set_inside_long( string long ) { _inside_long = long; }

/**
 * This method returns the inside long of the horse.
 * @return the inside long of the horse
 */
string query_inside_long() { return _inside_long; }

/**
 * This method sets the maximum exhaustion points for the transport.
 * @param exhaust the maximum exhaustion points
 */
void set_maximum_exhaustion( int num ) {
    _max_exhaustion = num;
    _cur_exhaustion = num;
} /* set_maximum_exhaustion() */

/**
 * This method returns the maximum exhaustion points for the transport.
 * @return the maximum exhaustion points
 */
int query_maximum_exhaustion() { return _max_exhaustion; }

/**
 * This method returns the current exhaustion points for the transport.
 * @return the current exhaustion points
 */
int query_current_exhaustion() { return _cur_exhaustion; }

/**
 * This method sets the current exhaustion points for the transport.
 * @param points the current exhaustion points
 */
int set_current_exhaustion( int points ) { _cur_exhaustion = points; }

/**
 * This method sets the maximum speed for the transport.
 * @param the maximum speed
 * @return 1 if successful, 0 on invalid speed
 */
int set_maximum_speed( int speed ) {
    if( speed < RIDE_WALK || speed > RIDE_GALLOP )
        return 0;

    _max_speed = speed;

    return 1;

} /* set_maximum_speed() */

/**
 * This method queries the maximum speed for the transport.
 * @return the maximum speed for the transport
 */
int query_maximum_speed() { return _max_speed; }

/**
 * This method returns the string associated with the specified speed.
 * @param speed the speed to check
 * @param panic if the horse is panicing
 * @return the name of the speed
 */
string query_speed_string( int speed, int panic ) {
    if( panic )
        return "flee";

    switch( speed ) {
      case RIDE_WALK :
        return "walk";
      case RIDE_CANTER :
        return "canter";
      case RIDE_GALLOP :
        return "gallop";
      case RIDE_TROT :
        return "trot";
      default :
        return "unknown speed";
    }

} /* query_speed_string() */

/**
 * This method expands the name of the direction.
 * @param dir the direction to expand
 * @return the expanded name
 */
string expand_direction( string dir ) { return LENGTHEN[dir] || dir; }

/**
 * This method checks to see if the specified person is allowed to do
 * things to this transport.
 * @param name the name of the person to check
 * @return 1 if they can do things, 0 if not
 */
int is_allowed_to_use( string name ) {
    if( _owner )
        return name == _owner || ( sizeof(_allowed) &&
               member_array( name, _allowed ) != -1 );

    return 0;

} /* is_allowed_to_use() */

/**
 * Mount the horse!
 * @return 1 on success, 0 on failure
 */
int do_mount() {
    class task_class_result result;
    int ret, difficulty;
    object worn;
    string *str, pre;

    IS_ALLOWED("You are not the owner and are not allowed to use $D.\n");

    if( ENV(TP) == TO ) {
        TP->add_failed_mess( TO, "You are already mounted on $D.\n");
        return 0;
    }

    // Diffulty is the default plus any modifiers for what the horse is
    // wearing (ie: saddle).
    difficulty = query_default_mount_difficulty();

    foreach( worn in query_wearing() )
        if( worn->query_mount_difficulty_adjustment() )
            difficulty -= worn->query_mount_difficulty_adjustment();

    if( difficulty < 1 )
        difficulty = 1;

    // First lets do a skill check.
    result = TASKMASTER_H->perform_task( TP,
             TRANSPORT_SKILL_BASE + query_transport_type(),
             difficulty, TM_FREE, 1 );

    switch( result->result ) {
      case AWARD :
        write("%^YELLOW%^You feel more able to climb onto "+the_short()+
            ".\n%^RESET%^");
      case SUCCEED :
        if( ret = TP->move(TO) ) {
            switch( ret ) {
              case MOVE_TOO_HEAVY :
                TP->add_failed_mess( TO, "You are unable to mount $D because "
                    "you are too heavy for "+HIM+".\n");
              break;
              default :
                TP->add_failed_mess( TO, "You are unable to mount $D for some "
                    "reason ("+ret+").\n");
              break;
            }
            return 0;
        }

        switch( result->degree ) {
          case 0..10 :
            str = ({ "You grab the back of $D and heave yourself onto the "
                     "creature with some difficulty, barely managing to keep "
                     "your balance.\n",
                     "$N grab$s the back of $D and heave$s $oself onto the "
                     "creature in a display of uncertain movements, then "
                     "wobble$s for a moment, but regains $p balance.\n"});
          break;
          case 11..40 :
            str = ({ "You grab the back of $D and heave yourself onto the "
                     "creature.\n",
                     "$N grab$s the back of $D and heave$s $oself onto the "
                     "creature.\n"});
          break;
          case 41..80 :
            str = ({ "You grab the back of $D and effortlessly heave yourself "
                     "onto the creature.\n",
                     "$N grab$s the back of $D and effortlessly heave$s "
                     "$oself onto the creature.\n"});
          break;
          default :
            str = ({ "You grab the back of $D and swing yourself onto the "
                     "creature in a display of skill.\n",
                     "$N grab$s the back of $D and swing$s $oself onto the "
                     "creature in a display of skill.\n"});
        }

        TP->add_effect( TRANSPORT_EFFECT, TO );
        TP->add_succeeded_mess( TO, str );

        return 1;

      case FAIL :
        pre = "You attempt to get onto $D, but ";
        switch( result->degree ) {
          case -1000..-71 :
            str = ({ pre + "fail to figure out how to even begin.\n",
                     "$N stare$s at $D with a stupefied expression.\n"});
          break;
          case -70..-41 :
            str = ({ pre + "your grasp of the back of the creature slips "
                     "before you even start to climb.\n",
                     "$N grasp$s the back of $D as if attempting to mount "+
                     HIM+", but fail$s to get a proper hold.\n"});
          break;
          case -40..-16 :
            str = ({ "You grab the back of $D, but don't quite manage to "
                     "heave yourself onto the creature.\n",
                     "$N grab$s the back of $D, but fail$s to heave $oself "
                     "onto the creature.\n"});
          break;
          default :
            str = ({ "You grab the back of $D and heave yourself onto the "
                     "creature, but just as you are done, you lose your "
                     "balance and slide down the other side.\n",
                     "$N grab$s the back of $D and heave$s $oself onto the "
                     "creature, but slide$s down the other side after a "
                     "moment of wobbling.\n"});
        }

        TP->add_succeeded_mess( TO, str );
        return 1;
    }

} /* do_mount() */

/**
 * This method returns whether or not we are following a path.
 * @return 1 if we are following a path, 0 if not
 */
int query_path_follow() { return _riding_flags & PATH_FOLLOW; }

/**
 * This method returns whether or not we should stop at an intersection.
 * @return 1 if we should stop at an intersection, 0 if not
 */
int query_stop_at_intersection() {
    return _riding_flags & STOP_AT_INTERSECTION;
} /* query_stop_at_intersection() */

/**
 * This method returns whether or not we should stop after moving once.
 * @return 1 if we should stop after moving once, 0 if not
 */
int query_stop_after_moving_once() {
    return _riding_flags & STOP_AFTER_MOVING_ONCE;
} /* query_stop_at_intersection() */

/**
 * Ride the horse off into the sunset.
 * @return 1 on success, 0 on failure
 */
int do_ride( string dir, int speed, string type ) {
    string *route;

    if( ENV(TP) != TO ) {
        TP->add_failed_mess( TO, "You must mount $D before you "
            "can ride anywhere on "+HIM+".\n");
        return 0;
    }

    dir = expand_direction(dir);

    _cur_direction = dir;
    _cur_speed = speed;
    _last_location = 0;
    _riding_flags = 0;
    _route = 0;

    switch( type ) {
      case "intersection" :
      case "once" :
      case "forever" :
        // Check to see if the exit exists in that direction.
        if( ENV(TO)->query_destination(dir) == VOID_ROOM ) {
            TP->add_failed_mess( TO, "There is no exit in the direction '"+
                dir+"'.\n");
            return 0;
        }
      break;
      case "route" :
        route = map( explode( replace_string( dir, " ", ""), ",") - ({ 0 }),
                (: expand_direction($1) :) );

        if( !sizeof(route) ) {
            TP->add_failed_mess( TO, "Who are you kidding?  $C$$D is only "
                "capable of following sensible routes.\n");
            return 0;
        }

        if( ENV(TO)->query_destination(route[0]) == VOID_ROOM ) {
            TP->add_failed_mess( TO, "There is no exit in the direction '"+
                route[0]+"'.\n");
            return 0;
        }

        _route = route;

      break;
      case "roughly" :
      case "roughly-intersection" :
        if( member_array( dir, ({"north", "northeast", "east", "southeast",
            "south", "southwest", "west", "northwest"}) ) == -1 ) {
            TP->add_failed_mess( TO, "You can only $V roughly towards the "
                "north, northeast, east, southeast, south, southwest, west "
                "or northwest.\n");
            return 0;
        }
      break;
      default :
    }

    switch( type ) {
      case "roughly" :
        _riding_flags = PATH_FOLLOW;
      break;
      case "intersection" :
        _riding_flags = STOP_AT_INTERSECTION;
      break;
      case "once" :
        _riding_flags = STOP_AFTER_MOVING_ONCE;
      break;
      case "roughly-intersection" :
        _riding_flags = PATH_FOLLOW | STOP_AT_INTERSECTION;
      break;
      case "route" :
        _cur_direction = 0;
      break;
      case "forever" :
      break;
      default :
        _riding_flags = STOP_AFTER_MOVING_ONCE;
    }

    TP->add_succeeded_mess( TO, ({"You start to "+
        query_speed_string( _cur_speed, _panic )+" $D.\n", ""}) );

    setup_movement();
    return 1;

} /* do_ride() */

/**
 * Stop the transport from running off.
 * @return 1 on success, 0 on failure
 */
int do_stop() {
    if( _cur_speed == RIDE_NOT_MOVING ) {
        TP->add_failed_mess( TO, "$D is not moving.\n");
        return 0;
    }

    // I want a skill check here, perhaps we would succeed in calming
    // down the mount. - Sandoz
    if( _panic ) {
        TP->add_failed_mess( TO, "$D is currently panicing and unable "
            "to be stopped.\n");
        return 0;
    }

    _cur_speed = RIDE_NOT_MOVING;
    remove_call_out(_move_id);

    TP->add_succeeded_mess( TO, "$N $V $D.\n");
    return 1;

} /* do_stop() */

/**
 * This is used to get off the horse the easy way.
 * @return 1 on success, 0 on failure
 */
int do_dismount() {
    int ret;

    if( ENV(TP) != TO ) {
        TP->add_failed_mess( TO, "You need to be mounted on $D to "
            "dismount.\n");
        return 0;
    }

    if( !ENV(TO) ) {
        TP->add_failed_mess( TO, "You cannot dismount $D for "+
            HE+" is in limbo.  Looks like you need professional help.\n");
        return 0;
    }

    if( ret = TP->move( ENV(TO) ) ) {
        TP->add_failed_mess( TO, "You failed to dismount $D for some "
            "reason ("+ret+").\n");
        return 0;
    }

    if( _cur_speed )
        do_stop();

    if( _panic ) {
        tell_object( TP, "You throw yourself from "+the_short()+" who is "
            "still panicing.\n");
        tell_room( ENV(TO), TP->the_short()+" throws "+HIM+"self from "+
            the_short()+" who is panicing.\n", ({ TP }) );
    } else {
        tell_object( TP, "You dismount from "+the_short()+".\n");
        tell_room( ENV(TO), TP->the_short()+" dismounts from "+
            the_short()+".\n", ({ TP }) );
    }

    TP->add_succeeded_mess( TO, "");
    return 1;

} /* do_dismount() */

#ifdef DO_RUSTLE
/**
 * This method will attempt to get the horse rustled by some nasty
 * pk person.
 * @return 1 on success, 0 on failure
 */
int do_rustle() {
    object *bing;

    // We need skill checks here.
    // - Sandoz.
    if( !_owner ) {
        set_owner( TP->query_name() );
        write("You successfuly rustle "+the_short()+".\n");
        do_mount();
        return 1;
    }

    if( _owner == TP->query_name() ) {
        TP->add_failed_mess( TO, "You already own $D.\n");
        return 0;
    }

    if( !pk_check( _owner, TP, 1 ) ) {
        // Ok, so they are pkable...
        if( sizeof(query_riders()) ) {
            bing = query_riders();
            TP->add_failed_mess( TO, "It is rather hard to rustle $D when $I "+
                ( sizeof(bing) > 1 ? "are" : "is")+" sitting on "+HIM+".\n", bing );
            return 0;
        }


        // Do the rustle...
//      event( ENV(TP), "theft", TO, TP, find_player(_owner), ({ TO }) );
        TO->set_owner( TP->query_name() );
        return 1;
    }

    TP->add_failed_mess( TO, "Both you and the owner of $D must be "
        "playerkillers in order to rustle the creature.\n");
    return 0;

} /* do_rustle() */
#endif

/**
 * This method puts stuff on the horse, like saddle bags, saddles and things.
 * @param obs the objects to try and dress the horse in
 */
int do_dress( object* obs ) {
    object *good, *bad, blue, old_env;
    mapping errors;
    string result;

    IS_ALLOWED("You are not the owner and are not allowed to use $D.\n");

    // First check to make sure they are for the right race.
    good = filter( obs, (: $1->query_wearable() &&
           $1->query_worn_by_race() == query_race() :) );

    if( !sizeof(good) ) {
        TP->add_failed_mess( TO, "$I cannot be worn by $D.\n", obs );
        return 0;
    }

    bad = ({ });
    errors = ([ ]);

    foreach( blue in good ) {
        // Make sure they can wear it first.
        if( result = WEAR_CMD->can_wear_or_remove( blue, TO ) ) {
            result = replace_string( result, "you ", HE+" ");
            if( !errors[result] )
                errors[result] = ({ blue });
            else
                errors[result] += ({ blue });
            good -= ({ blue });
        } else {
           old_env = ENV(blue);
           if( !blue->move(TO) ) {
               if( result = wear_armour( blue, 0 ) ) {
                   result = replace_string( result, "you ", HE+" ");
                   if( !errors[result] )
                       errors[result] = ({ blue });
                   else
                       errors[result] += ({ blue });
                   blue->move(old_env);
                   good -= ({ blue });
               }
           } else {
               result = "could not be moved into "+HIS+" inventory";
               if( !errors[result] )
                   errors[result] = ({ blue });
               else
                   errors[result] += ({ blue });
               good -= ({ blue });
           }
        }
    }

    if( !sizeof(good) ) {
        foreach( result, bad in errors )
            TP->add_failed_mess( TO, "You cannot dress $D with $I, because "+
                ( query_group( bad ) ? "they" : "it")+" "+result+".\n", bad );
    } else {
        TP->add_succeeded_mess( TO, "$N $V $D with $I.\n", good );
    }

    return sizeof(good) > 0;

} /* do_dress() */

/**
 * This sets up the horse for being led.  Basically it just makes the
 * horse follow you.
 * @return 1 on success, 0 on failure
 */
int do_lead() {
    IS_ALLOWED("You are not the owner and are not allowed to lead $D.\n");
    return command("follow " + TP->query_name() );
} /* do_lead() */

/**
 * This sets the horses name.
 * @param name the name to set the horse to
 * @return 1 on success, 0 on failure
 */
int do_name( string name ) {
    string str;

    if( query_owner() != TP->query_name() ) {
        TP->add_failed_mess( TO, "Sorry, only the owner can change the name "
            "of $D.\n");
        return 0;
    }

    str = lower_case(name);

    if( sizeof(name) > MAX_NAME_LEN ) {
        TP->add_failed_mess("Sorry, the maximum length of the name you can "
            "give $D is "+query_num(MAX_NAME_LEN)+" characters.\n");
        return 0;
    }

    if( sscanf( str, "%*scyber%*s") == 2 ||
        sscanf( str, "%*spenis%*s") == 2 ||
        sscanf( str, "%*scock%*s") == 2 ||
        sscanf( str, "%*spussy%*s") == 2 ||
        sscanf( str, "%*sfuck%*s") == 2 ||
        sscanf( str, "%*sshit%*s") == 2 ||
        sscanf( str, "%*sdragon%*s") == 2 ||
        sscanf( str, "%*sfish%*s") == 2 ||
        sscanf( str, "%*spimp%*s") == 2 ||
        sscanf( str, "%*skiller%*s") == 2 ||
        sscanf( str, "%*sslayer%*s") == 2 ) {
        TP->add_failed_mess( TO, "Sorry, you cannot name $D as '"+
            name+"'.\n");
        return 0;
    }

    if( PLAYER_H->test_user(str) ) {
        TP->add_failed_mess( TO, "You cannot name $D as '"+name+"', because "
            "it is the name of a player.\n");
        return 0;
    }

    if( PLAYER_H->test_banished(str) ) {
        TP->add_failed_mess( TO, "You cannot name $D as '"+name+"'.\n");
        return 0;
    }

    str = TP->convert_message( the_short() );
    set_transport_name(name);
    TP->add_succeeded_mess( TO, "$N set$s the name of "+str+" to "+
        name+".\n");

    return 1;

} /* do_name() */

/**
 * This sets the horses name.
 * @param name the name to set the horse to
 * @return 1 on success, 0 on failure
 */
int do_offer( object *food ) {
    object *ok, *last, ob;

    IS_ALLOWED("Sorry, only the owner can offer food to $D.\n");

    ok = filter( food, (: $1->query_edible() ||
        ( $1->query_liquid() && $1->query_continuous() ) :) );
    last = ({ });

    foreach( ob in ok ) {
        if( ob->do_eat(1) == 2 ) {
            last += ({ ob });
            ok -= ({ ob });
        }
    }

    if( !sizeof(ok) && !sizeof(last) ) {
        TP->add_failed_mess( TO, "You cannot offer $I to $D, because it is "
            "not food.\n", food );
        return 0;
    }

    if( sizeof(last) )
        TP->add_succeeded_mess( TO, "$N $V $I to $D, who munches happily on "
            "the last of it.\n", last );

    if( sizeof(ok) )
        TP->add_succeeded_mess( TO, "$N $V $I to $D, who munches on it "
            "happily.\n", ok );

    return 1;

} /* do_offer() */

/**
 * This allows someone to use the horse.
 * @param person the person to allow
 * @return 1 if successful, 0 if not
 */
int do_allow( string person ) {
    int i;

    if( TP->query_name() != _owner ) {
        TP->add_failed_mess( TO, "You are not the owner of $D and cannot "
            "change "+HIS+" allow list.\n");
        return 0;
    }

    person = lower_case(person);

    if( person == _owner ) {
        TP->add_failed_mess( TO, "You are the owner of $D and don't need to "
            "be added to "+HIS+" allow list.\n");
        return 0;
    }

    if( sizeof( person ) > 20 || !PLAYER_H->test_user( person ) ) {
        TP->add_failed_mess( TO, "There is no such player - "+
            CAP(person)+".\n");
        return 0;
    }

    if( !i = sizeof( _allowed ) ) {
        _allowed = ({ person });
    } else {
        if( member_array( person, _allowed ) != -1 ) {
            TP->add_failed_mess( TO, CAP(person)+" is already allowed to "
                "ride $D.\n");
            return 0;
        }

        if( i >= 10 ) {
            TP->add_failed_mess( TO, "Sorry, you cannot allow more than ten "
                "people to ride $D.\n");
            return 0;
        }

        _allowed += ({ person });
    }

    TP->add_succeeded_mess( TO, ({"You allow "+CAP(person)+" to ride $D.\n",
        ""}) );
    return 1;

} /* do_allow() */

/**
 * This disallows someone to use the horse.
 * @param person the person to disallow
 * @return 1 if successful, 0 if not
 */
int do_disallow( string person ) {
    if( TP->query_name() != _owner ) {
        TP->add_failed_mess( TO, "You are not the owner of $D and cannot "
            "change "+HIS+" allow list.\n");
        return 0;
    }

    person = lower_case(person);

    if( person == _owner ) {
        TP->add_failed_mess( TO, "You cannot disallow yourself from riding "
            "$D, because you are the owner of the creature.\n");
        return 0;
    }

    if( !sizeof(_allowed) ) {
        TP->add_failed_mess( TO, "No-one but you are allowed to ride $D.\n");
        return 0;
    }

    if( member_array( person, _allowed ) == -1 ) {
        TP->add_failed_mess( TO, CAP(person)+" is already not allowed to "
            "ride $D.\n");
        return 0;
    }

    _allowed -= ({ person });

    TP->add_succeeded_mess( TO, ({"You disallow "+CAP(person)+" from "
        "riding $D.\n", ""}) );

    return 1;

} /* do_disallow() */

/**
 * This method lists the people currently able to use your transports.
 * @return 1 on success, 0 on failure
 */
int do_list() {
    if( TP->query_name() != _owner ) {
        TP->add_failed_mess( TO, "You are not the owner of $D and cannot "
            "view "+HIS+" allow list.\n");
        return 0;
    }

    if( !sizeof(_allowed) )
        TP->add_succeeded_mess( TO, ({"No-one but you are currently allowed "
            "to ride $D.\n", ""}) );
    else
        TP->add_succeeded_mess( TO, ({ query_multiple_short( map(
            asort( _allowed ), (: CAP($1) :) ) )+" "+( sizeof(_allowed) == 1 ?
            "is" : "are")+" currently allowed to ride $D.\n", ""}) );

    return 1;

} /* do_list() */

/**
 * This method is used to teather the mount to something.
 * The horse must be wearing something that responds to the id 'teather'.
 * @param obs the thing to teather us too
 * @return 1 on success, 0 on failure
 */
int do_teather( object *obs ) {
    object *teathers, *to;

    IS_ALLOWED("Sorry, only the owner can teather $D.\n");

    teathers = filter( query_wearing(),
        (: $1->query_property(TRANSPORT_TEATHER_PROP) :) );

    if( !sizeof(teathers) ) {
        TP->add_failed_mess( TO, "$D $V$0=does,do$V$ not have anything for "
            "you to teather "+verbalize("them", HIM )+" with.\n");
        return 0;
    }

    if( sizeof(obs) > 1 ) {
        TP->add_failed_mess( TO, "You cannot teather "+the_short()+" to more "
            "than one thing.\n", obs );
        return 0;
    }

    to = filter( obs, (: !living($1) && ENV($1) == ENV(TO) &&
         ( $1->query_property(TRANSPORT_TEATHER_PROP) ||
           $1->id("pole") ) :) );

    if( !sizeof(to) ) {
        TP->add_failed_mess( TO, "You cannot teather "+the_short()+" to "
            "$I.\n", obs );
        return 0;
    }

    // Set us up to be teathered to something.
    set_teathered_to( to[0] );

    TP->add_succeeded_mess( TO, "$N $V $D to $I.\n", to );
    return 1;

} /* do_teather() */

/**
 * This method unteathers the mount if it is teathered to something.
 * @return 1 on success, 0 on failure
 */
int do_unteather() {
    object teather;

    if( !teather = query_teathered_to() ) {
        TP->add_failed_mess( TO, "You cannot unteather $D because "+
            verbalize("they aren't", HE+" isn't")+" teathered.\n");
        return 0;
    }

    IS_ALLOWED("Sorry, only the owner can unteather $D.\n");

    set_teathered_to(0);

    TP->add_succeeded_mess("$N $V $D from $I.\n", ({ teather }) );
    return 1;

} /* do_unteather() */

/**
 * This method is called when ever someone we are following causes us to
 * move.
 */
int check_doing_follow( object thing, string verb, string special ) {
    int exhaust;

    exhaust = time() - _last_move;
    if( !exhaust ) {
        exhaust = _max_speed;
    } else if( exhaust < _transport_speed ) {
        exhaust = _transport_speed / exhaust;
    } else {
        exhaust = 1;
    }

    // Let the exhaustion go down a lot slower when being led as opposed
    // to ridden.
    exhaust--;

    // Try and figure out how much exhaustion this move should give the
    // horse..
    if( _cur_exhaustion < exhaust * exhaust ) {
        tell_room( TO, the_short()+" looks too tired to move.\n");
        tell_object( thing, the_short()+" is too tired to follow you.\n");
        return 0;
    }

    _cur_exhaustion -= exhaust * exhaust;
    return 1;

} /* check_doing_follow() */

/** @ignore yes */
protected void inform_of_move( string dir ) {
    object ob;
    int dark;

    foreach( ob in query_riders() ) {
        dark = ob->check_dark( ENV(TO)->query_light() );
        tell_object( ob, "You "+query_speed_string( _cur_speed, _panic )+" "+
            dir+" on "+the_short()+".\n");
        if( ob->query_verbose("look") ) {
            tell_object( ob, ENV(TO)->long( 0, dark ) );
        } else {
            tell_object( ob, GLANCE_CMD->room_glance( ob, ENV(TO), dark ) );
        }
    }

} /* inform_of_move() */

/**
 * This returns the list of directions the transport can currently
 * move from this location.  It takes in account things like size and
 * if the exit is obvious or not.
 * @param no_last don't go back where we came from
 */
string *query_allowed_directions( int no_last ) {
    mixed dest_other, data;
    string *ret;
    int i;

    dest_other = ENV(TO)->query_dest_other();
    ret = ({ });

    for( i = sizeof( dest_other ) - 2; i > -1; i -= 2 ) {
        data = dest_other[ i + 1 ];

        if( data[ROOM_OBV] && !data[ROOM_REL] &&
            data[ROOM_SIZE] >= query_height() &&
            !( no_last && data[ROOM_DEST] == _last_location ) )
            ret += ({ dest_other[ i ] });
    }

    return ret;

} /* query_allowed_directions() */

private string do_move_direction( string direction ) {
    int difficulty, result;
    object worn;
    string *allowed, new_direction;

    allowed = query_allowed_directions(1);

    // No such exit at all.
    if( member_array( direction, allowed ) == -1 )
        return 0;

    // They could go in a different direction!
    if( sizeof(allowed) > 1 )
        new_direction = choice( allowed );

    if( new_direction && !_panic ) {
        // Difficulty is the default plus any modifiers for what the horse is
        // wearing (ie: saddle).
        difficulty = query_default_direction_difficulty();

        foreach( worn in query_wearing() ) {
            if( worn->query_direction_difficulty_adjustment() )
                difficulty -= worn->query_mount_difficulty_adjustment();
        }

        if( difficulty < 1 )
            difficulty = 1;

        // First lets do a skill check.
        result = TASKMASTER_H->perform_task( TP,
                 TRANSPORT_SKILL_BASE + query_transport_type(),
                 difficulty, TM_FREE );

        switch( result ) {
          case AWARD :
            tell_object( TP, "%^YELLOW%^You feel more able to direct "+
                the_short()+" than ever before.\n%^RESET%^");
          case SUCCEED :
          break;
          case FAIL :
            if( new_direction == direction ) {
                write("You fail totally in your attempt to direct "+
                    the_short()+" to the "+direction+", but "+
                    HE+" decides to wander there anyway.\n");
            } else {
                write("You attempt to move "+the_short()+" to the "+
                    direction+", but "+HE+" attempts to wander off to the "+
                    new_direction+" instead.\n");
                direction = new_direction;
            }
          break;
        }
    }

   command(direction);
   return direction;

} /* do_move_direction() */

/**
 * This method turns a standard direction into a number.
 * @param direction the direction to turn into a number
 * @return the number associated with the direction
 */
int query_direction_as_number( string direction ) {
    switch( direction ) {
      case "north" :
        return 0;
      case "northeast" :
        return 1;
      case "east" :
        return 2;
      case "southeast" :
        return 3;
      case "south" :
        return 4;
      case "southwest" :
        return 5;
      case "west" :
      return 6;
      case "northwest" :
        return 7;
      default :
        return -1;
   }
} /* query_direction_as_number() */

private int query_direction_weight( string direction ) {
    int weight, direction_num, dest_num, dist;
    mixed stuff;

    stuff = ENV(TO)->query_dest_other(direction);
    weight = stuff[ROOM_SIZE];

    if( stuff[ROOM_DEST] == _last_location )
        weight -= 100;

    direction_num = query_direction_as_number(direction);
    dest_num = query_direction_as_number(_cur_direction);

    if( direction_num != -1 && dest_num != -1 ) {
        if( dest_num > direction_num ) {
            dist = dest_num - direction_num;
            if( dist > 4 )
                dist = direction_num + 8 - dest_num;
        } else {
            dist = direction_num - dest_num;
            if( dist > 4 )
                dist = dest_num + 8 - direction_num;
        }
        weight += ( 4 - dist ) * 75;
    }

    return weight;

} /* query_direction_weight() */

private int do_actual_move() {
    string *exits, highest_exit, str;
    int highest_weight, weight;
    object old;

    old = ENV(TO);

    // A route to follow.
    if( sizeof(_route) && !_cur_direction && !_panic ) {
        str = _route[0];
        _route = _route[1..];

        if( str = do_move_direction(str) ) {
            // Tell all the people here about it.
            _last_location = file_name(old);
            inform_of_move(str);
            if( sizeof(_route) )
                return 1;
        }

        tell_object( TP, the_short()+" finishes following "+
            HIS+" route and stops, waiting for more wild commands.\n");
        return 0;
    }

    // Attempting to sort of follow a path.  Heuristics, don't go back the
    // way we came.  Try and follow the biggest exit.  Choose an exit in
    // roughly the direction we are going.
    if( query_path_follow() || _panic ) {
        exits = query_allowed_directions(0);
        do {
            foreach( str in exits ) {
                weight = query_direction_weight(str);
                if( weight > highest_weight ) {
                    highest_weight = weight;
                    highest_exit = str;
                }
            }

            // If the best exit takes us back where we were...  Stop...
            if( ENV(TO)->query_destination(highest_exit) == _last_location ) {
                if( _panic ) {
                    _panic--;
                    exits -= ({ highest_exit });
                } else {
                    tell_object( TP, the_short()+" could not find anywhere "
                        "else to go and stops, waiting for you to do "
                        "something.\n");
                    return 0;
                }
            } else {
                if( str = do_move_direction(highest_exit) ) {
                    // Tell all the people about it.
                    _last_location = file_name(old);
                    inform_of_move(str);
                    if( _panic ) {
                        if( !--_panic ) {
                            tell_riders( the_short()+" calms down and stops "
                                "panicing.\n");
                            return 0;
                        }
                    }
                    return 1;
                } else {
                    exits -= ({ highest_exit });
                }
            }
        } while( _panic && sizeof(exits) );

        tell_object( TP, the_short()+" could not find anywhere else to go "
            "and stops, waiting for you to do something.\n");
        return 0;
    }

    // A specific direction.
    if( str = do_move_direction(_cur_direction) ) {
        // Tell all the people about it.
        _last_location = file_name(old);
        inform_of_move(str);
        return 1;
    }

    tell_object( TP, the_short()+" stops since there is no "+
        _cur_direction+" exit here, or "+HE+" was unable to go that way.\n");

    return 0;

} /* do_actual_move() */

/**
 * This method moves the horse.
 */
void do_move_transport() {
    int fluff, divide, i, ok;
    string *exits;

    if( _cur_speed == RIDE_NOT_MOVING )
        return;

    // Figure out how many bits to move per section.
    divide = _transport_speed / 2;
    if( divide == 0 )
        divide = 1;

    if( _cur_speed < divide )
        fluff = 1;
    else
        fluff = _cur_speed / divide;

    // They don't stop when they are panicing.
    if( _cur_exhaustion <= _cur_speed * _cur_speed && !_panic ) {
        tell_riders( the_short()+" is too exhausted to move any further.\n");
        return;
    }

    // Decrease the exhaustion first.
    _cur_exhaustion -= _cur_speed * _cur_speed;

    // Add in the call_out first to make it less likely for the horse to get
    // stuck panicing (for instance).
    if( _cur_speed < divide )
        _move_id = call_out( (: do_move_transport :),
                   divide * 2 / _cur_speed );
    else
        _move_id = call_out( (: do_move_transport :), 2 );

    // Do the move, see if it succeeded...
    // See how fast we are supposed to be moving.
    for( i = 0; i < fluff; i++ ) {
        ok = do_actual_move();

        // See if we should stop after moving once.
        if( query_stop_after_moving_once() ) {
            _cur_speed = RIDE_NOT_MOVING;
            remove_call_out(_move_id);
            _move_id = 0;
            return;
        }

        // See if we are at an intersection.
        // If we are, then stop...
        if( query_stop_at_intersection() ) {
            exits = query_allowed_directions(1);
            if( sizeof(exits) > 1 ) {
                // Inform the player and stop.
                tell_riders( the_short()+" stops and waits for your next "
                    "direction as you arrive at an intersection.\n");
                _cur_speed = RIDE_NOT_MOVING;
                remove_call_out(_move_id);
                _move_id = 0;
                return;
            }
        }

        if( !ok ) {
            _cur_speed = RIDE_NOT_MOVING;
            remove_call_out(_move_id);
            _move_id = 0;
            return;
        }
    }

} /* do_move_transport() */

/**
 * Sets up the call_out if needed.
 */
void setup_movement() {
    if( _cur_speed == RIDE_NOT_MOVING )
        return;

    if( find_call_out(_move_id) == -1 ) {
        int divide;

        // Figure out how many bits to move per section.
        divide = _transport_speed / 2;
        if( divide == 0 )
            divide = 1;

        if( _cur_speed < divide )
            _move_id = call_out( (: do_move_transport :),
                       divide * 2 / _cur_speed );
        else
            _move_id = call_out( (: do_move_transport :), 2 );
    }

} /* setup_movement() */

/**
 * This sets the speed at which the transport defaults to moving.  This is
 * how long it takes to move one room by default.
 * @param the default number of action points
 */
void set_transport_speed( int num ) { _transport_speed = num; }

/**
 * This method returns the amount of time it takes to move the transport
 * one room.
 * @return the amount of time to move one room
 */
int query_transport_speed() { return _transport_speed; }

/**
 * This method sets the default mount difficulty for the transport.
 * @parm difficulty The default difficulty
 */
void set_default_mount_difficulty( int difficulty ) {
    _default_mount_difficulty = difficulty;
} /* set_default_mount_difficulty() */

/**
 * This method returns the default mount difficulty for the transport.
 * @return the default difficulty
 */
int query_default_mount_difficulty() {
    return _default_mount_difficulty;
} /* query_default_mount_difficulty() */

/**
 * This method determines the default directional control of the transport.
 * (no reins?  Where do you think your going?)
 * @param difficulty the default directional difficulty
 */
void set_default_direction_difficulty( int difficulty ) {
    _default_direction_difficulty = difficulty;
} /* set_default_direction_difficulty() */

/**
 * This method determines the default directional control of the transport.
 * (no reins?  Where do you think your going?)
 * @return the default directional difficulty
 */
int query_default_direction_difficulty() {
    return _default_direction_difficulty;
} /* query_default_direction_difficulty() */

/**
 * This method determines the default difficulty of controlling the
 * transport in combat.
 * @param difficulty the default difficulty of controlling the mount in combat
 */
void set_default_fight_difficulty( int difficulty ) {
    _default_fight_difficulty = difficulty;
} /* set_default_fight_difficulty() */

/**
 * This method returns the default difficulty of controlling the
 * mount in combat.
 * @return the default difficulty of controlling the mount in combat
 */
int query_default_fight_difficulty() {
    return _default_fight_difficulty;
} /* query_default_fight_difficulty() */

/**
 * This method returns the type of transport that this is.
 * @return the type of transport
 */
string query_transport_type() { return _transport_type; }

/**
 * This method returns the type of transport that this is.
 * @param type the type of transport
 */
string set_transport_type( string type ) { _transport_type = type; }

/**
 * This method sets the name of the transport.
 * @param name sets the name of the transport
 */
void set_transport_name( string name ) { _transport_name = name; }

/**
 * This method returns the name of the transport.
 * @return the name of the transport
 */
string query_transport_name() { return _transport_name; }

/** @ignore yes */
string query_quit_handler() { return "/room/transport_start"; }

/**
 * This method returns the current list of people riding the
 * transport.
 * @return the list of people riding the transport
 */
object *query_riders() { return _riding; }

/**
 * This method checks to see if the person specified is actually a
 * rider.
 * @return 1 if they are a rider, 0 if not
 */
int is_rider( object ob ) { return member_array( ob, _riding ) != -1; }

/**
 * This method tells the riders about something.
 * @param str the message to tell the riders
 */
void tell_riders( string str ) {
    object thing;

    foreach( thing in query_riders() )
        tell_object( thing, str );

} /* tell_riders() */

/**
 * Fixes up the current list of people riding the transport.
 */
void fixup_riders() {
    object *old_riders, ob;
    int *ids, fluff;

    old_riders = _riding;
    _riding = filter( INV(TO), (: living($1) &&
        sizeof( $1->effects_matching(
        TRANSPORT_EFFECT->query_classification() ) ) :) );

    old_riders -= _riding + ({ 0 });

    foreach( ob in old_riders ) {
        ids = ob->effects_matching( TRANSPORT_EFFECT->query_classification() );
        foreach( fluff in ids )
            ob->delete_effect(fluff);
    }

} /* fixup_riders() */

/**
 * This method sets the object we are teathered to.
 * @param ob the object we are teathered to, 0 if we are not teathered
 */
void set_teathered_to( object ob ) {
    _teathered_to = ob;
    if( ob ) {
        _teathered_to_short = ob->query_short();
        set_position("teathered");
        set_position_type("to");
        set_position_on(_teathered_to);
    } else {
        _teathered_to_short = 0;
        set_position(0);
        set_position_type(0);
        set_position_on(0);
        // return_to_default_position(0);
    }
} /* set_teathered_to() */

/**
 * This method returns the object we are currently teathetred to.
 * @return the object we are teathered to
 */
object query_teathered_to() { return _teathered_to; }

/**
 * This method is called to make the object slide off.
 * @param ob the object sliding off
 */
void do_slide_off( object thing ) {
    if( ENV(thing) == TO && ( !living(thing) ||
        !sizeof( thing->effects_matching(
        TRANSPORT_EFFECT->query_classification() ) ) ) &&
        thing != _me_repeater && thing != _env_repeater &&
        member_array( thing, query_wearing() ) == -1 ) {
        if( thing->move( ENV(TO) ) ) {
            tell_creator("sandoz", "Failed to move "+
                thing->the_short()+" from "+the_short()+" to "+
                ENV(TO)->the_short()+".\n");
        } else {
            tell_room( TO, thing->the_short()+" slides off "+
                the_short()+".\n");
        }
    } else if( living(thing) ) {
        fixup_riders();
    }

} /* do_slide_off() */

/** @ignore yes */
void repeat_event_person_say( object caller, object ob, string start,
                              string mess, string lang ) {
    object *obs;

    if( ob == TO ) {
        obs = INV(TO) - ({ _me_repeater });
        obs->event_person_say( ob, start, mess, lang );
    } else if( caller == _me_repeater ) {
        // Here, so echo it to the environment.
        obs = INV( ENV(TO) ) - ({ TO, _env_repeater });
        obs->event_person_say( ob, "From the "+pretty_short( TP, 1 )+" "+start,
            mess, lang );
    } else {
        obs = INV(TO) - ({ _me_repeater });
        obs->event_person_say( ob, "From the room "+start, mess, lang );
    }

} /* repeat_event_person_say() */

/** @ignore yes */
void repeat_event_emote( object caller, object ob, string mess ) {
    object *obs;

    if( ob == TO ) {
        obs = INV(TO) - ({ _me_repeater });
        obs->event_emote( ob, mess );
    } else if( caller == _me_repeater ) {
        // Here, so echo it to the environment.
        obs = INV( ENV(TO) ) - ({ TO, _env_repeater });
        obs->event_emote( ob, "From the "+pretty_short( TP, 1 )+" "+mess );
    } else {
        obs = INV(TO) - ({ _me_repeater });
        obs->event_emote( ob, "From the room "+mess );
    }

} /* repeat_event_emote() */

/** @ignore yes */
void repeat_event_say( object caller, object ob, string str,
                       mixed avoid ) {
    object *obs;

    // The environment repeater is actually in us, creates a loop.
    // - Sandoz.
    if( caller == _env_repeater && ENV( _env_repeater ) == TO )
        return;

    if( ob == TO ) {
        obs = INV(TO) - ({ _me_repeater });
        obs->event_say( ob, str, avoid );
    } else if( caller == _me_repeater ) {
        // Here, so echo it to the environment.
        obs = INV( ENV(TO) ) - ({ TO, _env_repeater });
        obs->event_say( ob, str, avoid );
    } else {
        obs = INV(TO) - ({ _me_repeater });
        obs->event_say( ob, str, avoid );
    }

} /* repeat_event_say() */

/** @ignore yes */
void repeat_event_enter( object caller, object thing, string mess,
                         object prev ) {
    object *obs;

    // Things should slide off...
    if( ENV(thing) == TO )
        call_out( (: do_slide_off :), 2, thing );

    if( !stringp(mess) && thing != TO )
        return;

    if( caller == _env_repeater ) {
        // Here, so echo it to the environment.
        obs = INV(TO) - ({ _me_repeater });
        obs->event_enter( thing, mess, prev );
    }

} /* repeat_event_enter() */

/** @ignore yes */
void repeat_event_exit( object caller, object thing, string mess,
                        object dest ) {
    object *obs;

    if( ENV(thing) == TO && living(thing) )
        call_out( (: fixup_riders :), 2 );

    if( !stringp(mess) && thing != TO )
        return;

    if( caller == _env_repeater ) {
        // Here, so echo it to the environment.
        obs = INV(TO) - ({ _me_repeater });
        obs->event_enter( thing, mess, dest );
    }

} /* repeat_event_exit() */

/** @ignore yes */
void repeat_event_soul( object caller, object thing, string mess,
                        object *avoid ) {
    object *obs;

    if( thing == TO ) {
        obs = INV(TO) - ({ _me_repeater });
        obs->event_soul( thing, mess, avoid );
    } else if( caller == _me_repeater ) {
        // Here, so echo it to the environment.
        obs = INV( ENV(TO) ) - ({ TO, _env_repeater });
        obs->event_soul( thing, mess, avoid );
    } else {
        obs = INV(TO) - ({ _me_repeater });
        obs->event_soul( thing, mess, avoid );
    }

} /* repeat_event_soul() */

/**
 * This method creates the repeaters used for delivering the event
 * messages to us.
 */
void create_repeaters() {
    if( !_me_repeater ) {
        _me_repeater = clone_object(TRANSPORT_REPEATER);
        _me_repeater->set_repeater_owner(TO);
        _me_repeater->move(TO);
    }

    if( !_env_repeater ) {
        _env_repeater = clone_object(TRANSPORT_REPEATER);
        _env_repeater->set_repeater_owner(TO);
        _env_repeater->move( ENV(TO) );
    }
} /* create_repeater() */

/** @ignore yes */
private void check_teathered_to() {
    object* obs;

    obs = match_objects_for_existence( _teathered_to_short, ENV(TO) );

    if( sizeof(obs) )
        set_teathered_to( obs[0] );
    else
        set_teathered_to(0);

} /* check_teathered_to() */

/** @ignore yes */
varargs int move( mixed dest, string messin, string messout ) {
    int ret;

    _last_move = time();
    ret = ::move( dest, messin, messout );

    if( ret == MOVE_OK ) {
        if( _env_repeater )
            _env_repeater->move(dest);

        if( !_env_repeater || !_me_repeater )
           call_out( (: create_repeaters :), 2 );
    }

    return ret;

} /* move() */

/**
 * This method is called by the ownership effect when the player logs off.
 */
void retire() {
    // So that we wouldn't dest players and whatnot.
    //  - Sandoz
    if( ENV(TO) ) {
        foreach( object ob in INV(TO) ) {
            if( living(ob) ) {
                tell_object( ob, "You jump off "+the_short()+".\n");
                ob->move_with_look( ENV(TO),
                    "$N jump$s off "+the_short()+".");
            }
        }
    }

    move("/room/rubbish", 0, "$N disappear$s in a puff of fluff.");

} /* retire() */

/** @ignore yes */
void dest_me() {
    if( _env_repeater )
        _env_repeater->dest_me();

    if( _me_repeater )
        _me_repeater->dest_me();

    if( _owner )
        set_owner(0);

    // So that we wouldn't dest players and whatnot.
    //  - Sandoz
    if( ENV(TO) ) {
        string str = PLAYER_OBJ->convert_message( the_short() );

        foreach( object ob in INV(TO) ) {
            if( living(ob) ) {
                tell_object( ob, "You jump off "+str+".\n");
                ob->move_with_look( ENV(TO),
                    "$N jump$s off "+str+".");
            } else {
                ob->move("/room/rubbish");
            }
        }
    } else {
        INV(TO)->move("/room/rubbish");
    }

    ::dest_me();

} /* dest_me() */

/** @ignore yes */
int attack_ob( object ob ) {
    ob->stop_all_fight();
    TO->stop_all_fight();
    return 0;
} /* attack_ob() */

/** @ignore yes */
int second_life() {
    // If we die, move the riders into our environment.
    query_riders()->move( ENV(TO) );
    return 0;
} /* second_life() */

/** @ignore yes */
int query_ok_turn_off_heart_beat() {
    return _cur_exhaustion < _max_exhaustion;
} /* query_ok_turn_off_heart_beat() */

/** @ignore yes */
void heart_beat() {
    if( _cur_exhaustion < _max_exhaustion )
       _cur_exhaustion++;

    ::heart_beat();

} /* heart_beat() */

/**
 * @ignore yes
 * Stuff to mess with light levels...
 */
int query_light() {
    if( PO == ENV(TO) || !ENV(TO) )
        return ::query_light();

    return ENV(TO)->query_light();

} /* query_light() */

/**
 * This method panics the horse when it encounters a fight.
 * @param multiplier make the difficulty harder
 */
void panic_horse( int multiplier ) {
    object main_rider, *riders, rider;
    int result, panic, bonus;

    if( !multiplier )
        multiplier = 1;

    if( sizeof( query_riders() ) ) {
        main_rider = query_riders()[0];

        // First lets do a skill check.
        bonus = _default_fight_difficulty * multiplier;
        if( _cur_speed != RIDE_NOT_MOVING )
            bonus = bonus / ( _cur_speed + TRANSPORT_PANIC_RIDING_DIVISOR );

        result = TASKMASTER_H->perform_task( main_rider,
                 TRANSPORT_SKILL_BASE + query_transport_type(),
                 _default_fight_difficulty * multiplier, TM_FREE );

        switch( result ) {
          case AWARD :
            tell_object( main_rider, "%^YELLOW%^You feel more able to "
                "control "+the_short()+" in combat than you did "
                "before.\n%^RESET%^");
          case SUCCEED :
            tell_object( main_rider, "You manage to keep "+
                the_short()+" calm in the fight going on around you.\n");
            tell_room( ENV(TO), main_rider->the_short()+" manages to keep "+
                the_short()+" calm in the fight going on around you.\n",
                ({ main_rider }) );
            return;
          case FAIL :
            tell_object( main_rider, "Despite your efforts to keep "+
                the_short()+" calm in the fight going on around you, "
                "you lose control over "+HIM+".\n");
            tell_room( ENV(TO), main_rider->the_short()+" loses control "
                "over "+the_short()+" in the fight going on around you.\n",
                ({ main_rider }) );
            // Check and see if they get tossed off...
            result = TASKMASTER_H->perform_task( main_rider,
                     TRANSPORT_SKILL_BASE + query_transport_type(),
                     ( _default_fight_difficulty * multiplier ) / 2, TM_FREE );
            switch( result ) {
              case AWARD :
                tell_object( main_rider, "%^YELLOW%^You feel more able to "
                    "stay on the horse and not be thrown off.\n%^RESET%^");
              case 1 :
                tell_object( main_rider, the_short()+" tries to throw you "
                    "off, but you manage to keep your seating.\n");
                tell_room( ENV(TO), the_short()+" tries to throw "+
                    main_rider->the_short()+" off, but "+
                    main_rider->HE+" manages to keep "+
                    main_rider->HIS+" seating.\n", ({ main_rider }) );
              break;
              case 0 :
                // Throw off all the riders.
                riders = query_riders();

                foreach( rider in riders ) {
                    tell_object( rider, the_short()+" throws you off "+
                        HIS+" back.\n");
                    rider->move( ENV(TO) );
                }

                tell_room( ENV(TO), the_short()+" throws "+
                    query_multiple_short(riders)+" off "+HIS+" back.\n",
                    riders );

              break;
            }
            break;
        }
    }

    // Panic!
    panic = _panic;
    _panic += 4 * multiplier;
    _cur_speed++;

    if( _cur_speed > _max_speed )
        _cur_speed = _max_speed;

    setup_movement();

    if( !panic )
        tell_room( ENV(TO), the_short()+" panics and makes a run for it!\n");

    _last_panic = time();

} /* panic_horse() */

/**
 * If there is a fight nearby the horsey gets a little upset.
 * @ignore yes
 */
void event_fight_in_progress( object attacker, object attackee ) {
    if( time() - _last_panic > 10 ) {
        panic_horse(TRANSPORT_PANIC_NORMAL_MULTIPLIER);
        _last_panic = time();
    }
} /* event_fight_in_progress() */

/**
 * @ignore yes
 * This method allows the container to have stuff inside it checked.
 * @param looker the person doing the checking
 * @return 1 on success, 0 on failur
 */
int can_find_match_reference_inside_object( object thing, object looker ) {
    if( is_rider(thing) )
        return 1;

    if( ::can_find_match_reference_inside_object( thing, looker ) )
        return 1;

    return 0;

} /* can_find_match_recurse_into() */

/**
 * @ignore yes
 * We mess with the followers array so that anything riding the horse that
 * has stuff following it, they follow the horse...
 * @return all the followers
 */
object *query_followers() {
    object *ret, ob;

    // No one can follow us as we zip along.  This should probably check
    // for other horses...
    if( _cur_speed > RIDE_WALK )
        return ({ });

    ret = ::query_followers();
    foreach( ob in query_riders() )
        ret |= ob->query_followers();

    return ret;

} /* query_followers() */

/**
 * This method will tell if the object is a transport or not.
 * @return 1 if it is a transport
 */
int query_transport() { return 1; }

/** @ignore yes */
int adjust_hp( int damage, object attacker, object weapon, string type ) {
    int ret, chance, ac;
    object rider;
    string zone;

    // Do the pk checks and panicing first.
    if( attacker && damage < 0 && _owner && pk_check( attacker, _owner ) )
        return 0;

    if( damage < 0 )
        panic_horse(TRANSPORT_PANIC_IN_BATTLE_MULTIPLIER);

    // Figure out the attack zone...  We will assume that the player
    // is more likely to try and hit the person on the horse.
    if( !sizeof( query_riders() ) || damage >= 0 )
        return ::adjust_hp( damage, attacker );

    // If the type is anything but one of the standard ones, pass on all the
    // damage.
    switch (type) {
      case "blunt" :
      case "sharp" :
      case "pierce" :
        // Figure out armour defenses...
        ret = ::adjust_hp( damage, attacker );
        damage = damage / 2;
        // Do AC stuff and so on.  More likely to hit legs than torso...

        switch( random(40) ) {
          case 0..1:
            zone = "head";
          break;
          case 2:
            zone = "neck";
          break;
          case 3..6:
            zone="chest";
          break;
          case 7..16:
            zone="abdomen";
          break;
          case 17..19:
            zone = "arms";
          break;
          case 20..21:
            zone = "hands";
          break;
          case 22..37:
            zone = "legs";
          break;
          case 38..39:
            zone = "feet";
          break;
        }

        foreach( rider in query_riders() ) {
            ac = rider->query_ac( type, damage, zone );
            if( damage - ac > 0 )
                rider->adjust_hp( damage - ac, attacker );

            // Now check to see if they get tossed off.
            chance = damage - ac * weapon->query_weight();

            switch( TASKMASTER_H->perform_task( TP,
                    TRANSPORT_SKILL_BASE + query_transport_type(), chance,
                    TM_FREE ) ) {
            case 2 :
              tell_object( rider, "%^YELLOW%^You feel more able to stay "
                  "mounted on "+the_short()+" while being hit.\n");
            case 1 :
            break;
            case 0 :
              tell_object( rider, attacker->poss_short()+" blow make you lose "
                  "balance and you fall off "+the_short()+".\n");
              tell_room( ENV(TO), attacker->poss_short()+" blow makes "+
                  rider->the_short()+" lose balance and "+rider->HE+" falls "
                  "off "+the_short()+".\n");
              rider->move( ENV(TO) );
            break;
         }
        }
      break;
    default :
      query_riders()->adjust_hp( damage, attacker );
      ret = ::adjust_hp( damage, attacker );
      break;
    }

    return ret;

} /* adjust_hp() */

/** @ignore yes */
int attack_by( object ob ) {
    object controller;

    if( !_owner )
        return ::attack_by( ob );

    if( ob->query_summoned() && ( controller = ob->query_owner() ) ) {
        if( pk_check( _owner, controller ) ) {
            tell_object( controller, "%^YELLOW%^$C$"+ob->one_short()+" tells "
                "you: I don't want to attack "+the_short()+"%^RESET%^.\n" );
            TO->stop_all_fight();
            ob->stop_fight(TO);
            ob->go_away();
            return 0;
        }
    }

    if( pk_check( _owner, ob ) ) {
        tell_object( ob, "You feel it would be wrong to attack "+
            the_short()+".\n");
        TO->stop_all_fight();
        ob->stop_all_fight();
        return 0;
    }

    panic_horse(TRANSPORT_PANIC_IN_BATTLE_MULTIPLIER);
    query_riders()->attack_by(ob);

    return ::attack_by( ob );

} /* attack_by() */

/**
 * @ignore yes
 * We are still in the same zone as the horse.
 */
string *query_zones() {
    if( ENV(TO) )
        return ENV(TO)->query_zones();
    return ({ });
} /* query_zones() */

/** @ignore yes */
mapping query_dynamic_auto_load() {
    mapping map;

    // Do this so we won't save the repeaters with our inventory.
    // - Sandoz.
    if( _me_repeater )
        _me_repeater->move(VOID_ROOM);
    if( _env_repeater && ENV(_env_repeater) == TO )
        _env_repeater->move(VOID_ROOM);

    map = (["::" : ::query_dynamic_auto_load() ]);

    if( _me_repeater )
        _me_repeater->move(TO);
    if( _env_repeater )
        _env_repeater->move(ENV(TO));

    if( _owner )
        map["owner"] = _owner;
    if( _route )
       map["route"] = _route;
    if( _transport_name )
        map["name"] = _transport_name;
    if( _cur_direction )
        map["cur direction"] = _cur_direction;
    if( _cur_speed )
        map["cur speed"] = _cur_speed;
    if( _last_location )
        map["last location"] = _last_location;
    if( _riding_flags )
        map["riding flags"] = _riding_flags;
    if( _panic )
        map["panic"] = _panic;
    if( _cur_exhaustion )
        map["cur exhaustion"] = _cur_exhaustion;
    if( _transport_id )
        map["transport id"] = _transport_id;
    if( _teathered_to_short )
        map["teathered to"] = _teathered_to_short;
    if( _allowed )
        map["allowed"] = _allowed;

    return map;

} /* query_dynamic_auto_load() */

/** @ignore yes */
void init_dynamic_arg( mapping map ) {
    if( map["::"] )
        ::init_dynamic_arg(map);

    // Do not use set_owner() here, because it will add the owner effect to
    // the player again, and thus breaking their transports array.
    // - Sandoz
    _owner = map["owner"];

    // Set them up to zip off if they were when they exited.
    _cur_direction = map["cur direction"];
    _route = map["route"];
    _transport_name = map["name"];
    _cur_speed = map["cur speed"];
    _last_location = map["last location"];
    _panic = map["panic"];
    _riding_flags = map["riding flags"];
    _cur_exhaustion = map["cur exhaustion"];
    _transport_id = map["transport id"];
    _teathered_to_short = map["teathered to"];
    _allowed = map["allowed"];

    if( _teathered_to_short )
        call_out( (: check_teathered_to :), 2 );

    setup_movement();

} /* init_dynamic_arg() */

/** @ignore yes */
mixed stats() {
    mixed arr;
    int sz, i;

    arr = allocate( sz = sizeof(_riding), (: allocate( 2 ) :) );

    for( ; i < sz; i++ ) {
        arr[i][0] = "rider #"+i;
        arr[i][1] = sprintf("%s (%s)", _riding[i]->query_cap_name(),
                    file_name(_riding[i]) );
    }

    return ::stats() + arr + ({
        ({"owner", _owner }),
        ({"allowed", _allowed }),
        ({"transport name", _transport_name }),
        ({"transport id", _transport_id }),
        ({"transport type", _transport_type }),
        ({"teathered to", _teathered_to }),
        ({"teathered to short", _teathered_to_short }),
        ({"me repeater", _me_repeater }),
        ({"env repeater", _env_repeater }),
        ({"current speed", _cur_speed }),
        ({"current exhaustion", _cur_exhaustion }),
        ({"following path", query_path_follow() }),
        ({"last location", _last_location }),
        ({"route", _route }),
        ({"current direction", _cur_direction }),
        ({"transport speed", _transport_speed }),
        ({"max speed", _max_speed }),
        ({"max exhaustion", _max_exhaustion }),
        ({"last move", _last_move }),
        ({"last panic", _last_panic }),
        });

} /* stats() */
