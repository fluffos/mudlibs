inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You smack youself senseless!$N$\n", "#MN# smacks #MO#self senseless!$N$\n");
       target("You smack #TN# across the face!$N$\n", "#MN# smacks #TN# across the face!$N$\n", "#MN# smacks you across the face!$N$\n");
       afar("You smack #TN# across the face from afar!$N$\n", "#MN# smacks you across the face from afar!$N$\n");
    }
}

int
cmd_smack(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
