#include "path.h"
inherit "obj/monster"; 


void setup()
{
   set_name("Zzarg the adventurer");
   add_alias("Zzarg");
   add_alias("zzarg");
   add_alias("zzarg the adventurer");
   add_alias("adventurer");
   set_main_plural("Adventurerers");
   add_plural("adventurerers");
   set_long("Zzarg, a huge and strong lizard, he seems to have been"
            " in many battles, and he looks kinda old. What you have"
            " heard of this lizard, is much. For many years now"
            " he has been walking around the land of lizards,"
            " explaining what the realms bring.\n\n");
   set_race("lizard");
   set_level(5+random(4));
   set_gender(1);
        load_chat(15,
                ({
                        1,"' If you wanna hear what I have to say, listen to me.",
                        1,": stares into midair, it looks like he is lost in thoughts.\n",
                        1,": smiles.",
	        }));
   new(ITEMS"long_sword")->move(this_object());
   this_object()->init_equip();

}
void init()  
{  
        ::init();  
          add_action("do_listen","listen");
}

int do_listen(string str)
{
 if(str=="zzarg" || str=="Zzarg")
  {
   if(this_object()->query_property("tale") == 1)
        {
            do_command("say Do not interrupt me.");
	    return 1;
	}
        do_command("say I'll now tell you about the lands you probably"
                   " are going to later.\n");
        this_object()->add_property("tale", 1);
        call_out("daggerford", 5);
	return 1;
    }
}

int daggerford()
{
    do_command("say Daggerford, the city in the middle of the land, a huge city"
               " with lots of things in, but there is nothing for you there"
               " the city doesnt like our race.");
    call_out("stf", 7);
    return 1;
}

int stf()
{
    do_command("say A city of goodness, protected by many guard, but beware "
               " they don't like weapons there, so if you go there, be sure to"
               " have enough money with you for buying your weapons back.");
    call_out("cove", 10);
    return 1;
}

int cove()
{
    do_command("say And as a last place I want to mention now is Unicorn Cove,"
               " a place lying high up the mountains and difficult to reach,"
               " but its quite a lovely place.");
    do_command("grin");
    call_out("guilds", 13);
    return 1;
}

int guilds()
{
    do_command("say Ill now tell you a little about some profesions.");
    call_out("assassin", 13);
    return 1;
}

int assassin()
{
    do_command("Assassin, a man who lurks in shadows and murder with cold"
               " blood, you must be careful if you meet one of these, since"
               " they also do contracts on people. If you have problems with"
               " a person, have the money, then put up a contract and you"
               " will get his head delivered.");
    call_out("fighter", 13);
    return 1;
}
int fighter()
{
    do_command("say Fighter, a muscular person, which likes to do battle"
               " with his strength. Being able to use every armour and"
               " weapons available, he can be quite powerful.");
    do_command("sigh");
    call_out("cleric", 13);
    return 1;
}
int cleric()
{
    do_command("say Cleric, a man of healing and curing, many types exist"
               ", some evil, some good, but one thing is the same, all can heal.");
               
    call_out("theend", 13);
    return 1;
}
int theend()
{
    do_command("say This is all I have to tell you.");
    do_command("smile");
    this_object()->remove_property("tale");
    return 1;
}
