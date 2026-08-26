#define MAX_NORMAL 50	/* How much can a normal player's bladder hold */
#define MAX_WIZARDS 100	/* Wizard's can certainly take the piss ;-) */
int content;	/* How full is the bladder? */
string uncomfortable_feelings;
object player;
string himherit;
string hesheit;
int count;

id(str) { return str=="bladder"; }
get() { return 1; }
drop() { return 1; }

reset(str)
{
    content = 0;
    count = 0;
    uncomfortable_feelings = allocate(10);
    uncomfortable_feelings[0] = "You feel a bit strange";
    uncomfortable_feelings[1] = "Your eyes wonder over to the restroom";
    uncomfortable_feelings[2] = "Your bladder feels a bit full";
    uncomfortable_feelings[3] = "You wonder where the toilets are";
    uncomfortable_feelings[4] = "You feel like your bladder is about to burst";
    uncomfortable_feelings[5] = "You wonder if you are going to wet yourself";
    uncomfortable_feelings[6] = "You feel like you need to take a leek";
    uncomfortable_feelings[7] = "The drink has taken it's natural course";
    uncomfortable_feelings[8] = "Where are the toilets, you ask yourself";
    uncomfortable_feelings[9] = "You wish you had a bigger bladder";
}
init(str)
{
    string gender;

    player = this_player();
    add_action("piss", "piss");
    add_action("piss", "pee");
    add_action("piss", "wee");

    gender = player->query_gender_string();
    if(gender == "male") { himherit = "him"; hesheit = "he"; }
    else if (gender == "female") { himherit = "her"; hesheit = "she"; }
    else { himherit = "it"; hesheit = "it"; }
}

add(val)
{
int max;

    if(player->query_level() >= 20) max = MAX_WIZARDS;
    else max = MAX_NORMAL;

    if (content >= max) return;

    content += val;

    if (content >= max)
    {
	write("You feel like you need to go to the toilet.\n");
	say(player->query_name() + " needs to visit the toilet.\n");
	call_out("uncomfortable", 60);
    }
}
uncomfortable()
{
string line;

    if(!count) count = 11;
    else count--;

    if(count == 1)
    {
	piss();
	return;
    }

    line = player->query_name() + " looks " + hesheit + " might wet ";
    line = line + himherit + "self.\n";
    say(line);
    write(uncomfortable_feelings[random(10)] + "\n");
    call_out("uncomfortable", 60);
}
zero()
{
    content = 0;
    catch(remove_call_out("uncomfortable"));
}
piss(str) {
string where;
string tmp1, tmp2;

    zero();

    where = file_name(environment(player));
    sscanf(where,"%stoile%s", tmp1, tmp2);
    if(tmp2 == "t")
    {
	say(player->query_name() + " looks much more relaxed.\n");
	write("You feel much better.\n");
	return 1;
    }
    write("You wet yourself!\nGo to a toilet next time.\n");
    say(player->query_name() + " wets " + himherit + "self.\n");

    return 1;
}
