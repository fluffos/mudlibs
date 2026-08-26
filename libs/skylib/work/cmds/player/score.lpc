
inherit COMMAND_BASE;

#include <top_ten_tables.h>
#include <clubs.h>
#include <player.h>

#define essify(x,y) ( x > 1  ||  x == 0 ? " " y "s" : " " y )
#define LIMIT 150

int score_quests( object ob, int sorted ) {
    string *quests;
    mixed quest_info;

    if( ob->query_property("dead") ) {
        write( "You are just a disembodied spirit.  What use does a wispy "
            "thing like you have for a collection of meaningless numbers?\n");
        return 1;
    }

    quests = LIBRARY_H->query_quests( ob->query_name() );
    if( !sizeof( quests ) ) {
        printf("You have not completed any quests.\n");
        return 1;
    }

    quest_info = map( quests, (: ({ QUEST_H->query_quest_title($1),
                                    QUEST_H->query_quest_story($1) }) :) );

    if( sorted )
        quest_info = sort_array( quest_info, (: strcmp($1[0], $2[0]) :) );

    write("$P$Quests$P$You have completed the following quests:\n"+
        implode( map( map( quest_info, (: "     \""+
            $1[0] +"\", in which you "+replace( $1[1], "was", "were" ) :) ),
            (: sprintf( $1[0..24]+"%*-=s",
            $(ob)->query_cols() - 30, $1[25..] ) :) ), ",\n" ) +".\n" );

    return 1;

} /* score_quests() */

int query_verbose( object ob, string verbose )  {
    if( !verbose )
        return ob->query_verbose("score");
    return verbose == "verbose";
} /* query_verbose() */

int score_stats( object ob, string verbose )  {
    string word;

    if( ob->query_property("dead") ) {
        write("You are just a disembodied spirit.  What use does a wispy "
            "thing like you have for a collection of meaningless numbers?\n");
        return 1;
    }

    word = ( ob->query_weight() / 20 ) +"."+ ( ob->query_weight() % 10 );
    if( query_verbose( ob, verbose ) )  {
        printf("%-#*s\n", ob->query_cols(),
            "Constitution ... "+ ob->query_con() +"\n"
            "Dexterity ...... "+ ob->query_dex() +"\n"
            "Intelligence ... "+ ob->query_int() +"\n"
            "Strength ....... "+ ob->query_str() +"\n"
            "Wisdom ......... "+ ob->query_wis() +"\n"
            "Height ......... "+ ob->query_height()+"cm\n"
            "Weight ......... "+ word +"kg\n");
    } else  {
        printf("%-#*s\n", ob->query_cols(),
            "Con: "+ ob->query_con()+"\n"
            "Dex: "+ ob->query_dex() +"\n"
            "Int: "+ ob->query_int() +"\n"
            "Str: "+ ob->query_str() +"\n"
            "Wis: "+ ob->query_wis() +"\n"
            "Hgt: "+ ob->query_height()+"cm\n"
            "Wgt: "+ word +"kg\n");
    }

    return 1;

} /* score_stats() */

int score_normal( object ob, string verbose )  {
    string word, tmp;
    int age, temp1, temp2, temp3, temp4;
    mapping m;

    if( ob->query_property("dead") ) {
        write("You are just a disembodied spirit.  What use does a wispy "
            "thing like you have for a collection of meaningless numbers?\n");
        return 1;
    }

    if( query_verbose( ob, verbose ) )  {
        temp1 = ob->query_hp();
        temp2 = ob->query_gp();
        temp3 = (int)LIBRARY_H->query_quest_points( ob->query_name() );
        temp4 = ob->query_sp();

        printf("%-=*s", ob->query_cols(), "You have "+temp1+" ("+
            ob->query_max_hp()+") hit"+essify( temp1, "point")+", "+
            temp2+" ("+ob->query_max_gp()+") energy"+
            essify( temp2, "point")+", "+temp3+" ("+
            (int)QUEST_H->query_total_qp()+") quest"+
            essify( temp3, "point")+" and "+temp4+" ("+
            ob->query_max_sp()+") social"+essify( temp4, "point")+".\n");
        printf("%-=*s", ob->query_cols(), "Your current experience is "+
            ob->query_xp()+".\n");
//             and you are level "+(int)ob->query_level()+".\n"
//            "Your overall rating is "+
//            (int)TOP_TEN_HANDLER->calculate_rating( ob )+".\n" );

        temp1 = ob->query_deaths();
        temp2 = ob->query_max_deaths();
        printf("%-=*s", ob->query_cols(), "You have lost "+
            temp1+
            "% of your lifeforce.\n");

        if( temp1 = ob->query_wimpy() )
            printf("Your wimpy is set to %d%%.\n", temp1 );
        else
            printf("You are in brave mode.\n" );

        if( tmp = ob->align_string() ) {
            word = ob->query_deity();
            if( word && DEITY_H->query_deity( word ) )
                printf("You are %s, and worshipping %s, %s.\n",
                    tmp, word, DEITY_H->query_title(word) );
            else
                printf("You are %s.\n", tmp );
        }

        tmp = ob->query_temp_str();
        printf("You are %s (%i%%)%s.\n", ob->burden_string(),
            ob->query_burden(), ( tmp ? " and feeling "+tmp : "") );

        if( ob->query_property( PKER ) )
            printf("You are registered as a player killer.\n");

        if( sizeof( m = ob->query_hide_invis() ) )  {
            printf("%-=*s\n", ob->query_cols(), "You are "+
                query_multiple_short( keys( m ) )+".");
        }

        printf("%-=*s", ob->query_cols(), ob->extra_score() );
        age = -ob->query_time_on();
        if( age > 86400 ) {
            temp1 = age / 86400;
            word = temp1 + essify( temp1, "day");
        } else  {
            word = "";
        }

        if( age > 3600 )  {
            if( age > 86400 )
                word += ", ";
            temp1 = ( age / 3600 ) % 24;
            word += temp1 + essify( temp1, "hour");
        }

        if( age > 60 )  {
            if( age > 3600 )
                word += ", ";
            temp1 = ( age / 60 ) % 60;
            temp2 = age % 60;
            temp3 = ob->query_no_logins();
            printf("%-=*s", ob->query_cols(), "You are "+word+temp1+
                essify( temp1, "minute")+" and "+temp2+
                essify( temp2, "second")+" old and have logged in "+temp3+
                essify( temp3, "time")+".\n");
        } else  {
            temp1 = age % 60;
            temp2 = ob->query_no_logins();
            printf("%-=*s", ob->query_cols(), "You are "+temp1+
                essify( temp1, "second")+" old and have logged in "+temp2+
                essify( temp2, "time")+".\n");
        }
    } else {
        printf("%-=*s", ob->query_cols(),
            "Hp: "+ob->query_hp()+"("+ob->query_max_hp()+")  "
            "Ep: "+ob->query_gp()+"("+ob->query_max_gp()+")  "
            "Xp: "+ob->query_xp()+"\n");
    }

    return 1;

} /* score_normal() */

string create_relationship_text( string relationship, mapping data ) {
    string *relatives;
    int size;

    if( !relatives = data[ relationship ] )
        return "";

    if( !size = sizeof( relatives ) )
        return "";

    if( size == 1 )
        return CAP( relatives[0] )+" is your "+relationship;

    return query_multiple_short( map( sort_array( relatives, 1 ),
        (: CAP( $1 ) :) ) )+" are your "+pluralize( relationship );

} /* create_relationship_text() */

int get_gender( string name ) {
    int gender;

    gender = PLAYER_H->test_gender( name );

    if( gender )
        gender -= 1;

    return gender;

} /* get_gender() */

int score_relationships( object ob, int verbose ) {
    string txt, family, *sorted;
    class relationship_data *bing;
    mapping grouped;

    family = ob->query_family_name();

    if( !family || !CLUB_HANDLER->is_family( family ) ) {
        add_failed_mess("You are not in a family.\n");
        return 0;
    }

    bing = CLUB_HANDLER->query_relationships( family, ob->query_name() );

    if( !sizeof( bing ) ) {
        add_failed_mess("You have no relatives.\n");
        return 0;
    }

    grouped = unique_mapping( bing,
        (: CLUB_HANDLER->query_relationship_gender(
           CLUB_HANDLER->query_opposite_relationship( $1->relationship ),
           get_gender( $1->related_to ) )  :) );

    grouped = map( grouped, (: map( $2, (: $1->related_to :) ) :) );
    sorted = sort_array( keys( grouped ), 1 );

    txt = implode( map( sorted,
        (: create_relationship_text( $1, $(grouped) ) :) ), ".\n" );

    tell_object( ob, "$P$Relationships$P$" + txt + ".\n");
    return 1;

} /* score_relationships() */

int score_align( object ob, int verbose ) {
    int al_range, al_offset;
    string deity, status;

    if( ob->query_property("dead") ) {
        write("You're dead.  Things such as 'good' and 'evil' are no longer "
            "of your concern.\n");
        return 1;
    }

    deity = ob->query_deity();

    if( !deity ) {
        write("You are "+ob->align_string()+", and not worried about the "
            "approval of any deity at all.\n");
        return 1;
    }

    if( !DEITY_H->query_deity( deity ) ) {
        write("You are "+ob->align_string()+", and apparently worshipping "
            "a non-existent god.\n" );
        return 1;
    }

    if( DEITY_H->query_valid_al( deity, ob->query_al() ) )
        status = "furious with you";
    else {
        al_range = ABS( ( DEITY_H->query_al_lower( deity ) -
                          DEITY_H->query_al_upper( deity ) ) );
        al_offset = ( ob->query_al() -
            DEITY_H->query_al_middle( deity ) ) / ( al_range / 20 );

        switch( ABS( al_offset ) ) {
          case 0 : status = "most pleased with you";
          break;
          case 1 : status = "pleased with you";
          break;
          case 2 : status = "satisfied with you";
          break;
          case 3 : status = "watching you with interest";
          break;
          case 4..5 : status = "contented with you";
          break;
          case 6 : status = "slightly discontented with you";
          break;
          case 7 : status = "displeased with you";
          break;
          case 8 : status = "annoyed with you";
          break;
          case 9 : status = "angry with you";
          break;
          default : status = "angry with you";
        }
    }

    write("You are "+ob->align_string()+", and "+deity+" is "+status+".\n");
    return 1;

} /* score_align */

int score_fighting( object player, int verbose ) {
    object *attacker_list, *attacker_list_here;

    attacker_list = player->query_attacker_list();

    if( !sizeof( attacker_list ) ) {
        tell_object( player, "You are not fighting anyone.\n");
        return 1;
    }

    attacker_list_here = filter( attacker_list,
        (: living($1) && ENV($1) == $2 :), ENV(player) );
    attacker_list -= attacker_list_here;

    if( sizeof(attacker_list_here) ) {
        tell_object( player, "You are currently fighting "+
            query_multiple_short( attacker_list_here )+" here.\n");
    }

    if( sizeof(attacker_list) ) {
        tell_object( player, "You are currently fighting "+
            query_multiple_short( attacker_list )+".\n");
    }

    return 1;

} /* score_fighting() */

mixed query_patterns() {
   return ({ "quests", (: score_quests( TP, 0 ) :),
             "quests sorted", (: score_quests( TP, 1 ) :),
             "{brief|verbose} stats", (: score_stats( TP, $4[0] ) :),
             "stats", (: score_stats( TP, 0 ) :),
             "{brief|verbose}", (: score_normal( TP, $4[0] ) :),
             "relationships", (: score_relationships( TP, 0 ) :),
             "", (: score_normal( TP, 0) :),
             "align", (: score_align( TP, 0 ) :),
             "fighting", (: score_fighting( TP, 0 ) :) });
} /* query_patterns() */
