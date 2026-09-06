#include <const.h>

/*This verb is part of the site object, or at least requires a site object
 *in the room. Player makes a onetime no practice skillcheck on ka.sc.geology,
 *and that roll is the probability to check the first level. From there it
 *decreases by 10% each level.If you fail a check, let players know there's more
 *levels.

 *Sample Output:
 *You survey the area, noting X amounts of Y, Z amounts of ALPHA... etc. However
 *you can't get past the feeling that there's more down past the BETA layers you
 *dug through.
 */

string mound_it(int i) {
   if(i == 1) {
      return "vein";
   } else {
      return "veins";
   }
}

int main(string param) {
   object site, building;
   string *reslist;
   string toshow;
   mapping finallist, cached_survey;
   int dc, failed, test, depth, full_depth;

   if (!param) {
      return notify_fail("What is it you want to survey?\n");
   }

   if(param != "site" && param != "mine") {
      return notify_fail("Why would you want to survey that?!");
   }

   site = single_present( param, environment(this_player()) );

   if(!site) {
      return notify_fail("I don't see the thing you want to survey.\n");
   }

   if(site->query_name() == "mine") {
      cached_survey = site->query_survey();
      full_depth = site->query_full_depth();
      toshow = "~Name ~verbassess the area, ";
      if(sizeof(cached_survey) == 0) {
         toshow += "unfortunately ~name doesn't seem to learn anything.";
      } else {
         toshow += "noting the presence of ";
         foreach(object rock: cached_survey) {
            toshow += cached_survey[rock] + " " + mound_it(cached_survey[rock])
                   + " of " + rock->query_name() + ", ";
         }
      }
      if(full_depth) {
         toshow += "and ~verbrest, having completed the survey.";
      } else {
         toshow += "and yet ~verbappear to think a mine should go deeper.";
      }
      this_player()->msg_local("~CACT" + toshow + "~CDEF");
      return 1;
   }

   building = site->query_building();

   if(!building || building->query_name() != "mine") {
      return notify_fail("Now why would you want to survey that?\n");
   }

   cached_survey = site->query_building()->query_survey();

   /**Find out if someone's already surveyed the area**/
   if(cached_survey) {
      full_depth = site->query_building()->query_full_depth();
      toshow = "~Name ~verbassess the area, ";
      if(sizeof(cached_survey) == 0) {
         toshow += "unfortunately ~name doesn't seem to learn anything.";
      } else {
         toshow += "noting the presence of ";
         foreach(object rock: cached_survey) {
            toshow += cached_survey[rock] + " " + mound_it(cached_survey[rock])
                   + " of " + rock->query_name() + ", ";
         }
      }
      if(full_depth) {
         toshow += "and ~verbrest, having completed the survey.";
      } else {
         toshow += "and yet ~verbappear to think a mine should go deeper.";
      }
      this_player()->msg_local("~CACT" + toshow + "~CDEF");
      return 1;
   }

   dc = this_player()->skill_check("nopractice:knowledge.science.geology", 10,
                                   20, 30, 40, 50, 60, 70, 80, 90) * 10;

   if(environment(site) && environment(environment(site))) {
      reslist = environment(environment(site))->query_minerals();
   }

   failed = 0;
   depth = 0;
   finallist = ([]);

   while(!failed) {
      test = random(10) * 10;
      if((dc - test) >= 0) {
         depth++;
         dc -= 10;
      } else {
         if(depth > sizeof(reslist)) {
            depth = sizeof(reslist);
         }
         for(int j = 0; j < depth; j++) {
            finallist[reslist[j]]++;
         }
         failed = 1;
      }
   }

   toshow = "~Name ~verbassess the area, ";

   if(depth == 0) {
      toshow += "unfortunately ~name doesn't seem to learn anything.";
   } else {
      toshow += "noting the presence of ";
      foreach(object rock: finallist) {
         toshow += finallist[rock] + " " + mound_it(finallist[rock])
                + " of " + rock->query_name() + ", ";
      }
   }

   if(depth != sizeof(reslist)) {
      toshow += "and yet ~verbappear to think a mine should go deeper.";
      site->query_building()->set_full_depth(0);
   } else {
      toshow += "and ~verbrest, having completed the survey.";
      site->query_building()->set_full_depth(1);
   }

   site->query_building()->set_survey(finallist);
   this_player()->msg_local("~CACT" + toshow + "~CDEF");
   return 1;
}
