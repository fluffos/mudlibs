inherit ARMOUR;
void create() 
{
::create();
  
    set_name("Suri Necklace");
    
	set_short("%^BOLD%^%^RED%^S%^RESET%^%^RED%^u%^BOLD%^r%^RESET%^RED%^i%^RESET%^'%^BOLD%^%^RED%^s%^RESET%^ N%^BOLD%^e%^RESET%^c%^BOLD%^k%^RESET%^l%^BOLD%^a%^RESET%^c%^BOLD%^e%^RESET%^");
    set_long("This necklace given to Endbringer by her love Suri, It's a simple silver chain necklace with a little gold heart charm attached to it, on the back of the heart you notice I <3 you etched in the back of the charm.");
    set_id(({"necklace", "suri necklace"}));
    set_ac(0);            
    set_mass(1);
    set_type("necklace");
    set_limbs(({ "head" }));
}
 int query_auto_load() 
 { 
         if (this_player()->query_name() == "endbringer") 
        return 1; 
 }
int slap_on_the_wrist(string str) 
{
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_name() == "endbringer") 
   return 0;
   write("Only Endbringer may wear this necklace.");
   say(this_player()->query_cap_name()+" can not wear this necklace as it
doesn't belong to them!", this_player());
this_player()->force_me("shout I can't believe I tried to wear Endbringer's
necklace. PLEASE forgive me mistress Endbringer!");
   return 1;
}
void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}
