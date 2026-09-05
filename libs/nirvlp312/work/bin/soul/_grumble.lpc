inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You grumble about something or other.$N$\n", "#MN# grumbles about something or other.$N$\n");
       target("You grumble at #TN# about something or other.$N$\n", "#MN# grumbles at #TN# about something or other.$N$\n", "#MN# grumbles at you about something or other.$N$\n");
       afar("You grumble at #TN# about something or other from afar.$N$\n", "#MN# grumbles at you about something or other from afar.$N$\n");
    }
}

int
cmd_grumble(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
