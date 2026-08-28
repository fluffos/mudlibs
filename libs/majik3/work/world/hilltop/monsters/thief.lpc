inherit GUILD;

init_guild()
{
  add_action("do_info","info");
  add_action("do_join","join");
  add_action("do_advance","advance");
 add_action("do_train","train");
 }
create_guild ()
{
    set_name(({"a fellow","fellow","pale-skinned fellow","pale fellow","sneaker","man"}));
 set_guild ("Hilltop's Sneakers");
 set_titles (({ "sneaker", "master sneaker" }));

 add_avail_skill("pick pockets", ({ 35, 75 }));
 add_avail_skill("pick locks", ({ 0, 25 }));
 add_avail_skill ("sneak", ({ 15, 75 }));
 add_avail_skill ("hiding", ({ 10, 50 }));
 add_avail_skill ("awareness", ({ 0, 65 }));

 add_req_skill ("sneak", ({ 0, 10 }));
 add_req_skill ("hiding", ({ 0, 5 }));
 add_req_skill ("pick pockets", ({ 0, 25 }));

 set_guild_desc ("Hilltop's Sneakers is a test-guild which is always under construction. Join us if you feel ready to face many nasty bugs.\n");
 set_custom_advance_msg("The fellow smiles and announces your new title, [title]!\n");

    set_short("A pale-skinned fellow is quietly standing in the shadows");
    set_long("He is a young and agile man, clad in a black hooded cloak.\n");
    set_race ("thari");
    set_gender (1);
    set_aligny (-1000 + random(500));
    set_alignx (-250 + random(250));
    set_levels ((["fighter" : 25, "caster" : 15]));
    set_skill_chance("dodge", 85 + random(10));
    set_skill_chance("pick pockets", 100);
    set_skill_chance("sneak", 100);
    set_skill_chance("pick locks", 100);

    set_talk (({
	"Psst! I know how to pick pockets.",
	"I can teach you basics of stealing - only 10 gold pieces!",
	"Join us and become a great sneaker!"
      }));

    set_emote (({
	"A fellow sneaks behind you.",
	"A fellow sneaks in front of you.",
	"A fellow sneaks in your left side.",
	"A fellow sneaks in your right side.",
	"A fellow sneaks around the room.",
	"A fellow steals something from you.",
	"A fellow looks hungrily at your money pouch.",
	"A fellow points at you and mumbles in a sinister voice 'Luuska!'",
	"A fellow whispers silent prayer to the god of thieves.",
	"A fellow examines you carefully."
      }));

    set_msgin ("sneaks in");
    set_msgout ("sneaks");
}
