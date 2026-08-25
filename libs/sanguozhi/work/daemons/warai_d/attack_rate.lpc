// attack_rate.c by fire on Nov 1998
// this is used to define the attack rate
// for different type of soilder
int get_soldier_attack_rate(string p_type)
{       switch (p_type)
        {       
		case "infantry": return 5;
                case "cavalry" : return 7;
                case "bowman"  : return 3;
                case "commando"  : return 3;
		case "footman" : return 5;
                default: return 0;
        }
}
int get_array_attack_rate(mixed type)
{
	if((!type)||(type=="bowman"))
		return 5; // it is very powerful 
	return 0;
}
int get_horse_attack_rate(mixed type)
{
	if((!type)||(type=="cavalry"))
		return 12; // a real powerful horse attack
	return 0;
}
string get_soldier_name(string p_type)
{
        switch (p_type)
        {
                case "infantry": return "%^H_RED%^步兵";
                case "cavalry" : return "%^H_GREEN%^骑兵";
                case "bowman"  : return "%^H_BLUE%^弓兵";
                case "commando"  : return "%^H_CYAN%^民兵";
		case "footman"  : return "%^H_CYAN%^新兵";
                default: return "%^H_YELLOW%^未知";
        }
                
}               
mixed get_soldier(string p_type,string p_what)
{
        switch(p_what)
        {
              case "name":
                        return get_soldier_name(p_type)+"%^RESET%^";
              case "attack_rate":
                        return get_soldier_attack_rate(p_type);
        }
        return 0;
}

// 兵种进攻能力
int get_bz_attack_rate(string bz,string type)
{
	switch(type) {
	case "siege":
	case "general":
		return get_soldier_attack_rate(bz);
	case "array":
		return get_array_attack_rate(bz);
	case "horse":
		return get_horse_attack_rate(bz);
	}
	return 0;
}
// 兵种防御能力
int get_bz_defence_rate(string bz,string type)
{
	switch(type) {
	case "siege":
	case "general":
		switch(bz) {
            case "infantry": return 5;
            case "cavalry" : return 6;
            case "bowman"  : return 3;
            case "commando"  : return 4;
	    case "footman"  : return 5;
		}
		break;
	case "array":
		switch(bz) {
            case "infantry": return 5;
            case "cavalry" : return 4;
            case "bowman"  : return 5;
            case "commando"  : return 4;
	    case "footman"  : return 5;
		}
		break;
	case "horse":
		switch(bz) {
            case "infantry": return 5;
            case "cavalry" : return 5;
            case "bowman"  : return 3;
            case "commando"  : return 4;
            case "footman"  : return 5;
  		}
		break;
	}
	return 5; // incase divide by zero
}
