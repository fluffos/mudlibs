// Inhabitants...

inherit "/obj/monster";

void setup() {    
      set_race("human");
      set_long("This is one of the inhabitants of Daggerford.\n");
	set_random_stats(6, 18);
      switch(random(3)) {
        case 0:
          set_name("man");
          add_alias("man");
          set_main_plural("men");
          set_gender(1);
          add_move_zone("city");
          set_level(-1+random(3));
          break;
        case 1:
          set_name("lady");
          add_alias("lady");
          set_main_plural("ladies");
          set_gender(2);
          set_level(-1+random(3));
          break;
        case 2:
          set_name("child");
          set_short("child");
          add_alias("child");
          set_main_plural("children");
          set_gender(1 + random(2));
          set_level(-5+random(5));
      }
} /* setup */
