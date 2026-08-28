inherit GUILD;

create_guild ()
{
  set_name (({"a master linguist", "linguist", "master linguist"}));
  set_short ("a master linguist is talking many languages");
  set_long ("He is the master linguist, the guild master of linguistics.\n");
  set_levels (([ "fighter" : 100, "caster" : 100 ]));
  set_race ("ogre");
   set_guild ("Hilltop's Linguistics");
   set_titles (({ "linguist", "master linguist" }));

   add_req_skill ("sartog", ({ 50, 75 }));

   add_avail_skill ("alande", ({ 50, 100 }));
   add_avail_skill ("kvanya", ({ 50, 100 }));
   add_avail_skill ("uruzden", ({ 50, 100 }));

   add_avail_skill ("draz", ({ 50, 100 }));

   add_avail_skill ("ohrim", ({ 50, 100 }));
   add_avail_skill ("palen", ({ 50, 100 }));
   add_avail_skill ("grahnik", ({ 50, 100 }));
   add_avail_skill ("hgrzag", ({ 50, 100 }));
   add_avail_skill ("sartog", ({ 75, 125 }));

   add_avail_skill ("choui", ({ 50, 100 }));
   add_avail_skill ("yavahe", ({ 50, 100 }));
   add_avail_skill ("ugal", ({ 50, 100 }));
   add_avail_skill ("tzhimsal", ({ 50, 100 }));
   add_avail_skill ("yiunda", ({ 50, 100 }));

   set_guild_desc ("No description available.\n");
  set_skill_chance ("dodge", 75);
}

  init_guild ()
   {
     add_action("do_train","train");
     add_action("do_info","info");
     add_action("do_advance","advance");
     add_action("do_join","join");
    }
