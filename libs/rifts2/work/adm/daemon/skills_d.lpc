//	/adm/daemon/skills_d.c
//	from the Nightmare mudlib
//	contains code that would be very memory wasteful if in the user object
//	created by Descartes of Borg 14 february 1993

int training_formula(string cl, int lvl, string skill) {
    if(cl == "fighter") {
	switch(skill) {
	    case "melee": case "attack": case "defense": case "double wielding":
	    case "two handed": case "blade":
		return lvl * lvl; break;
	    case "knife": case "blunt": case "bargaining": case "murder":
	    case "stealing":
	  	return lvl * lvl * lvl; break;
	    default: return lvl * lvl * lvl * lvl; break;
	}
    }
    else if(cl == "cleric") {
	switch(skill) {
	    case "magic defense": case "healing": case "faith":
		return lvl * lvl; break;
	    case "melee": case "defense": case "knife": case "blunt":
            case "conjuring":
		return lvl * lvl * lvl; break;
	    default: return lvl * lvl * lvl * lvl; break;
	}
    }
    else if(cl == "mage") {
	switch(skill) {
	    case "magic attack": case "magic defense": case "conjuring": case "blunt":
		return lvl * lvl; break;
	    case "projectile": case "melee": case "attack": case "knife":
	    case "bargaining":
		return lvl * lvl * lvl; break;
	    default: return lvl * lvl * lvl * lvl; break;
	}
    }
    else if(cl == "kataan") {
        switch(skill) {
            case "projectile": case "stealth": case "attack": case "faith":
              return lvl * lvl; break;
            case "two handed": case "double wielding": case "murder":
            case "locks": case "magic attack":
              return lvl * lvl * lvl; break;
            default: return lvl * lvl * lvl * lvl; break;
        }
    }
    else if(cl == "monk") {
	switch(skill) {
	    case "melee": case "defense": case "blunt": case "projectile":
	    case "bargaining": case "magic defense": case "faith":
		return lvl * lvl; break;
	    case "knife": case "attack": case "conjuring":
		return lvl * lvl * lvl; break;
	    default: return lvl * lvl * lvl * lvl; break;
	}
    }
    else {
	switch(skill) {
	    case "stealth": case "melee": case "attack": case "defense": case "knife":
	    case "bargaining": case "murder": case "stealing": case "locks":
	        return lvl * lvl; break;
	    case "blunt": case "projectile": case "double wielding":
		return lvl * lvl * lvl; break;
	    default: return lvl * lvl * lvl * lvl; break;
	}
    }
}

int query_melee_ac(string cl) {
    switch(cl) {
	case "fighter": return 15; break;
	case "monk": return 20; break;
        case "kataan": return 11; break;
	case "rogue": return 20; break;
	case "cleric": return 5; break;
	case "mage": return 8; break;
	default: return 1;
    }
}

