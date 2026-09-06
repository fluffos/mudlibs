================================================================
                       CASINO OVERVIEW
================================================================

The casino is an area where players can gamble their hard-earned
gold coins.  Usually the casino covers all bets, except at the  
poker table, where players compete against each other.

The casino currently has the following gambling machines/tables:


             Machine            Type (see below)
        ----------------------------------------
         Wheel of Fortune            M/S,N
         Roulette wheel              M/S,N
         Wheel of Misfortune          S,N

         Goblinoid Slot machine       S,N
         Ancient slot machine         S,N
         Lordly slot machine          S,N
         Guild slot machine           S,N
         Blue magic poker machine     S,N
         Green magic poker machine    S,N
         Red magic poker machine      S,N

         Baccarat table              M/S,I
         Blackjack table             M/S,I
         Poker table                  M,I


  M => Multi-player    : Many players can play at a time       

  S => Single player   : Only one player can play at a time

  N => Non interactive : Game result is returned in one round

  I => Interactive     : Multiple rounds are required before
                         the result can be determined. 


                        --------


Wherever possible, I have coded the machines to be as close as
possible to the RL equivalent machines.  This means that the
general rules, betting limits, and house profit margin are
apprximately the same as in RL.  Most of these machines
in theory have a profit margin of around 2-5%, meaning that
for every 100 coins spent by the player, the casino will
keep 2-5 on average.  See each particular machine code for
more specific comments. 

Currently, the player luck stat is NOT used in determining
the outcomes of any of the machines.  However, it might
be cool in the future to code a dependance on the player's
luck factor. 

The machines are coded to keep track of how many coins have
been won/lost since the last reboot.  If too many coins are
lost, most machines will assume that they are bugged, and
shut themselves down.

Also, each machine can be set to keep a logfile of each
time a player wins and what the winning situation was.

                      --------

Obviously, in order to be able to gamble, players must be
able to carry gold coins, perhaps even lots of gold coins!
Consequently, good casino security is necessary to prevent
gold from being stolen.  

My philosophy is that nothing should be forbidden - stealing
is (and must be) possible in the casino.  However, players
must feel secure enough to carry the necessary coins for
fun gambling. 

So, the casino must employ a number of bouncers.  These guys
are VERY tough, and when fighting in a group are probably
virtually impossible for a player to kill.  When a player
commits a crime (steals or attacks a dealer, etc) the bouncers
are summoned.  Once the bouncers have been summoned, they
will NEVER give up until the player is dead, or until
the player manages to kill them.  They follow the player
WHEREVER he goes, including ld.  I rather like this feature,
because players who go ld at the first hint of trouble
are really annoying to me.  After player is killed, the
bouncers will return to the casino security room.
 
Currently, stealing attempts have a 50% chance of being
noticed by the security.
   
                      --------

The casino doorman prevents players younger than 10 days
from entering the casino.  This is partly to stop 2nd
chars from totally lagging up the place, and also partly
to punish plastic lords.  Besides, young players probably
can't afford to be there anyhow. :) 

Anyway, I am open to any ideas/complaints anyone might
have with regard to the casino, so please mail me if
you have any comments.

//Germ 
