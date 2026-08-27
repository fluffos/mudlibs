inherit "/std/room";
void shield_it(string str, string waitpunk) {
   object porter;
 porter = this_player();
if (str == "players") {
if(this_player()->query_creator()) {
     write("You feel a small pulse of magic as you pass through"
            " a magical shield.\n");
 return;
}
else
{
        waitpunk->force_load();
        this_player()->move(waitpunk);
        write("You are not powerful to breach the magical shield which"
        " protects your destination.\n"
        "The magical shield bounces you to another location.\n");
    }
}
if (str == "creators") {
if(this_player()->query_lord()) {
    write("You feel a unnerving pulse of magic as you pass through"
            " a magical shield.\n");
return;
}
else
{
        waitpunk->force_load();
        this_player()->move(waitpunk);
        write("Devoe appears before you.\n"
         "Devoe smiles at you.\n"
         "Devoe says: I am sorry m'lord, only higher immortals may pass the"
         "magical shield that protects this area.\n"
         "Devoe opens a rift in time and steps through.\n"
        "The magical shield bounces you to another location.\n");
    }
}
if (str == "demigods") {
if(this_player()->query_god()) {
    write("You feel a large pulse of magic as you pass through"
            " a magical shield.\n");
 return;
}
else
{
        waitpunk->force_load();
        this_player()->move(waitpunk);
        write("This is a magically protected area.  This shield should of"
                " been placed by: "
                " Bivins, Ducky, or Dank.  Only gods may pass here.\n"
                "The magical shield bounces you to another location.\n");
    }
}
} 
