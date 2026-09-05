inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You manage to zurbur yourself, and that takes some mad skills.$N$\n", "#CMN# manages, through a fearsom feat of skill, to zurburt #MP# belly, freakish, no?2$N$\n");
       target("You $HW$zurburt$N$ #CTN#'s belly, with a loud wet THUUUURBT!$N$\n", "#CMN# $HW$zurburts$N$ #CTN#'s belly, with a loud wet THUUUURBT!#RET#You recoil in disgust, yet want to experience one for yourself.$N$\n", "You have been $HW$zurburted$N$ by #CMN#, you giggle with delight!$N$\n");
       afar("You $HW$zurburt$N$ #CTN#'s belly from afar, with a loud wet THUUUURBT!  $N$\n", "You have been $HW$zurburted$N$ from afar by #CMN#, you giggle with delight!$N$\n");
    }
}

int
cmd_zurburt(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "khrell"; }
