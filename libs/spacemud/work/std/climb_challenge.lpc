/* Do not remove the headers from this file! see /USAGE for more info. */

inherit EXIT_OBJ;

#define REFLEX_USE_FACTOR 5

private
string challenge_name = "";
private
int challenge_rating = 100;
private
string *fail_messages = ({});
private
string direction;

mixed direct_get_obj(object ob)
{
   return "#Try climbing it instead.";
}

mixed direct_climb_obj()
{
   return "Climb up or down the " + challenge_name + "?";
}

void set_fail_climb_message(string *m)
{
   fail_messages = m;
}

int reflex_use()
{
   return to_int(challenge_rating / REFLEX_USE_FACTOR) || 1;
}

int handle_fail(string action, string rule, string prep, object ob)
{
   int max_dam = this_body()->query_health("torso") - 2;
   // Fail climb
   if (random(2))
   {
      this_body()->simple_action(fail_messages[1]);
      this_body()->hurt_us(max_dam);
      return ::do_verb_rule(action, rule, prep, ob);
   }
   else
   {
      this_body()->simple_action(fail_messages[0]);
      this_body()->hurt_us((max_dam / 2));
      return ::do_verb_rule(action, rule, prep, ob);
   }
}

int do_verb_rule(string action, string rule, string prep, object ob)
{
   // You can always climb if you just have 5 point of mana.
   if (action == "ascend" && this_body()->query_reflex() < 5)
   {
      write("You cannot concentrate enough to climb this.\n");
      return;
   }

   if (action == "descend" && this_body()->query_reflex() < 5)
   {
      return handle_fail(action, rule, prep, ob);
   }

   this_body()->spend_reflex(reflex_use());

   if (this_body()->test_skill("misc/life/climbing", challenge_rating))
   {
      return ::do_verb_rule(action, rule, prep, ob);
   }
   else
   {
      return handle_fail(action, rule, prep, ob);
   }
}

int can_ascend()
{
   return direction == "up";
}

int can_descend()
{
   return direction == "down";
}

varargs protected void setup_messages(string name, string dir, mixed dest, int cr)
{
   string dirs;
   direction = dir;
   if (dest && direction == "up")
      add_method("ascend", dest, 0, ({sprintf("$N $vclimb up the $o.")}),
                 ({sprintf("$N $vclimb up the $o from below.")}));
   else if (dest && direction == "down")
      add_method("descend", dest, 0, ({sprintf("$N $vclimb down from the $o.")}),
                 ({sprintf("$N $vclimb down the $o from up above.")}));

   add_id(name);
   challenge_rating = cr;
   set_long(sprintf("The %s %s %s", name, query_plural() ? "lead" : "leads", dirs));
   set_in_room_desc(sprintf("There %s %s here, leading %s.", query_plural() ? "are " : "is a ", name, dirs));
}

void mudlib_setup(string name, string direction, mixed dest, int cr)
{
   ::mudlib_setup();
   challenge_name = name;
   setup_messages(challenge_name, direction, dest, cr);
   set_base(( : environment() :));
   set_attached(1);
}
