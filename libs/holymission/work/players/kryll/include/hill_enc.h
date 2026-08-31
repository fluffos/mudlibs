/*
   This file contains the possible monsters that can be cloned in the
   hills every reset. The variables provide the necessary info that
   clone_list requires.
*/

#define KOB "/players/kryll/monsters/kobolds/"
#define MON "/players/kryll/monsters/"

nosave string id_of_mons, file_of_mons;
nosave int no_of_mons;

void rnd_enc_hill() {
  id_of_mons = "kobold";
  switch(random(23)) {
    case 1 :
      file_of_mons = MON + "harpy";
      no_of_mons = 3;
      id_of_mons = "harpy";
      return;
    case 3..4 :
      file_of_mons = KOB + "k_male";
      no_of_mons = 6;
      return;
    case 7..8 :
      file_of_mons = KOB + "k_female";
      no_of_mons = 7;
      return;
    case 10 :
      file_of_mons = KOB + "k_prankster";
      no_of_mons = 5;
      return;
    case 12..14 :
      file_of_mons = KOB + "k_worker";
      no_of_mons = 10;
      return;
    case 19 :
      file_of_mons = KOB + "k_leader";
      no_of_mons = 1;
      return;
    case 20 :
      file_of_mons = KOB + "k_guard";
      no_of_mons = 2;
      return;
    case 21..22 :
      file_of_mons = KOB + "k_fighter";
      no_of_mons = 3;
      return;
    default:
      file_of_mons = KOB + "kobold_warrior";
      no_of_mons = 5;
      return;
  }
}

