/* include for finding opposite stat/resistance and matching colors for stat/resistance */

/* will choose a random stat for you */

string query_random_stat()
{
    string *types;

    types = ({"str","dex","int","con","wis","cha",});
    return types[random(sizeof(types))];  
}

string query_random_resistance()
{
    string *types = ({"fire","cold","air","magical","acid",
      "poison","psionic","stone","electrical","mirror"});
    return types[random(sizeof(types))];
}

string query_opposite(string opposite)
{
    switch(opposite)
    {
    case "fire":
	return "cold";
	break;
    case "cold":
	return "fire";
	break;
    case "acid":
	return "electrical";
	break;
    case "electrical":
	return "acid";
	break;
    case "stone":
	return "air";
	break;
    case "air":
	return "stone";
	break;
    case "poison":
	return "psionic";
	break;
    case "psionic":
	return "poison";
	break;
    case "magical":
	return "mirror";
	break;
    case "mirror":
	return "magical";
	break;
    case "str":
	return "cha";
	break;
    case "cha":
	return "str";
	break;
    case "con":
	return "wis";
	break;
    case "wis":
	return "con";
	break;
    case "int":
	return "dex";
	break;
    case "dex":
	return "int";
	break;
    case "damage":
	return "tohit";
	break;
    default:
	return "none";
    }
}

string match_color_to(string str)
{
    switch(str)
    {
    case "air":
	return "lavendar";
	break;
    case "cold":
	return "cobalt blue";
	break;
    case "magical":
	return "silver";
	break;
    case "electrical":
	return "magenta";
	break;
    case "acid":
	return "yellow";
	break;
    case "poison":
    case "con":
	return "green";
	break;
    case "stone":
	return "grey";
	break;
    case "mirror":
	return "quicksilver";
	break;
    case "fire":
	return "vermillion";
	break;
    case "str":
	return "purple";
	break;
    case "dex":
	return "red";
	break;
    case "int":
	return "brown";
	break;
    case "psionic":
	return "light gray";
	break;

    case "wis":
	return "orange";
	break;
    case "cha":
	return "golden";
	break;
    case "tohit":
	return "maroon";
	break;
    case "damage":
	return "crimson";
	break;
    default:
	return "none";
	break;
    }
}
