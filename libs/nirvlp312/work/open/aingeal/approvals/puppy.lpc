2/17/03		Walk-through of Puppy's new area

Here are the list of corrections and suggestions as a result of my
walk-through of the area.  Overall, it looked very good!  
I separated everything by "room", "mob", "equipment", "heals", and
"Misc items".  Please let me know if you have any questions.  
Pain will check everything for balance and will be the one to 
give final approval on the area.
		- Aingeal


ROOMS

room areaentrance.c
1.	Main description:  The first sentence is a sentence fragment, and 
needs a predicate.

2.	You need an item description for: liquid


room 1.c
1.	Try to eliminate "you" and "your" from the main room descriptions.
("catches the eye" rather than "catches your eye" would work just as well.)

2.	Item description "town": "colerful" should be "colorful"


room 2.c
1.	Main description: Should this read "The grass has been worn a 
little..." rather than "The grass has been worn little...."?

2.	Try to eliminate "you" and "your" from the main room descriptions.
Perhaps, "A small bird watches from the trees above" might work as well?


room 3.c
1.	"seems" should be "seem".


room 4.c
1.	You need an item description for: oak

2.	Description for action "listen": Try to eliminate "you".


room 5.c
1.	Try to eliminate "you" from the main description.

2.	You need an item description for: grass

3.	Item description for "blocks": Using "stack" and "stacked" in the 
same sentence is redundant.  You should either limit the description to
"A small stack of blocks" or use another word choice in place of "stack".


room 6.c
1.	Main description: Try to eliminate "your" from the main description.
("the path" would work just as well.)

2.	Item "path": Try to eliminate "you" in this description.

3.	You need an item description for: vines (referenced in your 
		description for item "swing")

4.	You may want to add an action "climb ladder".  Although players 
can't climb it, the description begs them to try, and they get a "what?" 
response.


room 7.c
1.	You need an item description for: pile, huts


room 8.c
1.	You need an item description for: campfire
You may also wish to add item descriptions for: table (singular), 
chair (singular), stump (singular), branch (singular), vine (singular),
	bucket (singular)

2.	Item description for "vines": "vegitation" should be "vegetation"


room 9.c
1.	Main description:  You may wish to change "to do" in the to do list 
to: 'to do' or to-do.

2.	You need an item description for: berry bushes

3.	When I "search under workbench" and "search workbench", I get 
"You search the bushes, but find nothing."

4.	This room is calling Farmer Smurf, rather than Handy Smurf.
Is that what you intended?  The room description suggests that Handy should
be here.


room 10.c
1.	This room cloned two "Painter Smurfs".  You need to code in a check
to make sure the mob isn't in the room before the room clones the mob at reset.

2.	You need an item description for: hill


room 11.c
(No changes or suggestions.)


room 12.c
1.	Main description: Try to eliminate "you" from the main description.
Also, there needs to be a comma in the second sentence between "windows"
and "preventing", and a comma in the last sentence after "hill".


room 13.c
1.	Main description:  Try to eliminate "you" from the main description.

room 14.c
1.	You need an item description for: room


room 15.c
1.	You need an item description for: room, leg (of the workbench)


room 16.c
1.	Main description:  Try to eliminate "you" from the main description.

2.	You need an item description for: bedroom


room 17.c
1.	This is the description for the inside of a room, but nothing in
the adjoining "outside" rooms indicates that the player is entering an
indoor area.  You should change the entrances to this room to reflect that
the player is going from outside to inside.

2.	Main description: "colerful" should be "colorful".
Also, "are hung here against" should be "hang upon".

3.	You need an item description for: room, floor


room 18.c
1.	Did you mean for Handy to clone in this room?  (It just seemed odd -
Hefty fits the room description much better, but he also fits room 22.c.)

2.	Main description: "workout" should be "work out" in the first 
sentence (but not in the second -- it's used as a verb in the first
sentence, and as an adjective in the second, so 'workout' is correct in
the second sentence).  Also, "ones" should have an apostrophe.

3.	You need an item description for: clearing, woods

4.	Description for item "vines": "vegitation" should be "vegetation".


room 19.c
1.	You need an item description for: ground

2.	In the description for item "paper": "shiney" should be "shiny".


room 20.c
1.	Main description:  The first sentence doesn't make sense -- there are
too many verbs.  Try splitting this into multiple full sentences.

2.	In the description for item "rocks": "layed" should be "laid".


room 21.c
1.	Main description:  There should be a comma between "the area" and
"making it one...."

2.	You need an item description for: redwood (singular)



room 22.c
(No corrections or suggestions)


room 23.c
1.	Main description:  There should be a comma in the second sentence
between "west" and "some dark..."  There should also be a comma in the third
sentence between "tree" and "the path ..."
The last sentence is redundant -- the end of the path ends.  A better option
is: "The rocky path ends here."

2.	You need an item description for: sunlight, oak, rocks


room 24.c
1.	Main description: In the second sentence, there should be a comma
between "treetops" and "the ground..."
Try to eliminate "your" from the main description.  ("Overhead..." would work
as well as "Above your head...", and "something glimmers" would work as well
as "something glimmering catches your eye")

2.	You need an item description for: vine

3.	You may want to code an add_action for "pull rope".

4.	The way the room is coded, there is no way to enter the spaceship 
from this room.



room 25.c (spaceship)
1.	You need an item description for: wood

2.	Descriptions for item "seats": "Captains" should have an
apostrophe, and "set" should be "sit".

3.	You may want to include add_actions for "push button(s)" and
"pull lever(s)".


room 26.c
1.	Main description: Try to avoid "your" in the main description.  
There should be a comma in the last sentence between "south" and "giving..."

2.	You need an item description for: structure


room 27.c
1.	Main description: There should be a comma between "bend" and
"it becomes...."
Try to limit use of "you" and "your" in the main descriptions.

2.	Item description for "gray clouds": "mistical" should be "mystical".

3.	"smell liquid": "odours" should be "odors", and "liquid" should
be "the liquid".


room 28.c
1.	You need an item description for: sky


	

MOBS:
(GENERAL NOTE:  Many of these mobs don't have any coins or any items.  
 It might be a good idea to give even the little mobs something of value,
 unless the exp is exceptional for the level of the kill.  I did not
 check these for balance; Pain will do that.)


Puppy Smurf
1.	Main description: There is a subject mis-match in the first 
sentence.  I would break it into two sentences, perhaps like this:
"Puppy was originally given to Papa Smurf as a pet.  However, seeing the
energy that Puppy had and the time it would take to train him, Papa
Smurf decided it would be best to turn him over to the Smurflings."
Also, "faithfull" should be "faithful".


Baby Smurf
1.	Main description:  You need a comma between "from" and "or".

Snappy Smurf
1.	Main description: "carefull" should be "careful".


Slouchy Smurf
1.	Main description: You need a comma between "lazy" and "he just..."
Also, "hear" should be "near".


Cook Smurf
1.	Main description: "Cook Smurf if..." should be "Cook Smurf is..."
There should be a comma in the second sentence between "baby Smurf" and "he..."
Also, there is a tense mismatch in the second sentence (e.g. "he has chosen
that..." should be "he chose cook...").

Farmer Smurf
(No changes or suggestions)

Painter Smurf
1.	Main description: There should be a comma between "grown" and "that".
There should also be a comma in the second sentence between "Smurfs" and "but".


Poet Smurf
1.	Main description: There should be a comma between "writes down" and
"he thinks..."  
(Very cute description)


Smurfette
(No changes or suggestions)


Papa Smurf
1.	Try to eliminate "you" from the main description.
("The village leader is recognizable with his white beard...." would work
 just as well.)


Grandpa Smurf
1.	Main description: In the second sentence, there should be an 
apostrophe in "Smurfs", and a comma after "role".  Also, that sentence should
read "influence over all..." rather than "influence for all...."
There should be a comma in the third sentence between "he is" and "but think".

2.	Try not to use "you" in the main description.

(Okay, I'm on the floor laughing over 'Grandpa removes pants'!)


Handy Smurf
(No corrections or suggestions)


Jokey Smurf
1.	Main description: You need a comma in the last sentence after "while".


Lazy Smurf
(No corrections or recommedations)


Hefty Smurf
1.	Main description: The second sentence has a conflict between
active and passive verbs.  Perhaps this would work better:  
He exercises, he is a sportsman, and he even organizes the Smurf Olympics.


Astro Smurf
1.	Main description: There should be a comma in the last sentence
between "ship" and "and is just...."

King Smurf
1.	Main description: There should be a comma in the first sentence
between "away" and "he would...", in the second sentence between 
"while" and "but...", and in the third sentence between "days" and "he..."
and between "high" and "trying...."


Vanity Smurf
1.	You have Vanity cloning a whistle (an item example from your
examples directory) rather than his mirror.

2.	Try to eliminate "you" from the main description.


Azrael
1.	Main description:  Did you really mean "underdog"?  (The definition
doesn't match the word usage in this sentence -- perhaps "underling"?)
Also, you may wish to capitalize "smurfs" to make it consistent with your
references in the rest of the area.


Gargamel
(Nice job -- what a fun description.  No corrections or suggestions)



EQUIPMENT:

Collar (collar.c)
(No corrections or changes.)

Mirror (mirror.c)
"hand held" should be "hand-held".
(Suggestion only -- perhaps "gaze mirror" should return "You look into
 the mirror" rather than "at" the mirror.)<F2>

Straw Hat (nathat.c)
(No corrections or suggestions.)

Work Boots (boots.c)
1.	Try to eliminate "you" from the description.

Work Gloves (gloves.c)
1.	Try to eliminate "you" from the description.

Apron (apron.c)
(No suggestions or changes.  This description cracked me up, by the way--
 very, very funny!)

Spatula (spatula.c)
(No corrections or suggestions.)

Paint Brush (brush.c)
You may want to add an alias for "paint brush".


Quill (quill.c)
Suggestion:  You may wish to restructure the description phrase, although
the one you have is technically correct.  It may be easier
to read as:  A quill used for writing down thoughts and ideas.

Parchment (parchment.c)
Suggestion:  You may want to do an add_action for "untie parchment" or
"untie string", as the description begs the action.

Lazy's Pillow (pillow.c)
"carrys" should be "carries", and "usefull" should be "useful".

(Grandpa's) pants (gpants.c)
(No suggestions or corrections)

Oak Staff (staff.c)
Spell out '5', rather than listing the numeral.
Also, there should be a comma between "look like much" and "but just...."


Grandpa Smurfs Spectacles (glasses.c)
You need an apostrophe in the short description in "smurfs".
Also, you may want to code in an add_action for "wear".

Handy's hammer (hammer.c)
(No corrections or suggestions)


Wooden Ruler (ruler.c)
There should be a comma between "days" and "but it still...."

(Jokey's) Present (present.c)
(Suggestion only) You may want to change it so a player 
can "open box" or "open present".


(Hefty's) Barbell (bbell.c)
(No changes or corrections)
	
(Astro's) Spacesuit (space.c)
(Suggestion only) You may want to change the description from passive to
active voice (i.e. "This suit was designed ......").


(King's) sceptre (septre.c)
You have this spelled "scepter" in the description and "septre" in the
filename. You should change the spelling in both places to either 
"scepter" or "scepter" to be consistent.  (Both are correct, although 
'sceptre' is the British variant.)
Also, the id is set as a "club" in the code; thus, players cannot drop 
it unless they guess they need to "drop club".
In the first sentence of the description, "has" should be "had", and there
is an extra space after "scepter".

(King's) cape (cape.c)
"hand stitched" should be "hand-stitched".



(King's) crown (crown.c)
"royality" should be "royalty".



HEALS:

Blue Berries
1.	Main description: "handfull" should be "handful"

Poptarts
1.	You need an alias identifying these as "poptarts" as well as "box".

Pancake
1.	You may want to change the message "You finish off the last pancake" 
since these only come in groups of one.

Blue Berry Muffin
1.	You may want to change the message "You finish off the last muffin" 
since these only come in groups of one.

Smurf Juice
1.	You need a period between " 'drink' " and "There is...."
Also, "glasses" should be "glass".


Spirits
1.	You may wish to add an alias identifying the bottle.




MISC. ITEMS:

Building Block
1.	Main description: "it's" should be "its".

Shovel
(No suggestions or corrections)

(Gargamel's) potion
"smell potion": "odours" should be "odors".

	
