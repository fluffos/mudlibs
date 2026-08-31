#include <teststd.h>

inherit OBJECT;

int _Uses, _Elite;
string _Action, _YourMessLimb, _YourMessAll, _TheirMessLimb, _TheirMessAll;

void set_your_mess_limb(string);
void set_your_mess_all(string);
void set_their_mess_limb(string);
void set_their_mess_all(string);
void set_action(string);
void set_elite(int);
int query_elite();
int fApply(string);
private string replace_dollar(string, object, string);

void create()
{
    ::create();
    _Uses = 20;
    _Elite = 0;
    _Action = "apply $I";
    _YourMessLimb = "!ERROR! The coder did not provide a message.";
    _YourMessAll = "!ERROR! The coder did not provide a message.";
    _TheirMessLimb = "!ERROR! The coder did not provide a message.";
    _TheirMessAll = "!ERROR! The coder did not provide a message.";
}

int set_id(string* strs)
{
    if( member_array("ointment_check", strs) == -1 )
        strs += ({"ointment_check"});
    return ::set_id(strs);
}

string query_short()
{
    string str = ::query_short() + " %^RESET%^(";
    
    switch(_Uses)
    {
        case 1: str += "one"; break;
        case 2: str += "two"; break;
        case 3: str += "three"; break;
        case 4: str += "four"; break;
        case 5: str += "five"; break;
        case 6: str += "six"; break;
        case 7: str += "seven"; break;
        case 8: str += "eight"; break;
        case 9: str += "nine"; break;
        case 10: str += "ten"; break;
        case 11: str += "eleven"; break;
        case 12: str += "twelve"; break;
        case 13: str += "thirteen"; break;
        case 14: str += "fourteen"; break;
        case 15: str += "fifteen"; break;
        case 16: str += "sixteen"; break;
        case 17: str += "seventeen"; break;
        case 18: str += "eighteen"; break;
        case 19: str += "nineteen"; break;
        case 20: str += "twenty"; break;
    }
    
    if(_Uses > 1)
	   str += " uses left)";
    else
	   str += " use left)";
    
    return str;
}

void init()
{
    ::init();
    add_action("fApply", explode(_Action, " ")[0]);
}

void set_elite(int flag) { _Elite = flag; }

int query_elite() { return _Elite; }

void set_action(string str) { _Action = str; }

void set_your_mess_limb(string str) { _YourMessLimb = str; }

void set_your_mess_all(string str) { _YourMessAll = str; }

void set_their_mess_limb(string str) { _TheirMessLimb = str; }

void set_their_mess_all(string str) { _TheirMessAll = str; }

int fApply(string str)
{
    string nfail = "Correct syntax: <" +
        replace_string(_Action, "$I", this_object()->query_id()[0])
        + " [(limb) or 'all']>\n";
    string what, limb;
    string apply = _Action;
    
    if( !str )
        return notify_fail(nfail);
    
    if( this_player()->query_disable() )
        return notify_fail("You are too busy doing something else.\n");
    
    if( this_player()->query_paralyzed() || this_player()->query_magic_round()
            || this_player()->query_casting() )
    {
	   return notify_fail(this_player()->query_paralyze_message());
    }
    
    if( strsrch(apply, "$I") != -1 )
    {
        apply = replace_string(apply, "$I", "%s") + " %s";
        if( sscanf(query_verb() + " " + str, apply, what, limb) != 2 ||
            member_array(what, this_object()->query_id()) == -1 )
        {
            return notify_fail(nfail);
        }
    }
    else
    {
        if( sscanf(query_verb() + " " + str, apply, limb) != 1 )
            return notify_fail(nfail);
    }
    
    if( limb == "all" )
    {
	    string* limbs = (string *)this_player()->query_limbs();
        int i = sizeof(limbs);
        while(i--)
        {
            this_player()->set_disable();
	        if( !_Elite )
	        {
                this_player()->heal_limb(limbs[i], 25+random(25));
                this_player()->add_sp(50+random(45)+random(45));
            }
            else
            {
                this_player()->heal_limb(limbs[i], 40+random(20));
                this_player()->add_sp(80+random(40)+random(40));
            }
	        message("oint", replace_dollar(_YourMessAll, this_player(), 0),
                    this_player());
            message("oint", replace_dollar(_TheirMessAll, this_player(), 0),
                    environment(this_player()), this_player());
	        _Uses--;
	        if(_Uses <= 0)
                this_object()->remove();
            return 1;
        }
    }
    
    if( member_array(limb, this_player()->query_limbs()) == -1 )
    {
        if( !sizeof(this_player()->query_severed_limbs()) 
            || member_array(limb, this_player()->query_severed_limbs()) == -1 )
        {
            return notify_fail("You don't have such a limb!\n");
        }
        return notify_fail("That limb is missing!\n");
    }

    this_player()->set_disable();
    message("oint", replace_dollar(_YourMessLimb, this_player(), limb),
            this_player());
    message("oint", replace_dollar(_TheirMessLimb, this_player(), limb),
            environment(this_player()), this_player());
    if( !_Elite )
    {
        this_player()->heal_limb(limb, 50+random(50));
        this_player()->add_sp(35+random(20)+random(20));
    }
    else
    {
        this_player()->heal_limb(limb, 75+random(40));
        this_player()->add_sp(55+random(15)+random(15));
    }
    _Uses--;
    if(_Uses <= 0)
        this_object()->remove();
    return 1;
}

private string replace_dollar(string str, object tp, string limb)
{
    string new_str = str;
    
    if( !new_str || !tp || !tp->is_living() )
        return new_str;
    
    new_str = replace_string(new_str, "$N", tp->query_cap_name());
    new_str = replace_string(new_str, "$O", tp->query_objective());
    new_str = replace_string(new_str, "$S", tp->query_subjective());
    new_str = replace_string(new_str, "$P", tp->query_possessive());
    if( sizeof(limb) )
        new_str = replace_string(new_str, "$L", limb);
    
    return new_str;
}

