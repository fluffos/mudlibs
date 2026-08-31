/* Do not remove the headers from this file! see /USAGE for more info. */

// Folded out from DOOR.   --OH. (Around 1996)

//: MODULE
// This module handles an object that has a corrsponding sibling. Typically used for doors, where two door objects in
// two different rooms should act as one object. Could also be used for teleporters, one-way mirrors, and other things
// where the object is on two rooms, but should be considered as one object. Elevator doors use this functionality as
// well.
//
// Note: setup_door() is deprecated. Use this approach instead:
//
// .. code-block:: c
//   set_sibling_ident("oak door");
//   set_door_direction(dir);
//   set_door_destination(room);
//
// .. TAGS: RST

private
string our_ident;
private
function sibling_room;
private
object cached_sibling;

//: FUNCTIOn setup_sibling
// A quick way to change the sibling of this object. An elevator door
// changes siblings as it moves through its destinations.
void setup_sibling(string ident, mixed room)
{
   if (ident)
      our_ident = ident;
   if (stringp(room))
      sibling_room = ( : absolute_path($(room), environment()) :);
   else
      sibling_room = room;

   cached_sibling = 0;
}

//: FUNCTION set_sibling_ident
// Set the ID the siblings will be using.
void set_sibling_ident(string ident)
{
   if (ident)
      our_ident = ident;

   cached_sibling = 0;
}

//: FUNCTION set_sibling_room
// Set the room of the sibling. This can either be an object or a string. If a string
// it will then be loaded as an object.
void set_sibling_room(mixed room)
{
   if (stringp(room))
      sibling_room = ( : absolute_path($(room), environment()) :);
   else
      sibling_room = room;

   cached_sibling = 0;
}

//: FUNCTION respond_to_sibling_ident
// For the siblings to be able to find each other, this public function returns
// true if the ident matches.
int respond_to_sibling_ident(string id)
{
   return our_ident == id;
}

//: FUNCTION get_sibling
// From a given object, return the sibling object. Usefor for responding to things
// that happens to the sibling object or vice versa.
object get_sibling()
{
   if (!environment())
   {
      return 0;
   }
   if (!cached_sibling)
   {
      object ob;
      if (!sibling_room || !evaluate(sibling_room))
         return 0;
      ob = load_object(evaluate(sibling_room));

      if (!ob)
         return 0;

      foreach (object ob2 in all_inventory(ob))
      {
         if (ob2->respond_to_sibling_ident(our_ident))
         {
            cached_sibling = ob2;
            break;
         }
      }
   }
   return cached_sibling;
}

//: FUNCTION update_sibling
// After a door is opened or closed, this is called, and in turn calls
// do_on_open/close() in the door and its sibling.
void update_sibling()
{
   object ob;
   if (ob = get_sibling())
      ob->update_state(this_object());
}

void update_state(object ob)
{
   // Insert stuff to sync
}

private
void initial_move()
{
   object ob;
   // when we initially get moved to a room, check if our sibling already
   // exists, and if so, get it's state.
   if (ob = get_sibling())
      update_state(ob);
}