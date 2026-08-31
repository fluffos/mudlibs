inherit MONSTER;

void create() {
string colour;
int rand;
::create();
        set_name("forest drake");
        set_id( ({"monster", "drake"}) );
        set_heart_beat(1);

        rand = random(6);
        if(rand == 0) colour = "%^BOLD%^MAGENTA%^Purple%^RED%^";
        if(rand == 1) colour = "%^BOLD%^BLUE%^Blue%^RED%^";
        if(rand == 2) colour = "%^BOLD%^WHITE%^White%^RED%^";
        if(rand == 3) colour = "%^BOLD%^GREEN%^Green%^RED%^";
        if(rand == 4) colour = "%^YELLOW%^Yellow%^RED%^";
        if(rand == 5) colour = "Red";
        set_short("a "+colour+" forest drake");
        set_long("The drake is an ancient offshoot of the Dragon race. While Dragons grew larger and more powerful, some remained small and animalistic, and so became known simply as Drakes.");
        set_race("drake");
        if (random(10) > 5)
           set_gender("female");
        else
           set_gender("male");
        set_body_type("dragon");
        set_level(39+random(3));
        set_alignment(-random(100));
}
