int main ()
{
	mixed a;
	string *slots;
	int i;
	
	slots = THIS->query_armour_slot_names();
	a = THIS->query_armour_slots();
	for (i = 0; i < sizeof(slots); i++)
	{
		if (a[i][5] != 0)
			slots[i] = "^cL" + slots[i] + "^c0";
		else
			slots[i] = "^c0" + slots[i] + "^c0";
	}

	message("0", sprintf("%#-78s\n", implode(slots, "\n")), THIS);
    return 1;
}

query_author()
{
  return"namhas";
}

query_help()
{
  return "Shows all the different slots you can wear an equipment on.";
}
query_position()
{
  return POS_RESTING;
}

