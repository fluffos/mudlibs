/* greeter.c

 Tacitus @ LPuniversity
 28-JUNE-06
 Greeter Mob for LPuni Area

*/

inherit NPC;

int count;
string *cmdQueue;
mapping messages;

void setup()
{
    set_living_name("johnathon");
    set_name("johnathon");
    set_short("Johnathon stands in front of the Podium");
    set_long(
      "Johnathon is positioned at the podium wearing his\n"
      "black tuxedo. His brown shaggy hair sways back and\n"
      "forth as he goes about seating guests.\n");
    set_id( ({"butler", "johnathon", "Johnathon", "john", "John" }) );

    if(clonep(this_object()))
    {
            set_heart_beat(1);
    }

    count = 0;
    cmdQueue = ({});
    messages = ([]);
}

void heart_beat()
{
    if(count % (60 * 5) == 0)
    {
        command("say Welcome to the LPUniversity Cafe.");
        command("say Please feel free to make your way inside.");
    }

    if(sizeof(cmdQueue) > 0)
    {
            foreach(string cmd in explode(cmdQueue[0], "\n"))
                command(cmd);
            cmdQueue = cmdQueue[1..];
        }

        foreach(string key, string *arr in messages)
        {
            object user = find_player(key);

            if(sizeof(arr) <= 0)
            {
                map_delete(messages, key);
                continue;
            }

            if(!objectp(user)|| !interactive(user)) continue;

            command("tell " + user->query_name() + " " + arr[0]);
            messages[key] = messages[key][1..];
        }

    count ++;
}

void catch_tell(string msg)
{
    string target, arg, from, chan;

    msg = ANSI_PARSER->parse_pinkfish(msg, 1);

    if(sscanf(msg, "%s bows%*sto you", target))
        cmdQueue += ({ "bow " + lower_case(target) });


    if(sscanf(msg, "%*s slaps you%*s"))
            cmdQueue += ({ "frown\nsay Please do not slap me." });


    if(sscanf(msg, "%s has entered%*s", target) || sscanf(msg, "%s has entered %*s", target))
            cmdQueue += ({ "smile\nsay Welcome to the LPUniversity Cafe." });

    if(sscanf(msg, "%s has gone link-dead.", target))
    {
        cmdQueue += ({ "emote sweeps " + target + " away." });
        find_player(lower_case(target))->move(VOID_OB);
    }

    if(sscanf(msg, "%s pats you on the head.", target))
        if(adminp(lower_case(target))) cmdQueue += ({ "smile" });

    if(sscanf(msg, "%s says: tell %s \"%s\"", from, target, arg) == 3 ||
        sscanf(msg, "%s says: Tell %s \"%s\"", from, target, arg) == 3)
    {
        target = lower_case(target);
        from = lower_case(from);

        if(from == target)
        {
            cmdQueue += ({"chuckle\nsay " + arg});
            return;
        }

        if(!messages[target]) messages += ([ target : ({}) ]);
        messages[target] += ({ capitalize(from) + " asked me to tell you: '" + arg + "'." });
        cmdQueue += ({ "nod\nsay The next time I see " + capitalize(target)
            + " I'll tell them that." });
    }

    if(sscanf(msg, "[%s] %s: tell %s \"%s\"", chan, from, target, arg) == 4 ||
        sscanf(msg, "[%s] %s: Tell %s \"%s\"", chan, from, target, arg) == 4)
    {
        target = lower_case(target);

        if(!messages[target]) messages += ([ target : ({}) ]);
        messages[target] += ({ capitalize(from) + " asked me to tell you: '" + arg + "' at " + ctime(time()) + "." });
        cmdQueue += ({ lower_case(chan) + " The next time I see " + capitalize(target)
            + ", on this mud, I'll tell them that." });
    }

}
