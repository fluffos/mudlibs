inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You mumble about something under your breath.$N$\n", "#MN# mumbles about something under #MP# breath.$N$\n");
       target("You mumble about something to #TN# under your breath.$N$\n", "#MN# mumbles about something to #TN# under #MP# breath.$N$\n", "#MN# mumbles about something to you under #MP# breath.$N$\n");
       afar("From afar, you mumble about something to #TN# under your breath.$N$\n", "From afar, #MN# mumbles about something to you under #MP# breath.$N$\n");
    }
}

int
cmd_mumble(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
