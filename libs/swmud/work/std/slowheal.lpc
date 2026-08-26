/* Do not remove the headers from this file! see /USAGE for more info. */

/*
 *heal-over-time inheritable for creating cigarettes, drugs and
 *other types of time-based healing stuff
 */

inherit OBJ;
inherit M_GETTABLE;
inherit M_HEALING;

int fuel, healing;
string consume_message, heal_message, expire_message;

int is_slowheal()
{
   return 1;
}

void timed_healing(int remaining);

void set_fuel(int n)
{
   fuel = n;
}

int query_fuel()
{
   return fuel;
}

void set_healing(int n)
{
   healing = n;
}

int query_healing()
{
   return healing;
}

int query_value()
{
   // Don't modify this, since it's balanced against all the other healing types.
   float heal_mod = 0.2;

   return to_int((float)query_fuel() * query_heal_value() * heal_mod);
}

//: FUNCTION set_consume_message
// This is the first message shown when the slowheal is
// first activated. If the message does not begin with '!'
// it is considered an action and simple_action() is used
// for delivery. If it has a '!' it's a private message
// and sent in a tell to the person using the item.
void set_consume_message(string str)
{
   consume_message = str;
}

//: FUNCTION query_consume_message
// Returns the consume message, see also set_consume_message
// for more details on this message.
string query_consume_message()
{
   return consume_message;
}

//: FUNCTION set_heal_message
// This is the interval message shown when the slowheal is
// periodically activated. If the message set begins with '!'
// it is considered an action and simple_action() is used
// for delivery. If it has no '!' it's a private message
// and sent in a tell to the person using the item.
void set_heal_message(string str)
{
   heal_message = str;
}

//: FUNCTION query_consume_message
// Returns the heal message, see also set_heal_message
// for more details on this message.
string query_heal_message()
{
   return heal_message;
}

//: FUNCTION set_expire_message
// This is the last message shown when the slowheal has its
// final activation. If the message does not begin with '!'
// it is considered an action and simple_action() is used
// for delivery. If it begins with '!' it's a private message
// and sent in a tell to the person using the item.
void set_expire_message(string str)
{
   expire_message = str;
}

//: FUNCTION query_expire_message
// Returns the expiry message, see also set_expire_message
// for more details on this message.
string query_expire_message()
{
   return expire_message;
}

void mudlib_setup()
{
   set_id("slowheal");
   set_long("If you see this message, report to a scientist!");
   set_fuel(10);
   set_heal_value(30);
   set_consume_message("You consume a slowheal. If you see this message, report to a scientist!\n");
   set_heal_message("The slowheal heals you. If you see this message, report to a scientist!\n");
   set_expire_message("Slowheal expired. If you see this message, report to a scientist!\n");
}

int direct_consume_obj()
{
   return 1;
}

void do_consume()
{
   object *healers = all_inventory(environment())->query_healing();
   healers -= ({0});
   if (sizeof(healers) > 0)
   {
      tell(this_body(), "You can't use two at once!\n");
      return;
   }
   set_healing(1);
   set_visibility(0);
   if (query_consume_message()[0] == '!')
      tell(this_body(), query_consume_message()[1..] + "\n");
   else
      this_body()->simple_action(query_consume_message());

   set_fuel(query_fuel() - 1);
   timed_healing(10);
}

void timed_healing(int remaining)
{
   if (query_heal_message()[0] == '!')
      this_body()->simple_action(query_heal_message()[1..]);
   else
      tell(this_body(), query_heal_message() + "\n");

   heal_from_slowheal();
   this_body()->abuse_body(1 + random(query_heal_value()));

   if (remaining > 0)
   {
      call_out("timed_healing", 30, remaining - 1);
   }
   else
   {
      if (query_expire_message()[0] == '!')
         tell(this_body(), query_expire_message()[1..] + "\n");
      else
         this_body()->simple_action(query_expire_message());
      set_healing(0);
      this_object()->remove();
   }
}
