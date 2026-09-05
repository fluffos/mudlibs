inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You walk up to yourself and kiss yourself on the cheek.$N$\n", "#MN# walks up to #MP#self and kisses #MP#self on the cheek.$N$\n");
       target("You walk up to #TN# and kiss #TO# on the cheek.$N$\n", "#MN# walks up to #TN# and kisses #TO# on the cheek.$N$\n", "#MN# walks up to you and kisses you on the cheek.$N$\n");
       afar("You walk up to #TN# and kiss #TO# on the cheek from afar.$N$\n", "#MN# walks up to you and kisses you on the cheek from afar.$N$\n");
    }
}

int
cmd_kcheek(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
