inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say: I'm going to punch someone in the ovary, that's what I'm gonna do. A straight shot, right to the babymaker.$N$\n", "#MN# says: I'm going to punch someone in the ovary, that's what I'm gonna do. A straight shot, right to the babymaker.\n");
       target("You say: I'm going to punch #CTN# in the ovary, that's what I'm gonna do. A straight shot, right to the babymaker.$N$\n", "#CMN# says: I'm going to punch #CTN# in the ovary, that's what I'm gonna do. A straight shot, right to the babymaker.$N$\n", "#CMN# says: I'm going to punch you in the ovary, that's what I'm gonna do. A straight shot, right to the babymaker.$N$\n");
       afar("$HW$[$HY$afar$HW$]$N$ #CMN# say: I'm going to punch you in the ovary, that's what I'm gonna do. A straight shot, right to the babymaker.$N$\n", "$HW$[$HY$afar$HW$]$N$ #CMN# says: I'm going to punch you in the ovary, that's what I'm gonna do. A straight shot, right to the babymaker.$N$\n");
    }
}

int
cmd_povary(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
