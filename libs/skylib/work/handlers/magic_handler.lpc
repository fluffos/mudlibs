string expand_spell_message( string message, object thing,
      object *things, int to_whom ) {
   string ob_name, ob_poss, ob_pron, ob_obje;
   object target;
   mixed *stuff;
/* to_whom is -2 for caster, -1 for room and 0, 1, ... for targets */
   if ( member_array( thing, things ) != -1 )
      switch ( to_whom ) {
         case -2 :
            ob_name = query_multiple_short( things - ({ thing }) +
                  ({ "yourself" }), "the" );
            switch ( sizeof( things ) ) {
               case 1 :
                  ob_poss = "your";
                  ob_pron = "you";
                  ob_obje = "yourself";
                  break;
               case 2 :
                  target = ( things - ({ thing }) )[ 0 ];
                  ob_poss = (string)target->query_possessive() +" and your";
                  ob_pron = (string)target->query_pronoun() +" and you";
                  ob_obje = (string)target->query_objective() +" and yourself";
               default :
                  ob_poss = "their and your";
                  ob_pron = "they and you";
                  ob_obje = "them and yourself";
            }
            break;
         case -1 :
            stuff = ({ (string)thing->query_objective() +"self" });
            stuff += things - ({ thing });
            ob_name = query_multiple_short( stuff );
            if ( sizeof( things ) > 2 ) {
               ob_poss = "their";
               ob_pron = "they";
               ob_obje = "them";
            } else {
               ob_poss = (string)thing->query_possessive();
               ob_pron = (string)thing->query_pronoun();
               ob_obje = (string)thing->query_objective();
            }
            break;
         default :
            stuff = ({ (string)thing->query_objective() +"self" });
            stuff += delete( things, to_whom, 1 ) - ({ thing });
            stuff += ({ "you" });
            ob_name = query_multiple_short( stuff );
            switch ( sizeof( things ) ) {
               case 1 :
                  ob_poss = "your";
                  ob_pron = "you";
                  ob_obje = "yourself";
                  break;
               case 2 :
                  ob_poss = (string)thing->query_possessive() +" and your";
                  ob_pron = (string)thing->query_pronoun() +" and you";
                  ob_obje = (string)thing->query_objective() +" and yourself";
               default :
                  ob_poss = "their and your";
                  ob_pron = "they and you";
                  ob_obje = "them and yourself";
            }
      }
   else
      switch ( to_whom ) {
         case -2 .. -1 :
            if ( !sizeof( things ) )
               break;
            ob_name = query_multiple_short( things,
                  ( to_whom == -2 ? "the" : "a" ) );
            if ( sizeof( things ) > 2 ) {
               ob_poss = "their";
               ob_pron = "they";
               ob_obje = "them";
            } else {
               ob_poss = (string)things[ 0 ]->query_possessive();
               ob_pron = (string)things[ 0 ]->query_pronoun();
               ob_obje = (string)things[ 0 ]->query_objective();
            }
            break;
         default :
            if ( !sizeof( things ) )
               break;
            ob_name = query_multiple_short( delete( things, to_whom,
                  1 ) + ({ "you" }) );
            switch ( sizeof( things ) ) {
               case 1 :
                  ob_poss = "your";
                  ob_pron = "you";
                  ob_obje = "yourself";
                  break;
               case 2 :
                  target = delete( things, to_whom, 1 )[ 0 ];
                  ob_poss = (string)target->query_possessive() +" and your";
                  ob_pron = (string)target->query_pronoun() +" and you";
                  ob_obje = (string)target->query_objective() +" and yourself";
               default :
                  ob_poss = "their and your";
                  ob_pron = "they and you";
                  ob_obje = "them and yourself";
            }
      }
   if ( thing )
      message = replace( message, ({
         "$tp_name$", (string)thing->the_short(),
         "$tp_poss$", (string)thing->query_possessive(),
         "$tp_pron$", (string)thing->query_pronoun(),
         "$tp_obje$", (string)thing->query_objective()
      }) );
   return capitalize( replace( message, ({
         "$ob_name$", ob_name, "$ob_poss$", ob_poss,
         "$ob_pron$", ob_pron, "$ob_obje$", ob_obje
   }) ) );
} /* expand_spell_message() */

void write_messages(object caster, object *targets, string *messages) {
  targets = filter(targets, (: $1 :));
  if(member_array(caster, targets) == -1) { //caster not target.
    tell_object(caster, expand_spell_message(messages[0], caster, targets, -2));
  }
  else {
    tell_object(caster, expand_spell_message(messages[1], caster, targets, -2));
  }
  tell_room(ENV(caster),
            expand_spell_message(messages[3],
                                 caster, targets, -1),
            targets + ({ caster }));
  targets -= ({ caster });
  foreach(object target in targets) {
    tell_object(target, expand_spell_message(messages[2], caster, targets, 0));
  }
}
