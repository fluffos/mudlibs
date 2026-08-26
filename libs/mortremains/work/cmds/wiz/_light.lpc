// The light command...cause the player to produce light.
// Written by Publius@TMI-2 on 6/16/93

#include <mudlib.h>

inherit DAEMON;

int help();

int cmd_light( string str )
{
   int light;

   light = this_player() -> query( "light" );
   if( !str )
   {
      if( !light )
         write( "You are not currently producing any light.\n" );
      else
         write( "You are glowing with an intensity of " + light + ".\n" );
      return 1;
   }
// I always did hate nested if-thens :)
   switch( str )
   {
      case "on":
         write( "You start producing light with an intensity of 1.\n" );
         this_player() -> set( "light", 1 );
         break;
      case "off":
         write( "You stop producing light.\n" );
         this_player() -> set( "light", 0 );
         break;
      default:
         if( sscanf( str, "%d", light ) != 1 )
            return help();
         write( "You start producing light with an intensity of " +
                light + ".\n" );
         this_player() -> set( "light", light );
   }
   return 1;
}

int help()
{
   write( "Usage: light [on|off|<intensity>]\n\n" +
          "This command will cause you to produce light. Without any\n" +
          "parameters, your current light setting will be shown. Using\n" +
          "\"on\" will cause you to glow at an intensity of 1. You can\n" +
          "override that with the <intensity> parameter. \"off\" will\n" +
          "will set your light to 0, causing you to cease to produce\n" +
          "light.\n" );
   return 1;
}
