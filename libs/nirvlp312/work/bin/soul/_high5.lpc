inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You run up and slap yourself a high-five!$N$\n", "#MN# runs up and slaps #MO#self a high-five!$N$\n");
       target("You run up and slap #TN# a high-five!$N$\n", "#MN# runs up and slaps #TN# a high-five!$N$\n", "#MN# runs up and slaps you a high-five!$N$\n");
       afar("You run up and slap #TN# a high-five from afar!#RET#Right on!$N$\n", "#MN# runs up and slaps you a high-five from afar!#RET#Right on!$N$\n");
    }
}

int
cmd_high5(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
