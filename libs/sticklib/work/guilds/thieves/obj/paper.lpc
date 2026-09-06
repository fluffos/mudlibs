// Accept form

inherit "/basic/id";

// Time before one can be accepted
// TEN (12) hours for now!
#define ACCEPT_TIME     (30 * 60 * 12)

#define TP this_player()

string *sig;
int gtime;

void
create()
{
    set_name("accept form");
    set_short("Accept form");
    set_id(({ "form", "thief_accept_form", "paper" }));
    set_long(
      "This is an official form to be filled when accepting someone \
to the Guild of Thieves. Try 'read form' for more information.");
    sig = ({ "0", "0", "0" });
    gtime = ACCEPT_TIME;
    set_heart_beat(1); // AARGH!!
}

void set_gtime(int g) { gtime = g; }

void
heart_beat()
{
    if (gtime > 0) gtime--;
    else set_heart_beat(0);
}

int get() { return 1; }
int drop() { return 1; }

string
query_auto_load()
{
    return "/guilds/thieves/obj/paper:" +
    sig[0] + "#" + sig[1] + "#" + sig[2] + "#" + gtime;
}

void
init_arg(string arg)
{
    if (!arg) return;
    sig = ({ "0", "0", "0" });
    gtime = ACCEPT_TIME;
    sscanf(arg, "%s#%s#%s#%d", sig[0], sig[1], sig[2], gtime);
    set_heart_beat(1);
}

void
init()
{
    add_action("read_cmd", "read");
    add_action("discard_cmd", "discard");
}

// Called by thief 'sign' command
status
signed_by(object who)
{
    string n;

    if (!who) return 0;

    n = (string)who->query_real_name();

    if (member(sig, n) != -1)
    {
	who->tell_me("You have already signed that form.");
	return 0;
    }

    if (sig[0] != "0" && sig[1] != "0" && sig[2] != "0")
    {
	who->tell_me("That form already has the required three signatures.");
	return 0;
    }

    if (sig[0] == "0") sig[0] = n;
    else if (sig[1] == "0") sig[1] = n;
    else if (sig[2] == "0") sig[2] = n;

    return 1;
}

// Called by accept
status
signed_ok(object who)
{
    int t;

    if (sig[0] == "0" || sig[1] == "0" || sig[2] == "0")
    {
	who->tell_me((string)environment()->query_name() +
	  "'s form doesn't have three signatures!");
	return 0;
    }

    if (gtime > 0)
    {
	who->tell_me((string)environment()->query_name() +
	  " has to be in the game for " + (gtime / 30) +
	  " more minutes before " +
	  (string)environment()->query_pronoun() +
	  " can be accepted.");
	return 0;
    }

    return 1;
}

status
read_cmd(string arg)
{
    string str, *tmp;

    if (!id(arg))
    {
	notify_fail("Read " + (arg ? "\"" + arg + "\"" : "what") + "?\n");
	return 0;
    }

    str = "This is the official form which must be filled \
before you could possibly be accepted to the Guild of Thieves. You \
can use command 'discard form' to get rid of it.\n\n";

    str += "You have to persuade THREE different thieves to sign the \
form for you. Then you also have to beg an official of the Guild \
to accept you into the guild. It won't be easy!\n\n";

    tmp = ({});
    if (sig[0] != "0") tmp += ({capitalize(sig[0])});
    if (sig[1] != "0") tmp += ({capitalize(sig[1])});
    if (sig[2] != "0") tmp += ({capitalize(sig[2])});

    if (sizeof(tmp) < 1)
	str += "No one has signed the form yet.\n\n";
    else
	str += "Form has been signed by: " + implode(tmp, ", ", " and ") + "\n\n";

    if (gtime > 0)
	str += "Also you have to be in the game for " +
	(gtime / 30) +
	" more minutes before you could be accepted.";

    TP->tell_me(str);
    set_heart_beat(1);
    return 1;
}

status
discard_cmd(string arg)
{
    if (arg != "form")
    {
	notify_fail("Discard " + (arg ? "\"" + arg + "\"" : "what") + "?!?");
	return 0;
    }

    TP->tell_me("Ok. You get rid of the form.");
    destruct(this_object());
    return 1;
}
