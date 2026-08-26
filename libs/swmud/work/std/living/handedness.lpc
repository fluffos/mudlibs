// Last edited by deforce on 03-22-2010
string dominant_hand = "right";

//:FUNCTION set_dominant_hand
// Right or left, default is right
void set_dominant_hand(string hand)
{
   if (this_object()->is_body()) { this_object()->check_wizard_set("change " + this_object()->short() + "'s handedness from " + dominant_hand + " to " + hand, previous_object(-1)); }

   dominant_hand = (lower_case(hand) == "left" ? "left" : "right");
}

//:FUNCTION query_dominant_hand
// Returns "right" or "left"
string query_dominant_hand()
{
   return dominant_hand;
}

//:FUNCTION query_other_hand
// Returns "left" or "right"
string query_other_hand()
{
   return (dominant_hand == "right" ? "left" : "right");
}

//:FUNCTION is_right_handed
// Returns 1 for right handed and 0 for left handed
int is_right_handed()
{
   return (dominant_hand == "right" ? 1 : 0);
}