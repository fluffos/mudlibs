/**
 * Contains some simul_efuns.
 * @author Pinkfish
 */
private string ob_short( object ob ) {
   string ret;

   if( ob->query_clothing() && ( ret = ob->query_pocket_mess() ) && ret != "" )
       return ret;

   return "$ob_short$";

} /* ob_short() */

/**
 * This method produces the inside messages for the given object up
 * to the player object.  This one generates 'the_short' messages.
 * This should only be called with an object that is a container.
 * It will produce weird and incorrect messages otherwise.
 * @param ob the object to generate the short for
 * @param play the player to generate the short up to
 * @see inside_a_short()
 */
string inside_the_short( object ob, object play ) {
   string str;

   if( !play )
       play = TP;

   if( !ob )
       ob = ENV(play);

   str = replace_string( ob_short(ob), "$ob_short$", ob->the_short() );

   while( ENV(ob) && ENV(ob) != play && ENV(ob) != ENV(play) ) {
      ob = ENV(ob);
      str += " inside " + replace_string( ob_short(ob), "$ob_short$",
                                          ob->the_short() );
   }

   return str;

} /* inside_the_short() */

/**
 * This method produces the inside messages for the given object up
 * to the player object.  This one generates 'a_short' messages.
 * This should only be called with an object that is a container.
 * It will produce weird and incorrect messages otherwise.
 * @param ob the object to generate the short for
 * @param play the player to generate the short up to
 * @see inside_the_short()
 */
string inside_a_short( object ob, object play ) {
   string str;

   if( !play )
       play = TP;

   if( !ob )
       ob = ENV(play);

   str = replace_string( ob_short(ob), "$ob_short$", ob->a_short() );

   while( ENV(ob) && ENV(ob) != play && ENV(ob) != ENV(play) ) {
      ob = ENV(ob);
      str += " inside " + replace_string( ob_short(ob), "$ob_short$",
                                          ob->the_short() );
   }

   return str;

} /* inside_a_short() */

/**
 * This method produces the inside messages for the given object up
 * to the player object.  This one generates 'a_short' messages.
 * This should only be called with an object that is a container.
 * It will produce weird and incorrect messages otherwise.
 * @param ob the object to generate the short for
 * @param play the player to generate the short up to
 * @see inside_the_short()
 */
string inside_one_short( object ob, object play ) {
   string str;

   if( !play )
       play = TP;

   if( !ob )
       ob = ENV(play);

   str = replace_string( ob_short(ob), "$ob_short$", ob->one_short() );

   while( ENV(ob) && ENV(ob) != play && ENV(ob) != ENV(play) ) {
      ob = ENV(ob);
      str += " inside " + replace_string( ob_short(ob), "$ob_short$",
                                          ob->the_short() );
   }

   return str;

} /* inside_one_short() */
