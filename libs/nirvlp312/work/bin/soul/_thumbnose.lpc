inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You thumb your nose at New York! Or, uh, something!$N$\n", "#MN# thumbs #MP# nose at New York! Or, uh, something!$N$\n");
       target("You thumb your nose at #TN#!#RET#Sweet!$N$\n", "#MN# thumbs #MP# nose at #TN#!#RET#Sweet!$N$\n", "#MN# thumbs #MP# nose at you!#RET#Not so sweet!$N$\n");
       afar("You thumb your nose at #TN# from afar!#RET#Wow. You're a cool guy.$N$\n", "#MN# thumbs #MP# nose at you from afar!#RET#You are in \"shock-n-awe\" at the pure coolness of that guy.$N$\n");
    }
}

int
cmd_thumbnose(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
