inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You arch an eyebrow inquisitively.$N$\n", "#MN# arches an eyebrow inquisitively.$N$\n");
       target("You arch an eyebrow inquisitively at #TN#.$N$\n", "#MN# arches an eyebrow inquisitively at #TN#.$N$\n", "#MN# arches an eyebrow inquisitively at you.$N$\n");
       afar("You arch an eyebrow inquisitively at #TN# from afar.$N$\n", "#MN# arches an eyebrow inquisitively at you from afar.$N$\n");
    }
}

int
cmd_iarch(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
