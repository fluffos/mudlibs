inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You ask a question and log out before anyone can answer. Just like Wicket!\n", "#MN# asks a question and logs out before anyone can answer. Just like Wicket!\n");
       target("You ask #TN# a question and log out before #TS# can answer. Just like Wicket!\n", "You ask #TN# a question and log out before #TS# can answer. Just like Wicket!\n", "#MN# asks you a question and logs out before you can answer. Just like Wicket!\n");
       afar("From afar, you ask #TN# a question and log out before #TS# can answer. Just like Wicket!\n", "From afar, #MN# asks you a question and logs out before you can answer. Just like Wicket!\n");
    }
}

int
cmd_wicketed(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "shinshi"; }
