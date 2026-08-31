/* Do not remove the headers from this file! see /USAGE for more info. */

inherit __DIR__ "death_messages";

void remove();
void simple_action(string);
string query_name();
varargs void stop_fight(object);
void stop_attacking();
void clear_effects();

private
nosave string corpse_long;
private
nosave string corpse_filename = CORPSE;
private
nosave string in_room_singular;
private
nosave string in_room_plural;
private
nosave string drops_pelt;

//: FUNCTION set_drops_pelt
// void set_drops_pelt(string type);
// Sets the pelt type dropped by this adversary. This is normally
// only used for beasts that you would expect to drop pelts.
// In your giraffe, do:
//    set_drops_pelt("giraffe skin");
void set_drops_pelt(string type)
{
   drops_pelt = type;
}

//: FUNCTION query_drops_pelt
// string query_drops_pelt()
// Returns the type of pelt dropped
string query_drops_pelt()
{
   return drops_pelt;
}

nomask string query_default_death_message()
{
   return "$N $vbreathe $p last breath and $vslump to the ground, dead.";
}

//: FUNCTION override_corpse_descriptions
// void void override_corpse_descriptions(string singular,string plural)
// Sets new description for corpses. Not everyone is "lying around".
void override_corpse_descriptions(string singular, string plural)
{
   in_room_singular = singular;
   in_room_plural = plural;
}

//: FUNCTION set_corpse_long
// void set_corpse_long(string str);
// Sets the long description of this adversary's corpse.
void set_corpse_long(string str)
{
   corpse_long = str;
}

string query_corpse_long()
{
   return corpse_long;
}

string in_room_singular()
{
   return in_room_singular;
}

string in_room_plural()
{
   return in_room_plural;
}

//: FUNCTION set_corpse_filename
// void set_corpse_filename(string str);
// Sets the corpse to be cloned to 'str'.
void set_corpse_filename(string str)
{
   corpse_filename = str;
}

string query_corpse_filename()
{
   return corpse_filename;
}

//: FUNCTION drop_corpse
// Replace us with a corpse.
void drop_corpse()
{
   clear_effects();
   LOOT_D->drop_corpse(this_object());
}

protected
void die()
{
   stop_fight(0);
   stop_attacking();
   simple_action(query_death_message());
   drop_corpse(); // subtle pun
   call_out("remove", 1);
}
