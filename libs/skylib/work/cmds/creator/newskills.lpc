
#include <skills2.h>

inherit COMMAND_BASE;

string rec_list( mixed *args, string path, int all, int lvl,
                 int only_leaf ) {
   int i, sk, o_l, non_zero;
   int no_bonus;
   string str, tp, tmp;

   str = "";
   for ( i = 0 ; i < sizeof( args ) ; i += SKILL_ARR_SIZE ) {
      o_l = 0;
      tp = path +"."+ args[ i ];
      /* Get the level of the skill at this point */
      if (tp[0] == '.') {
         tp = tp[1..];
      }
      sk = (int)this_player()->query_skill( tp );
      non_zero = 0;
      no_bonus = 0;
      reset_eval_cost();

     tmp = rec_list( args[ i + SKILL_BIT ], path +"."+ args[i],
                        all, lvl + 1, only_leaf || o_l );
     str += sprintf( "%*'| 's%*'.'-s    -    -\n", ( lvl-1 ) * 2, "",
                           20 - ( ( lvl - 1 ) * 2 ), args[ i ]) + tmp;
   }
   return str;
} /* rec_list() */

int cmd(string word) {
   int i;
   string result, *bits;
   mixed *args;
   result = "";
   
   bits = ({ });
   args = STD_SKILLS;

   if ( word ) {
      args = STD_SKILLS;
      if ( ( i = member_array( word, args ) ) == -1 ) {
         tell_object(TP, "Usage: "+ query_verb() +" <skill>\n" );
         return 1;
      }
      args = args[ i + SKILL_BIT];
      result = sprintf( "%'='*-s\n", (int)this_player()->query_cols(),
            "=======SKILLS=======Level/Bonus" );
      result += sprintf( "%#*-s\n", (int)this_player()->query_cols(),
            rec_list( args, word, 1, 1, 0 ) );
      this_player()->more_string( result, "Skills" );
      return 1;
   }
   result += sprintf( "%'='*-s\n", (int)this_player()->query_cols(),
         "=======SKILLS=======Level/Bonus");
   result += sprintf( "%#*-s\n", (int)this_player()->query_cols(),
         rec_list( args, "", ( member_array( "all", bits ) != -1 ), 1, 0 ) );
   this_player()->more_string( result, "Skills" );
   return 1;
} /* cmd() */
