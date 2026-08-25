// Alea 1996
//     CODE by Taniwha and Alea
//          July 22,1996
inherit "/std/object";
string * verbotten = ({ "thief","Grimbrand","bard","wiz-thief" });
int wet;

void setup()
{
   set_name("towel");
   set_short("Fluffy Towel");
   set_long("     You hold in your hands one of the fluffiest "
      "towels you have ever layed your eyes on.  Its bright "
      "pink color goes wonderfully with you features "
      "as well as anything you decide to wear."
      "\n\n");

   set_weight(20);
   add_plural("Fluffy Towels");
}
void dryer(object me)
{
   wet = me->query_wetness();
   if(wet > 50) wet = 50;
   me->adjust_wetness(-wet);
}

void init()
{
  ::init();
   add_action("do_dry","dry");
   add_action("do_wring","wring");
}

int do_dry(string targetname)
{
   object me,you;
if(!targetname)
{
 notify_fail("Would you like to dry an object, or are you just trying to stop boozing?\n");
return 0;
}
   you = present(targetname,environment(this_player()));
   me  = this_player();
if(!targetname)
 {notify_fail ("Would you like to dry a person, or are you simply trying to stop boozing?\n");
return 0;
}
   if(!you)
   {
      notify_fail("Dry whom ?\n");	
      return 0;
   }
   if(!you->query_alive())
   {
      notify_fail("Icky, this towel is far too good to dry THAT with!\n");
      return 0;
   }
   if(wet)
   {
      notify_fail("Oook, the towel is soggy.\n");
      return 0;
   }
   if( member_array(me->query_guild_name(),verbotten)>= 0 && !query_property("stolen") )
   {
      notify_fail("You'd die of shame if you used a towel that HADN'T been stolen.\n");
      return 0;
   }
   if(!you->query_wetness())
   {
   	notify_fail(targetname+" is not wet.\n");
   	return 0;
   }	
   if( me == you )
   {
   	write(" Feeling a bit damp, you decide to grab your "
      	"fluffy pink towel to get the job done, having had only "
      	"fond memories of it fluffiness against your skin.  "
      	"After a brief moment of reminicing, you begin to "
      	"dry yourself off.\n\n");

   	tell_room(environment(me),me->query_cap_name()+
      	" retrieves a fluffy pink towel and begins drying "
   	+me->query_possessive()+"self off. A look of pleasure crosses "+
      	me->query_cap_name()+"'s face, while increasing "
      	"jealously crosses yours.\n\n",({me}));
   	dryer(you);
   	return(1);
   }
   else
   {
   	write(" Seeing that "+you->query_cap_name()+
   	" is somewhat soggy, you reach for your trusty towel and "
   	"dry "+you->query_possessive()+" off.\n"
   	);
   	tell_object(you,(string)me->query_cap_name()+
   	" smiles at you, whips out a towel and dries you off.\n"
   	);
   	tell_room(environment(me),(string)me->query_cap_name()+
   	" whips out a large pink object and rubs "
   	+you->query_cap_name()+" down with it.\n"
   	"They both seemed to enjoy the experience.\n"
      ,({me,you}));
   	dryer(you);
   	return(1);
   	
   }	
return(0);
}

int do_wring(string str)
{
   object me=this_player();
   if(str != "towel") 
   {
   	notify_fail("wring what ?\n");	
   	return 0;
   }	
   if(!wet)
   {
      notify_fail("The towel is already dry.\n");
      return 0;
   }
   write("     Longing to feel the fluffiness in the towel "
      "again, you slowly begin twisting the towel, attempting "
      "to wring all of the water out of it.\n\n"
      "Ahhhh..... much better now.  A look of pleasure "
      "crosses your face as you hold the fluffiness up "
      "against your skin.\n\n");


      tell_room(environment(me),me->query_cap_name()+
   	" holds the dripping towel in "+me->query_possessive()+" hands, and "
      	"slowly begins twisting it to get the water out.\n\n",({me}));
   	wet = 0;
      return(1);
}
