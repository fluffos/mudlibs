/*
** /room/smithy
**
** The smithy is a shop offering special services for repairing
** and resizing weapons and armour
**
** 03jan97 [a] Creation
**
** [a] Analena
*/

inherit "/std/shop";

#include <config.h>
#include <money.h>
#include <properties.h>
#include <rooms.h>
#include <skills.h>
#include <secure/wizlevels.h>

/* small 'hotfix'. Someone seems to have removed SK_REPAIR as
 * skill from skills.h, so i added it here to the file to have it
 * up and running again.
 * if you think, that this solution is not good enough, remove it and
 * do something better.
 */
#ifndef SK_REPAIR
#define SK_REPAIR "repair"
#endif
#define TP this_player()
#define TO this_object()
#define ENV environment()
#define Wrap(x) ({string})"/lib/string"->wrap(x)

#define SF(x) #'x //'
#define LSF(x) symbol_function(x,TO)

private nosave string Pverb_fix;
private nosave string Pverb_resize;
private nosave int Psmithy;
private nosave int Pno_shop;
private nosave int Prepair_factor;
private nosave int Presize_factor;
private nosave int Pmax_repair;
private nosave int Pmax_quality;
private nosave int Pweapon_decay;
private nosave int Parmour_decay;

int SetNoShop(int i)
{
    if (i)
        RemoveExit(({"store"}));
    else
        SetStore();
    return Pno_shop=i;
}

int QueryNoShop() { return Pno_shop; }

string SetFix(string verb) { return Pverb_fix=verb; }
string QueryFix() { return Pverb_fix; }

string SetResize(string verb) { return Pverb_resize=verb; }
string QueryResize() { return Pverb_resize; }

string QueryBuy()
{
    if(QueryNoShop())
        return 0;
    else
        return ::QueryBuy();
}

string QuerySell()
{
    if(QueryNoShop())
        return 0;
    else
        return ::QuerySell();
}

string QueryList()
{
    if(QueryNoShop())
        return 0;
    else
        return ::QueryList();
}

string QueryShow()
{
    if(QueryNoShop())
        return 0;
    else
        return ::QueryShow();
}

string QueryAppraise()
{
    if( QuerySell() || QueryFix() || QueryResize() )
        return ::QueryAppraise();
    else
        return 0;
}

int SetRepairFactor(int factor) { return Prepair_factor = factor; }
int QueryRepairFactor() { return Prepair_factor; }

int SetResizeFactor(int factor) { return Presize_factor = factor; }
int QueryResizeFactor() { return Presize_factor; }

int SetMaxRepair(int percent)
{
    if (percent > 100)
        percent = 100;
    if (percent < 1)
        percent = 1;
    return Pmax_repair = percent;
}

int QueryMaxRepair() { return Pmax_repair; }

int SetMaxQuality(int percent)
{
    if (percent > 100)
        percent = 100;
    if (percent < 0)
        percent = 0;
    return Pmax_quality = percent;
}

int QueryMaxQuality() { return Pmax_quality; }

int SetWeaponDecay(int decay) { return Pweapon_decay=decay; }
int QueryWeaponDecay() { return Pweapon_decay; }

int SetArmourDecay(int decay) { return Parmour_decay=decay; }
int QueryArmourDecay() { return Parmour_decay; }

int SetSmithy(int i)
{
    if (i)
        AddDetail(({"hammer","anvil"}),
            "A hammer lies on the anvil.\n");
    else
        RemoveDetail(({"hammer","anvil"}));
    return Psmithy=i;
}

int QuerySmithy() { return Psmithy; }

int IsSmithy() { return QuerySmithy(); }

int cmd_repair(string str)
{
    if( !QuerySmithy() )
        return 0;
    if( TP && ({int})TP->QueryAttr(SK_REPAIR,1) )
        return 0;
    if( str && QueryFix() && sk_in_shop() )
    {
        notify_fail(Wrap("The hammer is too heavy for you. Why "
            "don't you ask the smith to fix your stuff for "
            "you?\n"));
        return 0;
    }
    notify_fail(Wrap("The hammer is too heavy for you. You don't "
        "manage to repair anything.\n"));
    return 0;
}

varargs int GetRepairPrice(object ob,int force)
{
    mixed price;
    int percent,quality,max_quality;
    if (!ob)
        return 0;
    quality=({int})ob->QueryQuality();
    max_quality=QueryMaxQuality();
    if (max_quality==0)
        max_quality = (({int})ob->QueryResetQuality() || 100);
    if (!quality)
        return 0;
    if( (percent=max_quality-quality) > QueryMaxRepair() )
        percent=QueryMaxRepair();
    if (percent <= 0)
        return 0;
    price=({int})ob->QueryValue(1);
    price=(price*percent)/100;
    price=ModifyPrice(ob,price,"fix");
    price=(price*QueryRepairFactor())/100;
    if (force)
        price=2*price;
    if (price<=0)
        price=1;
    else
        price=(round_value(price)||1);
    return price;
}

varargs int GetResizePrice(object ob,int size,int force)
{
    mixed price;
    if (!ob)
        return 0;
    if (({int})ob->QuerySize()==PSIZE_GENERIC)
        return 0;
    if ((!size) || (({int})ob->QuerySize()==size))
        return 0;
    price=({int})ob->QueryValue(1);
    price=ModifyPrice(ob,price,"resize");
    price=(price*QueryResizeFactor())/100;
    if (force)
        price=2*price;
    if (price<=0)
        price=1;
    else
        price=(round_value(price)||1);
    return price;
}

int do_fix(string str)
{
    mixed pay_result;
    object ob;
    string dummy;
    int price,force,repair;

    if (!TP)
        return 0;
    Say(CustomerName(1)+" wants to have "+(str||"something")+" "+
        (QueryFix()||"fix")+"ed.\n",
        ({TP}),1);
    if (!sk_in_shop())
        return 0;
    if (!QueryFix())
    {
        notify_fail(lambda(0,
            ({SF(SkSay),"I don't fix any items.\n"})),NOTIFY_NOT_OBJ);
        return 0;
    }
    if (!str)
    {
        notify_fail(lambda(0,
            ({SF(SkSay),"What do you want to have "+QueryFix()+"ed?\n"})),
            NOTIFY_NOT_VALID);
        return 0;
    }
    if (sscanf(lower_case(str),"really %s",dummy)==1)
    {
        str=dummy;
        force=1;
    }
    if (!ob=present(str,TP))
    {
        notify_fail(lambda(0,
           ({SF(SkSay),"Sorry "+CustomerName(1)+", you have no item called '"
           +str+"'.\n"})),NOTIFY_NOT_VALID);
        return 0;
    }
    if((!CheckTrade(ob)) || (!CheckLivingTrade(ob)))
    {
        notify_fail(lambda(0,
           ({SF(SkSay),"Sorry "+CustomerName()+", but I can't "+QueryFix()+
           " "+({string})ob->Short()+".\n"})),NOTIFY_NOT_VALID);
        return 0;
    }
    if(({int})ob->QueryQuality()>=100)
    {
        notify_fail(lambda(0,
           ({SF(SkSay),capitalize(({string})ob->Short())+" is in perfect "
           "condition.\n"})),NOTIFY_NOT_VALID);
        return 0;
    }
    if(({int})ob->QueryQuality()<=0)
    {
        notify_fail(lambda(0,
           ({SF(SkSay),capitalize(({string})ob->Short())+" is damaged far "
           "beyond my ability to "+QueryFix()+" it.\n"})),NOTIFY_NOT_VALID);
        return 0;
    }
    if(({int})ob->QueryQuality()>=(QueryMaxQuality()||({int})ob->QueryResetQuality()))
    {
        notify_fail(lambda(0,
           ({SF(SkSay),"I'm sorry, but I can't "+QueryFix()+" "+
           ({string})ob->Short()+" any better.\n"})),NOTIFY_NOT_VALID);
        return 0;
    }
    price=GetRepairPrice(ob,force);
    if (force)
        pay_result=PayValue2(TP,price,m_indices(({mapping})MONEY_DEMON->
            QueryCoinTypes()));
    else
        pay_result=PayValue2(TP,price,QueryValuta());
    if (!pointerp(pay_result))
    {
        notify_fail(lambda(0,
            ({SF(SkSay),"It would cost "+({string})MONEY_DEMON->QueryMoneyString(
            ({mapping})MONEY_DEMON->CreateMoney(price,(force?m_indices(({mapping})MONEY_DEMON->
            QueryCoinTypes()):QueryValuta())))+" to have "+({string})ob->Short()+
            " "+QueryFix()+"ed, which you don't have.\n"})),
            NOTIFY_ILL_ARG);
        return 0;
    }
    SkEmote("does some work with "+({string})ob->Short()+".\n");
    repair=(QueryMaxQuality() || ({int})ob->QueryResetQuality())-({int})ob->QueryQuality();
    if (repair > QueryMaxRepair())
        repair = QueryMaxRepair();
    ob->SetQuality(({int})ob->QueryQuality()+repair);
    if (({int})ob->QueryWeaponType())
    {
        ob->Set(P_WP_PER_QP,({int})ob->Query(P_WP_PER_QP)+QueryWeaponDecay());
        if (({int})ob->Query(P_WP_PER_QP) < 1)
            ob->Set(P_WP_PER_QP,1);
    }
    if (({mixed})ob->QueryArmourType())
    {
        ob->Set(P_AP_PER_QP,({int})ob->Query(P_AP_PER_QP)+QueryArmourDecay());
        if (({int})ob->Query(P_AP_PER_QP) < 1)
            ob->Set(P_AP_PER_QP,1);
    }
    Write("You pay "+pay_result[0]+(pay_result[1]?" and get "+
        pay_result[1]+" back":"")+".\n");
    Say(CustomerName(1)+" pays "+pay_result[0]+(pay_result[1]?" and gets "+
        pay_result[1]+" back":"")+".\n",({TP}),1);
    return 1;
}

int do_resize(string str)
{
    mixed pay_result;
    object ob;
    string dummy;
    int size,price,force;

    if (!TP)
        return 0;
    Say(CustomerName(1)+" wants to have "+(str||"something")+" "+
        (QueryResize()||"resize")+"d.\n",
        ({TP}),1);
    if (!sk_in_shop())
        return 0;
    if (!QueryResize())
    {
        notify_fail(lambda(0,
            ({SF(SkSay),"I don't resize any items.\n"})),NOTIFY_NOT_OBJ);
        return 0;
    }
    if (!str)
    {
        notify_fail(lambda(0,
            ({SF(SkSay),"What do you want to have "+QueryResize()+"d?\n"})),
            NOTIFY_NOT_VALID);
        return 0;
    }
    if (sscanf(lower_case(str),"really %s",dummy)==1)
    {
        str=dummy;
        force=1;
    }
    if (sscanf(lower_case(str),"%s large",dummy)==1)
    {
        size=PSIZE_LARGE;
        str=dummy;
    }
    else
        if (sscanf(lower_case(str),"%s small",dummy)==1)
        {
            size=PSIZE_SMALL;
            str=dummy;
        }
    if (!ob=present(str,TP))
    {
        notify_fail(lambda(0,
           ({SF(SkSay),"Sorry "+CustomerName(1)+", you have no item called '"
           +str+"'.\n"})),NOTIFY_NOT_VALID);
        return 0;
    }
    if((!CheckTrade(ob)) || (!CheckLivingTrade(ob)))
    {
        notify_fail(lambda(0,
           ({SF(SkSay),"Sorry "+CustomerName()+", but I can't "+QueryResize()+
           " "+({string})ob->Short()+".\n"})),NOTIFY_NOT_VALID);
        return 0;
    }
    if(({int})ob->QuerySize()==PSIZE_GENERIC)
    {
        notify_fail(lambda(0,
           ({SF(SkSay),capitalize(({string})ob->Short())+" fits all sizes.\n"})),
           NOTIFY_NOT_VALID);
        return 0;
    }
    if(!size)
    {
        notify_fail(lambda(0,
            ({SF(SkSay),"Do you want me to "+QueryResize()+" "+
            ({string})ob->Short()+" to be smaller or larger?\n"})),
            NOTIFY_NOT_VALID);
        return 0;
    }
    if(({int})ob->QuerySize()==size)
    {
        notify_fail(lambda(0,
           ({SF(SkSay),capitalize(({string})ob->Short())+" is already as "+
           (size==PSIZE_SMALL?"small":"large")+" as possible.\n"})),
           NOTIFY_NOT_VALID);
        return 0;
    }
    price=GetResizePrice(ob,size,force);
    if (force)
        pay_result=PayValue2(TP,price,m_indices(({mapping})MONEY_DEMON->
            QueryCoinTypes()));
    else
        pay_result=PayValue2(TP,price,QueryValuta());
    if (!pointerp(pay_result))
    {
        notify_fail(lambda(0,
            ({SF(SkSay),"It would cost "+({string})MONEY_DEMON->QueryMoneyString(
            ({mapping})MONEY_DEMON->CreateMoney(price,(force?m_indices(({mapping})MONEY_DEMON->
            QueryCoinTypes()):QueryValuta())))+" to have "+({string})ob->Short()+
            " "+QueryResize()+"d, which you don't have.\n"})),
            NOTIFY_ILL_ARG);
        return 0;
    }
    SkEmote("does some work with "+({string})ob->Short()+".\n");
    if(size==PSIZE_SMALL)
        ob->SetSize(({int})ob->QuerySize()-1);
    else
        ob->SetSize(({int})ob->QuerySize()+1);
    Write("You pay "+pay_result[0]+(pay_result[1]?" and get "+
        pay_result[1]+" back":"")+".\n");
    Say(CustomerName(1)+" pays "+pay_result[0]+(pay_result[1]?" and gets "+
        pay_result[1]+" back":"")+".\n",({TP}),1);
    return 1;
}

int do_appraise(string str)
{
    object ob;
    int price,maxprice;
    int repairprice,resizeprice;
    string text;

    Say(CustomerName(1)+" asks "+(SkShort()||"someone")+" to "+
        (QueryAppraise()||"appraise")+" "+(str||"something")+".\n",({TP}));
    if (!sk_in_shop())
        return 0;
    if (!QueryAppraise())
    {
        notify_fail(lambda(0,
            ({SF(SkSay),"You can't appraise things here.\n"})),
            NOTIFY_NOT_OBJ);
        return 0;
    }
    if(!str)
    {
        notify_fail(lambda(0,
            ({SF(SkSay),"What shall I "+QueryAppraise()+"?\n"})),
            NOTIFY_NOT_VALID);
        return 0;
    }
    if(!ob = present(str, TP))
    {
        notify_fail(lambda(0,
           ({SF(SkSay),"Sorry "+CustomerName()+", you have no item called '"
           +str+"'.\n"})),NOTIFY_NOT_VALID);
        return 0;
    }
    if(blueprint(ob) == "/obj/money")
    {
        notify_fail(lambda(0,
            ({SF(SkSay),"Sorry "+CustomerName()+", if you want to deal with "
            "money you must go to the bank.\n"})),NOTIFY_NOT_VALID);
        return 0;
    }
    price = (price = GetPrice(ob))>(maxprice = GetMaxPrice(ob))
        ?maxprice:price;
    if((!CheckTrade(ob)) || (!CheckLivingTrade(ob)))
    {
        SkSay("I'd guess that "+({string})ob->Short()+" is worth about "+
            ({string})MONEY_DEMON->QueryValueString(price,QueryValuta())+
            " but I can't say for sure since I don't trade with "
            "such items.\n");
        return 1;
    }
    repairprice = GetRepairPrice(ob);
    resizeprice = GetResizePrice(ob,({int})ob->QuerySize()+1);
    text="";
    if(QuerySell())
        text+="I'll give you "+({string})MONEY_DEMON->QueryValueString(price,QueryValuta())+
            " for "+({string})ob->Short()+". ";
    if(QueryFix() && ({int})ob->QueryQuality() && (({int})ob->QueryQuality()<100))
        text+="I'll "+QueryFix()+" "+({string})ob->Short()+" for "+
            ({string})MONEY_DEMON->QueryValueString(repairprice,QueryValuta())+".";
    if(QueryResize() && resizeprice)
        text+="I'll "+QueryResize()+" "+({string})ob->Short()+" for "+
            ({string})MONEY_DEMON->QueryValueString(resizeprice,QueryValuta())+".";
    if((text=="") && (({int})ob->QueryQuality()==100))
        text+=capitalize(({string})ob->Short())+" is in perfect condition.";
    if((text=="") && (({int})ob->QuerySize()==PSIZE_GENERIC))
        text+=capitalize(({string})ob->Short())+" fits all sizes.";
    if(text=="")
        text+=capitalize(({string})ob->Short())+" is worthless.";
    SkSay(text+"\n");
    return 1;
}

int CheckTrade(object ob)
{
    if( ({mixed})ob->QueryWeaponType() || ({mixed})ob->QueryArmourType() )
        return 1;
}

varargs string format_sign(string cmd,string desc,string help)
{
  return
    ({string})"/lib/string"->wrap(({string})"/lib/string"->ladjust(cmd+" ",29,".")+
    " "+desc,0,30)+"\n"+(help?({string})"/lib/string"->wrap(
    ({string})"/lib/string"->mkstr(30)+"Example: "+help,0,30)+"\n":"");
}

string detail_sign()
{
    string buy,sell,identify,appraise,list,vshow,fix,resize,result;

    if (buy = QuerySignDesc()) return buy;
    buy = QueryBuy();
    sell = QuerySell();
    identify = QueryIdentify();
    appraise = QueryAppraise();
    list = QueryList();
    vshow = QueryShow();
    fix = QueryFix();
    resize = QueryResize();

    if (!(buy||sell||identify||appraise||list||vshow||fix||resize))
    return "The smith is stupid and understands no command at all.\n";

    result = "";
    if (buy||sell)
        result+="You can "+(buy?buy+(sell?" or ":""):"")
            +(sell||"")+" things here.\n";
    result+="The smith understands the following commands:\n";
    result+=list?format_sign(list+" [<what>]",
        "List (all/matching) items in the store.",
        list+", "+list+" weapon"):"";
    result+=identify?format_sign(identify+" <what>",
        "Ask for special information on an item "
        "you have. This will cost you 10% of the "
        "items value.",identify+" sword"):"";
    result+=vshow?format_sign(vshow+" <what>",
        "Ask the smith about information for "
        "an item in the store.",
        vshow+" helmet"):"";
    result+=appraise?format_sign(appraise+" <what>",
        "Ask the smith"+(sell?" for the value of one of your "
        "items"+(fix&&resize?",":(fix||resize?" and":"")):"")+
        (fix?" how much it will cost to "+fix+" the item"+
        (resize?" and":""):"")+(resize?" how much it will "
        "cost to "+resize+" the item":"")+".",
        appraise+" knife"):"";
    if (!QueryMarket())
        result+=sell?format_sign(sell+" <what>",
            "Sell items you have.",
             sell+" all, "+sell+" gauntlets from bag"):"";
    else
        result+=sell?format_sign(sell+" <what> [for <price>]",
            "Sell items you have. You'll get paid (on your "
            "bankaccount) as soon as someone buys this item. "
            "If you want to sell the item for a certain "
            "price, give the price in copper coins.",
            sell+" axe for 300, "+sell+" knife from bag"):"";
    result+=buy?format_sign(buy+" <what>",
        "Buy items from the store. 'buy really <what>' "
        "will try to pay the price in any currency, but "
        "you'll have to pay a small fee.",
         buy+" chainmail, "+buy+" 3, "+buy+" all arrow"):"";
    result+=fix?format_sign(fix+" <what>",
        "Ask the smith to "+fix+" an item. '"+fix+" really "
        "<what>' will try to pay the price in any currency, "
        "but you'll have to pay a small fee.",
        fix+" sword"):"";
    result+=resize?format_sign(resize+" <what> <small/large>",
        "Ask the smith to resize an item. <small/large> "
        "indicates wether you want the item to be smaller "
        "or larger. '"+resize+" really <what> <small/large>' "
        "will try to pay the price in any currency, but "
        "you'll have to pay a small fee.",
        resize+" sword small, "+resize+" really boots large"):
        "";
    result+=(TP&&IS_IMMORTAL(TP))?format_sign("shop <command>",
        "Special commands for wizards. "
        "See 'shop help' for more."):"";
    return result;
}

string detail_shopkeeper()
{
    if (QueryNoShopkeeper())
        return "This is the smith.\n";
    if (!QueryShopkeeper())
        return "None here.\n";
    return 0;
}

varargs string QueryIntLong(string arg)
{
    if (arg)
        return ::QueryIntLong(arg);
    return ((::QueryIntLong(arg))||"You are in a smithy.\n")+
        "There's a sign hanging on the wall.\n";
}

varargs void SetShopkeeper(string file, mapping properties)
{
    RemoveShopkeeper();
    if(!file)
        TO->AddItem("/std/npc",REFRESH_HOME,({
            ([P_NAME:"Smith",
              P_IDS:({"shopkeeper","keeper","assistant","smith"}),
              P_SHORT:"the smith",
              P_LONG:"This is the smith.\n",
              P_GENDER:(random(3)?GENDER_MALE:GENDER_FEMALE),
              P_RACE:"dwarf",
              P_ALIGN:-400+random(800),
              P_LEVEL:17,
              P_CON:19,
              P_STR:20,
              P_INT:12
            ]),
            properties})-({0}),
            LSF("shopkeeper_refresh"));
    else
        TO->AddItem(file,REFRESH_HOME,properties,LSF("shopkeeper_refresh"));
}

varargs void create()
{
    ::create();
    SetIntShort("A smithy");
    SetIdentify(0);
    SetFix("fix");
    SetResize("resize");
    SetNoShop(0);
    SetSmithy(1);
    SetMaxRepair(100);
    SetMaxQuality(100);
    SetRepairFactor(150);
    SetResizeFactor(33);
    RemoveDetail("counter");
    AddDetail("wall","There's a sign hanging on the wall.\n");
    AddDetail("smith",#'detail_shopkeeper);
    AddDetail(({"hammer","anvil"}),"A hammer lies on the anvil.\n");
    RemoveDustbin();
    AddRoomCmd("repair",#'cmd_repair);
}

void init()
{
    ::init();
    add_action("do_fix",QueryFix()||"fix");
/*
    add_action("do_resize",QueryResize()||"resize");
*/
}
