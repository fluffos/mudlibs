/**
 * A skin inherit for use with the skin command and in scraping/tanning.
 * @author Sandoz, 08th September 2001.
 */

#include <bit.h>
#include <skin.h>

#define WEIGHT_SIZE_DIV 3

inherit OBJECT_OBJ;

private int decay, gender, tanned, scraped, hair_lost;
private string race, skin_type;

int query_scraped();
int query_softness();
int query_tanned();
int query_no_hair();
int query_hair_left();
int query_amount_scraped();
string query_size_string();
string query_gender_string();
string query_softness_string();
string query_scrape_string();
string query_preferred_item();

/** @ignore yes */
void create() {
    ::create();
    race = "default";
    skin_type = "skin";
    add_extra_look(TO);
} /* create() */

/** @ignore yes */
int query_skin() { return 1; }

/** @ignore yes */
string upd_long() {
    string str;

    if( tanned && query_no_hair() ) {
        str = "This is a $size$ piece of tanned $race$ skin that has been "
              "scraped clean of all hair.  It is $soft$ and would probably "
              "be rather comfortable and look good if tailored into a $item$.";
    } else if( tanned ) {
        switch( query_hair_left() ) {
          case 0..30:
            str = "This is a $size$, $soft$, and somewhat worn and almost "
                  "hairless tanned $race$ $type$ - the result of poor "
                  "scraping and lack of tanning technique.";
          break;
          case 31..60:
            str = "This $size$, $soft$, tanned $race$ $type$ appears to have "
                  "lost several larger patches of hair, though it would "
                  "probably still make itself useful if a $item$ was made "
                  "out of it.";
          break;
          case 61..90:
            str = "This $size$, $soft$, tanned $race$ $type$ appears to have "
                  "lost some its the hair in places, although it would still "
                  "make itself useful if a $item$ was made out of it.";
          break;
          default:
            str = "This $size$, $soft$, well tanned $race$ $type$ has most "
                  "of its hair left intact and looks rather warm, surely it "
                  "would make a great $item$.";
        }
    } else {
        str = "This is a $size$ $type$ carefully cut from the corpse of "
              "$who$.  "+query_scrape_string()+".";
    }

    set_long( replace( str, ({ "$race$", race, "$type$", skin_type, "$who$",
        ( gender ?  "a "+query_gender_string()+" "+race : add_a(race) ),
        "$size$", query_size_string(), "$soft$", query_softness_string(),
        "$item$", query_preferred_item() }) )+
        "\n" );

} /* upd_long() */

/**
 * This method returns a string description on how much of
 * the skin has been scraped along with how much hair is left.
 * @return the scraped description string
 */
string query_scrape_string() {
    string hair;

    switch( query_hair_left() ) {
      case 0:
        hair = "no hair left whatsoever";
      break;
      case 1..10:
        hair = "a few patches of hair still intact";
      break;
      case 31..50:
        hair = "several patches of hair intact";
      break;
      case 51..75:
        hair = "a few patches of hair missing";
      break;
      case 76..95:
        hair = "most of the hair still intact";
      break;
      default:
        hair = "all of the hair nicely intact";
    }

    switch( query_amount_scraped() ) {
      case 0..10:
        return "It is mostly untouched with "+hair+", but could still "
               "use quite a bit of scraping to make anything useful out of it";
      case 11..40:
        return "It has "+hair+", but could still use more scraping to make "
               "anything useful out of it";
      case 41..70:
        return "It has "+hair+", but could still use a bit more scraping "
               "to make it to anything useful";
      case 71..99:
        return "It has "+hair+", but could still use a tiny bit of scraping "
               "before it is ready to be tanned";
      default:
        return "It has "+hair+" and has been scraped completely clean "
               "of the grain layer, just waiting to be tanned";
    }
} /* query_scraped_string() */

/**
 * This method returns the size string of the skin,
 * calculated from the weight of the skin.
 * @return the size of skin as a string, calculated from the
 * weight
 */
string query_size_string() {
    int tmp;

    tmp = ::query_weight();
    if( ( tmp /= WEIGHT_SIZE_DIV ) < 1 )
        tmp = 1;

    switch(tmp) {
      case 0..4:
        return "tiny";
      case 5..10:
        return "small";
      case 11..20:
        return "fairly small";
      case 21..40:
        return "medium sized";
      case 41..80:
        return "fairly large";
      case 81..160:
        return "large";
      default:
        return "huge";
    }
} /* query_size_string() */

/**
 * This method returns the gender string of the pelt.
 * This will be either male, female or neuter.
 * @return the gender string
 */
string query_gender_string() {
    switch( gender ) {
      case 1: return "male";
      case 2: return "female";
      default: return "neuter";
    }
} /* query_gender_string() */

/**
 * This method returns the gender associated with the skin.
 * @return the gender associated with the skin
 */
int query_gender() { return gender; }

/**
 * This method queries the race of the skin.
 * @return the race of the skin
 */
string query_race() { return race; }

/**
 * This method returns the skin type - pelt, fur etc.
 * @return the skin type
 */
string query_skin_type() { return skin_type; }

/**
 * This method sets the skin type.
 * @param _race the race of the creature the skin came off from
 * @param _type the type of skin - pelt, fur, scales etc.
 * @param _gender the gender of the creature the skin came off from
 * @param _decay the current decay level of the skin
 */
void setup_skin( string _race, string _type, int _gender, int _decay ) {
    if( undefinedp( SKIN_TYPES[_type] ) )
        skin_type = "skin";
    else
        skin_type = _type;
    race = _race;
    gender = _gender;
    if( _decay ) {
        decay = _decay;
    } else {
        decay = 200;
    }
    set_name( skin_type );
    set_short( race+" "+skin_type );
    upd_long();
    add_adjective( race );
    BIT_CONTROLLER->add_bit(TO);
} /* setup_skin() */

/**
 * This method returns the current decay level of the skin
 * @return the current decay level
 */
int query_decay() { return decay; }

/**
 * This method is called by the bits controller to do the actual
 * decaying of the skin.
 * @return 1 if it still exists, 0 if it has finished decaying
 */
int do_decay() {
    int rate;

    if( tanned ) {
        BIT_CONTROLLER->remove_bit(TO);
        decay = 0;
        return 0;
    }

    if( !ENV(TO) ) {
        move( "/room/rubbish" );
        return 0;
    }

    rate = 1;
    if( !query_scraped() )
        rate += 2;
    rate += (int)ENV(TO)->query_property( "decay rate" );

    if( rate > 0 ) {
        decay -= rate;
    }
    if( decay < 0 ) {
        if( interactive(ENV(TO)) )
            tell_object( ENV(TO), poss_short()+" decays to dust.\n");
        move( "/room/rubbish" );
        return 0;
    }
    upd_long();
    return 1;
} /* do_decay() */

/** @ignore yes */
int query_weight() {
    int base;
    float weight;

    weight = ( ( weight = ::query_weight() ) < 1 ? 1 : weight );
    base = weight / ( query_tanned() ? 4 : 3 );
    base = ( base < 1 ? 1 : base );
    weight -= base;
    weight = ( weight < 1 ? 1 : weight );
    weight /= 200;

    return to_int( base + weight * query_hair_left() +
                   weight * ( 100 - query_amount_scraped() ) );

} /* query_weight() */

/**
 * This method returns the percentual softness of the skin.
 * @return the softness percentage
 */
int query_softness() {
    int tmp;
    if( !tmp = SKIN_TYPES[skin_type][S_TAN] )
        return 0;
    return 100 - 100 * ( tmp - tanned ) / tmp;
} /* query_softness() */

/**
 * This method returns the softness of the skin in a string format.
 * @return the softness of the skin
 */
string query_softness_string() {
    switch( query_softness() ) {
      case 0..20:
        return "quite hard";
      case 21..40:
        return "fairly hard";
      case 41..60:
        return "not too soft";
      case 61..80:
        return "fairly soft";
      case 81..90:
        return "quite soft";
      default:
        return "extremely soft";
    }
} /* query_softness_string() */

/**
 * This method returns the preferred cloting item to be
 * made out of the skin based on its softness.
 * @return the preferred clothing item
 */
string query_preferred_item() {
    string ret;

    switch( query_softness() ) {
      case 0..20:
        ret = "breastplate";
      break;
      case 21..40:
        ret = "backpack";
      break;
      case 41..60:
        ret = "pair of shoes";
      break;
      case 61..80:
        ret = "hat";
      break;
      case 81..90:
        ret = "jacket";
      break;
      default:
        ret = "pair of gloves";
    }
    return ret + " or something similar";
} /* query_preferred_item() */

/**
 * This method returns if the skin is tanned or not.
 * @return 1 if the skin is tanned, 0 if not tanned
 */
int query_tanned() { return !( SKIN_TYPES[skin_type][S_TAN] - tanned ); }

/**
 * This method is called when the skin is being tanned.
 * It stops the decay of the skin and changes its short
 * and extra look.
 * @return 1 if the tanning was successful, 0 if the skin
 * cannot be tanned or has already been tanned
 */
int do_tan() {
    if( query_tanned() )
        return 0;

    /* skin will lose all hair with tanning */
    if( skin_type == "skin" )
        hair_lost = SKIN_TYPES[skin_type][S_HAIR];

    remove_adjective("scraped");
    add_adjective("tanned");

    if( query_no_hair() && skin_type != "skin" ) {
        set_name("leather");
        call_out( (: set_short("piece of tanned leather") :), 3 );
        remove_plural( pluralize(skin_type) );
        add_plural("leathers");
        add_adjective("piece of");
        set_material("leather");
    } else {
        call_out( (: set_short("tanned "+race+" "+skin_type ) :), 3 );
    }

    BIT_CONTROLLER->remove_bit(TO);
    tanned++;
    decay = 0;
    upd_long();
    return 1;

} /* do_tan() */

/**
 * This methods queries the max amount of hair this type of
 * skin can have.
 * @return the max amount hair the skin can have
 */
int query_max_hair() { return SKIN_TYPES[skin_type][S_HAIR]; }

/**
 * This methods queries the amount of hair that has been
 * scraped off or otherwise lost.
 * @return the amount of hair lost
 */
int query_hair_lost() { return hair_lost; }

/**
 * This methods queries the percentual amount of hair that is left.
 * @return the percentual amount of hair left
 */
int query_hair_left() {
    int tmp;
    if( !tmp = query_max_hair() )
        return 0;
    return 100 * ( tmp - hair_lost ) / tmp;
} /* query_hair_left() */

/**
 * This method queries if the skin has any hair left or not.
 * @return 1 if the skin has some hair left, 0 if there is no
 * hair left
 */
int query_no_hair() { return !( query_max_hair() - hair_lost ); }

/**
 * This method queries if the skin has been successfully scraped.
 * @return 1 if the skin has been successfully scraped, 0 if not
 */
int query_scraped() { return !( SKIN_TYPES[skin_type][S_SCRAPE] - scraped ); }

/**
 * This method queries how much of the skin has been
 * scraped, percentually.
 * @return the amount of skin that has been scraped
 */
int query_amount_scraped() {
    int tmp;
    if( !tmp = SKIN_TYPES[skin_type][S_SCRAPE] )
        return 0;
    return 100 - 100 * ( tmp - scraped ) / tmp;
} /* query_amount_scraped() */

/**
 * This method is called when the skin is being scraped.
 * @return 1 if the scraping was successful, 0 if the skin
 * has already been scraped
 */
int do_scrape( int _hair ) {

    if( query_tanned() || ( query_scraped() &&
        ( _hair && ( !query_max_hair() || query_no_hair() ) ) ) )
        return 0;

    /* scrape off some hair */
    if( _hair && !query_no_hair() ) {
        hair_lost++;
    }

    /* scrape some more */
    if( !query_scraped() )
        scraped++;

    /* scraped, fix the desc */
    if( query_scraped() ) {
        add_adjective("scraped");
        call_out( (: set_short( "scraped "+race+" "+skin_type ) :), 3 );
    }

    upd_long();
    return 1;

} /* do_scrape() */

/** @ignore yes */
void dest_me() {
    BIT_CONTROLLER->remove_bit(TO);
    ::dest_me();
} /* dest_me() */

/** @ignore yes */
mapping query_dynamic_auto_load() {
    mapping map;

    if( !query_name() || query_name() == "object" )
        return 0;

    map = ([ "::" : ::query_dynamic_auto_load() ]);

    if( gender )
        map["gender"] = gender;
    if( race )
        map["race"] = race;
    if( skin_type )
        map["skin type"] = skin_type;
    if( decay )
        map["decay"] = decay;
    if( tanned )
        map["tanned"] = tanned;
    if( scraped )
        map["scraped"] = scraped;
    if( hair_lost )
        map["hair lost"] = hair_lost;

    return map;

} /* query_dynamic_auto_load() */

/** @ignore yes */
void init_dynamic_arg( mapping map ) {

    if( map["::"] )
        ::init_dynamic_arg( map["::"] );

    if( map["gender"] )
        gender = map["gender"];
    if( map["race"] )
        race = map["race"];
    if( map["skin type"] )
        skin_type = map["skin type"];
    if( map["decay"] )
        decay = map["decay"];
    if( map["tanned"] )
        tanned = map["tanned"];
    if( map["scraped"] )
        scraped = map["scraped"];
    if( map["hair lost"] )
        hair_lost = map["hair lost"];

    BIT_CONTROLLER->add_bit(TO);

} /* init_dynamic_arg() */

/** @ignore yes */
mapping int_query_static_auto_load() {
    return ([ "::" : ::int_query_static_auto_load() ]);
} /* int_query_static_auto_load() */

/** @ignore yes */
mapping query_static_auto_load() {
    if( !query_name() || query_name() == "object" )
        return 0;
    if( file_name( TO )[ 0 .. 13 ] == "/obj/misc/skin" )
        return int_query_static_auto_load();
    return 0;
} /* query_static_auto_load() */

/** @ignore yes */
void init_static_arg( mapping map ) {
    if( !mappingp( map ) )
        return;
    if( map["::"] )
        ::init_static_arg( map["::"] );
} /* init_static_arg() */

/** @ignore yes */
mixed *stats() {
    mixed tmp;

    tmp = ::stats();

    tmp +=  ({
        ({ "gender", query_gender_string() }),
        ({ "race", race }),
        ({ "skin type", skin_type }),
        ({ "size", query_size_string() }),
        ({ "decay", decay }),
        ({ "tanned", query_tanned() }),
        ({ "softness", query_softness() }),
        ({ "scraped", query_scraped() }),
        ({ "amount scraped", query_amount_scraped() }),
        ({ "max hair", query_max_hair() }),
        });

    if( query_no_hair() )
        return tmp + ({ ({ "no hair", query_no_hair() }) });
    else
        return tmp + ({ ({ "hair lost", hair_lost }),
                        ({ "hair left", query_hair_left() }),
                        });
} /* stats() */

/** @ignore yes */
string extra_look() {
    if( !tanned )
        switch( decay ) {
          case 0..10:
            return "It is completely rotten.\n";
          break;
          case 11..50:
            return "It is fairly rotten.\n";
          break;
          case 51..100:
            return "It is somewhat decayed.\n";
          break;
          case 101..150:
            return "It has started to decay in places.\n";
          break;
          default:
            return "It looks quite fresh.\n";
        }
} /* extra_look() */