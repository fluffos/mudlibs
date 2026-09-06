#include <const.h>
#define SK_DAEMON ("/daemon/skill")

/* Note: On 4/24/04, I updated these functions to actually query another player's
 *       skills if requested - it was simply using this_player() for everything. [al]
 */

string query_proficiency( int bonus ) {
   debug( "/bin/skills->query_proficiency is deprecated. use /daemon/skill->query_skill_string instead" );
   return SK_DAEMON->query_skill_string( bonus );
}

mapping get_skill_list(object who) {
   string *skills = m_indices(who->query_skills());
   string iskill;
   mapping skill_tree;

   skill_tree = ([ ]);
   foreach( iskill : skills ) {
      string itag;
      mapping m;

      m = skill_tree;

      foreach( itag : explode(iskill, ".") ) {
         if( member(m, itag) )
            m = m[itag];
         else
            m = m[itag] = ([ ]);
      }
   }
   return skill_tree;
}

int *get_skill_value( object who, mapping m, string name ) {
   string key;
   mapping im;
   // Skill count, skill exp, pending exp, percentage of quota filled for pending, level, level w/ bonus
   int *ret = ({ 0, 0, 0, 0, 0, 0 });

   if( !name ) name = "";
   if( !mappingp(m) ) return ret;

   if( "/daemon/skill"->query_skill_exists(name) ) {
      if( !sizeof(m) )
         ret[0]++;
      ret[1] += who->query_skill_total_exp( name );
      ret[2] += who->query_skill_current_exp( name );
	  // TODO: make the 3rd column show xp to next level in stead
	  ret[3] += who->query_skill_current_exp( name ) * 100 /
         who->query_skill_max_exp( name );
      ret[4] += who->query_skill( name );
      ret[5] += who->query_modified_skill( name );
   }

   foreach( key, im : m ) {
      int *subskill, isub;

      subskill = get_skill_value( who, im, name + "." + key );
      for( isub = 6; isub--; )
         ret[isub] += subskill[isub];
   }

   return ret;
}

varargs void show_skills( object who, mapping m, string prefix, string name, int is_wiz ) {
   string key;
   mapping im;

   if( !name ) name = "";
   if( !prefix ) prefix = "";
   if( !mappingp(m) ) return;

   foreach( key : sort_array(m_indices(m), #'>) ) {
      int *skill_stat;
	  im = m[key];

      skill_stat = get_skill_value( who, im, name + key );
      if( name == prefix + "." || name == prefix || name + key == prefix ) {
         if( skill_stat[0] == 0 )
            continue;
         if( is_wiz )
            msg( "~CLAB" + pad(name + key, 30, JUST_LEFT) + "~CDEF" +
               pad( "" + skill_stat[0], 8, JUST_LEFT ) +
               pad( "" + skill_stat[1], 8, JUST_LEFT ) +
               pad( "" + skill_stat[2], 8, JUST_LEFT ) +
               pad( "" + (skill_stat[3] / skill_stat[0]), 8, JUST_LEFT ) +
               pad( "" + (skill_stat[4] / skill_stat[0]), 8, JUST_LEFT ) +
               pad( "" + (skill_stat[5] / skill_stat[0]), 8, JUST_LEFT ) );
         else
            msg( (sizeof(im)?"~CBRT+ ":"  ") +
               "~CLAB" + pad(name + key, 30, JUST_LEFT) + "~CDEF" +
               pad( "/daemon/skill"->query_skill_string(skill_stat[4] / skill_stat[0]), 15, JUST_CENTER) +
               capitalize("" + "/daemon/skill"->query_skill_description(name+key)) );
      }

      show_skills( who, im, prefix, name + key + ".", is_wiz );
   }
}

int main( string param ) {
   mapping skills;
   string target, base;

   object ob;
   int wizard_view = ( this_player()->query_level() >= WIZLEVEL );

   if( !param ) param = "";

   if( wizard_view && param[0..0] == "-" ) {
      wizard_view = 0;
      param = param[1..];
   }

   if( this_player()->query_level() >= WIZLEVEL && sscanf(param, "%s@%s", base, target) == 2 ) {
      ob = find_player( target );
      if( !ob ) return notify_fail("No such player!\n");
   }
   else {
      base = param;
      ob = this_player();
   }
   base = trim(base);

   /* Flawed method for allowing abbreviations with this command ;)
	*
   if( !SK_DAEMON->query_skill_exists(base) )
      base = SK_DAEMON->query_skill_name(base);
   */

   if( !this_player()->query_skills() )
      return notify_fail( "You're not particularly skillful. At ANYTHING.\n" );

   skills = get_skill_list(ob);
   set_actor( ob );
   set_listener( this_player() );

   msg( "~CTIT~Npos Skills~CDEF\n" + tab("-",this_player()->query_term_width()-2) );

   // creates column titles
   // Skill count, skill exp, pending exp, percentage of quota filled for pending, level, level w/ bonus
   if( wizard_view )
      msg( "~CTIT" + pad("Skill", 30, JUST_LEFT) +
         pad( "Types", 8, JUST_LEFT) +
         pad( "Exp", 8, JUST_LEFT ) +
         pad( "Pending", 8, JUST_LEFT) +
         pad( "Pend%", 8, JUST_LEFT ) +
         pad( "Base", 8, JUST_LEFT) +
         pad( "Adjusted~CDEF", 8, JUST_LEFT) );
   else
      msg( "~CTIT" + pad("Skill", 30, JUST_LEFT) +
         pad( "Ability", 20, JUST_CENTER) +
         "Description" + "~CDEF" );

   show_skills( ob, skills, base, "", wizard_view );

   return 1;
}
