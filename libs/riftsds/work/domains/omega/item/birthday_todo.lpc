inherit ITEM_QUEST_TODO;

void setup()
{
   ::setup();
   add_id("birthday_list");
   set_title("Doc. Green's Colleagues");
   set_entries((["1":"Find Dr. Nelson in the canteen area on the 3rd floor",
                 "2":"Find Dr. Williams, he should be in his favourite café in the Landing Terminal, Stellar Bites, "
                     "around this time or in the medical center on the same floor.",
   ]));
   set_synonyms((["canteen":"1", "landing terminal":"2"]));
}

mixed query_hint()
{
   return ({
       "You have a list of items in your inventory (think \"to do list\"). These items will track your progress in "
       "quests and other tasks on " +
           mud_name() + ".",
       "Be sure to see the index of items by doing 'look at list' and then 'read 1 on list' or 'read canteen on list', "
       "so either an index number or a name from the index.",
   });
}