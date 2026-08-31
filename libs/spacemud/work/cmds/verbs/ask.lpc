/* Do not remove the headers from this file! see /USAGE for more info. */

//: COMMAND
// USAGE
//
//  |  ``ask <someone> about <something>``
//  |  ``ask about <something>``
//  |  ``ask biff about sword``
//
// For asking vendors about their goods.
//
// .. TAGS: RST

inherit VERB_OB;

mixed do_ask_liv_about_wrd(object liv, string item)
{
   string items = liv->ask_about_items(item);
   if (items)
   {
      write(liv->short() + " says: " + items);
   }
   else
      write(liv->short() + " has no opinion on that.");
}

mixed do_ask_liv_about_str(object liv, string item)
{
   string items = liv->ask_about_items(item);
   if (items)
   {
      write(liv->short() + " says: " + items);
   }
   else
      write(liv->short() + " has no opinion on that.");
}

mixed do_ask_about_str(string item)
{
   object *respondents = filter_array(all_inventory(environment(this_body())), ( : $1->direct_ask_liv_about_str() :));

   switch (sizeof(respondents))
   {
   case 0:
      write("Nobody seems to want to be asked about " + item + " here?");
      break;
   case 1:
      write("(Asking " + respondents[0]->short() + ")");
      do_ask_liv_about_str(respondents[0], item);
      break;
   default:
      write("Ask " + format_list(map(respondents, ( : $1->short() :)), "or") + "?");
      break;
   }
}

void create()
{
   add_rules(({"LIV about WRD", "LIV about STR", "about STR"}), ({}));
}
