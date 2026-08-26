#include <bounty.h>
#include <player.h>

#define HOME                 VOID_ROOM
#define DEATH_MESSAGE_EFFECT "/std/effects/other/death_message"
#undef ROLL_DICE_NOW

inherit "/std/container";

string *pending, visiting;
object person;

void setup() {
    set_name("death");
    set_living_name("death");
    add_property( "npc", 1 );
    add_property( "determinate", "" );
    enable_commands();
    set_short("Death");
    add_property( "player", 1 );
    set_long(
      "This is Death, the Grim Reaper.  He is wearing a long flowing black "+
      "robe with a heavy belt slung round his waist, from which is slung "+
      "a white-handled sword.  He slowly turns his skull towards you, "+
      "the actinic pinpoints in his eyesockets flaring.\n");
    pending = ({ });
    visiting = "";
    move(HOME);
    reset_get();
} /* setup() */

string *query_pending() { return pending; }
string query_visiting() { return visiting; }
object query_person() { return person; }

void add_to_list( string name ) {
    tell_object( find_player(name), "Death tells you: Hold on, "
        "I'll deal with you in a moment.\n");
    pending += ({ name });
} /* add_to_list() */


void go_home() {
    move(HOME);
    tell_room( ENV(TO), "Death winks into existance.  He then stands against "
        "the wall and with a blank look becomes as still as a statue.\n");
} /* go_home() */

void start_visit( object person ) {
    if( file_name(ENV(TO)) == HOME )
        tell_room( ENV(TO), "Death looks around slowly and a slow grin "
            "creeps across his face.  Then, suddenly, with a sparkle in "
            "his eye, he flits out of existence.\n");

    move(ENV(person));

    tell_object( person, "You hear a wispy voice chuckling, seemingly from "
        "nowhere in particular.  The sound just seems to seep through the "
        "woodwork of space and time.\n");

    person->add_effect( DEATH_MESSAGE_EFFECT, TO );

    if( lordp(person) )
        call_out("lord_chat", 5 );
    else if( creatorp(person) )
        call_out("cre_chat", 5 );
    else
        call_out("player_chat", 5 );

} /* start_visit() */

/* lords */
void lord_chat( int stage ) {
    switch( stage ) {
      case 0:
        tell_object( person, "Death's eerie voice whispers: Oh, you're a "
            "Lord.\n");
        call_out("lord_chat", 5, ++stage );
      break;
      case 1:
        tell_object( person, "Death fidgets, unsure of what to do.\n");
        call_out("lord_chat", 5, ++stage );
      break;
      case 2:
        tell_object( person, "Death's face lightens up, as if he just got "
            "an idea.\n");
        call_out("lord_chat", 5, ++stage );
      break;
      case 3:
        tell_object( person, "Death puts on his black ray-bans and flashes "
            "his neuralizer at you.\n");
        call_out("lord_chat", 5, ++stage );
      break;
      default:
        tell_object( person, "Death flits out of existance with a sigh of "
            "relief.\n");
        call_out("finish_visit", 0 );
    }
} /* lord_chat() */

/* Creators */
void cre_chat( int stage ) {
    switch( stage ) {
      case 0:
        tell_object( person, "Death says: Oh, you're a creator.\n");
        call_out("cre_chat", 5, ++stage );
      break;
      case 1:
        tell_object( person, "Death says: You can sort it out by your damned "
            "self then.\n");
        call_out("cre_chat", 5, ++stage );
      break;
      default:
        tell_object( person, "Death flips you the bird and with a sparkle in "
            "his eye, flits out of existence.\n");
        call_out("finish_visit", 0 );
      }
} /* cre_chat() */

/* Players */
void player_chat( int stage ) {
    switch( stage ) {
      case 0:
        tell_object( person, "Death materializes right in front of you, "
            "totally in command of the situation.\n");
        call_out("player_chat", 5, ++stage );
      break;
      case 1:
        tell_object( person, "Death says: Yes!  Every time you die, your "
            "soul grows weaker, its force grows fainter.\n");
        call_out("player_chat", 5, ++stage );
      break;
      case 2:
        tell_object( person, "Death says: When your soul is weak enough, "
            "you will belong eternally to me.\n");
        call_out("player_chat", 5, ++stage );
      break;
      case 3:
        tell_object( person, "Death cackles, the sound ripping through you, "
            "causing shivers of such intensity that you cannot keep your "
            "teeth from chattering.\n");
#ifdef ROLL_DICE_NOW
        if( person->query_property(PK_KILLED) )
            call_out("player_chat", 5, ++stage );
        else
            call_out("begin_dice_stuff", 5 );
#else
        call_out("player_chat", 5, ++stage );
#endif
      break;
      default:
        tell_object( person, "Death points at you, saying: Just remember, "
            "I'll return for you soon enough.  Then, with a sparkle in his "
            "eye, he flits out of existence.\n");
        call_out("finish_visit", 0 );
      }

} /* player_chat() */

void begin_dice_stuff() {
    if( person->query_property(PK_KILLED) )
        call_out("player_chat", 0, 4 );
    else
        person->set_death_rolling();
} /* begin_dice_stuff() */

void finish_visit() {
    person->remove_death_message_effect();  //Urgh...
    person = 0;
    visiting = "";

    if( sizeof(pending) > 0 ) {
        visiting = pending[0];
        pending -= ({ visiting });
        person = find_player(visiting);
        return start_visit(person);
    }

    go_home();

} /* finish_visit() */

void person_died( string name ) {
    if( name == visiting || member_array( name, pending ) != -1 )
        return;

    if( visiting != "")
        return add_to_list( name );

    person = find_player(name);
    visiting = name;
    start_visit(person);

} /* person_died() */

int someone_died( object thing ) {
    int no_dec;
    string inform, damnit;
    object *attackers, attacker;

    if( !userp( thing ) && !thing->query_property("unique") ) {
        if( (string)thing->query_property( "determinate" ) == "" ) {
            inform = (string)thing->query_short();
            if( inform != lower_case( inform ) )
                if( ENV( thing ) )
                    log_file("UNIQUES", inform+" ("+file_name(thing)+" in "+
                        file_name( ENV(thing) ) +")\n");
                else
                    log_file("UNIQUES", inform+" ("+file_name(thing)+")\n");
        }
        return 0;
    }

    no_dec = 0;
    inform = lower_case( (string)thing->query_short() ) +" killed by";
    attackers = (object *)thing->query_attacker_list();

    if( !sizeof( attackers ) ) {
        damnit = PO->query_property("death_message");
        if( damnit )
            inform += PO->query_property("death_message");
        else if( objectp( TP ) )
            inform += " "+(string)TP->query_name()+" (who knows)";
        else
            inform += " who knows";
    } else
        foreach ( attacker in attackers )
            if( objectp(attacker) ) {
                inform += " "+(string)attacker->query_name()+" <"+
                          geteuid( attacker )+">";
                if( userp(attacker) || attacker->query_property("player") )
                    no_dec += 1;
            }

    log_file("DEATH", ctime( time() ) +": "+ inform +"\n" );
    user_event("inform", inform, "death" );
    BOUNTY->register_kill( thing, attackers );

    return no_dec;

} /* someone_died() */
