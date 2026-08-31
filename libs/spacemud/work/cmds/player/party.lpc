/* Do not remove the headers from this file! see /USAGE for more info. */

// party.c - Command to start up the party menu. Checks to see
//           if the player is currently in a party, and if not
//           prompts to see if the player wants to create a new
//           one. If the answer is no, the cmd quits without
//           creating a menu object.
// March 1, 1997: Iizuka@Lima Bean created.
// August 15, 1999: Iizuka@Lima Bean ripped out all of the modal code
//                  and moved it to PARTY_MENU.
// October, 2020: Tsath changed all references to 'team' to 'party' since
//                this is now the common lanaguage used for this functionality
//                in other online games.

//: PLAYERCOMMAND
// USAGE
//    ``party``
//    ``party accept`` - if you got an invite
//
// Starts up the "party" menu system.
//
// .. TAGS: RST

inherit M_INPUT;
inherit CMD;

void main(string arg)
{
   new (PARTY_MENU)->join_party(arg);
}