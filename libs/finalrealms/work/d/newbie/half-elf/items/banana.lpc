// A banana.

inherit "/std/object";

void create()
{
     ::create();
     add_timed_property("cha",1,20000); 
}
  

void setup()
{
  set_name("banana");
  set_short("banana");
  set_long("A small banana, bright yellow. When you look at it you notice"
	   " how hungry you really are.. maybe you should eat it? \n");
  set_weight(1);
  set_value(0);
}


void init()
{
  add_action("do_eat","eat");
  ::init();
}


int do_eat(string str)
{
 
   object ob;
   ob=environment(this_player());
   
    if (str == "banana")
    {
     


        write("\n  You eat a delicious banana, it doesn't taste like"
	      " anything you have eaten before.\n"); 

        if(this_player()->query_tmp_cha() <= 0)

        {

            write("\n   You feel the wonderful taste fill your heart"
	          " and body, and it feels great! \n\n");
            

            this_player()->adjust_tmp_cha(1);
            this_object()->dest_me();
            return 1;
        }
        else

        {
              
            write("The banana doesn't taste as good now. Have to"
	          " spare some for later.\n\n");
              
            this_object()->dest_me();
            return 1;
        }
    }
    return(0);
}








