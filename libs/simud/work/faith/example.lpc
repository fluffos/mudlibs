string on_prayer(string subject)
{
	switch(subject) {
	case "list":
		return "I can grant prayers for: alignment.";

	case "alignment":
		{
			return "Your alignment is "
				+ this_player()->query_good_alignment()
				+ " by "
				+ this_player()->query_lawful_alignment();
		}
		break;

	default:
		return "I don't grant prayers for that.";
	}
}

string on_offer(object obj)
{
	return 0;
}
