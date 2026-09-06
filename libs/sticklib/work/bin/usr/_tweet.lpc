// Originally created by Excalibur@StickMUD
#include <daemons.h>
#include <mud_name.h>
#include <twitter_defs.h>

nomask status tweet_cmd( string args, object who )
{
   string msg;

   if (!who && !(who=this_player()))
      return 0;

   if (!args || !sizeof(args))
      return notify_fail("Tweet what?\n"), 0;

   if (!TWITTER_D->allow_tweet(who))
   {
      who->tell_me("You are not authorized to send " + MUD_NAME + " tweets.");
      return 1;
   }

   msg = implode(explode(args, "\n"), " ");

   if (sizeof(msg) > MAX_TWEET_LENGTH)
   {
      who->tell_me("Tweet message is too long. Cannot be more than "+MAX_TWEET_LENGTH+" characters.");
      return 1;
   }

   if (!TWITTER_D->send_tweet(msg, who))
   {
      who->tell_me("Tweet not sent.");
      return 1;
   }

   who->tell_me("Tweet sent.");

   return 1;
}
