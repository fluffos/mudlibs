/**
 * A basic fence for thieves and others to sell stolen items to.
 * @change Partly rewritten by Sandoz, December 2001.
 */

#include <shop.h>

inherit NPC_OBJ;

#define TIMEOUT (60*60*24*2)

#define SKILL "general.valueing"

class offer {
    object who;
    int amount;
    int offer_time;
    object *objects;
}

class offer this_offer;
object cont;
string fence_type, *stole_from_fence;
mapping old_offers;

int query_timeout() { return TIMEOUT; }
object query_cont() { return cont; }

/** @ignore yes */
mapping query_old_offers() { return old_offers; }

void whisper( object ob, string message ) {
    do_command("whisper " + message + " to " + ob->query_name() );
} /* whisper() */

/**
 * This method creates a container for the fence to use.
 * Override it in your fence NPC if you wish.
 */
void check_cont() {
    if( !cont || ENV(cont) != TO ) {
        cont = (object)ARMOURY_H->request_item("large hessian sack", 85 );
        cont->add_property("nosteal", 1 );
        cont->move(TO);
        do_command(":produces "+cont->a_short()+" from somewhere.");
    }

    if( cont->query_loc_weight() > 2 * cont->query_max_weight() / 3 ) {
        INV(cont)->move("/room/rubbish");
        old_offers = ([ ]);
    }

} /* check_cont() */

void create() {
    do_setup++;
    ::create();
    do_setup--;
    if( !do_setup )
        TO->setup();

    check_cont();

    set_respond_to_with( ({
        ({ ({"y", "yes", "Y", "Yes", "ok", "okay"}) }) , "#do_yes",
        ({ ({"n", "no", "N", "No"}) }) , "#do_no" }) );

    old_offers = ([ ]);
    stole_from_fence = ({ });

    set_wimpy(90);

} /* create() */

void reset() {
    call_out("clean_cont", 12 );
} /* reset() */

void clean_cont() {
    // Don't dest anything if we're in the middle of dealing with someone.
    if( this_offer )
        return;

    check_cont();

    INV(cont)->move("/room/rubbish");
    old_offers = ([ ]);

} /* clean_cont() */

/**
 * This method sets the speciality of the fence.
 * This can be one of the following: weapons, jewellery,
 * armour, clothing, gems or misc.
 * @param str the speciality of the fence to use
 */
void set_fence_type( string str ) { fence_type = str; }

/** @ignore yes */
int query_cost( object thing, object buyer ) {
    return thing->query_value_at(TO);
} /* query_cost() */

/** @ignore yes */
string cost_string( object thing, string place, object buyer ) {
    return MONEY_H->money_value_string( query_cost( thing, buyer ), place );
} /* cost_string() */

/**
 * This method will work out the type of object being fenced.
 * @param ob the object to test
 * @return the object type
 */
string query_item_type(object ob) {
    if( member_array("weapons", ob->query_plurals() ) != -1 )
        return "weapons";
    if( member_array("jewellery", ob->query_plurals() ) != -1 ||
        ob->query_property("shop type") == "jewellers" )
        return "jewellery";
    if( member_array("armours", ob->query_plurals() ) != -1 )
        return "armour";
    if( member_array("clothes", ob->query_plurals() ) != -1 )
        return "clothing";
    if( member_array("gems", ob->query_plurals() ) != -1 )
        return "gems";
    return "misc";
} /* query_item_type() */

/**
 * This method returns the value of an item based on
 * the client's valueing skills.
 * @param ob the object to get the value for
 * @param player the client
 * @param type the type of the object
 * @return the value of the object
 */
int judge_value( object ob, object player, string type ) {
    int value, variance, skill;

    value = query_cost( ob, TO );
    skill = player->query_skill_bonus( SKILL+( type != "" ? "."+type : "" ) ) || 1;
    variance = to_int( value / ( 1 + ( sqrt( to_float(skill) ) / 8 ) ) );

    return value + random(variance) - random(variance);

} /* judge_value() */

/**
 * This method sets the place, or the currency area this
 * fence operates in.  This is used for currency calculations.
 * @param where the place where we operate in
 */
void set_place( string where ) { add_property("place", where ); }

/**
 * This method will return the place we are in,
 * which is used in money strings etc.
 * @return the place we are in
 */
string query_place() {
    return query_property("place") || "default";
} /* query_place() */

/**
 * This method will return the money string for the given value.
 * @param amt the amount of money to get the money string for
 * @return the money string for the given amount of money
 */
string cost_str( int amt ) {
    return MONEY_H->money_value_string( amt, query_place() );
} /* cost_str() */

int scaled_value( int n ) {
    int profit;

    profit = 5 + to_int( sqrt( to_float( n / 5 ) ) );
    if( profit > MAX_PROFIT / 3 )
        profit = MAX_PROFIT / 3;

    return n * ( 100 - profit ) / 100;

} /* scaled_value() */

int do_fail( object player ) {
    whisper( player, "Well, that was a waste of time.");
    this_offer = 0;
    return 1;
} /* do_fail() */

int do_fence( object *obs ) {
    int offer, their_skill;
    float f;
    string type, skill;
    object ob, *offered, *not_speciality, *tmp;

    check_cont();

    tell_object( TP, "You ask "+the_short()+" about fencing "+
        query_multiple_short(obs)+".\n");
    tell_room( ENV(TO), TP->the_short()+" asks "+the_short()+" about fencing "+
        query_multiple_short(obs)+".\n", TP );

    if( TP->query_property(query_name()+"_killer") &&
        ( TP->query_property(query_name()+"_killer") + TIMEOUT ) < time() ) {
        do_command("peer "+TP->query_name() );
        init_command("lsay Oh sod off you!  I wouldn't buy anything from you "
            "even if I was offered a kingdom!", 1 );
        TP->add_failed_mess( TO, "" );
        return 0;
    }

    if( this_offer && this_offer->who && ENV( this_offer->who ) == ENV(TO) &&
        this_offer->offer_time > time() - 60 ) {
        whisper( TP, ( this_offer->who != TP ? "Sorry, I'm already helping "+
            (this_offer->who)->the_short()+"." : "I'm still waiting for a "
            "response from you!") );
        TP->add_succeeded_mess( TO, "", offered );
        return 1;
    }

    if( !TP->query_visible(TO) ) {
        TP->add_failed_mess( TO, "$D doesn't seem to notice you.\n", offered );
        return 0;
    }

    TP->add_succeeded_mess( TO, "", offered );

    if( member_array( TP->query_name(), stole_from_fence ) != -1 ) {
        do_command("peer "+TP->query_name() );
        init_command("lsay Piss off scumbag!", 1 );
        return 1;
    }

    if( sizeof(obs) > MAX_OBS ) {
        whisper( TP, "Sorry, I can't handle that many items at once.");
        this_offer = 0;
        return 1;
    }

    tell_room( ENV(TO), the_short()+" studies "+
        query_multiple_short( obs, "the" )+".\n");

    if( sizeof( tmp = filter( obs, (: $1->query_keep() :) ) ) ) {
        whisper( TP, "You can't sell "+strip_colours(
            query_multiple_short(tmp, "the") )+" because you are keeping "+
            ({"it","them"})[query_group(tmp)]+".");
        if( !sizeof( obs -= tmp ) )
            return do_fail(TP);
    }

    not_speciality = ({ });

    this_offer = new( class offer );
    this_offer->objects = ({ });
    this_offer->who = TP;
    this_offer->offer_time = time();

    if( sizeof( tmp = filter( obs, (: ENV($1) != this_offer->who :) ) ) ) {
        whisper( TP, "Do you think I'm blind?  I can see that you don't "
            "have "+strip_colours( query_multiple_short(tmp) )+".");
        if( !sizeof( obs -= tmp ) )
            return do_fail(TP);
    }

    if( sizeof( tmp = filter( obs, (: $1->query_property("money") :) ) ) ) {
        whisper( TP, "You can't sell money, are you daft?");
        if( !sizeof( obs -= tmp ) )
            return do_fail(TP);
    }

    if( sizeof( tmp = filter( obs, (: $1->query_worn_by() :) ) ) ) {
        whisper( TP, "I'm sorry, but you can't fence "+strip_colours(
            query_multiple_short(tmp, "the") )+" because you're wearing "+
            ({"it","them"})[query_group(tmp)]+".");
        if( !sizeof( obs -= tmp ) )
            return do_fail(TP);
    }

    if( sizeof( tmp = filter( obs, (: $1->query_wielded() :) ) ) ) {
        whisper( TP, "You can't fence "+strip_colours(
            query_multiple_short(tmp, "the") )+" because you're holding "+
            ({"it","them"})[query_group(tmp)]+".");
        if( !sizeof( obs -= tmp ) )
            return do_fail(TP);
    }

    if( sizeof( tmp = filter( obs, (: $1->do_not_sell() :) ) ) ) {
        whisper( TP, "You can't sell "+strip_colours(
            query_multiple_short(tmp, "the") )+".");
        if( !sizeof( obs -= tmp ) )
            return do_fail(TP);
    }

    if( sizeof( tmp = filter( obs, (: $1->move(cont) :) ) ) ) {
        whisper( TP, "I can't take "+strip_colours(
            query_multiple_short(tmp, "the") )+" from you for some reason, "
            "so you can't fence "+({"it","them"})[query_group(tmp)]+".");
        if( !sizeof( obs -= tmp ) )
            return do_fail(TP);
    }

    TCRE("sandoz", sprintf("%s fencing:\n%-*#s", TP->short(), 79, implode(
        map( obs, (: $1->short(0)+" ("+query_item_type($1)+")" :) ), "\n") ) );

    foreach( ob in obs ) {
      type = query_item_type(ob);

      if( !offer = judge_value( ob, TP, type ) ) {
          whisper( TP, ob->the_short()+" isn't worth anything.");
          if( !ob->move(TP) )
              whisper( TP, "So you can have it back.");
          else {
              ob->move(environment());
              whisper( TP, "So I'll just put it down here.");
          }
          continue;
      }

      // are we a fence for this type of object?
      if( type != fence_type ) {
          offer -= offer / 5;
          not_speciality += ({ ob });
      }

      // now do the profit (just like a shop)
      offer = (int)scaled_value(offer) || 1;

      if( ob->query_property("fenced") ) {
          if( ob->query_property("fenced") == (string)TP->query_name() ) {
              do_command("'Hey, that "+ob->short(0)+" is mine you scoundrel!");
              init_command("'Think I'm stupid do you?", 2 );
              init_command("'You'd better leave, and quickly!", 4 );
              stole_from_fence += ({ TP->query_name() });
              return 1;
          } else {
              do_command("'Mmm, that looks familiar.");
              do_command(":frowns in thought");
              do_command("'Oh well.");
              this_offer->amount -= ( offer * 3 ) / 4;
          }
      }

      // Remember our previous offers.
      if( old_offers[ob] )
          offer = old_offers[ob];
      else
          old_offers[ob] = offer;

      // now see if we can fleece them
      skill = SKILL + ( type != "" ? "."+type : "" );
      their_skill = TP->query_skill_bonus(skill) || 2;

      // reduce the offer dependant on their valueing skill
      f = sqrt( to_float( their_skill / 2 ) ) / 3;
      offer -= to_int( offer / ( f < 2 ? 2 : f ) );

      this_offer->amount += offer;
      this_offer->objects += ({ ob });

    }

    if( sizeof(not_speciality) )
        whisper( TP, "Well, "+strip_colours( query_multiple_short(
            not_speciality, "the" ) )+" "+({"isn","aren"})
            [query_group(not_speciality)]+"'t really my speciality.");

    if( !sizeof( this_offer->objects ) ) {
        whisper( TP, "Well, that was a waste of time.");
        this_offer = 0;
        return 1;
    }

    // Tell em how much and wait for their response
    whisper( TP, "I'll give you "+cost_str(this_offer->amount)+" for "+
        strip_colours( query_multiple_short( this_offer->objects, "the" ) )+
        ", what do you think?");
    return 1;

} /* do_fence() */

// Now they've given a response.  Either stop or take their goods
// and give them money.
void do_yes( object person ) {
    object money, *selling, ob;
    mixed m_arr;

    if( !this_offer || person != this_offer->who )
        return;

    whisper( person, "You've got a deal.");
    selling = ({ });

    foreach( ob in this_offer->objects ) {
        ob->add_property("fenced", person->query_name(), 86400 );
        selling += ({ ob });
    }

    m_arr = MONEY_H->create_money_array( this_offer->amount, query_place() );
    money = clone_object( MONEY_OBJ );
    money->set_money_array( m_arr );

    if( money->move(person) ) {
        whisper( person, "You're too heavily burdened to accept all that "
            "money, so I'll just put it "+( ENV(TO)->query_property("here") ?
            ENV(TO)->query_property("here") : "on the floor" )+".");
        money->move(ENV(TO));
    } else {
        tell_object( person, the_short()+" gives you "+
            cost_str(this_offer->amount)+".\n");
        tell_room( ENV(TO), the_short()+" gives some coins to "+
            person->the_short()+".\n", ({ person }) );
    }

    this_offer = 0;

} /* do_yes() */

void do_no( object person ) {
    object ob;

    if( !this_offer || person != this_offer->who )
        return;

    whisper( person, "Ok, have it your own way then.");

    foreach( ob in this_offer->objects )
      if( ob->move(person) )
          ob->move(ENV(TO));

    tell_object( person, the_short()+" returns "+
        query_multiple_short( this_offer->objects, "the" )+" to you.\n");
    tell_room( ENV(TO), the_short()+" returns the items to "+
        person->the_short()+".\n", person );

    this_offer = 0;

} /* do_no() */

int attack_by( object ob ) {
    object tmp;

    if( this_offer && this_offer->who && ENV(this_offer->who) == ENV(TO) &&
        this_offer->offer_time > time() - 60 ) {
        do_command("'Hey! I'm trying to do business here!");

        foreach( tmp in this_offer->objects ) {
          if( tmp->move(this_offer->who) )
              tmp->move(ENV(TO));
        }

        whisper( this_offer->who, "Hey, you'd better take these back.");
        tell_object( this_offer->who, the_short()+" returns " +
            query_multiple_short(this_offer->objects, "the")+" to you.\n");
        tell_room( ENV(TO), the_short()+" gives some items to "+
            (this_offer->who)->the_short()+".\n", ({ this_offer->who }) );
        this_offer = 0;
    }

    return ::attack_by(ob);

} /* attack_by() */

void event_exit( object ob, string message, object to ) {
    object tmp;

    if( ob && ob == cont )
        ob->remove_property("nosteal");

    if( ob && this_offer && this_offer->who && this_offer->who == ob &&
        ENV(ob) == ENV(TO) ) {
        foreach( tmp in this_offer->objects ) {
          if( tmp->move(this_offer->who) )
              tmp->move(ENV(TO));
        }
        whisper( this_offer->who, "You might want to take these back before "
            "you go.");
        tell_object( this_offer->who, the_short()+" returns " +
            query_multiple_short(this_offer->objects, "the")+" to you.\n");
        tell_room( ENV(TO), the_short()+" returns some items to "+
            (this_offer->who)->the_short()+".\n", ({ this_offer->who }) );
        this_offer = 0;
    }

    return ::event_exit( ob, message, to );

} /* event_exit() */

void init() {
    ::init();
    TP->add_command("fence", TO,
        "<indirect:object:me> to <direct:object'person'>",
        (: do_fence($1) :) );
} /* init() */
