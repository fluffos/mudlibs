inherit "obj/weapon";
object ob;
int can_heal;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("staff");
                set_class(10);
                set_value(1000);
                set_weight(7);
                set_alias("staff");
                set_short("Staff of Elrond");
can_heal=8;
set_long(
"This powerfully enchanted staff once beloned to Elrond the King of the\n"+
"Elves. It has been reputed to have amazing healing properties which\n"+
"have kept King Elrond alive for so long. Unfortunately the words that\n"+
"trigger the magic are written on the staff in a language that has long\n"+
"past from the land. Maybe they are written down somewhere.\n");
}
}
init()
{
::init();
if(environment() == this_player()) add_action("do_heal", "heal");
if(environment() == this_player()) add_action("do_tonic", "transfer"); ;
}
do_heal(str)
{
ob=this_player()->query_money();
if(ob <= 2999)
{
write("You dont have enough cash.\n");
return 1;
}
if(!str) return 0;
if(str == "hp")
{
write("The staff dissolves some of your gold coins and turns them into hit points.\n");
this_player()->add_hit_point(50);
this_player()->add_money(-3000);
can_heal -=1;
}
if(str == "sp")
{
write("The staff dissolves some of your gold coins and turns them into spell points.\n");
this_player()->add_spell_point(50);
this_player()->add_money(-3000);
can_heal -=1;
}
if(str == "both")
{
write("The staff has dissolved a substantial amount of gold coins and, you guessed it, turns it into both hp and sp.\n");
this_player()->heal_self(50);
this_player()->add_money(-5000);
can_heal -=2;
}
if(can_heal<1)
{
write("Staff fades away.\n");
destruct(this_object());
}
return 1;
}
do_tonic()
{
ob=this_player()->query_sp();
if(ob < 100)
{
write("You dont have enough spell points to transfer.\n");
return 1;
}
write("You transfer some spell points to hit points.\n");
this_player()->add_hit_point(50);
this_player()->add_spell_point(-100);
return 1;
}
