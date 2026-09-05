inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You mouth a few words that look nothing like \"...Workshed\".$N$\n", "#MN# mouths a few words that look nothing like \"...Workshed\".$N$\n");
       target("You mouth a few words to #TN# that look nothing like \"...Workshed\".$N$\n", "#MN# mouths a few words to #TN# that look nothing like \"...Workshed\".$N$\n", "#MN# mouths a few words to you that look nothing like \"...Workshed\".$N$\n");
       afar("You mouth a few words to #TN# from afar that look nothing like \"...Workshed\".$N$\n", "#MN# mouths a few words to you from afar that look nothing like \"...Workshed\".$N$\n");
    }
}

int
cmd_workshed(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "x"; }
