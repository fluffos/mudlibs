#include <emote.h>

string carroll() {

  switch (random(70)) {
    case 0: return "Inconceivable!";

    case 1: return "Rodents Of Unusual Size? I don't think they exist.";

    case 2: return "You mean you wish to surrender to me? Very well then, I accept.";

    case 3: return "The Pit of Despair....don't even think...[cough, gag] Don't even think about trying to escape.";

    case 4: return "Well I'm not saying I'd like to build a summer home here but the trees are actually quite lovely.";

    case 5: return "Hello, my name is Inigo Montoya. You killed my father. Prepare to die.";

    case 6: return "It's possible, pig. I might be bluffing. It's conceivable you miserable vomitous mass.";

    case 7: return "Mawwiage. Mawwiage is what bwings us togethaw today.";

    case 8: return "I'll beat you both apart! I'll take you both together!";

    case 9: return "Have fun storming the castle! Think it will work? It would take a miracle.";

    case 10: return "It just so happens that your friend here is only mostly dead.";

    case 11: return "Now, mostly dead is slightly alive.";

    case 12: return "Now, all dead...well, with all dead, there's usually only one thing that you can do. Go through his clothes and look for loose change.";

    case 13: return "I...am...waiting...for...Vizzini. You surely are a meany.";

    case 14: return "You told me to go back to the beginning, so I have. This is where I am, and this is where I'll stay. I will not be moved.";

    case 15: return "The Queen of Slime, the Queen of Filth, the Queen of putrescence!";

    case 16: return "As you Wish.";

    case 17: return "Murdered by pirates is good!";

    case 18: return "You were not hired for your brains you hippo-britanic land mass!!";

    case 19: return "Do you want me to send you to where you were? Unemployed, in Greenland!!";

    case 20: return "Vizzini, he can...fuss. Fuss, fuss, I think he likes to scream at us.";

    case 21: return "Probably he means no...harm.  He's very very short on...charm.";

    case 22: return "You have a great gift for rhyme. Yes, yes, some of the time.";

    case 23: return "Fezzik, are there rocks ahead? If there are, we all be dead.";

    case 24: return "No more rhymes now, I mean it! Anybody want a peanut?";

    case 25: return "They always grow louder when they're about to feed on human flesh!";

    case 26: return "The Cliffs of Insanity!!!";

    case 27: return "Move..the thing...and that other thing!";

    case 28: return "Inconceivable!";

    case 29: return "You keep using that word? I do not think it means what you think it means...";

    case 30: return "But I do not think you would accept my help, since I am only waiting around to kill you.";

    case 31: return "You seem a decent fellow...I hate to kill you.";

    case 32: return "You seem a decent fellow...I hate to die.";

    case 33: return "You are using Bonetties Defense against me, ah?";

    case 34: return "I thought it fitting considering the rocky terrain.";

    case 35: return "Naturally, you must suspect me to attack with Capa Fero?";

    case 36: return "Naturally...but I find that Tibal cancels out Capa Fero. Don't you?";

    case 37: return "Unless the enemy has studied his Agrippa...which I have.";

    case 38: return "I am not left-handed!";

    case 39: return "I'm not left-handed either.";

    case 40: return "I would as soon destroy a stained glass window as an artist like yourself.";

    case 41: return "The minute his HEAD is in view hit it with the rock!";

    case 42: return "We face each other as god intended; sportsman-like...no tricks, no weapons, skill against skill alone.";

    case 43: return "You mean, you'll put down your rock and I'll put down my sword and we'll try and kill each other like civilized people?";

    case 44: return "Rest well and dream of large women.";

    case 45: return "Have you ever heard of Plato, Aristotle, Socrates? Morons!";

    case 46: return "What you do not smell is Iocaine powder.";

    case 47: return "You'd like to think that, wouldn't you!";

    case 48: return "It has worked! You've given everything away! I know where the poison is!";

    case 49: return "The most famous is never get involved in a land war in Asia; and only slightly less well known is this: Never go in against a Sicilian, when death is on the line!";

    case 50: return "Hahahaha.... hahahaha.... hahahahah-*THUD*";

    case 51: return "They were both poisoned.";

    case 52: return "It's possible, I kill a lot of people.";

    case 53: return "No, a farmboy...poor! Poor and perfect.";

    case 54: return "I mean once word leaks out that a pirate has gone soft people begin to disobey him and its nothing but work, work, work all the time.";

    case 55: return "Life is pain, highness! Anyone who says differently is selling something.";

    case 56: return "Nonsense! You're only saying that because no one ever has.";

    case 57: return "Good night Westley, good work, sleep well, I'll most likely kill you in the morning.";

    case 58: return "I swear it will be done.";

    case 59: return "Yes, you're very smart. Shut up.";

    case 60: return "Not to fifty!!";

    case 61: return "Fezzik, jog his memory.";

    case 62: return "Why don't you give me a nice paper cut, and pour lemon juice on it.";

    case 63: return "And as we all know, to blaithe means to bluff. So, you were probably playing cards and he cheated...";

    case 64: return "What, Humperdinck?! Ahh!! Humperdinck! Ahh!!";

    case 65: return "Let me explain....no, there is too much. Let me sum up.";

    case 66: return "Fezzik, tear his arms off. Oh, you mean this gate key.";

    default: return "Hello, my name is Inigo Montoya. You killed my father. Prepare to die.";

  }

  return 0;
}

string query_cself() { return "~Name ~verbquote: "+carroll(); }
string query_ctarget() { return "~Name ~verbquote to ~targ: "+carroll(); }

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
