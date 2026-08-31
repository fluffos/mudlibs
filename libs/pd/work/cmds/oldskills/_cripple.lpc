// Seeker [Paladin start-off spell]

#include <std.h>
#include <spells.h>

inherit DAEMON;

int spell();

int cmd_cripple(string str)
{ 
 object ob;
 int i;
 if (!spell())
   return notify_fail("What?\n");

 if (!str && !this_player()->query_current_attacker())
   return notify_fail("Cripple who?\n");
 
 if (!ob = this_player()->query_current_attacker())
   ob = present(str, environment(this_player()));
 if (!ob)
   return notify_fail("You dont see that anywhere.\n");
  
if (!spell_check(ob)) return 0; // New, without having to spend 10 minutes working
// on checking ghosts, etc.
 if (this_player()->query_sp() < 10)
   return notify_fail("You are too tired.\n");
 if (this_player()->query_mp() < 10)
   return notify_fail("You are drained of your magic.\n");
 i = this_player()->query_stats("strength")*4/3;
 i += this_player()->query_skill("magic attack")/2;
 i += this_player()->query_skill("attack")/2;
 i -= ob->query_stats("dexterity");
 i -= ob->query_skill("defense")/3;
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
 this_player()->set_casting(i + random(this_player()->query_level()));
 this_player()->set_disable();
 this_player()->add_mp(-i/7);
 write("%^BLUE%^%^BOLD%^The gods crush the life force out of "+ob->query_cap_name()+".");
 message("info", "%^BLUE%^%^BOLD%^"+this_player()->query_cap_name()+ "crushes the life force out of you.", ob);
 message("info", "%^BLUE%^%^BOLD%^"+this_player()->query_cap_name()+ " crushes the life force out of "+ob->query_cap_name()+".", environment(this_player()), ({ this_player(), ob }) );
 return 1; 
}

int spell()
{
 if (this_player()->query_subclass()!="paladin") return 0;
   if (this_player()->query_level() < 5) return 0;
 return 1;
}


void help()
{
 write("Syntax: <cripple>\n\n"
"This is a paladin spell which the caster prays to their god and they "
"assist you by crushing the life-force out of your opponent.");
}

