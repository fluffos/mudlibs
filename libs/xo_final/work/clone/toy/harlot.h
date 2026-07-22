// harlot.h writen by tea 12.11.98

void welcome_visitor()
{
    object me=this_player();
        switch(random(4))
    {
        case 0:
            command(chat_emote[random(sizeof(chat_emote))]);
            break;
        case 1:
            if( me->query("gender") == "女性" )
            {
                command("interest " +me->query("id"));
                command("snicker");
            }
            break;
        case 2:
            command("say " + this_player()->name() + "快做报告！我要饿死啦！！");
            break;
        case 3:
            command("say "+chat_msg[random(sizeof(chat_msg))]);
            break;
    }
}

/*int refuse_killing(object me)
{
    object guard, this=this_object();
    int i=random(3)+1;

    message_vision("$N大叫道：“"+RANK_D->query_respect(me)+"饶命呀！”\n", this);
    this->set("env/wimpy",100);

    guard=new( __DIR__"dashou"+(string)i );
    guard->move( environment() );
    guard->set_leader( me );
    guard->kill_ob(me);
    me->kill_ob(guard);
    return 0;
}*/

void relay_whisper( object me, string msg )
{
    command("xixi "+me->query("id") );
}

void give_cake( object ppl )
{
	object cake;
	if ( !cake = present( "Mooncake", this_object() ) )
	{
		cake = new ("/clone/toy/mooncake");
		cake->move(this_object());
	}
	if ( ! ppl->can_afford( cake->query("value") ) )
	{
		command("say 嘻嘻，这么穷，不给不给。");
		return;
	}
	ppl->pay_money( cake->query("value") );
	command("noeat " +ppl->query("id"));
	command("give Mooncake to " + ppl->query("id"));
}

void relay_emote( object me, string verb )
{
    string player_id,harlot_id;
    player_id=me->query("id");
    harlot_id=this_object()->query("id");
    
    switch(verb)
    {
    case "clasp": case "hug": case "kiss": case "touch1": case "dance":
        command("shy "+harlot_id);
        break;
    case "blush": case "flook": case "lov": case "loveshoe": case "loveu":
    case "idiot": case "joyce": case "sing1": case "whylook":
        command("blush");
        break;
    case "lean": case "love": case "loveu":
        command("love "+harlot_id);
        break;
    case "smile": case "flower": case "smirk": case "swallow": case "wink":
        command("smile "+player_id);
        break;
    case "curtain": case "lovebite":
        command("pain");
    case ":P": case "agree": case "applaud": case "dream": case "duanyi": 
    case "faint": case "handshake": case "nod": case "play": case "prettyme": 
    case "shrug": case "sorry": case "thank":
        command("xixi");
        break;
    case ":(": case "altruism": case "cry": case "cry1": case "sob": 
        command("comfort "+player_id);
        break;
    case "benger": case "confused": case "crazy": case "die": case "fear": 
    case "fear1": case "girl": case "hammer": case "papaya": case "qfight": 
    case "shuai": case "shy": case "trip":
        command("qifu "+player_id);
        break;
    case "addoil": case "eatdrink": case "forget": case "nokill": case "patient": 
    case "west1": case "west2":
        command("ok");
        break;
    case "admire": case "admire1": case "bigman": case "humble": case "longtime": 
    case "wait":
        if( random(2) )
            command("same");
        else
            command("same "+player_id);
        break;
    case "ah": case "hi1": case "interest": case "missyou": case "qing": 
        command("nod "+player_id);
        break;
    case "amber": case "robot":
        command("agree");
        break;
    case "angry": case "bigmouth": case "bored": case "girl1": case "hate2": 
    case "lust": case "qifu":
        command("inn");
        break;
    case "callname": case "grin2": case "point": case "rumor":
        command("innocent");
        break;
    case "baobei": case "dunno": case "rule":
        command("puke "+player_id);
        break;
    case "idle": case "pretty1": case "wyuh":
        command("faint "+player_id);
        break;
    case "birthday": case "comfort": case "comfort1": case "comfort2":
    case "weather":
        command("thank "+player_id);
        break;
    case "blade": case "consider": case "escape": case "hate1":
        command("escape");
        break;
    case "bow": case "lure": case "visit":
        command("humble");
        break;
    case "brag": case "bro": case "jinger": case "sing":  case "swear":
        command("lean "+player_id);
        break;
    case "beep": case "cammay": case "greet": case "jojo": case "snow": 
        command("say 我一直在这儿呀！");
        break;
    case "congra": case "foll": case "lnwm": case "qmarry":
		command("shy " + query("id"));
    case "fault": case "pothead":
        command("sigh");
        break;
    case "lemon": case "foll":
        command("say 好多呦~~~~~~~~~~~~~~~~~~~~~~~~~~");
        break;
    case "bye": case "byebye": case "goeat": case "wave":
        command("snow "+player_id);
        break;
    case "candy": case "inn": case "innocent": case "joke":
        command("sorry "+player_id);
        break;
    case "cat": case "fool": case "fun": case "jump": case "shiver": 
    case "touch": case "wa":
        command("pat "+player_id);
        break;
    case "date": case "dinner":
        command("wa "+player_id);
        break;
    case "deadlove": case "waiting":
        command("touch "+player_id);
        break;
    case "dayu": case "laugh": case "pig": case "rich": case "slap": 
    case "ugly":
        command("slap "+player_id);
        command("heng "+player_id);
        break;
    case "disapp":
        command("cry "+player_id);
        break;
    case "divorce": case "duh": case "dxyun": case "flat": case "heng": 
    case "lazy": case "norose": case "shout":
        command("poor "+harlot_id);
        break;
    case "haha": case "goaway": case "hang": case "laugh1": case "leave_alone": 
    case "nip": case "noescape": case "zap": case "zisha":
        command("poor");
        break;
    case "help!": case "lag": case "lag2":
        command("poor "+player_id);
        break;
    case "face": case "falcon": case "leonhart": case "pain": 
        command("face "+player_id);
        break;
    case "farewell":
        command("fear "+player_id);
        break;
    case "hero": case "life":
        command("shake "+player_id);
        break;
    case "puke": case "lingshan": case "same": case "scowl":
        command("crazy "+player_id);
        break;
    case "hit": case "kick": case "poor":
        command("cry1");
        break;
    case "mm": case "sister":
        command("sister "+player_id);
        break;
    case "no": case "no1": case "noeat": case "snicker": case "tap": 
    case "tender":
        command("pure "+player_id);
        break;
    case "language1": case "nolove": case "ok": case "pout": case "raise":
    case "sing2": case "ya":
        command("dunno "+player_id);
        break;
    case "hi": case "poke": case "xixi":
        command("hi "+player_id);
        break;
    case "hehe": case "peace": case "shutup!": case "sneer":
        if( random(2) )
            command("fear");
        else
            command("fear1");
        break;
    case "forehead": case "pat": case "trill": case "waggle": case "yaolan":
        command("forehead "+harlot_id);
        break;
    case "regard": case "snowball":
        command(verb+" "+harlot_id);
        break;
    case "sshy": case "wake": case "drinkcup":
        command(verb);
        break;
    case "taste":
        command("taste "+harlot_id);
        command("taste");
        command("smirk");
        break;
    case "xyao": case "baogao": case "help": case "candy":
		give_cake(this_player());
		break;
    default :
		break;
    }
}
