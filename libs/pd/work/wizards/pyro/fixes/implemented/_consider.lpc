#include <std.h>
inherit DAEMON;

int cmd_consider(string str)
{
    int comp;
    object ob;
    string subjec, objec, possess;
    if (!str || str=="")
    {
        write("Consider who?");
        return 1;
    }
    ob = present(str, environment(this_player()));
    if (!ob)
    {
        write("Consider who?");
        return 1;
    }
    if(!ob->is_living()) return 
        notify_fail("How hard would it be to beat up an inanimate object?\n");
    comp = ob->query_level()-this_player()->query_level();
    subjec = ob->query_subjective();
    objec = ob->query_objective();
    possess = ob->query_possessive();
    if(this_player()->query_level() < 8)
        comp += 5;
    comp += sizeof(ob->query_spells());
    if (comp > 35)
       switch(random(6)) {
          case 0:
            write(capitalize(subjec)+" would rip off your arm and beat you with the bloody stump!");
            break;
          case 1:
           write("You wouldn't live long enough to regret the day you decided to attack "+objec+".");
            break;
          case 2:
            write(capitalize(subjec)+" might be able to kill you just by sneezing at you.");
            break;
          case 3:
            write("You might not walk away from the fight even if "+subjec+" were already dead to begin with.");
            break;
          case 4:
            write("You would consider "+objec+", but merely looking at "+objec+" may result in your death.");
           break;
          case 5:
            write("Think of it this way. You should spend the rest of your life making sure "+subjec+" never finds out you considered attacking "+objec+".");
        } 
    else if (comp > 30)
       switch(random(3)) {
          case 0:
            write("You would be beaten into the ground in just a few swings.");
            break;
          case 1:
            write("You would be torn limb from limb!");
            break;
          case 2:
            write("If you're fast enough, you may be able to scratch "+objec+" a few times before being annihilated.");
            break;
        }
    else if (comp > 25)
       switch(random(3)) {
          case 0:
            write("You would fare better if there were three... or four... or five of you.");
            break;
          case 1:
            write("You need an army of friends to kill "+objec+".");
            break;
          case 2:
            write("It would be wiser to mark yourself up and pretend to have fought them.");
            break;
        }
    else if (comp > 20)
       switch(random(3)) {
          case 0:
            write("You would have to be extremely lucky to kill "+objec+", and even then you would be gravely injured.");
            break;
          case 1:
            write("You shouldn't try to kill "+objec+" without a friend or two.");
            break;
          case 2:
            write("You would be a fool to take "+objec+" on.");
            break;
        }
    else if (comp > 15)
      switch(random(3)) {
          case 0:
            write("Don't fight "+objec+" unless you absolutely have to.");
            break;
          case 1:
            write("You would most likely die.");
            break;
          case 2:
            write("If you're planning on taking them on alone, make sure your will is made out.");
            break;
        }
    else if (comp > 10)
        switch(random(3)) {
          case 0:
            write("Be careful if you decide to fight "+objec+", and don't be afraid to run.");
            break;
          case 1:
            write("You might die.");
            break;
          case 2:
            write("Make sure you have some first aid ready.");
            break;
        }
    else if (comp > 5)
        switch(random(3)) {
          case 0:
            write("You could probably take "+objec+" in a fair fight.");
            break;
          case 1:
            write("A perfect match!");
            break;
          case 2:
            write("Go for it.");
            break;
        }
    else if (comp > 2)
        switch(random(2)) {
          case 0:
            write("You shouldn't have a problem killing "+objec+".");
            break;
          case 1:
            write("You would most likely kill "+objec+".");
            break;
        }
    else if (comp > -5)
        switch(random(3)) {
          case 0:
            write("You should be more worried about which hand you want to tie behind your back while you're killing "+objec+".");
            break;
          case 1:
            write("You wouldn't even break a sweat.");
            break;
          case 2:
            write(capitalize(subjec)+" poses no threat to you.");
            break;
        }
    else
        switch(random(7)) {
          case 0:
            write(capitalize(subjec)+" is too weak for you to even be able to accurately compare "+possess+" strength to your own.");
            break;
          case 1:
            write("Pshaw! Why even bother considering?");
            break;
          case 2:
            write("Should you really be wasting your time beating up children?");
            break;
          case 3:
            write("Why don't you check out some anger management classes?");
            break;
          case 4:
            write("Whatever "+subjec+" did, it couldn't have been bad enough to make "+objec+" deserve such punishment.");
            break;
          case 5:
            write("You may be physically strong enough, but if you go through with it then you don't have very much inner strength.");
            break;
          case 6:
            write("You could slam "+objec+" into the ground with one finger.");
            break;
        }

    write(strip_color((string)ob->query_long_health()+""));
    if(member_group(this_player()->query_name(), "ambassador") ||
      wizardp(this_player()))
        write("HP: "+ob->query_hp()+"/"+ob->query_max_hp()+
          " Lev: "+ob->query_level());
    return 1;
}
int help()
{
    write(@EndText
Syntax: consider [monster]
Effect: allows you to know if you have a chance of killing a monster.
EndText
    );
    return 1;
}
