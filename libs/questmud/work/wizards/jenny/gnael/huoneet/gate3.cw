inherit "room/room";

reset(arg) {

        if(!present("lendor")) {
           move_object(clone_object("/wizards/jenny/gnael/mosut/lendor"), this_object());
        }
        if(!present("orc")) {
           move_object(clone_object("/wizards/jenny/gnael/mosut/meglah"), this_object());
        }
        if (!present("sign")) {
         move_object(clone_object("wizards/jenny/gnael/rojut/sign"), this_object());
        }

        if(arg) return;

        add_exit("east","out: 82 128");
        add_exit("west","/wizards/jenny/gnael/huoneet/city46.c");

  short_desc = "Eastern gate";
  long_desc = "There is a huge gate in front of you,\n"+
              "people are coming and going from it\n"+
              "all the time. A small sign is on the\n"+
              "ground and some torches are burning near\n"+
              "the gate. Behind the gate lies the\n"+
              "large city of Gnael. You see only rich\n"+
              "people inside and all the houses seem to be\n"+
              "very expensively made.\n";
        }
