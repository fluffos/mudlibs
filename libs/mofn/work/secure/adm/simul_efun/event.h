/**
 * This method calls an event on all the users online.
 * It does not do any filtering, so it will send messages to people who
 * are earmuffed and ignoring or lord invisible or whatever.
 *
 * @param from the person it is from
 * @param name the name of the event
 * @param args the arguments to the event
 */
void user_event( mixed from, mixed first, mixed args ... ) {
   if ( stringp( from ) ) {
      call_other( efun::users(), "event_"+ from, previous_object(),
            first, args ... );
   } else {
      if ( objectp( from ) && stringp( first ) ) {
         call_other( efun::users(), "event_"+ first, from, args ... );
      }                                                               
   }   
/*
   event( efun::users(), first, args ... );
*/
}

void event(mixed ob, string func, mixed rest ...){
  object origin = previous_object(), *bing;
  string name = "event_" + func;
  if(arrayp(ob)){
    ob = filter(ob, (:$1:));
    call_other(ob, name, origin, rest ...);
    return;
  } else if(!objectp(ob))
    return;
 
  call_other(ob, name, origin, rest ...);
  bing = all_inventory(ob);
  bing -= ({origin});
  bing = filter(bing, (:$1:));
  call_other(bing, name, origin, rest ...);
}

