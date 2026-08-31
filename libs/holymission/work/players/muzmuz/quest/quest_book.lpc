
/* quest_book */

#define FOOD\
   ({"grass","lettuce","carrot","cucumber","radish","raddicchio",\
     "melon","pumpkin","dandelion","cloverleaf"}) 

#define PFOOD\
   ({"grass","lettuce","carrots","cucumbers","radish","raddicchio",\
     "melons","pumpkins","dandelion","cloverleaves"}) 

inherit "/obj/std_book";

string food, pfood;
int count;

void reset(int flag)
{
   int rnd;

     if (count)
         count--;
     if (flag !=0 && !count)
         call_out("remove_me",0);
     ::reset(flag);
     if (flag == 0)
     {
         if (!count)
             count = 2; 
         rnd = random(10);
         food = FOOD[rnd];
         pfood = PFOOD[rnd];
         add_names(({"quest_book","book about guineapigs"}));
         set_long(
         short()+"\n"+
         "This book seems to be very important and it seems \n"+
         "that you shouldn't do anything with it than read it.\n");
         add_contense(([
         "page1":
         "GUINEAPIGS\n\n"+
         "Guineapigs are little hairy rodents and therefore vegetarians.\n" +
         "They are sensitive against moistness and drafts. Therefore\n" +
         "guineapigs would never leave a warm room on their own will.\n" +
         "They prefer warm, dry and dark spots to hide from eventual \n" +
         "danger.\n",
         "page2":
         "How to feed them:\n\n"+
         "As already mentioned at page 1, guineapigs are vegetarians.\n"+
         "They especially prefer "+pfood+".\n"+
         "Guineapigs need to be fed at least twice a day.\n"+
         "Guineapigs can live without water supply if they get enough fresh food.\n"+ 
         "If you follow all these rules, your guineapig will live\n"+
         "long and prosper.\n"]));
         add_funs((["page2":"add_knowledge"]));
      }
}

void add_knowledge()
{
     object shad;

    if (!this_player()->food_shad())
    {
        shad = clone_object("/players/muzmuz/quest/food_shad");
        shad->start_shadow(this_player(),0,"food_shad");
        shad->set_food(food);
    }
}
     
         
int drop()
{
    object shad;
    
    if (objectp(shad = this_player()->food_object()))
        destruct(shad);

    write("As you try to drop the book it crumbles to dust.\n");
    destruct(this_object());
    return 1;
}


void remove_me()
{
    object mob;

    if (mob = find_object("/players/muzmuz/quest/guineapig"))
    {
       if (environment(mob) == environment(environment()))
       {
          tell_room(environment(environment()),
          "Suddenly the guineapig leaves.\n");
       }
       destruct(mob);
    }
    tell_object(environment(),
    "Suddenly your book crumbles to dust.\n");
    destruct(this_object());
    return;
}               
