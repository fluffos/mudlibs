inherit MONSTER;

void create () {


    ::create();
    seteuid(getuid());
    set("short", "Zed");
    set("long", @BiteMe
Zed is a Huge man. His arms are the size of cannons.Zed is a Huge Man. His arms are the size of cannons.
You don't think it would be wise to Fuck with him.
BiteMe
  );
    set("id", ({ "zed", "smith", "blacksmith"}) );
    set_name ("zed");
    set("race", "human");
    set("gender", "male");
    enable_commands();
    set_living_name("zed");
    set ("stat/constitution", 19);
    set ("stat/constitution", 1);
    set ("stat/strength", 1);
    set ("stat/intelligence", 5);
   set ("stat/dexterity", 1);
   set ("stat/wisdom", 9);
   set("damage", ({ 1,2 }) );
    set("weapon_name", "fists");
    set("CLASS", "warrior");
   set_skill("Clubbing Weapons", 1, "Strength");
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;

    // You forgot these:
    set_size(6);       //Man sized.
    set_align("cg");   // Nobody ever add this...  I made him chaotic good,
                       // Just to show how to do it.

    // set_level should always be last in the function so the xp is
    // calculated right.
  set_level(1000);
    }
