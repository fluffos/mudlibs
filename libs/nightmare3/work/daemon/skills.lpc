//	/adm/daemon/skills_d.c
//	from the Nightmare mudlib
//	contains code that would be very memory wasteful if in the user object
//	created by Descartes of Borg 14 february 1993

mapping init_skills(string cl) {
    mapping skills;
    if(!skills) skills = ([]);
    if(!cl) {
	skills["melee"] = ([ "level": 1, "points": 0, "max": 1 ]);
	skills["attack"] = ([ "level":0, "points":0, "max":0 ]);
	skills["defense"] = ([]);
 	skills["double wielding"] = ([]);
	skills["knife"] = ([]);
	skills["blunt"] = ([]);
	skills["projectile"] = ([]);
	skills["blade"] = ([]);
	skills["two handed"] = ([]);
	skills["murder"] = ([]);
	skills["stealing"] = ([]);
	skills["bargaining"] = ([]);
	skills["locks"] = ([]);
	skills["magic defense"] = ([]);
	skills["magic attack"] = ([]);
	skills["healing"] = ([]);
	skills["faith"] = ([]);
	skills["conjuring"] = ([]);
    }
    else {
	switch(cl) {
	    case "fighter":
		skills["melee"] = ([ "level": 1, "points": 0, "max": 100 ]);
		skills["attack"] = ([ "level": 5, "points": 0, "max": 100]);
	  	skills["defense"] = ([ "level": 2, "points":0, "max": 90 ]);
		skills["double wielding"] = (["level": 0, "points":0, "max":100]);
		skills["knife"] = ([ "level": 1, "points":0, "max":70 ]);
		skills["blunt"] = (["level": 1, "points":0, "max": 75 ]);
		skills["projectile"] = (["level":0, "points":0, "max": 60 ]);
		skills["blade"] = (["level":10, "points":0, "max":100 ]);
		skills["two handed"] = (["level":1, "points":0, "max":100 ]);
		skills["murder"] = (["level":0, "points":0, "max": 10 ]);
		skills["stealing"] = (["level":0, "points":0, "max": 10 ]);
		skills["bargaining"] = (["level":1, "points":0, "max":100 ]);
		skills["locks"] = (["level":0, "points":0, "max":5 ]);
                skills["stealth"] = ([ "level":0, "points":0, "max":10 ]);
		skills["magic defense"] = (["level":0, "points":0, "max":0 ]);
		skills["magic attack"] = (["level":0, "points":0, "max":0 ]);
		skills["healing"] = (["level":0, "points":0, "max":0 ]);
		skills["faith"] = (["level":0, "points":0, "max":0 ]);
		skills["conjuring"] = (["level":0, "points":0, "max":0 ]);
		break;
            case "kataan":
                skills["melee"] = (["level":2, "points":0, "max":50]);
                skills["attack"]= (["level":1, "points":0, "max":75]);
                skills["defense"]= (["level":1, "points":0, "max":40]);
                skills["double wielding"]=(["level":5, "points":0, "max":80]);
                skills["knife"]=(["level":0, "points":0, "max":40]);
                skills["blunt"]=(["level":0, "points":0, "max":100]);
                skills["blade"]=(["level":1, "points":0, "max":60]);
                skills["two handed"]=(["level":1, "points":0, "max":100]);
                skills["projectile"]=(["level":5, "points":0, "max":110]);
                skills["bargaining"]=(["level":1, "points":0, "max":50]);
                skills["stealth"]=(["level":1, "points":0, "max":67]);
                skills["stealing"]=(["level":0, "points":0, "max":5]);
                skills["locks"]=(["level":10, "points":0, "max":83]);
                skills["murder"]=(["level":1, "points":0, "max":100]);
                skills["magic attack"]=(["level":3, "points":0, "max":50]);
                skills["faith"]=(["level":5, "points":0, "max":110]);
                skills["healing"]=(["level":2, "points":0, "max":50]);
                skills["magic defense"]=(["level":0, "points":0, "max":0]);
                skills["conjuring"]=(["level":1, "points":0, "max":32]);
                break;
	    case "rogue":
		skills["melee"] = (["level": 1, "points":0, "max": 100 ]);
		skills["attack"] = (["level": 1, "points":0, "max": 100 ]);
		skills["defense"] = (["level":5, "points":0, "max":100 ]);
		skills["double wielding"] = (["level":0, "points":0, "max":10 ]);
		skills["knife"] = (["level":10, "points":0, "max": 100 ]);
		skills["blunt"] = (["level":2, "points":0, "max":100 ]);
		skills["projectile"] = (["level":7, "points":0, "max":100]);
		skills["blade"] = (["level":0, "points":0, "max": 40]);
		skills["two handed"] = (["level":0, "points":0, "max":75 ]);
		skills["murder"] = (["level":3, "points":0, "max":100 ]);
                skills["stealth"] = (["level":10, "points":0, "max":100 ]);
		skills["stealing"] = (["level":7, "points":0, "max":100 ]);
		skills["bargaining"] = (["level":10, "points":0, "max":100 ]);
		skills["locks"] = (["level":10, "points":0, "max":100 ]);
		skills["magic defense"] = ([ "level": 0, "points":0, "max":0 ]);
		skills["magic attack"] = (["level":0, "points":0, "max":0 ]);
		skills["healing"] = (["level":0, "points":0, "max":0 ]);
		skills["faith"] = (["level":0, "points":0, "max":0 ]);
		skills["conjuring"] = (["level":0, "points":0, "max":0 ]);
		break;
	    case "mage":
		skills["melee"] = (["level":1, "points":0, "max":50 ]);
		skills["attack"] = (["level":0, "points":0, "max": 30 ]);
		skills["defense"] = (["level":1, "points":0, "max":60 ]);
		skills["double wielding"] = (["level":0, "points":0, "max":10 ]);
		skills["knife"] = (["level":1, "points":0, "max":50 ]);
	 	skills["blunt"] = (["level":5, "points":0, "max":90 ]);
		skills["projectile"] = (["level":0, "points":0, "max":53 ]);
		skills["blade"] = (["level":0, "points":0, "max":20 ]);
		skills["two handed"] = (["level":0, "points":0, "max":17 ]);
		skills["murder"] = (["level":0, "points":0, "max":5 ]);
		skills["stealing"] = (["level":0, "points":0, "max":5 ]);
		skills["bargaining"] = (["level":1, "points":0, "max":79 ]);
		skills["locks"] = (["level":0, "points":0, "max":28 ]);
		skills["magic defense"] = (["level" :1, "points":0, "max":61 ]);
		skills["magic attack"] = (["level": 10, "points": 0, "max":100 ]);
		skills["healing"] = (["level":0, "points":0, "max":20 ]);
		skills["faith"] = (["level":0, "points":0, "max":0 ]);
		skills["conjuring"] = (["level":7, "points":0, "max":100 ]);
		break;
	    case "monk":
		skills["melee"] = (["level":10, "points":0, "max":100 ]);
		skills["attack"] = (["level":1, "points":0, "max":70 ]);
		skills["defense"] = (["level":10, "points":0, "max":100]);
		skills["double wielding"] = (["level":0, "points":0, "max":0 ]);
		skills["knife"] = (["level":0, "points":0, "max":30 ]);
		skills["blunt"] = (["level":3, "points":0, "max": 95 ]);
		skills["projectile"] = (["level":7, "points":0, "max":100 ]);
		skills["blade"] = (["level":0, "points":0, "max":3 ]);
		skills["two handed"] = (["level":0, "points":0, "max":0 ]);
		skills["murder"] = (["level":0, "points":0, "max":0 ]);
		skills["stealing"] = (["level":0, "points":0, "max":0 ]);
		skills["bargaining"] = (["level":0, "points":0, "max": 55 ]);
		skills["locks"] = (["level":0, "points":0, "max":0 ]);
		skills["magic defense"] = (["level":3, "points":0, "max":100 ]);
		skills["magic attack"] = (["level":1, "points":0, "max": 25 ]);
		skills["healing"] = (["level":0, "points":0, "max": 37 ]);
		skills["faith"] = (["level":7, "points":0, "max":100 ]);
		skills["conjuring"] = (["level":0, "points":0, "max": 15 ]);
		break;
	    case "cleric":
		skills["melee"] = ([ "level": 1, "points":0, "max": 50 ]);
		skills["attack"] = ([ "level":0, "points":0, "max": 10 ]);
		skills["defense"] = ([ "level":1, "points":0, "max":20 ]);
		skills["double wielding"] = (["level":0, "points":0, "max": 1 ]);
		skills["knife"] = ([ "level":5, "points":0, "max": 90 ]);
		skills["blunt"] = ([ "level":1, "points":0, "max":70 ]);
		skills["projectile"] = (["level":0, "points":0, "max": 20]);
		skills["blade"] = (["level":0, "points":0, "max":15 ]);
		skills["two handed"] = (["level":0, "points":0, "max":1 ]);
		skills["murder"] = ([ "level":0, "points":0, "max":0 ]);
		skills["stealing"] = ([ "level":0, "points":0, "max":0 ]);
		skills["locks"] = (["level":0, "points":0, "max":0 ]);
		skills["bargaining"] = ([ "level":0, "points":0, "max": 55 ]);
		skills["magic defense"] = ([ "level":0, "points":0, "max": 80 ]);
		skills["magic attack"] = ([ "level":0, "points":0, "max": 7 ]);
		skills["healing"] = ([ "level":10, "points":0, "max":100 ]);
		skills["faith"] = (["level":5, "points":0, "max":90 ]);
		skills["conjuring"] = ([ "level":0, "points":0, "max":22 ]);
		break;
	    case "child": init_skills(0);
		break;
	    default: init_skills(0);
	}
    }
    return skills;
}

int training_formula(string cl, int lvl, string skill) {
    if(cl == "fighter") {
	switch(skill) {
	    case "melee": case "attack": case "defense": case "double wielding":
	    case "two handed": case "blade":
		return lvl * lvl; break;
            case "knife": case "blunt": case "projectile":
              return (lvl * lvl * lvl)/2; break;
            case "bargaining": case "murder":
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

