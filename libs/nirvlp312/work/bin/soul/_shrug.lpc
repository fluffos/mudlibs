inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shrug.$N$\n", "#MN# shrugs helplessly.$N$\n");
       target("You shrug at #TN#.$N$\n", "#MN# shrugs at #TN#.$N$\n", "#MN# shrugs at you.$N$\n");
       afar("You shrug at #TN# from afar.$N$\n", "#MN# shrugs at you from afar.$N$\n");
    }
}

int
cmd_shrug(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
