#include <std.h>
inherit MONSTER;
void create() {
::create();
set_name("child");
set_short("a crying child");
set_long("The child is talking of a diamond he lost.");
set_gender("male");
set("race", "human");
set_body_type("human");
set_level(1);
set_emotes(3,({
"%^CYAN%^the child says: %^RESET%^I cant believe i lost it!",
"%^CYAN%^the child says: %^RESET%^I think i droped my green diamond in a forest",
"%^CYAN%^the child says: %^RESET%^Please help me find it!",
}),0);
set_id(({"child", "crying child"}));
}
void check_valid(string *what)
{
  object tp, ob;
 string who, that;
 who = what[0];
 that = what[1];
 tp = present(who, environment(this_object()));
 ob = present("green_diamond_event_whit");
 if (!ob || !tp) return;
 ob->remove();
this_object()->force_me("say Thank you so much "+this_player()->query_cap_name()+
".  Now i can succeed in making my army of darkness and rule the world!.");
this_player()->move_player("/wizards/whit/quest/rooms/cave1");
}
void catch_tell(string str)
{
 object ob;
 string a, b;
 if(this_player() == (ob = this_object())) return;
    if(sscanf(str, "%s gives%s", a, b) == 2)
   call_out("check_valid", 2, ({ lower_case(a), lower_case(b) }) );
}
