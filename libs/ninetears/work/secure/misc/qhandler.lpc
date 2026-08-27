/* be a real bastard, put this in a locked dir */
mixed *questions = ({
  ({"What keeps the crocodiles in the pit beneath your feet well fed ?",({"wrong answers"}),"Wrong answers."}),
   ({"How many Orcs does it take to sharpen a sword ?.",({"which end"}),"The correct (Orcish) answer is \"which end\", hrrmph."}),
  ({"What spell destroyed the Illythid race ?",({"power word genocide"}),"Power word Genocide."}),
  ({"A drow cleric in banefall, and an Elf Wizard in daggerford agree at 1am to fight at the niche,at what time does the fight take place ?",({"never"}),"Never, The drow is by now under Shadowfall, and the Elf is on Wardens."}),
  ({"You are stupid enough to walk into a room that has a locked door and a sign saying \"Tresspassers will be invited to dinner\", you die, do you complain to the gods ?",({"invariably","of course"}),"Invariably.. hmm it says here \"Taniwha sighs sadly\""}),
  ({"You are stupid enough to walk into a room that has a locked door and a sign saying \"Tresspassers will be invited to dinner\", which God laughs loudest ?",({"timion","all of them"}),"How odd, Timion, but there's an Echoing laugh from the heavens ...."}),
  ({"If a Drow invites you to a fair fight at the niche, what do you do ?",({"turn up"}),"Turn up, thats the last place he'll be."}),  	
  ({"What is a goblins idea of a fair fight ?",({"twenty goblins mugging a dead cow"}),"Twenty goblins mugging a dead cow."}),
  
  ({"How many Drow does it take to light a torch ?",({"one"}),"One if sufficient lamp oil is added to the Drow prior to ignition is generally considered sufficient."}),
  ({"How many Drow does it take to light a torch ?",({"none"}),"A True Drow would rather curse the darkness than ligh a torch."}),
  ({"How many Vampires does it take to light a torch ?",({"none"}),"You gotta be jokning clive , no Vampire would do that."}),
  ({"How many Dwarves does it take to light a torch ?",({"none"}),"We'll have non of that revolutionary strike business around here thank you !"}),
  ({"How many Thieves does it take to light a torch ?",({"what torch","I could have sworn it was here a moment ago"}),"what torch ?"}),
  ({"How many Cyrcia clerics does it take to light a torch ?",({"two"}),"One to pray, one to wipe the blood off afterwards."}),
  ({"How many fighters does it take to light a torch ?",({"which end ?","which end,which end?"}),"which end ?"}),
  ({"How does one summon a demon.",({"carefully","damn carefully"}),"Damn carefully."}),
  ({"How does a Troll sharpen a sword ?..",({"shaves","shaves with it"}),"Shaves with it."}),
  ({"How do you get a drink out of a Dwarf..",({"cut his throat","stick a finger down his throat"}),"Stick a finger down his throat."}),
  ({"How many Trolls does it take to sharpen a sword ?..",({"three"}),"Three, one to hold the sword and two to move the grindstone back and forth."}),
  ({"How many people does it take to make a working love potion..",({"two"}),"heh."}),
  ({"Whats the surest way to get thrown out of a Dwarf bar ?..",({"order a short"}),"Order a short."}),
  ({"Whats a dwarves favourite song subject, other than \"gold\"..",({"gold"}),"Well that was obvious"}),
  ({"Say what I say not do as I do, say \"feet without shoes and socks\"..",({"feet"}),"Heh."}),
  ({"Say what I say not do as I do, say \"feet without shoes and socks\"..",({"feet and socks"}),"Heh.."}),
  ({"Say what I say not do as I do, say \"feet without shoes or socks\"..",({"feet"}),"Heh.."}),
  ({"Say what I say not do as I do, say \"feet without shoes or socks\"..",({"feet","socks"}),"Heh.."}),
  ({"Don't say what I say but do as I do, say \"feet without shoes or socks\"..",({"bare feet","barefoot"}),"Heh.."}),
  ({"I eat mountains, destroy civilizations and annoy philosophs, what am I ?..",({"time"}),"Time.."}),
  ({"What did the zombie say to the lady of the night ?..",({"keep the tip"}),"Keep the tip.."}),
  ({"Two Trolls walk into a bar, what happens next ?..",({"ouch"}),"ouch.."}),
  ({"How many Assassins does it take to sharpen a sword ?..",({"two"}),"Two, one to light the torch, one to hide the body.."}),
});
/* gotta be an efun for this */

int a_qnum()
{
    return (1+random(sizeof(questions)-1));

}

string the_question(int num)
{
    return questions[num][0];

}

string the_possibles(int num)
{
    return questions[num][0];

}
string numwords(int num)
{
    return number_as_string(sizeof(questions[num][1]));
}

string minans(int num)
{
    int i,m,n;
    string * answers;
    m = 69;
    answers = questions[num][1];
    for(i = 0; i < sizeof(answers); i++)
    {
        n = sizeof(explode(answers[i]," "));
        if(n < m) m = n;
    }
    return number_as_string(m);
}     

string maxans(int num)
{
    int i,m,n;
    string * answers;
    m = 0;
    answers = questions[num][1];
    for(i = 0; i < sizeof(answers); i++)
    {
        n = sizeof(explode(answers[i]," "));
        if(n > m) m = n;
    }
    return number_as_string(m);
}     
/* O.K. it's crude, it's nasty 
 If I'm nice I just check that the answer has all the same words 
 as the set I expect and pass anyway
 */
int check_answer(int num, string answer)
{
    string *answers;
    answers = questions[num][1];
    answer = lower_case(answer);
    if(member_array(answer,answers) != -1) return 1;
    else return 0;      
}

string the_answer(int num)
{
    return questions[num][2];

}

