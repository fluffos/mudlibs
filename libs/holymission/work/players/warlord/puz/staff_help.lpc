Commands     Arguments               Notes
------------------------------------------------------------------
 mail        [player_name]           Works like at the post house.
 read        none or 'mail'          Works like at the post house.
 count       <intger>                Sets how many times the 'patch'
                                     command shall be executed.
 Get         [object]                Silent get.
 reset       [object]                Resets a room/object.
 tail        none                    tails the file /lpmud.log
 rm          none                    If 'rm' or 'cat' is done without
 cat         none                    an argument, the default will be
                                     your own log. ie /log/<your_name>
 Goto        [object]                Silent goto
 List        none                    Lists remembered objects.
 patch       [object] [func] [arg]   This command calls the function
                                     [func] in the [object] with the
                                     argumants [arg].
                                     Ex.    patch me add_money 1000
                                     The return value vil be stored in
                                     'arg' and can be viewed with 'List'
                                     if it is not zero.
 light       none or integer         Turns the staff in to a possitive or
 				     negative light source.
 rem         [object]                Remembers object.
 I           none or [object]        Gives inventory of object.
 trace       [object]                Traces an object.
 Goin        [object]                Moves yourself into [object]
 Look        none or [object]        Enhanced look.
 Move        [object] into [object]  
 Clone       [path]                  Silent clone.
 Trans       [object]                Silent trans.
 Destruct    [object]                Silent destruct.
 clean       [object]                Destroys all objects in [object],
                                     except souls, staffs and players.
 fs          <filename>              Show the size of a file
 change      'short'|'long'|'id'     Magicaly change the staff.
 exec        LPC-code                this function can execute LPC-
                                     code from the command line.
                                     Ex: exec write("Thanx for using exec\n");
 execw       <arg>                   Analogous to:
                                        exec write(<arg>);write("\n");
 command     [object] [action]       May the force be with you.
 creator     [object]                show the creator of [object]
 fwho                                Works like who.
 ipwho       [name|number]           Shows all players with 'related' ip-numbers
 info                                Make the staff less curious about
                                     other objects 'looks' :)
 uc          [filename]              update and clone
 ul          [filename]              update and load
 ug          [filename]              update and goto
Syntax
------------------------------------------------------------------
An [object] can be many things; It can be a location (= room/pub2),
a player (= fizzy), an item (sword) and some other special things.
Special objects are : 

          rem (the remembered object)
          old (the old remembered object)
          me  (Your self)
          env (the environemnt of an object)
          arg (the return value from the last patched object's function)
          'number'

-you can combine these arguments to point to a uniqe object by seperating
them with kommas.

And now some examples :

Ex1.
 1. If you want to Trans Fizzy you can do it this way
          Trans fizzy  (trans fizzy to our own location)
    here 'fizzy' is the object.

 2. You could also have done it this way
          Trans fizzy,env,fizzy 
                                
 3. Or this way
          rem fizzy        (remember fizzy)
          Trans rem

Ex2.
 1. Now you might like to turn fizzy invisible. That could be done this way :
          patch fizzy invis

 2. Or this way
          rem fizzy        (remember fizzy)
          patch rem invis

   Try to do a 'List' and see what remembered objects you have.

   If you want to turn him visible again you can do this :
          patch rem vis

Remark  : vis() and invis() are functions defined in obj/player.c .

Ex3.
 You can also remember the room fizzy is in by doing this :
          rem fizzy,env
 if fizzy was in the church then the church would be the new
 remembered object.

Ex4.
 1. If you want Fizzy's soul do :
          Get fizzy,soul
    or:
          rem fizzy
          Get rem,soul
    or :
          rem fizzy,soul
          Get rem

 2. Get the bottle he has in his bag
          Get fizzy,bag,bottle

Ex5.
    Try to do the 'Look' command.
    You will then get a numbered list of objects in the room.

    If you wanted object number 2 you could do :
             Get 2

Ex.6
    Try to see what fizzy is carrying :
             I fizzy
    You will then get a numbered list of objects in Fizzy.

    You could also get Fizzy's object number 0 by doing :
             Get fizzy,0

Experimant a little on your own. If you have any questions regarding the staff
or ideas of how to improve it do mail me (Fizban).

With Regards to All
               /Fizban

