/* Do not remove the headers from this file! see /USAGE for more info. */

//: PLAYERCOMMAND
//$$ see: inventory, score, equip
// USAGE
//   ``money``
//
// Displays how much money you are carrying. Short form of the ``score`` command.
//
// .. TAGS: RST

inherit CMD;

private
void main()
{
   write("You have the following types of money:\n\t" +
         implode(explode(MONEY_D->money_string(this_body()), "\n"), "\n\t"));
}