inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You proclaim: \"Shop SMART. Shop S-MART. YOU GOT THAT?!?!!?\"$N$\n", "#MN# proclaims: \"Shop SMART. Shop S-MART. YOU GOT THAT?!?!!?\"$N$\n");
       target("You proclaim to #TN#: \"Shop SMART. Shop S-MART. YOU GOT THAT?!?!!?\"$N$\n", "#MN# proclaims to #TN#: \"Shop SMART. Shop S-MART. YOU GOT THAT?!?!!?\"$N$\n", "#MN# proclaims to you: \"Shop SMART. Shop S-MART. YOU GOT THAT?!?!!?\"$N$\n");
       afar("You proclaim to #TN# from afar: \"Shop SMART. Shop S-MART. YOU GOT THAT?!?!!?\"$N$\n", "#MN# proclaims to you from afar: \"Shop SMART. Shop S-MART. YOU GOT THAT?!?!!?\"$N$\n");
    }
}

int
cmd_smart(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
