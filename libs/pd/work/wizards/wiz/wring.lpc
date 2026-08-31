// wedding ring re-written by wiz 10/14/04

#include <std.h>

inherit ARMOUR;

string describe_short();

void
create()
{
        ::create();

        set_name("A wedding ring");
        set_short((: describe_short() :));
        set_long("A solid gold ring.  There is an inscription on it.");
        set_id( ({ "ring", "wedding ring" }) );

        set_ac(1);
        set_type("ring");
        set_limbs( ({ "left hand" }) );

        set_weight(1);
        set_value(10000);
}

int
init()
{
        ::init();

        if (environment(this_object())->is_player() && environment(this_object()) == this_player() && this_player()->query_married()) {
                // "honey" line, and thoughtful notification
                add_action("notify_spouse", "honey");

                // actions for jealousy notices
                add_action("jealous_action", "kiss");
                add_action("jealous_action", "wink");
                add_action("jealous_action", "nibble");
                add_action("jealous_action", "cuddle");
                add_action("jealous_action", "french");
                add_action("jealous_action", "snuggle");
                add_action("jealous_action", "love");
                add_action("jealous_action", "lick");
                add_action("jealous_action", "grope");
                add_action("jealous_action", "fondle");

                notify_spouse("I'm home.");
                call_out("wear", 2, "ring");
        }
}

string
describe_short()
{
        if (environment(this_object())->is_player() && environment(this_object())->query_married())
                return environment(this_object())->query_cap_name()+"'s wedding ring";
        else
                return "A wedding ring";
}

int
notify_spouse(string str)
{
        string spouse = this_player()->query_current_marriage()[0];

        if (!find_living(spouse)) {
                notify_fail(spouse+" is not around.");
        } else if (!str) {
                tell_object(find_living(spouse) , "%^BOLD%^%^RED%^"+this_player()->query_cap_name()+" is thinking about you!");
                tell_object(this_player(), "%^BOLD%^%^RED%^You let your spouse know you're thinking about them.%^RESET%^");
        } else {
                tell_object(find_living(spouse), this_player()->query_cap_name()+" %^BOLD%^%^RED%^<honey>%^RESET%^ "+str);
                tell_object(this_player(), this_player()->query_cap_name()+" %^BOLD%^%^RED%^<honey>%^RESET%^ "+str);
        }

        return 1;
}

int
jealous_action(string arg)
{
        string str, target, spouse = this_player()->query_current_marriage()[0];
        int i;

        if (!arg)
                return 0;

        i = strsrch(arg, ' ');

        if (i > 0)
                target = arg[0..(i - 1)];
        else
                target = arg;

        if (!find_living(spouse) || !find_living(target) || find_living(target) == find_living(spouse))
                return 0;

        switch (query_verb()) {
                case "kiss":    i = 1;
                case "wink":    i = 1;
                case "nibble":  i = 2;
                case "cuddle":  i = 2;
                case "french":  i = 3;
                case "snuggle": i = 3;
                case "love":    i = 3;
                case "lick":    i = 3;
                case "grope":   i = 3;
                case "fondle":  i = 3;

                default:        tell_object(this_player(), "verb is -"+query_verb()+"-"); return 0;
        }

        switch (i) {
                case 1: str = " is flirting with "+target+"!";
                case 2: str = " is fooling around with "+target+"!";
                case 3: str = " is sleeping around with "+target+"!";
        }

        tell_object(find_living(spouse), "%^BOLD%^%^RED%^A little bird tells you:%^RESET%^ "+this_player()->query_cap_name()+str);
        return 0;
}

string extra_look() { return this_player()->query_cap_name()+" is married to "+this_player()->query_current_marriage()[0]+"\n"; }
int query_auto_load() { return 1; }
int drop() { return 1; }
int remove() { return 1; }
