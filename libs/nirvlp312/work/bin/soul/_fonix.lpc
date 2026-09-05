inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You babble: \"Huuk'd ohn fonix wurk'd fer mee!\"$N$\n", "#MN# babbles: \"Huuk'd ohn fonix wurk'd fer mee!\"$N$\n");
       target("You babble to #TN#: \"Huuk'd ohn fonix wurk'd fer mee!\"$N$\n", "#MN# babbles to #TN#: \"Huuk'd ohn fonix wurk'd fer mee!\"$N$\n", "#MN# babbles to you: \"Huuk'd ohn fonix wurk'd fer mee!\"$N$\n");
       afar("You shout at #TN#: \"Huuk'd ohn fonix wurk'd fer mee!\"$N$\n", "#MN# shouts at you: \"Huuk'd ohn fonix wurk'd fer mee!\"$N$\n");
    }
}

int
cmd_fonix(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
