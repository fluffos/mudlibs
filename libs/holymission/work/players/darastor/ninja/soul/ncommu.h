#ifndef _ninja_communicate_
#define _ninja_communicate_

int noff;

/* --- introducing ------------------------------------------------------------ */
_intro( arg )
{
#if 0
    object who, ob;

    write( "Temporarily removed.\n" );
    return( 1 );

    if ( !arg ) {
	write( "Introduce whom ?\n" );
	return( 1 );
    }

    if ( arg == "myself" )
	_intro_me( TP );
    else {
	who = present( arg, environment(this_player()) );
	if ( who ) {
	    ob = present( "ninjasoul", who );
	    if ( !ob ) {
		write( "You only can introduce memeber of your guild.\n" );
		return( 1 );
	    }
	    else
		ob->_intro_me( who );
	}
    }
#endif
    return( 1 );
}

_intro_me( arg )
{
#if 0
    string str;

    if ( arg == TP ) {
	write( "You introduce yourself as:\n\n" );
	str = TP->query_possessive();
	if ( str == "his" ) str = "him";
	else if ( str == "its" ) str = "it";
	say( capitalize(arg->query_name()) + " introduces " + str + "self as:\n" );
    }
    else {
	tell_object( this_player(), "You introduce " + capitalize(arg->query_real_name()) + 
	  " as:\n");
	tell_object(arg, capitalize(TP->query_real_name()) + " introduces you as:\n" );
	say( capitalize(TP->query_real_name()) + " introduces " + 
	  capitalize(arg->query_name()) + " as:\n", arg );
    }

    write( NINJA_TITLES->get_pretitle(arg->query_level()) + " " + 
      capitalize(arg->query_real_name()) + ", member of the ninja-guild, " + 
      arg->query_gender_string() + ".\n" );
    say( NINJA_TITLES->get_pretitle(arg->query_level()) + " " +
      capitalize(arg->query_real_name()) + ", member of the ninja-guild, " +
      arg->query_gender_string() + ".\n" );

    if ( arg == TP ) {
	tell_object( arg, "You are:\n" );
	say( capitalize(arg->query_pronoun()) + " is:\n", arg );
    }
    else {
	write( capitalize(arg->query_pronoun()) + " is:\n" );
	say( capitalize(arg->query_pronoun()) + " is:\n", arg );
	tell_object( arg, "You are:\n" );
    }

    write( capitalize(NINJA_TITLES->get_skill_title(actThrowSkill)) + " in Throwing.\n" );
    write( capitalize(NINJA_TITLES->get_skill_title(actKarateSkill)) + " in Karate.\n" );
    write( capitalize(NINJA_TITLES->get_skill_title(actParrySkill)) + " in Yadomejutsu.\n" );
    write( capitalize(NINJA_TITLES->get_skill_title(actAccSkill)) + " in Kenjutsu.\n" );
    write( capitalize(NINJA_TITLES->get_skill_title(actTHCSkill)) + " in Ni-To-Kenjutsu.\n" );
    write( capitalize(NINJA_TITLES->get_skill_title(actCamouSkill)) + " in Camouflage.\n" );
    write( capitalize(NINJA_TITLES->get_skill_title(actAssassSkill)) + " in Assassination.\n" );
    write( capitalize(NINJA_TITLES->get_skill_title(actDisarmSkill)) + " in Disarm.\n" );

    say( capitalize(NINJA_TITLES->get_skill_title(actThrowSkill)) + " in throwing.\n" );
    say( capitalize(NINJA_TITLES->get_skill_title(actKarateSkill)) + " in karate.\n" );
    say( capitalize(NINJA_TITLES->get_skill_title(actParrySkill)) + " in Yadomejutsu.\n" );
    say( capitalize(NINJA_TITLES->get_skill_title(actAccSkill)) + " in Kenjutsu.\n" );
    say( capitalize(NINJA_TITLES->get_skill_title(actTHCSkill)) + " in Ni-To-Kenjutsu.\n" );
    say( capitalize(NINJA_TITLES->get_skill_title(actCamouSkill)) + " in Camouflage.\n" );
    say( capitalize(NINJA_TITLES->get_skill_title(actAssassSkill)) + " in Assassination.\n" );
    say( capitalize(NINJA_TITLES->get_skill_title(actDisarmSkill)) + " in Disarm.\n" );

    write( "\n" );
    say( "\n" );
    show_awards( arg );
    say( "\nThank you for your aknowledgement.\n" );

#endif
    return( 1 );
}

_emote (str)
{
    if(!str) return;
    "sys/chatd.lpc"->do_chat(8, "[*Ninja*] "+
         capitalize(this_player()->query_real_name())+" "+str+"\n");
    return 1;
}

_ninja(str) { return TP->guild_line(str); }

less_func( ob1, ob2 )
{
    if ( ob1->query_level() < ob2->query_level() )
	return( 1 );

    return( 0 );
}

query_noff()
{
    return( noff );
}

right_align( txt, w )
{
    if ( strlen( txt ) < w )
	txt = txt + "                                     ";

    return( extract( txt, 0, w-1 ) );
}

get_line( c, w )
{
    int i;
    string l;

    l = "";
    for ( i = 0; i < w; i++ )
	l += c;

    return( l );
}


/* ----- beep dice ------------------------------------------------------------- */
_beep( arg )
{
    object obj;
  if ( !this_player()->query_immortal() && arg != "dice" && arg != "patience" ) {
	write( "Sorry, but you only can beep Dice or Patience.\n" +
	  "And this only for a good reason ! (e.g. a bug or something like that)\n" );
	return( 1 );
    }

    obj = find_player( arg );
    if ( !obj ) {
	write( "Sorry, he is invis.\n" );
	return( 1 );
    }

    tell_object( obj, "" );
    tell_object( obj, "---->" + TP->query_name() + " beeped you !\n");
    write("You beeped !\n");

    return( 1 );
}

// ----- awards !!! ---------------------------------------------------------
void show_awards( object who )
{
   string awds;

   write( who->query_name_true() + " earned the following awards:\n" );
   say( who->query_name_true() + " earned the following awards:\n" );
   awds = "";
   if ( WEAP_OWNERS->is_kat_owner( who->query_real_name() ) )
      awds += "The katana by defeating the evil ryu !!!\n";
   if ( WEAP_OWNERS->is_waki_owner( who->query_real_name() ) )
      awds += "The wakizashi by driving forth the mujina from the caves"+
              " !!!\n";
   if ( WEAP_OWNERS->is_nt_owner( who->query_real_Name() ) )
      awds += "The ninja-to !!!\n";

   if ( awds == "" )
      awds += "none\n";

   write( awds );
   say( awds );
}

#endif /*_ninja_communicate_*/
