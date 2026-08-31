/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
inherit M_GETTABLE;

string *signers = ({"Gerald Green"});
int max_signers = 3;

void setup()
{
   add_adj("colourful");
   set_id("birthday card", "card", "birthday_card_quest");
   set_long(
       "A very colourful birthday card saying:\n\n"
       "   \"Wishing a doctor with a prescription for laughter a side-splittingly Happy Birthday!\n    May your day be "
       "filled with hilarious anecdotes, laughter-induced 'stitches,'\n    and an EPIC PARTY!\".\n\n");
}

string get_extra_long()
{
   return "The card has been signed below by " + format_list(signers) + ". That is " + sizeof(signers) + " " +
          (sizeof(signers) == 1 ? "person" : "people") + " in total.";
}

void add_signer(string s)
{
   signers += ({s});
}

int signed_by(string w)
{
   return member_array(w, signers) != -1;
}

int completed()
{
   return sizeof(signers) >= max_signers;
}

int missing()
{
   return max_signers - sizeof(signers);
}

string query_hint()
{
   return "Look at the card to see how many have signed it and compare this to your list of people who should.";
}