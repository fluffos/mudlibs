inherit "/std/barkeep";

void create() {
 ::create();
   set_name("voodoo");
   set_id(({ "voodoo" }));
   set_short("Voodoo");
   set_long("Voodoo is the guardian of Inferno's bar. Its body is "
     "a swirling mass of pure evil. Its face is masked by a black "
     "cowl.");
   set_alignment(-666);
   set_race("demon");
   add_money("platinum", random(80000));
   set_skill("melee",90);
   set_body_type("demon");
   set_currency("gold");
   set_menu(
	({ "blood", "keg", "shot", "wine" }),
	({ "alcoholic", "alcoholic", "alcoholic", "alcoholic" }),
	({ 7, 150, 200, 20})
    );
    set_my_mess(
	({
	"You drink the blood away.\n",
	"Just when you think it'll never end, you finish the whole keg!\n",
	"H...ooo000OOOly shiiiiit!\n",
	"You down the cold black wine.\n"
	})
    );
    set_your_mess(
	({
	"empties the chalice of blood.\n",
	"just drank a whole keg of whiskey!\n",
	"takes a shot of the most potent alcohol in the known universe.\n",
	"downs a bottle of cold, black wine.\n"
    	})
    );
    set_menu_short(
	({
	"a glass chalice of blood",
	"a keg of whiskey",
	"a shot of the most potent alcohol in the known universe.",
	"a bottle of black wine"
	})
    );
    set_menu_long(
	({
	"The chalice is half filled with a dark red blood.\n",
	"Chug! Chug! CHUG!\n",
	"A single shot that will rock your world!\n",
	"A full bottle of cold, black wine.\n"
   	})
    );
}

int no_pay() { return 1; }
