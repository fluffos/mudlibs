// stormy
#include <std.h>
#include <daemons.h>
inherit DAEMON;
int abil();
int cmd_flash(string str)
{
    object ob;
    object *wield;
    int mstr, ostr, b, i, clear;
    string gen, ogen;
    if (!abil())
        return notify_fail("What?\n");
    if (environment(this_player())->query_property("no attack"))
        return notify_fail("Greater powers prevent your malice.\n");
    if (!str || str=="")
        return notify_fail("Flash whom?\n");
    if (this_player()->query_sp() < 50)
        return notify_fail("You are to tired.\n");
    if (this_player()->query_current_attacker())
        return notify_fail("You cannot take the time.\n");
    ob = present(str, environment(this_player()));
    if (!ob) 
        return notify_fail("You do not see that anywhere.\n");
    if (!ob->is_living())
        return notify_fail("Flash only affects living things.\n");
    if (ob->query_property("no stun"))
      return notify_fail("That is immune to your flash.\n");
    if (this_player()->query_disable())
        return notify_fail("You are already in the middle of something else.");
   if(!b=sizeof(wield=(object *)this_player()->query_wielded())) {
        notify_fail("You need a weapon to slash with!\n");
        return 0;
    } 
   i = sizeof(wield);
   clear = 0;
   while (i--) {
     if (wield[i]->query_type() == "blade")
      clear = 1;
   }
  if (!clear) return notify_fail("You need a blade to slash with!\n");
    mstr=this_player()->query_skill("blade")*3/2+(random(this_player()->query_level()/2));
    if (this_player()->query_gender()=="male") gen = "him"; else gen = "her";
    if (ob->query_gender()=="male") ogen = "him"; else ogen = "her";
    ostr = ob->query_skill("defense")*2/3+(random(ob->query_level()/2));
    mstr -= ostr;
    if (mstr < 0)
    {
        write("You fail to flash "+ob->query_cap_name()+" properly.");
        this_player()->kill_ob(ob);
        return 1;
    }
    write("%^BOLD%^You flash your blades at "+ob->query_cap_name()+" blinding "+ogen+" temporarily.");
    say("%^BOLD%^"+this_player()->query_cap_name() + " flashes "+this_player()->query_possessive()+" blades at "+ob->query_cap_name()+" blinding "+ogen+" temporarily.");
    this_player()->set_disable();
this_player()->add_sp(-(this_player()->query_level() * 2));
    ob->set_paralyzed(random(3), "You are still seeing stars.");
    this_player()->kill_ob(ob);
    return 1;
}
int abil()
{
    if (this_player()->query_level() < 10 ) return 0;
    if (this_player()->query_subclass()!="swashbuckler") return 0;
    return 1;
}
void help()
{
    write("Syntax: <flash [opponent]>\n\n"
      "You flash your blades at your opponent, blinding them temporarily.");
}
