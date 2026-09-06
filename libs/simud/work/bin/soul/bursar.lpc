#include <emote.h>

string query_cself() {
   switch ( random(12) ) {
      case 0: return "~Name ~verbyell, 'I like to listen to a man who likes to talk! Whoops! Sawdust and treacle! Put that in your herring and smoke it!'";
      case 1: return "~Name ~verbsearch for some dried frog pills.";
      case 2: return "~Name ~verbsay, 'Why, I'll have a little of the roast weasel, if you would be so good.'";
      case 3: return "~Name ~verbsay, 'And now, I must fly... except that I mustn't.'";
      case 4: return "~Name ~verbmumble, 'Whoops, here comes Mr. Jelly.'";
      case 5: return "~Name ~verbsay, 'Oh Good. I like sherry.'";
      case 6: return "~Name ~verbdeclare, 'Celery.'";
      case 7: return "'This is a lovely party,' ~name ~verbsay to a chair, 'I wish I was here.'";
      case 8: return "~Name ~verbshout, 'Yo Yo!'";
      case 9: return "~Name ~verbstate, 'It's having no boots that does it.'";
      case 10: return "~Name ~verbsay, 'Hooray for the pink, grey and green.'";
      case 11: return "~Name ~verbsay, 'Yes, thank you, a green one with cinnamon if it's not too much trouble.'";
   }
   return ""; // quiet annoying warnings
}

string query_ctarget() {
   switch ( random(12) ) {
      case 0: return "~Name ~verbshout at ~targ, 'I like to listen to a man who likes to talk! Whoops! Sawdust and treacle! Put that in your herring and smoke it!'";
      case 1: return "~Name ~verbask ~targ for some dried frog pills.";
      case 2: return "~Name ~verbtell ~targ, 'Why, I'll have a little of the roast weasel, if you would be so good.'";
      case 3: return "~Name ~verbsay to ~targ, 'And now, I must fly... except that I mustn't.'";
      case 4: return "~Name ~verbmumble to ~targ, 'Whoops, here comes Mr. Jelly.'";
      case 5: return "~Name ~verbsay, 'Oh Good. I like sherry.'";
      case 6: return "~Name ~verbdeclare, 'Celery.'";
      case 7: return "'This is a lovely party,' ~name ~verbsay to ~targ, 'I wish I was here.'";
      case 8: return "~Name ~verbshout at ~targ, 'Yo Yo!'";
      case 9: return "~Name ~verbstate to ~targ, 'It's having no boots that does it.'";
      case 10: return "~Name ~verbsay to ~targ, 'Hooray for the pink, grey and green.'";
      case 11: return "~Name ~verbsay to ~targ, 'Yes, thank you, a green one with cinnamon if it's not too much trouble.'";
   }
   return ""; // quiet annoying warnings
}

int main(string param) {
   object t;

   if(param) {
      if( t = present(param,environment(this_player()))) {
         set_target(t);
         if (!this_player()->query_toad())
            this_player()->msg_local("~CEMO"+query_ctarget()+"~CDEF");
         else
            msg("~CEMO"+query_ctarget()+"~CDEF");
      }
      else msg ("~[010No one by that name here~[070.");
   }
   else {
     if (!this_player()->query_toad())
        this_player()->msg_local("~CEMO"+query_cself()+"~CDEF");
     else
        msg("~CEMO"+query_cself()+"~CDEF");
   }
   return 1;
}
