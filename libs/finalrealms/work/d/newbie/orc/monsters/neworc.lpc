inherit "/obj/monster"; 

void setup() 
{ 
        set_name("orc"); 
        set_short("Old looking orc"); 
        set_long("This is an ugly old orc. It looks like his job is " 
                 "to patrol this path up and down from the tower.\n"); 
        set_race("orc"); 
        set_random_stats(12,17); 
        set_guild("fighter"); 
        set_gender(1); 
	set_level(random(5));
        set_al(random(500)); 
        set_aggressive(random(2)); 
        set_xp(300); 

        if(random(2)) 
        { 
                new("/baseobs/weapons/scimitar")->move(this_object()); 
        }
        else 
        { 
                new("/baseobs/weapons/short_sword")->move(this_object()); 
        } 
        new("/baseobs/armours/leather")->move(this_object()); 
        new("/baseobs/armours/helmet")->move(this_object()); 
        this_object()->init_equip(); 

} 
