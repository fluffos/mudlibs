/**
 * This skills modules for living creates.  This deals will all the
 * skill interactions needed for the living objects.
 *
 * @author Pinkfish
 */
/*
 * sigh, this will be interesting wont it?
 * quick summary of routines
 * skill_bonus(string,int)     - gives the bonus...
 * skill_lvl(string)           - gives the raw level, with out stat bonus etc
 * modify_skill(string,int,int)- modifies the skills level by int.
 * calc_bonus(int,string,int)  - given the skill lvl, stat bonus str cals bonus
 * calc_lvl(string *)          - calculate number of lvls in the path
 * add_skill_lvl(...)          - horror recursive skill adder. arghh
 * teach_skill(objct *,string) - Used to teach skills to other people.
 */
/*
 * Modifications:
 * Changed to use new creator checks - Shaydz - 07/03/01
 * Fixed a bug with add_skill_level - Shiannar.
 * Fixed a bug with disappearing first skill levels in add_skill_level
 * - Sandoz 31/01/02
 * Fixed another bug with disappearing first skill levels in add_skill_level
 * - Sandoz 06/02/02
 */

#include <skills.h>
#include <tasks.h>
#include <top_ten_tables.h>
#include <tune.h>

// #define BAD_TM "BAD_TM"
#undef LOGGING

varargs int calc_bonus( int lvl, string skill, int use_base_stats );
varargs int stat_modify( int bonus, string skill, int use_base_stats );
mixed recursive_skill_add( mixed skil, string *path, int avr, int lvl, int exp,
                           mixed standard );
private void convert_skills( mixed skills, string path );
int query_skill( string skill );

mapping new_skills;

nosave mapping _bonus_cache, _stat_cache, _teach_offer;

string last_award, last_ob;
int last_award_time;

mapping query_skills() { return copy( new_skills ); }
void set_skills( mapping map ) { new_skills = map; }
int calc_level(string *path);

void create() {
    _bonus_cache = ([ ]);
    _stat_cache = ([ ]);
    new_skills = ([ ]);
} /* create() */

/**
 * This method checks to see if the skill exists in the skill array or
 * not.
 * @param skill the skill to check for non-existance
 * @return 0 if it does not exist, 1 if it does
 */
int not_there( string skill ) {
    return undefinedp( new_skills[skill] );
} /* not_there() */

/**
 * This method returns the current bonus cache for the living thing.
 * The bonus cache is where the calculated bonuses for the skills are
 * kept.
 * @return the bonus cache mapping
 */
mapping query_bonus_cache() { return copy(_bonus_cache); }

/**
 * This method returns the cached values for the stats.
 * @return the caches stat values
 */
mapping query_stat_cache() { return copy(_stat_cache); }

/**
 * This method zaps the stat cache when a certain stat changes.
 * It calls the function stats_to_zap() on the living object to
 * figure out which stats have changed.
 * @see /std/living/stats->stats_to_zap()
 */
void zap_stat_cache() {
    int i;
    string stat, word, *list;

    stat = TO->stats_to_zap();
    if( !stat )
        return;

    if( find_call_out("reset_all2") == -1 )
        call_out("reset_all2", 1 );

    foreach( i in stat ) {
        if( !list = _stat_cache[ i ] )
            continue;
        foreach( word in list )
            map_delete( _stat_cache, word );
    }

    if( word = (string)TO->query_race_ob() )
        word->set_unarmed_attacks( TO );

} /* zap_stat_cache() */

/**
 * This method zaps the bonus cache.
 */
protected void totaly_zap_bonus_cache() {
   _bonus_cache = ([ ]);
} /* zap_bonus_cache() */

/**
 * This method zaps the stat cache.
 */
protected void totaly_zap_stat_cache() {
   _stat_cache = ([ ]);
} /* zap_stat_cache() */

/**
 * This is used to convert a previously not only_leaf tree into an only_leaf
 * tree.
 */
private void flatten_it( string skill ) {
   int value;
   string *same, tmp;

   reset_eval_cost();

   value = new_skills[skill];
   same = SKILL_H->query_immediate_children(skill);

   foreach( tmp in same ) {
      if( not_there( tmp ) )
          new_skills[tmp] = value;
      flatten_it( tmp );
   }

   if( sizeof(same) )
       map_delete( new_skills, skill );

} /* flatten_it() */

/**
 * This method returns the skill bonus for the specified skill.
 * It returns the skill + all its bonsues for stats/whatever.
 * It first checks to see if the skill is in it's cache.   THe
 * real stat values are ones not modified by bonuses or temporary
 * values.
 * @param skill the skill to get the bonus for
 * @param use_base_stats tells the system not to use the real stat values
 * @return the skill bonus
 */
varargs int query_skill_bonus( string skill, int use_base_stats ) {

  if( !stringp(skill) || !strlen(skill) )
      return 0;

  if( !new_skills )
      new_skills = ([ ]);

  if( skill[0] == '.' )
      skill = skill[1..];

  if( _bonus_cache[ skill ] ) {
      TASKER->set_control( ({ TO, skill }) );
      return stat_modify( _bonus_cache[ skill ], skill, use_base_stats );
  }

  return calc_bonus( query_skill(skill), skill, use_base_stats );

} /* query_skill_bonus() */

/**
 * This returns just the skill level.  Used a lot to determine if you
 * can use/teach/whatever a skill.
 * This also uses a cache.
 * @param skill the skill to return the level of
 * @return the skill level
 */
int query_skill( string skill ) {
   string *path, tmp;

   if( !stringp(skill) )
       return 0;

   if( !new_skills )
       new_skills = ([ ]);

   if( skill[0] == '.' )
       skill = skill[1..];

   TASKER->set_control( ({ TO, skill }) );

   if( not_there( skill ) ) {
       if( path = SKILL_H->query_skill_tree(skill) )
           foreach( tmp in path )
             if( !not_there( tmp ) )
                 return new_skills[tmp];
   }

   return new_skills[skill];

} /* query_skill() */

/**
 * This method adds a skill level to the specified skill to the
 * system.
 * @param skill the skill to add a level to
 * @param lvl the number of levels to add
 * @param exp the amount of exp spent on the skill
 * @return 1 if the skill level was changed
 * @see query_skill()
 * @see query_skill_bonus()
 */
varargs int add_skill_level( string skill, int lvl, mixed exp ) {
    string tmp, sk;
    string *recursive_skills;
    string *same_level;
    string *bits;
    string *tree;
    int i;

    reset_eval_cost();

    if( !stringp(skill) || !intp(lvl) || lvl > 1000 )
        return 0;

    if( lvl > 100 && interactive(TO) && !creatorp(TO) ) {
        log_file("CHEAT", "%s %s gave %d levels of %s to %s\n", ctime(time()),
            ( PO->query_name() || base_name(PO) ), lvl, skill,
            ( TO->query_name() || TO ) );
    }

    if( !new_skills || !mapp(new_skills) )
        new_skills = ([ ]);

    if( skill[0] == '.' )
        skill = skill[1..];

    recursive_skills = SKILL_H->query_related_skills(skill);
    if( !recursive_skills )
        return 0;

    bits = explode( skill, ".");

    /*
     * Make sure the path leading up to this skill exists so that we can
     * get the right value for the skill when we add it in.
     * This should only be done if they are not only leaf skills.
     */
    if( not_there( skill ) && !SKILL_H->query_only_leaf(skill) ) {
        int tmp_lvl;

        if( sizeof(bits) > 1 ) {
            tmp_lvl = 0;
            for( i = sizeof(bits)-1; !tmp_lvl && i >= 0; i-- ) {
               if( !not_there( implode( bits[ 0 .. i ], "." ) ) ) {
                   tmp_lvl = new_skills[ implode(bits[0..i], ".") ];
                   break;
               }
            }

            if( i >= 0 ) {
                for( ; i < sizeof(bits); i++ ) {
                    same_level = SKILL_H->query_immediate_children(
                        implode( bits[0..i], ".") );

                    foreach( tmp in same_level ) {
                        if( not_there( tmp ) ) {
                            new_skills[ tmp ] = tmp_lvl;
                            map_delete( _bonus_cache, tmp );
                        }
                    }
                }
            } else {
                tmp_lvl = 0;
            }
        }
    }

    /* Includes the current skill */
    foreach( tmp in recursive_skills ) {
        if( !not_there( tmp ) ) {
            new_skills[ tmp ] += lvl;
            if( new_skills[ tmp ] < 0 )
                new_skills[ tmp ] = 0;
        }
        map_delete( _bonus_cache, tmp );
    }

    if( not_there( skill ) )
        new_skills[skill] = lvl;

    /*
     * If it is not a only_leaf heirarchy, then fix up all the lower level
     * average skill levels.
     * The first element is the current skill.
     */
    tree = SKILL_H->query_skill_tree(skill)[1..];
    foreach( sk in tree ) {
        int total;

        same_level = SKILL_H->query_immediate_children( sk );
        if( sizeof(same_level) ) {
            total = 0;
            foreach( tmp in same_level ) {
                /* If it does not exist.  Set it from the top value down. */
                if( not_there( tmp ) ) {
                    if( !not_there( sk ) )
                        new_skills[ tmp ] = new_skills[ sk ];
                    map_delete( _bonus_cache, tmp );
                }
                total += new_skills[ tmp ];
            }
            new_skills[ sk ] = total / sizeof(same_level);
            map_delete( _bonus_cache, sk );
        }
    }

    // Update the high level players table.
    if( interactive(TO) )
        TOP_TEN_HANDLER->player_skill_advance( TO );

    if( !exp )
        exp = PO;

    if( lvl == 1 && userp(TO) && objectp(exp) )
        TASKMASTER_H->award_made( (string)TO->query_name(), base_name( exp ),
            skill, new_skills[ skill ] );

    // Make sure that there is at most one call_out running.
    if( find_call_out( "reset_all" ) == -1 )
        call_out( "reset_all", 1 );

    return 1;

} /* add_skill_level() */

/**
 * This method returns the skill as it should be modified by the
 * stats associated with it.
 * @param lvl the level to modify
 * @param skill the skill the modify the bonus of
 * @param use_base_stats use the real unmodified stat values
 * @see query_skill_bonus()
 * @return the stat modification
 */
varargs int stat_modify( int lvl, string skill, int use_base_stats ) {
   int i, stat, bonus;
   string stat_bonus;

   if( !_stat_cache[ skill ] || use_base_stats ) {
       stat_bonus = SKILL_H->query_skill_stat(skill);
       foreach( i in stat_bonus ) {
         switch( i ) {
            case 'C' :
              stat = ( use_base_stats ? (int)TO->query_real_con() :
                                        (int)TO->query_con() );
              break;
            case 'D' :
              stat = ( use_base_stats ? (int)TO->query_real_dex() :
                                        (int)TO->query_dex() );
              break;
            case 'I' :
              stat = ( use_base_stats ? (int)TO->query_real_int() :
                                        (int)TO->query_int() );
              break;
            case 'S' :
              stat = ( use_base_stats ? (int)TO->query_real_str() :
                                        (int)TO->query_str() );
              break;
            case 'W' :
            default :
              stat = ( use_base_stats ? (int)TO->query_real_wis() :
                                        (int)TO->query_wis() );
         }
         bonus += ( stat - 13 ) * 3;
         if( !_stat_cache[ i ] ) {
             _stat_cache[ i ] = ({ skill });
         } else {
             if( member_array( skill, _stat_cache[ i ] ) == -1 )
                 _stat_cache[ i ] += ({ skill });
         }
      }
      if( !use_base_stats )
          _stat_cache[ skill ] = ({ bonus, stat_bonus });
   } else {
      bonus = _stat_cache[ skill ][ 0 ];
      stat_bonus = _stat_cache[ skill ][ 1 ];
   }

   if( i = strlen( stat_bonus ) )
       return lvl + ( lvl * bonus ) / ( i * 60 );

   return lvl;

} /* stat_modify() */

/*
 * Handy fact: stat_modify( 100, skill ) - 35 is the stat total
 *  for that skill.
 */

/**
 * This method calculates the bonus for the skill.  It takes the raw
 * level and turns that into a bonus and then adds on the stats
 * modifications.
 * @param lvl the level to turn into bonus
 * @param skill the skill to modify the bonus of
 * @param use_base_stats use the real unmodified stats
 * @return the bonus associated with the skill
 */
varargs int calc_bonus( int lvl, string skill, int use_base_stats ) {

   if( lvl > 60 )
       lvl = 170 + ( ( lvl - 60 ) >> 1 );
   else if( lvl > 40 )
       lvl = 150 + ( lvl - 40 );
   else if( lvl > 20 )
       lvl = 100 + ( ( ( lvl - 20 ) * 5 ) >> 1 );
   else
       lvl = lvl * 5;

   if( !use_base_stats )
       _bonus_cache[ skill ] = lvl;

   return stat_modify( lvl, skill, use_base_stats );

} /* calc_bonus() */

/**
 * This method does a skill successful check.  Does this check:<br>
 * (bonus + mos) >= random(200)
 * @param str the skill to check
 * @param mod the modification value
 * @return 1 if the skill check is successful
 */
int query_skill_successful(string str, int mod) {
  return ( query_skill_bonus( str, 0 ) + mod >= random(200) );
} /* query_skill_successful */

/**
 * This method adds a teaching offer to the living object.
 * @param ob the object teaching us
 * @param skill the skill they are teaching
 * @param num the number of levels they are teaching
 * @param lvl the level they are teaching us from
 * @param xp the cost of the level increase in xp
 */
void add_teach_offer( object ob, string skill, int num, int lvl, int xp ) {
  if( !mapp(_teach_offer) )
      _teach_offer = ([ ]);
  _teach_offer[ob] = ({ skill, num, lvl, xp });
} /* add_teach_offer() */

/**
 * This method returns the current list of teach offerings on the
 * living object.
 * @return the mapping containing the teach offerings
 */
mapping query_teach_offer() { return copy(_teach_offer) || ([ ]); }

/**
 * The method to call when we stop teaching skills.  THis will stop the
 * stuff being taught if the stop is successful, and only teach partial
 * amounts if we are not finished yet.
 * @param left the amount of time left
 * @param bing the data associated with the command
 */
void stop_teaching_skills(int left, mixed bing) {
   object ob;

   if (left > 0) {
      /* Someone did a stop!  Naughty frogs! */

      if (bing[O_OTHER_PER] == TO) {
         say(TO->short() + " stops teaching themselves some "
             "skills.\n");
      } else if (previous_object() == TO) {
         ob = bing[O_OTHER_PER];
         tell_object(ob, TO->short() + " interupts your "
                         "training.\n");
      } else {
         ob = TO;
         tell_object(ob, bing[O_OTHER_PER]->short() + " interupts your "
                         "training.\n");
      }
      say(bing[O_OTHER_PER]->short() + " stops teaching some skills to " +
          TO->short() + ".\n",
          ({ TO, bing[O_OTHER_PER] }));

      TO->adjust_time_left(-((int)TO->query_time_left()));
      TO->set_interupt_command(0);

      return ;
   }

   if (previous_object() != TO) {
      /* First make sure we dont get the level twice... */
      return ;
   }

   // additional test added by ceres coz people are getting put into negative
   // xp by getting taught twice somehow.
   if(TO->query_xp() < bing[O_XP]) {
      write("Something has gone wrong. :(\n");
      return;
   }
   /* Ok...  We did it!  Finished! */
   if (TO != bing[O_OTHER_PER]) {
      bing[O_OTHER_PER]->adjust_xp(bing[O_XP]/10);
   }
   TO->adjust_xp(-bing[O_XP]);
   add_skill_level(bing[O_SKILL], bing[O_NUM], bing[O_XP]);
   if (TO != bing[O_OTHER_PER]) {
      tell_object(TO, "You finish learning " + bing[O_NUM] +
                  " levels of "
                  + bing[O_SKILL] + " from " + bing[O_OTHER_PER]->short() +
                  ".\n");
      tell_object(bing[O_OTHER_PER], TO->short() + " finishes " +
                  "learning " + bing[O_NUM] + " levels of "
                  +bing[O_SKILL] + " from you.\n");
      say(TO->short() + " finishes learning some skills "+
          "from "+bing[O_OTHER_PER]->short()+".\n",
          ({ TO, bing[O_OTHER_PER] }));
   } else {
      tell_object(TO, "You finish teaching yourself " + bing[O_NUM] +
                  " levels of " + bing[O_SKILL] + ".\n");
      say(TO->short() + " finishes learning some skills "
          "from " + TO->query_objective() + "self.\n",
          ({ TO, bing[O_OTHER_PER] }));
   }
} /* stop_teaching_skills() */
