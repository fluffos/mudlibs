inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You go, 'Woo Woo'.$N$\n", "#MN# goes: 'Woo Woo'.$N$\n");
       target("You point at #TN# and go, 'Woo Woo'.$N$\n", "#MN# points at #TN# and goes, 'Woo Woo'.$N$\n", "#MN# points at you and goes, 'Woo Woo'.$N$\n");
       afar("You point at #TN# from afar and go, 'Woo Woo'.$N$\n", "#MN# points at you from afar and goes, 'Woo Woo'.$N$\n");
    }
}

int
cmd_woo(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
