/*
 * Originally..
 * 'the bit of the soul that all players should have ;)'
 * By Pinkfish, presumably
 *
 * For some weird reason I am trying to make it a simul_efun.. 
 * not sure how to use it yet but we'll see.
 * changing all this_object() to this_player() altho I hate using it.
 * Baldrick, june '97.
 */

#define SOUL_OBJECT "/obj/handlers/soul"

int test_soul_com(string str) 
{
  string str1, str2;
  int i;

  if (sscanf(str,"%s %s", str1, str2) != 2)
    str1 = str;

  if (this_player()->exec_alias(str1, str2))
  {
    /* expanding an alias into several commands is trivial */
    this_player()->set_trivial_action();
    return 2;
  }

  if (!this_player()->query_property("nosoul")) 
  {
    if ( !load_object(SOUL_OBJECT) )
    {
      write("Soul errors!  Notify an immortal.\n");
      write("Use nosoul to turn the soul back on when it is fixed.\n");
      this_player()->add_property("nosoul",1);
      return 0;
    }

    i = SOUL_OBJECT->soul_command(str1,str2,this_player());
    /* souls are trivial */
    if ( i )
      this_player()->set_trivial_action();

    return i;
  }

  return 0;
} /* soul_com() */

/* 
 * This one can actually stay in the psoul.c 
 *
int soul_com_force(string str) 
{
  string str1,str2;

  if ( this_object()->action_blocked() && 
       !this_object()->query_lord() )
    return 0;

  if (file_name(previous_object()) != SOUL_OBJECT)
    return 0;

  command(str);

  return 1;
} /* soul_com_force() */

/* 
 * This one can actually stay in the psoul.c 
 *
void do_soul(string str, mixed bing) 
{
  say(str, bing);
}*/ /* do_soul() */
