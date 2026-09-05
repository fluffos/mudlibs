inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("Strut your stuff!$N$\n", "#MN# struts proudly.$N$\n");
       target("You strut around #TN#.$N$\n", "#MN# struts around #TN#.$N$\n", "#MN# struts around you.$N$\n");
       afar("You strut around #TN# from afar.$N$\n", "#MN# struts around you from afar.$N$\n");
    }
}

int
cmd_strut(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
