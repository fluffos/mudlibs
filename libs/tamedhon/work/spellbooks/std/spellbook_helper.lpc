/* Hilfsroutinen fuers Spellbook, damit sie nicht quer uebers Spellbook
 * verteilt sind.
 * Thu Mar  9 18:30:59 2000, Samtpfote
 */

#pragma strong_types

#include <properties.h>
#include <moving.h>
#include <combat.h>

object *get_livings(object container)
{
    object	*liv, *inv;
    int		i, isize;

    if(!container) return ({});
    
    liv=({});
    isize=sizeof(inv=all_inventory(container));
    if(isize)
    {
	for(i=0;i<isize;i++)
	{ if(living(inv[i])) liv+=({ inv[i] }); }
    }
    return liv;
}


varargs string liste(string *str, string pad) 
{
    if (!sizeof(str)) { return ""; }
    if (sizeof(str) == 1) { return str[0]; }
    return implode(str[0..<2], ", ")+(pad ? pad : " und " )+str[<1];
}


string map_dt(string dt)
{
    switch(dt)
    {
	case DT_SLASH:		return "schneidenden"; break;
	case DT_BLUDGEON:	return "schlagenden"; break;
        case DT_PIERCE:		return "stechenden"; break;
        case DT_SQUEEZE:	return "quetschenden"; break;
        case DT_WHIP:		return "peitschenden"; break;
        case DT_RIP:		return "reißenden"; break;
        case DT_FIRE:		return "brennenden"; break;
        case DT_COLD:		return "kalten"; break;
        case DT_WATER:		return "nassen"; break;
        case DT_AIR:		return "luftigen";
        case DT_LIGHTNING:	return "blitzenden"; break;
        case DT_EXPLOSION:	return "explodierenden"; break;
        case DT_SOUND:		return "lauten"; break;
        case DT_LIGHT:		return "lichtmachenden"; break;
        case DT_ACID:		return "säureartigen"; break;
        case DT_POISON:	        return "giftigen"; break;

        case DT_HOLY:		return "heiligen"; break;
        case DT_UNHOLY:  	return "unheiligen"; break;
        case DT_TERROR: 	return "angstmachenden"; break;
        case DT_MAGIC:		return "magischen"; break;
	default: return "unbekannten"; break;
    }	
    return "";
}


int check_dropable(object weapon)
{
    if(!weapon) return 0;
    if(!weapon->QueryProp(P_DAM_TYPE)) return 0;
    if(weapon->QueryProp(P_CURSED) || weapon->QueryProp(P_NODROP)) return 0;
    
    return 1;
}

varargs
void drop_weapon(object caster, string castermsg, string roommsg, int silent)
{
    object	room, wp;
    string	cmsg, rmsg;
    
    if(!caster) return;
    room=environment(caster);
    wp=caster->QueryProp(P_WEAPON);
    if(!silent) silent=1;
    if(!wp) return;
    if(!room) return;
    if(!castermsg)
    { 
	cmsg=sprintf("Dir entgleitet %s und lässt %s fallen.\n",
		     wp->name(), wp->QueryPronoun());
    }
    else cmsg=castermsg;
    if(!roommsg)
    { 
	rmsg=sprintf("%s entgleitet %s und lässt %s fallen.\n",
		     capitalize(caster->name()), wp->name(), 
		     wp->QueryPronoun());
    }
    else rmsg=castermsg;
    
    write(break_string(cmsg));
    say(break_string(rmsg), caster);
    
    if(check_dropable(wp))
    {
	wp->DoUnwield(silent);
	wp->move(room, M_PUT|M_SILENT|M_NOCHECK);
    }
    else
    {
	write("Irgendwie bleibt Dir die Waffe an den Händen kleben.\n");
	say(sprintf("%s kann sich wohl nicht von der Waffe "
		    "trennen...\n", capitalize(caster->name())), caster);
    }
}

varargs
void throw_weapon_room(object caster, 
		       string castermsg, string roommsg, string destmsg,
		       int silent)
		  
{
    object	room, wp, *lvs, lv, dest;
    string	cmsg, rmsg, dmsg, *exits, direction, roomfn;
    mapping	dirdata, m;

    if(!caster || !dest) return;
    if(!silent) silent=1;
    dest=environment(caster);
    wp=caster->QueryProp(P_WEAPON);
    if(!wp) return;
    
    /* erst mal die Richtung bestimmen */
    dirdata=dest->QueryProp(P_EXITS);
    exits=m_indices(dirdata);
    if(!sizeof(exits)) 
    {
	drop_weapon(caster, castermsg, roommsg, silent);
	return;
    }
    direction=exits[random(sizeof(exits))];
    /* auf special exit testen, und wenn ja --> waffe fallen lassen */
    
    if(!stringp(dirdata[direction]))
    {
	if(mappingp(dirdata[direction]))
	{
	    m=dirdata[direction];
	    if(!stringp(m[EX_DEST])) 
	    {
		drop_weapon(caster, castermsg, roommsg, silent);
		return;
	    }
	}
    }	    
    roomfn=dest->QueryProp(P_EXITS)[direction];
    call_other(roomfn, "???");
		
    if(!castermsg)
    {
	cmsg=sprintf("Du schleuderst %s mit voller Wucht nach %s.\n",
	             wp->name(WEN), capitalize(direction));
    }
    else cmsg=castermsg;
	
    if(!roommsg)
    {
        rmsg=sprintf("%s schleuderst %s mit voller Wucht nach %s.\n",
	             capitalize(caster->name()), wp->name(WEN), 
		     capitalize(direction));
    }
    else rmsg=roommsg;	

    /* so, jetzt mal das Rausfliegen machen */
    write(break_string(cmsg));
    say(break_string(rmsg), caster);

    if(!check_dropable(wp))
    {
        write("Irgendwie bleibt Dir die Waffe an den Fingern kleben.\n");
        say(sprintf("%s kann sich wohl nicht von der Waffe "+
                    "trennen...\n", capitalize(caster->name())), caster);
        return;
    }	
	
    if(!destmsg)
    {
	dmsg=sprintf("%s kommt plötzlich hereingeflogen.\n",
	             capitalize(wp->name()));
    }
    else dmsg=destmsg;
	
    /* im Raum drinnen selber das Reinfliegen */
    wp->DoUnwield(silent);
    tell_room(find_object(roomfn), break_string(dmsg));
    if(random(10) < 3)
    {
        lvs=get_livings(find_object(roomfn));
        if(sizeof(lvs))
        {
	    lv=lvs[random(sizeof(lvs))];
	    lv->reduce_hitpoints(random(wp->QueryProp(P_WC)));
	    if(lv->QueryProp(P_NPC)) { lv->InsertEnemy(caster); }
		
	    tell_object(lv, 
		sprintf("Du wirst dabei von %s getroffen.\n",
		        wp->name(WEN, 2)));
	    tell_room(find_object(roomfn),
	        sprintf("%s wird dabei von %s getroffen.\n",
		        wp->name(WEN, 2)), ({ lv }));
	    wp->move(lv, M_GET|M_SILENT|M_NOCHECK);			    
	}
	else
	{
	    wp->move(find_object(roomfn), M_PUT|M_NOCHECK);
	}
    }
    else /* bleibt liegen */
    {
	tell_room(find_object(roomfn),
		  sprintf("%s fällt dabei zu Boden.\n", 
			  capitalize(wp->name())));
	wp->move(find_object(roomfn), M_PUT|M_NOCHECK);
    }
}    

mapping get_enemy_material(object v)
{
    mapping	m;
    string	loc;
    object	gl;

    m=([]);
    if(!v) return m;
    
    switch(random(100))     
    {
	case 1..5:
	    loc=AT_HELMET; break;
	case 10..17:
	    loc=AT_TROUSERS; break;
	case 30..35:
	    loc=AT_BRACERS; break;
	case 70..71:
	    loc=AT_BELT; break;
	case 80..82:
	    loc=AT_GLOVE; break;
	default:
	    loc=AT_ARMOUR; break;
    }
    
    gl=(filter_objects(v->QueryProp(P_ARMOURS)||({}),"id",loc)+
       ({0}))[0];
    if(!objectp(gl))
    { m=v->QueryProp(P_MATERIAL); }
    else
    { m=gl->QueryProp(P_MATERIAL); }
    
    return m;
}

int enemy_contains_mat(object v, mapping mat)
{
    mapping	m;
    int		is, i;

    if(!v || (!sizeof(mat))) return 0;
    m=get_enemy_material(v);
    is=sizeof(mat);

    for(i=0; i<is; i++)
    {
	if(member(m, mat[i]) != -1) return 1;
    }

    return 0; 
}

varargs
string list_dt(mixed damtype, string *meta)
{
    string	*dt;
    mixed mt;
    int		i, is;
    string	*res;

//    DB(caster, sprintf("list_dt: %O", damtype));
    if(!sizeof(damtype)) return "";
    if(stringp(damtype)) 
    { dt=({ damtype }); }
    else
    { dt=({})+damtype; }
    if(!meta || !sizeof(meta)) 
    { mt=ALL_DAMAGE_TYPES; }
    else
    { mt=meta; }
    
    is=sizeof(dt); res=({});
    for(i=0; i<is; i++)
    {
	if(member(mt, dt[i]) != -1)
	{
	    res+=({ map_dt(dt[i]) });
	}	    
    }
    
    if(sizeof(res))
    { return liste(res); }
    else
    { return ""; }
}
