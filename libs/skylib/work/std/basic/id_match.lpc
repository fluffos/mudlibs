/**
 * This method is used by upper objects that only wish to match the
 * ids and not mess with all the context stuff.  This method will
 * return a combination of OBJ_PARSER_MATCH_SINGULAR and
 * OBJ_PARSER_MATCH_PLURAL.
 * @param input the input string
 * @param viewer the person viewing the object
 * @param context the contex this is to be taken in
 * @return the singular/plural match flags
 */

#include <obj_parser.h>

protected int is_matching_object( string* input, object viewer,
                                  class obj_match_context context ) {
   string *adj;
   string *names;
   string *pnames;
   int n;
   int ret;

   adj = TO->parse_command_adjectiv_id_list();
   names = TO->parse_command_id_list();
   pnames = TO->parse_command_plural_id_list();

   /* context */
   if( environment() == context->him ) {
      adj += ({ "his" });
   } else if( environment() == context->her ) {
      adj += ({ "her" });
   } else if( environment() == context->it ) {
      adj += ({ "its" });
   } else if( environment() == viewer ) {
      adj += ({ "my" });
   } else if( context->plural &&
                   member_array( environment(), context->plural ) != -1 ) {
      adj += ({ "their" });
   }

   if( TO == context->him &&
       input[<1] == "him" ) {
      ret |= OBJ_PARSER_MATCH_SINGULAR;
   } else if( TO == context->her && input[<1] == "her" ) {
      ret |= OBJ_PARSER_MATCH_SINGULAR;
   } else if( TO == context->it &&
          ( ( input[<1] == "it" && !query_group(TO) ) ||
          ( input[<1] == "them" && query_group(TO) ) ) ) {
      ret |= OBJ_PARSER_MATCH_SINGULAR;
   } else if( context->plural && input[<1] == "them" &&
              member_array( TO, context->plural ) != -1 ) {
      ret |= OBJ_PARSER_MATCH_PLURAL;
   } else if( TO == viewer && input[<1] == "me" ) {
      ret |= OBJ_PARSER_MATCH_SINGULAR;
   } else if (input[<1] == "all") {
      ret |= OBJ_PARSER_MATCH_PLURAL;
   }

   if (!ret) {
      // Strip off the here if it is the right place for it.
      if (input[<1] == "here" &&
          viewer != environment() &&
          sizeof(input) > 1) {
         input = input[0..<2];
      }

      // CHeck to see if we match the noun first.
      if( member_array( input[<1], pnames ) != -1 ) {
         ret |= OBJ_PARSER_MATCH_PLURAL;
      }
      if( member_array( input[<1], names ) != -1 ) {
         ret |= OBJ_PARSER_MATCH_SINGULAR;
      }

      if (!ret) {
         return 0;
      }
   }

   // Check and make sure we match all the adjectives.
   for( n = 0; n < sizeof( input ) - 1; n++ ) {
      if( n != sizeof( input ) - 1 ) {
          if( member_array( input[n], adj ) == -1 )
              return 0;
      }
   }

   return ret;
} /* is_matching_object() */

/**
 * This method updates the context.  It returns the number of the objects
 * we match, and you pass in the number of objects that we are.
 * @param context the context to update
 * @param num the number of objects
 * @param singular return from is_matching_object
 * @return the number of matched objects
 */
protected int update_parse_match_context( class obj_match_context context,
                                          int num, int singular ) {
   if (context->ordinal) {
      if (context->ordinal > num) {
         context->ordinal -= num;
         return 0;
      }
      context->ignore_rest = 1;
      return 1;
   } else if (context->number_included) {
      if (context->number_included <= num) {
         context->ignore_rest = 1;
         num = context->number_included;
         context->number_included = 0;
         return num;
      }
      context->number_included -= num;
      return num;
   } else {
      // Just a singular reference.
      if (num > 0 && (singular & OBJ_PARSER_MATCH_SINGULAR)) {
         return 1;
      }

      // All state.
      return num;
   }
} /* update_parse_match_context() */

/**
 * This code is for the new parser...  It returns an array which contains
 * two elements.  The first is the type of the match, plural or singular,
 * and the second is the object it matched.  Usualy TO but
 * it can be used to swap new objects.
 * @param input the input string
 * @param viewer the person viewing the object
 * @param context the contex this is to be taken in
 * @return ({ type, ob }), 0 on failure
 */
mixed parse_match_object( string* input,
                          object viewer,
                          class obj_match_context context ) {
   int ret;

   ret = is_matching_object(input, viewer, context);
   if (!ret) {
      return 0;
   }

   // We matched, so see if we should have.
   if (!update_parse_match_context(context, 1, ret)) {
      return 0;
   }

   return ({ ret, ({ TO }) });
} /* parse_match_object() */
