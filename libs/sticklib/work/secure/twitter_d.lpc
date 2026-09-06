#include <coder_levels.h>
#include <twitter_defs.h>
#include <erq.h>

//===================================
// Variables
//===================================
string *allowed_objects = ({
                            // For reboots
                             "secure/shut"
                            // For player deaths (mks & pks)
                            ,"areas/tristeza/temple/grave_stone"
                            // For Guild Raids
                          });

// ========================================
// Actual functions
// ========================================
nomask int allow_tweet(object who)
{
   object prev;
   string tmp, ob_name;
   int    x;

   prev=previous_object();
   if(prev)
   {
      tmp = object_name(prev);
      if(sscanf(tmp, "%s#%d", ob_name, x) != 2)
         ob_name = tmp;

      if(member(allowed_objects, ob_name) != -1)
         return 1;
   }

   if((who || (who=this_player()))
      && who->query_coder_level() >= LVL_SENIOR
     )
      return 1;

   return 0;
}

nomask varargs int send_tweet(string msg, object who)
{
   object prev;
   string tmp, *tmp2, filename;
   int    ts;

   if(!who)
      who = this_player();

   if(!allow_tweet(who) || !msg)
      return 0;

   // No hard returns allowed. Let's convert any to space just in case
   msg = implode(explode(msg, "\n")," ");

   if(!sizeof(msg) || sizeof(msg) > MAX_TWEET_LENGTH)
      return 0;

   // Log all tweets
   prev=previous_object();
   if(prev)
   {
      tmp2 = explode(object_name(prev), "/");

      tmp = "("+tmp2[(sizeof(tmp2)-1)]+")";
   }
   else if(who)
      tmp = capitalize(who->query_real_name());
   else
      tmp = "<something>";

   log_file("TWEETS", ctime(time())+" "+tmp+": "+msg+"\n");

   msg = implode(explode(msg, "'"),"\\'");
   msg = implode(explode(msg, "\""),"\\\"");

   return send_erq(ERQ_FORK, "tweet "+msg, 0);
}
