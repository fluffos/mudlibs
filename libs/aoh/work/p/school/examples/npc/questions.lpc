/*--------------------------------------------------------------------------
 *  /p/school/examples/npc/questions.c --  Example NPC
 *
 *  Copyright (C) 1997 by One Step Beyond.
 *  All Rights Reserved.
 *  Permission granted for non-commercial use.
 *-------------------------------------------------------------------------- 
 *  31-07-97 [tune]  creation
 *
 *  Demonstrates the use of questions in npcs
 * 
 *  Section 1: General NPC configuration
 *  Section 2: Basic question formats ( AddQuestion() )
 *  Section 3: Advanced question formats ( SetQuestions(), use of closures )
 *
 *  This NPC knows the answers to questions about:
 *     osb, calculator, coke, coca-cola, geek, quest, 
 *     pocket protector, mateese
 */
 

#include <npc.h>
#include <properties.h>

inherit "/std/npc";

// prototype
string my_questions(string s);


/* =======================================================================
**       [Section 1]      Initial Configuration
** =======================================================================
**
**       Setting up a simple NPC doesn't take much effort. The basic
**       things you should configure are short and long, name, race,
**       level, and gender. This will give you a perfectly functional,
**       though somewhat bland, NPC.
*/

varargs void create()
{ 
    // --> Always start NPC's like this (and only NPC's!)
    
  ::create();

    // --> NPC's should have a name if they are "unique"
    //     To avoid problems, set the name before the short
    
  SetName("Joe");
  
    // --> NPCs need a short like other objects
    
  SetShort("Joe, the questions npc");
  
    // --> What does he look like?
    
  SetLong("Joe looks like your average geeky programmer - pocket "
          "protector, algebraic calculator and cokebottle glasses.\n");
  
    // --> Now give him some characteristics
    
  SetGender(GENDER_MALE);
  SetLevel(5);
  SetRace("human");
  
    // --> Give him a better answer when he doesn't know a question
  
  SetShrugMsg(
    "Joe fiddles with his calculator. He doesn't seem to be listening.");
  
  
/* =======================================================================
**       [Section 2]      Basic Question Formats                          
** =======================================================================
**
**       There are multiple ways of adding questions and answers to
**       NPCs. Section 2 lists the basic 4 methods, which all use
**       AddQuestion() (a function found in /std/npc.c).
**
**       When you add questions, it's important to remember that you
**       also need to add the "Joe says:" to your answer (or however
**       you want them to respond, this is free for you to decide).
*/    
    
   /*  ----------------------------------------------------------------
    *    Example 1      
    *    AddQuestion( string question, string answer )
    *  ----------------------------------------------------------------
    *
    *    The most basic or simple way of adding questions to an npc
    *    is to add one string for the question keyword and one string
    *    for the answer. This answer goes to everyone in the room,
    *    _not_ just the person who asked.
    * 
    *  ----------------------------------------------------------------
    */
    
    AddQuestion("calculator",  
          "Joe exclaims: Oh, this is my nifty neato super-modular "
          "multi-flexible reverse-engineered proto-GUI calculator!"  
     );
  
   /*  ----------------------------------------------------------------
    *    Example 2
    *    AddQuestion( ({ string q1, string q2 }), string answer )
    *  ----------------------------------------------------------------  
    *
    *    Type two: you can have several question keywords which all
    *    receive the same answer. Simply store all the question keywords
    *    in an array.
    * 
    *  ----------------------------------------------------------------
    */
    
    AddQuestion( ({ "coke", "coca-cola" }),    // our list of questions
         "Joe exclaims: Hey, no programmer can live without it! "
         "Coke is the elixor of life." );
             
             
   /*  ----------------------------------------------------------------
    *    Example 3
    *    AddQuestion( string question, ({ string a1, string a2 })  )
    *  ----------------------------------------------------------------  
    *             
    *    You can also give out different messages, one for the player
    *    who asked the question, and a different one for the other
    *    people in the room. To do this, use an array of two strings
    *    for the answer.
    *
    *  ----------------------------------------------------------------
    */   
    
    
    AddQuestion( "geeks",  
                  ({ "Joe exclaims: Hey! Whatcha got against geeks?", 
                     "Joe mumbles something incoherent about geeks."
                  }) 
               );
              
   /*  ----------------------------------------------------------------
    *    Example 4
    *    AddQuestion( string question, string answer, silent int )
    *  ----------------------------------------------------------------  
    *             
    *    Sometimes you don't want your npc to tell everyone in the room
    *    the answer to a question. Maybe it's a quest hint, maybe it's
    *    a secret, etc. If you add a third argument of '1', the answer
    *    will only be printed to the player who asked the question.
    *    (You can also achieve the same effect using 0 as the second
    *    argument in the answer array).
    *
    *  ----------------------------------------------------------------
    */       
    
    AddQuestion("quest", 
     "Joe holds his finger to his lips: Shhh! That would be cheating.", 1);
  
    // alternatively...
  
    AddQuestion("pocket protector", 
        ({"Joe proudly shows you his plastic pocket protector.", 0 }) );         
     
 
/* ======================================================================= 
**       [Section 3]      Advanced Examples                           
** =======================================================================  

**       These following examples assume that you are more comfortable
**       with LPC and the mudlib. To use closures, you need be able
**       to write and understand functions.

**       Please note that SetQuestions() as shown in examples 5 & 6
**       are more prone to producing hard-to-find bugs, and it is 
**       usually a better idea to stick with AddQuestion() instead.  
*/

     
   /*  ----------------------------------------------------------------
    *    Example 5
    *    AddQuestion( string question, closure c )
    *  ----------------------------------------------------------------  
    *             
    *    If you need dynamic responses (i.e. answers which change, 
    *    dependent on some factor), add a closure for the answer.
    *    This will call the function in the closure.
    *
    *    Your closure will be called with the question keyword as the
    *    argument (in case you want to have a multi-purpose function
    *    which can answer multiple questions), and should return the
    *    answer message as a string.
    *    
    *  ----------------------------------------------------------------
    *    ( the function call my_questions() is continued below )
    */       
    
    AddQuestion("osb", #'my_questions);
  
    AddQuestion("mateese", #'my_questions);
  
  
   /*  ----------------------------------------------------------------
    *    Example 6
    *    SetQuestions( ([ q1: a1, q2: a2, q3: a3 ]) )
    *  ----------------------------------------------------------------  
    *             
    *    If you want, you can put all of your questions and answers 
    *    together into one big mapping. The keys are the questions,
    *    and the values are the answers.
    *
    *    It's not a good idea to mix this with AddQuestions - in
    *    particular, if you use SetQuestions() _after_ you have already
    *    used AddQuestion(), you will wipe out all of the questions
    *    you added. (If you do want to, or need to, use both, just be
    *    sure to use SetQuestions() before AddQuestion().)    
    *
    *  ----------------------------------------------------------------
    *    (commented out for reason mentioned above)
    *
    *    SetQuestions( ([ "chocolate": "Tastes yummy.",
    *                     "spinach": "Not as good as chocolate." ]) );
    */
    
    
   /*  ----------------------------------------------------------------
    *    Example 7
    *    SetQuestions( ({ q1, a1, q2, a2, q3, a3 }) )
    *  ----------------------------------------------------------------  
    *             
    *    It is also possible to initialize all your questions via
    *    SetQuestions() by using one large array instead of a mapping.
    *
    *    The same precaution applies as in example 6.
    *    
    *    It is additionally possible to make question arrays within
    *    the array.
    *    Ex: SetQuestions( ({ ({ q1a, q1b, q1c }), a1, q2, a2 }) );
    *
    *  ----------------------------------------------------------------
    *    (commented out for reason mentioned above)
    *
    *    SetQuestions( ({
    *        "chocolate", "Tastes yummy.", "pizza", "My favorite dinner.",
    *        ({ "spinach", "brussel sprouts" }), "Not as good as chocolate." 
    *     }) );
    */
  
}   // end of create()


/* --------------------------------------------------------------
**    Continuation of Example (5)
** --------------------------------------------------------------
*/

string my_questions(string question)
{
  object ob, env;
  string where;
  
  // Did player ask about osb?
  
  if(question == "osb")
    return "" + sizeof(users()) + 
      " people are logged into OSB right now.\n";
  
  // Did player ask about mateese?
  
  if(question == "mateese")
  {  
    ob = find_living("mateese");    // let's look for Mateese
    if( !ob )                       // hmmmm, not logged in
      return "Joe sighs. 'Mateese isn't here right now.'\n";
      
    env = environment(ob);          // where is Mateese right now?
    where = env->QueryIntShort();   // if he's in a room, this is the name 
    
    if( where != 0 && where != "" )
      return "Mateese is currently in " +  where + ".\n";  
    
    return "Joe isn't really sure where Mateese is right now.\n";
  }
  
  // Return some default text if we don't have an answer.
  return "Joe is confused.\n";
}
  
/***************************************************************/
