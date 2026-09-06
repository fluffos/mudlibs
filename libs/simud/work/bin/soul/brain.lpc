#include <emote.h>

void say(string str, object who, object other) {
  set_actor(who); set_target(other);
  if (!this_player()->query_toad())
     who->say_local( "~CEMO~Name says~CDEF: "+str, strlen(who->query_name()) + 7 );
  msg_object(who, "~CEMOYou say~CDEF: "+str, 9 );
}

string pinky() {
  switch (random(70)) {
     case 0: return "but where are we going to find a duck and a hose at this hour?";
     case 1: return "but where are we going to find an open tattoo parlour at this time of night?";
     case 2: return "but if we didn't have ears, we'd look like weasels.";
     case 3: return "but where are we going to find rubber pants our size?";
     case 4: return "but balancing a family and a career... ooh, it's all too much for me.";
     case 5: return "but isn't Regis Philbin already married?";
     case 6: return "but burlap chafes me so.";
     case 7: return "but how are we going to find chaps our size?";
     case 8: return "but we'll never get a monkey to use dental floss.";
     case 9: return "but this time you wear the tutu.";
     case 10: return "but culottes have a tendancy to ride up so.";
     case 11: return "but if they called them 'Sad Meals', kids wouldn't buy them.";
     case 12: return "but me and Pippi Longstocking -- I mean, what would the children look like?";
     case 13: return "but this time, you put the trousers on the chimp.";
     case 14: return "but I can't memorize a whole opera in Yiddish.";
     case 15: return "but there's still a bug stuck in here from last time.";
     case 16: return "but I get all clammy inside the tent.";
     case 17: return "but I don't think Kay Ballard's in the union.";
     case 18: return "but, the Rockettes? I mean, it's girls, isn't it?";
     case 19: return "but pants with horizontal stripes make me look chubby.";
     case 20: return "poit, but where do you stick the feather and call it macaroni?";
     case 21: return "but pantyhose are so uncomfortable in the summertime.";
     case 22: return "but it's a miracle that this one grew back.";
     case 23: return "but first you'd have to take that whole bridge apart, wouldn't you?";
     case 24: return "but 'apply North Pole' to what?";
     case 25: return "but 'Snowball for Windows?'";
     case 26: return "but ... *snort* ... no, no, it's to stupid.";
     case 27: return "but umm..., why would Sophia Loren do a musical?";
     case 28: return "but what if the chicken won't wear the nylons?";
     case 29: return "but isn't that why they invented tube socks?";
     case 30: return "but what if we stick to the seat covers?";
     case 31: return "but I think I'd rather eat the Macarena?";
     case 32: return "*hiccup* but Kevin Costner with an English accent?";
     case 33: return "but don't you need a swimming pool to play Marco Polo?";
     case 34: return "but do I really need two tongues?";
     case 35: return "but we're already naked.";
     case 36: return "but if Jimmy cracks corn, and nobody cares, why does he keep doing it?";
     case 37: return "NARF, but don't camels spit a lot?";
     case 38: return "but how will we get a pair of Abe Vigoda's pants?";
     case 39: return "But Pete Rose? I mean, can we trust him?";
     case 40: return "but why wound Peter Bogdanovich?";
     case 41: return "but isn't a cucumber that small called a gherkin?";
     case 42: return "but if we get Sam Spade, we'll never have any puppies.";
     case 43: return "but calling it a pu-pu platter? Huh, what were they thinking?";
     case 44: return "but how will we get the Spice Girls into the paella?";
     case 45: return "but if we give peas a chance, won't the lima beans feel left out?";
     case 46: return "but if we had a snowmobile, wouldn't it melt before summer?";
     case 47: return "but what kind of rides do they have in Fabioland?";
     case 48: return "but can the Gummi Worms really live in peace with the Marshmallow Chicks?";
     case 49: return "but wouldn't anything lose its flavor on the bedpost overnight?";
     case 50: return "but three rounds meals a day wouldn't be as hard to swallow.";
     case 51: return "but if the plural of mouse is mice, wouldn't the plural of spouse be spice?";
     case 52: return "but three men in a tub? Ooh, that's unsanitary.";
     case 53: return "but I prefer Space Jelly.";
     case 54: return "but if our knees bent the other way, how would we ride a bicycle?";
     case 55: return "but how will we get three pink flamingos into one pair of Capri pants?";
     case 56: return "but Tuesday Weld isn't a complete sentence.";
     case 57: return "but why would anyone want to see Snow White and the Seven Samurai?";
     case 58: return "but then my name would be Thumby.";
     case 59: return "but scratching just makes it worse.";
     case 60: return "but shouldn't the bat boy be wearing a cape?";
     case 61: return "but why would anyone want a depressed tongue?";
     case 62: return "but why would anyone want to Pierce Brosnan?";
     case 63: return "but wouldn't his movies be more suitable for children if we was named Jean-Claude van Darn?";
     case 64: return "but will they let the Cranberry Duchess stay in the Lincoln Bedroom?";
     case 65: return "but why does a forklift have to be so big if all it does is lift forks?";
     case 66: return "but if it was only supposed to be a three hour tour why did the Howells bring all their money?";
     case 67: return "but Zero Mostel times anything will still give you Zero Mostel.";
     case 68: return "but if we have nothing to fear but fear itself, why does Eleanor Roosevelt wear that spooky mask?";
     case 69: return "but what if the hippopotamus won't wear the beach thong?";
  }

  return ""; // for spammy warning
}

void holy_grail(int step, object p, object b) {
   string buf;
   switch (step) {
      case 1: buf = "Whoof, oh, I'd have to say the odds are slim, "+b->query_cap_name()+"."; break;
      case 2: buf = "True."; break;
      case 3: buf = "I mean, really, when have I ever been pondering what you've been pondering?"; break;
      case 4: buf = "To my knowledge, never."; break;
      case 5: buf = "Exactly. So, what are the chances that this time, I'm pondering what you're pondering?"; break;
      case 6: buf = "Next to nil."; break;
      case 7: buf = "Well, that's exactly what I'm thinking, too."; break;
      case 8: buf = "Therefore, you are pondering what I'm pondering."; break;
      case 9: buf = "Poit, I guess I am.";
   }
   if (step % 2) {
      say(buf,p,b);
   } else {
      say(buf,b,p);
   }
   if (step < 9)
      call_out("holy_grail",2,step+1,p,b);
}

void reply(object p, object b) {
   if (random(100) < 90) {
      say("I think so, "+b->query_cap_name()+", "+pinky(),p,b);
   } else {
     string buf;
     switch(random(8)) {
        case 0: buf = "Yes, I am."; break;
        case 1: buf = "We eat the box?"; break;
        case 2: buf = "I think so Larry and, um, "+b->query_cap_name()+", but how will we get seven dwarves to shave their legs?"; break;
        case 3: buf = "Oh, "+b->query_cap_name()+" I certainly hope so."; break;
        case 4: buf = "Yes, but why does the chicken cross the road, huh, if not for love? Sigh. I do not know."; break;
        case 5: buf = "Methinks so, "+b->query_cap_name()+", verily, but dost thou think Pete Rose by any other name would still smell as sweaty?"; break;
        case 6: {
           string old = (p->query_cap_name())[0..0];
           string new = old;
           while (new == old)
              new = efun::to_string( ({random(26)+65}) );
           buf = "I think so, "+b->query_cap_name()+" but if you replace the '"+old+"' with '"+new+"', my name would be "+new+p->query_name()[1..]+", wouldn't it?";
           break;
        default:
           holy_grail(1,p,b);
           return;
        }
     }
     say(buf,p,b);
   }
}

int main(string param) {
   object t;

   if(param) {
      if( t = present(param,environment(this_player()))) {
         say(t->query_cap_name()+", are you pondering what I'm pondering?",this_player(),t);
         if( t->query_is_living() && !this_player()->query_toad())
            call_out("reply",1,t,this_player());
      }
      else msg ("~[010No one by that name here~[070.");
   }
   else {
     if (!this_player()->query_toad())
        say("Are you pondering what I'm pondering?",this_player(),t);
   }
   return 1;
}
