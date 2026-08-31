/* Do not remove the headers from this file! see /USAGE for more info. */

//: PLAYERCOMMAND
// USAGE
//    ``spells [level]``
//    ``spells [spell]``
//
// List spells available to the player.  If a level is specified, only
// spells of that level are listed. If a spell is specified, details
// about that spell are shown.
//
// .. TAGS: RST

inherit CMD;
inherit M_FRAME;
inherit CLASS_SKILL;

private
spell_sort(mixed a, mixed b)
{
   return a->query_level() - b->query_level() + (a->query_category() > b->query_category());
}

string spell_name_colour(string name)
{
   object spell_ob;
   int level, rank;
   if (!name || name == "")
      return "<196>";
   spell_ob = load_object(SPELL_D->query_spell_obname(name));
   level = spell_ob->query_level();
   rank = SKILL_D->skill_rank(this_body(), "magic/" + spell_ob->query_category() + "/" + spell_ob->query_name());

   if (level == 0)
      return "<081>"; // Cantrip

   switch (level - rank)
   {
   case -100..0:
      return "<118>"; // Easy, will succeed
   case 1:
      return "<220>"; // Little too hard, might succeed
   case 2..100:
      return "<196>"; // Too hard, will fail
   }
}

void spell_lookup(string spell)
{
   frame_init_user();
   set_frame_title(sprintf("Spell details for %s", spell));
   set_frame_header(0);
   set_frame_footer(0);
   set_frame_content(load_object(SPELL_D->query_spell_obname(spell))->query_description());
   out(frame_render());
}

// Function to list all spells
void list_spells(mixed arg)
{
   mixed *spells = values(SPELL_D->query_spell_table());
   mapping ranks = ([]);
   int num_spells;
   spells = map(spells, ( : load_object($1) :));
   spells = sort_array(spells, ( : spell_sort:));

   if (member_array(arg, keys(SPELL_D->query_spell_table())) != -1)
   {
      spell_lookup(arg);
      return;
   }

   if (stringp(arg))
   {
      arg = to_int(arg);
      spells = filter(spells, ( : $1->query_level() == $(arg) :));
   }
   else
   {
      arg = -1;
   }

   num_spells = sizeof(spells);
   if (!num_spells)
   {
      out("No level " + arg + " spells found.\n");
      return;
   }

   foreach (object s in spells)
   {
      string cat = s->query_category();
      string name = s->query_name();
      string skill = "magic/" + cat + "/" + name;
      class skill sk = this_body()->query_skill(skill);
      int rank;
      if (!sk)
         ranks[name] = "";
      else
         ranks[name] = SKILL_D->skill_title_from_pts(sk.skill_points);
   }

   frame_init_user();
   set_frame_title(sprintf("Available Spells - %d ", num_spells));

   frame_add_column("Name", spells->query_name(), ( : spell_name_colour:));
   frame_add_column("S", map(spells->query_name(), ( : $(ranks)[$1] :)));
   frame_add_column("Level", map(spells->query_level(), ( : !$1 ? "Cantrip" : "" + $1:)));
   frame_add_column("Category", map(spells->query_category(), ( : capitalize($1) :)));
   frame_add_column("Reflex", spells->reflex_string());

   frame_add_column("Cast Time", spells->cast_time_string());
   frame_add_column("Targets", map(spells, ( : $1->target_to_str() :)));
   frame_add_column("Channeled", map(spells, ( : $1->is_channeled() ? "Yes" : "No" :)));
   frame_add_column("Channel interval", map(spells, ( : $1->is_channeled() ? $1->query_channeling_interval() : "-" :)));
   set_frame_footer("Use 'cast <spell>' to cast a spell, use e.g. 'spells " + choice(spells)->query_name() +
                    "' for details about that spell.\n"
                    "<081>Not a challenge<res> - <118>Easy<res> - <220>Medium<res> - <196>Hard<res> to cast");
   out(frame_render_columns());
}

private
void main(string arg)
{
   list_spells(arg);
   return 0;
}